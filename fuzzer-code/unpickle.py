import pickle
import sys

arg1 = sys.argv[1]
arg2 = sys.argv[2]

pkl = ""
names = ""

if "pkl" == arg1[-3:]:
    pkl = arg1
elif "pkl" == arg2[-3:]:
    pkl = arg2
else:
    print "ERROR: pkl file not supplied"
    exit(-1)

if "names" == arg1[-5:]:
    names = arg1
elif "names" == arg2[-5:]:
    names = arg2
else:
    print "ERROR: names file not supplied"
    exit(-1)

f = open(pkl, "r")
x = pickle.load(f)
f.close()
    
f = open(names, "r")
y = pickle.load(f)
y1 = [i for i in y[0]]
y2 = [i for i in y[1]]
f.close()

print "BB weights:"
print x
print "\nString immediates seen in CMP instructions:"
print y1
print "\n Byte immediates seen in CMP instructions:"
print y2