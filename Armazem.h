/* 
 * File:   Armazem.h
 * Author: OpticalZoom
 *
 * Created on 23 de Outubro de 2014, 22:31
 */

#ifndef _ARMAZEM_H
#define	_ARMAZEM_H


#include <string>
#include <iostream>
#include "Deposito.h"
#include "DFrescos.h"
#include "DNormais.h"
#include <map>

using namespace std;

class Armazem
{
	public:
		Armazem();
		Armazem(int numDepositosFrescos, int numPaletesFrescos, int capacidadeMaxFrecos, int numDepositosNormais, int numPaletesNormais, int capacidadeMaxNormais);
		~Armazem();

		void adicionarDeposito(const Deposito &deposito);

		void lerFicheiro();

	protected:
		int numDepositosFrescos;
		int numPaletesFrescos;
		int capacidadeMaxFrecos;
		int numDepositosNormais;
		int numPaletesNormais;
		int capacidadeMaxNormais;
		map<int, Deposito*> mapa;
		int posicao;

};


Armazem::Armazem(){
	this->posicao = 0;
	DNormal * depoNorm = new DNormal();

	DFrescos * depoFresco = new DFrescos();
	mapa[posicao] = depoNorm;
	posicao++;
	mapa[posicao] = depoFresco;
	posicao++;

}


Armazem::Armazem(int numDepositosFrescos, int numPaletesFrescos, int capacidadeMaxFrecos, int numDepositosNormais, int numPaletesNormais, int capacidadeMaxNormais){
	this->posicao = 0;
	for (int i = 0; i < numDepositosFrescos; i++){
		DFrescos* depoFresco = new DFrescos(numPaletesFrescos, capacidadeMaxFrecos);
		mapa[posicao] = depoFresco;
		posicao++;
	}
	for (int j = 0; j < numDepositosNormais; j++){
		DNormal* depoNorm = new DNormal(numPaletesNormais, capacidadeMaxNormais);
		mapa[posicao] = depoNorm;
		posicao++;
	}
}



Armazem::~Armazem(){
	mapa.clear();
}
/*
void Armazem::adicionarDeposito(const Deposito & deposito){
	mapa[posicao] = deposito;
	posicao++;

}
*/

void Armazem::lerFicheiro(){

	for (int i = 0 ; i < mapa.size(); i++)
	{

		(*mapa[i]).escrever();
	}

}


#endif	/* _ARMAZEM_H */

