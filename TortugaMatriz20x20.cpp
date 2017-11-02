#include <iostream>

using namespace std;

void plumaHaciaArriba(int &pluma);
void plumaHaciaAbajo(int &pluma);
void girarIzquierda(int &frente);
void girarDerecha(int &frente);
void Avanzar(int frente, int r, int c, int &avance);
void guardarAvance(char matriz[][20], int tamano, int frente, int &r, int &c, int avance);
void ImprimirEscenario(char matriz[][20],int tamano);

int main()
{
    char escenario[20][20]={' '};
    int frente=6, avance=0;
    int r=0, c=0, comando=0, pluma=0;
    cout<<"EN ESTE PROGRAMA UNA TORTUGA SOSTIENE UNA PLUMA EN 2 POSICIONES\n";
    cout<<"ARRIBA PARA NO ESCRIBIR Y ABAJO PARA DINUJAR UNA LINEA, LA TORTUGA INICIA\n";
    cout<<"EN LA ESQUINA SUPERIOR IZQUIERDA DE LA PANTALLA MIRANDO HACIA LA DERECHA.\n";
    cout<<"UTILICE LOS COMANDOS SIGUIENTES PARA MANEJAR LA TORTUGA Y DIBUJAR ALGO...\n\n";
    do
    {
        cout<<"\n1.- PLUMA HACIA ARRIBA\n";
        cout<<"2.- PLUMA HACIA ABAJO\n";
        cout<<"3.- GIRAR A LA DERECHA\n";
        cout<<"4.- GIRAR A LA IZQUIERDA\n";
        cout<<"5.- CAMINAR UN ESPACIO\n";
        cout<<"6.- IMPRIMIR ESCENARIO\n";
        cout<<"7.- SALIR\n";
        cout<<"INTRODUCE UN COMANDO..: "; cin>>comando;

        switch (comando)
        {
        case 1:
            {
                plumaHaciaArriba(pluma);
                break;
            }
        case 2:
            {
                plumaHaciaAbajo(pluma);
                break;
            }
        case 3:
            {
                girarDerecha(frente);
                break;
            }
        case 4:
            {
                girarIzquierda(frente);
                break;
            }
        case 5:
            {
                cout<<"Cuntos pasos quieres avanzar..: "; cin>>avance;
                avance--;
                if (comando==5 && pluma==1)
                {
                    Avanzar(frente,r,c,avance);
                    guardarAvance(escenario,20,frente,r,c,avance);
                    cout<<r<<c;

                }
                else
                {
                    Avanzar(frente,r,c,avance);
                }
                break;
            }
        case 6:
            {
                ImprimirEscenario(escenario,20);
                break;
            }
        }
    }while(comando != 7);
    return 0;
}
void plumaHaciaArriba(int &pluma)
{
    pluma=0;
}
void plumaHaciaAbajo(int &pluma)
{
    pluma=1;
}
void girarIzquierda(int &frente)
{
    switch(frente)
    {
    case 2:
        {
            frente=6;
            break;
        }
    case 4:
        {
            frente=2;
            break;
        }
    case 6:
        {
            frente=8;
            break;
        }
    case 8:
        {
            frente=4;
            break;
        }
    }
}
void girarDerecha(int &frente)
{
    switch(frente)
    {
    case 2:
        {
            frente=4;
            break;
        }
    case 4:
        {
            frente=8;
            break;
        }
    case 6:
        {
            frente=2;
            break;
        }
    case 8:
        {
            frente=6;
            break;
        }
    }
}
void Avanzar(int frente, int r, int c,int &avance)
{
    switch (frente)
    {
    case 6:
        {
            avance+=c;
            if (avance>19)
                avance=19;
            break;
        }
    case 4:
        {
            avance-=c;
            if (avance<0)
                avance=0;
            break;
        }
    case 8:
        {
            avance-=r;
            if(avance<0)
                avance=0;
            break;
        }
    case 2:
        {
            avance+=r;
            if (avance>19)
                avance=19;
            break;
        }
    }
}
void ImprimirEscenario(char matriz[][20],int tamano)
{
    for(int r=0; r<tamano; r++)
    {
        for(int c=0; c<tamano; c++)
        {
            cout<<matriz[r][c];
        }
        cout<<endl;
    }
}
void guardarAvance(char matriz[][20], int tamano, int frente, int &r, int &c, int avance)
{
    if (frente==4 || frente==6)
    {
        if (avance>c)
        {
            for(int conta=c;conta<=avance;conta++)
            {
                if(matriz[r][conta]!='_' && matriz[r][conta]!='|')
                    matriz[r][conta]='_';
            }
        }
        else
        {
            for(int conta=c;conta>=avance;conta--)
            {
                if(matriz[r][conta]!='_' && matriz[r][conta]!='|')
                    matriz[r][conta]='_';
            }
        }
        c=avance;
    }
    else
    {
        if(avance>r)
        {
            for(int conta=r;conta<=avance;conta++)
            {
                if(matriz[conta][c]!='_' && matriz[conta][c]!='|')
                    matriz[conta][c]='|';
            }
        }
        else
        {
            for(int conta=r;conta>=avance;conta--)
            {
                if(matriz[conta][c]!='_' && matriz[conta][c]!='|')
                    matriz[conta][c]='|';
            }
        }
        r=avance;
    }
}
