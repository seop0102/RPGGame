#pragma once
//#include "Character.h"
#include <string>

class StoryManager 
{
public:
	StoryManager()=default;
	~StoryManager() = default;

	void startPrologue();
	std::string getJob() const; //���� ��ȯ
	std::string getMap() const; //�� ��ȯ
	std::string getName() const; //�� ��ȯ

private:
	int totalScore; //������ �� ������ ���� �� ���� ����
	std::string job;
	std::string map;
	std::string username;

	void showStory(); //�帧 ���� 
	void playPrologue();//�̾߱� ����
	void askUsername(); // �̸� �Է�
	void makeJobMap(); // ���� �� ���� + ���
};