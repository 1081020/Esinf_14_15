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



#endif	/* _ARMAZEM_H */

