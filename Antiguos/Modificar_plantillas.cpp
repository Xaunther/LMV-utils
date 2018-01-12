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
void Actualizar (jugador [TAM], int , int);
void Subirmediappal (jugador [TAM], int );
void Reiniciar (jugador [TAM], int );
void Envejecer (jugador [TAM], int );
void Ordenar (jugador [TAM], int );
void GuardarFichero(jugador [TAM], int , string, string &, string &);
void Rerankeo (jugador [TAM], int );
void ReajT14 (jugador [TAM], int );
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

//Procedimiento para ordenar la lista de jugadores  (NO SE USA)
/*void Ordenar(jugador jug[TAM], int N)
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
    }
}*/


//Procedimiento para actualizar las plantillas según minutos y edad
void Actualizar (jugador jug[TAM], int N, int op)
{
     int filEdad = 20, filMedia = 20; //Número de filas de las tablas, he puesto de más 
     int i, j, k, l, res;
     double tablaEdad[filEdad][2], tablaMedia[filMedia], bonus;
	 double PtablaEdad[filEdad][2], PtablaMedia[filMedia]; //Tablas de porteros 
     
     //Tabla de edad. Primero los intervalos de edad y luego los valores
	 tablaEdad[0][0]=17; //Hasta 17 años
	 tablaEdad[1][0]=22; //De 18 a 22, etc.
	 tablaEdad[2][0]=28;
	 tablaEdad[3][0]=31;
	 tablaEdad[4][0]=34;
	 tablaEdad[5][0]=60;
	 
	 tablaEdad[0][1]=0.7; //Aquí los porcentajes (sobre uno en realidad asi que serian porunajes huehue)
	 tablaEdad[1][1]=0.7; //A los negativos... ya veremos
	 tablaEdad[2][1]=0.7;
	 tablaEdad[3][1]=0.7;
	 tablaEdad[4][1]=0.7;
	 tablaEdad[5][1]=0.7;
	 
	 //Tabla media. La componente 0 corresponde a media 15, y de ahi para arriba
	 tablaMedia[0]=1.0; //Aquí los porunajes
	 tablaMedia[1]=1.0; //Aquí mejor no pongas negativos, o quizá se te cruzará negativo*negativo y we are fucked
	 tablaMedia[2]=0.9;
	 tablaMedia[3]=0.8;
	 tablaMedia[4]=0.7;
	 tablaMedia[5]=0.6;
	 tablaMedia[6]=0.5;
	 tablaMedia[7]=0.3;
	 tablaMedia[8]=0.2;
	 tablaMedia[9]=0.1;
     tablaMedia[10]=0.05;
     tablaMedia[11]=0.02;	 
    //Tablas de los porteros  
	//Tabla de edad. Primero los intervalos de edad y luego los valores
	 PtablaEdad[0][0]=17; //Hasta 17 años
	 PtablaEdad[1][0]=22; //De 18 a 22, etc.
	 PtablaEdad[2][0]=28;
	 PtablaEdad[3][0]=31;
	 PtablaEdad[4][0]=34;
	 PtablaEdad[5][0]=60;
	 
	 PtablaEdad[0][1]=0.7; //Aquí los porcentajes (sobre uno en realidad asi que serian porunajes huehue)
	 PtablaEdad[1][1]=0.7; //Si pones números negativos, saldrá un bonus negativo :)
	 PtablaEdad[2][1]=0.7;
	 PtablaEdad[3][1]=0.7;
	 PtablaEdad[4][1]=0.7;
	 PtablaEdad[5][1]=0.7;
	 
	 //Tabla media. La componente 0 corresponde a media 15, y de ahi para arriba
	 PtablaMedia[0]=1.0; //Aquí los porunajes
	 PtablaMedia[1]=1.0; //Aquí mejor no pongas negativos, o quizá se te cruzará negativo*negativo y we are fucked
	 PtablaMedia[2]=0.9;
	 PtablaMedia[3]=0.8;
	 PtablaMedia[4]=0.7;
	 PtablaMedia[5]=0.6;
	 PtablaMedia[6]=0.5;
	 PtablaMedia[7]=0.3;
	 PtablaMedia[8]=0.2;
	 PtablaMedia[9]=0.1;
     PtablaMedia[10]=0.05;
     PtablaMedia[11]=0.02;
	 
     for (i=0;i<N;i++)
     {
         //Identifico la posición del jugador
         if (jug[i].St > jug[i].Tk && jug[i].St > jug[i].Ps && jug[i].St > jug[i].Sh)                             //Portero
         {
	         //Miro la edad
	         for (j=0;jug[i].Age>int(PtablaEdad[j][0]);j++)
	         {}
             //Miro su media, calculo el bonus y la media final
             bonus=double(jug[i].Min)*PtablaEdad[j][1]*PtablaMedia[jug[i].St-15]; //Bonus
             res=int(1000.0*double(jug[i].St)+double(jug[i].KAb)+bonus); //Media final (en pts de experiencia)
             jug[i].St=int(res/1000);
             jug[i].KAb=max(1,int(res)-jug[i].St*1000);                 
         }
         else if (jug[i].Tk > jug[i].St && jug[i].Tk > jug[i].Ps && jug[i].Tk > jug[i].Sh)                             //Defensa
         {
	         //Miro la edad
	         for (j=0;jug[i].Age>int(tablaEdad[j][0]);j++)
	         {}
             //Miro su media, calculo el bonus y la media final
             bonus=double(jug[i].Min)*tablaEdad[j][1]*tablaMedia[jug[i].Tk-15]; //Bonus
             res=int(1000.0*double(jug[i].Tk)+double(jug[i].TAb)+bonus); //Media final (en pts de experiencia)
             jug[i].Tk=int(res/1000);
             jug[i].TAb=max(1,int(res)-jug[i].Tk*1000);   
			 //Secundaria (pase)
			 bonus=bonus/2.0; 
			 max(1001,res=int(1000.0*double(jug[i].Ps)+double(jug[i].PAb)+bonus)); //Media final (en pts de experiencia)
             jug[i].Ps=int(res/1000);
             jug[i].PAb=max(1,int(res)-jug[i].Ps*1000);               
         }
         else if (jug[i].Ps > jug[i].St && jug[i].Ps > jug[i].Tk && jug[i].Ps > jug[i].Sh)                             //Medio
         {
	         //Miro la edad
	         for (j=0;jug[i].Age>int(tablaEdad[j][0]);j++)
	         {}
             //Miro su media, calculo el bonus y la media final
             bonus=double(jug[i].Min)*tablaEdad[j][1]*tablaMedia[jug[i].Ps-15]; //Bonus
             res=int(1000.0*double(jug[i].Ps)+double(jug[i].PAb)+bonus); //Media final (en pts de experiencia)
             jug[i].Ps=int(res/1000);
             jug[i].PAb=max(1,int(res)-jug[i].Ps*1000);
			 //Secundaria
			 bonus=bonus/2.0;
			 if(jug[i].Tk>jug[i].Sh)         //DM
			 {
			 	max(1001,res=int(1000.0*double(jug[i].Tk)+double(jug[i].TAb)+bonus)); //Media final (en pts de experiencia)
             	jug[i].Tk=int(res/1000);
             	jug[i].TAb=max(1,int(res)-jug[i].Tk*1000);
			 }
			 else           //AM
			 {
             	max(1001,res=int(1000.0*double(jug[i].Sh)+double(jug[i].SAb)+bonus)); //Media final (en pts de experiencia)
             	jug[i].Sh=int(res/1000);
             	jug[i].SAb=max(1,int(res)-jug[i].Sh*1000); 
			 }
         }
         else if (jug[i].Sh > jug[i].St && jug[i].Sh > jug[i].Tk && jug[i].Sh > jug[i].Ps)                            //Delantero
         {
	         //Miro la edad
	         for (j=0;jug[i].Age>int(tablaEdad[j][0]);j++)
	         {}
             //Miro su media, calculo el bonus y la media final
             bonus=double(jug[i].Min)*tablaEdad[j][1]*tablaMedia[jug[i].Sh-15]; //Bonus
             res=int(1000.0*double(jug[i].Sh)+double(jug[i].SAb)+bonus); //Media final (en pts de experiencia)
             jug[i].Sh=int(res/1000);
             jug[i].SAb=max(1,int(res)-jug[i].Sh*1000); 
			 //Secundaria (pase)
			 bonus=bonus/2.0; 
			 res=max(1001,int(1000.0*double(jug[i].Ps)+double(jug[i].PAb)+bonus)); //Media final (en pts de experiencia)
             jug[i].Ps=int(res/1000);
             jug[i].PAb=max(1,int(res)-jug[i].Ps*1000);                
         }
         else if (jug[i].Tk > jug[i].St && jug[i].Tk > jug[i].Sh && jug[i].Tk == jug[i].Ps)                    //Medio y defensa
         {
         	//Miro la edad
	         for (j=0;jug[i].Age>int(tablaEdad[j][0]);j++)
	         {}
	         //Miro su media, calculo el bonus y la media final
             bonus=double(jug[i].Min)*tablaEdad[j][1]*tablaMedia[jug[i].Tk-15]; //Bonus
             res=int(1000.0*double(jug[i].Tk)+double(jug[i].TAb)+bonus); //Media final (en pts de experiencia)
             jug[i].Tk=int(res/1000);
             jug[i].TAb=max(1,int(res)-jug[i].Tk*1000); 
             //Dos habs ppales
             bonus=double(jug[i].Min)*tablaEdad[j][1]*tablaMedia[jug[i].Ps-15]; //Bonus
             res=int(1000.0*double(jug[i].Ps)+double(jug[i].PAb)+bonus); //Media final (en pts de experiencia)
             jug[i].Ps=int(res/1000);
             jug[i].PAb=max(1,int(res)-jug[i].Ps*1000); 
		 }
		 else if (jug[i].Sh > jug[i].St && jug[i].Sh > jug[i].Tk && jug[i].Sh == jug[i].Ps)                    //Medio y delantero
         {
         	//Miro la edad
	         for (j=0;jug[i].Age>int(tablaEdad[j][0]);j++)
	         {}
	         //Miro su media, calculo el bonus y la media final
             bonus=double(jug[i].Min)*tablaEdad[j][1]*tablaMedia[jug[i].Sh-15]; //Bonus
             res=int(1000.0*double(jug[i].Sh)+double(jug[i].SAb)+bonus); //Media final (en pts de experiencia)
             jug[i].Sh=int(res/1000);
             jug[i].SAb=max(1,int(res)-jug[i].Sh*1000); 
             //Dos habs ppales
             bonus=double(jug[i].Min)*tablaEdad[j][1]*tablaMedia[jug[i].Ps-15]; //Bonus
             res=int(1000.0*double(jug[i].Ps)+double(jug[i].PAb)+bonus); //Media final (en pts de experiencia)
             jug[i].Ps=int(res/1000);
             jug[i].PAb=max(1,int(res)-jug[i].Ps*1000); 
		 }
     }
}

