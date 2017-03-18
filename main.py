#This will eventually incorporate ncurses, but for now, I want this to be a standard output text game only. Ncurses will make everything more complicated than it should be. This will eventually be made into an OpenGL application, I'm learning shit as I go along so that's why I'm not going immediately to OpenGl. Also because I do better by refractoring, I don't have the intellect to keep this in my mind long enough for something like OpenGL even though I actually haven't tried it with this. 
from random import random, randint, sample
from math import ceil
from time import sleep
import sys
import array
desc = ""
sectorletter = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
sectorindex = [None]*100
#do the command line arguments
sectoramnt=randint(1, 100)
#lettertmp = [None]*sectoramnt nvm about this
#print sectoramnt
def ClearScreen():
	for i in range(0, 3): #this amount will change due to the size of the window
		print "\n\n\n\n\n\n\n\n\n\n"	
		sleep(0.5)		
def main(): 
	"""This function displays the main menu interface and allows the user to choose which part of the software they wish to utilize.
	NG() is for the New game.
	Continue() is for the continuance of an existing game.
	Load() is to load a specific point in an existing game.
	Settings() is to get to the interface which allows the user to configure the software without the need for command line arguments.
	About() is to tell about the licensing of the software and the authors and summary of the game.
	Exit() is to exit the program.
	Please note the lack of break statements except for the exit option because remember, this is a game. A game or anything with a menu has an infinite loop.
	"""
	#ClearScreen() this will be uncommented when there are command line options to disable initial menu clear screen 
	while True:
		print "-----Nuke Sector-----\n1. New Game\n2. Continue\n3. Load\n4. Settings\n5. About\n6. Exit\n---------------------"
		d = raw_input("Pick: ")
		if d == "1":
			op = raw_input("Are you sure you want to create a new game? y/n ")
			if op == "y":
				print "Creating new game..."
				NG()
			else:
				pass
		if d == "2":
			op = raw_input("Are you sure you want to continue? y/n ")
			if op == "y":
				Continue()
			else:
				pass
		if d == "3":
			print "Entering Load menu..."
			Load()
		if d == "4":
			print "Entering Settings menu..."
			Settings()
		if d == "5":
			About()
		if d == "6":
			op = raw_input("Are you sure you want to exit? y/n ")
			if op == "y":
				break
			else:
				pass
def NG():
	sgen()
def Continue():
	print "Loading last saved game..."
def Load():
	pass
def Settings():
	pass
def About():
	#edit this so that it reads the info blank file which has the license and info about the game
	print "This is Nuke Sector by Scott Cohen.\nthis will eventually"		
def sgen():
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
	curmove = 0 #please take note that this may very well be global if I need to make another definition because of shitty python embeded loop breakage. Speaking of globals, I am aware that they can be declared with global, but like, it works when I don't do that. 
	curmovestr = str(curmove)	
	print "\rMove: " + curmovestr #+ "\n"
	#take the letter from sector index, convert it to number, which to do this, need to find a find command that can search for a specific value in a list, then immediately put into another list, do the sorted command for that list print out shit the same way at the top but in alphabetical form. 
	#if you were going to refactor back to c++, you need to look at the behind the scenes of the SORTED COMMAND		
	for i in range (0, len(sectorindex)):
		sectorjtmp = sectorindex[i]
		sectorjl2 = sectorjtmp[:1]
		sectorjn2 = sectorjtmp[1:]
		#make elements global relative to the for loop to print at the end of loop		
		elements = {} 
		#sectorletter.index(sectorjl2) = lettertmp[i] #FUCK I FORGOT THAT I NEED TO MAKE A 2D ARRAY OR SOME SHIT LIKE THAT SO THAT THE FUCKING STRINGS CONTAINING NUMBERS CAN BE FUCKING ASSOCIATED WITH THE LETTERS! SHIT! FUCK THIS I'M GOING TO BED!
	 
try:
	main()
except KeyboardInterrupt:
	print "\r"
#main2()

				
			 
