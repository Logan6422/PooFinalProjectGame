#ifndef SAVEPOINTS_H
#define SAVEPOINTS_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include "ScoreManager.h"

using namespace std;
using namespace sf;



class SavePoints {
public:
	SavePoints();
	string init(RenderWindow &window,int points);
private:
	
	Font m_font;
	Text ingresado;
	
	string nombre;
	int puntaje;
	
	
	
	string palabras;
	Text text_comun;
	Text text_palabras;
};

#endif