//Procedimiento para añadir un punto a la media ppal
void Subirmediappal (jugador jug[TAM], int N)
{
     int i, j, k; //Las filas son la edad máxima del intervalo y las columnas, el tope de minutos
          
     for (i=0;i<N;i++)
     {
         //Identifico la posición del jugador
         if (jug[i].St > jug[i].Tk && jug[i].St > jug[i].Ps && jug[i].St > jug[i].Sh)              //Portero
         {
             jug[i].St++;
         }
         else if (jug[i].Tk > jug[i].St && jug[i].Tk > jug[i].Ps && jug[i].Tk > jug[i].Sh) // DEFENSA
         {
             jug[i].Tk++;
         }
         else if (jug[i].Ps > jug[i].St && jug[i].Ps > jug[i].Tk && jug[i].Ps > jug[i].Sh) // MEDIO
         {
             jug[i].Ps++;
         }
         else                                                                              //Delantero
         {
             jug[i].Sh++;
         }
     }
}

void Reiniciar (jugador jug[TAM], int N)
{
     int fil = 8, col = 6;
     int i;
     for (i=0;i<N;i++)
     {
        jug[i].Gam = 0;
        jug[i].Sub = 100;
        jug[i].Min = 0;
        jug[i].Mom = 0;
        jug[i].Sav = 0;
        jug[i].Con = 0;
        jug[i].Ktk = 0;
        jug[i].Kps = 0;
        jug[i].Sht = 0;
        jug[i].Gls = 0;
        jug[i].Ass = 0;
        jug[i].DP = 0;
        jug[i].Inj = 0;
        jug[i].Sus = 0;
        if(jug[i].St > jug[i].Tk)//Portero
        {
        	jug[i].Fit = 100;
		}
        else
        {
        	jug[i].Fit = 90;
		}
     }
}

