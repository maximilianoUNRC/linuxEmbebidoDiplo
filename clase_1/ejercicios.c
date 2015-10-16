1. Crear la siguiente estructura de directorios en su directorio home
    practico1/dir1
              dir2
              dir3/nuevos
                   antiguos

Resolucion: 
        asus@asus-K53SC ~/Escritorio/linux_Embebed $ mkdir -p /practico/dir1/
        asus@asus-K53SC ~/Escritorio/linux_Embebed $ mkdir -p /practico/dir2
        asus@asus-K53SC ~/Escritorio/linux_Embebed $ mkdir -p /practico/dir3
        asus@asus-K53SC ~/Escritorio/linux_Embebed $ mkdir -p /practico/dir3/nuevos
        asus@asus-K53SC ~/Escritorio/linux_Embebed $ mkdir -p /practico/dir3/antiguos

*******************************************************************************************************************
2. Crear en el directorio nuevos un archivo que se llame arch1. Determine su número de inode.
Resulocion:
        asus@asus-K53SC /practico/dir3/nuevos $ touch arch1.txt
        asus@asus-K53SC /practico/dir3/nuevos $ ls -i 


*******************************************************************************************************************
3. Mover el archivo arch1 al directorio antiguos
Reasolucion: 
        asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3 $ mv nuevos/arch1 antiguos/

*******************************************************************************************************************
4. Escriba su nombre en el archivo arch1
Resolucion: 
        asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3 $ echo maxi > arch1.txt

*******************************************************************************************************************
5. Copie el archivo arch1 a la carpeta practico1
Resolucion: 
       asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3/antiguos $ cp arch1.txt ~/Escritorio/linux_Embebed/practico/

*******************************************************************************************************************

6. Renombre el archivo arch1 de la carpeta antiguos con el nombre arch1_v2
Resolucion: 
       asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3/antiguos $ mv arch1.txt arch2_v2.txt

*******************************************************************************************************************

7. Determine que tipo de archivo es arch1_v2
Resolucion:
        asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3/antiguos $ file -i arch2_v2 

*******************************************************************************************************************

8. Cree en el mismo directorio los archivos arch1_v3, arch1_v4 y arch1_v5
Resolucion:
       asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3/antiguos $ touch arch2_v3 && touch arch2_v4 && touch arch2_v5
        
*******************************************************************************************************************

9. Cree un enlace “blando” y un enlace “duro” del archivo arch1_v3. Determine su número de
inode en ambos casos. Experimente borrando y creando nuevamente el archivo original y
los enlaces. Cual es el comportamiento?.
Resolucion: 
            (No se realiza)

*******************************************************************************************************************

10. Mostrar en pantalla los archivos que empiecen con arch 
Resolucion : 
    asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3/antiguos $ ls | grep arch

*******************************************************************************************************************
11. Mostrar en pantalla los archivos cuya penúltima letra sea la letra v
Resolucion:
    asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3/antiguos $ ls | grep 'v.\>'

    asus@asus-K53SC ~/Escritorio/linux_Embebed/practico/dir3/antiguos $ ls *v?

*******************************************************************************************************************
12. Dar al directorio dir2 los permisos rw-rx-x
Resolucion: 
    asus@asus-K53SC ~/Escritorio/linux_Embebed/practico $ chmod 651 dir2
            
*******************************************************************************************************************
13. Dar al directorio dir3 los permisos rwx-rw-r
Resolucion:
    asus@asus-K53SC ~/Escritorio/linux_Embebed/practico $ chmod 764 dir3

*******************************************************************************************************************
14. Cambie la máscara para que quede rw-r-----16. Borre los archivos del directorio antiguos

*******************************************************************************************************************
15. Cambiar el nombre del directorio dir2 a dir_2
Resolucion:
         asus@asus-K53SC ~/Escritorio/linux_Embebed/practico $ mv dir2 dir_2^C

*******************************************************************************************************************
16. Listar todos los archivos del directorio etc que empiecen por t en orden inverso
Resolucion:
        asus@asus-K53SC /etc $ ls -r | grep '^t'

*******************************************************************************************************************
17. Listar todos los archivos del directorio dev que empiecen por tty y tengan 5 caracteres
Resolucion:
        asus@asus-K53SC /dev $ ls | grep 'tty..\>' 

*******************************************************************************************************************
18. Listar todos los archivos, incluidos los ocultos, del directorio raíz
Resolucion: 
        asus@asus-K53SC ~ $ ls -a

*******************************************************************************************************************
19. Determine donde están ubicados los archivos que se ejecutan cuando se llaman a los
comandos: ls, cp, man, type, alias
Resolucion:
        asus@asus-K53SC ~ $ type cp

