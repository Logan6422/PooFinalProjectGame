#ifndef MATCHDATA_H
#define MATCHDATA_H
#include <vector>
#include <fstream>
#include <string>
using namespace std;


class MatchData {
public:
	MatchData();
	void OpenForRead();
	void CreateBinary();
	void setPoints(const int points);
	void SavePoints();
	int getPoints();
	void readData();
private:
	ifstream m_archi_read;
	ofstream m_archi_write;
	int m_score;
};

#endif

