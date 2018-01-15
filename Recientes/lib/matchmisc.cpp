//Resto de funciones relacionadas con el partido
#include "lib/matchmisc.h"
#include "lib/stattable.h"
#include "lib/equipo.h"
#include "lib/textmisc.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void Nombrar(string &statstablename, int op)
{
	if(op==1)
	{
		statstablename = "league";
	}
	else if(op==2)
	{
		statstablename = "cup";
	}
	else if(op==3)
	{
		statstablename = "supercup";
	}
	else if(op==4)
	{
		statstablename = "champions";
	}
	else if(op==5)
	{
		statstablename = "europaleague";
	}
	else if(op==6)
	{
		statstablename = "eurosupercup";
	}
	else if(op==7)
	{
		statstablename = "international";
	}
	else if(op==8)
	{
		statstablename = "LMVcup";
	}
	else if(op==9)
	{
		statstablename = "classcup";
	}
	else if(op==10)
	{
		statstablename = "clubworldcup";
	}
}

//Leer stats.dir
void LeerStatsDir(string matchfiles[TAMpartidos], int &N)
{
	ifstream fichero;
    string basura;
    
    fichero.open("stats.dir");
    fichero >> basura;
    do
    {
        matchfiles[N] = basura;
        N++;
        basura = "";
        fichero >> basura;
    }while(basura != "");
    
    fichero.close();
}

//Leer stats.dir
void LeerTablesDir(string tablefiles[TAMtablas], int &N)
{
	ifstream fichero;
    string basura;
    
    fichero.open("tables.dir");
    getline(fichero, basura);
    do
    {
        tablefiles[N] = basura;
        N++;
        basura = "";
        getline(fichero, basura);
    }while(basura != "");
    
    fichero.close();
}

//Leer un partido
void LeerPartido(string matchfile, stattable* goleadores, stattable* asistentes, stattable* encajados, stattable* tackles)
{
	//Variables
	ifstream fichero;
	string basura;
	int indexjug; //Para guardar la posición en la que se encuentra el jugador que buscamos
	int indextabla;
	int value; //Para guardar lo que se va leyendo del fichero
	bool hajugado;
	bool lesionado;
	//Abro el fichero del partido
	fichero.open(matchfile.c_str());
	//Si no se encuentra, no hasemos ná
	if(!fichero)
	{
		cout << "No se ha encontrado el fichero " << matchfile << endl;
		return;
	}
	
	for(int i=0;i<2;i++) //2 veces, equipo local y luego el visitante
	{
		//Abreviatura equipo
		fichero >> basura;
		equipo eq(basura);
		eq.Load(); //Relleno el equipo usando su archivo correspondiente
		
		fichero >> basura; //Tiro el resultado
		for(int j=0;j<16;j++) //Bucle sobre los 16 hombres convocados
		{
			fichero >> basura; //Recojo el nombre
			indexjug = eq.Search(basura); //Obtengo la posición donde se encuentra ese jugador, que será modificado 
			//Empezamos las modificaciones
			fichero >> value;
			hajugado = value;
			eq.jug[indexjug].AddGam(value);
			fichero >> value;
			//eq.jug[indexjug].AddSub(value); El ESMS original usa esto como numero de subs, ahora es el cansancio
			fichero >> value;
			eq.jug[indexjug].AddMin(value);
			eq.jug[indexjug].MinHoy = value;
			fichero >> value;
			eq.jug[indexjug].AddMom(value);
			fichero >> value;
			eq.jug[indexjug].AddSav(value);
			fichero >> value;
			eq.jug[indexjug].AddCon(value);
			indextabla = encajados->Search(eq.jug[indexjug].Name, eq.abreviatura, eq.jug[indexjug].isGK()); //Posicion en tabla de encajados
			if(hajugado && eq.jug[indexjug].isGK()) //Si ha jugado, sumar un partido
			{
				encajados->member[indextabla].AddMatch();
			}
			if(encajados->member[indextabla].matches > 0 && eq.jug[indexjug].isGK())
			{
				encajados->member[indextabla].score = (encajados->member[indextabla].score*(encajados->member[indextabla].matches - hajugado)+value)/encajados->member[indextabla].matches;
			}
			else if(eq.jug[indexjug].isGK())
			{
				encajados->member[indextabla].score = 10;
			}
			
			
			fichero >> value;
			eq.jug[indexjug].AddKtk(value);
			indextabla = tackles->Search(eq.jug[indexjug].Name, eq.abreviatura); //Posicion en tabla de tackleadores
			tackles->member[indextabla].AddScore(value);
			if(hajugado) //Si ha jugado, sumar un partido
			{
				tackles->member[indextabla].AddMatch();
			}
			fichero >> value;
			eq.jug[indexjug].AddKps(value);
			fichero >> value;
			eq.jug[indexjug].AddSht(value);
			fichero >> value;
			eq.jug[indexjug].AddGls(value); //Y añado goleadores a la liga
			indextabla = goleadores->Search(eq.jug[indexjug].Name, eq.abreviatura); //Posicion en tabla de goleadores
			goleadores->member[indextabla].AddScore(value);
			if(hajugado) //Si ha jugado, sumar un partido
			{
				goleadores->member[indextabla].AddMatch();
			}
			fichero >> value;
			eq.jug[indexjug].AddAss(value);
			indextabla = asistentes->Search(eq.jug[indexjug].Name, eq.abreviatura); //Posicion en tabla de asistentes
			asistentes->member[indextabla].AddScore(value);
			if(hajugado) //Si ha jugado, sumar un partido
			{
				asistentes->member[indextabla].AddMatch();
			}
			fichero >> value;
			eq.jug[indexjug].AddDP(value); 
			//Determinar posibles sanciones
			if(value > 0)
			{
				eq.jug[indexjug].DetSus(value, eq.abreviatura);
			}
			fichero >> value;
			lesionado = value;
			fichero >> value;
			eq.jug[indexjug].AddHAb(value, eq.abreviatura, "St");
			fichero >> value;
			eq.jug[indexjug].AddHAb(value, eq.abreviatura, "Tk");
			fichero >> value;
			eq.jug[indexjug].AddHAb(value, eq.abreviatura, "Ps");
			fichero >> value;
			eq.jug[indexjug].AddHAb(value, eq.abreviatura, "Sh");
			fichero >> value; // Asumiremos que necesitamos 999 de exp para subir, sudamos del -999
			fichero >> value; //Ignoramos el fit del simulador
			if(lesionado)
			{
				eq.jug[indexjug].SetInj(eq.abreviatura);
			}
		}
		eq.SetCond(); //Nueva función para establecer la condicion fisica en funcion de los minutos y la edad
		eq.SetTrd(); //Nueva función para sumar stamina en funcion de los minutos jugados
		eq.ComputeFit();
		//Guardo el equipo
		eq.Save();
		cout << eq.nombre << " actualizado." << endl;
		//Borro para ser reutilizado
		eq.Clear();
	}
	fichero.close();
}


