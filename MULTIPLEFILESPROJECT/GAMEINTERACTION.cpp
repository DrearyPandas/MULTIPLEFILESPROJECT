
#include <iostream> //allows me to input and output
#include <string> //allows me to use strings
#include <algorithm> // allows me to do fancy string magic like making a string uppercase 
using namespace std; // makes it so i dont have to type std so much

// did you win or not
bool escaped = false;

// objects existence in environment
bool paper = false; //initializes variable at false
bool pencil = false;//initializes variable at false
bool money = false;//initializes variable at false
bool key = false;//initializes variable at false

// states for objects
bool phoneCall = false;//initializes variable at false
bool tableOpen = false;//initializes variable at false
bool writtenPaper = false;//initializes variable at false
bool gotNumber = false;//initializes variable at false
bool doorLocked = true;//initializes variable at true

void look(string object) // function to determine what the player is trying to look at and gives them a description
{
	if (object == "CHAIR")
	{
		if (paper)
		{
			cout << "The recliner's cushion is still on the floor from when you searched it"; // prints text to console
		}
		else
		{
			cout << "It's a bright red recliner leaning up against one of the walls.\n";// prints text to console
		}

	}
	else if (object == "DOOR")
	{
		cout << "It's a sturdy wooden DOOR, locked and with no way to break it down.\n";// prints text to console
	}
	else if (object == "TABLE")
	{
		cout << "Its a small wooden TABLE with a PHONE on top of it. There is a sliding drawer on the side.\n";// prints text to console
	}
	else if (object == "PAINTING")
	{
		if (money)
		{
			cout << "The PAINTING is still on the floor from when you searched it.\n";// prints text to console
		}
		else
		{
			cout << "It's a PAINTING of a crowned man in a loincloth. He seems very energetic.\n";// prints text to console
		}

	}
	else if (object == "VACUUM TUBE")
	{
		cout << "It is a VACUUM TUBE system commonly seen in banks and mail rooms used to transport documents and small objects.\n";// prints text to console
	}
	else if (object == "PHONE")
	{
		cout << "It is a bright red corded PHONE with a standard 0-9 keypad including * and #. You try to dial for the police, but it says an invalid number has been dialed.\n";// prints text to console
	}
	else if (object == "WINDOW")
	{
		cout << "The WINDOW runs from the floor to the ceiling, and has a curtain in front of it. Moving the curtain to the side, you can see a cityscape. You wont survive the fall if you try to break out this way.\n";// prints text to console
	}
	else if (object == "ROOM")
	{
		cout << "The room is a small square, with bright blue walls, a brown DOOR, a red CHAIR, a TABLE with a PHONE on top of it, a PAINTING, a VACUUM TUBE system, a blue and white checker-boarded floor, and a WINDOW.\n";// prints text to console
	}
	else if (object == "PENCIL")
	{
		if (pencil)
		{
			cout << "It is a normal #2 PENCIL.\n";// prints text to console
		}

	}
	else if (object == "MONEY")
	{
		if (money)
		{
			cout << "It is a 100$ bill.\n";// prints text to console
		}

	}
	else if (object == "KEY")
	{
		if (key)
		{
			cout << "It is a small KEY to fit into a DOOR lock.\n";// prints text to console
		}

	}
	else if (object == "PAPER")
	{
		if (paper)
		{
			cout << "A standard sheet of 8.5x11 inch PAPER.\n";// prints text to console
		}
		if (writtenPaper)
		{
			cout << "Written on the PAPER are the words HELP ME.\n";// prints text to console
		}
		if (gotNumber)
		{
			cout << "Written on the PAPER are the words HELP ME with a red skull and crossbones drawn in-between the words HELP and ME.\n";// prints text to console
		}

	}
}


