## Contenidos

Este repositorio contiene el código de diversos programas usados en ligamanagervirtual.com (LMV), en lenguaje C++.
Desde que se escribieron las primeras líneas hasta las últimas han pasado casi 5 años, en los cuales mi conocimiento sobre C++ ha aumentado considerablemente.

Es por eso que el código está dividido en 2 carpetas:

**Antiguos**: Contiene los primeros programas creados para LMV. Cada uno de los archivos .cpp contiene todo el código necesario para su compilación.
**Recientes**: Son los últimos programas creados. Comparten una librería personalizada, almacenada en el subdirectorio "lib", que cada uno de los .cpp del directorio superior usa para su propia compilación

## Notas

Gran parte de la configuración es "hard-coded" (por no decir toda) y algunos de los programas requieren la presencia de otros archivos para su ejecución (teams.dir, por ejemplo). El objetivo es especificar qué archivos son necesarios para cada programa y, en el futuro, añadir archivos configurables para añadir flexibilidad y reducir la necesidad de cambiar el mismo código.

Cualquier duda es bienvenida o problema son bienvenidos, pueden abrir un issue en github o contactar a través de alex.1993.24@gmail.com