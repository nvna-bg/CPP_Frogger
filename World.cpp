#pragma once
#include <World.h>

using namespace std;

World::World(wstring gameName, vector<StageBase> stages, int pixelSize) {
	this->m_sAppName = gameName;
	this->stages = stages;
	this->currentStage = stages[0];
	this->pixelSize = pixelSize;

	pair<int, int> frogBasePosition = this->currentStage.getFrogBasePosition();
	this->frogX = frogBasePosition.first;
	this->frogY = frogBasePosition.second;
};

bool World::OnUserCreate() {
	return true;
};

bool World::OnUserUpdate(float elapsedTime) {
	this->timeSinceGameStart += elapsedTime;

	if (this->m_keys[VK_UP].bPressed) {
		this->frogY -= 1;
	} else if (this->m_keys[VK_DOWN].bPressed) {
		this->frogY += 1;
	} else if (this->m_keys[VK_LEFT].bPressed) {
		this->frogX -= 1;
	} else if (this->m_keys[VK_RIGHT].bPressed) {
		this->frogX += 1;
	}

	vector<pair<float, wstring>> map = this->currentStage.getMap();
	if (this->frogY <= 3) {
		this->frogX -= elapsedTime * map[(int)this->frogY].first;
	}

	int x = -1, y = 0;
	for (auto lane : map) {
		int startPosition = (int)(this->timeSinceGameStart * lane.first) % lane.second.length();

		if (startPosition < 0) {
			startPosition = lane.second.length() - (abs(startPosition) % lane.second.length());
		}

		int cellOffset = (int)((float)this->pixelSize * this->timeSinceGameStart * lane.first) % this->pixelSize;
		int gameWidth = this->ScreenWidth() / this->pixelSize + 2;
		
		for (int i = 0; i < gameWidth; i++) {
			wchar_t symbol = lane.second[(startPosition + i) % lane.second.length()];

			int topLeftX = (x + i) * this->pixelSize - cellOffset;
			int topLeftY = y * this->pixelSize;
			int bottomRightX = (x + i + 1) * this->pixelSize - cellOffset;;
			int bottomRightY = (y + 1) * this->pixelSize;
			
			this->Fill(topLeftX, topLeftY, bottomRightX, bottomRightY, symbol);
		}

		y++;
	}

	int frogTopX = this->frogX * this->pixelSize;
	int frogTopY = this->frogY * this->pixelSize;
	int frogBottomX = frogTopX + this->pixelSize;
	int frogBottomY = frogTopY + this->pixelSize;

	this->Fill(frogTopX, frogTopY, frogBottomX, frogBottomY, this->frogSymbol);

	return true;
};

