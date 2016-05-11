#Práctica 10: Algoritmo de Fiat-Shamir
##Samuel Ramos Barroso

![Esquema](http://i.imgur.com/G09BotL.png?1)

Ejemplo 1:

1. Entrada:

* p=7, q=5
* s=3
* i=2 (número de iteraciones)
* 1ª iteración: x=16, e=0
* 2ª iteración: x=2, e=1

2. Salida:

* N=35
* v= 9
* 1ª iteración: a= 11, comprobar que 16^2 = 11 (mod 35) y dar por válida la iteración
* 2ª iteración: a= 4, y = 6, comprobar que 6^2 = 4*9 (mod 35) y dar por válida la iteración

Ejemplo 2:

1. Entrada:

* p = 683, q = 811
* s=43215
* i=1 (número de iteraciones)
* 1ª iteración: x=16785, e=1

2. Salida:

* N=553913
* v= 295502
* 1ª iteración: a= 348421, y = 291658, comprobar que 291658^2 = 348421*295502 (mod 553913) y dar por válida la iteración