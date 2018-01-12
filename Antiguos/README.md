## Compilación

**En Linux**: Es posible que se deban borrar las líneas con system("pause"); ya que es específico de Windows
**En Windows**: Si consigues usar un makefile, adelante. Si no, con dev-c++ es bastante sencillo.

## Descripción

Cada uno de los .cpp compila en su propio script, cada uno de ellos realiza diferentes tareas, descritas a continuación:

**Modificar_plantillas.cpp**: Requiere del un archivo índice (línea 955) que contenga los nombres de los archivos de plantilla (como teams.dir) y realiza diversas funciones:
			      1. Reinicia estadísticas.
			      2. Envejece un año a los jugadores.
			      3. Ordena por media.
			      4. Añade/resta experiencia según los minutos jugados, la edad y la media principal (diferente para los GKs). Ir a línea 234.
			      5. Sube un punto la media principal.
			      6. Rerankeo (desuso) sirvió para reducir la media de los jugadores.
			      7. Rerankeo T14 (desuso) sirvió para reducir la media en otra temporada.
			      
**Rankings.cpp**: Requiere del un archivo índice (línea 741) que contenga los nombres de los archivos de plantilla (como teams.dir) y ordena según el criterio elegido. Sirve para hacer rankings de goleadores, por ejemplo

**Suma_Fit.cpp**: Requiere del un archivo índice (línea 189) que contenga los nombres de los archivos de plantilla (como teams.dir) y añade fit manualmente, según la cantidad deseada.

**Salarios.cpp**: Requiere del un archivo índice (línea 264) que contenga los nombres de los archivos de plantilla (como teams.dir) y calcula el % de salarios de los equipos incluidos. La tabla para calcular salarios se encuentra a partir de la línea 135.
