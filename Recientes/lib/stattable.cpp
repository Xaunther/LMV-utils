//Funciones de la clase tabla
#include "lib/stattable.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

stattable::stattable(){Nmembers=0;}
void stattable::Load()
{
	string basura;
	ifstream fichero;
	
	fichero.open(filename.c_str());
	if(!fichero)
	{
		return; //No hay, se creará
	}
    //Bloque de cálculo (lectura de fichero)
    getline(fichero,basura);
    getline(fichero,basura); //Las dos primeras lineas son encabezados
    do //Compruebo que aun no he llegado al final, y luego paso datos al vector
    {
        basura = "";
        fichero >> basura;
        if (basura != "")
        {
            member[Nmembers].name = basura;
            fichero >> basura;
            member[Nmembers].teamabrev = basura.substr(1,3);
            fichero >> member[Nmembers].score;
            fichero >> member[Nmembers].matches;
            Nmembers++;
        }
    }while (basura != "");
    fichero.close();
} 
void stattable::Save()
{
	ofstream fichero;
	
	fichero.open(filename.c_str());
	fichero << "Name           Team     Score    Matches" << endl;
	fichero << "----------------------------------------" << endl;
	//Volcado de la información en el fichero
    for (int i=0;i<Nmembers;i++)
    {
        fichero << left << setfill(' ') << setw(13) << member[i].name;
        fichero << "   ";
        fichero << right << setfill(' ') << setw(5) << "(" + member[i].teamabrev + ")";
        fichero << " ";
        fichero << setfill(' ') << setw(9) << member[i].score;
        fichero << setfill(' ') << setw(11) << member[i].matches << endl;
	}
    //Cierre de fichero
    fichero.close ();
}
void stattable::Ordenar(bool invertido)
{
	tablemember aux;
	if(invertido)
	{
		for(int i=0;i<Nmembers;i++)
		{
			for(int j=i;j<Nmembers;j++)
			{
				if(member[j].score < member[i].score || (member[j].score == member[i].score && member[j].matches > member[i].matches))
				{
					aux = member[i];
					member[i] = member[j];
					member[j] = aux;
				}
			}
		}
	}
	else
	{
		for(int i=0;i<Nmembers;i++)
		{
			for(int j=i;j<Nmembers;j++)
			{
				if(member[j].score > member[i].score || (member[j].score == member[i].score && member[j].matches < member[i].matches))
				{
					aux = member[i];
					member[i] = member[j];
					member[j] = aux;
				}
			}
		}
	}
}
int stattable::Search(string nombre, string abrev, bool AddNewFlag, int start)
{
	for(int i=start;i<Nmembers;i++)
	{
		if(nombre==member[i].name)
		{
			return i;
		}
	}
	if(AddNewFlag)
	{
		AddNew(nombre, abrev);
		return Nmembers - 1;
	}
	return Nmembers;
	
}
void stattable::AddNew(string nombre, string abrev)
{
	member[Nmembers].name = nombre;
	member[Nmembers].teamabrev = abrev;
	member[Nmembers].matches = 0;
	member[Nmembers].score = 0;
	Nmembers++;
}
void stattable::Delete(int pos)
{
	for(int i=pos;i<Nmembers-1;i++)
	{
		member[i] = member[i+1];
	}
	Nmembers--;
}
void stattable::Combine(bool addscore)
{
	int j;
	//Ir uno a uno, mirar repetidos, combinar y "eliminar" la entrada repetida
	for(int i=0;i<Nmembers;i++)
	{
		do
		{
			j = Search(member[i].name, member[i].teamabrev, false,i+1);
			
			if(j < Nmembers && i!=j) //Es decir, si ha encontrado algún duplicado
			{
				if(addscore)
				{
					member[i].score+=member[j].score;
				}
				else
				{
					//Si ha jugado partidos
					if(member[i].matches+member[j].matches>0)
					{
						member[i].score=(member[i].score*member[i].matches + member[j].score*member[j].matches)/(member[i].matches+member[j].matches);
					}
					else //Y si no... no puedo realizar la división
					{
						member[i].score=10;
					}
				}
				member[i].matches+=member[j].matches;
				//Elimino la entrada j
				Delete(j);
			}
		}while(j<Nmembers);
	}
}
