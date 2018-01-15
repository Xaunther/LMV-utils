#Este makefile está pensado para ser usado en Linux.
#En Windows recomiendo usar Dev-C++ o algún otro software para programar en C++

#Variables
GCC = g++
Scripts = Modificar_plantillas.out Rankings.out Salarios.out Suma_Fit.out


#Custom options
.PHONY: all clean

all: $(Scripts) #Compila todos los códigos	

clean: #Borra compilaciones
	rm *.o *.so *.exe *.out

Modificar_plantillas.out: Modificar_plantillas.cpp
	$(GCC) Modificar_plantillas.cpp -o Modificar_plantillas.out

Rankings.out: Rankings.cpp
	$(GCC) Rankings.cpp -o Rankings.out

Salarios.out: Salarios.cpp
	$(GCC) Salarios.cpp -o Salarios.out

Suma_Fit.out: Suma_Fit.cpp
	$(GCC) Suma_Fit.cpp -o Suma_Fit.out
