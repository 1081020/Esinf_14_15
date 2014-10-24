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

    DFrescos d1("123456",3,3,3);
    DFrescos d2("8888",5,6,7);


    DNormais<char> d3("33434",2,3,4);


    arm1.insDepo(d1);
    arm1.insDepo(d2);
    arm1.insDepo(d3);

//    d3.empilha('a');
//
//    cout << d3;



//    if (d1 == d2)
//    {
//        cout << "Iguais \n";
//    }
//    else
//        cout << "Não Existe \n";
//


    cout << arm1;


   // return EXIT_SUCCESS;

};

