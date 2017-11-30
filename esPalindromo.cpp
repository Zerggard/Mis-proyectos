#include <iostream>
#include <string.h>

using namespace std;

int esPalindromo(char cadena[], int inicio, int fin);

int main()
{
    int respuesta;
    char cadena[50];
    cout<<"Dame una palabra..: "; cin.getline(cadena,50,'n');
    respuesta=esPalindromo(cadena,0,strlen(cadena)-1);
    if(respuesta==0)
        cout<<"LA PALABRA NO ES PALINDROMO";
    else
        cout<<"LA PALABRA ES PALINDROMO";
    return 0;
}
int esPalindromo(char cadena[],int inicio, int fin)
{
    if(inicio<fin)
    {
        if(cadena[inicio]==' ')
        {
            return esPalindromo(cadena,++inicio,fin);
        }
        else if (cadena[fin]==' ')
        {
            return esPalindromo(cadena,inicio,--fin);
        }
        else if(cadena[inicio]==cadena[fin])
        {
            return esPalindromo(cadena,++inicio,--fin);
        }
        else
            return 0;
    }
    else
        return 1;
}
