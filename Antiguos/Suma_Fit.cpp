/************************************************/
/* Nombre: Xaunther                             */
/* E-mail: alex.1993.24@gmail.com               */
/************************************************/

//Librerías que se incluyen
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

//Definición de constantes
#define TAM 5000

//Declaración de estructuras
struct jugador
{
    string Name;
    int Age;
    string Nat;
    int St;
    int Tk;
    int Ps;
    int Sh;
    int Ag;
    int KAb;
    int TAb;
    int PAb;
    int SAb;
    int Gam;
    int Sub;
    int Min;
    int Mom;
    int Sav;
    int Con;
    int Ktk;
    int Kps;
    int Sht;
    int Gls;
    int Ass;
    int DP;
    int Inj;
    int Sus;
    int Fit;
};

//Índice de las funciones
void LeerIndice (string , string [TAM], int &, ifstream &);
void LeerFichero (jugador [TAM], string , int &, string &, string &);
//void Ordenar (jugador [TAM], int );
void GuardarFichero(jugador [TAM], int , string, string &, string &);
void SumaFit (jugador [TAM], int , int );
int main ();

//Implementación de funciones
//Para leer los transportes de los equipos
void LeerIndice (string F1 , string plantillas[TAM], int &M, ifstream &fichero)
{
     string basura;
     
     fichero >> basura;
     do
     {
         plantillas[M] = basura;
         M++;
         basura = "";
         fichero >> basura;
     }while(basura != "");
}
//Función que lee el fichero y carga el contenido en un vector
void LeerFichero (jugador jug[TAM], string nombre, int &N, string &linea1, string &linea2)
{
    //Declaración de variables
    string basura;
    ifstream fichero;
    
    fichero.open (nombre.c_str());
    
    //Bloque de cálculo (lectura de fichero)
    getline(fichero,linea1);
    getline(fichero,linea2); //Las dos primeras lineas son encabezados
    do //Compruebo que aun no he llegado al final, y luego paso datos al vector
    {
        basura = "";
        fichero >> basura;
        if (basura != "")
        {
            jug[N].Name = basura;
            fichero >> jug[N].Age;
            fichero >> jug[N].Nat;
            fichero >> jug[N].St;
            fichero >> jug[N].Tk;
            fichero >> jug[N].Ps;
            fichero >> jug[N].Sh;
            fichero >> jug[N].Ag;
            fichero >> jug[N].KAb;
            fichero >> jug[N].TAb;
            fichero >> jug[N].PAb;
            fichero >> jug[N].SAb;
            fichero >> jug[N].Gam;
            fichero >> jug[N].Sub;
            fichero >> jug[N].Min;
            fichero >> jug[N].Mom;
            fichero >> jug[N].Sav;
            fichero >> jug[N].Con;
            fichero >> jug[N].Ktk;
            fichero >> jug[N].Kps;
            fichero >> jug[N].Sht;
            fichero >> jug[N].Gls;
            fichero >> jug[N].Ass;
            fichero >> jug[N].DP;
            fichero >> jug[N].Inj;
            fichero >> jug[N].Sus;
            fichero >> jug[N].Fit;
            N++;
        }
    }while (basura != "");
    fichero.close();
}
//Procedimiento para sumar fit
void SumaFit(jugador jug[TAM], int N, int fitness)
{
    //Variables locales
    int i;
    for (i=0;i<N;i++)
    {
    	jug[i].Fit=min(jug[i].Fit+fitness,100);
	}
    
}

//Procedimiento para guardar la información del vector en el fichero
void GuardarFichero(jugador jug[TAM], int N, string nomFichero, string &linea1, string &linea2)
{
    //Inicialización de variables
    ofstream fichero;
    int i;
    //Apertura del fichero
    fichero.open (nomFichero.c_str());
    
    //Encabezados
    fichero << "Name         Age Nat St Tk Ps Sh Ag KAb TAb PAb SAb Gam Sub  Min Mom Sav Con Ktk Kps Sht Gls Ass  DP Inj Sus Fit" << endl;
    fichero << "----------------------------------------------------------------------------------------------------------------" << endl;
    //Volcado de la información en el fichero
    for (i=0;i<N;i++)
    {
        fichero << left << setfill(' ') << setw(13) << jug[i].Name;
        fichero << right << setfill(' ') << setw(3) << jug[i].Age;
        fichero << setfill(' ') << setw(4) << jug[i].Nat;
        fichero << setfill(' ') << setw(3) << jug[i].St;
        fichero << setfill(' ') << setw(3) << jug[i].Tk;
        fichero << setfill(' ') << setw(3) << jug[i].Ps;
        fichero << setfill(' ') << setw(3) << jug[i].Sh;
        fichero << setfill(' ') << setw(3) << jug[i].Ag;
        fichero << setfill(' ') << setw(4) << jug[i].KAb;
        fichero << setfill(' ') << setw(4) << jug[i].TAb;
        fichero << setfill(' ') << setw(4) << jug[i].PAb;
        fichero << setfill(' ') << setw(4) << jug[i].SAb;
        fichero << setfill(' ') << setw(4) << jug[i].Gam;
        fichero << setfill(' ') << setw(4) << jug[i].Sub;
        fichero << setfill(' ') << setw(5) << jug[i].Min;
        fichero << setfill(' ') << setw(4) << jug[i].Mom;
        fichero << setfill(' ') << setw(4) << jug[i].Sav;
        fichero << setfill(' ') << setw(4) << jug[i].Con;
        fichero << setfill(' ') << setw(4) << jug[i].Ktk;
        fichero << setfill(' ') << setw(4) << jug[i].Kps;
        fichero << setfill(' ') << setw(4) << jug[i].Sht;
        fichero << setfill(' ') << setw(4) << jug[i].Gls;
        fichero << setfill(' ') << setw(4) << jug[i].Ass;
        fichero << setfill(' ') << setw(4) << jug[i].DP;
        fichero << setfill(' ') << setw(4) << jug[i].Inj;
        fichero << setfill(' ') << setw(4) << jug[i].Sus;
        fichero << setfill(' ') << setw(4) << jug[i].Fit << endl;
    }
    
    //Cierre de fichero
    fichero.close ();
}
//Función principal
int main ()
{
    //Declaración de variables
    int N = 0, fitness = 0, M = 0, i;
    jugador jug[TAM];
    ifstream fichero;
    string nomFichero = "", indice = "plantillas.txt";
    string linea1, linea2;
    string plantillas[TAM];
          
    //Apertura y lectura de fichero, o mensaje de bienvenida al programa
    fichero.open (indice.c_str());
    if (!fichero)
    {
        cout << "No se ha encontrado el fichero " << indice << endl << endl;
    }
    else
    {
         LeerIndice(indice, plantillas, M, fichero);
         //LeerFichero (jug, fichero, N, linea1, linea2); Para copiar
         fichero.close ();
         cout << "Introduce fit: ";
         cin >> fitness;
         cout << endl;
         for(i=0;i<M;i++)
    	{
          N = 0;
          LeerFichero (jug, plantillas[i], N, linea1, linea2);
          SumaFit (jug, N, fitness);
          GuardarFichero(jug, N, plantillas[i], linea1, linea2);
          cout << plantillas[i] << " actualizado" << endl;
      	}
         cout << endl;
    }
    system("pause");
    return 0;
}
