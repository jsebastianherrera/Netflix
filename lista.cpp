#include "lista.h"
#include<iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
template <class T>
void CrearLista(TNodo<T> **cab)
{
    *cab=NULL;
}
template <class T>
void DestruirLista(TNodo<T> **cab)
{
    TNodo<T> *aux;
    aux=*cab;
    while (aux!=NULL)
    {
        *cab=(*cab)->sig;
        delete(aux);
        aux=*cab;
    }
}

template <class T>
TNodo<T> *CrearNodo(T dato)
{
    TNodo<T> *nuevo= new TNodo<T>();

    nuevo->sig=NULL;
    nuevo->dato=dato;
    return nuevo;
}

template <class T>
void InsertarFinal(TNodo<T> **cab, T dato)
{
    TNodo<T> *nuevo=CrearNodo(dato);
    TNodo<T> *aux;

    aux=*cab;
    if (*cab==NULL)
        *cab=nuevo;
    else
    {
        while (aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=nuevo;
    }
}

template <class T>
void InsertarPrincipio(TNodo<T> **cab, T dato)
{
    TNodo<T> *nuevo=CrearNodo(dato);
    nuevo->sig=*cab;
    *cab=nuevo;
}
template <class T>
void Insertar(TNodo<T> **cab, T dato, int posi)
{
    if (LongitudLista(&(*cab))>posi)
    {
        TNodo<T> *nuevo=CrearNodo(dato);
        int i;
        TNodo<T> *aux;

        aux=*cab;
        for (i=1; i<posi; i++)
            aux=aux->sig;
        nuevo->sig=aux->sig;
        aux->sig=nuevo;
    }
}

template <class T>
bool EliminarFinal(TNodo<T> **cab, T &dato)
{
    TNodo<T> *aux,*aux1;

    if (*cab!=NULL)
    {
        aux=*cab;
        aux1=aux;
        while (aux->sig!=NULL)
        {
            aux1=aux;
            aux=aux->sig;
        }
        aux1->sig=NULL;
        dato=aux->dato;
        delete(aux);
        return true;
    }
    return false;
}

template <class T>
bool EliminarPrincipio(TNodo<T> **cab, T &dato)
{
    TNodo<T> *aux,*aux1;

    if (*cab!=NULL)
    {
        aux=*cab;
        *cab=(*cab)->sig;
        dato=aux->dato;
        delete(aux);
        return true;
    }
    return false;
}

template <class T>
bool Eliminar(TNodo<T> **cab, T &dato, int posi)
{
    if (LongitudLista(&(*cab))>posi)
    {
        int i;
        TNodo<T> *aux,*aux1;

        aux=*cab;
        aux1=aux;
        for (i=1; i<posi; i++)
        {
            aux1=aux;
            aux=aux->sig;
        };
        dato=aux->dato;
        aux1->sig=aux->sig;
        delete(aux);
        return true;
    }
    return false;
}


template <class T>
int LongitudLista(TNodo<T> **cab)
{
    int cont=0;
    TNodo<T> *aux;

    aux=*cab;
    while (aux!=NULL)
    {
        aux=aux->sig;
        cont++;
    }
    return cont;
}

template <class T>
bool ListaVacia(TNodo<T> **cab)
{
    return *cab==NULL;
}
