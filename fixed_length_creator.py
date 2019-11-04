
import sys
input_csv = sys.argv[1]
output_csv = sys.argv[2]

# modify these if you want a max number of object
#maxjet = -1
#lengths = maxjet*4
rowSize = []
objects = []
m  = 0
txt3 = open(input_csv)
for line in txt3:
        #linewrite = ""
        obhold= []
        split = line.split(",")
        #print 'The total no. of jets {}.'.format(len(split))
        rowSize.append(len(split)-1)
        rowLen = len(split)-1
	for l in range(0,rowLen):
        	obhold.append(split[l])
        objects.append(obhold)
        m = m+1
txt3.close()
maxRow = max(rowSize)
for k in range(0,m):
	if rowSize[k] < maxRow:
		for l in range(rowSize[k],maxRow):
			objects[k].append(0)
             	
print 'objects size {}.'.format(len(objects))
print 'objects {}.'.format(objects[1][1])	
txt = open(output_csv,"w")

for k in range(0,m):
	linewrite = ""	
	for l in range(0,maxRow):
		linewrite=linewrite+str(objects[k][l])+","
	txt.write(linewrite[:-1]+",\n")
txt.close()
