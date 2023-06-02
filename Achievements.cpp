#include "Achievements.h"
int Achievements::Timer = 0;

Achievements::Achievements()
{	
}

void Achievements::check(Player& player, sf::RenderWindow& window)
{
	static Achievement ach1(ach_strings[0]);
	static Achievement ach2(ach_strings[1]);
	static Achievement ach3(ach_strings[2]);
	static Achievement ach4(ach_strings[3]);
	if (player.score >= 1 && ach1.Timer <= 175) {
	
		ach1.draw_(window);
		ach1.Timer++;
	}
	else if (player.penalty >= 1 && ach2.Timer <= 175) {
		
		ach2.draw_(window);
		ach2.Timer++;
	}
	else if (player.points >= 3 && ach3.Timer <= 175) {
		
		ach3.draw_(window);
		ach3.Timer++;
	}
	else if (player.health < 10 && ach4.Timer <= 175) {
		ach4.draw_(window);
		ach4.Timer++;
	}

}
