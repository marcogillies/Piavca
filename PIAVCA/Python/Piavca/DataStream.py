import bisect
import time, thread

import wx

class DataSequence:
    def __init__(self, file = None):
        self.seq = []
        if file != None:
            self.readCSV(file)
        
    def readCSV(self, filename, separator=" "):
        f = open(filename)
        lines = f.readlines()
        f.close()
        for line in lines:
            try:
                line = line.strip()
                if line == "":
                    continue
                data = line.split()
                data = [float(d.strip()) for d in data]
                #print data
                self.addElement(data[0], data[1:])
            except ValueError, IndexError:
                pass
        
    def addElement(self, t, data):
        bisect.insort(self.seq, (t, data))
        
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
    
    def getMinMax(self):
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
        
    
class SequenceDisplay(wx.Frame):
    def __init__(self, parent = None, file = None):
        wx.Frame.__init__(self, parent)
        self.seq = DataSequence(file)
        if file != None:
            self.create()
        
    def create(self):
        self.sizer=wx.BoxSizer(wx.VERTICAL)
        
        min, max = self.seq.getMinMax()
        self.sliders = []
        for a,b in zip(min, max):
            self.sizer.Add(self.addSlider(a, b), 1)

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
        for i in range(len(d)):
            self.sliders[i].SetValue(d[i])
    
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
        