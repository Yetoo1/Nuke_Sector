#main.py
from random import random, randint, sample
from math import ceil
from time import sleep
import sys
import array
desc = ""
sectorletter = ["A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
sectorindex = [None]*100
#do the command line arguments
sectoramnt=randint(1, 100)
#print sectoramnt
def ClearScreen():
	for i in range(0, 6):
		print "\n\n\n\n\n\n\n\n\n\n"	
		sleep(0.5)		
		
def main():
	print "Sectors:\n"
	t = 1
	ti = 1
# if you wanted the while loop below this for loop within the for loop, you would need to make the for loop a while loop and then at the end for end states do break break but I'm not going to do that now.
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
	while True:
		sectordec = raw_input("Which sector do you want to select?\nNOTE: You cannot select any more sectors after this point in this session, unless of course you choose to restart the session. ")
		for i in range(1, sectoramnt + 1):     #fix this
			if sectordec == sectorindex[i]: #and not sectorindex[i]:
				print "You selected sector " + sectordec	
	#			General format:
	#			---------------
	#			Sector Name: <Sector Name>
	#			Sector Series: <Sector Letter Series>
	#			Sector Location in Series: <Sector Location in Series>			
	#			Sector Description: <Varies Depending on Sector Letter Series and Number Within>
	#			---------------
	#			Verify if this is the sector that the user wants
	#			If it is not, go to prompt screen.
	#			*/
	#			add the shit above
	#			cause program to scroll to add effect of travel in the perspective of the user.
				sectorjl = sectordec[:1]
				sectorjn = sectordec[1:]
				print "Sector Name: " + sectordec + "\nSector Series: " + sectorjl + "\nSector Location in Series: " + sectorjn + "\nSector Description: " + desc + "\n"
				happydec = raw_input("Are you sure this is the sector you desire? y/n\n")
				if happydec == "y":
					print "Initializing match for selected sector " + sectordec + "...\n"
					ClearScreen()
					return				
		
def main2():
	moves = 0 #please take note that this may very well be global if I need to make another definition because of shitty python embeded loop breakage. Speaking of globals, I am aware that they can be declared with global, but like, it works when I don't do that. 
	print "Move: "

main()
				
			 
