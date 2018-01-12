#ifndef tablemember_h
#define tablemember_h

#include <string>
using namespace std;

//Clase miembro tabla
class tablemember
{
	//Variables
	public:
	string name;
	string teamabrev;
	double score;
	int matches;
	//Funciones
	void AddScore(int value);
	void AddMatch();
};

#endif
