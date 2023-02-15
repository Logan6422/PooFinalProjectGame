#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class Score {
public:
	Score();
	
	void show(RenderWindow &w);
	void addPointPlayer();
	void updateSpeed();
	int GetPlayerPoints();
private:
	Font font;
	Text text_player;
	unsigned int points_player;
	Text ss;
	unsigned int spd;
};

#endif

