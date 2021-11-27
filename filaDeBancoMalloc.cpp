#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

//Estructura para la cola
struct persona{
    int num;
    struct persona *atras;
};

persona *inicioUno = NULL;
persona *inicioDos = NULL;
persona *inicioTres = NULL;
persona *inicioCuatro = NULL;
persona *inicioCinco = NULL;

int TiempoAleatorio(){//Funcion para la creacion de numeros pseudoaleatorios
    return((rand()%20)+1);
}

void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

int ColaAleatoria(){
    return(rand()%5);
}

void Aniadir_a_Cola(int fila){//Funcion para añadir personas a la cola N
    persona *nuevo, *aux;
    nuevo = (persona *)malloc(sizeof(persona));

    if(nuevo == NULL){
        cout << "\nError al reservar memoria" << endl;
        return;
    }

    nuevo->num = TiempoAleatorio();
    nuevo->atras = NULL;

    switch(fila){
        case 0:
            aux = inicioUno;
            if(inicioUno == NULL){
                inicioUno = nuevo;
            }else{
                while(aux->atras != NULL){
                    aux = aux->atras;
                }
                aux->atras = nuevo;
            }
            break;
        case 1:
            aux = inicioDos;
            if(inicioDos == NULL){
                inicioDos = nuevo;
            }else{
                while(aux->atras != NULL){
                    aux = aux->atras;
                }
                aux->atras = nuevo;
            }
            break;
        case 2: 
            aux = inicioTres;
            if(inicioTres == NULL){
                inicioTres = nuevo;
            }else{
                while(aux->atras != NULL){
                    aux = aux->atras;
                }
                aux->atras = nuevo;
            }
            break;
        case 3:
            aux = inicioCuatro;
            if(inicioCuatro == NULL){
                inicioCuatro = nuevo;
            }else{
                while(aux->atras != NULL){
                    aux = aux->atras;
                }
                aux->atras = nuevo;
            }
            break;
        case 4:
            aux = inicioCinco;
            if(inicioCinco == NULL){
                inicioCinco = nuevo;
            }else{
                while(aux->atras != NULL){
                    aux = aux->atras;
                }
                aux->atras = nuevo;
            }
            break;
        default:
            break;
    }
}

void Sacar_de_Cola(int fila){//Saca al primero de la fila N
    persona *aux;

    switch(fila){
        case 0:
            aux = inicioUno;
            inicioUno = inicioUno->atras;
            break;
        case 1:
            aux = inicioDos;
            inicioDos = inicioDos->atras;
            break;
        case 2:
            aux = inicioTres;
            inicioTres = inicioTres->atras;
            break;
        case 3:
            aux = inicioCuatro;
            inicioCuatro = inicioCuatro->atras;
            break;
        case 4:
            aux = inicioCinco;
            inicioCinco = inicioCinco->atras;
            break;
        default:
            break;
    }

    free(aux);
}

int Decision(){
    int decisionAleat = TiempoAleatorio();
    int decision;
    switch(decisionAleat){
        case 1:
            Aniadir_a_Cola(ColaAleatoria());
            break;
        case 2:
            Sacar_de_Cola(ColaAleatoria());
            break;
        case 3:
            cout << "\nSeguir ejecutando el programa? [Si=1/No=cualquier otro numero]: ";
            cin >> decision;
            return decision;
            break;
        default:
            break;
    }
return 1;}

void ImprimirColas(){
    bool primero=false;
    persona *aux;

    for(int i=0; i < 5; i++){
        switch(i){
            case 0:
                aux = inicioUno;
                primero = true;
                break;
            case 1:
                aux = inicioDos;
                primero = true;
                break;
            case 2:
                aux = inicioTres;
                primero = true;
                break;
            case 3:
                aux = inicioCuatro;
                primero = true;
                break;
            case 4:
                aux = inicioCinco;
                primero = true;
                break;
            default:
                break;
        }
        cout << "\n-------------------------------------------" << endl;
        cout << " o |"; 
        while(aux != NULL){
            if(primero){
                primero = false;
                cout << "*\t";
            }else{
                cout << "* ";
            }
            aux = aux->atras;
        }
        cout << "\n-------------------------------------------" << endl;
    }
}

void LiberarMemoria(){
    for(int i=0; i < 5; i++){
        switch(i){
            case 0:
                while(inicioUno!=NULL){
                    Sacar_de_Cola(i);
                }
                break;
            case 1:
                while(inicioDos!=NULL){
                    Sacar_de_Cola(i);
                }
                break;
            case 2:
                while(inicioTres!=NULL){
                    Sacar_de_Cola(i);
                }
                break;
            case 3:
                while(inicioCuatro!=NULL){
                    Sacar_de_Cola(i);
                }
                break;
            case 4:
                while(inicioCinco!=NULL){
                    Sacar_de_Cola(i);
                }
                break;
            default:
                break;
        }
    }
}

void clrscr(){
    system("@cls||clear");
}

int main(){

    int numero;
    srand((unsigned) time(NULL));

    clrscr();

    while(Decision()==1){
        ImprimirColas();
        delay(2);
        clrscr();
    }

    LiberarMemoria();

return 0;}
