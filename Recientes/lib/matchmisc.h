#include <string>
#include "lib/constantes.h"
#include "lib/stattable.h"
using namespace std;

//Some misc functions needed
void Nombrar(string &, int);
void LeerStatsDir(string [TAMpartidos], int &);
void LeerTablesDir(string [TAMtablas], int &);
void LeerPartido(string, stattable*, stattable*, stattable*, stattable*);
void ReduceSuspensions();
void ReduceInjuries();
void AddStamina();
string GetGKSht(string);
