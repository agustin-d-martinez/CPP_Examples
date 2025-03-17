#pragma once

#include <vector>
#include <iostream>
#include <functional>

class Figura;

class Plano {
	private:
	std::vector<std::vector<char> >	ui;
	std::vector<std::reference_wrapper<Figura> > formas;
	
	public:
	Plano (int largo = 50 , int ancho = 50);
	~Plano(){}
	void Add(Figura& a);
	void Set ( const int& x , const int& y );
	void Set ( const double& x , const double& y );
	void Update( void );
};