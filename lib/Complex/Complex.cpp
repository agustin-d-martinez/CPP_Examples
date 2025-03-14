#include "Complex.h"

Complex::Complex()	: _real(0) , _img(0) , _module(0) , _angle(0)
{}
Complex::Complex(const Complex &a) : _real(a._real) , _img(a._img) , _module(a._module) , _angle(a._angle)
{}
Complex::Complex(float real, float img) : _real(real), _img(img)
{
	calculateModAngle();
}

float Complex::Real( void ) const{
	return _real;
}
float Complex::Img( void ) const{
	return _img;
}
float Complex::Module( void ) const{
	return _module;
}
float Complex::Angle( void ) const{
	return _angle;
}

void Complex::Set( float real , float img ){
	_real = real;
	_img = img;
	calculateModAngle();
}
void Complex::SetPolar( float module , float angle ){
	_module = module;
	_angle = angle;
	calculateRealImg();
}

Complex operator+(const Complex& a, const Complex& b){
	Complex aux(a._real + b._real , a._img + b._img);
	return aux;
}
Complex operator-(const Complex& a, const Complex& b){
	Complex aux(a._real - b._real , a._img - b._img);
	return aux;
}
Complex operator*(const Complex& a, const Complex& b){
	Complex aux;
	aux.SetPolar(a._module * b._module , a._angle + b._angle);
	return aux;
}
Complex operator/(const Complex& a, const Complex& b){
	Complex aux;
	if (b._module != 0)
		aux.SetPolar(a._module / b._module , a._angle - b._angle);
	return aux;
}
Complex &Complex::operator+=(const Complex &a)
{
	_real += a._real;
	_img += a._img;
	calculateModAngle();
	return *this;
}
Complex &Complex::operator-=(const Complex &a)
{
	_real -= a._real;
	_img -= a._img;
	calculateModAngle();
	return *this;
}
Complex &Complex::operator*=(const Complex &a)
{
	_module *= a._module;
	_angle += a._angle;
	calculateRealImg();
	return *this;
}
Complex &Complex::operator/=(const Complex &a)
{
	if(a._module != 0)
		_module /= a._module;
	else
		_module = 0;
	_angle -= a._angle;
	calculateRealImg();
	return *this;
}

Complex &Complex::operator=(const Complex &a)
{
	_real = a._real;
	_img = a._img;
	calculateModAngle();
	return *this;
}

bool Complex::operator==(const Complex& a){
	return (_real == a._real && _img == a._img);
}
bool Complex::operator!=(const Complex& a){
	return !(_real == a._real && _img == a._img);
}

std::ostream& operator<< ( std::ostream& stream , const Complex& a){

	stream << a._real << " ";
	if (a._img > 0)
		stream << "+";
	stream << a._img << "i ";
	return stream;
}
std::istream& operator>> ( std::istream& stream , Complex& a){
	stream >> a._real;
	stream >> a._img;
	a.calculateModAngle();
	return stream;
}


void Complex::calculateModAngle( void ){
	_module = sqrt(_real * _real + _img * _img);
	_angle = atan2f(_img , _real);
}
void Complex::calculateRealImg( void ){
	_real = _module * cos(_angle);
	_img = _module * sin(_angle);
}
