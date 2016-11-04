#ifndef GLOBALS_H
#define GLOBALS_H
//remove declarations, add to cpp file
bool verbose = false, demigod= false, god = false, interdimensionalplus = false, maxchaos = false, beyondchaosi = false, beyondchaos9ki = false; 
bool happy = false;
	int sector = 0;
	int sectoramnt = 0; 
	std::string selectsector = "";
	std::string sectorts = ""; //sector to string
	std::string sectorwl= ""; //sector with letter this is going to contain the added letter and number
	std::string sectorjl=""; //sector with just letter
	std::string sectordec= ""; //string for sector decision 
	std::string sectorletter[26] =  {"A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};	
	std::string sectorindex[100];
	std::string desc = " ";
#endif
/*
#ifndef __SCREENEFFECTS__
#define __SCREENEFFECTS__
#include <iostream>
  #include <string>

  void ClearScreen()
    {
    std::cout << std::string( 100, '\n' );
    }

#else

  #include <stdio.h>

  void ClearScreen()
    {
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
#endif
*/
