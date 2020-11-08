#pragma once
#include <World.h>

using namespace std;

World::World() {
	this->m_sAppName = L"Frogger";
};

bool World::OnUserCreate() {
	return true;
};

bool World::OnUserUpdate(float elapsedTime) {
	this->timeSinceGameStart += elapsedTime;

	int x = 0, y = 0;
	for (auto lane : lanesHolder) {
		int startPosition = (int)(this->timeSinceGameStart * lane.first) % this->pixelSize;

		if (startPosition < 0) {
			startPosition = 64 - (abs(startPosition) % 64);
		}

		int cellOffset = (int)((float)this->pixelSize * this->timeSinceGameStart * lane.first) % this->pixelSize;
		int gameWidth = this->ScreenWidth() / this->pixelSize;
		
		for (int i = 0; i < gameWidth; i++) {
			wchar_t symbol = lane.second[(startPosition + i) % 64];

			int topLeftX = (x + i) * this->pixelSize - cellOffset;
			int topLeftY = y * this->pixelSize;
			int bottomRightX = (x + i + 1) * this->pixelSize - cellOffset;;
			int bottomRightY = (y + 1) * this->pixelSize;
			
			this->Fill(topLeftX, topLeftY, bottomRightX, bottomRightY, symbol);
		}

		y++;
	}

	return true;
};

