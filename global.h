//#define KEY_UP 72
#ifndef GLOBALS_H
#define GLOBALS_H
//remove declarations, add to cpp file
bool verbose = false, demigod= false, god = false, interdimensionalplus = false, maxchaos = false, beyondchaosi = false, beyondchaos9ki = false, happy = false, nomenu = false; 
	int sector = 0;
	int sectoramnt = 0;
	int x = 0, y = 0;
	int moves = 0; 	
	char c;
	std::string selectsector = "";
	std::string sectorts = ""; //sector to string
	std::string sectorwl= ""; //sector with letter this is going to contain the added letter and number
	std::string sectorjl=""; //sector with just letter
	std::string sectorjn=""; //sector with just number
	std::string sectordec= ""; //string for sector decision 
	std::string sectorletter[26] =  {"A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};	
	std::string sectorindex[100];
	std::string desc = " ";

#endif
#ifndef __SCREENEFFECTS__
#define __SCREENEFFECTS__
#include <iostream>
void ClearScreen()
{
	for (int x = 0; x < 5; x++)
	{      
	std::cout << "\n\n\n\n\n\n\n\n\n\n";
	Sleep(500); //half a second 
	}
}
#endif

