#include "Circulo.hpp"

Circulo::Circulo(const double& _x , const double& _y , const double& _radio) : centro(_x,_y) , radio(_radio) {
	x = _x - _radio;
	y = _y - _radio;}
Circulo::Circulo(const Punto& a , const double& _radio) : centro(a) , radio(_radio) {
	x = centro.x - _radio;
	y = centro.y - _radio;
}

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

void Circulo::Rotate( double degree_angle)
{
	return;
}

void Circulo::Imprimir(Plano &a)
{ //Algoritmo del Círculo de Bresenham o algoritmo de punto medio para circuloss
	int xc = static_cast<int>(centro.x);
	int yc = static_cast<int>(centro.y);
	int rad = static_cast<int>(radio);
	
	int x = rad;
	int y = 0;
	int decision = 1 - x;

	while (y <= x){
		a.Set(xc + x , yc + y);
		a.Set(xc - x , yc + y);
		a.Set(xc + x , yc - y);
		a.Set(xc - x , yc - y);
		a.Set(xc + y , yc + x);
		a.Set(xc - y , yc + x);
		a.Set(xc + y , yc - x);
		a.Set(xc - y , yc - x);

		y++;
		if (decision <= 0){
			decision += 2*y + 1;
		}else{
			x--;
			decision += 2*(y-x) + 1;
		}

	}

}
