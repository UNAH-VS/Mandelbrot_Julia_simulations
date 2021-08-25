/*
Este es el prototipo de la Clase Padre llamada
Conjunto en esta clase se ha implementado el
concepto de Clases Abstractas, ya que la misma
cuenta con una función del tipo virtual pura que 
básicamente obliga a sus clase hijas a cada quien 
implementarla a su manera.Esta Clase utiliza miembros
de datos del tipo Complejo.
*/
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"Complejos1.hpp"

#ifndef CONJUNTO
#define CONJUNTO
#define DIM 640 // variable Macros : Definir el tama;o de la ventana
//--------------Clase Padre--------------------
class Conjunto{
	public:
	   Conjunto(const int Maxiter); //constructor por parametro		
       Conjunto();                  //constructor por defecto	 
	 
	 //---------Funcion Miembro---------	
	virtual void ImprimirConjunto(Complejos1 &)=0;	
		
	protected:
		int Maxiter;                 //maximo de iteraciones que el usuario desee
		Complejos1 nuevoZ;        // valor de z_(k) en cada iteracion 
		Complejos1 Z2;      //se crea un objeto del tipo complejo para guardar el cuadrado de Z0
		Complejos1 Z0;                 // xviejo, yviejo, (iteracion anterior)
		Complejos1 Zc;              // numero complejo parametro c

};
#endif 