void ReduceSuspensions()
{
	ifstream fdir; //Para leer teams.dir
	string teamfile;
	string basura = "";
	fdir.open("teams.dir");
	if(!fdir)
	{
		cout << "teams.dir no encontrado." << endl;
		return;
	}
	//Leer archivos
	fdir >> basura;
	while(basura!="")
	{
		teamfile = basura;
		basura = "";
		fdir >> basura;
		equipo eq(teamfile.substr(0,3));
		eq.Load();
		eq.ReduceSus();
		eq.Save();
		cout << "Reducidas suspensiones en " << eq.nombre << endl;
	}
}
void ReduceInjuries()
{
	ifstream fdir; //Para leer teams.dir
	string teamfile;
	string basura = "";
	fdir.open("teams.dir");
	if(!fdir)
	{
		cout << "teams.dir no encontrado." << endl;
		return;
	}
	//Leer archivos
	fdir >> basura;
	while(basura!="")
	{
		teamfile = basura;
		basura = "";
		fdir >> basura;
		equipo eq(teamfile.substr(0,3));
		eq.Load();
		eq.ReduceInj();
		eq.Save();
		cout << "Reducidas lesiones en " << eq.nombre << endl;
	}
}
void AddStamina()
{
	ifstream fdir; //Para leer teams.dir
	string teamfile;
	string basura = "";
	fdir.open("teams.dir");
	if(!fdir)
	{
		cout << "teams.dir no encontrado." << endl;
		return;
	}
	//Leer archivos
	fdir >> basura;
	while(basura!="")
	{
		teamfile = basura;
		basura = "";
		fdir >> basura;
		equipo eq(teamfile.substr(0,3));
		eq.Load();
		eq.AddTrd(GetLeagueDat("FitFactor"));
		eq.ComputeFit();
		eq.Save();
		cout << "Anadida stamina para " << eq.nombre << endl;
	}
}
string GetGKSht(string filename)
{
	ifstream input;
	string basura;
	string GKName;
	
	input.open(filename.c_str());
	if(!input)
	{
		return "";
	}
	do
	{
		input >> basura;
	}while(basura != "GK");
	input >> GKName;
	input.close();
	return GKName;
}
