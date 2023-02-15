#ifndef POCHITA_H
#define POCHITA_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <ctime>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Rect.hpp>
using namespace std;
using namespace sf;

class Pochita {
public:
	Pochita();
	void update();
	Vector2f getPos()const;
	Sprite getSprite();
	void updatePochita(Time &delta);
	void initAnimation();
	void updateAnimation();
	
	private:
	Sprite pochita_spr;
	Texture pochita_tex;
//	Vector2f speed;
	SoundBuffer buffer;
	Sound sound;
	IntRect currentFrame;
	Clock m_clock;
	bool onGround;
	
	float m_gravity, m_jumps;
	void onCollision();
	
};

#endif

