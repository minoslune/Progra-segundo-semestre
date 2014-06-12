#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
int counter = 1;
double factorial = 1;
double aproximacion=1;
double e = 1;
bool bandera=true;


while (bandera){

    factorial = factorial*counter;
    aproximacion = (1/factorial) + aproximacion;
    counter++;

    if((aproximacion-e) > 1e-9){
    e = aproximacion;
    }
    else{
        bandera = false;
    }
    }

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout << aproximacion << cout.precision(9) << endl;


    return 0;
}
