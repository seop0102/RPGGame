#include "StoryManager.h"
#include <iostream>

StoryManager::StoryManager() : totalScore(0), job(""), map("") {
}
void StoryManager::startPrologue() {
	showStory();

	if (totalScore <= 6) {
		job = "도적";
		map = "안개의 숲";
	}
	else if (totalScore <= 12) {
		job = "";
		map = "";
	}
	else {
		job = "";
		map = "";
	}
	std::cout << "여기에 직업출력" << job << endl;
	std::cout << "여기엔 맵출력 " << map << endl;

}
void StoryManager::showStory() {
	std::vector<std::string> prologue = {
		"어둡고 낯선 숲 속을 헤매는 당신. 기억은 흐릿하고, 어디서 왔는지, 왜 이곳에 있는지조차 알 수 없습니다. 앙상한 나뭇가지들이 손짓하는 듯하고, 발밑의 마른 낙엽은 걷는 내내 스산한 소리를 냅니다. 방향을 가늠하려 고개를 들지만, 빽빽한 나무들 사이로 보이는 것은 희미한 달빛뿐입니다. \n 1. 선택 2. 선택 3. 선택" ,
		"두번째 스토리" ,
		"세번째 스토리",
		"네번째 스토리",
		"다섯번째 스토리",
		"여섯번째 스토리"
	};
	for (int i = 0; i < prologue.size(); ++i) {
		//문제 출력
		std::cout << "\n문제" << prologue[i] << endl;
		int userChoice = 0;
		std::cin >> userChoice;
		totalScore += userChoice; 
	}
	//토탈스코어 출력하면 좋을 듯?
}

std::string StoryManager::getJob() const {
	return job;
}
std::string StoryManager::getMap() const {
	return map;
}