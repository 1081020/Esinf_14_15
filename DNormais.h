/* 
 * File:   DNormais.h
 * Author: OpticalZoom
 *
 * Created on 23 de Outubro de 2014, 22:36
 */

#ifndef _DNORMAIS_H
#define	_DNORMAIS_H

#include "Deposito.h"
#include <list>
#include <stack>
#include <vector>
#include "Produto.h"


#include <deque>

#include <string>
#include <iostream>


using namespace std;

template<class T>
class DNormais : public Deposito
{
private:
    int ppares;
    int pimpares;

    vector < stack <T > > palete;

public:
	DNormais();
	DNormais(const DNormais & orig);
	DNormais(int numPaletes, int capacidadeMax);
	~DNormais();
	bool armazenar(const Produto & prod);
	void escrever();
	int getFirstAvailable();

private:
	list<stack<Produto> > lista;
};


DNormais::DNormais() :Deposito(){
	for (int i = 0; i < numPaletes; i++){
		stack<Produto> palete;
		lista.push_back(palete);

	}


}


DNormais::DNormais(const DNormais & orig) : Deposito(orig){
	lista = orig.lista;




}
DNormais::DNormais(int numPaletes, int capacidadeMax) :Deposito(numPaletes, capacidadeMax){
	for (int i = 0; i < numPaletes; i++){
		stack<Produto > palete;
		lista.push_back(palete);

	}

}


DNormais::~DNormais(){
	lista.clear();
}

bool DNormais::armazenar(const Produto & prod){
	list<stack<Produto> >::iterator it = lista.begin();

	if (getFirstAvailable() != -1){
		advance(it, getFirstAvailable());

		(*it).push(prod);

		return true;



	}
	return false;



}

void DNormais::escrever(){
	int i = 0;
	for (list<stack<Produto> >::iterator it = lista.begin(); it != lista.end(); it++){

		stack<Produto> palete = *it;
		int quantidadeExistente = palete.size();
		cout << "Palete " << i << " tem " << quantidadeExistente << " de " << capacidadeMax << " elementos" << endl;
		i++;

	}

}

int DNormais::getFirstAvailable(){
	int i = 0;

	for (list<stack<Produto> >::iterator it = lista.begin(); it != lista.end(); it++){

		stack<Produto> palete = *it;
		int quantidadeExistente = palete.size();

		if (quantidadeExistente < capacidadeMax){

			return i;
		}

		i++;
	}

	return -1;

}


#endif	/* _DNORMAIS_H */

