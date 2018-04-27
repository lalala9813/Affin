#include <iostream>
#include "affin.h"

using namespace std;

int main()
{
    Affin a;
    //a.generarClaves();
    cout << a.cifrar("Renzo") << endl;
    string cifrado;
    cout << "Dame el cifrado -> ";
    getline(cin, cifrado);
    Affin b(a.Ta,a.b);
    cout << b.descifrar(cifrado);
    return 0;
}
