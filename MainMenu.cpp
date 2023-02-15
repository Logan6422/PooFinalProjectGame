#include <SFML/Graphics/Text.hpp>
#include "MainMenu.h"
#include "config.hpp"

MainMenu::MainMenu() {
	///set font
	font.loadFromFile("Font/Pixel_Rand.otf");
	///play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(WIDTH/2.5,HEIGHT/3.1);

	///score
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Score");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(WIDTH/2.5,HEIGHT/2);
	
	
	///exit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(WIDTH/2.5,HEIGHT/1.5);
	
	MainMenuSelected = 0;
}

void MainMenu::draw(RenderWindow &w){
	for(int i=0;i<3;i++) { 
		w.draw(mainMenu[i]);
	}
	
}

void MainMenu:: MoveDown(){
	if(MainMenuSelected +1 <= 3){
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		
		MainMenuSelected++;
		if(MainMenuSelected == 3){
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}
int MainMenu::MainMenuPressed(){
	return MainMenuSelected;
}
MainMenu::~MainMenu(){
	
	
}
