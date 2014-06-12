#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
//declaro las variables como globales para manipularlas con mayor facilidad
short opcion=2;
int apuesta=0;
short puntajeJugador=0;
short maquinaPuntaje=0;
short esElJugador=0;
short contador=0;

using namespace std;
//Este metodo elige un numero al azar entre el 0 y 4, después, dependiendo del numero lo transforma en un String.
string colorDePalo(){
short numeroColor=rand() % 4;
string color;
if(numeroColor==0){
    color = "Corazones";
}else if(numeroColor==1){
        color = "Espadas";
}else if(numeroColor==2){
    color="Diamantes";
}else if(numeroColor==3){
    color="Treboles";
}return color;
}
//Se obtiene una nueva carta
void nuevaCarta(int jugadorOMaquina){
short carta=1;
string cartaEspecial;
bool haycartaespecial=false;
short mazo[13];
for (int i=0;i<14;i++){
    mazo[i]=i;
}
//Gracias a esta randomizacion, se obtiene un numero del 1 al 13 representando la posicion de la carta, del az al rey, y luego se junta con un color.
// eliminando con éxito la necesidad de crear un array y salvando espacio en el proceso.
carta+=mazo[rand() % 13];

// Esta seccion valida la carta  para cambiar su valor dependiendo de si es un as, rey, reina o un jack
if(carta==11){
    carta=10;
    haycartaespecial=true;
    cartaEspecial="jack";
}if(carta==12){
haycartaespecial=true;
carta=10;
cartaEspecial="Reina";
}if(carta==13){
haycartaespecial=true;
carta=10;
cartaEspecial="Rey";
}if(jugadorOMaquina==0){
if(carta==1 && (puntajeJugador+11)<22){
    carta=11;
    haycartaespecial=true;
    cartaEspecial="As";
}else if(carta==1 && (puntajeJugador+11)>22){
    carta=1;
    haycartaespecial=true;
    cartaEspecial="As";
}
}else if(jugadorOMaquina==1){
if(carta==1 && (maquinaPuntaje+11)<22){
    carta=11;
    haycartaespecial=true;
    cartaEspecial="As";
}if(carta==1 && (maquinaPuntaje+11)>22){
    carta=1;
    haycartaespecial=true;
    cartaEspecial="As";
}
}if(jugadorOMaquina==0){
puntajeJugador+=carta;
}else if(jugadorOMaquina==1){
maquinaPuntaje+=carta;
}if(haycartaespecial==true){
    cout << "Ha obtenido un " << cartaEspecial << " De " << colorDePalo() << endl;
}else{
cout << "Ha obtenido un " << carta << " De " << colorDePalo() << endl;
}
}
//La máquina procesa quien ganara el juego, dependiendo cuantos puntos obtuvieron de sus cartas.
void determinarGanador(){
esElJugador=1;
string ganador;
bool numeroGanador=false;

cout << "La casa " << endl;
nuevaCarta(esElJugador);
nuevaCarta(esElJugador);
menorQueQuince: if(maquinaPuntaje<15){
    nuevaCarta(esElJugador);
    goto menorQueQuince;
}
//Se determina el ganador con un true para el player y un false para la máquina
if (puntajeJugador==maquinaPuntaje || (puntajeJugador> 21 && maquinaPuntaje> 21)){
    ganador="Empate!";
    apuesta=0;
}else if((puntajeJugador>maquinaPuntaje) && puntajeJugador<=21){
    ganador="Gana Usted!";
    numeroGanador=true;
}else if(puntajeJugador<maquinaPuntaje && maquinaPuntaje<=21){
    ganador="Gana la casa!";
}else if(puntajeJugador>21){
    ganador="Gana la casa";
}else if(maquinaPuntaje>21){
    ganador="Gana usted!";
    numeroGanador=true;
}
cout << "Usted tiene " << puntajeJugador << "La casa tiene " << maquinaPuntaje << endl;
cout << ganador << endl;
if(apuesta>0 && numeroGanador==true){
        if(puntajeJugador==21 && numeroGanador==true){
            apuesta=apuesta*1.5;
        }
    cout << "El ganador se ha llevado " << apuesta*2 << endl;
}
}
// se  obtiene una carta extra.
void jalarCarta(){
    nuevaCarta(esElJugador);
}
//Contiene todas las funciones del juego de blackjack, de aquí se llaman, primariamente.
void blackjack(){
esElJugador=0;
puntajeJugador=0;
maquinaPuntaje=0;
cout << "Desea apostar? 1.si 2.no" << endl;
cin >> opcion;
if(opcion==1){
    cout << "Cuanto desea apostar?" << endl;
    cin >> apuesta;
}cout << "2 cartas para cada jugador" << endl;
nuevaCarta(esElJugador);
nuevaCarta(esElJugador);
opcion=0;
unaCartaMas: cout << "Desea una carta mas? 1.Si 2.No" << endl;
cin >> opcion;
if(opcion==1){
    jalarCarta();
    goto unaCartaMas;
}
if(opcion==2){
    determinarGanador();
}
}
//determina el ganador del juego de lanzar dados de acuerdo a sus puntos.
void ganadorDados(short dadoJugador, short maquinaDado){
if (dadoJugador==maquinaDado){
    cout << "Empate!" << endl;
}else if (dadoJugador >  maquinaDado){
cout << "Ha ganado usted!" << endl;
}else if(dadoJugador<maquinaDado){
cout << "Ha ganado la maquina "<< endl;
}
}
// este metodo lanza los dados y luego, dependiendo de en que cara cayeron, determina el ganador.
void dados(){
short option;
    cout << "Presione 1 para su dado, la maquina lo lanzara al mismo tiempo " << endl;
    cin >> option;
if(option==1){
short dadoJugador=(rand() % 6)+1;
short maquinaDado= (rand() % 6)+1;
cout << "Ha obtenido un " << dadoJugador << "Y la casa ha obtenido un " << maquinaDado << endl;
ganadorDados(dadoJugador, maquinaDado);
}
}
//el método main contiene la estructura del programa y llama a las funciones cuando se requiera.
int main()
{
    srand(time(0));
    menu: cout << "Bienvenido al casino Royale. Elija su juego. 1.Blackjack 2.Dados 3.Salir" << endl;
    cin >> opcion;
    switch(opcion){
case 1:
    deNuevo: blackjack();
    cout << "Desea jugar de nuevo? 1.Si 2.No " << endl;
    cin >> opcion;
if (opcion==1){
    goto deNuevo;
}else if(opcion==2){
    goto menu;
}break;
case 2:
    short jugarDenuevo;
    dadosDeNuevo: dados();
    cout << "Desea jugar de nuevo? 1.Si 2.No" << endl;
    cin >> jugarDenuevo;
    if (jugarDenuevo==1){
        goto dadosDeNuevo;
    }else if(jugarDenuevo==2){
    goto menu;
    }break;
case 3:
    return 0;
    }
    return 0;
}
