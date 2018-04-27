#ifndef AFFIN_H_INCLUDED
#define AFFIN_H_INCLUDED

using namespace std;

class Affin
{
public:
    int a;
    int b;
    int Ta;
public:
    static string alfabeto;
    int generarClaves();
    string cifrar(string);
    string descifrar(string);
    Affin();
    Affin(int a, int b);
};

#endif // AFFIN_H_INCLUDED
