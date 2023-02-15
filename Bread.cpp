#include "Bread.h"
#include "config.hpp"
using namespace std;
using namespace sf;



Bread::Bread(){
	///Load texture and sprite
	Bread_tex.loadFromFile("Images/Bread.png");	
	this->currentFrame = IntRect(0,0,32,32);
	Bread_spr.setTexture(Bread_tex);
	Bread_spr.setScale(1.5,1.5);
	Bread_spr.setPosition(WIDTH,HEIGHT/2.2);
	Bread_spr.setOrigin(16,16);
	speed.x = -200;
	speed.y = 0;
}

void Bread::updateBread(Time &delta){
	
	///updates bread 
	
	updateAnimation();
	Bread_spr.move(delta.asSeconds()*speed.x,0);
	if(Bread_spr.getPosition().x < -80){
		Bread_spr.setPosition(WIDTH + 32,Bread_spr.getPosition().y);
		speed.x -=15;
	}
}

void Bread::despawn(){
	
	///despawn bread
	
	Bread_spr.setPosition(WIDTH + 2000,Bread_spr.getPosition().y);
}
void Bread::drawBread(RenderWindow &w){
	
	///draw bread sprite 
	
	w.draw(Bread_spr);
}
Sprite Bread::getSprite(){
	
	///return bread sprite 
	
	return Bread_spr;
}
Vector2f Bread::getPos(){
	
	///returns bread position
	
	return Bread_spr.getPosition();
}
Vector2f Bread::getspeed(){
	
	///return bread speed 
	
	return speed;
}
void Bread::updateAnimation(){
	
	///updates bread animation
	
	if(this->m_clock.getElapsedTime().asMilliseconds()>100){
		
		this->currentFrame.left += 32;
		if(this->currentFrame.left>=192){
			this->currentFrame.left = 0;
		}
		
		this->Bread_spr.setTextureRect(this->currentFrame);
		this->m_clock.restart();
	}
	
}
