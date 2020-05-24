Adivina el número
============

**Alumno**:  Netanel David Jamilis           
**Número de Padrón**: 99093            
**Email**: njamilis@fi.uba.ar  
**Github**: netaneldj/tp3


Introducción
============

Objetivos
---------

Los objetivos del presente trabajo son los siguientes:

-   Diseño y construcción de sistemas con acceso distribuido

-   Encapsulación de Threads y Sockets en Clases

-   Definición de protocolos de comunicación

-   Protección de los recursos compartidos

-   Uso de buenas practicas de programación en C++

En las siguientes secciones se verá plasmado el cumplimiento de los
objetivos.

Secciones
---------

El presente trabajo práctico está dividido en diferentes secciones las cuales se pueden agrupar en dos grandes categorías. La primera es la introducción en donde se enumeran los objetivos y se informa como se estructurará el informe. La segunda es el analisis del desarrollo del proyecto. Allí se relatará todo el proceso de desarrollo del proyecto destacando los puntos más importantes del mismo y los desafios que se debio superar.

Desarrollo del proyecto
==========================

Primeras impresiones
------------------------

Al comienzo se me dificulto encarar la solución debido a la complejidad propia de un programa cliente-servidor sumado a que el servidor debe poder atender simultaneamente a multiples clientes. Nos simplifico un poco la tarea haber desarrollado previamente un programa cliente-servidor. Aunque el mismo haya sido desarrolado en otro lenguaje y debimos migrarlo al actual. Tambien nos simplifico la tarea haber trabajado antes con multihilos. Al ya tener desarrollados todos estos componentes nos ahorramos mucho tiempo de trabajo y pudimos completar la meta de tener listo el programa en tan solo una semana de trabajo. 

Resolución adoptada
------------------------

La solucón que implemente útiliza los siguientes objetos:

-   Client

-   Server
-   ClientTalker
-   ClientManager
-   TextFileInterpreter

-   Protocol

-   Command
-   CommandHelp
-   CommandNumber
-   CommandString
-   CommandSurrender

-   Socket
-   Thread

-   Score

A continuación explicare como utilice cada uno de ellos.

### Client

El Client es el objeto a través del cual el usuario se conecta al juego. Su rol es leer lo que el usuario ingresa por teclado, validarlo, enviarselo al servidor y esperar la respuesta para luego mostrarla por pantalla.

### Server

El Server es el objeto al cúal se concentan todos los clientes. En esta ocasion decidí delegar su funcionamiento a otros objetos por lo que lo unico que hace es inicializarlos y leer la entrada estandar porque en caso de que reciba una letra 'q' finalizará el programa y mostrara por pantalla las estadisticas del juego.

### TextFileInterpreter

El TextFileInterpreter es el encargado de leer el archivo que continene los números secretos, validarlos a traves del protocolo y guardarlos en una lista para su posterior utilización.

### ClientManager

El ClientManager es el encargado de coordinar a todos los ClientTalker. Es quien los creara asignandoles el número secreto, iniciará y al finalizar la partida eliminará sus recursos. 

### ClientTalker

El ClientTalker es el objeto a traves del cúal el Server interactua con cada Client. Por cada Client que se conecte el ClientManager creara una instancia de este objeto quien recibirá los mensajes, los procesara a traves del Protocol y enviara su respuesta.

### Protocol

El Protocol es el encargado de toda la logica de validación y encriptación del programa. Tambien a traves de él tanto el cliente como el servidor realizan envian y reciben sus mensajes ya que este objeto les realiza la encriptación y desencriptación de los mismos.

### Command

El Command representa a cada comando que se puede enviar o recibir en el programa, existe uno por cada tipo. Una vez que el protocolo identifico el tipo de mensaje se desea enviar o recibir, le delega dicha tarea al comando correspondiente al tipo de mensaje ya que este sabe como enviarlo o recibirlo.


### Socket

El Socket es el encargado de establecer la comunicación entre los clientes y el servidor. El protocolo y los comandos lo utilizan para enviar y recibir los mensajes. A su vez el cliente lo utiliza para conectarse al servidor y el ClientManager lo utiliza para conectarse aceptar las conexiones de los clientes.

### Thread

El objeto thread representa un hilo del programa. En el fondo cada cliente es un hilo y el servidor crea un hilo por cada conexion que acepta. Por este motivo hay que tener especial cuidado a la hora de contar las victorias y derrotas en el juego porque puede ser se pisen los diferentes hilos a la hora de computar los resultados de los juegos.

### Score

El Score es el marcador donde se computan los resultados de los juegos. Acá hay que tener cuidado de que no se pisen los diferentes hilos y este marque un resultado erroneo. Para esto utilizamos mutex y condition variables.

Diagrama ilustrativo
------------------------



Dificultades abordadas
------------------------

A lo largo de todo el trabajo me fui topando con una serie de dificultades que de no superarlas no superarlas no hubiese podido progresar con el trabajo. 

Algunas de ellas se deberieron en la falta de conocimiento, como por ejemplo no saber como aceptar multiples conexiones en un mismo servidor o como realizar un correcto manejo de errorres. 

Otras se debieron a dificultades propias de un diseño cliente-servidor como la construcción del protocolo.

Por último, pero no menos importante se debieron enfrentar las problematicas tipicas de un diseño orientado a objetos como por ejemplo herencia de atributos privados, entre otros.
