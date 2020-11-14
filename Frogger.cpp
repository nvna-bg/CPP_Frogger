#pragma once
#include <iostream>
#include <string>
#include <World.h>
#include "lib/stages/Stage1.h"

std::atomic<bool> olcConsoleGameEngine::m_bAtomActive(false);
std::condition_variable olcConsoleGameEngine::m_cvGameFinished;
std::mutex olcConsoleGameEngine::m_muxGame;

using namespace std;

int main() {
	int gameWidth = 128;
	int gameHeight = 80;
	int pixelSize = 8;

	Stage1 firstStage(gameWidth, pixelSize);
	vector<StageBase> stages = { firstStage };
	World game(L"Frogger", stages, pixelSize);

	game.ConstructConsole(gameWidth, gameHeight, pixelSize, pixelSize);
	game.Start();

	return 0;
}