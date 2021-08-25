/*
Este es el prototipo de la Clase hija Mandelbrot
implementa dentro de sus funciones una función que 
pinta el Conjunto y lo hace de acuerdo a su definición.
*/
#include"Complejos1.hpp"
#include"Conjunto.hpp"

#ifndef MANDELBROT1
#define MANDELBROT1

//--------------Clase Hija Mandelbrot1--------------------
class Mandelbrot1:public Conjunto{
	public:
	   Mandelbrot1(const int Maxiter);   //---------constructor por parametros--------------
	   Mandelbrot1();	                 //---------constructor por defecto--------------
	  ~Mandelbrot1();
	 
	 //---------Funciones Miembro---------	
	void ImprimirConjunto(Complejos1 &);	
		
	private:
		double dx,dy;                       // pasos que se vayan dando en el plano 
	    double xmax, xmin, ymax, ymin;      //double xmin,xmax, ymin, ymax; //delimitar los ejes
		static double w;                    //tama;o de cada pixel
        static double h;
};
#endif
