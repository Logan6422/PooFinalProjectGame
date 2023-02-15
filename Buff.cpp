#include "Buff.h"
#include "config.hpp"


#include <sstream>
using namespace std;

Buff::Buff() {
	///set points to 0
	act_bread = 0;
	
	///load font 
	font.loadFromFile("Font/Pixel_Rand.otf");
	
	///set text
	text_bread.setFont(font);
	
	///set text size
	text_bread.setCharacterSize(30);
	
	///set text color
	text_bread.setColor(Color(0,0,0));
	
	///set position
	text_bread.setPosition(WIDTH-20,35);
	bread_tex.loadFromFile("Images/Bread.png");
	this->currentFrame = IntRect(0,0,32,32);
	bread_spr.setTexture(bread_tex);
	bread_spr.setPosition(WIDTH-30,20);
	
}


void Buff::addBreadPlayer(){
	
	///add bread to de counter 
	
	act_bread += 1;
}

void Buff::show(RenderWindow &w){
	
	/// show breads
	
	stringstream pl;
	
	pl<<act_bread;
	
	text_bread.setString(pl.str());
	
	w.draw(bread_spr);
	w.draw(text_bread);	
}
