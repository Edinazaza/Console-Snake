#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <windows.h>

void ChooseDifficulty(char dflvl);

void PrintGreeting(std::vector<size_t>& records);

void PrintInstriuction();

void PrintInterface(const Snake& h, char dflvl, std::vector<size_t>& records);