//If anyone dares to look at this file, compile with -std=c++11 and -lncurses (ncurses not required as of now)
//If in the possibility of saving to the file, add catch if sudden stop a catch would be ensuring that both the value has inputted and depected ??? or crash
//make sure that they know you can restart the game without selecting another sector, but they have less of something than they started with, making the option useless in a way to the user 
/***FIX DUPLICATES IN THE SECTOR INDEX***/
/****EXPLANATIONS OF THE GLOBAL VARIABLES ARE PROVIDED IN THE global.h FILE LOCATED IN THIS SAME DIRECTORY AS THIS ONE AS OF NOW****/
#include <iostream>
#include <stdlib.h> /* prinf(), scanf(), puts, NULL, rand, srand*/
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
	srand(time(NULL)); //starts the instance of random
	sectoramnt = rand() % 100 + 1; //sectoramnt equals a random number from 1 to 100 (verify on that)
	//std::string sectorindex [sectoramnt];
	//std::cout << "It's nuclear war time!\n";
	std::cout << "Sectors:\n"; 
/***THE LOOP THAT PUTS VARIABLES INTO THE INDEX STARTS HERE***/
	for (int i = 0; i < sectoramnt; i++) //for loop iterates for whatever number of times defined by sectoramnt
	{
		sector = rand() % 100 + 1; //sector equals a random number from 1 to 100 (verify on that) 
		//TODO add special snowflake status if the program fucks up and causes number fluctuation **fix position of this TODO statement 
		sectorts = std::to_string(sector); //sectorts, or sector to string, converts the random number that is sector to a string
		//sectorjl = sectorletter[rand()%26+1];
		//sectorwl = sectorjl + sectorts;
		//the reason for 26 is because it needs to choose a letter for every value that is in the letter array
		sectorwl = sectorletter[rand()%26+0] + sectorts; //sectorwl, or sector with letter, equals a value in the array, sectorletter, that is decided by a randomly generated vaule in the range of 0 to 26 
		sectorindex[i] = sectorwl; //the array, sectorindex, will iterate the index because of the above for loop. This iteration of the index will equal sectorwl 
		std::cout << sectorindex[i] << " "; //this is where the output of sectors comes from as since the values have just been inputted into the sectorindex array, they can now be displayed in the same iteration
	}
	std::cout << "\n"; //makes a new line for separation
	
/***DECISION TIME FOR SELECTING THE RIGHT SECTOR STARTS HERE***/
	while (happy == false) //this loop is for the user to continually make a decision without possibility or fear being kicked out due to the fault of the program
	{
		std::cout << "Which sector do you want to select?\nNOTE: You cannot select any more sectors after this point in this session, unless of course you choose to restart the session. (You can keep the sector that you select into the next restart but you'll be losing <insert waht they'll be losing>)\n";
		std::cin >> sectordec; //remember, above this input are the generated sectors, now we are deciding\, with the variable sectordec or sector decision, which sector to choose, but in our perspective (not the user's) we are choosing a sector that will then have information extracted with it 
		for (int u = 0; u < sectoramnt; u++) //this for loop will loop from 0 to whatever number was generated to have sectoramnt to be equal with it
		{
			if (sectordec.compare(sectorindex[u]) == 0 && sectorindex[u] != "\0") //**the usefulness of this is questionable, but this will check to see if there are any differences between the sectordec and the sectorindex whom's item index is the same as the current iteration && if the current index of sectorindex is not equal to a space, it's just here just in case something goes wrong up there, but wait hold on ,this is fucking awful, if the decided sector doesn't equal the current index of sectorindex, then it's going to fail and go to this point again until it does equal, meaning that if there was a duplicate somewhere, it would go to the first one, this sucks and should be fixed for fucks sake, I'm not an idiot, I'm just retarded. 
			{
				std::string happydec = ""; //happydec is declared and initialized with an empty string for question that is below 
				std::cout << "You selected sector " << sectordec << "\n"; //reminds the player what they selected for verification and trust of the program, "If the program cnan get this right, then what can it get wrong?"
				selectsector = sectordec; //**the usefulness of selectsector is questionable but it now equals whatever sectordec equals 
					/***IT'S LOADING SECTOR INFORMATION TIME!***/
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
					sectorjl = selectsector.substr(0,1); //sectorjl or sector just letter consists of the selected sector having substr applied to it in which the selection of the string is 0 to 1 which results in the letter portion of the string
					sectorjn = selectsector.substr(1, selectsector.length()); //sectorjn or sector just number consists of the selected sector having substr applied to it in which the selection of the string is 1 to the length of selectsector single the number portion could either be single digit, double digit, or triple digit. In case you haven't figured it out by now, this is for the number portion of the string  			
					std::cout << "Sector Name: " << selectsector << "\nSector Series: " << sectorjl << "\nSector Location in Series: " << sectorjn << "\nSector Description: " << desc << "\n"; //This bit compiles a lot together, This takes the sector name [selectsector] (temporarily selectsector; will eventually change to something more unique), the sector letter [sectorjl] which will identify the sector series (the sectors with the same letter (A-Z) are in the same series), the sector number [sectorjn] which will identify the location in the sector series, and the sector description which is currently blank, but eventually each series (A-Z) will have their own unique description and the description will dynamically change, according to the main description, depending on the location in the series  
					std::cout << "Are you sure this is the sector you desire?(y | n)\n"; //It's important for verification, it's annoying for new users who experiment to test a method for something in which they are actually testing a "final product". Possibly allow to disable verification through cli arguments
					std::cin >> happydec; //this is the question that was supposed to come soon, happydec is named happy dec because it makes the user, at least the new user happy for verification 
					/***add a to lowercase function***/
					if (happydec == "y") //this currently only checks to see if happydec is equal to the string "y". I think, I may very well be incorrect on this, but since there is only y, if anything else is entered it will just go back to the beginning of this embeded loop.
					{
						happy = true; //since the verification is satisfied, happy will now equal true and break out of the main while loop, note how it doesn't break out immediately
						std::cout << "Initializing match for selected sector " << selectsector << "...\n"; //This is telling the user what is going on 
						ClearScreen(); //this calls the ClearScreen() function which is specified in global.h, but it's for scrolling which enhances the user experience
						break; //***DO EXPERIMENTATION this breaks out of the current look but I wonder why since I alrady halled happy = true, need to do experiments to see whether this is worth being here, but it's probably not 
					}
			}
		}
	}	
	std::cout << "Move: " << moves << "\n"; //this displays the current move, this shouldn't be here, it should be in a loop that would increment this
	/***EXPERIMENTAL SORTING STARS HERE COMMENTATION CEASES***/
	int a[100];
	int temp;
	//crappy excuse for a buffer
	bool satis = false;
	for (int i = 0; i < sectoramnt; i++) //this for loop is supposed to sort all the letters	
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
