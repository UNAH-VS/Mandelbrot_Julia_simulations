/*
La Clase Complejos1.hpp es el prototipo, �nicamente aqu�
encontramos las funciones miembro con las que trabaja
un n�mero complejo, para ello utilizamos funciones del 
tipo set y get adem�s se sobrecargan operadores para
trabajar con n�meros complejos.
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#ifndef COMPLEJOS1
#define COMPLEJOS1

class Complejos1{
	
	friend	Complejos1 &operator +(const Complejos1 &, const Complejos1 &); 
	friend Complejos1 &operator*(const Complejos1 &, const Complejos1 & );
   
	public:
		Complejos1();
		Complejos1(const double Real, const double Imaginaria);
	
		void MostrarComplejos();
		
		double setReal(const double);
        const double getReal() const; 
        
        double setImag(const double);
        double setComplejo(const double, const double);
        const double getImag() const;
        
        double getMagnitud();
        
        Complejos1 &operator =(const Complejos1 &);
		
	private:
		double real, imaginaria;
};

#endif
