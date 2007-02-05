import Piavca

def importNames(filename, joints=1):
	file = open(filename, "r")
	lines = file.readlines()
	file.close()
	
	for line in lines:
		if line[0] == "#":
			continue
		line = line.split(",")
		line = [l.strip() for l in line]
		if line[-1] == "":
			line = line[:-1]
		if joints :
			#print line
			Piavca.Core.getCore().addJointNameSet(line)
		else:
			#print line
			Piavca.Core.getCore().addExpressionNameSet(line)		
			
def importJointNames(filename):
	importNames(filename, 1)	
			
def importExpressionNames(filename):
	importNames(filename, 0)