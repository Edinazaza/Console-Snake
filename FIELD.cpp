#include "CManip.h"
#include "FIELD.h"


field GenerateField(size_t sideField)
{
	field result(sideField, std::vector<char>(sideField, ' '));
	for (size_t i = 0; i < sideField; ++i)
	{
		for (size_t j = 0; j < sideField; ++j)
		{
			if (i == 0 || i == sideField - 1)
			{
				result[i][j] = '.';
			}
			else
			{
				result[i][0] = '.';
				result[i][sideField - 1] = '.';
			}
		}
	}
	return result;
}

void PrintGameField(const field& gameField)
{
	bool flag;
	for (size_t sideOne = 0; sideOne < gameField.size(); sideOne++)
	{
		std::cout << std::setw(30);
		flag = true;
		for (size_t sideTwo = 0; sideTwo < gameField.size(); sideTwo++)
		{
			if (!flag)
			{
				std::cout << ' ';
			}
			flag = false;
			if (gameField.at(sideOne).at(sideTwo) == '#' || gameField.at(sideOne).at(sideTwo) == '+')
			{
				ChangeColour(2);
				std::cout << gameField.at(sideOne).at(sideTwo);
				ChangeColour(7);
			}
			else if (gameField.at(sideOne).at(sideTwo) == '@')
			{
				ChangeColour(6);
				std::cout << gameField.at(sideOne).at(sideTwo);
				ChangeColour(7);
			}
			else if (gameField.at(sideOne).at(sideTwo) == '&')
			{
				ChangeColour(4);
				std::cout << gameField.at(sideOne).at(sideTwo);
				ChangeColour(7);
			}
			else if (gameField.at(sideOne).at(sideTwo) == '.')
			{
				ChangeColour(3);
				std::cout << gameField.at(sideOne).at(sideTwo);
				ChangeColour(7);
			}
			else { std::cout << gameField.at(sideOne).at(sideTwo); }
		}
		std::cout << std::endl;
	}
}

void RestartGame(std::vector<size_t>& records, field& area, uint16_t eaten_count)
{
	system("cls");
	ChangeColour(4);
	MessageBeep(MB_OK);
	std::cout << std::endl << std::setw(68) << "You lose, try again, you score:  " << eaten_count << std::endl << std::endl;
	records.push_back(eaten_count);
	ChangeColour(7);
	area.clear();
	main();
}