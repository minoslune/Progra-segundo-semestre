#include <iostream>
#include  <math.h>

using namespace std;

float tangente(float aSacarTangente){
float resultadoTangente;

resultadoTangente=(aSacarTangente*3.1416)/180;
resultadoTangente=tan(resultadoTangente);
return resultadoTangente;
}

float coseno(float aSacarCoseno){
float resultadoCoseno;

resultadoCoseno=(aSacarCoseno*3.1416)/180;
resultadoCoseno=cos(resultadoCoseno);
return resultadoCoseno;
}

int modulo(int primerNumero, int segundoNumero){
int resultadoModulo;

resultadoModulo=primerNumero%segundoNumero;
return resultadoModulo;
}

float elevar(float aSacarCuadrado, float potencia){
float resultadoElevacion;

resultadoElevacion=pow(aSacarCuadrado,potencia);
return resultadoElevacion;
}

float raiz(float aSacarRaiz){
float resultadoRaiz;

resultadoRaiz=sqrt(aSacarRaiz);
return resultadoRaiz;
}

float porcentaje(float porCiento, float total){
float resultadoPorcentaje;

resultadoPorcentaje=(total/100)*porCiento;
return porCiento;
}

float seno(float primerNumero){
float resultadoSeno;

resultadoSeno=(primerNumero*3.1416)/180;
resultadoSeno=sin(resultadoSeno);
return resultadoSeno;
}

float suma (float primerNumero, float segundoNumero){
float resultadoSuma;

resultadoSuma=primerNumero+segundoNumero;
return resultadoSuma;
}

float resta(float primerNumero, float segundoNumero){
float resultadoResta;

resultadoResta=primerNumero-segundoNumero;
return resultadoResta;
}

float division(float primerNumero, float segundoNumero){
float resultadoDivision;

resultadoDivision=primerNumero/segundoNumero;
return resultadoDivision;
}

float multiplicacion(float primerNumero, float segundoNumero){
float resultadoMultiplicacion;

resultadoMultiplicacion=primerNumero*segundoNumero;
return resultadoMultiplicacion;
}

int main()
{
short opcion;
float a;
float b;
float resultado;

cout << "Elija la operacion que desea realizar: "  << endl;
cout << "1.suma 2.resta 3.multiplicacion 4.division" << endl;
cout << "5.seno 6.coseno 7.tangente" << endl;
cout << "8.modulo 9.porcentaje 10.raiz  11.elevacion" << endl;

cin >> opcion;

switch(opcion){
case 1:
    cin >> a;
    cin >> b;
    resultado = suma(a,b);
    cout << "El resultado es: " << resultado << endl;
    break;

case 2:
    cin >> a;
    cin >>b;
    resultado= resta(a,b);
    cout << "El resultado es: " << resultado << endl;
    break;

case 3:
    cin >>a;
    cin >>b;
    resultado= multiplicacion(a,b);
    cout << "El resultado es: " << resultado << endl;
    break;

case 4:
    cin >>a;
    cin >>b;
    resultado= division(a,b);
    cout << "El resultado es: " << resultado << endl;
    break;

case 5:
    cin >> a;
    resultado= seno(a);
    cout << "El resultado es: " << resultado << endl;
    break;

case 6:
    cin >> a;
    resultado= coseno(a);
    cout << "El resultado es: " << resultado << endl;
    break;

case 7:
    cin >> a;
    resultado= tangente(a);
    cout << "El resultado es: " << resultado << endl;
    break;

case 8:
    cin >> a;
    cin >> b;
    resultado= modulo(a,b);
    cout << "El resultado es: " << resultado << endl;
    break;

case 9:
    cin >> a;
    cin >> b;
    resultado= porcentaje(a,b);
    cout << "El resultado es: " << resultado << endl;
    break;

case 10:
    cin >> a;
    resultado= raiz(a);
    cout << "El resultado es: " << resultado << endl;
    break;

case 11:
    cin >> a;
    cin >> b;
    resultado= elevar(a,b);
    cout << "El resultado es: " << resultado << endl;
    break;

}


    return 0;
}
