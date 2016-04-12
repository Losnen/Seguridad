#Intercambio de claves de Diffie-Hellman

##Objetivo: 

Implementar el algoritmo de intercambio de claves de Diffie-Hellman

##Desarrollo:

Implementa el generador el algoritmo de intercambio de claves de Diffie-Hellman según el diagrama que se incluye a continuación

###Alice

A 

Escoge secreto Xa 

Calcula Ya = α^Xa (mod p)

Genera k = Yb^Xa (mod p) 

###Bob

B

Escoge secreto Xb

Calcula Ya = α^Xb (mod p)

Genera k = Ya^Xb (mod p) 

El programa debe solicitar el número primo p, el número α < p, y los secretos Xa y Xb, y mostrar la traza completa del algoritmo, es decir, los números intermedios generados Ya e Yb, y la clave compartida k.

##Ejemplos:

p = 13, α = 4, xA = 5, xB = 2, yA =10, yB =3, k = 9

p = 43, α = 23 xA = 25, xB = 33, yA =40, yB =16, k = 4

p = 113, α = 43 xA = 54, xB = 71, yA =11, yB =29, k = 61 
