#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace sf;

class MainMenu {
public:
	MainMenu();
	void draw(RenderWindow &w);
	void MoveUp();
	void MoveDown();
	int MainMenuPressed();
	~MainMenu();
private:
	int MainMenuSelected;
	Font font;
	Text mainMenu[3];
	
	Text instrucciones;
};

#endif

