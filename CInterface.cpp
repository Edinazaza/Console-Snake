#include "CManip.h"
#include "CSnake.h"
#include "CObject.h"
#include "CInterface.h"
#include <string>


void ChooseDifficulty(const char dflvl)
{
	std::string cmd;
	switch (dflvl)
	{
	case '1':
		Sleep(50);
		break;
	case '2':
		Sleep(25);
		break;
	case '3':
		Sleep(15);
		break;
	case '`':
		//Sleep(0);
		break;
	case '*':
		std::cin >> cmd;
		if (cmd == "kill")
		{
			system("cls");
			ChangeColour(4);
			MessageBeep(MB_OK);
			std::cout << std::endl << std::setw(66) << "You were killed by console" << std::endl << std::endl;
			ChangeColour(7);
			main();
			break;
		}
	default:
		Sleep(25);
		break;
	}
}

void PrintGreeting(std::vector<size_t>& records)
{
	std::vector<std::string> phrases = {   "         Paskal is better          ", "     Ye, I`m developed on C++      ",
	"This project cost about $ 1 million", " Turns is the most difficult part  ", "          Hello, world!            ",
	"           Return bool             ", "From __future__ import time_travel ", "    Completly original product     ",
	"     Not stolen from Minecraft     ", "           Still working           ", "        Who is the rabbit?         ",
	"Developed by K.N and B.F and Nikita", "          Here was Nikita          ", "           I wanna pitsa           ",
	"          ANTISLEEP CLUB           ", "    Development lasted 10 years    ", "           Python 4 gays           " };
	ChangeColour(2);
	std::cout
		<< std::setw(71) << " ####   ##  ##   ####   ##  ##  #####" << std::endl
		<< std::setw(71) << "##      ### ##  ##  ##  ## ##   ##   " << std::endl
		<< std::setw(71) << " ####   ## ###  ######  ####    #####" << std::endl
		<< std::setw(71) << "    ##  ##  ##  ##  ##  ## ##   ##   " << std::endl
		<< std::setw(71) << " ####   ##  ##  ##  ##  ##  ##  #####" << std::endl
		<< std::endl;
	ChangeColour(7);

	std::cout
		<< std::setw(71) << "#===================================#" << std::endl
		<< std::setw(71) << "|   Choose the difficulty level:    |" << std::endl
		<< std::setw(71) << "|===================================|" << std::endl
		<< std::setw(71) << "|  Press '1' to choose easy level   |" << std::endl
		<< std::setw(71) << "| Press '2' to choose medium level  |" << std::endl
		<< std::setw(71) << "|  Press '3' to choose hard level   |" << std::endl
		<< std::setw(71) << "#===================================#" << std::endl;
	std::cout << std::endl << std::setw(58) << "Version 0.19b" << std::endl;
	srand(static_cast<uint16_t>(time(NULL)));
	size_t res = rand() % 17;
	std::cout << std::endl << std::setw(70) << phrases[res] << std::endl;
	sort(records.begin(), records.end());
	if (!records.empty())
	{
		size_t count = 1;
		std::cout << std::endl;
		ChangeColour(6);
		std::cout << std::setw(57) << "Scores \n";
		ChangeColour(7);
		std::cout << std::setw(59) << "==============" << std::endl;
		for (auto it = records.rbegin(); it != records.rend(); ++it, ++count)
		{
			if (count >= 10) { break; }
			if (*it < 9)
			{
				std::cout << std::setw(47) << '|' << count << " place: " << *it << " |" << std::endl;
			}
			else
			{
				std::cout << std::setw(47) << '|' << count << " place: " << *it << '|' << std::endl;
			}
		}
		std::cout << std::setw(59) << "==============" << std::endl;
	}

	InvisibleCursor();
}

void PrintInstriuction()
{
	std::cout << std::endl
		<< std::setw(97) << "#===================================================================================#" << std::endl
		<< std::setw(97) << "|                                    Instuction                                     |" << std::endl
		<< std::setw(97) << "|===================================================================================|" << std::endl
		<< std::setw(97) << "|Use (a) to turn left and (d) to turn right, (w) turn up, (s) turn down, (r) restart|" << std::endl
		<< std::setw(97) << "|         Symbols: (+) - head, (#) - body part, (@) - food, (&) - obstacle          |" << std::endl
		<< std::setw(97) << "#===================================================================================#";
}

void PrintInterface(const Snake& h, char dflvl, std::vector<size_t>& records)
{
	std::cout << "|Score: " << h.GetCount() << '|';
	if (dflvl == '1')      { std::cout << std::setw(57) << "|difficulty level - easy|"; }
	else if (dflvl == '2') { std::cout << std::setw(57) << "|difficulty level - medium|"; }
	else if (dflvl == '3') { std::cout << std::setw(57) << "|difficulty level - hard|"; }
	else if (dflvl == '`') { std::cout << std::setw(57) << "|difficulty level - SecretLvl|"; }
	else { std::cout << std::setw(57) << "|difficulty level - default|"; };
	if (records.empty()) { std::cout << "                        High score: 0" << std::endl; }
	else {
		sort(records.begin(), records.end()); std::cout << "                        High score: " << records[records.size() - 1] << std::endl;
	}
}