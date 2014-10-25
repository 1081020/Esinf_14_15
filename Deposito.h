/* 
 * File:   Deposito.h
 * Author: OpticalZoom
 *
 * Created on 23 de Outubro de 2014, 22:34
 */

#ifndef _DEPOSITO_H
#define	_DEPOSITO_H

#include <string>
#include <iostream>

using namespace std;


class Deposito
{
protected:
	int numPaletes;
	int capacidadeMax; /*capasidade maxima de uma palete*/
	double areaTotal;


public:
	Deposito();
	Deposito(int numPaletes, int capacidadeMax, double  areaTotal);
	Deposito(int numPaletes, int capacidadeMax);
	Deposito(const Deposito & orig);
	~Deposito();
	int getNumPaletes()const;
	int getCapacidadeMax()const;
	double getAreaTotal() const;
	virtual void escrever()=0;

};

Deposito::Deposito(){
	capacidadeMax = 4;
	numPaletes = 4;
	areaTotal = 100;

}

Deposito::Deposito(const Deposito & orig)
{;
	numPaletes=orig.getNumPaletes();
	capacidadeMax=orig.getCapacidadeMax();
	areaTotal=orig.getAreaTotal();

}

Deposito::Deposito(int numPaletes, int capacidadeMax, double  areaTotal){
	this->numPaletes = numPaletes;
	this->capacidadeMax = capacidadeMax;
	this->areaTotal = areaTotal;

}
Deposito::Deposito(int numPaletes, int capacidadeMax){
	this->numPaletes = numPaletes;
	this->capacidadeMax = capacidadeMax;
	this->areaTotal = 100;
}


Deposito::~Deposito(){

}

int Deposito::getNumPaletes()const{
	return this->numPaletes;
}

int Deposito::getCapacidadeMax()const {
	return this->capacidadeMax;
}

double Deposito::getAreaTotal() const {
	return this->areaTotal;
}

void Deposito::escrever(){
	cout << "Deposito" << endl;

}

#endif	/* _DEPOSITO_H */