void Envejecer (jugador jug[TAM], int N)
{
     int fil = 8, col = 6;
     int i;
     for (i=0;i<N;i++)
     {
         jug[i].Age++;
     }
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

//Rerranqueo T5, ehe ehehe
void Rerankeo(jugador jug[TAM], int N)
{
     //Variables locales
     int i;
     for (i=0;i<N;i++)
     {
         if (jug[i].Age > 24)
         {
              //Portero
              if (jug[i].St > jug[i].Tk)
              {
                   if (jug[i].St <= 19) //Añado 1 nivel
                   {
                        jug[i].St = jug[i].St + 1;
                   }
                   else if (jug[i].St == 20) //Añado 900
                   {
                        if (jug[i].KAb + 900 >= 1000)
                        {
                             jug[i].St = jug[i].St + 1;
                             jug[i].KAb = jug[i].KAb - 99;
                        }
                        else
                        {
                            jug[i].KAb = jug[i].KAb + 900;
                        }
                   }
                   else if (jug[i].St == 21) //Añado 600
                   {
                        if (jug[i].KAb + 600 >= 1000)
                        {
                             jug[i].St = jug[i].St + 1;
                             jug[i].KAb = jug[i].KAb - 399;
                        }
                        else
                        {
                            jug[i].KAb = jug[i].KAb + 600;
                        }
                   }
                   else if (jug[i].St == 22) //Añado 300
                   {
                        if (jug[i].KAb + 300 >= 1000)
                        {
                             jug[i].St = jug[i].St + 1;
                             jug[i].KAb = jug[i].KAb - 699;
                        }
                        else
                        {
                            jug[i].KAb = jug[i].KAb + 300;
                        }
                   }
                   else if (jug[i].St == 23) //Añado 100
                   {
                        if (jug[i].KAb + 100 >= 1000)
                        {
                             jug[i].St = jug[i].St + 1;
                             jug[i].KAb = jug[i].KAb - 899;
                        }
                        else
                        {
                            jug[i].KAb = jug[i].KAb + 100;
                        }
                   }
              }
              //Defensa
              else if (jug[i].Tk > jug[i].Ps && jug[i].Tk > jug[i].Sh)
              {
                   if (jug[i].Tk <= 19) //Añado 1 nivel
                   {
                        jug[i].Tk = jug[i].Tk + 1;
                   }
                   else if (jug[i].Tk == 20) //Añado 900
                   {
                        if (jug[i].TAb + 900 >= 1000)
                        {
                             jug[i].Tk = jug[i].Tk + 1;
                             jug[i].TAb = jug[i].TAb - 99;
                        }
                        else
                        {
                            jug[i].TAb = jug[i].TAb + 900;
                        }
                   }
                   else if (jug[i].Tk == 21) //Añado 600
                   {
                        if (jug[i].TAb + 600 >= 1000)
                        {
                             jug[i].Tk = jug[i].Tk + 1;
                             jug[i].TAb = jug[i].TAb - 399;
                        }
                        else
                        {
                            jug[i].TAb = jug[i].TAb + 600;
                        }
                   }
                   else if (jug[i].Tk == 22) //Añado 300
                   {
                        if (jug[i].TAb + 300 >= 1000)
                        {
                             jug[i].Tk = jug[i].Tk + 1;
                             jug[i].TAb = jug[i].TAb - 699;
                        }
                        else
                        {
                            jug[i].TAb = jug[i].TAb + 300;
                        }
                   }
                   else if (jug[i].Tk == 23) //Añado 100
                   {
                        if (jug[i].TAb + 100 >= 1000)
                        {
                             jug[i].Tk = jug[i].Tk + 1;
                             jug[i].TAb = jug[i].TAb - 899;
                        }
                        else
                        {
                            jug[i].TAb = jug[i].TAb + 100;
                        }
                   }
              }
              //Mediocampista
              else if (jug[i].Ps > jug[i].Sh)
              {
                   if (jug[i].Ps <= 19) //Añado 1 nivel
                   {
                        jug[i].Ps = jug[i].Ps + 1;
                   }
                   else if (jug[i].Ps == 20) //Añado 900
                   {
                        if (jug[i].PAb + 900 >= 1000)
                        {
                             jug[i].Ps = jug[i].Ps + 1;
                             jug[i].PAb = jug[i].PAb - 99;
                        }
                        else
                        {
                            jug[i].PAb = jug[i].PAb + 900;
                        }
                   }
                   else if (jug[i].Ps == 21) //Añado 600
                   {
                        if (jug[i].PAb + 600 >= 1000)
                        {
                             jug[i].Ps = jug[i].Ps + 1;
                             jug[i].PAb = jug[i].PAb - 399;
                        }
                        else
                        {
                            jug[i].PAb = jug[i].PAb + 600;
                        }
                   }
                   else if (jug[i].Ps == 22) //Añado 300
                   {
                        if (jug[i].PAb + 300 >= 1000)
                        {
                             jug[i].Ps = jug[i].Ps + 1;
                             jug[i].PAb = jug[i].PAb - 699;
                        }
                        else
                        {
                            jug[i].PAb = jug[i].PAb + 300;
                        }
                   }
                   else if (jug[i].Ps == 23) //Añado 100
                   {
                        if (jug[i].PAb + 100 >= 1000)
                        {
                             jug[i].Ps = jug[i].Ps + 1;
                             jug[i].PAb = jug[i].PAb - 899;
                        }
                        else
                        {
                            jug[i].PAb = jug[i].PAb + 100;
                        }
                   }
              }
              //Delantero
              else
              {
                   if (jug[i].Sh <= 19) //Añado 1 nivel
                   {
                        jug[i].Sh = jug[i].Sh + 1;
                   }
                   else if (jug[i].Sh == 20) //Añado 900
                   {
                        if (jug[i].SAb + 900 >= 1000)
                        {
                             jug[i].Sh = jug[i].Sh + 1;
                             jug[i].SAb = jug[i].SAb - 99;
                        }
                        else
                        {
                            jug[i].SAb = jug[i].SAb + 900;
                        }
                   }
                   else if (jug[i].Sh == 21) //Añado 600
                   {
                        if (jug[i].SAb + 600 >= 1000)
                        {
                             jug[i].Sh = jug[i].Sh + 1;
                             jug[i].SAb = jug[i].SAb - 399;
                        }
                        else
                        {
                            jug[i].SAb = jug[i].SAb + 600;
                        }
                   }
                   else if (jug[i].Sh == 22) //Añado 300
                   {
                        if (jug[i].SAb + 300 >= 1000)
                        {
                             jug[i].Sh = jug[i].Sh + 1;
                             jug[i].SAb = jug[i].SAb - 699;
                        }
                        else
                        {
                            jug[i].SAb = jug[i].SAb + 300;
                        }
                   }
                   else if (jug[i].Sh == 23) //Añado 100
                   {
                        if (jug[i].SAb + 100 >= 1000)
                        {
                             jug[i].Sh = jug[i].Sh + 1;
                             jug[i].SAb = jug[i].SAb - 899;
                        }
                        else
                        {
                            jug[i].SAb = jug[i].SAb + 100;
                        }
                   }
              }
         }
         
     }
}

//Reajuste T14, ehe ehehe
void ReajT14(jugador jug[TAM], int N)
{
	//Punteros a las variables
	int* pri_hab; int* pri_exp;
	int* sec_hab; int* sec_exp;
	int* ter_hab; int* ter_exp;
	//10 filas, 1 por cada rango de edad. 4 columnas, la primera indica el maximo de edad del rango y el resto, el bonus
  	int tablajug[10][4] = {
	  {19,-100,-50,0},
	  {21,-200,-150,0},
	  {26,-350,-250,0},
	  {29,-350,-250,0},
	  {30,-500,-375,0},
	  {31,-500,-375,0},
	  {32,-500,-375,0},
	  {33,-1000,-650,0},
	  {34,-1000,-650,0},
	  {80,-1300,-850,0},
	  };
  	int tablaGK[10][4] = {
	  {19,-100,0,0},
	  {21,-200,0,0},
	  {26,-350,0,0},
	  {29,-350,0,0},
	  {30,-500,0,0},
	  {31,-500,0,0},
	  {32,-500,0,0},
	  {33,-1000,0,0},
	  {34,-1000,0,0},
	  {80,-1300,0,0},
	  };
	  
	for(int i=0;i<N;i++)
	{
		 int j;
		 int expf;
		 bool isGK = false;
         //Identifico la posición del jugador
         if (jug[i].St > jug[i].Tk && jug[i].St > jug[i].Ps && jug[i].St > jug[i].Sh)                             //Portero
         {
		 	for(j=0;jug[i].Age > tablaGK[j][0];j++){}
		 	pri_hab = &jug[i].St; pri_exp = &jug[i].KAb;
		 	sec_hab = &jug[i].Tk; sec_exp = &jug[i].TAb;
		 	ter_hab = &jug[i].Ps; ter_exp = &jug[i].PAb;
		 	isGK = true;
         }
         else if (jug[i].Tk >= jug[i].St && jug[i].Tk > jug[i].Ps && jug[i].Tk > jug[i].Sh)                             //Defensa
         {
			for(j=0;jug[i].Age > tablajug[j][0];j++){}
		 	pri_hab = &jug[i].Tk; pri_exp = &jug[i].TAb;
		 	sec_hab = &jug[i].Ps; sec_exp = &jug[i].PAb;
		 	ter_hab = &jug[i].Sh; ter_exp = &jug[i].SAb;
         }
         else if (jug[i].Ps >= jug[i].St && jug[i].Ps >= jug[i].Tk && jug[i].Ps > jug[i].Sh && jug[i].Tk > jug[i].St)    //Medio defensivo
         {
			for(j=0;jug[i].Age > tablajug[j][0];j++){}
		 	pri_hab = &jug[i].Ps; pri_exp = &jug[i].PAb;
		 	sec_hab = &jug[i].Tk; sec_exp = &jug[i].TAb;
		 	ter_hab = &jug[i].Sh; ter_exp = &jug[i].SAb;
         }
         else if (jug[i].Ps >= jug[i].St && jug[i].Ps >= jug[i].Tk && jug[i].Ps > jug[i].Sh && jug[i].St >= jug[i].Tk)    //Medio ofensivo
         {
			for(j=0;jug[i].Age > tablajug[j][0];j++){}
		 	pri_hab = &jug[i].Ps; pri_exp = &jug[i].PAb;
		 	sec_hab = &jug[i].Sh; sec_exp = &jug[i].SAb;
		 	ter_hab = &jug[i].Tk; ter_exp = &jug[i].TAb;
         }
         else if (jug[i].Sh >= jug[i].St && jug[i].Sh >= jug[i].Tk && jug[i].Sh >= jug[i].Ps)                            //Delantero
         {
         	for(j=0;jug[i].Age > tablajug[j][0];j++){}
		 	pri_hab = &jug[i].Sh; pri_exp = &jug[i].SAb;
		 	sec_hab = &jug[i].Ps; sec_exp = &jug[i].PAb;
		 	ter_hab = &jug[i].Tk; ter_exp = &jug[i].TAb;
		 }
		 expf = *pri_hab*1000 + *pri_exp + isGK*tablaGK[j][1]+(1-isGK)*tablajug[j][1];
		 *pri_hab = int(expf/1000);
		 *pri_exp = max(expf % 1000,1);
		 
		 expf = *sec_hab*1000 + *sec_exp + isGK*tablaGK[j][2]+(1-isGK)*tablajug[j][2];
		 *sec_hab = int(expf/1000);
		 *sec_exp = max(expf % 1000,1);
		 
		 expf = *ter_hab*1000 + *ter_exp + isGK*tablaGK[j][3]+(1-isGK)*tablajug[j][3];
		 *ter_hab = int(expf/1000);
		 *ter_exp = max(expf % 1000,1);
	}
}

//Función principal
int main ()
{
    //Declaración de variables
    int N = 0, op = 0, M = 0, i;
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
        do
        {
             LeerIndice(indice, plantillas, M, fichero);
             //LeerFichero (jug, fichero, N, linea1, linea2); Para copiar
             fichero.close ();
             cout << "Que desea hacer?" << endl;
             cout << "1: Reiniciar todas las estadisticas" << endl;
             cout << "2: Anadir un ano de edad" << endl;
             cout << "3: Ordenar" << endl;
             cout << "4: Anadir bonus de minutos" << endl;
             cout << "5: Subir 1 punto la media principal" << endl;
             cout << "6: Rerankeo -.-" << endl;
             cout << "7: Reajuste T14" << endl;
             cout << "0: Salir" << endl;
             cin >> op;
             cout << endl;
             if (op == 1)
             {
                  for(i=0;i<M;i++)
                  {
                      N = 0;
                      LeerFichero (jug, plantillas[i], N, linea1, linea2);
                      Reiniciar (jug, N);
                      GuardarFichero(jug, N, plantillas[i], linea1, linea2);
                      cout << plantillas[i] << " actualizado" << endl;
                  }
             }
             else if (op==2)
             {
                  for(i=0;i<M;i++)
                  {
                      N = 0;
                      LeerFichero (jug, plantillas[i], N, linea1, linea2);
                      Envejecer (jug, N);
                      GuardarFichero(jug, N, plantillas[i], linea1, linea2);
                      cout << plantillas[i] << " actualizado" << endl;
                  }
             }
             else if (op==3)
             {
                  for(i=0;i<M;i++)
                  {
                      N = 0;
                      LeerFichero (jug, plantillas[i], N, linea1, linea2);
                      Ordenar (jug, N);
                      GuardarFichero(jug, N, plantillas[i], linea1, linea2);
                      cout << plantillas[i] << " actualizado" << endl;
                  }
             }
             else if (op==4)
             {
                  for(i=0;i<M;i++)
                  {
                      N = 0;
                      LeerFichero (jug, plantillas[i], N, linea1, linea2);
                      Actualizar (jug, N, op);
                      GuardarFichero(jug, N, plantillas[i], linea1, linea2);
                      cout << plantillas[i] << " actualizado" << endl;
                  }
             }
             else if (op==5)
             {
                  for(i=0;i<M;i++)
                  {
                      N = 0;
                      LeerFichero (jug, plantillas[i], N, linea1, linea2);
                      Subirmediappal (jug, N);
                      GuardarFichero(jug, N, plantillas[i], linea1, linea2);
                      cout << plantillas[i] << " actualizado" << endl;
                  }
             }
                 else if (op==6)
             {
                  for(i=0;i<M;i++)
                  {
                      N = 0;
                      LeerFichero (jug, plantillas[i], N, linea1, linea2);
                      Rerankeo (jug, N);
                      GuardarFichero(jug, N, plantillas[i], linea1, linea2);
                      cout << plantillas[i] << " actualizado" << endl;
                  }
             }
                 else if (op==7)
             {
                  for(i=0;i<M;i++)
                  {
                      N = 0;
                      LeerFichero (jug, plantillas[i], N, linea1, linea2);
                      ReajT14 (jug, N);
                      GuardarFichero(jug, N, plantillas[i], linea1, linea2);
                      cout << plantillas[i] << " actualizado" << endl;
                  }
             }
             cout << endl;
        }while(op != 0);
    }
    system("pause");
    return 0;
}
