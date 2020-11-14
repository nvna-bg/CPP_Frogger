#include "lib/stages/StageBase.h"

using namespace std;

StageBase::StageBase() {}
StageBase::StageBase(int stageWidth, int pixelSize) {
	this->stageWidth = stageWidth;
	this->pixelSize = pixelSize;
}

vector<pair<float, wstring>> StageBase::getMap() {
	return this->stageMap;
}

pair<float, wstring> StageBase::getLane(int row) {
	return this->stageMap[row];
}

wstring StageBase::getDangerChars() {
	return this->dangerChars;
}

pair<int, int> StageBase::getFrogBasePosition() {
	int baseX = this->stageWidth / this->pixelSize / 2;
	int baseY = this->stageMap.size();
	return { baseX, baseY };
}
