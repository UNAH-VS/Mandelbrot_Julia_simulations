/*
Esta es la implementación de la Clase Padre Conjunto.cpp
aquí se implementa la sobrecarga de Constructores.
*/
#include"Conjunto.hpp"
//-------------constructor por parametros--------------
Conjunto::Conjunto(const int maxiter){  
    this->Maxiter=maxiter;
}			 
//-------------constructor por defecto--------------
Conjunto::Conjunto(){ 
    this->Maxiter=10;
}	

