/* 
 * File:   main.cpp
 * Author: OpticalZoom
 *
 * Created on 23 de Outubro de 2014, 22:25
 */

#include <iostream>
#include "Armazem.h"
#include "Deposito.h"
#include "DFrescos.h"
#include "DNormais.h"

using namespace std;

int main(int argc, const char * argv[])
{
    Armazem arm1;
    Armazem arm2;

//    Deposito d1("123456",3,3,3);
//    Deposito d2("78901",3,4,3);

  //  DFrescos d1("123456",3,3,3);
  //  DFrescos d2("8888",5,6,7);


   // DNormais<char> d3("33434",2,3,4);

/*
	DepositoFresco depo;



	for (int i = 0; i < 15; i++){
		cout << "--------------- Produto "<<i<<" ------------------------" << endl;
		Carne c;
		if (!depo.armazenar(c)){
			cout << "PASSOU O LIMITE MAXIMO DE PRODUTOS!" <<endl;
		} else
			depo.escrever();


	}*/
	/*

	DepositoNormal depo;



	for (int i = 0; i < 30; i++){
		cout << "--------------- Produto " << i << " ------------------------" << endl;
		Carne c;
		if (!depo.armazenar(c)){
			cout << "PASSOU O LIMITE MAXIMO DE PRODUTOS!" << endl;
		}
		else
			depo.escrever();


	}
	*/
	Armazem amar;

	amar.lerFicheiro();



	cin.get();
	return 0;



   // return EXIT_SUCCESS;

};

