#include "Bird.h"
#include "config.hpp"
#include <cstdlib>
using namespace std;

Bird::Bird() {
	///Load texture and sprite
	Bird_tex.loadFromFile("Images/Bird.png");	
	this->currentFrame = IntRect(0,0,32,32);
	Bird_spr.setTexture(Bird_tex);
	Bird_spr.setTexture(Bird_tex);
	Bird_spr.setScale(2,2);
	Bird_spr.setPosition(WIDTH+1500,HEIGHT/2.1);
	Bird_spr.setOrigin(16,16);
	speed.x = -200;
	speed.y = 0;
}

void Bird::updateBird(Time &delta){
	///animation
	updateAnimation();
	Bird_spr.move(delta.asSeconds()*speed.x,0);
	if(Bird_spr.getPosition().x < -80){
		Bird_spr.setPosition(WIDTH + 10+rand()%1500,Bird_spr.getPosition().y);
		speed.x -=17;
	}
}
void Bird::drawBird(RenderWindow &w){
	///draw bird
	w.draw(Bird_spr);
}
Sprite Bird::getSprite(){
	///returns bird sprite
	return Bird_spr;
}
Vector2f Bird::getPos(){
	///returns bird position
	return Bird_spr.getPosition();
}
Vector2f Bird::getspeed(){
	///	return bird speed
	return speed;
}
void Bird::updateAnimation(){
	
	///updates bird animation
	
	if(this->m_clock.getElapsedTime().asMilliseconds()>150){
		
		this->currentFrame.left += 32;
		if(this->currentFrame.left>=192){
			this->currentFrame.left = 0;
		}
		
		this->Bird_spr.setTextureRect(this->currentFrame);
		this->m_clock.restart();
	}
	
}
