#include "SavePoints.h"
#include <SFML/Graphics/Text.hpp>
#include <string>
#include "InputBox.h"
#include <SFML/Window/Event.hpp>
using namespace std;
using namespace sf;


SavePoints::SavePoints() {
	m_font.loadFromFile("Font/Pixel_Rand.otf");
	
	nombre = "empty";
	puntaje = 0;
	
	text_comun.setString("Ingrese su nombre (hasta 10 letras):");
	text_comun.setFont(m_font);
	text_comun.setCharacterSize(25);
	text_comun.setColor(Color::Blue);
	text_comun.setPosition(100,20);
	
}

string SavePoints::init(RenderWindow &w,int points){
	string h;
	puntaje = points;
	InputText text_entrada(m_font,30,Color::Black);
	text_entrada.setPosition(120,50);
	text_entrada.setMaxChars(10); 
	text_entrada.setSingleWord(true); 
	while(w.isOpen()) {
		
		
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
			else if (e.type==Event::KeyPressed && e.key.code==Keyboard::Return) { 
				nombre = text_entrada.getValue(); 
				palabras += "\n\t";
				
				
			} else text_entrada.processEvent(e); 
			
			
		}
		
		h = nombre;
		
		
		
		// dibujar
		w.clear(Color(255,255,255,255));
		text_entrada.update(); 
		w.draw(text_comun);
		w.draw(text_entrada);
		w.draw(text_palabras);
		w.display();
		if(Keyboard::isKeyPressed(Keyboard::Return)){
			break;
		}
	}
	return text_entrada.getValue();
}


