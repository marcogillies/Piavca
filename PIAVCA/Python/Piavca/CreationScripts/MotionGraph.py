
import Piavca
import scipy
			

# create a motion from seq that can be smoothly interrupted
# by any of the motions in interruptions
def MotionGraph(motions, pcFile=None, fps = 20, num_quants=6):
	
	
	if pcFile != None and pcFile != "":
		print "found pc file", pcFile
		pcs = Piavca.PCA()
		pcs.Load(pcfile)
	else:
		pcs = Piavca.PCA()
		pcs.setUseVels(True)
		pcs.do_analysis(motions, fps)
		
	projectedMotions = []
	expmaps = []
	# project all the motions onto the pcs
	for motion in motions:
		projectedMotions.append([pw[1] for pw in pcs.projectMotion(motion, frames_per_second=fps)])#, file_extension="weights_out_"+ str(motion.getStart()))])
		expmaps.append(pcs.getExpMaps(motion, frames_per_second=fps))
		#f = open("weights_out_"+ str(motion.getStart()) +".csv", "w")
		#for weightset in projectedMotions[-1]:
		#	for w in weightset:
		#		print >> f, w, ",",
		#	print >> f, ""
		#f.close()
	
	
	if pcs.quants == None:
		print "calculating cluster centres"
		weights = []
		for projmot in projectedMotions:
			weights = weights + projmot
		weights = scipy.array(weights)
		quantizedWeights = pcs.KMeans(weights, num_quants)
	
	num_quants = pcs.numQuants()
		
		
	quants = []
	for projmot in projectedMotions:
		quants.append(pcs.VectorQuantizeWithDistance(scipy.array(projmot)))
		
	minima = []
	cluster_counts = [0 for i in range(num_quants)]
	
	for motNum, (motQuants, motDists) in enumerate(quants):
		minima.append([])
		
		currentQuant = None
		currentMinimum = None
		currentMinimumVal = 1000000.0
		added = False
		for i in range(1, len(motQuants)-1):
			cluster_counts[motQuants[i]] += 1
			if motQuants[i] != currentQuant:
				if currentQuant != None and not added:
					minima[motNum].append((currentQuant, currentMinimum))
				added = False
				currentQuant = motQuants[i]
				currentMinimum =float(i)/fps
				currentMimimumVal = motDists[i]
			else:
				if motDists[i] < currentMinimumVal:
					currentMinimum =float(i)/fps
					currentMimimumVal = motDists[i]
			if motQuants[i-1] == motQuants[i] and motQuants[i] == motQuants[i+1]:
				if motDists[i-1] > motDists[i] and motDists[i] < motDists[i+1]:
					minima[motNum].append((motQuants[i], float(i)/fps))
					added = True
	
		if currentQuant != None and not added:
			minima[motNum].append((currentQuant, currentMinimum))
		
	# create the motions
	
	random_choices = [Piavca.RandomChoiceMotion() for i in range(num_quants)]
	transitions = []

	for motNum, mot_minima in enumerate(minima):
		for start, end in zip(minima[:-1], minima[1:]):
			start_node = start[0]
			end_node = end[0]
			submot = Piavca.SubMotion(seq, start[1], end[1])
			submot.setName(str(motNum)+"_"+str(start[1])+"_"+str(end[1]))
			transitions.append(submot.getName(), end_node)
			random_choices[start_node].addMotion(subMot)
			
	mo_graph = Piavca.MotionGraph()
	mo_graph.addEvent("default")
	
	for rc in random_choices:
		mo_graph.addMotion(rc)
		
	for motName, node in transitions:
		mo_graph.addNextNode("default", motName, node)
		
	
	loop = Piavca.LoopMotion(mo_graph)
	return loop
	
	

			
