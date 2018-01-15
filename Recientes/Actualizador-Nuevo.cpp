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
#include <stdlib.h>
#include <time.h>
#include "lib/stattable.h"
#include "lib/equipo.h"
#include "lib/matchmisc.h"
#include "lib/constantes.h"
using namespace std;

//Funcion principal
int main()
{
	int op, optasks;
	string statstablename;
	string matchfiles[TAMpartidos];
	int Npartidos = 0;
	ifstream testf; //Para testar que los archivos existan
	stattable goleadores, asistentes, encajados, tackles;
	bool update = false, decinj = false, decsus = false, fitness = false;
	string injreport, susreport, skchreport;
	
	srand (time(NULL));
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
	if(op < 1 || op > 10)
	{
		cout << "Opcion no valida" << endl;
		system("pause");
		return 0;
	}
	//Por defecto se realiza todo, descomenta las siguientes líneas si quieres activar el resto de opciones
	
	//Pregunto por las tareas a realizar
	/*cout << endl << "Que quieres hacer?" << endl << endl;
	cout << "1) Actualizar plantillas con los ultimos resultados" << endl;
	cout << "2) Reducir lesiones" << endl;
	cout << "3) Reducir suspensiones" << endl;
	cout << "4) Red. suspensiones y actualizar plantillas" << endl;
	cout << "5) Red. suspensiones y red. lesiones" << endl;
	cout << "6) Red. suspensiones y red. lesioes y actualizar plantillas" << endl;
	cout << "7) Anadir fit" << endl;
	cout << "8) Actualizar plantillas" << endl;
	cout << "9) Red. suspensiones y actualizar plantillas" << endl;
	cout << "10) Red. lesiones y actualizar plantillas" << endl;
	cout << "11) Red. suspensiones y red. lesiones y actualizar plantillas" << endl << endl;
	cout << "Introduce opcion -> ";
	cin >> optasks;*/
	optasks = 11;
	cout << endl;
	if(optasks < 1 || optasks > 11)
	{
		cout << "Opcion no valida" << endl;
		system("pause");
		return 0;
	}
	//Rellenar bools que actuan como "flags"
	
	if(optasks == 1)
	{
		update = true;
	}
	else if (optasks == 2)
	{
		decinj = true;
	}
	else if (optasks == 3)
	{
		decsus = true;
	}
	else if (optasks == 4)
	{
		decsus = true;
		update = true;
	}
	else if (optasks == 5)
	{
		decsus =  true;
		decinj = true;
	}
	else if (optasks == 6)
	{
		decsus =  true;
		decinj = true;
		update = true;
	}
	else if (optasks == 7)
	{
		fitness = true;
	}
	else if (optasks == 8)
	{
		update = true;
	}
	else if (optasks == 9)
	{
		update = true;
		decsus = true;
	}
	else if (optasks == 10)
	{
		update = true;
		decinj = true;
	}
	else if (optasks == 11)
	{
		update = true;
		decsus = true;
		decinj = true;
	}
	Nombrar(statstablename, op); //Nombrar los ficheros
	//Preparo las tablas
	goleadores.filename = "goleadores" + statstablename + ".txt";
	goleadores.Load();
	asistentes.filename = "asistentes" + statstablename + ".txt";
	asistentes.Load();
	encajados.filename = "encajados" + statstablename + ".txt";
	encajados.Load();
	tackles.filename = "tackleadores" + statstablename + ".txt";
	tackles.Load();
	
	//Primero hay que leer el stats.dir
	if(update)
	{
		testf.open ("stats.dir");
	    if (!testf)
		{
			cout << "No se ha encontrado stats.dir" << endl << endl;
			system("pause");
			return 0;
		}
		testf.close();
		LeerStatsDir(matchfiles, Npartidos); //Leer el fichero stats.dir con el indice
	}
	
	//Miro si se quieren reducir lesiones y/o sanciones
	if(decsus)
	{
		ReduceSuspensions();
		cout << endl;
	}
	if(decinj)
	{
		ReduceInjuries();
		cout << endl;
	}
	if(update)//Ahora abro los ficheros de cada partido en bucle, y actualizo plantillas
	{
		for(int i=0;i<Npartidos;i++)
		{
			LeerPartido(matchfiles[i], &goleadores, &asistentes, &encajados, &tackles);
		}
		cout << endl;
		//Ordeno las tabla y la guardo
		goleadores.Ordenar(false);
		goleadores.Save();
		cout << "Actualizada tabla de goleadores" << endl;
		asistentes.Ordenar(false);
		asistentes.Save();
		cout << "Actualizada tabla de asistentes" << endl;
		encajados.Ordenar(true);
		encajados.Save();
		cout << "Actualizada tabla de goles encajados" << endl;
		tackles.Ordenar(false);
		tackles.Save();
		cout << "Actualizada tabla de tackleadores" << endl;
		cout << endl;
	}
	if(fitness)
	{
		AddStamina();
		cout << endl;
	}
	system("pause");
	return 0;
}
