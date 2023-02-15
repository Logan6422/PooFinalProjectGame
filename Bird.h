#ifndef BIRD_H
#define BIRD_H
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

using namespace sf;

class Bird {
public:
	Bird();
	void updateBird(Time &delta);
	void drawBird(RenderWindow &w);
	Sprite getSprite();
	Vector2f getPos();
	void changeSpeed(float &a);
	Vector2f getspeed();
	void updateAnimation();
	Clock m_clock;
private:
	Vector2f speed;
	Sprite Bird_spr;
	Texture Bird_tex;
	IntRect currentFrame;
};

#endif

