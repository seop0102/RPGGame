#pragma once
#include "Character.h"
#include <string>

class StoryManager 
{
public:
	StoryManager()=default;
	~StoryManager() = default;

	void startPrologue();
	std::string getJob() const; //직업 반환
	std::string getMap() const; //맵 반환

private:
	int totalScore; //유저가 고른 정답의 점수 합 담을 변수
	std::string job;
	std::string map;

	void showStory();


};