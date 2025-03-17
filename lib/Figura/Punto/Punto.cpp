#include "Punto.h"
#include "../../Complex/Complex.h"

Punto &Punto::operator+=(const Punto &a)
{
	x += a.x;
	y += a.y;
	return *this;
}
Punto& Punto::operator-= (const Punto& a){
	x -= a.x;
	y -= a.y;
	return *this;
}

bool Punto::operator==(const Punto &a)
{
	return (x == a.x && y == a.y);
}

Punto &Punto::operator=(const Punto &a)
{
	if (this != &a)
	{
		x = a.x;
		y = a.y;
	}
	return *this;
}

Punto operator+ (const Punto& a ,const Punto& b){
	Punto aux(a.x + b.x , a.y + b.y);
	return aux;
}
Punto operator- (const Punto& a ,const Punto& b){
	Punto aux(a.x - b.x , a.y - b.y);
	return aux;
}

std::ostream& operator<<( std::ostream& stream , const Punto& a ){
	stream << "x: " << a.x << ", y: " << a.y;
	return stream;
}

std::istream& operator>>( std::istream& stream , Punto& a ){
	stream >> a.x;
	stream >> a.y;
	return stream;
}

void Punto::Imprimir( Plano& a ){
	a.Set(static_cast<int>(x),static_cast<int>(y));
}

Punto::operator Complex() const
{
	return Complex(x, y);
}
