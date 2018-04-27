#include <iostream>
#include "affin.h"
#include <time.h>
#include "euclides.h"

using namespace std;

string Affin::alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.-_0123456789";

int Affin::generarClaves(){
    int Ta = 0;
    srand(time(NULL));
    Ta = rand()%66;
    while(euclides(Ta,alfabeto.size()) != 1)
    {
        Ta = rand()%66;
    }
    a = Ta;
    return a;
}

Affin::Affin(){
    srand(time(NULL));
    a = generarClaves();
    b = rand()%66;
    cout << a << " " << b << endl;
}

Affin::Affin(int a, int b){
    int inversa = euclidesPLUS(a,alfabeto.size());
    while(inversa < 0){
        inversa += alfabeto.size();
    }
    /*if(inversa < 0){
        inversa = inversa%alfabeto.size();
        inversa = alfabeto.size() - inversa;
    }*/
    Ta = inversa;
    this->b = b;
    cout << Ta << " " << b << endl;
}

string Affin::cifrar(string mensaje){
    string cifrado = "";
    for(int i = 0; i < mensaje.size(); i++)
    {
        int index = alfabeto.find(mensaje[i]);
        cifrado += alfabeto[(a*index + b) % alfabeto.size()];
    }
    return cifrado;
}

string Affin::descifrar(string cifrado)
{
    string descifrado = "";
    int index = 0;
    int o = 0;
    for(int i = 0; i < cifrado.size(); i++)
    {
        index = alfabeto.find(cifrado[i]);
        o = (Ta*abs((index - b))) % alfabeto.size();
        descifrado += alfabeto[(Ta*abs((index - b))) % alfabeto.size()];
        cout << "descifrado -> "<< descifrado << endl;
        cout << "Pos en el alf ->"<< o << endl;
        cout << "Buscador ->"<< index << endl;
    }
    return descifrado;
}




