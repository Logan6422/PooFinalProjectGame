#include "Menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Music.hpp>
#include "MainMenu.h"
#include <SFML/Window/Event.hpp>
#include "Game.h"
#include "config.hpp"
#include <iostream>
#include "Score.h"

using namespace std;

Menu::Menu() {
		///Load texture_back
		texture_back.loadFromFile("Images/poch.jpg");
		///Assign Sprite
		background.setTexture(texture_back);
		background.setScale(1.5f,1.f);
		///Load music
		music.openFromFile("Sound/menu.wav");
		jump.openFromFile("Sound/Pochita.wav");
		music.setLoop(true);
		music.play();
}

void Menu::Procces(RenderWindow &MENU){
		while(MENU.isOpen()){
			
			MainMenu menu;
			Event ev;
			///Event processing
			while(MENU.pollEvent(ev)){
				
				///closed event type
				if(ev.type == Event::Closed){
					MENU.close();
				}	
				if(ev.type == Event::KeyReleased){
					if(ev.key.code == Keyboard::S){
						mainMenu.MoveDown();
						break;
					}
					if(ev.key.code == Keyboard::F){
						
						int x = mainMenu.MainMenuPressed();
						if(x == 0){
							
							music.stop();
							Game a;
							
							a.run(MENU);
							break;
						}
						
						if(x == 1){
							ScoreManager s;
							s.getBestScore();
							s.init(MENU);
							break;
						}
						
						if(x == 2){
							MENU.close();
							break;
						}
					}
				}
			}
			MENU.clear();
			MENU.draw(background);
			mainMenu.draw(MENU);
			
			
			///Update Window
			MENU.display();
			
		}
		
}
