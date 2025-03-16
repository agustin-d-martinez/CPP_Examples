#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class Punto;	//Forward declaration: Para no hacer un #include circular, declaro a la clase y la defino más adelante.

// Clase simil a <complex>	-> propia del standard
class Complex{
	private:
	double 	_real;
	double	_img;
	double	_module;
	double	_angle;

	public:
	Complex() : _real(0) , _img(0) , _module(0) , _angle(0) {}
	Complex( const Complex& a) : _real(a._real) , _img(a._img) , _module(a._module) , _angle(a._angle) {}
	Complex( double real , double img) : _real(real), _img(img) { calculateModAngle();}
	~Complex() {};

	double Real( void ) const;
	double Img( void ) const;
	double Module( void ) const;
	double Angle( void ) const;

	void Set( double real , double img );
	void SetPolar( double module , double angle );

	friend Complex operator+(const Complex& a, const Complex& b);
	friend Complex operator-(const Complex& a, const Complex& b);
	friend Complex operator*(const Complex& a, const Complex& b);
	friend Complex operator/(const Complex& a, const Complex& b);

	Complex& operator+=( const Complex& a);
	Complex& operator-=( const Complex& a);
	Complex& operator*=( const Complex& a);
	Complex& operator/=( const Complex& a);
	Complex& operator=(const Complex& a);
	
	bool operator==(const Complex& a);
	bool operator!=(const Complex& a);

	friend std::ostream& operator<< ( std::ostream& stream , const Complex& a);
	friend std::istream& operator>> ( std::istream& stream , Complex& a);

	operator Punto( void ) const;	//Permite la conversión de un Complex a un Punto 

	private:
	void calculateModAngle( void );
	void calculateRealImg( void );
};