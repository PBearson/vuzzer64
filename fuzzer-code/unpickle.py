import pickle

f = open("test.pkl", "r")
x = pickle.load(f)
f.close()

f = open("test.names", "r")
y = pickle.load(f)
f.close()

print "Pickle contents:"
print x
print "\nNames contents:"
print y