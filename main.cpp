#include "mbed.h"
 
/*
   Maquina sencilla de dos estados. Estado ledApagado y estado ledEncendido.
   El led se tiene que encender durante dos segundos cuando se pulse 
   El boton de la placa funciona por nivel bajo
*/
enum estados {nopulsado, pulsado} estado;
 
Timer temporizador;
 
 
DigitalOut led(LED1);
DigitalIn boton(PC_13);
 
void estadoNoPulsado()
{
    if(boton==0) {
        estado=pulsado;
    }
}
 
void estadoPulsado()
{
    if(boton==1) {
        led=!led;
        estado=nopulsado;
    }
}
 
int main()
{
    led=0;
    estado=nopulsado;
    while(1) {
        switch(estado) {
            case nopulsado:
                estadoNoPulsado();
                break;
            case pulsado:
                estadoPulsado();
                break;
        }
 
    }
}