*******************************************************************************************************************
20. Escribir los comandos que realicen las siguientes tareas:
    • Cree un directorio
    • Cree un archivo con el contenido del directorio /etc ordenado usando el comando sort
    • Mueva el archivo dentro del directorio
    • Verifique que tipo de archivo es el que usted creo
    • Muestre por pantalla el contenido del archivo

Resolucion: 
     asus@asus-K53SC ~/nuevo_etc $ mkdir directorio_nuevo
     asus@asus-K53SC ~/nuevo_etc $ touch archivo.txt
     asus@asus-K53SC ~/nuevo_etc $ ls /dev/ | sort >  archivo.txt
     asus@asus-K53SC ~/nuevo_etc $ file archivo.txt
     asus@asus-K53SC ~/nuevo_etc $ cat archivo.txt
         
*******************************************************************************************************************
21. Escribir los comandos que realicen las siguientes tareas como usuario root:
    • Cree un archivo con el contenido de las ultimas 15 líneas del directorio /etc y en otro las 10 primeras líneas del directorio /bin
    • Cree un archivo que liste el contenido del directorio actual en formato de lista "VER"
    • Quite al primer archivo permiso de lectura para todos. Intente visualizarlo. Que ocurre?
    • Otorgue al segundo archivo permiso de escritura para todos
    • Modifique el segundo archivo ordenándolo en forma inversa como usuario . Pudo? porque? "VER"

Resolucion: 
asus@asus-K53SC ~/prueba  $ touch ejer21a.txt && ls /etc/ | cat -b |  head -10  > ejer21a.txt && touch ejer21b.txt && ls /bin/ | cat -b |  tail -15  > ejer21b.txt
asus@asus-K53SC ~/prueba  $ chmod -r ejer21a.txt   "No permite la lectura por ningun usuario o medio"
asus@asus-K53SC ~/prueba  $ chmod +w ejer21b.txt   "No permite la lectura por ningun usuario o medio"    
asus@asus-K53SC ~/prueba  $ touch temp.txt && cat ejer21b.txt |sort > temp.txt && cat /dev/null > ejer21b.txt && cat temp.txt > ejer21b.txt && rm temp.txt

*******************************************************************************************************************
22. Cambie los permisos del archivo: ("VER")
    -rw-r--r-- 1 Usuario Users 150 Jul 1 15:00
    • Permisos de lectura y escritura para todos.
    • Quitar todos los permisos para el grupo y otros.
    • Que implican los permisos originales? 
Resolucion:



*******************************************************************************************************************
23. Cual es la salida correcta devuelta por Linux para el siguiente conjunto de comandos:
    ~$ mkdir test
    ~$ cd test
    ~/test$ echo echo > ECHO
    ~/test$ chmod 666 ECHO
    ~/test$ ./ECHO | more

"Es permiso denegado por que el chmod 666 es permiso de lectura escritura para todos los usuarios menos ejecucion"

*******************************************************************************************************************
24. Cual es la salida correcta devuelta por Linux para el siguiente conjunto de comandos:
~$ mkdir dirar
~$ echo date > dirar/ar
~$ cd dirar
~/dirar$ chmod 777 ar
~/dirar$ ./ar | more

"lun oct 12 10:40:52 ART 2015 - brinda acceso total al dueño  y a los demás cuando se trabaja con ar"

******************************************************************************************************************
25. Cree la siguiente estructura de archivos (escriba las órdenes necesarias suponiendo que esta
en el directorio /tmp). Los archivos que no sean directorios pueden estar vacíos.
__ tmp/
|_______ backup01.txt
|_______ backup02.txt
|_______ backup03/
            |_______ enero/
                        |
                        |_______ sistema.txt
                        |
                        |_______ usuarios.txt
            |_______ febrero/
            |_______ marzo/


Resolucion: 
    asus@asus-K53SC ~/prueba  $ mkdir -p tmp/backup03/enero && touch tmp/backup01.txt && touch tmp/backup02.txt && mkdir tmp/backup03/febrero tmp/backup03/marzo && touch tmp/backup03/enero/sistemas.txt && touch tmp/backup03/enero/usuarios.txt

******************************************************************************************************************
26. Suponiendo la estructura de archivos anterior, y estando en el directorio enero, borre con
direccionamiento absoluto y sin cambiar de directorio, el archivo backup01.txt, mueva el
archivo sistema.txt al subdirectorio marzo y copie el archivo usuarios.txt al subdirectorio
febrero.
******************************************************************************************************************
27. Crear el directorio dir2 y dir3 en otro directorio PRUEBA. Cuales son los permisos del
directorio dir2?

