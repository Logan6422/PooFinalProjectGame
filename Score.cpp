#include "Score.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <sstream>
using namespace std;

Score::Score() {
	///set points to 0
	points_player = 0;
	
	///load font 
	font.loadFromFile("Font/Pixel_Rand.otf");
	
	///set text
	text_player.setFont(font);
	ss.setFont(font);
	
	///set text size
	text_player.setCharacterSize(30);
	ss.setCharacterSize(30);
	
	///set text color
	text_player.setColor(Color(0,0,0));
	ss.setColor(Color(0,0,0));
	
	///set position
	text_player.setPosition(80,20);
	ss.setPosition(15,20);
	
	spd = 1;
	
	
}


void Score::updateSpeed(){
	spd++;
}
void Score::addPointPlayer(){
	points_player += 1*spd;
}

void Score::show(RenderWindow &w){
	stringstream pl;
	
	pl<<points_player;
	
	text_player.setString(pl.str());
	ss.setString("Score: ");
	
	
	w.draw(text_player);
	w.draw(ss);
	
}

int Score::GetPlayerPoints(){
	return points_player;
}
