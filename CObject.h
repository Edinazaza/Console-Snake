#pragma once
#include <utility>
#include <cstdint>
#include <ctime>

class Food
{
public:
	void Spawn(field& area);

private:
	std::pair<size_t, size_t> RandCoordinates(const size_t size);
	const char food_ = '@';
	bool existance = false;
};

class Obstacle
{
public:
	void Spawn(field& area);

	void SpawnObs(field& area, char dflvl);

private:
	std::pair<size_t, size_t> RandCoordinates(const size_t size);
	const char obstacle_ = '&';
};