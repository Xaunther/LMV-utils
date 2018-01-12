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
#include <iomanip>
#include <cmath>
#include "matchmisc.h"
#include "constantes.h"
#include "stattable.h"
using namespace std;

//Funcion principal
int main()
{
	int op;
	string statstablename;
	ifstream testf; //Para testar que los archivos existan
	stattable goleadores, asistentes, encajados, tackleadores;
	int Npartidos = 0;
	string tablefiles[TAMtablas];
	//Testeo que exista tables.dir
	testf.open("tables.dir");
	if(!testf)
	{
		cout << "No se ha encontrado tables.dir" << endl;
		system("pause");
		return 0;
	}
	testf.close();
	
	//Lo primero que toca hacer es preguntar que tipo de competición hay que actualizar (liga, copa...)
	cout << "Que competicion vas a actualizar?" << endl << endl;
	cout << "1) Liga" << endl;
	cout << "2) Copa nacional" << endl;
	cout << "3) Supercopa nacional" << endl;
	cout << "4) Champions League" << endl;
	cout << "5) Europa League" << endl;
	cout << "6) Supercopa Europa" << endl;
	cout << "7) Competicion selecciones" << endl;
	cout << "8) Copa LMV" << endl;
	cout << "9) Copa de Clase" << endl;
	cout << "10) Mundial de clubes" << endl << endl;
	cout << "Introduce opcion -> ";
	cin >> op;
	Nombrar(statstablename, op); //Nombrar los ficheros
	
	LeerTablesDir(tablefiles, Npartidos);
	for(int i=0;i<Npartidos;i++)
	{
		//Preparo las tablas
		goleadores.filename = tablefiles[i] + "goleadores" + statstablename + ".txt";
		asistentes.filename = tablefiles[i] + "asistentes" + statstablename + ".txt";
		encajados.filename = tablefiles[i] + "encajados" + statstablename + ".txt";
		tackleadores.filename = tablefiles[i] + "tackleadores" + statstablename + ".txt";
		
		goleadores.Load();
		asistentes.Load();
		encajados.Load();
		tackleadores.Load();
		
	}
	goleadores.Combine(true);
	asistentes.Combine(true);
	encajados.Combine(false);
	tackleadores.Combine(true);

	//ordeno
	goleadores.Ordenar(false);
	asistentes.Ordenar(false);
	encajados.Ordenar(true);
	tackleadores.Ordenar(false);
	
	//Guardo
	goleadores.filename = "goleadores" + statstablename + ".txt";
	asistentes.filename = "asistentes" + statstablename + ".txt";
	encajados.filename = "encajados" + statstablename + ".txt";
	tackleadores.filename = "tackleadores" + statstablename + ".txt";
	
	goleadores.Save();
	asistentes.Save();
	encajados.Save();
	tackleadores.Save();
	
	system("pause");
	return 0;
}
