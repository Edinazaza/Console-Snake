#include "CManip.h"
#include "FIELD.h"
#include "CSnake.h"
#include <conio.h>


void BodyPart::TurnLeft()
{
	if (direction == 0)
	{
		direction = 3;
	}
	else
	{
		direction -= 1;
	}
}

void BodyPart::TurnRight()
	{
		if (direction == 3)
		{
			direction = 0;
		}
		else
		{
			direction += 1;
		}
	}

uint16_t BodyPart::GetX() const
{
	return X;
}

uint16_t BodyPart::GetY() const
{
	return Y;
}

uint16_t BodyPart::GetDirection() const
{
	return direction;
}

void  BodyPart::MoveForward(field& area)
	{
		if (direction == 0) { SetCoordinate('X', -1, area); }	//  up
		if (direction == 1) { SetCoordinate('Y', 1, area); }	// right
		if (direction == 2) { SetCoordinate('X', 1, area); }	// down
		if (direction == 3) { SetCoordinate('Y', -1, area); }	// left
	}

void  BodyPart::SetCoordinate(const char coord, const int change, field& area)
	{
		if (X == 0 || Y == 0 || X == area.size() - 1 || Y == area.size() - 1)
		{
			area[X][Y] = '.';
		}
		else { area[X][Y] = ' '; }
		if (coord == 'X')
		{
			if (X == (area.size() - 1))
			{
				X = 1;
			}
			else if (X == 0)
			{
				X = area.size() - 2;
			}
			else
			{
				X += change;
			}
		}
		else if (coord == 'Y')
		{
			if (Y == (area.size() - 1))
			{
				Y = 1;
			}
			else if (Y == 0)
			{
				Y = area.size() - 2;
			}
			else
			{
				Y += change;
			}
		}
	}




Head::Head() { };
Head::Head(field& area)
	{
		direction = 0;
		area[area.size() / 2][area.size() / 2] = '+';
		X = (area.size() / 2), Y = (area.size() / 2);
	}

uint16_t Head::GetCount() const
	{
		return eaten_count;
	}

bool Head::GetIsDead() const
	{
		return isDead;
	}


bool Head::GetIsEat() const
	{
		return isEat;
	}
	
void Head::Animation(field& area)
	{
		if (direction == 0) { area[X][Y] = '^'; }
		else if (direction == 1) { area[X][Y] = '>'; }
		else if (direction == 2) { area[X][Y] = 'v'; }
		else if (direction == 3) { area[X][Y] = '<'; }
	}

void Head::Eat()
	{
		++eaten_count;
		std::cout << char(7);
	}

void Head::SetCoordinate(const char coord, const int change, field& area)
	{
		BodyPart::SetCoordinate(coord, change, area);
		if (area[X][Y] != '@')
		{
			isEat = false;
			if (area[X][Y] == '&' || area[X][Y] == '#')
			{
				isDead = true;
			}
			else {
				Animation(area);
			}
		}
		else {
			isEat = true;
			Eat();
			Animation(area);
		}
	}


Tail::Tail() {};

Tail::Tail(field& area, size_t i)
	{
		direction = 0;
		area[area.size() / 2][area.size() / 2] = '#';
		X = (area.size() / 2) + i, Y = (area.size() / 2);
	}

Tail::Tail(const uint16_t x, const uint16_t y, const uint16_t dir)
	{
		X = x, Y = y, direction = dir;
	}

void Tail::SetDirection(uint16_t d)
	{
		direction = d;
	}

void Tail::SetCoordinate(const char coord, const int change, field& area)
	{
		BodyPart::SetCoordinate(coord, change, area);
		area[X][Y] = '#';
	}


Snake::Snake(field& area) : head_(area)
	{
		body_.push_back(Tail(area, sizeSnake_++));
	}

void Snake::MoveSnake(field& area)
	{
		head_.MoveForward(area);
		if (head_.GetIsEat()) {
			SpawnBP(area);
		}
		else {
			for (size_t i = 0; i < body_.size(); ++i) {
				body_[i].MoveForward(area);
			}
		}

		for (int i = body_.size() - 1; i >= 0; --i) {
			if (i == 0) {
				if (body_[i].GetDirection() != head_.GetDirection()) {
					body_[0].SetDirection(head_.GetDirection());
				}
			}
			else if (body_[i].GetDirection() != body_[i - 1].GetDirection()) {
				body_[i].SetDirection(body_[i - 1].GetDirection());
			}
		}
	}

void Snake::TurnRight()
	{
		head_.TurnRight();
	}

void Snake::TurnLeft()
	{
		head_.TurnLeft();
	}

uint16_t Snake::GetCount() const
	{
		return head_.GetCount();
	}

uint16_t Snake::GetDirection()
	{
		return head_.GetDirection();
	}

bool Snake::isEat() const
	{
		return head_.GetIsEat();
	}

bool Snake::isDead() const
	{
		return head_.GetIsDead();
	}

void Snake::SpawnBP(field& area)
	{
		Tail bp(body_[body_.size() - 1].GetX(),
			body_[body_.size() - 1].GetY(),
			body_[body_.size() - 1].GetDirection());
		for (size_t i = 0; i < body_.size(); ++i) {
			body_[i].MoveForward(area);
		}
		body_.push_back(bp);
	}



void CatchCommand(Snake& player, char chr)
{
	size_t side = player.GetDirection();
	if (side == 0 && (chr == 'd' || chr == 'D')) {
		player.TurnRight();
	}
	else if (side == 0 && (chr == 'a' || chr == 'A')) {
		player.TurnLeft();
	}
	else if (side == 1 && (chr == 'w' || chr == 'W')) {
		player.TurnLeft();
	}
	else if (side == 1 && (chr == 's' || chr == 'S')) {
		player.TurnRight();
	}
	else if (side == 2 && (chr == 'a' || chr == 'A')) {
		player.TurnRight();
	}
	else if (side == 2 && (chr == 'd' || chr == 'D')) {
		player.TurnLeft();
	}
	else if (side == 3 && (chr == 'w' || chr == 'W')) {
		player.TurnRight();
	}
	else if (side == 3 && (chr == 's' || chr == 'S')) {
		player.TurnLeft();
	}
	else if (chr == 'r' || chr == 'R') {
		system("cls");
		main();
	}
}