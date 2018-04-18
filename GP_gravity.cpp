#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//ecuacion diferencial de Fuerza gravitacional
double funcion(double G, double M, double t, double x){
	return -(G*M)/(x*x);
}

//cambio de variable. velocidad es el cambio en el tiempo de posicion
double velocidad(double t, double v){
	return v;
}

//Funcion main
int main(){
	//condiciones/parametros iniciales
	double t =0.0;
	double h =0.01;
	double v =0.0;
	double x =100.0 ;
	double G =10;
	double M =1000;

	//x_final sera el 1 por ciento de la posicion inicial
	double x_fin = 0.01*x;


	//funciones Runge-Kutta orden 4
	double k1_v; 
  	double k2_v; 
   	double k3_v; 
  	double k4_v; 
 	double k1_x; 
	double k2_x; 
	double k3_x; 
	double k4_x; 
	
	//este for actualiza para cada paso 'h'  como evoluciona el sistema
	for(int i=0;x>=x_fin;i++){
			
		k1_v = funcion(G,M,t,x);
    		k2_v = funcion(G,M,t+h/2.0 , x+(h/2.0)*k1_v);
   		k3_v = funcion(G,M,t+h/2.0 , x+(h/2.0)*k2_v );
    		k4_v = funcion(G,M,t+h,x+h*k3_v);
    
    		k1_x = velocidad(t,v);
    		k2_x = velocidad(t+h/2.0 , v+(h/2.0)*k1_x);
    		k3_x = velocidad(t+h/2.0 , v+(h/2.0)*k2_x);
    		k4_x = velocidad(t+h,v+h*k3_x);

		x = x+(h/6.0)*( k1_x + 2*k2_x + 2* k3_x + k4_x );
    		v = v+(h/6.0)*( k1_v + 2*k2_v + 2* k3_v + k4_v );
		t = t+h;
	
		cout<<x<<" "<<v<<" "<<t<<endl;

	}
	return 0;
}
