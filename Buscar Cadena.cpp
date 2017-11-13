#include <iostream>
#include <string.h>

using namespace std;

int buscar(char texto[],char cadena[]);

int main()
{
    char cadena[20], texto[200]={"Los valores son las reglas de conducta y actitudes según las cuales nos comportarnos"};
    cout<<texto;
    cout<<"Dame la palabra a buscar..: "; cin>>cadena;
    int posicion=buscar(texto,cadena);
    if (posicion==1)
        cout<<"La palabra no se encontro en el texto";
    else
        cout<<"La palabra comienza en la posicion..: "<<posicion;
    return 0;
}
int buscar(char texto[], char cadena[])
{
    int conta=0, conta2=0;
    for(;conta<=strlen(texto);)
    {
        if(cadena[conta2]==texto[conta])
        {
            conta++, conta2++;
            if(conta2==strlen(cadena))
                return (conta-conta2);
        }
        else
        {
            if (conta2==0)
                conta++;
            else
                conta+=conta2-1, conta2=0;
        }
    }
    return 1;
}
