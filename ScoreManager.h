#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H
#include <fstream>
#include <vector>
#include "SavePoints.h"

using namespace std;
using namespace sf;


struct datos{
	string name;
	int points;
};

class SavePoints;

class ScoreManager {
public:
	ScoreManager();
	void getBestScore();
	void SaveNewBest();
	void setStats(int points, string name);
	void init(RenderWindow &window);
	
private:
	ifstream m_archi_read;
	ofstream m_archi_write;
	int best_score;
	vector<datos>table = {
		{"empty",0},
		{"empty",0},
		{"empty",0},
		{"empty",0},
		{"empty",0}
	};
	
	Font m_font;
	Text m_score;
	Text m_score2;
	Text m_score3;
	Text m_score4;
	Text m_score5;
	
	
};

#endif