void use(string object) // this function determines the objects which the player is trying to use together or to activate and performs their functions
{
	string userInput; // holds the user's input for this function

	if (object == "PHONE")
	{
		if (!phoneCall)
		{
			cout << "What number will you dial?\n";// prints text to console
			getline(cin, userInput); // gets user input
			if (userInput == "4357*63") // THIS IS THE CODE FOR THE PHONE ITS SUPER IMPORTANT
			{
				cout << "You dial the number, and the PHONE begins ringing. After a short while, the PHONE is answered and a man whispers 'Okay'. After this, he hangs up.\n";// prints text to console
				phoneCall = true;// changes boolean to true
			}
			else
			{
				cout << "The PHONE number you entered was invalid.\n";// prints text to console
			}
		}
		else
		{
			cout << "Every number you try to dial ends up being invalid except for the one you have on the PAPER. However, the man will not answer the PHONE.\n";// prints text to console
		}

	}
	else if (object == "TABLE")
	{

		if (tableOpen)
		{
			cout << "You close the TABLE's drawer\n";// prints text to console
		}
		else
		{
			cout << "You open the TABLE's drawer\n";// prints text to console
			tableOpen = true;// changes boolean to true
		}
	}
	else if (object == "PENCIL")
	{
		if (pencil)
		{
			cout << "Use PENCIL on what?\n";// prints text to console
			getline(cin, userInput);// gets user input
			transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase
			if (userInput == "PAPER")
			{
				if (paper)
				{
					if (!writtenPaper)
					{
						if (!gotNumber)
						{
							cout << "You write the words HELP ME on the PAPER.\n";// prints text to console
							writtenPaper = true;// changes boolean to true
						}
						else
						{
							cout << "You've already gotten a response from your captor.";// prints text to console
						}

					}
					else
					{
						cout << "You've already written the words HELP ME on the PAPER.\n";// prints text to console
					}
				}
				else
				{
					cout << "You don't have any PAPER to write on.\n";// prints text to console
				}
			}
			else
			{
				cout << "You cannot find a reason to write on that.\n";// prints text to console
			}
		}

	}
	else if (object == "PAPER")
	{
		if (paper)
		{
			cout << "Use paper with what?\n";// prints text to console
			getline(cin, userInput);// gets user input
			transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase
			if (userInput == "PENCIL")
			{
				if (pencil)
				{
					if (writtenPaper)
					{
						cout << "You've already written HELP ME on the paper.\n";// prints text to console
					}
					else
					{
						if (!gotNumber)
						{
							cout << "You write the words HELP ME on the paper\n";// prints text to console
							writtenPaper = true;// changes boolean to true
						}
						else
						{
							cout << "You've already gotten a response from your captor.";// prints text to console
						}
					}
				}
				else
				{
					cout << "You don't have a pencil to write with.\n";// prints text to console
				}
			}
			else if (userInput == "VACUUM TUBE")
			{
				if (writtenPaper)
				{
					cout << "You send the paper up the vacuum tube and after a few minutes it returns. Inside the container is the same piece of paper, with a red skull and crossbones drawn in-between the words HELP and ME. You wonder what it could mean.\n";// prints text to console
					gotNumber = true;// changes boolean to true
					writtenPaper = false;// changes boolean to false
				}
				else
				{
					cout << "You send the paper up the vacuum tube and after a very short while it returns. Inside the container is the same piece of paper. It has obviously been unfolded, but no changes were made.\n";// prints text to console
				}
			}
			else
			{
				cout << "You cannot find a reason to use the paper in such a way.\n";// prints text to console
			}
		}
		else
		{
			cout << "You don't have any paper.\n";// prints text to console
		}

	}
	else if (object == "KEY")
	{
		if (key)
		{
			cout << "Use key with what?\n";// prints text to console
			getline(cin, userInput);// gets user input
			transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase

			if (userInput == "DOOR")
			{
				cout << "You use the key in the door and the door unlocks.\n";// prints text to console
				doorLocked = false;// changes boolean to false
			}
			else if (userInput == "VACUUM TUBE")
			{
				cout << "Why would you want to do that?\n";// prints text to console
			}
			else
			{
				cout << "You cannot find a reason to use the key in this way.\n";// prints text to console
			}
		}
		else
		{
			cout << "You don't have a key.\n";// prints text to console
		}


	}
	else if (object == "VACUUM TUBE")
	{
		cout << "Use VACUUM TUBE with what?\n";// prints text to console
		getline(cin, userInput);// gets user input
		transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase

		if (userInput == "PAPER")
		{
			if (paper)
			{
				if (writtenPaper)
				{
					cout << "You send the PAPER up the VACUUM TUBE and after a few minutes it returns. Inside the container is the same piece of paper, with a red skull and crossbones drawn in-between the words HELP and ME. You wonder what it could mean.\n";// prints text to console
					gotNumber = true;// changes boolean to true
					writtenPaper = false;// changes boolean to false
				}
				else
				{
					cout << "You send the PAPER up the VACUUM TUBE and after a very short while it returns. Inside the container is the same piece of PAPER. It has obviously been unfolded, but no changes were made.\n";// prints text to console
				}
			}
			else
			{
				cout << "You don't have any PAPER to put in the VACUUM TUBE.\n";// prints text to console
			}

		}
		else if (userInput == "MONEY")
		{
			if (money)
			{
				if (phoneCall)
				{
					cout << "You send the MONEY up the VACUUM TUBE and after a few minutes it returns. Inside the container is a small KEY.\n";// prints text to console
					key = true;// changes boolean to true
					money = false;// changes boolean to false
				}
				else
				{
					cout << "You send the MONEY up the VACUUM TUBE and after a very short while it returns. Inside the container is the same piece of currency.\n";// prints text to console
				}
			}
			else
			{
				cout << "You don't have any MONEY to put into the VACUUM TUBE.\n";// prints text to console
			}

		}
		else if (userInput == "KEY")
		{
			if (key)
			{
				cout << "Why would you want to do that?\n";// prints text to console
			}
			else
			{
				cout << "You don't have a KEY to put in the VACUUM TUBE.\n";// prints text to console
			}
		}
		else
		{
			cout << "You cannot fit this object in the VACUUM TUBE.\n";// prints text to console
		}

	}
	else if (object == "DOOR")
	{
		if (doorLocked)
		{
			cout << "The DOOR is locked.\n";// prints text to console
		}
		else
		{
			cout << "You open the DOOR, escaping the room. You run down the hallway, down the stairs and out of the building into the street. You hail a taxi, and ride to the nearest police station to report the incident.\n";// prints text to console
			escaped = true;// changes boolean to true
		}
	}
	else if (object == "MONEY")
	{
		if (money)
		{
			cout << "Use MONEY with what?\n";// prints text to console
			getline(cin, userInput);// gets user input
			transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase
			if (userInput == "VACUUM TUBE")
			{
				if (phoneCall)
				{
					cout << "You send the MONEY up the VACUUM TUBE and after a few minutes it returns. Inside the container is a small KEY.\n";// prints text to console
					key = true;// changes boolean to true
					money = false;// changes boolean to false
				}
				else
				{
					cout << "You send the MONEY up the VACUUM TUBE and after a very short while it returns. Inside the container is the same piece of currency.\n";// prints text to console
				}
			}
			else
			{
				cout << "You cannot find a reason to use the MONEY in this way.";// prints text to console
			}
		}
		else
		{
			cout << "You don't have any MONEY.\n";// prints text to console
		}

	}
	else
	{
		cout << "You can't find a way to use that with anything else.";// prints text to console
	}
}

