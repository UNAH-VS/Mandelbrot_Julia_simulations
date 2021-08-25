#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<graphics.h>
#include"Mandelbrot1.hpp"
#include"Complejos1.hpp"
#include"Julia.hpp"

int main(){   
    int numIter;
    double a,b;
    cout<<"Para obtener un conjunto ingrese un numero complejo "<<endl<<endl;
	cout<<"->  Para la parte real ingrese un numero x: ";
	cin>>a;
	cout<<"->  Para la parte imaginaria ingrese un numero y : ";
    cin>>b;
    
	Complejos1 *c1=new Complejos1(a,b);  //se crea un objeto del tipo complejo en tiempo de ejecucion
    c1->MostrarComplejos();
    cout<<endl;
    
    cout<<"Ingrese el numero de iteraciones: ";
    cin>>numIter;
    cout<<endl;
    
    int Opcion;
    cout<<"Ingrese el numero 1 para ver el Conjunto de Mandelbrot "<<endl;
    cout<<"O Ingrese el numero 2 para ver el Conjunto de Julia"<<endl;
    cin>>Opcion;
    
    switch(Opcion){
    	case 1:{
    		Mandelbrot1 *fractal= new Mandelbrot1(numIter);
            fractal->ImprimirConjunto(*c1);
	        delete fractal;
            fractal=0;      
			break;
		}
		
		case 2:{
			Julia *fractal= new Julia(numIter);
	        fractal->ImprimirConjunto(*c1);
	        delete fractal;        //se borra el espacio de memoria para el objeto creado  
	        fractal=0;             //se desconecta el apuntador	
			break;
		}
		
    	default: cout<<"El numero ingresado debe ser 1 o 2 "; break;   	
	}
	system("pause");
	return 0;
} 
