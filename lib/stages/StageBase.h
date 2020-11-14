#pragma once

#include <string>
#include <vector>

using namespace std;

class StageBase {
protected:
	int stageWidth = 128;
	int pixelSize = 8;

	vector<pair<float, wstring>> stageMap = {
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

	wstring dangerChars = L"x~*@";
public:
	StageBase();
	StageBase(int stageWidth, int pixelSize);

	vector<pair<float, wstring>> getMap();
	pair<float, wstring> getLane(int);
	wstring getDangerChars();
	pair<int, int> getFrogBasePosition();
};
