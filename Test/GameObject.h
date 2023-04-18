#pragma once

#include <Windows.h>
#include <d3dx10.h>

#include "Texture.h"
#include "State.h"

class CGameObject
{
protected: 
	float x; 
	float y;

	// This should be a pointer to an object containing all graphic/sound/audio assets for rendering this object. 
	// For now, just a pointer to a single texture
	LPTEXTURE texture;			
public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	float GetX() { return x; }
	float GetY() { return y; }

	CGameObject(float x = 0.0f, float y=0.0f, LPTEXTURE texture = NULL);

	virtual void Update(DWORD dt) = 0;
	virtual void Render();

	~CGameObject();
};
typedef CGameObject * LPGAMEOBJECT;

class CBrick : public CGameObject
{
public:
	CBrick(float x, float y, LPTEXTURE texture): CGameObject(x,y,texture) {}
	void Update(DWORD dt) {};
};

class Control {
public:
	wchar_t Up, Down, Left, Right, Look_Up, Look_Down, Shoot;
	Control(wchar_t up, wchar_t down, wchar_t left, wchar_t right, wchar_t lup, wchar_t ldown, wchar_t shoot) : Up(up), Down(down), Left(left), Right(right), Look_Up(lup), Look_Down(ldown), Shoot(shoot) {};
};

class CBill : public CGameObject
{
	float vx;
	float vy;
public:
	STATE state;
	Control* control;
public: 
	CBill(float x, float y, float vx, float vy, LPTEXTURE texture) :CGameObject(x, y, texture)
	{
		control = NULL;
		this->vx = vx;
		this->vy = vy;
		state = new Standing();
	};
	void Update(DWORD dt);
	void Render();
};