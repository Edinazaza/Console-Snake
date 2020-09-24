#include "FIELD.h"
#include "CObject.h"


void Food::Spawn(field& area)
{
	while (true)
	{
		std::pair<size_t, size_t> cord = RandCoordinates((area.size() - 1));
		if (area[cord.first][cord.second] == ' ') {
			area[cord.first][cord.second] = food_;
			existance = true;
			break;
		}
	}
}

std::pair<size_t, size_t> Food::RandCoordinates(const size_t size)
{
	size_t X = rand() % size + 1;
	size_t Y = rand() % size + 1;
	return std::make_pair(X, Y);
}

void Obstacle::Spawn(field& area)
{
	while (true)
	{
		std::pair<size_t, size_t> cord = RandCoordinates(area.size());
		if (area[cord.first][cord.second] == ' ' && (cord.second != area.size() / 2 ))
		{
			area[cord.first][cord.second] = obstacle_;
			break;
		}
	}
}

void Obstacle::SpawnObs(field& area, char dflvl)
{
	switch (dflvl)
	{
	case '1':
		for (size_t i = 0; i < 7; i++)
		{
			Spawn(area);
		}
		break;
	case '2':
		for (size_t i = 0; i < 12; i++)
		{
			Spawn(area);
		}
		break;
	case '3':
		for (size_t i = 0; i < 15; i++)
		{
			Spawn(area);
		}
		break;
	case '`':
		for (size_t i = 0; i < 30; i++)
		{
			Spawn(area);
		}
		break;
	default:
		for (size_t i = 0; i < 5; i++)
		{
			Spawn(area);
		}
		break;
	}
}

std::pair<size_t, size_t> Obstacle::RandCoordinates(const size_t size)
{
	size_t X = rand() % size;
	size_t Y = rand() % size;
	return std::make_pair(X, Y);
}
