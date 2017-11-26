#include <iostream>

using namespace std;

int factorial(int numero);

int main()
{
    int numero=0, factor=0;
    cout<<"ESTE PROGRAMA CALCULA EL FACTORIAL DE UN NUMERO"<<endl;
    cout<<"Dame un numero..: "; cin>>numero;
    factor=factorial(numero);
    cout<<"El factorial es..: "<< factor<<endl;
    return 0;
}
int factorial(int numero)
{
    if (numero==0)
        numero=1;
    else
        numero*=factorial(numero-1);
    return numero;
}
