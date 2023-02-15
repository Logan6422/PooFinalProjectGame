#include "MatchData.h"
#include <iomanip>
#include <iostream>
using namespace std;

MatchData::MatchData() {
	m_score = 0;
	
	OpenForRead();
}

void MatchData::OpenForRead(){
	m_archi_read.open("puntajes.txt");
	
	readData();
	m_archi_read.close();
}
void MatchData::setPoints(const int points){
	m_score = points;
}
void MatchData::SavePoints(){
	
	m_archi_write.open("puntajes.txt",ios::trunc);
	if(!m_archi_write.is_open()) {
		cerr << "Error el archivo no se pudo abrir para escritura" << endl;
	}
	
	m_archi_write<<m_score;
	
	m_archi_write.close();
	readData();
	
}
int MatchData::getPoints(){
	return m_score;
}
void MatchData::readData(){	
	
	m_archi_read>>m_score;
	
}

