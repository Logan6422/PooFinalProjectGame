#include "Tilemap.h"
#include "config.hpp"
#include <SFML/System/Vector2.hpp>

Tilemap::Tilemap() {
	///Load texture and sprite
	Tilemap_tex.loadFromFile("Images/Cross.png");
	Tilemap_spr.setTexture(Tilemap_tex);
	Tilemap_spr.setScale(3,3);
	Tilemap_spr.setPosition(WIDTH+800,HEIGHT/1.46);
	Tilemap_spr.setOrigin(Tilemap_spr.getLocalBounds().width/2.0f,Tilemap_spr.getLocalBounds().height/2.1f);
	speed.x = -200;
	speed.y = 0;
}

void Tilemap::updateTilemap(Time &delta){
	Tilemap_spr.move(delta.asSeconds()*speed.x,0);
	if(Tilemap_spr.getPosition().x < -80){
		Tilemap_spr.setPosition(WIDTH + 280,Tilemap_spr.getPosition().y);
		speed.x -=10;
	}
}
void Tilemap::drawTilemap(RenderWindow &w){
	w.draw(Tilemap_spr);
}
Sprite Tilemap::getSprite(){
	return Tilemap_spr;
}
Vector2f Tilemap::getPos(){
	return Tilemap_spr.getPosition();
}
Vector2f Tilemap::getspeed(){
	return speed;
}
