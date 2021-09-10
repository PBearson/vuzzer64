import pickle

f = open("test.pkl", "r")
x = pickle.load(f)
f.close()

f = open("test.names", "r")
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