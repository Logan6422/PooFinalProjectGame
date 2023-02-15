#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "MainMenu.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;

class Menu {
public:
	Menu();
	void Procces(RenderWindow &	MENU);
private:
	///audio
	Music music;
	Music jump;
	MainMenu mainMenu;
	Texture texture_back;
	Sprite background;
};

#endif

