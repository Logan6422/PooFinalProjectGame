#include "Game.h"
#include <SFML/Window/VideoMode.hpp>
#include "config.hpp"
#include <SFML/Window/Event.hpp>
#include "Pochita.h"
#include "Tilemap.h"
#include <iostream>
#include <cmath>
#include "Bread.h"
#include "Score.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
using namespace std;

Game::Game() {
///Load texture_back
	texture_back.loadFromFile("Images/Background.png");
///Assign Sprite
	background.setTexture(texture_back);
	background.setScale(1.f,0.6f);
///Load music

	music.openFromFile("Sound/music.wav");
	jump.openFromFile("Sound/Pochita.wav");
	music.setLoop(true);
	music.play();
}




void Game::run(RenderWindow &window){
///Game loop while window is open
	while(window.isOpen()){
		if(!collide(enemy,pochita) && !collide(corven,pochita)){
			
			
			///reset clock
			time = clock.restart();
			
			Event ev;
			///Event processing
			
			///Update game elements
			pochita.updatePochita(time);
			enemy.updateTilemap(time);
			corven.updateBird(time);
			coin.updateBread(time);
			count.addPointPlayer();
			
			///Draw game elements
			window.draw(background);
			window.draw(pochita.getSprite());
			window.draw(enemy.getSprite());
			window.draw(corven.getSprite());
			window.draw(coin.getSprite());
			count.show(window);
			breads.show(window);
			
			
			
			
			///bread collition
			if(collide(coin,pochita)){
				count.updateSpeed();
				jump.play();
				coin.despawn();
				breads.addBreadPlayer();
			}
			
			
			///Update Window
			window.display();
		}else{
			datos a = {"none",count.GetPlayerPoints()};
			
			///gameover window
			
			music.stop();
			
			Gameover b(count.GetPlayerPoints());
			b.init(window);
			break;
		}
		
	}
}

template<typename T>
bool Game::collide(T &a, Pochita &b){
	Vector2f posA = a.getPos();
	Vector2f posB = b.getPos();
	Vector2f res = posA - posB;
	return sqrt(res.x*res.x+res.y*res.y) < 50;
}


