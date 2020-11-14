#pragma once
#include <lib/olcConsoleGameEngine.h>
#include "lib/stages/StageBase.h"

using namespace std;

class World : public olcConsoleGameEngine {
private:
	int frogX = 8;
	int frogY = 9;
	short frogSymbol = L'Ж';

	float timeSinceGameStart = 0.0;
	int pixelSize = 8;
	wstring dangerChars = L"x~*@";
	vector<StageBase> stages;
	StageBase currentStage;

public:
	World(wstring gameName, vector<StageBase> stages, int pixelSize);

	

protected:
	bool OnUserCreate();
	bool OnUserUpdate(float);
};

