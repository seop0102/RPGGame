#pragma once
//#include "Character.h"
#include <string>

class StoryManager 
{
public:
	StoryManager()=default;
	~StoryManager() = default;

	void startPrologue();
	std::string getJob() const; //직업 반환
	std::string getMap() const; //맵 반환
	std::string getName() const; //맵 반환

private:
	int totalScore; //유저가 고른 정답의 점수 합 담을 변수
	std::string job;
	std::string map;
	std::string username;

	void showStory(); //흐름 관리 
	void playPrologue();//이야기 시작
	void askUsername(); // 이름 입력
	void makeJobMap(); // 직업 맵 결정 + 출력
};