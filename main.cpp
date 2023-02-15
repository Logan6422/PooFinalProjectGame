#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "config.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Menu.h"
using namespace sf;

int main(int argc, char *argv[]){
	///window setup
	RenderWindow MENU(VideoMode(WIDTH,HEIGHT,BPP),"Pouchita",Style::Close|Style::Titlebar);
	///sync vertical
	MENU.setFramerateLimit(60);
	Menu h;
	h.Procces(MENU);
	return 0;
}

