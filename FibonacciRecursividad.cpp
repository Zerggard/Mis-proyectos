#include <iostream>

using namespace std;

int fibonacci(int numero);

int main()
{
    int numero=0, resultado=0;
    cout<<"ESTE PROGRAMA CALCULA EL NUMERO FIBONACCI CORRESPONDIENTE A LA SECUENCIA INTRODUCIDA"<<endl;
    cout<<"Introduce el hasta que secuencia quieres llegar..: "; cin>>numero;
    resultado=fibonacci(numero);
    cout<<"El numero que corresponde a la secuencia es..: "<<resultado<<endl;
    return 0;
}
int fibonacci(int numero)
{
    if (numero==0||numero==1)
        return 1;
    else
        return fibonacci(numero-1)+fibonacci(numero-2);
}
