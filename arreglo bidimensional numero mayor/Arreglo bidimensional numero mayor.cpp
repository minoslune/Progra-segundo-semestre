#include <iostream>

using namespace std;

int main()
{
    int matrizDeNumeros[4][5];

    matrizDeNumeros[0][0]=16;
    matrizDeNumeros[0][1]=22;
    matrizDeNumeros[0][2]=99;
    matrizDeNumeros[0][3]=4;
    matrizDeNumeros[0][4]=18;
    matrizDeNumeros[1][0]=-258;
    matrizDeNumeros[1][1]=4;
    matrizDeNumeros[1][2]=101;
    matrizDeNumeros[1][3]=5;
    matrizDeNumeros[1][4]=98;
    matrizDeNumeros[2][0]=105;
    matrizDeNumeros[2][1]=6;
    matrizDeNumeros[2][2]=15;
    matrizDeNumeros[2][3]=2;
    matrizDeNumeros[2][4]=45;
    matrizDeNumeros[3][0]=33;
    matrizDeNumeros[3][1]=88;
    matrizDeNumeros[3][2]=72;
    matrizDeNumeros[3][3]=16;
    matrizDeNumeros[3][4]=3;
    int maximumNumber=matrizDeNumeros[0][0];
    int fila=0;
    int columna=0;

    for (int i=0; i<4; i++)
        for (int j=0; j<5; j++)
        {
            if(matrizDeNumeros[i][j]> maximumNumber )
            maximumNumber= matrizDeNumeros[i][j];
            fila = i;
            columna = j;
        }

        cout << "El numero maximo es " << maximumNumber << " Su fila es  " << fila << " y su columna es " << columna << endl;

    return 0;
}
