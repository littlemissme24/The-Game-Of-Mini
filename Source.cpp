#include <iostream>
#include <iostream>
#include <chrono>
#include <thread>

#include "TextBasedAdventure.h"
#include "Person.h"
#include "Tool.h"
#include "TTT.h"
#include "adventureGame.h"

void Speed();

Person initPerson()
{
	Person temp;
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;

	temp.SetName(name);
	return temp;
}


int main()
{

	bool driver = true;
	Person person = initPerson();
	std::cout << "Welcome to my land of mini-games. Here you can select which mini game you want to play" << std::endl;

	while (driver == true)
	{

			system("cls");
			int usrOpt1 = 0;
			std::cout << "What game do you want to play?\n1) Tic Tac Toe(2 player game)\n2) Reflexes\n3) Adventure Game \n4) Text Based Adventure Game  " << std::endl;
			std::cin >> usrOpt1;

			std::string name = person.GetName();
			try
			{
				if (usrOpt1 == 1)
				{

					TTT * newTTT = new TTT;
					newTTT->ttt();
			
					delete newTTT;
				}
				if (usrOpt1 == 2)
				{
					Speed();
				}
				if (usrOpt1 == 3)
				{
					std::thread t1(game, &name);
					t1.join();
				}
				if (usrOpt1 == 4)
				{
					std::thread t2 (game2, name);
					t2.join();
				}

				std::cout << "\n\n\nDo you want to play again? (y/n) " << std::endl;
				char usrOpt2;
				std::cin >> usrOpt2;
				if (usrOpt2 == 'n')
				{
					driver = false;
				}
			}

			catch (const std::exception&)
			{

		}
	} 

	return 0;
}

void Speed()
{
	using namespace std::chrono;
	std::cout << "Welcome to Speed! Speed is a game where you will have to press the given letter key as fast as possible. \n To enter your selected key, simply press enter after pressing the key, this will count towards your time, so try to do it quickly. \n The time of completion will be displayed once you complete each key."<< endl;
	bool driver = true;
	char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', };
	

	do
	{
		Tool tools;
		char usrOpt = ' ';
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		int rand = tools.RNG(0, 25);
	
		std::cout << "Press " << letters[rand];
		std::cin >> usrOpt;

		if (usrOpt == letters[rand])
		{
			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

			std::cout << " You did it you pressed " << letters[rand] << " in ";
			std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[micro seconds]" << std::endl;
			driver = false;

		}
		else
		{
			std::cout << "Incorrect" << std::endl;
		}

	} while (driver = true);

}