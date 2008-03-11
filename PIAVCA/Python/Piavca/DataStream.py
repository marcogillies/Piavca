# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is DataStreams.py
#
# The Initial Developer of the Original Code is
# Marco Gillies
# Portions created by the Initial Developer are Copyright (C) 2007
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

import bisect
import time, thread

import wx

class DataSequence:
    def __init__(self, file = None):
        self.seq = []
        if file != None:
            self.readCSV(file)
            
    def stringToValue(self, str):
    	return float(str.strip())
        
    def readCSV(self, filename, separator=" "):
        f = open(filename)
        lines = f.readlines()
        f.close()
        for line in lines:
            try:
                line = line.strip()
                if line == "":
                    continue
                #print line
                line = line.replace(","," ")
                line = line.replace(";"," ")
                #print line
                data = line.split()
                #print data
                t = float(data[0].strip())
                data = [self.stringToValue(d) for d in data[1:]]
                #print data
                self.addElement(t, data)
            except ValueError, IndexError:
                pass
               
    def saveCSV(self, filename):
    	f = open(filename, "w")
    	for t,data in self.seq:
    		f.write(str(t)+", ")
    		for d in data:
    			f.write(str(d)+", ")
    		f.write("\n")
    	f.close()
        
    def addElement(self, t, data):
        bisect.insort(self.seq, (t, data))
        
    def getDataSize(self):
        return len(self.seq[0][1])
		
    def getDataAtTime(self, t):
        # find the keyframe after the requested time 
        index = bisect.bisect(self.seq, (t, []))
        # if its before or at the start return the first item
        if index == 0:
            return self.seq[0][1]
        # if it's after or at the end erturn the last item
        if index >= len(self.seq):
            return self.seq[-1][1]
        
        # otherwise interpolate
        t0, d0 = self.seq[index-1]
        t1, d1 = self.seq[index]
        t = t -t0
        t = float(t)/(t1 - t0)
        d = [(x1 - x0)*t + x0 for x0, x1 in zip(d0, d1)]
        return d
    
    def getMean(self):
        if len(self.seq) == 0:
            return None
        mean = list(self.seq[0][1])
        for t, d in self.seq[1:]:
            #print d, min, max
            for i in range(len(d)):
                mean[i] += float(d[i])/(len(self.seq)-1)
		#mean = [m-1) for m in mean]
        return mean
	
    def getMinMax(self):
    	print len(self.seq)
        if len(self.seq) == 0:
            return None
        min = list(self.seq[0][1])
        max = list(self.seq[0][1])
        for t, d in self.seq[1:]:
            #print d, min, max
            for i in range(len(d)):
                if d[i] > max[i]:
                    #print d[i], max[i]
                    max[i] = d[i]
                if d[i] < min[i]:
                    min[i] = d[i]
        return min, max
    
    def getStartTime(self):
        return self.seq[0][0]
    
    def getEndTime(self):
        return self.seq[-1][0]
        
class IntegerDataSequence(DataSequence):
    def __init__(self, file = None):
     	DataSequence.__init__(self, file)
    
    def stringToValue(self, str):
    	return int(float(str.strip()))
		
    def getDataAtTime(self, t):
        # find the keyframe after the requested time 
        index = bisect.bisect(self.seq, (t, []))
        # if its before or at the start return the first item
        if index == 0:
            return self.seq[0][1]
        # if it's after or at the end erturn the last item
        if index >= len(self.seq):
            return self.seq[-1][1]
        
        return self.seq[index][1]
     
class SequenceDisplay(wx.Frame):
    def __init__(self, parent = None, file = None):
        wx.Frame.__init__(self, parent)
        self.seq = DataSequence(file)
        print "length of sequence", self.seq.seq
        if file != None:
            self.create()
        
    def create(self):
        print "length of sequence", self.seq.seq
        self.sizer=wx.BoxSizer(wx.VERTICAL)
        
        self.min, self.max = self.seq.getMinMax()
        self.sliders = []
        for a,b in zip(self.min, self.max):
            self.sizer.Add(self.addSlider(0, 60), 1)

        self.SetSizer(self.sizer)
        self.SetAutoLayout(1)
        self.sizer.Fit(self)
        self.Show(True)
        self.Layout()
        
    def addSlider(self, a, b):
        print a, b
        s = wx.Slider(self, len(self.sliders)+100, a, a, b, style=wx.SL_HORIZONTAL, size=(200, 40))
        self.sliders.append(s)
        return s
    
    def setTime(self, t):
        d = self.seq.getDataAtTime(t)
        #print d
        for i in range(len(d)):
        	val = d[i] - self.min[i]
        	#print val,
        	val *= 60.0
        	#print val,
        	val /= (self.max[i] - self.min[i])
        	#print val,
        	self.sliders[i].SetValue(int(val))
        	#print ""
    
    def setTimeNormalized(self, t):
        start = self.seq.getStartTime()
        end = self.seq.getEndTime()
        self.setTime(t*(end-start)+start)


     
class IntSequenceDisplay(wx.Frame):
    def __init__(self, parent = None, file = None):
        wx.Frame.__init__(self, parent)
        self.seq = IntegerDataSequence(file)
        if file != None:
            self.create()
        
    def create(self):
    	min, max = self.seq.getMinMax()
    	print min, max
    	self.radioboxes = []
        self.sizer=wx.BoxSizer(wx.HORIZONTAL)
    	for a,b in zip(min, max):
            items = [str(i) for i in range(a, b+1)]
            self.radioboxes.append(wx.RadioBox(self, -1, "data stream", (10, 10), wx.DefaultSize, items, 5, wx.RA_SPECIFY_COLS))
            self.sizer.Add(self.radioboxes[-1], 1)
        
        self.SetSizer(self.sizer)
        self.SetAutoLayout(1)
        self.sizer.Fit(self)
        self.Show(True)
        self.Layout()
    
    def setTime(self, t):
    	print "set time", t
        d = self.seq.getDataAtTime(t)
        print "current data", d
        for data, radiobox in zip(d, self.radioboxes):
			radiobox.SetStringSelection(str(data))
    
    def setTimeNormalized(self, t):
        start = self.seq.getStartTime()
        end = self.seq.getEndTime()
        self.setTime(t*(end-start)+start)

    
if __name__ == "__main__":
    #seq = DataSequence()
    #seq.readCSV("../../../Data/boredinterested_qvalue3/intensityVariance.csv")
    app = wx.PySimpleApp()
    #disp = SequenceDisplay(None, "../../../Desktop/test.csv")
    disp = SequenceDisplay(None, "../../../Data/boredinterested_qvalue3/intensityVariance.csv")
    #print seq.seq
    #ts = range(10)
    #ds = range(0, 100, 10)
    #for t, d in zip(ts, ds):
    #    disp.seq.addElement(t, [d])
    for t in [-1, 0, 2.3, 4.5, 6.7, 9, 10, 100]:
       print t, disp.seq.getDataAtTime(t)
    #disp.create()
    disp.setTime(2.3)
    
    def controlTime():
         startTime = time.time()
         while (True):
             t = time.time()
             print t
             t = t - startTime + disp.seq.getStartTime()
             if t > disp.seq.getEndTime():
                 t = t - disp.seq.getEndTime()
                 startTime = time.time() - t
             wx.CallAfter(disp.setTime, t)
             time.sleep(0.05)
    thread.start_new_thread(controlTime, ())
    
    app.MainLoop()
        