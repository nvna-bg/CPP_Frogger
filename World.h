#pragma once
#include <lib/olcConsoleGameEngine.h>

using namespace std;

class World : public olcConsoleGameEngine {
public:
	World();

	vector<pair<float, wstring>> lanesHolder = {
		{ 0.0, L"xxx..xxx..xxx..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" }, //64 elements
		{-3.0, L"###~~~~~####~~~~~~~~#####~~~~~~~~~~~~~##~~~~###~~~~~~~~####~~~~~" },
		{ 3.0, L"###~~~~~###~~~~~~~~~~~~~####~~~~~~~~~####~~~~~~~##~~~##~~~~~###~" },
		{ 2.0, L"##~~~~~~~##~~~~~~##~~~~~##~~~~####~~~~~###~~~~~~~####~~~~~~~##~~" },
		{ 0.0, L"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp" },
		{ 3.0, L"...**.........**............@@@............***.......***.....***" },
		{-2.0, L"..***.....**..@@.........****..........****.........****.....***" },
		{ 2.0, L"..****........**......**...**......@@@...**.....**.....***......" },
		{-1.0, L"..***........***......@@@..........***...**.....***........***.." },
		{ 0.0, L"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp" },
	};

	float timeSinceGameStart = 0.0;
	int pixelSize = 8;
	wstring dangerChars = L"x~*@";

protected:
	bool OnUserCreate();
	bool OnUserUpdate(float);
};

