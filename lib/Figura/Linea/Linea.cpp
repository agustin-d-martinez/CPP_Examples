#include "Linea.h"

Linea::Linea(/* args */) : inicio() , fin() {x = y = 0;}

Linea::Linea(const Punto& _inicio , const Punto& _fin) : inicio(_inicio) , fin(_fin) {
	x = std::min(inicio.x , fin.x);
	y = std::min(inicio.y , fin.y);
}
double Linea::getPendiente( void ){
	return (inicio.y + fin.y) / (inicio.x - fin.x);
}
double Linea::Largo( void ){
	return sqrt( pow(inicio.x - fin.x, 1) + pow(inicio.y - fin.y, 1));
}
void Linea::setInicio( const Punto& a ){
	inicio = a;
}
void Linea::setFinal( const Punto& a){
	fin = a;
}

bool Linea::operator== (const Linea& a){
	return (inicio == a.inicio && fin == a.fin);
}

Linea &Linea::operator=(const Linea &a)
{
	if (this != &a)
	{
		inicio = a.inicio;
		fin = a.fin;
	}
	return *this;
}

Linea &Linea::operator+=(const Punto &a)
{
	inicio += a;
	fin += a;
	return *this;
}

Linea &Linea::operator-=(const Punto &a)
{
	inicio -= a;
	fin -= a;
	return *this;
}

void Linea::Rotate(const double &degree_angle, const Punto &center_rotation)
{
	this->operator-=(center_rotation);
	inicio.Rotate(degree_angle);
	fin.Rotate(degree_angle);
	this->operator+=(center_rotation);
}

void Linea::Rotate(const double &degree_angle)
{
	inicio.Rotate(degree_angle);
	fin.Rotate(degree_angle);
}

void Linea::Imprimir(Plano &a)
{	//algoritmo de Bresenham para graficar lineas.
	int x0 = static_cast<int>(inicio.x);
	int y0 = static_cast<int>(inicio.y);
	int x1 = static_cast<int>(fin.x);
	int y1 = static_cast<int>(fin.y);

	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);

	// Dirección del incremento
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;

	// Error
	int err = dx - dy;

	while (true) {
		a.Set(x0, y0);

		if (x0 == x1 && y0 == y1)
			break;

		int e2 = 2 * err;
		// Si el error doble es mayor que -dy, avanzamos en x
		if (e2 > -dy) {
			err -= dy;
			x0 += sx;
		}
		// Si el error doble es menor que dx, avanzamos en y
		if (e2 < dx) {
			err += dx;
			y0 += sy;
		}
	}
}

Linea operator+(const Linea &a, const Punto &b)
{
	Linea aux(a);
	aux.inicio += b;
	aux.fin += b;
	return aux;
}

Linea operator-(const Linea &a, const Punto &b)
{
	Linea aux(a);
	aux.inicio -= b;
	aux.fin -= b;
	return aux;
}
