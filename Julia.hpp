/*
Este es el prototipo de la Clase hija Julia.hpp
en este apartado se crea la propia definición función
miembro que se encarga de pintar el conjunto de Julia.
Y lo hace de acuerdo a su definición.
*/
#include"Complejos1.hpp"
#include"Conjunto.hpp"

#ifndef JULIA
#define JULIA

//--------------Clase Julia--------------------
class Julia:public Conjunto{
	public:
	   Julia(const int Maxiter); //constructor por parametro
	   Julia();                 	//constructor por defecto	
	  ~Julia();                //Destructor
	 
	 //---------Funciones Miembro---------	
	void ImprimirConjunto(Complejos1 & );	
		
	private:
		double dx,dy;                      // pasos que se vayan dando en el plano 
		double xmax, xmin, ymax, ymin;     //float xmin,xmax, ymin, ymax; //delimitar los intervalos
		static double w;                   //tama;o de cada pixel
        static double h;

};
#endif
