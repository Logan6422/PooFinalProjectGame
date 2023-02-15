#include "ScoreManager.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include "config.hpp"
#include <SFML/Window/Keyboard.hpp>
using namespace std;

ScoreManager::ScoreManager(){
	getBestScore();
	///pos1 
	
	m_font.loadFromFile("Font/Pixel_Rand.otf");
	m_score.setFont(m_font);
	m_score.setFillColor(Color::White);
	m_score.setString("Posicion 1:"+table[0].name+"/"+to_string(table[0].points));
	m_score.setCharacterSize(70);
	m_score.setPosition(WIDTH/5,HEIGHT/9);
	
	///pos2
	
	m_font.loadFromFile("Font/Pixel_Rand.otf");
	m_score2.setFont(m_font);
	m_score2.setFillColor(Color::White);
	m_score2.setString("Posicion 2:"+table[1].name+"/"+to_string(table[1].points));
	m_score2.setCharacterSize(70);
	m_score2.setPosition(WIDTH/5,HEIGHT/4);
	
	///pos3
	
	m_font.loadFromFile("Font/Pixel_Rand.otf");
	m_score3.setFont(m_font);
	m_score3.setFillColor(Color::White);
	m_score3.setString("Posicion 3:"+table[2].name+"/"+to_string(table[2].points));
	m_score3.setCharacterSize(70);
	m_score3.setPosition(WIDTH/5,HEIGHT/2.5);
	
	///pos4
	
	m_font.loadFromFile("Font/Pixel_Rand.otf");
	m_score4.setFont(m_font);
	m_score4.setFillColor(Color::White);
	m_score4.setString("Posicion 4:"+table[3].name+"/"+to_string(table[3].points));
	m_score4.setCharacterSize(70);
	m_score4.setPosition(WIDTH/5,HEIGHT/1.8);
	
	///pos5
	
	m_font.loadFromFile("Font/Pixel_Rand.otf");
	m_score5.setFont(m_font);
	m_score5.setFillColor(Color::White);
	m_score5.setString("Posicion 5:"+table[4].name+"/"+to_string(table[4].points));
	m_score5.setCharacterSize(70);
	m_score5.setPosition(WIDTH/5,HEIGHT/1.3); 
	
}



bool mayor(datos d1,datos d2){
	if(d1.points>d2.points){return true;}
	return false;
}

void ScoreManager::getBestScore(){
	m_archi_read.open("puntuacion.txt");
	datos aux;
	while (getline(m_archi_read,aux.name)&&m_archi_read>>aux.points){
		table.push_back(aux);
		
		m_archi_read.ignore();
	}
	sort(table.begin(),table.end(),mayor);
	table.resize(5);
	m_archi_read.close();
	
}

	
void ScoreManager::setStats(int points, string name){
	datos a = {name,points};
	table.push_back(a);
	
	sort(table.begin(),table.end(),mayor);
	table.pop_back();
}
void ScoreManager::SaveNewBest(){
	m_archi_write.open("puntuacion.txt",ios::trunc);
	for (int i =0; i<table.size();i++){
		m_archi_write<<table[i].name<<endl<<table[i].points<<endl;
	}
	m_archi_write.close();
}


void ScoreManager::init(RenderWindow &window){
	while(window.isOpen()){
		
		window.clear(Color::Blue);
		window.draw(m_score);
		window.draw(m_score2);
		window.draw(m_score3);
		window.draw(m_score4);
		window.draw(m_score5);
		window.display();
		
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			break;
		}
	}
}

