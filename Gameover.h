#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ScoreManager.h"

using namespace sf;

class Gameover {
public:
	Gameover(int current);
	void init(RenderWindow &window);
private:
	///audio
	int puntaje;
	Font m_font;
	Text press;
	Text press2;
	Text Best;
	Text currentScore;
	Text gamov;
	Music death;
};


#endif

