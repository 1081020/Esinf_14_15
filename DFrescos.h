/* 
 * File:   DFrescos.h
 * Author: OpticalZoom
 *
 * Created on 23 de Outubro de 2014, 22:35
 */

#ifndef _DFRESCOS_H
#define	_DFRESCOS_H


#include "Deposito.h"
#include <vector>
#include <queue>
#include "Produto.h"

using namespace std;


class DFrescos: public Deposito
{
public:
	DFrescos();
	DFrescos(const DFrescos & orig);
	DFrescos(int numPaletes, int capacidadeMax);
	~DFrescos();
	bool armazenar(const Produto & prod);
	void escrever();
	int getMaxQuantity(int posi);
	int getFirstAvailable();

private:
	vector<queue<Produto> > vec;

};


DFrescos::DFrescos() :Deposito(){
	vec.reserve(numPaletes);
	for (int i = 0; i < numPaletes; i++){
		queue<Produto> palete;
		vec.push_back(palete);
	}


}

DFrescos::DFrescos(int numPaletes, int capacidadeMax) :Deposito(numPaletes,capacidadeMax){
	vec.reserve(numPaletes);
	for (int i = 0; i < numPaletes; i++){
		queue<Produto> palete;
		vec.push_back(palete);
	}

}


DFrescos::DFrescos(const DFrescos & orig) : Deposito(orig){
	vec = orig.vec;




}


DFrescos::~DFrescos(){
	vec.clear();
}

bool DFrescos::armazenar(const Produto & prod){
	int indicePalete = getFirstAvailable();
	if (indicePalete == -1) return false;

	vec[indicePalete].push(prod);


	return true;
}

void DFrescos::escrever(){

	for (int i = 0; i < numPaletes; i++){
		queue<Produto> palete = vec[i];
		int quantidadeExistente = palete.size();
		int quantidadeMaxima = getMaxQuantity(i);
		cout << "Palete " << i << " tem " << quantidadeExistente << " de " << quantidadeMaxima << " elementos" << endl;

	}

}

/*retorna o indice da palete ou -1 se nao encontrar nada*/
int DFrescos::getFirstAvailable(){
	for (int i = 0; i < numPaletes; i++){
		queue<Produto> palete = vec[i];
		int quantidadeExistente = palete.size();
		int quantidadeMaxima = getMaxQuantity(i);
		if (quantidadeExistente < quantidadeMaxima){
			return i;
		}

	}

	return -1;

}


int DFrescos::getMaxQuantity(int posi) {
	return posi % 2 == 0 ?
		getCapacidadeMax() :
		getCapacidadeMax() / 2;
}



#endif	/* _DFRESCOS_H */

