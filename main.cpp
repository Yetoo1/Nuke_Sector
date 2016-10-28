#include <iostream>
#include <stdlib.h> /* prinf, scanf, puts, NULL */
#include <stdio.h> /* srand, rand */
#include <time.h> /* time */
#include <vector> /* vector */
#include <string> /* string */
#include <string.h> /* strcmp */
#include <algorithm> /* find, transform */
#include <stdio.h> /* strcmp */
//#include <unistd.h> /* usleep */
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
	*--interdimensional+   	allows sectors with numbers higher than 100 to spawn in
	----------THE FOLLOWING THREE ARE NOT COMPATIBLE WITH EACH OTHER!!!!----------------------
  	--maxchaos		starts the game with the chaos level already starting at 10
	*--beyondchaosi		10 is not the limit for the maximum amount of chaos in a game		 
	*--beyondchaos9ki	starts the game at a chaos level of 9000 and it's not a limit for a game 
	*/	
	//std::string commandlist[] = {"-v", "--v", "--demigod", "--god", "--interdimensional", "--maxchaos", "--beyondchaosi", "--beyondchaos9ki"};
	//int commandlistamnt = sizeof(commandlist)/sizeof(commandlist[0]);
	bool verbose = false, demigod= false, god = false, interdimensionalplus = false, maxchaos = false, beyondchaosi = false, beyondchaos9ki = false; 
	//for (int h = 0; h < commandlistamnt; h++)
	//{	
	//change this to switch case	
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
	}
	//else
	//{
	//std::cout << "wrong usage, read the manpage you lazy fuck\n";
	//return 0;
	//}
	
	//}
	int sector;
	int sectoramnt;
	std::string selectsector = "";
	std::string sectorts = ""; //sector to string
	std::string sectorwl= ""; //sector with letter this is going to contain the added letter and number
	std::string sectordec= ""; //string for sector decision 
	std::string sectorletter[] =  {"A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};	
	srand(time(NULL));
	sectoramnt = rand() % 100 + 1;
	std::string sectorindex [sectoramnt];
	std::cout << "It's nuclear war time!\n";
	//usleep(200000);
	std::cout << "Sectors:\n"; 
	for (int i = 0; i < sectoramnt; i++)
	{
	sector = rand() % 100 + 1;
	//TODO add special snwoflak status if the program fucks up and causes number fluctuation
        sectorts = std::to_string(sector);
	sectorwl = sectorletter[rand()%26+1] + sectorts;
        sectorindex[i] = sectorwl;
	//if in the possibility of saving to the file, add catch if sudden stop 
	//a catch would be ensuring that both the value has inputted and depected or crash
	std::cout << sectorindex[i] << " "; 
	}
	std::cout << "\n";
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
	*/	
	std::cout << "Which sector do you want to select?\nNOTE: You cannot select any more sectors after this point in this session, unless of course you choose to restart the session.\n";
	//make sure that they know you can restart without selecting another secotr, but they have less of something than they started with, making the option useless in a way 
	std::cin >> sectordec;
    //std::string * sectordecfind;
	/*
	bool sectordecfind (const std::string $sectordec, const std::vector<std::string> &sectorindex);
	{
			//return std::find(sectorindex.begin(), sectorindex.end(), sectordec) != sectorindex.end());
			return std::find(sectorindex.begin, sectorindex.end, sectordec) != sectorindex.end;
	}
	*/
	bool happy = false;
	while (happy == false)
	//move a lot of what is above into here so the user can have choice
	{
	for (int u = 0; u < sectoramnt; u++)
	{
	if (sectordec.compare(sectorindex[u]) == 0)
	{
		std::cout << "You selected sector " << sectordec << "\n";
		selectsector = sectordec;
		std::cout << "Loading information for sector " << selectsector << "\n";
			//IT'S LOADING SECTOR INFORMATION TIME!
			/*
			General format:
			---------------
			Sector Name: <Sector Name>
			Sector Location: <Sector Letter Series>
			Sector Description: <Varies Depending on Sector Letter Series and Number Within>
			---------------
			Verify if this is the sector that the user wants
			If it is not, go to prompt screen.
			*/
			//add the shit above
		std::string happydec = "";
		std::string happydec2= "";
		std::cout << "Are you sure this is the sector you desire?(y | n)\n";
		std::cin >> happydec;
		//std::transform(happydec.begin(), happydec.end(), happydec.begin(), ::tolower);
		if (happydec == "y")
		{
			happy = true;
			std::cout << "true\n";
			break;
		}
		
	}
	}
	}

	return 0;
}
//http://www.cplusplus.com/reference/cstdlib/rand/
