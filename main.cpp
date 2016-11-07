//If anyone dares to look at this file, compile with -std=c++11
#include <iostream>
#include <stdlib.h> /* prinf(), scanf(), puts, NULL, rand, srand */
#include <stdio.h> /* srand(), rand() */
#include <time.h> /* time */
#include <vector> /* vector */
#include <string> /* std::string */
#include <string.h> /* strcmp */
#include <algorithm> /* find, transform */
#include <iterator>
#include <stdio.h> /* strcmp() */
#include <unistd.h> /* usleep() */
#include <ncurses.h> /* initscr(), printw(), refresh(), getch()//only for ncurse, not normal input, endwin()*/ 
#include "global.h" 


int main (int argc, char*argv[])
{
	//NOTE THE CHAOS LEVEL INCREMENTS BY 1 DECIMAL UNLESS A STRIKE IS INITIATED!	
	/*
	THESE COMMANDS ARE NOT FINAL!
	* by the command means that it is hidden from the man pages.
	--v 			verbose
	-v			version
	--demigod		enables demigodmode, you can't die, but you have limited resources
	--god			enables godmode, you can't die, unlimited resources
	--nomenu		disables the main menu and goes directly to the game
	*--interdimensional+   	allows sectors with numbers higher than 100 to spawn in
	----------THE FOLLOWING THREE ARE NOT COMPATIBLE WITH EACH OTHER!!!!----------------------
  	--maxchaos		starts the game with the chaos level already starting at 10
	*--beyondchaosi		10 is not the limit for the maximum amount of chaos in a game		 
	*--beyondchaos9ki	starts the game at a chaos level of 9000 and it's not a limit for a game 
	*/	
	//std::string commandlist[] = {"-v", "--v", "--demigod", "--god", "--interdimensional", "--maxchaos", "--beyondchaosi", "--beyondchaos9ki"};
	//int commandlistamnt = sizeof(commandlist)/sizeof(commandlist[0]);
	
	//for (int h = 0; h < commandlistamnt; h++)
	//{	
	//THIS ISN'T A CASE SWITCH STAEMENT SINCE I DON'T KNOW HOW TO COMPARE ARGUMENTS WITH STINGS IN A SWITCH FUNCTION, SO THERE'S A REASON
	if (argc > 1)
	{
		if (strcmp(argv[1],"-v") == 0)
		{
			std::cout << "Program by Yetoo Happy\n<Insert version date>\n<Insert version number>\n";
			//break;
		}
		else if (strcmp(argv[1],"--v") == 0)
		{
			std::cout << "What a shitty switch.\n";
			verbose = true;
		}			
		else if (strcmp(argv[1], "--demigod") == 0)
		{
			std::cout << "wowwweee\n";
			demigod = true;			
			return 0;
		}
		else if (strcmp(argv[1], "--god") == 0)
		{
			god = true;
		}
		else if (strcmp(argv[1],"--interdimensional+") == 0)
		{
			interdimensionalplus = true;
		}		
		else if (strcmp(argv[1],"--maxchaos") == 0)
		{
			maxchaos = true;
		}
		else if	(strcmp(argv[1],"--beyondchaosi") == 0)
		{
			beyondchaosi = true;
		}
		else if (strcmp(argv[1],"--beyondchaos9ki") == 0)
		{
			beyondchaos9ki = true;
		}
		else if (strcmp(argv[1],"--nomenu") == 0)
		{
			nomenu = true;
		}	
	}
	
	//else
	//{
	//std::cout << "wrong usage, read the manpage you lazy fuck\n";
	//return 0;
	//}
	
	//}
/*
	initscr(); //remember this starts the curses mod
	printw("Nuke Sector!\nIt's nuclear war time!"); //remember this goes into a buffer
	
	while(!nomenu)
	{
		//test if statement instead of case
		//what ever the method is, if the desired key is pressed it will move the cursor to a definite place, set the x and y values so that when the program checks for the x and y to be at a certain location, it will be the same location as the cursor, the cursor being visible is merely an illusion of doing something.
		refresh(); //this gets the contents out of a buffer, onto the screen
		switch(c)
		{
		case KEY_UP:		
		y++;
		printw("asd");		
		break;
		case KEY_DOWN:
		y--;
		printw("asd");
		break;
		case KEY_LEFT:
		x--;
		printw("asd");
		break;
		case KEY_RIGHT:
		x++;
		printw("asd");
		break;
		}
		//move (0+x, 0+y);
		move (x, y);		
		refresh();		
		getch();
		endwin();
	}
*/
	srand(time(NULL));
	sectoramnt = rand() % 100 + 1;
	//std::string sectorindex [sectoramnt];
	//std::cout << "It's nuclear war time!\n";
	std::cout << "Sectors:\n"; 
	for (int i = 0; i < sectoramnt; i++)
	{
	//std::cout << "test";	
	sector = rand() % 100 + 1;
	//TODO add special snowflake status if the program fucks up and causes number fluctuation

        sectorts = std::to_string(sector);
	//sectorjl = sectorletter[rand()%26+1];
	//sectorwl = sectorjl + sectorts;
	//the reason for 26 is because it needs to choose a letter for every value that is in the letter array
	sectorwl = sectorletter[rand()%26+0] + sectorts;
        sectorindex[i] = sectorwl;
	//if in the possibility of saving to the file, add catch if sudden stop 
	//a catch would be ensuring that both the value has inputted and depected or crash
	std::cout << sectorindex[i] << " "; 
	}
	std::cout << "\n";
	

	while (happy == false)
	//move a lot of what is above into here so the user can have choice
	{
	//make sure that they know you can restart without selecting another secotr, but they have less of something than they started with, making the option useless in a way 
	std::cout << "Which sector do you want to select?\nNOTE: You cannot select any more sectors after this point in this session, unless of course you choose to restart the session.\n";
	std::cin >> sectordec;
	for (int u = 0; u < sectoramnt; u++)
	{
	if (sectordec.compare(sectorindex[u]) == 0 && sectorindex[u] != "\0")
	{
		std::string happydec = "";
		std::string happydec2= "";		
		std::cout << "You selected sector " << sectordec << "\n";
		selectsector = sectordec;
			//IT'S LOADING SECTOR INFORMATION TIME!
			/*
			General format:
			---------------
			Sector Name: <Sector Name>
			Sector Series: <Sector Letter Series>
			Sector Location in Series: <Sector Location in Series>			
			Sector Description: <Varies Depending on Sector Letter Series and Number Within>
			---------------
			Verify if this is the sector that the user wants
			If it is not, go to prompt screen.
			*/
			//add the shit above
			//cause program to scroll to add effect of travel
			sectorjl = selectsector.substr(0,1);
			sectorjn = selectsector.substr(1, selectsector.length());			

			std::cout << "Sector Name: " << selectsector << 
	"\nSector Series: " << sectorjl << "\nSector Location in Series: " << sectorjn << "\nSector Description: " << desc << "\n";
		std::cout << "Are you sure this is the sector you desire?(y | n)\n";
		std::cin >> happydec;
		//make to lowercase
		//std::transform(happydec.begin(), happydec.end(), happydec.begin(), ::tolower);
		if (happydec == "y")
		{
			happy = true;
			std::cout << "Initializing match for selected sector " << selectsector << "...\n";
			ClearScreen();
			break;
		}
		
	}
	}
	}	
	std::cout << "Move: " << moves << "\n";
	//this for loop is supposed to sort all the letters	
	int a[100];
	int temp;
	//crappy excuse for a buffer
	bool satis = false;
	for (int i = 0; i < sectoramnt; i++)
	{
		//always going to be equal to the sectorindex		
		std::string tmpl = ""; //templetter
		tmpl= sectorindex[i].substr(0,1);
		auto it = std::find(std::begin(sectorletter),std::end(sectorletter), tmpl);		
		//size_t x = std::distance(sectorletter, std::find(sectorletter, sectorletter + 26, ;
		if (it != std::end(sectorletter))
		{
			
			
			//your just going to sort the places in the sectorletter array so that they are in order, that's all you're doing				
			a{i] = std::distance(std::begin(sectorletter), it);
			//while (temp )
			/*			
			temp = a[i];
			a[i] = a[i + 1];
			a[i+1] = temp;
			if (a[i+1])			
			std::cout << temp << "\n";
			*/		
		}		
		
			
		//std::cout << sectorindex[i] << " ";
		 
	}
	while (!satis)
	{
		if (a[sectoramnt] > a[i])
		{
			//you do use a[i + 1];
		}
	}
	std::cout << "\n";
	return 0;
}
//http://www.cplusplus.com/reference/cstdlib/rand/
/*
	for (int x = 0; x < 26; x++)
	{
		std::cout << "\n";
		for (int z = 0; z < 101; z++)
		{ 			
			sectorts = std::to_string(z);
			sectorwl = sectorletter[x] + sectorts;					
			//std::cout << sectorwl << " ";			
			//std::string *sectorindexfind = std::find(std::begin(sectorindex), std::end(sectorindex), sectorwl);		
			
			if (sectorindexfind != std::end(sectorindex))
			{
				std::cerr << "found at position" << std::distance(sectorindex, sectorindexfind) << "\n";
			}
			else
			{	
				std::cerr << sectorwl << "\n";	
			}
			
			for (int y = 0; y < sectoramnt; y++)
			{			
			if (sectorwl.compare(sectorindex[y]) == 0)
			//std::cout << "a";
			//if (sectorwl.compare(sectorindex[y]) != 0)
			std::cout << sectorwl << " ";
			
			//else
			//std::cout << sectorwl << " ";
			}
			
		}  
	}
		
	

	
    //std::string * sectordecfind;
	bool sectordecfind (const std::string $sectordec, const std::vector<std::string> &sectorindex);
	{
			//return std::find(sectorindex.begin(), sectorindex.end(), sectordec) != sectorindex.end());
			return std::find(sectorindex.begin, sectorindex.end, sectordec) != sectorindex.end;
	}
	*/
