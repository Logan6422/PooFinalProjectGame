#ifndef BUFF_H
#define BUFF_H
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class Buff{
public:
	Buff();
	
	void show(RenderWindow &w);
	void addBreadPlayer();
private:
	Font font;
	Text text_bread;
	unsigned int act_bread;
	Sprite bread_spr;
	Texture bread_tex;
	IntRect currentFrame;
	
};


#endif