Resolucion:
    asus@asus-K53SC ~/prueba  $ mkdir dir2 dir3
    asus@asus-K53SC ~/prueba  $ ls -l
    total 40
    drwxr-xr-x 2 asus asus 4096 oct 12 11:07 dir2
    drwxr-xr-x 2 asus asus 4096 oct 12 11:07 dir3

******************************************************************************************************************
28. Utilizando la notación simbólica, eliminar todos los permisos de escritura (propietario,
grupo, otros) del directorio dir2.

Resolucion:
   asus@asus-K53SC ~/prueba  $ chmod -w dir2
   asus@asus-K53SC ~/prueba  $ ls -l
   total 40
   dr-xr-xr-x 2 asus asus 4096 oct 12 11:07 dir2


******************************************************************************************************************
29. Utilizando la notación octal, eliminar el permiso de lectura del directorio dir2, al resto de
los usuarios.

Resolucion:
    asus@asus-K53SC ~/prueba  $ chmod 111 dir2
    asus@asus-K53SC ~/prueba  $ ls -l
    total 40
    d--x--x--x 2 asus asus 4096 oct 12 11:15 dir2


******************************************************************************************************************
30. Cuáles son ahora los permisos asociados a dir2?

Resolucion:
    Para dir2 los permisos son:     dueño X / grupo X / otros X "Osea solo permisos de ejecucion"

******************************************************************************************************************
31. Crear bajo dir2, un directorio llamado dir2l

Resolucion:
    asus@asus-K53SC ~/prueba  $ mkdir dir2/dir2l
    mkdir: no se puede crear el directorio «dir2/dir2l»: Permiso denegado

******************************************************************************************************************
32. Concederse así mismo permiso de escritura en el directorio dir2e intentar de nuevo el paso anterior.
Resolucion:
    asus@asus-K53SC ~/prueba  $ chmod 777 dir2
    asus@asus-K53SC ~/prueba  $ ls -l
    total 40
    drwxrwxrwx 2 asus asus 4096 oct 12 11:15 dir2
    asus@asus-K53SC ~/prueba  $ mkdir dir2/dir2l


***************************************************************************************************************** 
33. Cuáles son los valores por omisión asignados a los archivos?
Resolucion:
    dueño rwx / grupo r-x / otros r-x  

*****************************************************************************************************************
34. Cambiar el directorio actual al directorio dir3. Imprimir su trayectoria completa para verificar el cambio.

Resolucion:
    "Ver"    

*****************************************************************************************************************
35. Cuáles son los permisos asignados en su momento a este directorio?
Resolucion:
    asus@asus-K53SC ~/prueba  $ mv dir2/dir2l/ dir3
    asus@asus-K53SC ~/prueba /dir3 $ ls -l
    total 4
    drwxr-xr-x 2 asus asus 4096 oct 12 11:29 dir2l

*****************************************************************************************************************
36. Cree un archivo de texto. Determine su número de inode.
Resolucion: 
    asus@asus-K53SC ~/prueba  $ touch nuevo_doc.txt
    asus@asus-K53SC ~/prueba  $ ls -i
         2235841 nuevo_doc.txt
    asus@asus-K53SC ~/prueba  $ ls -l
    -rw-r--r-- 1 asus asus    0 oct 12 11:38 nuevo_doc.txt
   
*****************************************************************************************************************
37. Cree un enlace “blando” y un enlace “duro” del archivo anterior. Determine su número de
inode en ambos casos. Experimente borrando y creando nuevamente el archivo original y
los enlaces. Cual es el comportamiento?.
    (No se realiza)
*****************************************************************************************************************
38. Cree un directorio dir1 y otro dir2 en el directorio home del usuario.
 Cree un enlacesimbólico al directorio dir1 dentro del directorio dir2 enlacedir1.
"EnlaceSimbolico: es una referencia (enlace) a una carpeta (directorio) o fichero que está situado en un lugar físico distinto. "INODOS DIFERENTES 
Resolucion:
    asus@asus-K53SC ~/prueba /dir3 $ ln -s ~/prueba\ /dir1 enlace_publico1
    asus@asus-K53SC ~/prueba /dir3 $ ls -l
    total 4
    drwxr-xr-x 2 asus asus 4096 oct 12 11:29 dir2l
    lrwxrwxrwx 1 asus asus   23 oct 12 11:53 enlace_publico1 -> /home/asus/prueba /dir1

