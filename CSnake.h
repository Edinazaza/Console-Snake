#pragma once
#include "FIELD.h"
#include <vector>

class BodyPart
{
public:
	virtual void TurnLeft();

	virtual void TurnRight();


	virtual uint16_t GetX() const;

	virtual uint16_t GetY() const;

	virtual uint16_t GetDirection() const;

	virtual void MoveForward(field& area);

protected:
	uint16_t X = NULL;
	uint16_t Y = NULL;
	uint16_t direction = NULL;

	virtual void SetCoordinate(const char coord, const int change, field& area);
};


class Head : public BodyPart
{
public:
	Head();
	Head(field& area);

	uint16_t GetCount() const;

	bool GetIsDead() const;


	bool GetIsEat() const;

private:
	uint16_t eaten_count = 0;

	bool isEat = false;

	bool isDead = false;

	void Animation(field& area);

	void Eat();

	void SetCoordinate(const char coord, const int change, field& area) override;
};

class Tail : public BodyPart
{
public:
	Tail();

	Tail(field& area, size_t i);

	Tail(const uint16_t x, const uint16_t y, const uint16_t dir);

	void SetDirection(uint16_t d);

private:
	void SetCoordinate(const char coord, const int change, field& area) override;
};


class Snake
{
public:
	Snake(field& area);

	void MoveSnake(field& area);

	void TurnRight();

	void TurnLeft();

	uint16_t GetCount() const;

	uint16_t GetDirection();

	bool isEat() const;

	bool isDead() const;

private:
	uint16_t sizeSnake_ = 1;
	Head head_;
	std::vector<Tail> body_;

	void SpawnBP(field& area);

};


void CatchCommand(Snake& player, char chr);