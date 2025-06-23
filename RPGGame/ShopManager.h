#pragma once

#include <iostream>

class ShopManager
{
public:
	ShopManager() = default;
	~ShopManager() = default;

	void openShop() {

		std::cout << "상점이 열렸습니다!" << std::endl;
	}


};