****************************************************************************************************************
39. Posicionarse en dir2 y, empleando el enlace creado en el ejercicio , crear el directorio
nuevo1 de dir1. Verifique los inodos de los directorios y enlaces creados.
    "VER"
***************************************************************************************************************
40. Utilizando el enlace creado copiar los archivos que empiecen por u del /bin directorio
nuevo1.
Resolucion:
    asus@asus-K53SC ~/prueba  $ ls /bin/ | grep '^u'
    udevadm
    ulockmgr_server
    umount
    uname
    uncompress
    unicode_start
    asus@asus-K53SC ~/prueba  $ cp -pRv /bin/udevadm  dir3/enlace_publico1/
    «/bin/udevadm» -> «dir3/enlace_publico1/udevadm»
    asus@asus-K53SC ~/prueba  $ cp -pRv /bin/ulockmgr_server  dir3/enlace_publico1/
    «/bin/ulockmgr_server» -> «dir3/enlace_publico1/ulockmgr_server»
    asus@asus-K53SC ~/prueba  $ cp -pRv /bin/umount  dir3/enlace_publico1/
    «/bin/umount» -> «dir3/enlace_publico1/umount»
    asus@asus-K53SC ~/prueba  $ cp -pRv /bin/uname  dir3/enlace_publico1/
    «/bin/uname» -> «dir3/enlace_publico1/uname»
    asus@asus-K53SC ~/prueba  $ cp -pRv /bin/uncompress  dir3/enlace_publico1/
    «/bin/uncompress» -> «dir3/enlace_publico1/uncompress»
    asus@asus-K53SC ~/prueba  $ cp -pRv /bin/unicode_start  dir3/enlace_publico1/
    «/bin/unicode_start» -> «dir3/enlace_publico1/unicode_start»

***************************************************************************************************************
41. Cree en el directorio home del usuario un archivo llamado fich1 usando el comando touch.
Crear dos enlaces duros del fichero fich1, llamarlos enlace, en los dir1 dir2
respectivamente. Verifique los inodos de los directorios y enlaces creados.
"Los enlaces duros lo que hacen es asociar dos o más ficheros compartiendo el mismo inodo. Esto hace que cada enlace duro sea una copia exacta del resto de ficheros asociados, tanto de datos como de permisos, propietario, etc. Esto implica también que cuando se realicen cambios en uno de los enlaces o en el fichero este también se realizará en el resto de enlaces. "
Resolucion:
    asus@asus-K53SC ~/prueba  $ touch dir1/nuevo1/fich1.txt
    asus@asus-K53SC ~/prueba  $ ln dir1/nuevo1/fich1.txt dir3/enlace_duro
    asus@asus-K53SC ~/prueba  $ ls -il dir1/nuevo1/fich1.txt 
    2235583 -rw-r--r-- 2 asus asus 0 oct 12 12:19 dir1/nuevo1/hola.txt
    asus@asus-K53SC ~/prueba  $ ls -il dir3/enlace_duro 
    2235583 -rw-r--r-- 2 asus asus 0 oct 12 12:19 dir3/enlace_duro

***************************************************************************************************************
42. Ingrese como root y liste los procesos que se están ejecutando actualmente en el sistema
• Use las opciones –A, u, –u root y otras opciones
/* u  formato usuario, muestra nombre, PID, hora inicio, estado
  a  mostrar también procesos de otros usuarios.*/

• Explique lo observado
    "informa sobre procesos en ejecución"

• ¿Identifica los procesos?
asus-K53SC prueba  # ps au
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root      1115  0.0  0.0   4644   840 tty4     Ss+  08:51   0:00 /sbin/getty -8 38400 tty4
root      1119  0.0  0.0   4644   836 tty5     Ss+  08:51   0:00 /sbin/getty -8 38400 tty5
root      1126  0.0  0.0   4644   832 tty2     Ss+  08:51   0:00 /sbin/getty -8 38400 tty2
root      1129  0.0  0.0   4644   836 tty3     Ss+  08:51   0:00 /sbin/getty -8 38400 tty3
root      1135  0.0  0.0   4644   840 tty6     Ss+  08:51   0:00 /sbin/getty -8 38400 tty6
root      1500  1.8  0.8 163036 67364 tty8     Ssl+ 08:51   3:53 /usr/bin/X :0 -audit 0 -auth /var/lib/mdm/:0.Xauth -nolisten tcp vt8
root      1552  0.0  0.0   4644   840 tty1     Ss+  08:51   0:00 /sbin/getty -8 38400 tty1
asus      3908  0.0  0.0   8560  3684 pts/2    Ss   09:18   0:05 bash
root      6338  0.0  0.0  10128  2468 pts/2    S    12:23   0:00 sudo su
root      6339  0.0  0.0   9480  2144 pts/2    S    12:23   0:00 su
root      6347  0.0  0.0   8392  3388 pts/2    S    12:23   0:00 bash
root      6397  0.0  0.0   6500  1196 pts/2    R+   12:27   0:00 ps au

