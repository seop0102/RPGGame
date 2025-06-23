#include "GameManager.h"

int main() {
	GameManager gameManager;

	gameManager.storyManager->startPrologue(); // 프롤로그 시작

	//gameManager.startGame();

	gameManager.playGame();

	gameManager.endGame();
	return 0;
}