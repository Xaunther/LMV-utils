## Compilación

**En Linux**: Es posible que se deban borrar las líneas con system("pause"); ya que es específico de Windows
**En Windows**: Si consigues usar un makefile, adelante. Si no, con dev-c++ es bastante sencillo (debes crear un proyecto para añadir las librerías de la carpeta lib y el propio dev-c++ crea un makefile para compilar como debe).

## Descripción

Cada uno de los scripts tiene un .cpp en este directorio. Todos ellos dependen de las librerías contenidas en lib

**Actualizador-Nuevo.cpp**: Es un actualizador como el que viene por defecto en ESMS; pero además crea tablas de goleadores, asistentes, goles encajados y tacklers según la competición escogida. De esta manera se pueden llevar tablas estadísticas para cada competición.
			      
**Combinar-tablas.cpp**: Requiere del archivo tables.dir, que contiene las direcciones de los directorios de diferentes carpetas de simulación. Eliges la competición correspondiente y combina las tablas de estadísticas. MUY Útil para fusionar estadísticas tras una fase de grupos. Ejemplo:
			 -. Posees la carpeta Champions, que a su vez contiene carpetas para cada grupo (Grupo A, Grupo B).
			 -. Creas tables.dir, y escribes (en líneas distintas) Grupo A/   ,   Grupo B/.
			 -. Ejecutas el script en la carpeta Champions, seleccionando la competición correspondiente.

**GKs-suplentes.cpp**: Script que funciona en una carpeta de simulación y detecta si algún equipo está usando al portero titular cuando el suplente está disponible (Usado para competiciones donde el portero suplente sea obligatorio)

**lib**: Carpeta donde se contienen las librerías con funciones, clases, etc.