void search(string object)
{
	if (object == "ROOM")
	{
		cout << "You look about the ROOM, but cannot find anything more than your general surroundings.\n";// prints text to console
	}
	else if (object == "DOOR")
	{
		cout << "You search around the DOOR, but find nothing.\n";// prints text to console
	}
	else if (object == "CHAIR")
	{
		if (paper)
		{
			cout << "You have already searched the CHAIR and found the PAPER.";// prints text to console
		}
		else
		{
			cout << "You search the CHAIR, and after picking off the cushion you discover a piece of PAPER.\n";// prints text to console
			paper = true;// changes boolean to true
		}
	}
	else if (object == "WINDOW")
	{
		cout << "You search about the WINDOW but cannot find anything of use.\n";// prints text to console
	}
	else if (object == "PAINTING")
	{
		if (money)
		{
			cout << "You have already found the MONEY taped behind the PAINTING.\n";// prints text to console
		}
		else
		{
			cout << "You manage to wiggle the PAINTING off of the frame it is held on, and discover some MONEY taped to the wall behind it.\n";// prints text to console
			money = true;// changes boolean to true
		}
	}
	else if (object == "VACUUM TUBE")
	{
		cout << "The VACUUM TUBE is empty.\n";// prints text to console
	}
	else if (object == "PHONE")
	{
		cout << "The PHONE has nothing of interest hidden near or around it.\n";// prints text to console
	}
	else if (object == "TABLE")
	{
		if (tableOpen)
		{
			if (pencil)
			{
				cout << "You already found the PENCIL in the drawer.\n";// prints text to console
			}
			else
			{
				cout << "You search the drawer of the TABLE and find a single PENCIL.\n";// prints text to console
				pencil = true;// changes boolean to true
			}

		}
		else
		{
			cout << "You look about the TABLE, but cannot find anything of interest outside of its drawer.\n";// prints text to console
		}
	}
	else
	{
		cout << "You find nothing.\n";// prints text to console
	}

}


