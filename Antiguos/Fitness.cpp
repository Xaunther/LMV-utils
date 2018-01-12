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
void LeerIndice (string , string [TAM], int [TAM], int &);
void LeerFichero (jugador [TAM], int &, string );
void GuardarFichero(jugador [TAM], int , string );

//Para leer los transportes de los equipos
void LeerIndice (string F1 , string plantillas[TAM], int transporte[TAM], int &M)
{
     ifstream fichero;
     string basura;
     
     fichero.open (F1.c_str());
     if (!fichero)
     {
         cout << F1 << " no encontrado" << endl;
     }
     else
     {
         fichero >> basura;
         do
         {
             plantillas[M] = basura;
             fichero >> transporte[M];
             M++;
             basura = "";
             fichero >> basura;
         }while(basura != "");
     }
}

//Leer plantillas
void LeerFichero (jugador jug[TAM], int &N, string nombre)
{
    //Declaración de variables
    string basura;
    ifstream fichero;
    fichero.open (nombre.c_str());
    //Bloque de cálculo (lectura de fichero)
    getline(fichero,basura);   
    getline(fichero,basura); //Las dos primeras lineas son encabezados
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
}

//Procedimiento para guardar la información del vector en el fichero
void GuardarFichero(jugador jug[TAM], int N, string nomFichero)
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
    int N = 0, op = 0, M = 0, i, j;
    jugador jug[TAM];
    string plantillas[TAM];
    string F1 = "Transporte.txt";
    int transporte[TAM];
    
    //Leo el fichero con los transportes de cada equipo
    LeerIndice(F1, plantillas, transporte, M);
    
    //Actualizo fit
    for (i=0;i<M;i++)
    {
        N = 0;
        LeerFichero(jug, N, plantillas[i]);
        for (j=0;j<N;j++)
        {
            jug[j].Fit = jug[j].Fit - transporte[i];
        }
        GuardarFichero(jug, N, plantillas[i]);
        cout << plantillas[i] << " actualizado" << endl;
    }
    
    cout << "Hecho" << endl << endl;
    cout << "Desarrollado por Tatiko para www.ligamanagervirtual.com" << endl << endl;
    system("Pause");
    return 0;
}
