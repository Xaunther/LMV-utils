#Variables
GCC = g++
Scripts = Modificar_plantillas.out Rankings.out Salarios.out Suma_Fit.out


#Custom options
.PHONY: all clean

all: $(Scripts) #Compila todos los códigos	

clean: #Borra compilaciones
	rm *.o *.so *.exe *.out

Modificar_plantillas.out:
	$(GCC) Modificar_plantillas.cpp -o Modificar_plantillas.o

Rankings.out:
	$(GCC) Rankings.cpp -o Rankings.out

Salarios.out:
	$(GCC) Salarios.cpp -o Salarios.out

Suma_Fit.out:
	$(GCC) Suma_Fit.cpp -o Suma_Fit.out