void tutorial()
{
	cout << "Welcome to the Blue Chamber\n\n";// prints text to console
	cout << "Your objective is to solve the puzzle in order to escape the room you are trapped inside by searching for tools and using them in the correct manner.\n";// prints text to console
	cout << "In order to interact with the game, use the commands USE, LOOK, and SEARCH.\n";// prints text to console
	cout << "Any objects you can interact with will be written in CAPITAL LETTERS.\n";// prints text to console
	cout << "Use these commands and enter in any additional information afterwards to interact.\n\n";// prints text to console
	cout << "EXAMPLE: Use.  Use what?  Gun.  Use gun where? Tree. You shoot the gun at the tree.\n";// prints text to console
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";// prints text to console
}

bool gamePlay()
{

	bool replay = true; //initializes variable at true
	string userInput; // stores user input

	cout << "You awaken in an unknown ROOM. You cannot remember how you got here. All you know is that you are trapped and must escape.\n";// prints text to console
	cout << "You LOOK around the ROOM, and see that the ROOM is a small square with bright blue walls, a brown DOOR, a red CHAIR, a TABLE with a PHONE on top of it, a VACUUM TUBE, a PAINTING, a blue and white checker-boarded floor, and a WINDOW.\n";// prints text to console


	while (!escaped)
	{
		cout << "\nWhat will you do?\n";// prints text to console
		getline(cin, userInput);// gets user input
		transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase


		if (userInput == "USE")
		{
			cout << "Use what?\n";// prints text to console
			getline(cin, userInput);// gets user input
			transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase
			use(userInput); // calls the use fucntion with the parameter of userinput
		}
		else if (userInput == "LOOK")
		{
			cout << "Look at what?\n";// prints text to console
			getline(cin, userInput);// gets user input
			transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase
			look(userInput);// calls the look function with the parameter of userinput
		}
		else if (userInput == "SEARCH")
		{
			cout << "Search what?\n";// prints text to console
			getline(cin, userInput);// gets user input
			transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase
			search(userInput);// calls the search function with the parameter of userinput
		}
		else
		{
			cout << "\nSorry, didn't understand that. Make sure to use the commands given at the start of the program.\n";// prints text to console
		}
	}

	if (escaped)
	{
		cout << "\n\n\n\n\n----------------------------------------------------------------------------------------------------\n\n";// prints text to console
		cout << "Congratulations, you've won! Would you like to replay the game? Enter Yes, or No.\n";// prints text to console
		getline(cin, userInput);// gets user input
		transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);// makes userinput uppercase
		if (userInput != "YES")
		{
			replay = false;// changes boolean to false
		}
		else
		{
			cout << "Resetting Game........";// prints text to console
			phoneCall = false; // changes boolean to false
			tableOpen = false;// changes boolean to false
			writtenPaper = false;// changes boolean to false
			gotNumber = false;// changes boolean to false
			doorLocked = true;// changes boolean to false
			paper = false;// changes boolean to false
			pencil = false;// changes boolean to false
			money = false;// changes boolean to false
			key = false;// changes boolean to false
			escaped = false;// changes boolean to false

			system("pause");
			cout << "\n\n\n\n\n\n\n\n\n\n\n";// prints text to console
		}
	}
	return replay; // returns the game continuation variable
}