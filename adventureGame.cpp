#include "adventureGame.h"

#include <iostream> //provides basic input and output services
#include <string> //provides string services
#include <ctime> //for my random generater to generate somthing new everytime. Resets time
// input types of variables
using std::cout; //output value
using std::cin; //input value
using std::endl; //inserts a new line
using std::string; //varables with characters

int game(std::string* leader)
{
	//set varaibles and name them
	const int Diamonds = 614;
	int adventurers, killed, survivors;
	//Array for weapons and materials
	string weapons[4] = { "Ninja Stars", "Guns", "Swords", "SledgeHammers" };
	string materials[4] = { "trees", "shoes", "rocks", "BirthdayCake" };

	//output asking for information
	cout << "Welcome to Jumanji\n\n";
	cout << "Please enter the following for your personalized adventure\n";
	//User inputs number and saves it to the variable advanturers
	cout << "Enter a number: ";
	cin >> adventurers;
	//User inputs number and saves it to the variable killed
	cout << "Enter a number, smaller than the first: ";
	cin >> killed;
	//set variables to equation to determine how many survivors are left 
	survivors = adventurers - killed;
	// Get the system time.
	unsigned seed = time(NULL);
	// Seed the random number generator.
	srand(seed);
	// credit int var for the random generator
	int index = rand() % 4;
	string weapon = weapons[index]; //random generator to choose how of the weapons array
	string material = materials[index]; //random generator to choose how of the materials array


	//tell the story and input the set variables
	cout << "\n When a group of  " << adventurers << " nerds decide to play a vintage game console, their lives changed. ";
	cout << "Their goal was to complete the game by conquering the dragon named, Paarthurnax. ";
	cout << "The group was led by that legendary ninja warrior that was amazing at crafting anything out of any type of materials, " << *leader << ".";

	cout << "\nAs they were surrounding the mighty Paarthurnax, goblins started attacking. ";
	cout << *leader << " with their amazing craftings skills crafting the whole team "<<weapon <<" out of "<<material << ".";
	cout << " Eveyone fought hard and strong with the "<<weapon <<" that " << *leader <<" created. ";
	cout << "The goblins were defeated but they did not go down without a fight. ";
	cout << "Of the adventurers, " << killed << " were vanquished, ";
	cout << "only " << survivors << " were left but they were ready to take down Paarthurnax.";

	cout << "As the remaining "<< survivors <<" survivors were beating up Paarthurnax with their "<<weapon <<". ";
	cout << *leader << " took out Parthurnax with the final blow to the eye."; 
	cout << " Once the dragon was dead it exploded into diamonds.";
	cout << "So the adventurers split " << Diamonds << " diamonds.";
	cout << *leader << " held on to the extra " << (Diamonds % survivors);
	cout << " pieces to keep things fair of course.";

	return 0;
}

