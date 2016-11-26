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
ti = 1
for i in range(1, sectoramnt + 1):
		
	sector = randint(1, 100)
	sectorwl = sectorletter[randint(1,25)] + str(sector)
	sectorindex[t] = sectorwl 
	#below creates a cool design but not sure why for the first iteration until 	
	#it's not consistent because of shits that has to do with floats and I kind of know that ceil could fix it but like, it doesn't do shit when I make ti and the 10 and the 2 floats. It's probably really doable but im tired right now. But to clarify the reason why it wont work is because when it gets to 4, 10/4 is 2.5 so then it rounds down, what the ceil function is supposed to do is round up but aparently float or not the divsion does not give a single fuck and doesnt work the way i want. In fact the floats don't work so much that there isn't even any spaces when they are used. Probably its because of the for loop but I cant change the sector amount to float unless by putting it in parenthesis with float in front to convert to float is the solution. If so then wowee that's something to do in the morning.
	if ceil(10 / ti) == 2:	
		print "    " + sectorindex[t],	
	else:	
		print sectorindex[t],	
	t += 1
	ti += 1
	if ti == 5:
		ti = 1
print "\n"

