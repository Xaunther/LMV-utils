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
//Procedimientos de ordenar
void OrdenarAge (jugador [TAM], int );
void OrdenarSt (jugador [TAM], int );
void OrdenarTk (jugador [TAM], int );
void OrdenarPs (jugador [TAM], int );
void OrdenarSh (jugador [TAM], int );
void OrdenarGam (jugador [TAM], int );
void OrdenarSub (jugador [TAM], int );
void OrdenarMin (jugador [TAM], int );
void OrdenarMom (jugador [TAM], int );
void OrdenarSav (jugador [TAM], int );
void OrdenarCon (jugador [TAM], int );
void OrdenarKtk (jugador [TAM], int );
void OrdenarKps (jugador [TAM], int );
void OrdenarSht (jugador [TAM], int );
void OrdenarGls (jugador [TAM], int );
void OrdenarAss (jugador [TAM], int );
void OrdenarDP (jugador [TAM], int );
void OrdenarConRate (jugador [TAM], int );
void OrdenarKtkRate (jugador [TAM], int );
void OrdenarAssRate (jugador [TAM], int );
void OrdenarGlsRate (jugador [TAM], int );

void GuardarFichero(jugador [TAM], int , string, string &, string &);
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

//Procedimientos para ordenar la lista de jugadores
//Separador :D
void OrdenarAge(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Age>jug[j].Age)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarSt(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].St>jug[j].St)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarTk(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Tk>jug[j].Tk)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarPs(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Ps>jug[j].Ps)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarSh(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Sh>jug[j].Sh)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarGam(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Gam>jug[j].Gam)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarSub(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Sub>jug[j].Sub)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarMin(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Min>jug[j].Min)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarMom(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Mom>jug[j].Mom)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarSav(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Sav>jug[j].Sav)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarCon(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Con>jug[j].Con)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarKtk(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Ktk>jug[j].Ktk)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarKps(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Kps>jug[j].Kps)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarSht(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Sht>jug[j].Sht)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarGls(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Gls>jug[j].Gls)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarAss(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].Ass>jug[j].Ass)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarDP(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
        for (j=0;j<i;j++)
        {    
			if (jug[i].DP>jug[j].DP)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarConRate(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    double Ratei;
    double Ratej;
    int minGames = 12;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
    	if (jug[i].Sav == 0)
    	{
    		Ratei=10;
		}
		else
		{
			Ratei=double(jug[i].Con)/double(jug[i].Sav);
		}
        for (j=0;j<i;j++)
        {    
	        if (jug[j].Sav == 0)
	    	{
	    		Ratej=10;
			}
			else
			{
				Ratej=double(jug[j].Con)/double(jug[j].Sav);
			}
			if (Ratei<Ratej && jug[i].Gam>=minGames)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarKtkRate(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    double Ratei;
    double Ratej;
    int minGames = 12;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
    	if (jug[i].Gam == 0)
    	{
    		Ratei=-1;
		}
		else
		{
			Ratei=double(jug[i].Ktk)/double(jug[i].Gam);
		}
        for (j=0;j<i;j++)
        {    
	        if (jug[j].Gam == 0)
	    	{
	    		Ratej=-1;
			}
			else
			{
				Ratej=double(jug[j].Ktk)/double(jug[j].Gam);
			}
			if (Ratei>Ratej && jug[i].Gam>=minGames)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarAssRate(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    double Ratei;
    double Ratej;
    int minGames = 12;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
    	if (jug[i].Gam == 0)
    	{
    		Ratei=-1;
		}
		else
		{
			Ratei=double(jug[i].Ass)/double(jug[i].Gam);
		}
        for (j=0;j<i;j++)
        {    
	        if (jug[j].Gam == 0)
	    	{
	    		Ratej=-1;
			}
			else
			{
				Ratej=double(jug[j].Ass)/double(jug[j].Gam);
			}
			if (Ratei>Ratej && jug[i].Gam>=minGames)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
        }
    }
}

//Separador :D
void OrdenarGlsRate(jugador jug[TAM], int N)
{
    //Variables locales
    int i, j;
    double Ratei;
    double Ratej;
    int minGames = 12;
    
    //Ordenar
    for (i=0;i<N;i++)
    {
    	if (jug[i].Gam == 0)
    	{
    		Ratei=-1;
		}
		else
		{
			Ratei=double(jug[i].Gls)/double(jug[i].Gam);
		}
        for (j=0;j<i;j++)
        {    
	        if (jug[j].Gam == 0)
	    	{
	    		Ratej=-1;
			}
			else
			{
				Ratej=double(jug[j].Gls)/double(jug[j].Gam);
			}
			if (Ratei>Ratej && jug[i].Gam>=minGames)
            {
                //Intercambio
                jug[N] = jug[j];
                jug[j] = jug[i];
                jug[i] = jug[N];
            }   
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
    	LeerIndice(indice, plantillas, M, fichero);
        //LeerFichero (jug, fichero, N, linea1, linea2); Para copiar
        fichero.close ();
        do
        {
             
             cout << "Que desea hacer?" << endl;
             cout << "1: Ordenar por todo (genera multiples archivos)" << endl;
             cout << "2: Ordenar una estadistica" << endl;
             cout << "0: Salir" << endl;
             cin >> op;
             cout << endl;
             if (op == 1)
             {
                  for(i=0;i<M;i++) //Leo todo
                  {
                      LeerFichero (jug, plantillas[i], N, linea1, linea2);
                  }
                      OrdenarAge (jug, N);
                      GuardarFichero(jug, N, "Age.txt", linea1, linea2);
                      OrdenarSt (jug, N);
                      GuardarFichero(jug, N, "St.txt", linea1, linea2);
                      OrdenarTk (jug, N);
                      GuardarFichero(jug, N, "Tk.txt", linea1, linea2);
                      OrdenarPs (jug, N);
                      GuardarFichero(jug, N, "Ps.txt", linea1, linea2);
                      OrdenarSh (jug, N);
                      GuardarFichero(jug, N, "Sh.txt", linea1, linea2);
                      OrdenarGam (jug, N);
                      GuardarFichero(jug, N, "Gam.txt", linea1, linea2);
                      OrdenarSub (jug, N);
                      GuardarFichero(jug, N, "Sub.txt", linea1, linea2);
                      OrdenarMin (jug, N);
                      GuardarFichero(jug, N, "Min.txt", linea1, linea2);
                      OrdenarMom (jug, N);
                      GuardarFichero(jug, N, "Mom.txt", linea1, linea2);
                      OrdenarSav (jug, N);
                      GuardarFichero(jug, N, "Sav.txt", linea1, linea2);
                      OrdenarCon (jug, N);
                      GuardarFichero(jug, N, "Com.txt", linea1, linea2);
                      OrdenarKtk (jug, N);
                      GuardarFichero(jug, N, "Ktk.txt", linea1, linea2);
                      OrdenarKps (jug, N);
                      GuardarFichero(jug, N, "Kps.txt", linea1, linea2);
                      OrdenarSht (jug, N);
                      GuardarFichero(jug, N, "Sht.txt", linea1, linea2);
                      OrdenarGls (jug, N);
                      GuardarFichero(jug, N, "Gls.txt", linea1, linea2);
                      OrdenarAss (jug, N);
                      GuardarFichero(jug, N, "Ass.txt", linea1, linea2);
                      OrdenarDP (jug, N);
                      GuardarFichero(jug, N, "DP.txt", linea1, linea2);
                      OrdenarConRate (jug, N);
                      GuardarFichero(jug, N, "ConRate.txt", linea1, linea2);
                      OrdenarKtkRate (jug, N);
                      GuardarFichero(jug, N, "KtkRate.txt", linea1, linea2);
                      OrdenarAssRate (jug, N);
                      GuardarFichero(jug, N, "AssRate.txt", linea1, linea2);
                      OrdenarGlsRate (jug, N);
                      GuardarFichero(jug, N, "GlsRate.txt", linea1, linea2);
             }
             else if (op==2)
             {
                for(i=0;i<M;i++) //Leo todo
                {
                    LeerFichero (jug, plantillas[i], N, linea1, linea2);
                }
             	cout <<"Elige cual ordenar:" << endl;
             	cout <<"1. Age" << endl;
             	cout <<"2. St" << endl;
             	cout <<"3. Tk" << endl;
             	cout <<"4. Ps" << endl;
             	cout <<"5. Sh" << endl;
             	cout <<"6. Gam" << endl;
             	cout <<"7. Sub" << endl;
             	cout <<"8. Min" << endl;
             	cout <<"9. Mom" << endl;
             	cout <<"10. Sav" << endl;
             	cout <<"11. Con" << endl;
             	cout <<"12. Ktk" << endl;
             	cout <<"13. Kps" << endl;
             	cout <<"14. Sht" << endl;
             	cout <<"15. Gls" << endl;
             	cout <<"16. Ass" << endl;
             	cout <<"17. DP" << endl;
             	cout << "18. Ratio Sav/Con" << endl;
             	cout << "19. Ratio Ktk/Gam" << endl;
             	cout << "20. Ratio Ass/Gam" << endl;
             	cout << "21. Ratio Gls/Gam" << endl;
             	cout << "22. Todos los ratios" << endl;
             	cin >> op;
             	cout << endl << endl;
             	
             	if(op==1)
             	{
             		OrdenarAge (jug, N);
                    GuardarFichero(jug, N, "Age.txt", linea1, linea2);
				}
				if(op==2)
             	{
             		OrdenarSt (jug, N);
                    GuardarFichero(jug, N, "St.txt", linea1, linea2);
				}
				if(op==3)
             	{
             		OrdenarTk (jug, N);
                    GuardarFichero(jug, N, "Tk.txt", linea1, linea2);
				}
				if(op==4)
             	{
             		OrdenarPs (jug, N);
                    GuardarFichero(jug, N, "Ps.txt", linea1, linea2);
				}
				if(op==5)
             	{
             		OrdenarSh (jug, N);
                    GuardarFichero(jug, N, "Sh.txt", linea1, linea2);
				}
				if(op==6)
             	{
             		OrdenarGam (jug, N);
                    GuardarFichero(jug, N, "Gam.txt", linea1, linea2);
				}
				if(op==7)
             	{
             		OrdenarSub (jug, N);
                    GuardarFichero(jug, N, "Sub.txt", linea1, linea2);
				}
				if(op==8)
             	{
             		OrdenarMin (jug, N);
                    GuardarFichero(jug, N, "Min.txt", linea1, linea2);
				}
				if(op==9)
             	{
             		OrdenarMom (jug, N);
                    GuardarFichero(jug, N, "Mom.txt", linea1, linea2);
				}
				if(op==10)
             	{
             		OrdenarSav (jug, N);
                    GuardarFichero(jug, N, "Sav.txt", linea1, linea2);
				}
				if(op==11)
             	{
             		OrdenarCon (jug, N);
                    GuardarFichero(jug, N, "Con.txt", linea1, linea2);
				}
				if(op==12)
             	{
             		OrdenarKtk (jug, N);
                    GuardarFichero(jug, N, "Ktk.txt", linea1, linea2);
				}
				if(op==13)
             	{
             		OrdenarKps (jug, N);
                    GuardarFichero(jug, N, "Kps.txt", linea1, linea2);
				}
				if(op==14)
             	{
             		OrdenarSht (jug, N);
                    GuardarFichero(jug, N, "Sht.txt", linea1, linea2);
				}
				if(op==15)
             	{
             		OrdenarGls (jug, N);
                    GuardarFichero(jug, N, "Gls.txt", linea1, linea2);
				}
				if(op==16)
             	{
             		OrdenarAss (jug, N);
                    GuardarFichero(jug, N, "Ass.txt", linea1, linea2);
				}
				if(op==17)
             	{
             		OrdenarDP (jug, N);
                    GuardarFichero(jug, N, "DP.txt", linea1, linea2);
				}
				if(op==18)
             	{
             		OrdenarConRate (jug, N);
                    GuardarFichero(jug, N, "ConRate.txt", linea1, linea2);
				}
				if(op==19)
             	{
             		OrdenarKtkRate (jug, N);
                    GuardarFichero(jug, N, "KtkRate.txt", linea1, linea2);
				}
				if(op==20)
             	{
             		OrdenarAssRate (jug, N);
                    GuardarFichero(jug, N, "AssRate.txt", linea1, linea2);
				}
				if(op==21)
             	{
             		OrdenarGlsRate (jug, N);
                    GuardarFichero(jug, N, "GlsRate.txt", linea1, linea2);
				}
				if(op==22)
             	{
             		OrdenarConRate (jug, N);
                    GuardarFichero(jug, N, "ConRate.txt", linea1, linea2);
             		OrdenarKtkRate (jug, N);
                    GuardarFichero(jug, N, "KtkRate.txt", linea1, linea2);
             		OrdenarAssRate (jug, N);
                    GuardarFichero(jug, N, "AssRate.txt", linea1, linea2);
             		OrdenarGlsRate (jug, N);
                    GuardarFichero(jug, N, "GlsRate.txt", linea1, linea2);
				}
				
             }
             cout << endl;
        }while(op != 0);
    }
    cout << "La estadistica Con se guarda como Com (busca en google: con.txt -.-)" << endl;
    system("pause");
    return 0;
}
