ejercicio 9
Complejidad: Es O(n) (lineal, o sea, va creciendo parejito).
Si duplico n, Las comparaciones también se duplican, directo.
Aunque a simple vista hay dos bucles anidados, el de adentro es engañoso jakssj. El bucle de la j siempre se ejecuta exactamente 3 veces, sin importar el tamaño de n.

Entonces, la cantidad de comparaciones totales siempre va a ser 3 * n. 
En Big-O siempre ignoramos las constantes (los números fijos), así que quitamos ese 3 y nos queda
la complejidad lineal de O(n). Por esta misma razón, si pasamos de 100 a 200 elementos, las comparaciones pasan de 300 a 600. 
El crecimiento es totalmente proporcional, así que si n se duplica, el tiempo que toma también xd.
