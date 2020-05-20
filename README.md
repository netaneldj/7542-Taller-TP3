Recolectores y Productores
============

**Alumno**:  Netanel David Jamilis           
**Número de Padrón**: 99093            
**Email**: njamilis@fi.uba.ar  
**Github**: netaneldj/tp2


Introducción
============

Objetivos
---------

Los objetivos del presente trabajo son los siguientes:

-   Diseño y construcción de sistemas orientados a objetos

-   Diseño y construcción de sistemas con procesamiento concurrente

-   Protección de los recursos compartidos

En las siguientes secciones se verá plasmado el cumplimiento de los
objetivos.

Secciones
---------

El presente trabajo práctico está dividido en diferentes secciones las cuales se pueden agrupar en dos grandes categorías. La primera es la introducción en donde se enumeran los objetivos y se informa como se estructurará el informe. La segunda es el analisis del desarrollo del proyecto. Allí se relatará todo el proceso de desarrollo del proyecto destacando los puntos más importantes del mismo y los desafios que se debio superar.

Desarrollo del proyecto
==========================

Primeras impresiones
------------------------

Al comienzo se me dificulto encarar la solución. No sabía por donde empezar a desarrollarla. En este trabajo además de sumarse la dificultad del manejo de Threads y el diseño orientado a objetos, se sumo la dificultad de tener que desarrollarlo en un nuevo lenguaje. 

Luego de dedicarle varios dias a familiarizase con el nuevo lenguaje y cambiar la mentalidad de programación estructurada a orientada a objetos, comence a desarrollar los objetos en orden de complejidad ascendente. Partiendo desde los recursos y las herramientas auxiliares hasta los recolectores, productores y los objetos más complejos como el inventario.

Resolución adoptada
------------------------

La solucón que implemente útiliza los siguientes objetos:

-   Poblado

-   Recurso
-   Carbon
-   Hierro
-   Madera
-   Trigo

-   Recolector
-   Agricultor
-   Leniador
-   Minero

-   Productor
-   Armero
-   Carpintero
-   Cocinero

-   Inventario
-   Tablero

-   Cola Bloqueante
-   Thread

A continuación explicare como utilice cada uno de ellos.

### Poblado

El poblado es el objeto principal del programa. Este se encarga de ingresar los recursos que llegan por parametro a las colas, crear los trabajadores que se especifican en la entrada y mandarlos a trabajar. Tambien una vez finalizado el trabajo se encarga de unir los resultados parciales y mostrar las estadisticas por pantalla.  

### Recurso

El recurso es el elemento base el cual los trabajadores van a recolectar y los productores van a utilizar como materia prima para sus trabajos. Los diferentes tipos de recurso disponibles en este poblado son carbon, hierro, madera y trigo.

### Recolector

El recolector es el encargado de recolectar el recurso de la cola bloqueante, trabajarlo y depositarlo en el inventario. Los diferentes tipos de recolectores son agricultor, leniador y minero. Cada uno recolecta sus recursos de una cola bloqueante diferente.

### Productor

El productor es el encargado de buscar los recursos del inventario, trabajarlos y convertirlos en puntos de beneficio. Los diferentes tipos de productores son armero, carpintero y cocinero. Cada uno necesita diferentes recursos en diferentes cantidades para realizar su trabajo y generar puntos de beneficio por ello.

### Inventario

El inventario es el deposito donde los recolectores almacenan sus materias primas y donde los productores las buscan para transformarlas en sus productos. Es el objeto más concurrido del programa ya que allí covergen todos los productores y recolectores. Por eso hay que tener un cuidado especial para que no se descontrole todo. Este orden se logra utilizando bloqueos para que solo pueda acceder u trabajador a la vez.

### Tablero

El tablero es el contador de puntos donde los productores depositan los puntos de beneficio obtenidos por su trabajo. Al igual que en el inventario hay que tener cuidado porque allí van a acceder todos los productores y no queremos que se pierdan ni que se sumen dos veces los puntos.

### Cola Bloqueante

La cola bloqueante es el objeto donde se depositan los recursos recibidos por parametro y de donde los recolectores los tomaran para luego depositarlos en el inventario.

### Thread

El objeto thread representa un hilo del programa. En el fondo cada trabajador es un hilo que trabaja en paralelo a los dems. Por eso en los espacios comunes como el inventario, la cola bloqueante o el tablero hay que tener especial cuidado que no se superpongan los diferentes pedidos de los trabajadores.


Diagrama ilustrativo
------------------------

![\[fig:class01\]Proceso de Envio y Recepción de Mensajes](img/diagrama_secuencia_recolector_productor.png)

Dificultades abordadas
------------------------

A lo largo de todo el trabajo me fui topando con una serie de dificultades que de no superarlas no superarlas no hubiese podido progresar con el trabajo. 

Algunas de ellas se deberieron en la falta de conocimiento, como por ejemplo no saber como se manejan los threads o el uso compartido de memoria. 

Otras se debieron a dificultades propias de un lenguaje nunca antes trabajado.

Por último, pero no menos importante se debieron enfrentar las problematicas tipicas de un diseño orientado a objetos como por ejemplo herencia de atributos privados, entre otros.
