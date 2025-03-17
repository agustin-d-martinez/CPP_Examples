#include "Circulo.h"

Circulo::Circulo(const double& _x , const double& _y , const double& _radio) : centro(_x,_y) , radio(_radio) {}
Circulo::Circulo(const Punto& a , const double& _radio) : centro(a) , radio(_radio) {}

double Circulo::Area ( void ){
	return M_PI * radio * radio;
}
double Circulo::Perimetro ( void ){
	return M_PI * 2 * radio;
}

void Circulo::setRadio( const double& _radio ){
	radio = _radio;
}
void Circulo::setPos ( const double& x , const double& y ){
	centro.x = x;
	centro.y = y;
}
void Circulo::setPos ( const Punto& a ){
	centro = a;
}
