#pragma once

#include <algorithm>
#include "../Figura.h"
#include "../Punto/Punto.h"

class Linea : public Figura
{
protected:
	Punto inicio , fin ;
public:
	Linea();
	Linea(const Punto& _inicio , const Punto& _fin);
	~Linea(){}
	double getPendiente( void );
	double Largo( void );
	void setInicio( const Punto& a );
	void setFinal( const Punto& a);
	
	friend Linea operator+ (const Linea& a , const Punto& b);
	friend Linea operator- (const Linea& a , const Punto& b);

	bool operator== (const Linea& a);
	Linea& operator= (const Linea& a);
	Linea& operator+= (const Punto& a);
	Linea& operator-= (const Punto& a);
	void Rotate( const double& degree_angle , const Punto& center_rotation );
	void Rotate( const double& degree_angle );
	void Imprimir( Plano& a );
};

