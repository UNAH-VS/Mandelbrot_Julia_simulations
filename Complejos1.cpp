/*
Esta es la implementación de la Clase Complejo.cpp,
Aquí se definen el propósito de cada función miembro
de la clase y los operadores sobrecargados.
*/
#include "Complejos1.hpp"
//-------------------Constructor por defecto----------------------
Complejos1::Complejos1(){
	this->real = 0;
    this->imaginaria = 0;
}

//-------------------Constructor con parametro--------------------
Complejos1::Complejos1(const double Real, const double Imaginaria){
   this->real = Real;
   this->imaginaria = Imaginaria;
}

//---------------------Mostrar complejos--------------------------
void Complejos1::MostrarComplejos(){
	cout<<"El numero complejo es: "<<this->real<<"+"<<this->imaginaria<<"i"<<endl;
}

//---------------------Funcion set ParteReal----------------------
double Complejos1::setReal(const double Real){
	this->real = Real;
}

//---------------------Funcion get ParteReal----------------------
const double Complejos1::getReal() const{
	return this->real;
}

//--------------------Funcion set ParteImag-----------------------
double Complejos1::setImag(const double Imaginaria){
	this->imaginaria = Imaginaria;
}
 
 double Complejos1::setComplejo(const double Real, const double Imaginaria){
 		this->real = Real;
	   this->imaginaria = Imaginaria;

}

//---------------------Funcion get ParteImag----------------------
const double Complejos1::getImag() const{
    return this->imaginaria;
}


//--------------------Funcion get Magnitud---------------------
      double Complejos1::getMagnitud(){
           double magnitud;
           magnitud=real*real+imaginaria*imaginaria;
	        return magnitud;
	
        } 
	
//------------------Sobrecarga de operadores---------------------
Complejos1 &operator *(const Complejos1 & c1, const Complejos1 &c2){
	double real = c1.real*c2.real-c1.imaginaria*c2.imaginaria;
	double imag = c1.real*c2.imaginaria + c2.real*c1.imaginaria;
	
	return *(new Complejos1(real, imag));
}

Complejos1 &operator +(const Complejos1 & c1, const Complejos1 &c2){
	double real = c1.real + c2.real;
	double imag = c1.imaginaria + c2.imaginaria;
	
	return *(new Complejos1(real, imag));
}

Complejos1 &Complejos1::operator =(const Complejos1 &c1){
       if(this != &c1){
       	this->real=(c1.real);
       	this->imaginaria=(c1.imaginaria);
	   }
	return *(this);
}
