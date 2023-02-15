#ifndef BREAD_H
#define BREAD_H
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;

class Bread {
public:
	Bread();
	void updateBread(Time &delta);
	void drawBread(RenderWindow &w);
	Sprite getSprite();
	Vector2f getPos();
	void changeSpeed(float &a);
	Vector2f getspeed();
	void updateAnimation();
	Clock m_clock;
	void despawn();
private:
	Vector2f speed;
	Sprite Bread_spr;
	Texture Bread_tex;
	IntRect currentFrame;
};

#endif

