#include "Rectangulo.h"
#include "../Plano.h"

Rectangulo::Rectangulo(double _largo , double _ancho , double _x , double _y): largo(_largo) , ancho(_ancho){
	puntos.push_back(Punto(_x , _y));
	puntos.push_back(Punto(_x + ancho , _y));
	puntos.push_back(Punto(_x , _y + largo));
	puntos.push_back(Punto(_x + ancho, _y + largo));
}
double Rectangulo::Area( void ){
	return largo * ancho ;
}
double Rectangulo::Perimetro( void ){
	return (2*largo + 2*ancho);
}

void Rectangulo::Imprimir(Plano &a)
{
	for (auto& punto : puntos)
		a.Set(punto.x , punto.y);
}
