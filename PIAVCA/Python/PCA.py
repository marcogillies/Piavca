
from EigenAnalysis import *

# perform a PCA on motion data
class PCA(EigenAnalysis):
	def __init__ (self):
		EigenAnalysis.__init__(self)
	
	def get_matrix (self, data):
		print "PCA: getting covariance matrix"
		rows, cols = scipy.shape(data)
		mean = scipy.sum(data)
		temp = scipy.asmatrix(data - mean)
		cov = temp.T*temp
		rows, cols = scipy.shape(cov)
		cov = cov/cols
		return cov
