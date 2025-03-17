#include "Linea.h"

Linea::Linea(/* args */) : inicio() , fin() {}

Linea::Linea(const Punto& _inicio , const Punto& _fin) : inicio(_inicio) , fin(_fin) {}
double Linea::getPendiente( void ){
	return (inicio.y + fin.y) / (inicio.x - fin.x);
}
double Linea::Largo( void ){
	return sqrt( pow(inicio.x - fin.x, 1) + pow(inicio.y - fin.y, 1));
}
void Linea::setOrigen( const Punto& a ){
	inicio = a;
}
void Linea::setFinal( const Punto& a){
	fin = a;
}

bool Linea::operator== (const Linea& a){
	return (inicio == a.inicio && fin == a.fin);
}

void Linea::Imprimir(Plano &a)
{
	double pendiente = getPendiente();
	for ( double i = inicio.x ; i < fin.x ; i++ )
		a.Set(i , inicio.x + pendiente * i);
}
