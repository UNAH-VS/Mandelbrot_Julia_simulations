/*
Implementacion de la Clase Hija Conjunto de Mandelbrot,
en este apartado se hace la sobrecarga de constructores 
ademas de ello se implementa la función que pinta 
el conjunto y hacemos uso de la librería gráfica
*/
#include<graphics.h>
#include<math.h>
#include"Complejos1.hpp"
#include"Conjunto.hpp"
#include"Mandelbrot1.hpp"

//-----Inicializacion de variables tipo static-----
double Mandelbrot1::w=2.5;   
double Mandelbrot1::h=2.5;

//-------------------Sobrecarga de constructores---------------------
Mandelbrot1::Mandelbrot1(const int maxiter):Conjunto(maxiter){ //constructor por parametro
	this->xmin=-2;      //delimitar los ejes
	this->ymin=-1.25;
	this->xmax=this->xmin+w;  //0.5
	this->ymax=this->ymin+h;  // 1.25
	 	
	this->dx=(this->xmax -this->xmin)/(DIM-1);  //tamaño de paso entre cada pixel // 0.5
	this->dy=(this->ymax-this->ymin)/(DIM-1);                                    //1.25	
}	
		 
Mandelbrot1::Mandelbrot1():Conjunto(){ //constructor por defecto
	this->Maxiter=10;
	this->xmin=-2;
	this->ymin=-1.25;
	this->xmax=this->xmin+w;
	this->ymax=this->ymin+h;
	 	
	this->dx=(this->xmax -this->xmin)/(DIM-1);
	this->dy=(this->ymax-this->ymin)/(DIM-1);
}	

void Mandelbrot1::ImprimirConjunto(Complejos1 &c1){
	initwindow(DIM,DIM);
	setcolor(WHITE);
	settextstyle(6,0,3);
	outtextxy(50,70,"PRESENTANDO EL CONJUNTO DE:");
	delay(2000);
	outtextxy(DIM/4,DIM/4,"MANDELBROT");
	delay(3000);
	     
//-----------bucles para recorrer la pantalla a traves de cada pixel y calcular el numero complejo correspondiente-------------
	    for(int j=0; j<DIM; j++){
	 	  this->Zc.setImag(ymin+j*this->dy);   //se hace cambio del espacio virtual al espacio matematico
	 		for(int i=0; i<DIM; i++){
	 		  this->Zc.setReal(xmin+i*this->dx);
	 			this->Z0 = Zc; 
	 			    
	    // iterar la funcion 
	    int iter=0;
	    for(iter=0;iter<this->Maxiter;iter++){
		  
		  this->Z2 = Z0*Z0;
		  this->nuevoZ = Z2+Zc;  
		
		/*si esto se cumple entonces el punto donde hemos comenzado la iteracion no pertenece 
		al conjunto y pasaremos a estudiar el siguiente pixel de la pantalla*/			   	   
		if(nuevoZ.getMagnitud()>4){ 
		   break;
		}
		   this->Z0 = nuevoZ;    //se actualiza el valor de Z0
	    }
				
	    if(iter==this->Maxiter){    
	    	putpixel(i,j,BLACK); //pertenecen al conjunto
		}
		else if(iter<this->Maxiter){  //No pertenecen al conjunto
			putpixel(i,j,WHITE);
		}
	}
}    
	delay(3000);
	     
//-----------bucles para recorrer la pantalla a traves de cada pixel y calcular el numero complejo correspondiente-------------
	 	for(int j=0; j<DIM; j++){
	 	  this->Zc.setImag(ymin+j*this->dy);
	 		for(int i=0; i<DIM; i++){
	 		  this->Zc.setReal(xmin+i*this->dx);
	 		  this->Z0 = Zc;
					 
	    // iterar la funcion 
	    int iter=0;
		for(iter=0;iter<this->Maxiter;iter++){
		    this->Z2 = Z0*Z0;
		   	this->nuevoZ = Z2+Zc;	 
		
		/*si esto se cumple entonces el punto donde hemos comenzado la iteracion no pertenece 
		al conjunto y pasaremos a estudiar el siguiente pixel de la pantalla*/				  
		if(nuevoZ.getMagnitud()>4){ 
			break;
		}
		this->Z0 = nuevoZ;
	    }  
	    	    
	    if(iter==this->Maxiter){ // si iter alcanza el numero maximo de iteraciones significa que el mod de zn no fue mayor que 2
	        setcolor(0);
			putpixel(i,j,getcolor()); // implica que el punto pertenece al conjunto de Mandelbrot
		}
		else if(iter>=0 && iter<=10){
			setcolor(100);
		    putpixel(i,j,getcolor());
		}
		else if(iter>10 && iter<=17){
			setcolor(iter*16%255);
		    putpixel(i,j,getcolor());
		}
		else if(iter>17 && iter <=255){
			setcolor(2*iter*16%255);
			putpixel(i,j,getcolor());
		}
		else if(iter>2*255 && iter<=3*255){  
			setcolor(iter-2*255);
			putpixel(i,j,getcolor());
		}
		else if(iter>3*255 && iter<=4*255){
			setcolor(4*iter*16%255);
			putpixel(i,j,getcolor());
		}
		else if(iter>4*255 && iter<=5*255){
			setcolor(5*iter*16%255);
			putpixel(i,j,getcolor());
		}
	}
}
	getch();
	closegraph();
	
	system("pause");
}
  
Mandelbrot1::~Mandelbrot1(){
}
