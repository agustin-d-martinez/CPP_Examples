#include "Rectangulo.hpp"
#include "../Plano.hpp"

Rectangulo::Rectangulo(double _largo , double _ancho , double _x , double _y): largo(_largo) , ancho(_ancho){
	Punto punto1(_x , _y);
	Punto punto2(_x + ancho , _y);
	Punto punto3(_x + ancho, _y + largo);
	Punto punto4(_x , _y + largo);
	lineas.push_back(Linea(punto1 , punto2));
	lineas.push_back(Linea(punto2 , punto3));
	lineas.push_back(Linea(punto3 , punto4));
	lineas.push_back(Linea(punto4 , punto1));

	x = punto1.x;
	y = punto1.y;
}
double Rectangulo::Area( void ){
	return largo * ancho ;
}
double Rectangulo::Perimetro( void ){
	return (2*largo + 2*ancho);
}

void Rectangulo::Imprimir(Plano &a)
{
	for (auto& i : lineas)
		i.Imprimir(a);
}

void Rectangulo::Rotate( double degree_angle)
{
	for(auto& i : lineas)
	{
		i.Rotate(degree_angle, Punto(x,y));
	}
}
