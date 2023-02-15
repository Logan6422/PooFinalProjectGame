#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Music.hpp>
#include "Pochita.h"
#include <vector>
#include "Tilemap.h"
#include "Bird.h"
#include "Bread.h"
#include "Score.h"
#include "Buff.h"
#include "Gameover.h"
#include "MatchData.h"
#include "ScoreManager.h"


using namespace std;
using namespace sf;


class Game {
public:
	
	Game();
	void run(RenderWindow &W);
	template<typename T>
	bool collide(T &a, Pochita &b);
	
private:
	///window
	
	
	Clock clock;
	Time time;
	
	///background
	Texture texture_back;
	Sprite background;
	
	///audio
	Music music;
	Music jump;
	
	///Pochita
	Pochita pochita;
	Bird corven;
	Tilemap enemy;
	Bread coin;
	Score count;
	Buff breads;
	ScoreManager saver;
	
};

#endif

