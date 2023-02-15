#ifndef TILEMAP_H
#define TILEMAP_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Tilemap.h"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;


class Tilemap {
public:
	Tilemap();
	void updateTilemap(Time &delta);
	void drawTilemap(RenderWindow &w);
	Sprite getSprite();
	Vector2f getPos();
	void changeSpeed(float &a);
	Vector2f getspeed();
private:
	Vector2f speed;
	Sprite Tilemap_spr;
	Texture Tilemap_tex;
};

#endif

