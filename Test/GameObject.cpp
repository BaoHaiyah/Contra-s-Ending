#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"

/*
	Initialize game object 
*/
CGameObject::CGameObject(float x, float y, LPTEXTURE tex)
{
	this->x = x;
	this->y = y;
	this->texture = tex;
}

void CGameObject::Render()
{
	/*for (int i = x; i < 1000; i += 16 ) {
		CGame::GetInstance()->Draw(i, y, texture);
	}
	CGame::GetInstance()->Draw(x, y, texture);*/
}
void CBill::Render()
{
	RECT* frame = &state->frames[state->currentFrame];
	state->timer++;
	if (state->timer / state->counter > 0) 
	{
		state->currentFrame++;
		state->timer = 0;
	}
	if (state->currentFrame >= state->frameCount) { state->currentFrame = 0; }
	CGame::GetInstance()->Draw(x + state->x, y + state->y, texture, frame);
}

CGameObject::~CGameObject()
{
	if (texture != NULL) delete texture;
}

#define MARIO_VX 0.1f
#define MARIO_WIDTH 14
#define Gravity 2

void CBill::Update(DWORD dt)
{
	state = state->Update();
	y += state->verticalSpeed;
	state->verticalSpeed += Gravity;
	if (y >= 160) {
		y = 160;
		state->verticalSpeed = 0;
	}
	if (GetKeyState(VK_LEFT) & 0x8000) {
		x += -state->horizontalSpeed;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000) {
		x += state->horizontalSpeed;
	}
	//x += vx*dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {
		
		//vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
}
