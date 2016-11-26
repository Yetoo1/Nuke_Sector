#main.py
import sys
from random import random, randint, sample
from math import ceil
import array
#do the array
sectorletter = ["A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
sectorindex = [None]*100
#do the command line arguments
sectoramnt=randint(1, 100)
#print sectoramnt
print "Sectors:\n"
t = 1
ti = 1.0
for i in range(1, sectoramnt + 1):
		
	sector = randint(1, 100)
	sectorwl = sectorletter[randint(1,25)] + str(sector)
	sectorindex[t] = sectorwl 
	#below creates a cool design but not sure why for the first iteration until 	
	if ceil(10.0 / ti) == 2.0:	
		print "    " + sectorindex[t],	
	else:	
		print sectorindex[t],	
	t += 1
	ti += 1.0
	if ti == 5:
		ti = 1.0
print "\n"

