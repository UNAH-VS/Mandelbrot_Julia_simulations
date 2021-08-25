/*
Aquí se hace la implementación de la clase Julia.cpp
se implementa la función virtual pura y esta la hace 
a su manera y pinta el conjunto de acuerdo a su definición.
En este apartado se hace uso de la librería gráfica.
*/
#include"Complejos1.hpp"
#include"Conjunto.hpp"
#include"Julia.hpp"
#include<graphics.h>
#include<math.h>

//-----Inicialización de variables de tipo static-----
double Julia::w=4;   
double Julia::h=4;

//-------------Sobrecarga de Constructores--------------
Julia::Julia(const int maxiter):Conjunto(maxiter){ //constructor por parametro
	this->xmin=-2;
	this->ymin=-2;
	this->xmax=this->xmin+w;
	this->ymax=this->ymin+h;
	 	
	this->dx=(this->xmax -this->xmin)/(DIM-1);
	this->dy=(this->ymax-this->ymin)/(DIM-1);
}	
		
Julia::Julia():Conjunto(){ //constructor por defecto
	this->Maxiter=10;
	this->xmin=-2;
	this->ymin=-1;
	this->xmax=this->xmin+w;
	this->ymax=this->ymin+h;
	 	
	this->dx=(this->xmax -this->xmin)/(DIM-1);
	this->dy=(this->ymax-this->ymin)/(DIM-1);
}	
	
void Julia::ImprimirConjunto(Complejos1 &c1){
	initwindow(DIM,DIM);
	setcolor(WHITE);
	settextstyle(6,0,3);
	outtextxy(50,100, "PRESENTANDO EL CONJUNTO DE" );
	delay(2000);
	settextstyle(6,0,3);
	outtextxy(DIM/3,DIM/3, " JULIA ");
	delay(1000);	 
	
//-----------bucles para recorrer la pantalla a traves de cada pixel y calcular el numero complejo correspondiente-------------
    for(int j=0; j<DIM; j++){
	  this->Zc.setImag(ymin+j*this->dy);
	 	for(int i=0; i<DIM; i++){
	 	  this->Zc.setReal(xmin+i*this->dx);
	 		 this->Z0=Zc;
					 
// iterar la funcion 
	int iter=0;
	for(iter=0; iter<Maxiter; iter++){
	    Complejos1 Zc(c1.getReal(), c1.getImag());
		Z2=Z0*Z0;
		nuevoZ= Z2+Zc;	 
	
	/*si esto se cumple entonces el punto donde hemos comenzado la iteracion no pertenece 
	al conjunto y pasaremos a estudiar el siguiente pixel de la pantalla*/					  
	if(nuevoZ.getMagnitud()>4){ 
	   break;
	}
	this->Z0=nuevoZ;
	}  
	    	    
    if(iter==this->Maxiter){ // si iter alcanza el numero maximo de iteraciones significa que el mod de zn no fue mayor que 2
	        setcolor(0);
			putpixel(i,j,getcolor()); // implica que el punto pertenece al conjunto de Julia
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
Julia::~Julia(){
}
