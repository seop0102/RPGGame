#pragma once
#include <string>
#include <vector>
class StoryManager
{
public:
	StoryManager();
	~StoryManager() = default;
	void startPrologue();
	void askUsername(); // �̸� �Է�
	std::string getJob() const; //���� ��ȯ
	std::string getMap() const; //�� ��ȯ
	std::string getName() const; //���� �̸� ��ȯ

private:
	int totalScore = 0; //������ �� ������ ���� �� ���� ����
	std::string job = "";
	std::vector<std::string> map;
	std::string username = "";
	void showStory(); //�帧 ����
	void playPrologue();//�̾߱� ����
	void makeJobMap(); // ���� �� ���� + ���
};