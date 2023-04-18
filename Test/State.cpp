#include <Windows.h>
#include <d3dx10.h>
#include "State.h"

#pragma once
#include <Windows.h>
#include <d3dx10.h>

#define Gravity 2

RECT Bill_Standing[2] = {{1, 30, 25, 65}, {26, 30, 50, 65}};

Standing::Standing(float vs, float x, float y, float hs) : State(0, 2, vs, x, y, hs) {
	frames = Bill_Standing;
}
State* Standing::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	if (GetKeyState(VK_DOWN) & 0x8000) {
		return new Lay_Down(0, 0, 10);
	}
	if (GetKeyState(VK_UP) & 0x8000) {
		return new Jumping(-15);
	}
	if ((GetKeyState(VK_LEFT) & 0x8000) || (GetKeyState(VK_RIGHT) & 0x8000)) {
		return new Running();
	}
	if ((GetKeyState('W') & 0x8000)) {
		return new Shot_Up(0, -4, -6);
	}
	return this;
}

Running::Running(float vs, float x, float y, float hs) : State(0, 6, vs, x, y, hs) {
	frames = new RECT[6]{
		{2, 66, 23, 102},
		{24, 66, 41, 102},
		{42, 66, 61, 102},
		{62, 66, 83, 102},
		{84, 66, 101, 102},
		{102, 66, 122, 102},
	};
}
State* Running::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	if (GetKeyState(VK_DOWN) & 0x8000) {
		return new Lay_Down(0, 0, 10);
	}
	if (GetKeyState(VK_UP) & 0x8000) {
		return new Jumping(-15);
	}
	if (GetKeyState('W') & 0x8000) {
		return new Running_Shot_Up();
	}
	if (GetKeyState('S') & 0x8000) {
		return new Running_Shot_Down();
	}
	if (!(GetKeyState(VK_LEFT) & 0x8000) && !(GetKeyState(VK_RIGHT) & 0x8000)) {
		return new Standing();
	}
	return this;
}

Jumping::Jumping(float vs, float x, float y, float hs) : State(0, 4, vs, x, y, hs) {
	frames = new RECT[4]{
		{117, 44, 134, 65},
		{135, 44, 155, 65},
		{156, 44, 173, 65},
		{174, 44, 194, 65},
	};
}
State* Jumping::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	if (verticalSpeed == 0) {
		return new Standing();
	}
	return this;
}

Lay_Down::Lay_Down(float vs, float x, float y, float hs) : State(0, 1, vs, x, y, hs) {
	frames = new RECT[1]{
		{83, 48, 116, 65},
	};
}
State* Lay_Down::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	if (!(GetKeyState(VK_DOWN) & 0x8000)) {
		return new Standing();
	}
	return this;
}

Shot_Up::Shot_Up(float vs, float x, float y, float hs) : State(0, 2, vs, x, y, hs) {
	frames = new RECT[2]{
		{51, 19, 66, 65},
		{67, 19, 82, 65},
	};
}
State* Shot_Up::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	if ((GetKeyState(VK_DOWN) & 0x8000)) {
		return new Lay_Down(0, 0, 10);
	}
	if ((GetKeyState(VK_UP) & 0x8000)) {
		return new Jumping();
	}
	if (!(GetKeyState('W') & 0x8000)) {
		return new Standing();
	}
	if ((GetKeyState(VK_LEFT) & 0x8000) || (GetKeyState(VK_RIGHT) & 0x8000)) {
		return new Running_Shot_Up();
	}
	return this;
}

Running_Shot_Up::Running_Shot_Up(float vs, float x, float y, float hs) : State(0, 3, vs, x, y, hs) {
	frames = new RECT[3]{
		{123, 66, 144, 102},
		{145, 66, 162, 102},
		{163, 66, 183, 102},
	};
}
State* Running_Shot_Up::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	if ((GetKeyState(VK_UP) & 0x8000)) {
		return new Jumping();
	}
	if (!(GetKeyState('W') & 0x8000)) {
		return new Running();
	}
	if (!(GetKeyState(VK_LEFT) & 0x8000) && !(GetKeyState(VK_RIGHT) & 0x8000)) {
		return new Shot_Up(0, -4, -6);
	}
	return this;
}

Running_Shot_Down::Running_Shot_Down(float vs, float x, float y, float hs) : State(0, 3, vs, x, y, hs) {
	frames = new RECT[3]{
		{184, 66, 206, 102},
		{207, 66, 228, 102},
		{229, 66, 251, 102},
	};
}
State* Running_Shot_Down::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	if ((GetKeyState(VK_UP) & 0x8000)) {
		return new Jumping();
	}
	if (!(GetKeyState('S') & 0x8000)) {
		return new Running();
	}
	if (!(GetKeyState(VK_LEFT) & 0x8000) && !(GetKeyState(VK_RIGHT) & 0x8000)) {
		return new Standing();
	}
	return this;
}

Swimming::Swimming(float vs, float x, float y, float hs) : State(0, 2, vs, x, y, hs) {
	frames = new RECT[2]{
		{94, 115, 111, 131},
		{130, 115, 147, 131},
	};
}
State* Swimming::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	return this;
}

Diving::Diving(float vs, float x, float y, float hs) : State(0, 1, vs, x, y, hs) {
	frames = new RECT[1]{
		{112, 123, 129, 131},
	};
}
State* Diving::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	return this;
}

Swimming_Shot::Swimming_Shot(float vs, float x, float y, float hs) : State(0, 1, vs, x, y, hs) {
	frames = new RECT[1]{
		{191, 113, 217, 131},
	};
}
State* Swimming_Shot::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	return this;
}

Swimming_Shot_Up::Swimming_Shot_Up(float vs, float x, float y, float hs) : State(0, 1, vs, x, y, hs) {
	frames = new RECT[1]{
		{148, 113, 168, 131},
	};
}
State* Swimming_Shot_Up::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	return this;
}

Swimming_Stand_Shot_Up::Swimming_Stand_Shot_Up(float vs, float x, float y, float hs) : State(0, 1, vs, x, y, hs) {
	frames = new RECT[1]{
		{169, 103, 187, 131},
	};
}
State* Swimming_Stand_Shot_Up::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	return this;
}

Dead::Dead(float vs, float x, float y, float hs) : State(0, 4, vs, x, y, hs) {
	frames = new RECT[4]{
		{2, 107, 18, 131},
		{19, 112, 42, 131},
		{43, 107, 59, 131},
		{60, 120, 93, 131},
	};
}
State* Dead::Update(bool up, bool down, bool left, bool right, bool lup, bool ldown, bool shoot) {
	return this;
}