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

using namespace std;

class Armazem
{
private:
    Deposito **depositos;
    int tamanho_array;
    int actual;
    
public:
    Armazem();
    Armazem(const Armazem& a);
    bool insDepo(Deposito &a);
    
    
    virtual Armazem *clone() const;
    virtual ~Armazem();
    
    
    virtual Armazem & operator = (const Armazem &a);
    
    virtual void escreve(ostream& out) const;
    

};

Armazem::Armazem()
{
    tamanho_array = 3;
    actual = 0;
    depositos = new Deposito*[tamanho_array];
}

Armazem::Armazem(const Armazem& a)
{
    for( int i = 0; i<a.tamanho_array;i++){
        depositos[i] = a.depositos[i];
    }
    tamanho_array = a.tamanho_array;
}


bool Armazem::insDepo(Deposito &d) {
    if (actual == tamanho_array) {
        tamanho_array *= 2;
        Deposito **tmp = new Deposito*[tamanho_array];
        for (int i = 0; i < actual; i++) {
            tmp[i] = depositos[i];
        }
        delete[] depositos;
        depositos = tmp;
    }
    depositos[actual] = d.clone();
    actual++;
    return true;
}



Armazem::~Armazem()
{

}

Armazem *Armazem:: clone() const
{
    return new Armazem(*this);
}



//sobrecarga de operadores
Armazem & Armazem::operator=(const Armazem &a) {
    if(this !=&a) {
        for(int i=0;i<actual;i++) {
            delete depositos[i];
        }
        delete[] depositos;
        tamanho_array = a.tamanho_array;
        actual = a.actual;
        depositos = new Deposito *[tamanho_array];
        for(int i=0;i<actual;i++) {
            depositos[i] = a.depositos[i]->clone();
        }
    }
    return *this;
}



void Armazem::escreve(ostream& out) const {
    out << "Lista de Depositos: " << endl;
    for(int i=0;i<actual;i++) {
        out << *depositos[i];
    }
    
}

ostream & operator <<(ostream &out,const Armazem &a)
{
    a.escreve(out);
    return out;
}




#endif	/* _ARMAZEM_H */

