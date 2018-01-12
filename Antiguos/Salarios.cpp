/************************************************/
/* Nombre: Alejandro                            */
/* Apellidos: Alfonso Albero                    */
/* Práctica final: Gestión de un Videoclub      */
/************************************************/

//Librerías que se incluyen
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <math.h>
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
struct salario
{
    string club;
    double valor;
};

//Índice de las funciones
void LeerIndice (string , string [TAM], int &, ifstream &);
void LeerFichero (jugador [TAM], string , int &, string &, string &);
double Salarios (jugador [TAM], int );
void Ordenar (salario [500], int );
void Post (salario [500], int , string);
string AddMillares (int);
string AddZeroes(string, int);
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
//Calcular salarios
double Salarios (jugador jug[TAM], int N)
{
    int i;
    int indexedad;
    int filtabla = 16, filtablaedad = 7;
    double total = 0;
    double tabla[filtabla] = {0, 0, 0 , 0.5, 0.8, 1.4, 2.1, 3.8, 7, 12.6, 19, 28, 36, 47, 61, 80}; //Salario base desde media 15 a 30
    double tablaedad[filtablaedad][2] =
	{
    	{19, 1.0},
    	{21, 1.0},
    	{25, 1.0},
    	{29, 1.0},
    	{32, 0.9},
    	{34, 0.85},
    	{80, 0.75},
	}; //Tabla de edad: edad maxima del rango y multiplicador
    
    //Calculo salarios
    for(i=0;i<N;i++)
    {
    	//Obtengo el multiplicador del jugador por edad
    	for(indexedad = 0;indexedad < filtablaedad;indexedad++)
    	{
    		if(tablaedad[indexedad][0] >= jug[i].Age)
    		{
    			break;
			}
		}
        if (jug[i].St >= jug[i].Tk && jug[i].St >= jug[i].Ps && jug[i].St >= jug[i].Sh) //portero
        {
        	double salario = tabla[jug[i].St - 15];
            total = total + salario;
        }
        else // jugador de campo
        {
        	int media = max(jug[i].Tk, max(jug[i].Ps, jug[i].Sh));
        	double salario = tablaedad[indexedad][1] * tabla[media - 15] * (1.0 + (jug[i].Tk+jug[i].Ps+jug[i].Sh-media - 2)/double(media));
            total = total + salario;
        }
    }
    return total * 1000000;
}
//Ordenar de mayor salario a menor
void Ordenar (salario sal[500], int M)
{
     int i,j;
     salario A; //Para intercambiar
     for(i=0;i<M;i++)
     {
         for(j=i;j<M;j++)
         {
             if(sal[j].valor > sal[i].valor)
             {
                 A = sal[i];
                 sal[i] = sal[j];
                 sal[j] = A;
             }
         }
     }
     
}

//Para hacer el post
void Post (salario sal[500], int M, string nomFichero)
{
     int i;
     int decimales = 0;
     ofstream fichero;
    //Apertura del fichero
    fichero.open (nomFichero.c_str());
    fichero << "<pre>";
    for(i=0;i<M;i++)
    {
    	string salariopuntos = AddMillares(int(sal[i].valor));
    	fichero << i+1 << ". (" << sal[i].club << ") " << salariopuntos << " €" << endl;
        //fichero.precision(int(log(sal[i].valor)/log(10)) + 1 + decimales);
        //fichero << i+1 << ". (" << sal[i].club << ") " << sal[i].valor << " €" << endl;
    }
}

string AddMillares(int numero) //Devuelve una string con el numero formateado con puntos cada 1000
{
	ostringstream ss;
	int resto = numero;
	string numero_str;
	int i = 1;
	
	ss << (resto % int(pow(1000,i))) / int(pow(1000,i-1));
	numero_str = AddZeroes(ss.str(),3);
	resto = resto - (resto % int(pow(1000,i)));
	ss.str("");
	i++;
	while(resto > 0)
	{
		numero_str = "." + numero_str; //Añado punto
		
		ss << (resto % int(pow(1000,i))) / int(pow(1000,i-1));
		numero_str = AddZeroes(ss.str(),3) + numero_str;
		resto = resto - (resto % int(pow(1000,i)));
		ss.str("");
		i++;
	}
	//El numero no puede empezar por 0, asi que hay que quitar los ceros sobrantes al inicio
	while(numero_str[0] == '0')
	{
		numero_str = numero_str.substr(1);
	}
	return numero_str;
}

string AddZeroes(string word, int length)
{
	string final = word;
	int toadd =  length - word.length();
	for(int i=0;i<toadd;i++)
	{
		final = "0" + final;
	}
	return final;
}
//Función principal
int main ()
{
    //Declaración de variables
    int N = 0, op = 0, M = 0, i;
    double rate = 0;
    jugador jug[TAM];
    ifstream fichero;
    string nomFichero = "Post.txt", indice = "plantillas.txt";
    string linea1, linea2, ans;
    string plantillas[300];
    salario sal[300];
    
    //Apertura y lectura de fichero, o mensaje de bienvenida al programa
    fichero.open (indice.c_str());
    if (!fichero)
    {
        cout << "No se ha encontrado el fichero " << indice << endl << endl;
    }
    else
    {
        do
        {
             ans = "0";
             LeerIndice(indice, plantillas, M, fichero);
             //LeerFichero (jug, fichero, N, linea1, linea2); Para copiar
             fichero.close ();
             cout << "Que desea hacer?" << endl;
             cout << "1: Calcular 30%" << endl;
             cout << "2: Calcular 35%" << endl;
             cout << "3: Calcular 40%" << endl;
             cout << "4: Calcular 60%" << endl;
             cout << "5: Calcular 100%" << endl;
             cout << "0: Salir" << endl;
             cin >> op;
             cout << endl;
             if (op == 1)
             {
                  rate = 0.3;
                  ans = "y";
             }
             else if (op == 2)
             {
                  rate = 0.35;
                  ans = "y";
                          }
             else if (op == 3)
             {
                  rate = 0.4;
                  ans = "y";
             }
             else if (op == 4)
             {
                  rate = 0.6;
                  ans = "y";
             }
             else if (op == 5)
             {
                  rate = 1.0;
                  ans = "y";
             }
             if (ans == "y")
             {
                 for(i=0;i<M;i++)
                 {
                     N = 0;
                     LeerFichero (jug, plantillas[i], N, linea1, linea2);
                     sal[i].club = plantillas[i].substr (0,3);
                     sal[i].valor = Salarios (jug, N) * rate;
                     cout << sal[i].club << " calculado" << endl;
                 }
                 cout << endl;
             
                 ans = "0";
                 cout << "Ordenar por salario? (y/n): ";
                 cin >> ans;
             
                 if (ans == "y")
                 {
                     Ordenar (sal, M);
                 }
                 cout << endl << endl;
                 Post(sal, M, nomFichero);
             }
        }while(op != 0);
    }
    return 0;
}