• ¿Qué número de proceso tiene el shell de root?
    root      6347  0.0  0.0   8392  3388 pts/2    S    12:23   0:00 bash


***************************************************************************************************************
43. Ingrese a una nueva consola virtual como usuario y liste los procesos que se están
ejecutando actualmente en el sistema

• ¿Identifica los procesos? "PID"
asus@asus-K53SC ~ $ ps au
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root      1115  0.0  0.0   4644   840 tty4     Ss+  08:51   0:00 /sbin/getty -8 38400 tty4
root      1119  0.0  0.0   4644   836 tty5     Ss+  08:51   0:00 /sbin/getty -8 38400 tty5
root      1126  0.0  0.0   4644   832 tty2     Ss+  08:51   0:00 /sbin/getty -8 38400 tty2
root      1129  0.0  0.0   4644   836 tty3     Ss+  08:51   0:00 /sbin/getty -8 38400 tty3
root      1135  0.0  0.0   4644   840 tty6     Ss+  08:51   0:00 /sbin/getty -8 38400 tty6
root      1500  1.8  0.9 186436 74604 tty8     Ssl+ 08:51   4:01 /usr/bin/X :0 -audit 0 -auth /var/lib/mdm/:0.Xauth -nolisten tcp vt8
root      1552  0.0  0.0   4644   840 tty1     Ss+  08:51   0:00 /sbin/getty -8 38400 tty1
asus      3908  0.0  0.0   8560  3684 pts/2    Ss   09:18   0:05 bash
asus      6441  0.0  0.0   6500  1196 pts/2    R+   12:32   0:00 ps au

• ¿Qué número de proceso tiene el shell de root?
    "VER"
• Use las opciones –A, u, –u usuario y otras opciones
    ps au 
• Explique lo observado
    Procesos corriendo en el sistema 
**************************************************************************************************************
44. Visualice los procesos del sistema en formato de árbol
    ps -forest
**************************************************************************************************************
45. Crear el archivo proceso con los procesos que no tienen ningún terminal .
Resolucion:
    asus@asus-K53SC ~/prueba  $ touch procesos.txt
    asus@asus-K53SC ~/prueba  $ ps x > procesos.txt 

**************************************************************************************************************
46. Escribir los comandos que realicen las siguientes tareas
• Ejecute el comando “yes > /dev/null &”
    asus@asus-K53SC ~/prueba  $ yes > /dev/null &
    [1] 6514
• Cámbiese a una consola como root y ejecute ps aux
• ¿Observa el proceso del usuario corriendo? ¿Que número de PID tiene?
    asus      6514  100  0.0   5448   280 pts/2    R    12:38   1:15 yes
• Detenga el proceso que esta corriendo el usuario
    asus-K53SC asus # kill 6514

*************************************************************************************************************
47. Ejecute el comando yes hola > /dev/null en primer plano y luego yes hola > /dev/null en
segundo plano.
 El & le indica a S.O. que ejecute el programa en segundo plano
    asus@asus-K53SC ~ $ yes hola >/dev/null &
    [1] 3191
    asus@asus-K53SC ~ $ bg 1
    bash: bg: el trabajo 1 ya está en segundo plano
    asus@asus-K53SC ~ $ fg 1
    yes hola > /dev/null
    ^Z
    [1]+  Detenido                yes hola > /dev/null

    

*************************************************************************************************************
48. Cambie el proceso del segundo plano a primer plano del ejercicio anterior.
    asus@asus-K53SC ~ $ yes hola >/dev/null &
    [1] 3191
    asus@asus-K53SC ~ $ fg 1
    yes hola > /dev/null
    ^Z
    [1]+  Detenido                yes hola > /dev/null


*************************************************************************************************************
49. Detenga (no los elimine!!!) los procesos del ejercicio No 47.
    Ctrl + Z
*************************************************************************************************************
50. Reactive los procesos del ejercicio No 47 en segundo plano.

Ahora queremos volver a poner en funcionamiento :
    Si queremos devolverlo a foreground escribiremos fg.
    Si queremos devolverlo a background escribiremos bg (esta sería la opción mas lógica)

*************************************************************************************************************
51. Elimine las tareas del ejercicio No 28 47 el número de jobs, y pid.
"VER"









