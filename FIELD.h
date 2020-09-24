#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <windows.h>

typedef std::vector<std::vector<char>> field;

field GenerateField(size_t X); // creating two-dimensional array(game field)
void PrintGameField(const field& gameField);
void RestartGame(std::vector<size_t>& records, field& area, uint16_t eaten_count);