#pragma once

#include <algorithm>
#include "../Figura.hpp"
#include "../Punto/Punto.hpp"

// Also Works as an Vector

class Linea : public Figura
{
protected:
	Punto inicio , fin ;
public:
	Linea();
	Linea(const Punto& _inicio , const Punto& _fin);
	~Linea(){}
	double getPendiente( void ) const;
	double Largo( void ) const;
	void setInicio( const Punto& a );
	void setFinal( const Punto& a);
	
	friend Linea operator+ (const Linea& a , const Punto& b);
	friend Linea operator- (const Linea& a , const Punto& b);

	Linea operator*( double scalar ) const;

	bool operator== (const Linea& a) const;
	Linea& operator= (const Linea& a);
	Linea& operator+= (const Punto& a);
	Linea& operator-= (const Punto& a);
	Linea& operator*= ( double scalar );

	void Rotate( double degree_angle , const Punto& center_rotation );
	void Rotate( double degree_angle );
	void Imprimir( Plano& a );
};

