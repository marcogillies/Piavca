"""DFS.py

Algorithms for depth first search in Python.
We need to search iteratively rather than recursively in
order to avoid Python's low recursion limit.

D. Eppstein, July 2004.
"""

from sets import Set

# Types of edges in DFS traversal.
# The numerical values are used in DepthFirstSearcher, change with care.
forward = 1	 # traversing edge (v,w) from v to w
reverse = -1	# returning backwards on (v,w) from w to v
nontree = 0	 # edge (v,w) is not part of the DFS tree

whole_graph = object()  # special flag object, do not use as a graph vertex

class SearchStrategy:
	def __init__(self):
		pass
	def select(self, stack):
		pass
	def continuation_test(self, parent, child):
		return 1
		
class dfs(SearchStrategy):
	def __init__(self):
		SearchStrategy.__init__(self)
	def select(self, stack):
		return -1
		
class bfs(SearchStrategy):
	def __init__(self):
		SearchStrategy.__init__(self)
	def select(self, stack):
		return 0
	

def search(G,search_strategy,initial_vertex = whole_graph):
	"""
	Generate sequence of triples (v,w,edgetype) for DFS of graph G.
	The subsequence for each root of each tree in the DFS forest starts
	with (root,root,forward) and ends with (root,root,reverse).
	If the initial vertex is given, it is used as the root and vertices
	not reachable from it are not searched.
	"""
	visited = Set()
	if initial_vertex == whole_graph:
		initials = G
	else:
		initials = [initial_vertex]
	for v in initials:
		if v not in visited:
			yield v,v,forward
			visited.add(v)
			stack = [(v,v,iter(G[v]))]
			while stack:
				index = search_strategy.select(stack)
				grandparent,parent,children = stack[index]
				try:
					child = children.next()
					if not search_strategy.continuation_test(parent,child):
						continue
					if child in visited:
						yield parent,child,nontree
					else:
						yield parent,child,forward
						visited.add(child)
						stack.append((parent,child,iter(G[child])))
				except StopIteration:
					stack.pop(index)
					#if stack:
					yield grandparent,parent,reverse
			#yield v,v,reverse

def preorder(G,initial_vertex = whole_graph):
	"""Generate all vertices of graph G in depth-first preorder."""
	for v,w,edgetype in search(G,initial_vertex):
		if edgetype is forward:
			yield w

def postorder(G,initial_vertex = whole_graph):
	"""Generate all vertices of graph G in depth-first postorder."""
	for v,w,edgetype in search(G,initial_vertex):
		if edgetype is reverse:
			yield w

def reachable(G,v,w):
	"""Can we get from v to w in graph G?"""
	return w in preorder(G,v)

class Searcher:
	"""
	Handler for performing general depth first searches of graphs.
	Some or all of the routines preorder, postorder, and backedge
	should be shadowed in order to make the search do something useful.
	"""

	def preorder(self,parent,child):
		"""
		Called when DFS visits child, before visiting all grandchildren.
		Parent==child when child is the root of each DFS tree.
		"""
		pass

	def postorder(self,parent,child):
		"""
		Called when DFS visits child, after visiting all grandchildren.
		Parent==child when child is the root of each DFS tree.
		"""
		pass

	def backedge(self,source,destination):
		"""Called when DFS discovers an edge to a non-child."""
		pass

	def __init__(self,G,search_strategy):
		"""Perform a depth first search of graph G."""
		dispatch = [self.backedge,self.preorder,self.postorder]
		for v,w,edgetype in search(G,search_strategy):
			dispatch[edgetype](v,w)
