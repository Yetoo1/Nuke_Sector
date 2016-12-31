//#define KEY_UP 72
#ifndef GLOBALS_H
#define GLOBALS_H
//remove initializations, add to cpp file
//these are for the command line arguments explained in the main file, it's just easier that way
bool verbose = false, demigod= false, god = false, interdimensionalplus = false, maxchaos = false, beyondchaosi = false, beyondchaos9ki = false, happy = false, nomenu = false; 
	int sector = 0; //This is a bit misleading, this is the number porition of the sector
	int sectoramnt = 0; //Or sector amount, this determines the number of sectors to be generated
	int x = 0, y = 0; //I have no idea what the hell these are supposed to be for
	int moves = 0; //this is the variable that holds the current move 	
	char c; //I think this was supposed to be for that commented out case statement in main.cpp 
	std::string selectsector = ""; //I think this is useless, but it is the variable that holds the user selection
	std::string sectorts = ""; //sector to string
	std::string sectorwl= ""; //***POSSIBLY FIX sector with letter this is going to contain the added letter and number
	std::string sectorjl=""; //sector with just letter
	std::string sectorjn=""; //sector with just number
	std::string sectordec= ""; //string for sector decision 
	std::string sectorletter[26] =  {"A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}; //this is the array that is supposed to hold the predefined letters that sectors will contain 	
	std::string sectorindex[100]; //the index initialized with 100 spaces maximum
	std::string desc = " "; //stuff is going to come here soon

#endif
#ifndef __SCREENEFFECTS__
#define __SCREENEFFECTS__
#include <iostream>
void ClearScreen() //Clears the screen but scrolls
{
	for (int x = 0; x < 5; x++) //This scrolls 5 times
	{      
	std::cout << "\n\n\n\n\n\n\n\n\n\n"; //i don't know if this is lame, but it's pretty lame
	usleep(500000); //half a second, this is what makes it scroll 
	}
}
#endif

