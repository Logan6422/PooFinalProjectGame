#include "Gameover.h"
#include "config.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include "ScoreManager.h"
#include "SavePoints.h"



Gameover::Gameover(int current) {

	puntaje = current;
	
	m_font.loadFromFile("Font/Pixel_Rand.otf");
	
	
	///GAMEOVER
	gamov.setFont(m_font);
	gamov.setFillColor(Color::White);
	gamov.setString("GAME OVER");
	gamov.setCharacterSize(70);
	gamov.setPosition(WIDTH/3.1,HEIGHT/5);
	
	///GAMEOVER
	press.setFont(m_font);
	press.setFillColor(Color::White);
	press.setString("presione R para volver al menu");
	press.setCharacterSize(50);
	press.setPosition(WIDTH/5.5,HEIGHT/1.8);
	
	
	///Score
	currentScore.setFont(m_font);
	currentScore.setFillColor(Color::White);
	currentScore.setString("Your Score: "+to_string(current));
	currentScore.setCharacterSize(60);
	currentScore.setPosition(WIDTH/3.3,HEIGHT/1.5);
	
	
	press2.setFont(m_font);
	press2.setFillColor(Color::White);
	press2.setString("Presione G para guardar puntaje");
	press2.setCharacterSize(50);
	press2.setPosition(WIDTH/7.2,HEIGHT/1.2);
}

void Gameover::init(RenderWindow &window){

	while(window.isOpen()){
		window.clear(Color::Black);
		window.draw(gamov);
		window.draw(press);
		window.draw(Best);
		window.draw(press2);
		window.draw(currentScore);
		window.display();
		
		unsigned char r = rand();
		unsigned char g = rand();
		unsigned char b = rand();
		gamov.setFillColor({r,g,b});
		
		if(Keyboard::isKeyPressed(Keyboard::R)){
			break;
		}
		
		
		if(Keyboard::isKeyPressed(Keyboard::G)){
			SavePoints a;
			string nombre = a.init(window,puntaje);
			ScoreManager g;
			g.setStats(puntaje,nombre);
			g.SaveNewBest();
			break;
		}
	
	}
	
	
}

