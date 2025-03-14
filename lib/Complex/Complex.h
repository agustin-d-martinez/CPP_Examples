#pragma once
#include <iostream>
#include <cmath>

# define M_PIl          3.141592653589793238462643383279502884L

// Clase simil a <complex>	-> propia del standard
class Complex{
	private:
	float 	_real;
	float	_img;
	float	_module;
	float	_angle;

	public:
	Complex();
	Complex( const Complex& a);
	Complex( float real , float img);
	~Complex() {};

	float Real( void ) const;
	float Img( void ) const;
	float Module( void ) const;
	float Angle( void ) const;

	void Set( float real , float img );
	void SetPolar( float module , float angle );

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


	private:
	void calculateModAngle( void );
	void calculateRealImg( void );
};