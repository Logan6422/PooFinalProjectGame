#include "Pochita.h"
#include "config.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <cmath>
#include <SFML/System/Clock.hpp>
#include <iomanip>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
using namespace std;
using namespace sf;






Pochita::Pochita() {
	///load texture and sprite
	pochita_tex.loadFromFile("Images/PochitaSS.png");	
	this->currentFrame = IntRect(0,0,608,418);
	pochita_spr.setTexture(pochita_tex);
	
	pochita_spr.setScale(0.2,0.2);
	
	///Sound setup
	this->buffer.loadFromFile("Sound/jump.wav");
	this->sound.setBuffer(buffer);
	
	///Set sprite origin to center
	pochita_spr.setOrigin(304,209);
	///start position
	pochita_spr.setPosition(WIDTH/2.f,HEIGHT/1.5);
	
//	speed.x = 1;
//	speed.y = 300;
	m_gravity = 8;
	
}




void Pochita::updatePochita(Time &delta){
	
	updateAnimation();

	///Move player
	
	pochita_spr.move(-200*delta.asSeconds(),0);
	if(Keyboard::isKeyPressed(Keyboard::A)){
		pochita_spr.move(-100*delta.asSeconds(),0);
	}
	if(Keyboard::isKeyPressed(Keyboard::D)){
		pochita_spr.move(450*delta.asSeconds(),0);
	}
	
	
	Vector2f player_pos = pochita_spr.getPosition();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and player_pos.y <= 330) {
		pochita_spr.move(0,-0.001-m_gravity);
		m_gravity -= .50;
		
	}else if(player_pos.y<330){
		m_gravity = 9;
		player_pos.y += m_gravity;
		m_gravity = 0;
		pochita_spr.setPosition(player_pos);
	}
	
	if(pochita_spr.getPosition().y > 330){pochita_spr.setPosition(player_pos.x,330);}
	if(m_gravity<0 and player_pos.y == 330) m_gravity = 8;
	player_pos = pochita_spr.getPosition();
	

	onCollision();
	//261.983
	

}
Vector2f Pochita::getPos()const{
	return pochita_spr.getPosition();
}
Sprite Pochita::getSprite(){
	return this->pochita_spr;
}



void Pochita::onCollision(){
	
	if(pochita_spr.getPosition().y < 0){
		pochita_spr.setPosition(pochita_spr.getPosition().x,0);
	}
	if(pochita_spr.getPosition().x < 32){
		pochita_spr.setPosition(32,pochita_spr.getPosition().y);
	}
	if(pochita_spr.getPosition().x > WIDTH-32){
		pochita_spr.setPosition(WIDTH-32,pochita_spr.getPosition().y);
		onGround = true;
	}
}
void Pochita::updateAnimation(){
	if(this->m_clock.getElapsedTime().asMilliseconds()>100){
		
		this->currentFrame.left += 608;
		if(this->currentFrame.left>=3040){
			this->currentFrame.left = 0;
		}
		
		this->pochita_spr.setTextureRect(this->currentFrame);
		this->m_clock.restart();
	}
	
}
