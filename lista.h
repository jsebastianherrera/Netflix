#ifndef __LISTA_H
#define __LISTA_H
#include <stdlib.h>
#include <conio.h>

//HOL
template <class T>
struct TNodo
{
    T dato;
    struct TNodo<T> *sig;

};
template <class T>
void CrearLista(TNodo<T> **cab);

template <class T>
void DestruirLista(TNodo<T> **cab);

template <class T>
TNodo<T> *CrearNodo(T dato);

template <class T>
void InsertarFinal(TNodo<T> **cab, T dato);

template <class T>
void InsertarPrincipio(TNodo<T> **cab, T dato);

template <class T>
void Insertar(TNodo<T> **cab, T dato, int posi);

template <class T>
bool EliminarFinal(TNodo<T> **cab, T &dato);

template <class T>
bool EliminarPrincipio(TNodo<T> **cab, T &dato);

template <class T>
bool Eliminar(TNodo<T> **cab, T &dato, int posi);

template <class T>
int LongitudLista(TNodo<T> **cab);

template <class T>
bool ListaVacia(TNodo<T> **cab);


#endif

