#pragma once
#include <Windows.h>
#include <d3dx10.h>

#define Gravity 2

class State
{
public:
	RECT* frames;
	int frameCount;
	int currentFrame;
	int timer = 0;
	int counter = 6;
	float verticalSpeed;
	float horizontalSpeed;
	float x, y;
	State(int currentFrame, int frameCount, float vs = 0, float x = 0, float y = 0, float hs = 0) {
		this->currentFrame = currentFrame;
		this->frameCount = frameCount;
		verticalSpeed = vs;
		horizontalSpeed = hs;
		this->x = x; this->y = y;
	}
	virtual State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) = 0;
}; typedef State* STATE;

class Standing : public State
{
public:
	Standing(float vs = 0, float x = 0, float y = 0, float hs = 0);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Running : public State
{
public:
	Running(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Jumping : public State
{
public:
	Jumping(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Lay_Down : public State
{
public:
	Lay_Down(float vs = 0, float x = 0, float y = 0, float hs = 0);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Shot_Up : public State
{
public:
	Shot_Up(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Running_Shot_Up : public State
{
public:
	Running_Shot_Up(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Running_Shot_Down : public State
{
public:
	Running_Shot_Down(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Swimming : public State
{
	Swimming(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Diving : public State
{
	Diving(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Swimming_Shot : public State
{
	Swimming_Shot(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Swimming_Shot_Up : public State
{
	Swimming_Shot_Up(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Swimming_Stand_Shot_Up : public State
{
	Swimming_Stand_Shot_Up(float vs = 0, float x = 0, float y = 0, float hs = 0);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};

class Dead : public State
{
	Dead(float vs = 0, float x = 0, float y = 0, float hs = 5);
	State* Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot);
};
