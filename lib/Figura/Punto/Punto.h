#pragma once

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#include "../Figura.h"

class Complex;		//Forward declaration: Para no hacer un #include circular, declaro a la clase y la defino más adelante.

class Punto : public Figura{
	public:
//	double x , y;
	
	public:
	Punto( double _x = 0 , double _y = 0 ) {x = _x; y = _y;}
	
	~Punto(){}

	Punto& operator+= (const Punto& a);
	Punto& operator-= (const Punto& a);
	bool operator== (const Punto& a);
	Punto& operator= (const Punto& a);

	friend Punto operator+ (const Punto& a ,const Punto& b);
	friend Punto operator- (const Punto& a ,const Punto& b);

	friend std::ostream& operator<<( std::ostream& stream , const Punto& a );
	friend std::istream& operator>>( std::istream& stream , Punto& a );

	void Rotate( const double& degree_angle );

	void Imprimir( Plano& a );

	operator Complex( ) const;	//Permite la conversión de un Punto a un Complex
};