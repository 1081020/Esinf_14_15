/* 
 * File:   DFrescos.h
 * Author: OpticalZoom
 *
 * Created on 23 de Outubro de 2014, 22:35
 */

#ifndef _DFRESCOS_H
#define	_DFRESCOS_H


#include "Deposito.h"

using namespace std;


class DFrescos: public Deposito
{
private:

//    int npaletes;
//    int maxcap;
//    float totarea;

//   stack <Produtos* > paletes;


    // stack <int> Palete;


public:
    DFrescos(string k, int np, int mc, float ta);
    DFrescos(const DFrescos &df);

    virtual DFrescos *clone() const;
    virtual ~DFrescos();

    virtual void escreve(ostream& out) const;


};

DFrescos:: DFrescos(string k, int np, int mc, float ta): Deposito(k,np, mc, ta)
{



}

DFrescos:: DFrescos(const DFrescos &df) : Deposito (df.getKey(), df.getNpaletes(),df.getMaxcap(),df.getTotarea())
{

}

DFrescos::~DFrescos()
{

}

DFrescos* DFrescos::clone() const
{
    return new DFrescos(*this); 
}

void DFrescos::escreve(ostream& out) const {
    out << "\nDeposito de Frescos: \n";
    Deposito::escreve(out);
}
#endif	/* _DFRESCOS_H */

