#ifndef stattable_h
#define stattable_h

#include "tablemember.h"
#include "constantes.h"
using namespace std;

//Clase tabla goleadores
class stattable
{
	//Variables
	public:
	tablemember member[TAM];
	int Nmembers;
	string filename;
	//Functions
	stattable();
	void Load();
	int Search(string, string, bool AddNewFlag = true, int start = 0); //Devuelve el puesto de la tabla donde se encuentra el jugador (si es nuevo, lo añade al final si la opcion AddNew está activada)
	void Ordenar(bool);
	void Save();
	void AddNew(string, string);
	void Delete(int pos);
	void Combine(bool addscore); //Busca jugadores repetidos y combina sus stats. True si el stat es aditivo(goles,ass) o false si es de promedio
};

#endif
