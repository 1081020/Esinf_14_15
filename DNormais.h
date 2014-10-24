/* 
 * File:   DNormais.h
 * Author: OpticalZoom
 *
 * Created on 23 de Outubro de 2014, 22:36
 */

#ifndef _DNORMAIS_H
#define	_DNORMAIS_H


#include <list>
#include <vector>
#include <deque>
#include <Stack>
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
    DNormais(string k, int np, int mc, float ta);
    DNormais(const DNormais &dn);

    virtual DNormais *clone() const;
    virtual ~DNormais();

    void empilha(T);
    void desempilhar();
   // Listar(Deposito<T> & w);

    virtual void escreve(ostream& out) const;




    vector < stack <T> > getVet()
    {
        return palete;
    }

};


template<class T>
DNormais<T>:: DNormais(string k, int np, int mc, float ta): Deposito(k,np,mc,ta)
{
    ppares = mc;
    pimpares = mc/2;

}

template<class T>
DNormais<T>:: DNormais(const DNormais &dn) : Deposito (dn.getKey(), dn.getNpaletes(),dn.getMaxcap(),dn.getTotarea())
{

}

template<class T>
DNormais<T>::~DNormais()
{

}

template<class T>
DNormais<T>* DNormais<T>::clone() const
{
    return new DNormais(*this);
}





template<class T>
void DNormais<T>::empilha(T value){
    int tam = palete.size();
    if(tam==0){
        stack<T> st;
        palete.push_back(st);

    }else{
        if(palete[tam-1].size()>=5){
            stack<T> st;
            palete.push_back(st);
        }
    }

    palete[palete.size()-1].push(value);
}


template<class T>
void DNormais<T>::desempilhar()
{
    int tam = palete.size();
    if(tam<=0)
        return;

    palete[tam-1].pop();
    if(palete[tam-1].size()==0)
        palete.pop_back();
}

/*
template<class T>
void DNormais<T>::Listar(Deposito<T> & w){
    cout<<"\n\n------------------------------";
    vector<stack<T>> vector=w.getVet();
    for (int i = 0; i < vector.size; i++) {
        cout<<"\n["<<i<<"]";
        stack<T> s(vector[i]);
        while(!s.empty()){
            cout<<s.top()<<",";
            s.pop();
        }

    }
    //return out;

}
*/

template<class T>
void DNormais<T>::escreve(ostream& out) const {
    out << "\nDeposito de Normais: \n";
    Deposito::escreve(out);
        //return out;


}

#endif	/* _DNORMAIS_H */

