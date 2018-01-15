#Este makefile está pensado para ser usado en Linux.
#En Windows recomiendo usar Dev-C++ o algún otro software para programar en C++

#Variables
GCC = g++
Scripts = Actualizador-Nuevo.out Combinar-tablas.out GKs-suplentes.out


#Custom options
.PHONY: all clean

all: $(Scripts) #Compila todos los códigos	

clean: #Borra compilaciones
	rm -r *.o *.so *.exe *.out

#Dependencias de los ejecutables
Actualizador-Nuevo.out: Actualizador-Nuevo.cpp lib/stattable.o lib/equipo.o lib/matchmisc.o lib/constantes.h
	$(GCC) Actualizador-Nuevo.cpp -o Actualizador-Nuevo.out

Combinar-tablas.out: Combinar-tablas.cpp lib/matchmisc.o lib/stattable.o lib/constantes.h
	$(GCC) Combinar-tablas.cpp -o Combinar-tablas.out

GKs-suplentes.out: GKs-suplentes.cpp lib/equipo.o lib/matchmisc.o
	$(GCC) GKs-suplentes.cpp -o GKs-suplentes.out

#Dependencias de las librerías
#Librerías compuestas de otras librerías compuestas
lib/equipo.o: lib/equipo.cpp lib/equipo.h lib/jugador.o lib/textmisc.o lib/constantes.h
	$(GCC) -c lib/equipo.cpp -o lib/equipo.o

lib/matchmisc.o: lib/matchmisc.cpp lib/matchmisc.h lib/stattable.o lib/equipo.o lib/textmisc.o lib/constantes.h
	$(GCC) -c lib/matchmisc.cpp -o lib/matchmisc.o

#Librerías compuestas de librerías básicas
lib/jugador.o: lib/jugador.cpp lib/jugador.h lib/textmisc.o
	$(GCC) -c lib/jugador.cpp -o lib/jugador.o

lib/stattable.o: lib/stattable.cpp lib/stattable.h lib/tablemember.o lib/constantes.h
	$(GCC) -c lib/stattable.cpp -o lib/stattable.o

#Librerías básicas
lib/tablemember.o: lib/tablemember.cpp lib/tablemember.h
	$(GCC) -c lib/tablemember.cpp -o lib/tablemember.o

lib/textmisc.o: lib/textmisc.cpp lib/textmisc.h
	$(GCC) -c lib/textmisc.cpp -o lib/textmidc.o
