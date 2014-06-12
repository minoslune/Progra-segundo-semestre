#include <iostream>

int counter=1;
double factorial = 1;
double aproximacion=1;
double e = 1;
bool bandera=true;

using namespace std;

void factorialF(){
    factorial = factorial*counter;
    aproximacion = (1/factorial) + aproximacion;
    counter++;
    }

void aproximacionE(){
    factorialF();
if((aproximacion-e) > 1e-9){
    e = aproximacion;
    }else{
        bandera = false;
    }
    }

int main()
{
    while (bandera==true){
        aproximacionE();
    }
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout << aproximacion << cout.precision(9) << endl;
    return 0;
}
