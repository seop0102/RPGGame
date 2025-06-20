#include "StoryManager.h"
#include <iostream>

StoryManager::StoryManager() : totalScore(0), job(""), map("") {
}
void StoryManager::startPrologue() {
	showStory();

	if (totalScore <= 6) {
		job = "����";
		map = "�Ȱ��� ��";
	}
	else if (totalScore <= 12) {
		job = "";
		map = "";
	}
	else {
		job = "";
		map = "";
	}
	std::cout << "���⿡ �������" << job << endl;
	std::cout << "���⿣ ����� " << map << endl;

}
void StoryManager::showStory() {
	std::vector<std::string> prologue = {
		"��Ӱ� ���� �� ���� ��Ŵ� ���. ����� �帴�ϰ�, ��� �Դ���, �� �̰��� �ִ������� �� �� �����ϴ�. �ӻ��� ������������ �����ϴ� ���ϰ�, �߹��� ���� ������ �ȴ� ���� ������ �Ҹ��� ���ϴ�. ������ �����Ϸ� ���� ������, ������ ������ ���̷� ���̴� ���� ����� �޺����Դϴ�. \n 1. ���� 2. ���� 3. ����" ,
		"�ι�° ���丮" ,
		"����° ���丮",
		"�׹�° ���丮",
		"�ټ���° ���丮",
		"������° ���丮"
	};
	for (int i = 0; i < prologue.size(); ++i) {
		//���� ���
		std::cout << "\n����" << prologue[i] << endl;
		int userChoice = 0;
		std::cin >> userChoice;
		totalScore += userChoice; 
	}
	//��Ż���ھ� ����ϸ� ���� ��?
}

std::string StoryManager::getJob() const {
	return job;
}
std::string StoryManager::getMap() const {
	return map;
}