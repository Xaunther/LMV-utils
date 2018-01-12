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
void LeerFichero (jugador [TAM], string , int &, string &, string &);
//void Ordenar (jugador [TAM], int );
void Ordenar (jugador [TAM], int );
void GuardarFichero(jugador [TAM], int , string, string &, string &);
int main (int, char *[]);

//Implementación de funciones
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
//Procedimiento para ordenar la lista de jugadores
void Ordenar(jugador jug[TAM], int N)
{
    //Variables locales
    int A = 0, B = 0, C = 0, D = 0, i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        if (jug[i].St > jug[i].Tk) //Portero
        {
            for (j=0;j<A;j++)
            {
                if ((jug[i].St > jug[j].St) || (jug[i].St == jug[j].St && jug[i].Age < jug[j].Age))
                {
                    //Intercambio
                    jug[N] = jug[j];
                    jug[j] = jug[i];
                    jug[i] = jug[N];
                }   
            }
            //El portero más malo queda en la posición i
            for (j=A;j<i;j++)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }
            A++;
        }
        else if (jug[i].Tk > jug[i].St && jug[i].Tk > jug[i].Ps && jug[i].Tk > jug[i].Sh) // DEFENSA
        {
            for (j=A;j<A+B;j++)
            {
                if ((jug[i].Tk > jug[j].Tk) || (jug[i].Tk == jug[j].Tk && jug[i].Age < jug[j].Age))
                {
                    //Intercambio
                    jug[N] = jug[j];
                    jug[j] = jug[i];
                    jug[i] = jug[N];
                }   
            }
            //El defensa más malo queda en la posición i
            for (j=A+B;j<i;j++)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }
            B++;
        }
        else if (jug[i].Ps > jug[i].St && jug[i].Ps > jug[i].Tk && jug[i].Ps > jug[i].Sh) // MEDIO
        {
            for (j=A+B;j<A+B+C;j++)
            {
                if ((jug[i].Ps > jug[j].Ps) || (jug[i].Ps == jug[j].Ps && jug[i].Age < jug[j].Age))
                {
                    //Intercambio
                    jug[N] = jug[j];
                    jug[j] = jug[i];
                    jug[i] = jug[N];
                }   
            }
            //El medio más malo queda en la posición i
            for (j=A+B+C;j<i;j++)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }
            C++;
        }
        else if (jug[i].Sh > jug[i].St && jug[i].Sh > jug[i].Tk && jug[i].Sh > jug[i].Ps) // DELANTERO
        {
            for (j=A+B+C;j<A+B+C+D;j++)
            {
                if ((jug[i].Sh > jug[j].Sh) || (jug[i].Sh == jug[j].Sh && jug[i].Age < jug[j].Age))
                {
                    //Intercambio
                    jug[N] = jug[j];
                    jug[j] = jug[i];
                    jug[i] = jug[N];
                }   
            }
            //El delantero más malo queda en la posición i
            for (j=A+B+C+D;j<i;j++)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }
            D++;
        }
        else                                                                              //Medio con secundaria igual
        {
        	for (j=A+B;j<A+B+C;j++)
            {
                if ((jug[i].Ps > jug[j].Ps) || (jug[i].Ps == jug[j].Ps && jug[i].Age < jug[j].Age))
                {
                    //Intercambio
                    jug[N] = jug[j];
                    jug[j] = jug[i];
                    jug[i] = jug[N];
                }   
            }
            //El medio más malo queda en la posición i
            for (j=A+B+C;j<i;j++)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }
            C++;
		}
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
    fichero << "Name         Age Nat St Tk Ps Sh Ag KAb TAb PAb SAb Gam Fit  Min Mom Sav Con Ktk Kps Sht Gls Ass  DP Inj Sus Sta" << endl;
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
int main (int argc, char* argv[])
{
    //Declaración de variables
    int N = 0, M = 0, i;
    jugador jug[TAM];
    string nomFichero;
    ifstream fichero;
    string linea1, linea2;
    nomFichero=argv[1];
    
    N = 0;
    LeerFichero (jug, nomFichero, N, linea1, linea2);
    Ordenar (jug, N);
    GuardarFichero(jug, N, nomFichero, linea1, linea2);
    return 0;
}
