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
#include <math.h>
using namespace std;

//Función principal
int main ()
{
    //Declaración de variables
    double valor = 0, presup = 0, total = 0, impuestos = 0, r, base;
    string op = "Y";
    do
    {
         base = 0;
         r = 0.3;
         cout << "Valor del jugador (mira en la tabla): ";
         cin >> valor;
         cout << "Presupuesto del equipo rival: ";
         cin >> presup;
         cout << endl;
         //Este es el if para distinguir entre presupuestos mayores y menores de 100M de PESETAS (dale tiempo)
         if (presup>100)
         {
             r=0.1;
             base=30;
             presup=presup-100;
         }
         total = base+r*presup + 100;
         total = total*valor/100;
         total = double(ceil(10*total))/10;
         impuestos = total*0.1;
         impuestos = double(ceil(10*impuestos))/10;
         cout << "La clausula es de " << total << "M Euros con " << impuestos << "M Euros de impuestos" << endl << endl;
         cout << "Quiere calcular otra? (y/n): ";
         cin >> op;
         cout << endl;
    }while (op == "Y" || op == "y");
    system("pause");
    return 0;
}
