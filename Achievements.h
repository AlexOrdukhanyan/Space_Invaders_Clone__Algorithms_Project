#pragma once
#include "Achievement.h"
#include <vector>
#include <string>
#include "Player.h"

class Achievements
{
	static int Timer;
	std::vector<std::string> ach_strings = {
		"Achievements/ach1.png",
		"Achievements/ach2.png",
		"Achievements/ach3.png",
		"Achievements/ach4.png"
	};
	
public:
	Achievements();
	void check(Player& player, sf::RenderWindow& window);
};

