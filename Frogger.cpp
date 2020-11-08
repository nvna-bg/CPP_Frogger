#pragma once
#include <iostream>
#include <string>
#include <World.h>

std::atomic<bool> olcConsoleGameEngine::m_bAtomActive(false);
std::condition_variable olcConsoleGameEngine::m_cvGameFinished;
std::mutex olcConsoleGameEngine::m_muxGame;

using namespace std;

int main() {
	World game;
	game.ConstructConsole(128, 80, 8, 8);
	game.Start();

	return 0;
}