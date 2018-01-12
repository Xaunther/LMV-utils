/*************************************************************
*Actualizador de plantillas                                  *
*Deberia sustituir el actualizador de ESMS                   *
*                                                            *
*                                                            *
*                                                            *
*************************************************************/
//Librerias a importar
#include <iostream>
#include <string>
#include <fstream>
#include "equipo.h"
#include "matchmisc.h"
using namespace std;

//Funcion principal
int main()
{
	string filename;
	string GKTitular;
	ifstream input;
	int Nteams = 0;
	//Leer teams.dir
	input.open("teams.dir");
	while(!input.eof())
	{
		input >> filename;
		equipo eq(filename.substr(0,3));
		eq.Load();
		if(eq.Njugadores > 0)
		{
			GKTitular = GetGKSht(filename.substr(0,3) + "sht.txt");
			if (GKTitular != "")
			{
				if(eq.VetoedGK() == GKTitular)
				{
					cout << filename.substr(0,3) + "sht.txt" << ": GK ilegal" << endl;
				}
				else
				{
					cout << filename.substr(0,3) + "sht.txt" << ": Ok" << endl;
				}
			}
			else
			{
				cout << filename.substr(0,3) + "sht.txt not found" << endl;
			}
		}
		eq.Clear();
	}
	input.close();
	system("pause");
	return 0;
}
