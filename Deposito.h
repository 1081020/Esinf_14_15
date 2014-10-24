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
private:


    string key;
    int npaletes;
    int maxcap;
    float totarea;

public:
    Deposito();
    Deposito(string k, int np, int mc, float ta);
    virtual Deposito *clone() const;
    virtual ~Deposito();

    string getKey() const;
    int getNpaletes() const;
    int getMaxcap() const;
    float getTotarea() const;

    void setKey(string k);
    void setNpaletes(int np);
    void setMaxcap(int mc);
    void setTotArea(float ta);


    virtual Deposito & operator = (const Deposito &d);

    virtual bool operator == (const Deposito &d) const;
    virtual void escreve(ostream& out) const;


};

Deposito::Deposito()
{

}

Deposito::Deposito(string k, int np, int mc, float ta)
{
    key = k;
    npaletes = np;
    maxcap = mc;
    totarea = ta;
}

Deposito *Deposito:: clone() const
{
    return new Deposito(*this);
}


Deposito:: ~Deposito()
{

}

//-------------- GET ---------------
string Deposito::getKey() const
{
    return key;
}

int Deposito::getNpaletes() const
{
    return npaletes;
}

int Deposito::getMaxcap() const
{
    return maxcap;
}

float Deposito::getTotarea() const
{
    return totarea;
}

//-------------- SET ---------------
void Deposito:: setKey(string k)
{
    key = k;
}

void Deposito:: setNpaletes (int np)
{
    npaletes = np;
}

void Deposito:: setMaxcap (int mc)
{
    maxcap = mc;
}

void Deposito:: setTotArea(float ta)
{
    totarea = ta;
}

//---------- Sobrecarga de operadores ------------

Deposito & Deposito::operator=(const Deposito &d)
{
    if(this!=&d) {
        setKey(d.getKey());
        setNpaletes(d.getNpaletes());
        setMaxcap(d.getMaxcap());
        setTotArea(d.getTotarea());
    }
    return *this;
}

bool Deposito:: operator == (const Deposito &d) const
{
    if(d.getKey() == key)
        return true;
    return false;
}

void Deposito::escreve(ostream& out) const {
    out << "Key: " << key << " | Nº Paletes: " << npaletes << " | MAX Capacity: " << maxcap << " | Total Área: " << totarea << "\n";
}

ostream & operator <<(ostream &out,const Deposito &d)
{
    d.escreve(out);
    return out;
}


#endif	/* _DEPOSITO_H */

