//Desarrollado por:
//Maria Camila Aguirre Collante - Luis Felipe Ayala - Sebastián Herrera G
//Librerias
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<cmath>
#include <conio.h>
#include <windows.h>
#include "Lista.cpp"
using namespace std;
//Declaración de estructuras
struct Peliculas
{
    long int Codigo;
    char Titulo[25], Resumen[200], Duracion[20], Genero[50];
    int Reproducciones;
    bool Estado;
    int calificacion;
    int calif,Cant;
};
struct Usuario
{
    char TipoCuenta;
    char Usuario[50];
    char Contrasena[50];

};
struct Recomendacion
{
    char Usuario[50];
    char Genero[50];
};
struct PeliculasVistas
{
    char Titulo [25], Genero [50];
    long int codigo;
    int califi;
    char Usuario[20];
};
struct Plataforma
{
    TNodo<struct Peliculas> *ListaPeliculas;
    TNodo<struct Usuario> *ListaUsuarios;
};
TNodo<struct Peliculas> *Temp;
//FUNCIONES ADICIONALES
void Proof();
void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void leerPasw(char frase[])
{
    int i = 0;
    cout.flush();
    do
    {
        frase[i] = (unsigned char)_getch();

        if (frase[i] != 8) // no es retroceso
        {
            cout << '*'; // muestra por pantalla
            i++;
        }
        else if (i > 0) // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--; //el caracter a borrar e el backspace
        }
        cout.flush();

    }
    while (frase[i - 1] != 13);   // si presiona ENTER

    frase[i - 1] = NULL;
    cout << endl;
}
//FUNCIONES GENERICAS
void OrdenFile(TNodo<struct PeliculasVistas> *Aux1);
void OrdenarArchivo();
/*
Objetivo: Imprimir la primera pantalla (Registarse o Iniciar sesión)
Entrada: N/A
Salida: N/A
*/
void FirstScreen();
/*
Objetivo: Permitir al usuario registrarse, es decir, le permite crear su usuario y contraseña.
Entradas: N/A
Salidas: N/A
*/
void Registrarse();
/*
Objetivo: Validar el inicio de sesión
Entrada: Arreglo de caracteres con el nombre del usuario
Salida: Retornar Verdadero si encontro el usuario o falso si el usuario no existe en archivo de usuarios.
*/
bool IniciarSesion(char *);
/*
Objetivo: Valida si un usuario ya existe
Entrada: Arreglo de caracteres con el nombre del usuario
Salida: Retornar Verdadero si encontro el usuario ya registrado o falso si el usuario no existe.
*/
bool Validar(char *);
bool ValidarCodigo(long int);
struct Plataforma Moviez();
//FUNCIONES DE IMPRESION
void Graficas();
/*
Objetivo: Imprimir las películas que están guardadas en el archivo
Entradas: N/A
Salidas: N/A
*/
void ListaPeliculas();
void PrintUsuario();
/*
Objetivo: Imprimir la lista de usuarios que se encuentren el archivo
Entradas: N/A
Salidas: N/A
*/
void ListaUsuarios();
/*
Objetivo: Imprimir las peliculas que tiene en común la palabra clave ingresada
Entradas: Lista de peliculas
Salidas: N/A
*/
void PrintPalabraClave(TNodo<struct Peliculas> *Lista, char*);
//FUNCIONES ADMINISTRADOR
/*
Objetivo: Muestra la pantalla del administrador, las funciones que solo tiene él.
Entradas: N/A
Salidas: N/A
*/
void AdminScreen();
/*
Objetivo: Permite ingresar y guardar las películas en el archivo
Entradas: N/A
Salidas: N/A
*/
void LeerPelis();
/*
Objetivo: Modificar una película que exista dentro del archivo
Entradas: N/A
Salidas: N/A
*/
void ModificarPeli();
/*
Objetivo: Eliminar una película existente en el archivo
Entradas: N/A
Salidas: N/A
*/
void EliminarPeli();
//FUNCIONES USUARIO
void peliculasUsuarios(char*Usu,TNodo<struct Peliculas> *Lista);
void AlmacenarReco(char Genero[50], char Usuario[50]);
void imprimirRecomendaciones(char Nombre[50]);
void Calificacion(int code,bool acepto,int califica);
void UserPelis(char *Usu,TNodo<struct Peliculas>*Vistas);
/*
Objetivo: Mostrar la pantalla del usuario (las funciones que puede realizar).
Entradas: Nombre del Usuario
Salidas: N/A
*/
void UserScreen(char *);
/*
Objetivo: Busca una película dentro del archivo de películas.
Entradas: Nombre de la pelicula
Salidas: N/A
*/
void BuscarPelicula(char *,char*);
void Ordenar(TNodo<struct Peliculas> **ListaPeliculas, char criterio);
int main()
{
    FirstScreen();
}
//FUNCIONES DE IMPRESION
void ListaPeliculas()
{
    struct Plataforma Pelis;
    Pelis = Moviez();
    char respuesta;
    int contador = 0;
    int auxContador = 0;
    int paginacion = 0;
    TNodo<struct Peliculas> *auxListaPelis = Pelis.ListaPeliculas;
    if(ListaVacia(&auxListaPelis)==true)
        return;
    int Longitud = LongitudLista(&auxListaPelis);
    char criterio, opcion;
    cout << char(168) << "Desea verlas en alg"<< char(163) << "n orden? (S/N) ->";
    cin >> opcion;

    if (opcion == 'S' || opcion == 's')
    {
        system("cls");
        gotoxy(50, 0);
        cout << "Criterios de ordenamiento " << endl;
        cout << "\nG: G"<< char(130) << "nero. " << endl;
        cout << "T: T"<< char(161) << "tulo. " << endl;
        cout << "D: Duraci"<< char(162) << "n. " << endl;
        cout << "\nOrdenar por: ";
        cin >> criterio;
        switch (criterio)
        {
        case 'G':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 'D':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 'T':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 'g':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 'd':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 't':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        default:
            cout << char(173) << "Criterio incorrecto!" << endl;
        }
    }
    do
    {
        if (respuesta == 'r')
        {
            if (auxContador % 10 == 0)
                auxContador = auxContador - 10;
            paginacion = 10 * (auxContador / 10);
            auxContador = paginacion;
            auxListaPelis = Pelis.ListaPeliculas;

            while (auxContador > 10)
            {
                auxListaPelis = auxListaPelis->sig;
                auxContador--;
            }
            auxContador = 0;
            contador = 0;
        }
        else
            contador = 0;
        while (contador < 10 && auxListaPelis != NULL)
        {
            cout << "----------------------------------------------" << endl;
            cout << "Pel"<< char(161) << "cula -----:" << (auxListaPelis->dato).Titulo << "   "
                 << "" << (auxListaPelis->dato).Codigo << "" << endl;
            cout << "G"<< char(130) << "nero -----: " << (auxListaPelis->dato).Genero << endl;
            cout << "Resumen -----: \t" << (auxListaPelis->dato).Resumen << endl;
            cout << "Duraci"<< char(162) << "n -----: " << (auxListaPelis->dato).Duracion << endl;
            cout << "Reproducciones -----: " << (auxListaPelis->dato).Reproducciones << endl;
            auxListaPelis = auxListaPelis->sig;
            contador++;
        }
        auxContador += contador;
        if (auxContador == Longitud)
        {
            cout << "\nSe encuentra en la "<< char(163) << "ltima p"<< char(160) << "gina !" << endl;
            cout << "\nPresione 'r' para retroceder o 'e' para salir: ";
            cin >> respuesta;
            if (respuesta == 's')
                respuesta = 'r';
        }
        else
        {
            cout << "\nPresione 's' para continuar,'r' para retroceder o 'e' para salir: ";
            cin >> respuesta;
        }
        system("cls");
    }
    while (respuesta != 'e');
}
void ListaUsuarios()
{
    struct Usuario User;
    int i = 0;
    ifstream Leer("Usuarios.dat", ios::binary);
    if (Leer)
    {
        cout << "\t\t LISTA USUARIOS " << endl;
        while (!Leer.eof())
        {
            if (Leer.read((char *)&User, sizeof(User)))
            {
                cout << "----------------------------------------";
                cout << "\nUsuario -----: " << User.Usuario << endl;
                cout << "Password -----: " << User.Contrasena << endl
                     << endl;
            }
        }
        Leer.close();
    }
    else
        cout << "El archivo no se pudo abrir!" << endl;
}
//FUNCIONES GENÉRICAS
void FirstScreen()
{
    int opcion = -1;
    char Usuario[10];
    bool Encontro;
    struct Usuario RegUsu;
    while (opcion != 3)
    {
        system("cls");
        gotoxy(50, 1);
        cout << "WELCOME TO MOVIEZ+" << endl
             << endl;
        cout << "1. Registrarse" << endl;
        cout << "2. Iniciar sesi"<< char(162) << "n" << endl;
        cout << "3. Salir" << endl
             << endl;
        cout << "Ingrese su opci"<< char(162) << "n -> ";
        cin >> opcion;
        switch (opcion)
        {
        case 0:
            system("cls");
            ListaUsuarios();
            system("pause");
            system("cls");
            break;
        case 1:
            system("cls");
            cout << "\t\t\tREGISTRO" << endl
                 << endl;
            Registrarse();
            system("pause");
            break;
        case 2:
        {
            bool Temp=false;
            char User_Name[20];
            system("cls");
            Encontro = IniciarSesion(Usuario);
            strcpy(User_Name,Usuario);
            ifstream FileUser("Usuarios.dat",ios::binary);
            system("cls");
            if(FileUser)
            {
                if (Encontro == true)
                {
                    cout << "Iniciando sesi"<< char(162) << "n.";
                    Sleep(300);
                    cout << ".";
                    Sleep(300);
                    cout << ".";
                    Sleep(400);
                    system("cls");
                    ifstream Usu("Usuarios.dat",ios::binary);
                    if(Usu)
                    {
                        while(!Usu.eof() && Temp==false)
                        {
                            if(Usu.read((char*)&RegUsu,sizeof(RegUsu)))
                            {
                                if(strcmp(RegUsu.Usuario,User_Name)==0)
                                {
                                    if (RegUsu.TipoCuenta=='a' ||RegUsu.TipoCuenta=='A' )
                                    {
                                        AdminScreen();
                                        Temp=true;
                                    }
                                    else if(RegUsu.TipoCuenta=='u' ||RegUsu.TipoCuenta=='U' )
                                    {
                                        UserScreen(Usuario);
                                        Temp=true;
                                    }
                                }
                            }
                        }
                    }
                    else
                        cout<<" El archivo no existe !"<<endl;
                }
                else
                    cout << "\n" << char(173) <<  "La informaci"<< char(162) << "n no coincide!" << endl;
            }
            else
                cout<<"\tEl archivo no existe !"<<endl;
            system("pause");
            break;
        }
        case 3:
            return;
            break;
        }
    }
}
void Registrarse()
{
    struct Usuario New;
    struct Peliculas Temp;
    char Usu[20];
    bool Encontro;
    ofstream User("Usuarios.dat", ios::binary | ios::app);
    cout<<"Tipo de usuario (Admin(A)/User(U)) -> ";
    cin>>New.TipoCuenta;
    cout << "Nombre de usuario -> ";
    cin >> New.Usuario;
    strcpy(Usu, New.Usuario);
    Encontro = Validar(Usu);
    if (Encontro == false)
    {
        if (User)
        {
            cout << "Password -> ";
            leerPasw(New.Contrasena);
            User.write((char *)&New, sizeof(New));
            User.close();
        }
        else
            cout << char(173) <<  "No se pudo abrir el archivo!" << endl;
    }
    else
    {
        cout << char(173) <<  "El usuario ya est"<< char(160) << " en uso!" << endl;
        system("pause");
        system("cls");
        Registrarse();
    }
}
bool Validar(char *Usu)
{
    struct Usuario Reg;
    ifstream User("Usuarios.dat", ios::binary);
    if (User)
    {
        while (!User.eof())
        {
            if (User.read((char *)&Reg, sizeof(Reg)))
            {
                if (strcmp(Usu, Reg.Usuario) == 0)
                    return true;
            }
        }
        User.close();
        return false;
    }
    else
        cout << char(173) <<  "No se pudo abrir el archivo!" << endl;
}
bool IniciarSesion(char *Usuario)
{
    struct Usuario UserN;
    struct Usuario RegU;
    bool Encontro = false, Pass = false;
    ifstream ArchivoU("Usuarios.dat", ios::binary | ios::in);
    if (ArchivoU)
    {
        cout << "\n\t\t\tINICIO DE SESI"<< char(224) << "N" << endl;
        cout << "\nUsername -> ";
        cin >> UserN.Usuario;
        cout << "Password-> ";
        leerPasw(UserN.Contrasena);
        UserN.TipoCuenta = 'u';
        while (!ArchivoU.eof() && !Encontro && !Pass)
        {
            if (ArchivoU.read((char *)&RegU, sizeof(RegU)))
            {
                if (strcmp(UserN.Usuario, RegU.Usuario) == 0)
                {
                    Encontro = true;
                    strcpy(Usuario, UserN.Usuario);
                }
                if (strcmp(UserN.Contrasena, RegU.Contrasena) == 0)
                    Pass = true;
            }
        }
        ArchivoU.close();
    }
    else
        cout << char(173) <<  "No se pudo abrir el archivo!" << endl;

    if (Pass == true && Encontro == true)
        return true;
    else
        return false;
}
//Struct Plataforma guarda todos los datos que esten en el archivo en sus respectivas listas
struct Plataforma Moviez()
{
    ifstream Peliculas("Peliculas.dat", ios::binary | ios::in);
    ifstream Usuarios("Usuarios.dat", ios::binary | ios::in);
    TNodo<struct Peliculas> *ListaPeliculas;
    CrearLista(&ListaPeliculas);
    TNodo<struct Usuario> *ListaUsuarios;
    CrearLista(&ListaUsuarios);
    struct Plataforma Moviez;
    struct Peliculas Pelis;
    struct Peliculas RegP;
    struct Usuario User;
    struct Usuario RegU;
    if (Peliculas)
    {
        while (!Peliculas.eof())
        {
            if (Peliculas.read((char *)&RegP, sizeof(RegP)))
            {
                Pelis = RegP;
                InsertarFinal(&ListaPeliculas, Pelis);
            }
        }
        Peliculas.close();
    }
    else
        cout << char(173) <<  "El archivo de pel"<< char(161) << "culas no existe!" << endl;
    /***************************************************************************************/
    if (Usuarios)
    {
        while (!Usuarios.eof())
        {
            if (Usuarios.read((char *)&RegU, sizeof(RegU)))
            {
                User = RegU;
                InsertarFinal(&ListaUsuarios, User);
            }
        }
        Usuarios.close();
    }
    else
        cout << char(173) << "El archivo de pel"<< char(161) << "culas no existe!" << endl;
    Moviez.ListaPeliculas = ListaPeliculas;
    Moviez.ListaUsuarios = ListaUsuarios;
    return Moviez;
}
//FUNCIONES ADMINISTRADOR
void AdminScreen()
{
    int opcion = -1;
    cout << char(173) <<  "Bienvenido de nuevo Admin!" << endl;
    Sleep(800);
    while (opcion != 5)
    {
        system("cls");
        cout << "\tMENU " << endl
             << endl;
        cout << "1. Agregar pel"<< char(161) << "culas" << endl;
        cout << "2. Lista pel"<< char(161) << "culas" << endl;
        cout << "3. Modificar pel"<< char(161) << "cula" << endl;
        cout << "4. Borrar pel"<< char(161) << "cula" << endl;
        cout << "5. Ver gr"<< char(160) << "ficas" << endl;
        cout << "6. Salir" << endl;
        cout << "\nIngrese una opci"<< char(162) << "n -> ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("cls");
            LeerPelis();
          //  system("pause");
            break;
        case 2:
            system("cls");
            ListaPeliculas();
            _getch();
            break;
        case 3:
            system("cls");
            ModificarPeli();
            break;
        case 4:
            system("cls");
            EliminarPeli();
            system("pause");
            break;
        case 5:
            system("cls");
            Graficas();
            getch();
            opcion=7;
            break;
        case 6:
            return;
        case 7:
        default:
            cout << char(173) << "Opci"<< char(162) << "n incorrecta!" << endl;
        }
    }
}
void LeerPelis()
{
    struct Peliculas LeerPelis;
    bool Validar;
    int cod;
    ofstream Leer("Peliculas.dat", ios::binary | ios::app);
    if (Leer)
    {
        cout << "\t\t INSERTAR PEL"<< char(214) << "CULA " << endl
             << endl;
        cout << "C"<< char(162) << "digo -> ";
        cin >> LeerPelis.Codigo;
        cin.ignore();
        cod = LeerPelis.Codigo;
        Validar = ValidarCodigo(cod);
        if (Validar != false)
        {
            cout  << char(173) << "La pel"<< char(161) << "cula ya existe en nuestro repertorio!" << endl;
            return;
        }
        cout << "T"<< char(161) << "tulo -> ";
        cin.getline(LeerPelis.Titulo, sizeof(LeerPelis.Titulo));
        cout << "Resumen -> ";
        cin.getline(LeerPelis.Resumen, sizeof(LeerPelis.Resumen));
        cout << "Duraci"<< char(162) << "n -> ";
        cin.getline(LeerPelis.Duracion, sizeof(LeerPelis.Duracion));
        cout << "G"<< char(130) << "nero -> ";
        cin.getline(LeerPelis.Genero, sizeof(LeerPelis.Genero));
        LeerPelis.Reproducciones=0;
        LeerPelis.calificacion=0;
        LeerPelis.calif=-1;
        LeerPelis.Cant=0;
        LeerPelis.Estado=false;
        Leer.write((char *)&LeerPelis, sizeof(LeerPelis));
        Leer.close();
        cout << "Pel"<< char(161) << "cula ingresada." << endl;
    }
    else
        cout << "No se pudo abrir el archivo" << endl;
}
bool ValidarCodigo(long int codigo)
{
    struct Peliculas Reg;
    ifstream User("Peliculas.dat", ios::binary);
    if (User)
    {
        while (!User.eof())
        {
            if (User.read((char *)&Reg, sizeof(Reg)))
            {
                if (codigo == Reg.Codigo)
                    return true;
            }
        }
        User.close();
        return false;
    }
    else
        cout << char(173) <<  "No se pudo abrir el archivo!" << endl;
}
void ModificarPeli()
{
    struct Peliculas RegPelis;
    struct Peliculas AuxReg;
    int opcion = 0;
    bool Encontro = false;
    char Titulo[20];
    fstream Archivo("Peliculas.dat", ios::binary | ios::in | ios::out);
    if (Archivo)
    {
        cin.ignore();
        cout << "Pel"<< char(161) << "cula a modificar -> ";
        cin.getline(Titulo, sizeof(Titulo));
        strupr(Titulo);
        while (!Archivo.eof())
        {
            if (Archivo.read((char *)&RegPelis, sizeof(RegPelis)))
            {
                AuxReg = RegPelis;
                strupr(AuxReg.Titulo);
                if (strcmp(AuxReg.Titulo, Titulo) == 0)
                    Encontro = true;
                if (Encontro == true)
                {
                    while (opcion != 6)
                    {
                        system("cls");
                        gotoxy(50, 0);
                        cout << "Informaci"<< char(162) << "n pelicula " << endl;
                        cout << "\nPel"<< char(161) << "cula -----:" << RegPelis.Titulo << "   "
                             << "*" << RegPelis.Codigo << "*" << endl;
                        cout << "G"<< char(130) << "nero -----: " << RegPelis.Genero << endl;
                        cout << "Resumen -----: \t" << RegPelis.Resumen << endl;
                        cout << "Duraci"<< char(162) << "n -----: " << RegPelis.Duracion << endl;
                        cout << "Reproducciones -----: " << RegPelis.Reproducciones << endl
                             << endl;
                        gotoxy(50, 10);
                        cout << "MODIFICANDO" << endl;
                        gotoxy(47, 11);
                        cout << "<<" << RegPelis.Titulo << ">>" << endl
                             << endl;
                        cout << "1. C"<< char(162) << "digo" << endl;
                        cout << "2. T"<< char(161) << "tulo" << endl;
                        cout << "3. Resumen" << endl;
                        cout << "4. Duraci"<< char(162) << "n" << endl;
                        cout << "5. G"<< char(130) << "nero" << endl;
                        cout << "6. Salir" << endl;
                        cout << "\nIngrese su opci"<< char(162) << "n -> ";
                        cin >> opcion;
                        switch (opcion)
                        {
                        case 1:
                            cout << "Nuevo c"<< char(162) << "digo -> ";
                            cin >> RegPelis.Codigo;
                            cin.ignore();
                            cout << char(173) <<  "Registro actualizado!" << endl;
                            Sleep(500);
                            break;
                        case 2:
                            cin.ignore();
                            cout << "Nuevo t"<< char(161) << "tulo -> ";
                            cin.getline(RegPelis.Titulo, sizeof(RegPelis.Titulo));
                            cout << char(173) <<  "Registro actualizado!" << endl;
                            Sleep(500);
                            break;
                        case 3:
                            cin.ignore();
                            cout << "Nuevo Resumen -> ";
                            cin.getline(RegPelis.Resumen, sizeof(RegPelis.Resumen));
                            cout << char(173) << "Registro actualizado!" << endl;
                            Sleep(500);
                            break;
                        case 4:
                            cin.ignore();
                            cout << "Nueva duraci"<< char(162) << "n -> ";
                            cin.getline(RegPelis.Duracion, sizeof(RegPelis.Duracion));
                            cout << char(173) << "Registro actualizado!" << endl;
                            Sleep(500);
                            break;
                        case 5:
                            cin.ignore();
                            cout << "Nuevo g"<< char(130) << "nero -> ";
                            cin.getline(RegPelis.Genero, sizeof(RegPelis.Genero));
                            cout << char(173) << "Registro actualizado!" << endl;
                            Sleep(500);
                            break;
                        case 6:
                            system("pause");
                            break;
                        }
                        Archivo.seekg((int)((-1) * sizeof(RegPelis)), ios::cur);
                        Archivo.write((char *)&RegPelis, sizeof(RegPelis));
                    }
                }
            }
        }
        if (Encontro == false)
        {
            cout << "\t" << char(173) <<  "No se encontr"<< char(162) << " el t"<< char(161) << "tulo que buscaba!" << endl;
            Sleep(2000);
        }
        Archivo.close();
    }
    else
        cout << char(173) << "No se pudo abrir el archivo!" << endl;
    getch();
}
void EliminarPeli()
{
    struct Peliculas Peliculas;
    struct Peliculas AuxP;
    ofstream RegAux("Auxiliar.dat", ios::binary | ios::app);
    fstream RegPelis("Peliculas.dat", ios::binary | ios::in);
    char N_Pelicula[20], rta;
    bool Encontro = false;

    if (RegPelis)
    {
        gotoxy(50, 0);
        cout << "ELIMINAR PEL"<< char(214) << "CULA " << endl;
        cin.ignore();
        cout << "Nombre pel"<< char(161) << "cula -> ";
        cin.getline(N_Pelicula, sizeof(N_Pelicula));
        strupr(N_Pelicula);
        while (!RegPelis.eof())
        {
            if (RegPelis.read((char *)&Peliculas, sizeof(Peliculas)))
            {
                AuxP = Peliculas;
                strupr(AuxP.Titulo);
                if (strcmp(AuxP.Titulo, N_Pelicula) == 0)
                {
                    Encontro = true;
                    system("cls");
                    gotoxy(50, 0);
                    cout << "Informaci"<< char(162) << "n pel"<< char(161) << "cula " << endl;
                    cout << "\nPel"<< char(161) << "cula -----:" << AuxP.Titulo << "   "
                         << "*" << AuxP.Codigo << "*" << endl;
                    cout << "G"<< char(130) << "nero -----: " << AuxP.Genero << endl;
                    cout << "Resumen -----: \t" << AuxP.Resumen << endl;
                    cout << "Duraci"<< char(162) << "n -----: " << AuxP.Duracion << endl;
                    cout << "Reproducciones -----: " << AuxP.Reproducciones << endl
                         << endl;
                    cout << char(168) << "Est"<< char(160) << " seguro que desea eliminar la pel"<< char(161) << "cula? :";
                    cin >> rta;
                    if (rta == 'n')
                    {
                        if (RegAux)
                            RegAux.write((char *)&Peliculas, sizeof(Peliculas));
                        else
                            cout << "No se cre"<< char(162) << " el auxiliar" << endl;
                    }
                }
                else
                {
                    if (RegAux)
                        RegAux.write((char *)&Peliculas, sizeof(Peliculas));
                    else
                        cout << "No se cre"<< char(162) << " el auxiliar" << endl;
                }
            }
        }
        RegAux.close();
        RegPelis.close();
        if (Encontro == true && rta == 's')
            cout << "Eliminando pel"<< char(161) << "cula..." << endl;
        else if (Encontro == false)
            cout << char(173) <<  "La pel"<< char(161) << "cula no se encuentra en nuestro repertorio!" << endl;

        remove("Peliculas.dat");
        rename("Auxiliar.dat", "Peliculas.dat");
    }
    else
        cout << char(173) <<  "El archivo no se pudo abrir! " << endl;
}
//FUNCIONES USUARIO
void UserScreen(char *Usuario)
{
    int opcion = -1;
    char PClave[20], User[20];
    strcpy(User,Usuario);
    cout << "Bienvenido de nuevo " << User << "!" << endl;
    Sleep(800);
    while (opcion != 3)
    {
        system("cls");
        cout << "\tMEN"<< char(233) << endl
             << endl;
        cout << "0. Lista pel"<< char(161) << "culas" << endl;
        cout << "1. Buscar pel"<< char(161) << "cula" << endl;
        cout << "2. Recomendaciones" << endl;
        cout << "3. Salir" << endl;
        cout << "\nIngrese una opci"<< char(162) << "n -> ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 0:
            system("cls");
            PrintUsuario();
            getch();
            break;
        case 1:
            system("cls");
            gotoxy(50, 0);
            cout << "BUSCAR PEL"<< char(214) << "CULA" << endl;
            cout << "Palabra clave -> ";
            cin.getline(PClave, sizeof(PClave));
            BuscarPelicula(PClave,User);
            system("pause");
            opcion=2;
            break;
        case 2:
            imprimirRecomendaciones(User);
            system("pause");
            break;
        case 3:
            return;
            break;
        default:
            cout << char(173) << "Opci"<< char(162) << "n incorrecta!" << endl;
        }
    }
}
void BuscarPelicula(char *PClave,char *User)
{
    TNodo<struct Peliculas> *ListaPeliculas;
    CrearLista(&ListaPeliculas);
    struct Peliculas RegPelis;
    struct Peliculas AuxPelis;
    ifstream Archivo("Peliculas.dat", ios::binary | ios::in);
    string *Words = new string[100];
    string *Words_2 = new string[100];
    char *Clave, *ComunWords, *Titulo;
    int ContPal = 0;
    bool bandera=false;
    strupr(PClave);
    Clave = strtok(PClave, ",. ");
    while (Clave != NULL)
    {
        if (strcmp(Clave, "LOS") == 0 || strcmp(Clave, "DE") == 0 ||strcmp(Clave, "Y") == 0 || strcmp(Clave, "O") == 0 || strcmp(Clave, "LA") == 0 || strcmp(Clave, "EL") == 0 || strcmp(Clave, "EN") == 0 || strcmp(Clave, "SU") == 0)
        {
        }
        else
        {
            Words[ContPal] = Clave;
            ContPal++;
        }
        Clave = strtok(NULL, ",. ");
    }
    if (Archivo)
    {
        while (!Archivo.eof())
        {
            if (Archivo.read((char *)&RegPelis, sizeof(RegPelis)))
            {
                AuxPelis = RegPelis;
                strupr(AuxPelis.Titulo);
                if (strcmp(PClave, AuxPelis.Titulo) == 0 && bandera==false)
                {
                    InsertarPrincipio(&ListaPeliculas, RegPelis);
                    bandera=true;
                }
                else
                {
                    int Contador = 0;
                    //busqueda por titulo
                    ComunWords = strtok(AuxPelis.Titulo, " ");
                    while (ComunWords != NULL)
                    {
                        if (strcmp(ComunWords, "LOS") == 0 || strcmp(ComunWords, "DE") == 0 ||strcmp(ComunWords, "Y") == 0 || strcmp(ComunWords, "O") == 0 || strcmp(ComunWords, "LA") == 0 || strcmp(ComunWords, "EL") == 0 || strcmp(ComunWords, "EN") == 0 || strcmp(ComunWords, "SU") == 0)
                        {}
                        else
                        {
                            Words_2[Contador] = ComunWords;
                            Contador++;
                        }
                        ComunWords = strtok(NULL, " ");
                    }

                    //busqueda por genero
                    ComunWords = strtok(AuxPelis.Genero, " , ");
                    while (ComunWords != NULL)
                    {
                        if (strcmp(ComunWords, "LOS") == 0 || strcmp(ComunWords, "DE") == 0 ||strcmp(ComunWords, "Y") == 0 || strcmp(ComunWords, "O") == 0 || strcmp(ComunWords, "LA") == 0 || strcmp(ComunWords, "EL") == 0 || strcmp(ComunWords, "EN") == 0 || strcmp(ComunWords, "SU") == 0)
                        {}
                        else
                        {
                            strupr(ComunWords);
                            Words_2[Contador] = ComunWords;
                            Contador++;
                        }
                        ComunWords = strtok(NULL, " , ");
                    }
                    //busqueda resumen
                    ComunWords = strtok(AuxPelis.Resumen, " ,Y ");
                    while (ComunWords != NULL)
                    {
                        if (strcmp(ComunWords, "LOS") == 0 || strcmp(ComunWords, "DE") == 0 ||strcmp(ComunWords, "Y") == 0 || strcmp(ComunWords, "O") == 0 || strcmp(ComunWords, "LA") == 0 || strcmp(ComunWords, "EL") == 0 || strcmp(ComunWords, "EN") == 0 || strcmp(ComunWords, "SU") == 0)
                        {}
                        else
                        {
                            strupr(ComunWords);
                            Words_2[Contador] = ComunWords;
                            Contador++;
                        }
                        ComunWords = strtok(NULL, " ,Y ");
                    }
                    int s;
                    for (int i = 0; i < ContPal; i++)
                    {
                        for (int j = 0; j < Contador; j++)
                        {
                            if (Words_2[j] == Words[i])
                            {
                                InsertarFinal(&ListaPeliculas, RegPelis);
                                j = Contador;
                                s = j;
                            }
                        }
                        if (s == Contador)
                            i = ContPal;
                    }
                }
            }
        }
        Archivo.close();
    }
    else
        cout << char(173) << "No se pudo abrir el archivo!" << endl;
    delete[] Words_2;
    delete[] Words;
    if (LongitudLista(&ListaPeliculas) == 0)
        cout << "\n\t" << char(173) << "No se encontraron resultados con la palabra clave! " << endl;
    else
        PrintPalabraClave(ListaPeliculas,User);
}
void PrintPalabraClave(TNodo<struct Peliculas> *ListaPeliculas,char *User)
{
    char criterio,Name[20], opcion, op2;
    int codes[50];
    int contaCod=0;
    int cod;
    strcpy(Name,User);
    TNodo<struct Peliculas> *aux;
    aux = ListaPeliculas;
    cout << char(168) << "Desea verlas en alg"<< char(163) << "n orden?(S/N) ->";
    cin >> opcion;
    do
    {
        if (opcion == 'S' || opcion == 's')
        {
            system("cls");
            gotoxy(50, 0);
            cout << "Criterios de ordenamiento " << endl;
            cout << "\nG: G"<< char(130) << "nero. " << endl;
            cout << "T: T"<< char(161) << "tulo. " << endl;
            cout << "D: Duraci"<< char(162) << "n. " << endl;
            cout << "\nOrdenar por: ";
            cin >> criterio;
            switch (criterio)
            {
            case 'G':
                Ordenar(&ListaPeliculas, criterio);
                opcion = 'N';
                break;
            case 'D':
                Ordenar(&ListaPeliculas, criterio);
                opcion = 'N';
                break;
            case 'T':
                Ordenar(&ListaPeliculas, criterio);
                opcion = 'N';
                break;
            case 'g':
                Ordenar(&ListaPeliculas, criterio);
                opcion = 'N';
                break;
            case 'd':
                Ordenar(&ListaPeliculas, criterio);
                opcion = 'N';
                break;
            case 't':
                Ordenar(&ListaPeliculas, criterio);
                opcion = 'N';
                break;
            default:
                cout << char(173) << "Criterio incorrecto!" << endl;
            }
        }
        else if (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n')
        {
            cout << char(173) <<  "Opci" << char(162) << "n incorrecta!\n";
            cout << "Ingrese una opci" << char(162) << "n v"<< char(160) << "lida: ";
            cin >> opcion;
        }
    }
    while (opcion == 'S' || opcion == 's');

    if (LongitudLista(&ListaPeliculas) == 1)
        cout << char(173) << "Se encontr"<< char(162) << " " << LongitudLista(&ListaPeliculas) << " coincidencia!" << endl;
    else
        cout << char(173) << "Se encontraron " << LongitudLista(&ListaPeliculas) << " coincidencias!" << endl;
    while (ListaPeliculas != NULL)
    {
        cout << "--------------------------------------------" << endl;
        cout << "Pel"<< char(161) << "cula -----:" << (ListaPeliculas->dato).Titulo << "   "
             << "*" << (ListaPeliculas->dato).Codigo << "*" << endl;
        cout << "Duraci"<< char(162) << "n -----: " << (ListaPeliculas->dato).Duracion << endl;
        codes[contaCod] = (ListaPeliculas->dato).Codigo;
        contaCod++;
        ListaPeliculas = ListaPeliculas->sig;
    }
    int i=0;
    if(contaCod>1)
    {
        cout << "\n" << char(168) << "Desea ver una pel"<< char(161) << "cula? (s/n) -> ";
        cin >> op2;
    }
    else
    {
        cout << "\n" << char(168) << "Desea ver la pel"<< char(161) << "cula? (s/n) -> ";
        cin >> op2;
    }
    do
    {
        if (op2 == 'S' || op2 == 's')
        {
            if(contaCod>1)
            {
                cout << "\nPara seleccionar la pel"<< char(161) << "cula que desea ver, ingrese el c"<< char(162) << "digo: ";
                cin >> cod;
            }
            else
                cod=codes[0];
            int j=0;
            for (i=0; i<contaCod; i++)
            {
                if (cod == codes[i])
                {
                    while (aux != NULL)
                    {
                        if (codes[i] == (aux->dato).Codigo)
                        {
                            char si;
                            cout << "--------------------------------------------" << endl;
                            cout << "Pel"<< char(161) << "cula -----:" << (aux->dato).Titulo << "   "
                                 << "*" << (aux->dato).Codigo << "*" << endl;
                            cout << "Duraci"<< char(162) << "n -----: " << (aux->dato).Duracion << endl;
                            cout << "G"<< char(130) << "nero -----: " << (aux->dato).Genero << endl;
                            cout << "Resumen -----: \t" << (aux->dato).Resumen << endl;
                            cout << "Reproducciones -----: " << (aux->dato).Reproducciones << endl;
                            if((aux->dato).calificacion==0)
                                cout<<"Calificaci"<< char(162) << "n promedio -----: No ha recibido ninguna calificaci"<< char(162) << "n"<<endl;
                            else
                                cout<<"Calificaci"<< char(162) << "n promedio -----: "<<(aux->dato).calificacion<<endl;
                            AlmacenarReco((aux->dato).Genero, Name);
                            cout << endl << char(168) << "Desea darle una calificaci"<< char(162) << "n? (s/n) -> ";
                            cin>>si;
                            if(si=='s')
                            {
                                int califi;
                                cout<<"Calificaci"<< char(162) << "n (0-5) -> ";
                                cin>>(aux->dato).calif;
                                califi=(aux->dato).calif;
                                Calificacion(codes[i],true,califi);
                            }
                            else
                                Calificacion(codes[i],false,0);
                            (aux->dato).Estado=true;
                            TNodo<struct Peliculas> *Vistas;
                            CrearLista(&Vistas);
                            InsertarFinal(&Vistas,aux->dato);
                            peliculasUsuarios(Name,Vistas);
                            DestruirLista(&Vistas);
                            i = contaCod;
                            op2 = 'N';
                        }
                        aux = aux->sig;
                    }
                }
                else
                    j++;
                if (j == contaCod)
                {
                    cout << char(173) << "C"<< char(162) << "digo incorrecto!\n";
                    cout << "Ingrese un c"<< char(162) << "digo nuevo: ";
                    cin >> cod;
                    i=0;
                }
            }
        }
        else if (op2 != 'S' && op2 != 's' && op2 != 'N' && op2 != 'n')
        {
            cout << char(173) << "Opci"<< char(162) << "n incorrecta!\n";
            cout << "Ingrese una opci"<< char(162) << "n v" << char(160) << "lida: ";
            cin >> op2;
        }
    }
    while (op2 == 'S' || op2 == 's');
}
void Ordenar(TNodo<struct Peliculas> **ListaPeliculas, char criterio)
{
    TNodo<struct Peliculas> *I, *J;
    struct Peliculas Temp;
    I = *ListaPeliculas;
    while (I != NULL)
    {
        J = I->sig;
        while (J != NULL)
        {
            if (criterio == 'g' || criterio == 'G')
            {
                if (strcmp((I->dato).Genero, (J->dato).Genero) > 0)
                {
                    Temp = I->dato;
                    I->dato = J->dato;
                    J->dato = Temp;
                }
            }
            if (criterio == 'D' || criterio == 'd')
            {
                if (strcmp((I->dato).Duracion, (J->dato).Duracion) > 0)
                {
                    Temp = I->dato;
                    I->dato = J->dato;
                    J->dato = Temp;
                }
            }
            if (criterio == 't' || criterio == 'T')
            {
                if (strcmp((I->dato).Titulo, (J->dato).Titulo) > 0)
                {
                    Temp = I->dato;
                    I->dato = J->dato;
                    J->dato = Temp;
                }
            }
            J = J->sig;
        }
        I = I->sig;
    }
}
void PrintUsuario()
{

    struct Plataforma Pelis;
    Pelis = Moviez();
    char respuesta;
    int contador = 0;
    int auxContador = 0;
    int paginacion = 0;
    TNodo<struct Peliculas> *auxListaPelis = Pelis.ListaPeliculas;
    if(ListaVacia(&auxListaPelis)==true)
        return;
    int Longitud = LongitudLista(&auxListaPelis);
    char criterio, opcion;
    cout << char(168) << "Desea verlas en alg"<< char(163) << "n orden? (S/N) ->";
    cin >> opcion;

    if (opcion == 'S' || opcion == 's')
    {
        system("cls");
        gotoxy(50, 0);
        cout << "Criterios de ordenamiento " << endl;
        cout << "\nG: G"<< char(130) << "nero. " << endl;
        cout << "T: T"<< char(161) << "tulo. " << endl;
        cout << "D: Duraci"<< char(162) << "n. " << endl;
        cout << "\nOrdenar por: ";
        cin >> criterio;
        switch (criterio)
        {
        case 'G':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 'D':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 'T':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 'g':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 'd':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        case 't':
            Ordenar(&Pelis.ListaPeliculas, criterio);
            break;
        default:
            cout << char(173) << "Criterio incorrecto!" << endl;
        }
    }
    do
    {
        if (respuesta == 'r')
        {
            if (auxContador % 10 == 0)
                auxContador = auxContador - 10;
            paginacion = 10 * (auxContador / 10);
            auxContador = paginacion;
            auxListaPelis = Pelis.ListaPeliculas;

            while (auxContador > 10)
            {
                auxListaPelis = auxListaPelis->sig;
                auxContador--;
            }
            auxContador = 0;
            contador = 0;
        }
        else
            contador = 0;
        while (contador < 10 && auxListaPelis != NULL)
        {
            cout << "----------------------------------------------" << endl;
            cout << "Pel"<< char(161) << "cula -----:" << (auxListaPelis->dato).Titulo << "   "
                 << "" << (auxListaPelis->dato).Codigo << "" << endl;
            cout << "G"<< char(130) << "nero -----: " << (auxListaPelis->dato).Genero << endl;
            cout << "Duraci"<< char(162) << "n -----: " << (auxListaPelis->dato).Duracion << endl;
            auxListaPelis = auxListaPelis->sig;
            contador++;
        }
        auxContador += contador;
        if (auxContador == Longitud)
        {
            cout << "\nSe encuentra en la "<< char(163) << "ltima p"<< char(160) << "gina !" << endl;
            cout << "\nPresione 'r' para retroceder o 'e' para salir: ";
            cin >> respuesta;
            if (respuesta == 's')
                respuesta = 'r';
        }
        else
        {
            cout << "\nPresione 's' para continuar,'r' para retroceder o 'e' para salir: ";
            cin >> respuesta;
        }
        system("cls");
    }
    while (respuesta != 'e');
}
void Graficas()
{
    struct Plataforma Plat;
    Plat = Moviez();
    TNodo <struct Peliculas> *ListaPelis;
    ListaPelis = Plat.ListaPeliculas;
    int debugCont1 = 0;
    int debugCont2 = 1;

    if(ListaVacia(&ListaPelis)==true)
        return;
    TNodo <struct Peliculas> *OrdenadaXcalificaciones = ListaPelis;
    TNodo <struct Peliculas> *aux1OrdenadaXcalificaciones = OrdenadaXcalificaciones;
    TNodo <struct Peliculas> *aux2OrdenadaXcalificaciones;
    //Ordenar de mayor a menor
    while(aux1OrdenadaXcalificaciones!=NULL)
    {
        aux2OrdenadaXcalificaciones=aux1OrdenadaXcalificaciones->sig;
        while(aux2OrdenadaXcalificaciones!=NULL)
        {
            if((aux1OrdenadaXcalificaciones->dato).calificacion<(aux2OrdenadaXcalificaciones->dato).calificacion)
            {
                struct Peliculas Peli;
                Peli=aux1OrdenadaXcalificaciones->dato;
                aux1OrdenadaXcalificaciones->dato=aux2OrdenadaXcalificaciones->dato;
                aux2OrdenadaXcalificaciones->dato=Peli;
            }
            aux2OrdenadaXcalificaciones=aux2OrdenadaXcalificaciones->sig;
        }
        aux1OrdenadaXcalificaciones=aux1OrdenadaXcalificaciones->sig;
    }

    cout << endl << "Gr"<< char(160) << "fica del Top 5 pel"<< char(161) << "culas mejor calificadas. " << endl << endl;

    int maxRating = (OrdenadaXcalificaciones->dato).calificacion;
    char caracter;
    aux1OrdenadaXcalificaciones = OrdenadaXcalificaciones;

    for (int i=0; i<5; i++)
    {
        caracter = 'A'+i;

        if ((aux1OrdenadaXcalificaciones->dato).calificacion == 0 || maxRating == 0)
        {
            cout << "(" <<caracter << ") |" << "[" << (aux1OrdenadaXcalificaciones->dato).calificacion << "]" <<endl;
        }
        if ((aux1OrdenadaXcalificaciones->dato).calificacion >= maxRating)
        {
            cout << "(" <<caracter<< ") |" << "   *   *   *   *   *  [" << (aux1OrdenadaXcalificaciones->dato).calificacion << "]" <<endl;
        }
        else if ((aux1OrdenadaXcalificaciones->dato).calificacion >= maxRating*0.7)
        {
            cout << "(" << caracter << ") |" << "   *   *   *   *  [" << (aux1OrdenadaXcalificaciones->dato).calificacion << "]" <<endl;
        }
        else if ((aux1OrdenadaXcalificaciones->dato).calificacion >= maxRating*0.5)
        {
            cout << "(" << caracter << ") |" << "   *   *   *  [" << (aux1OrdenadaXcalificaciones->dato).calificacion << "]" <<endl;
        }
        else if ((aux1OrdenadaXcalificaciones->dato).calificacion >= maxRating*0.3)
        {
            cout << "(" << caracter << ") |" << "   *   *  [" << (aux1OrdenadaXcalificaciones->dato).calificacion << "]" <<endl;
        }
        else if ((aux1OrdenadaXcalificaciones->dato).calificacion >= maxRating*0.1)
        {
            cout << "(" << caracter << ") |" << "   *  [" << (aux1OrdenadaXcalificaciones->dato).calificacion << "]" <<endl;
        }
        aux1OrdenadaXcalificaciones = aux1OrdenadaXcalificaciones->sig;

    }
    cout << "____________" << endl << endl;

    aux1OrdenadaXcalificaciones = OrdenadaXcalificaciones;

    for (int i=0; i<5 ; i++)
    {
        caracter = 'A'+i;
        cout << i << ". (" << caracter << ") : " << (aux1OrdenadaXcalificaciones->dato).Titulo << endl;
        cout << "    Calificaci"<< char(162) << "n: " << (aux1OrdenadaXcalificaciones->dato).calificacion << endl;
        aux1OrdenadaXcalificaciones = aux1OrdenadaXcalificaciones->sig;
    }

    Plat = Moviez();
    ListaPelis = Plat.ListaPeliculas;
    TNodo <struct Peliculas> *OrdenadaXreproduccion = ListaPelis;
    TNodo <struct Peliculas> *aux1OrdenadaXreproduccion = OrdenadaXreproduccion;
    TNodo <struct Peliculas> *aux2OrdenadaXreproduccion;

    while(aux1OrdenadaXreproduccion!=NULL)
    {
        aux2OrdenadaXreproduccion=aux1OrdenadaXreproduccion->sig;
        while(aux2OrdenadaXreproduccion!=NULL)
        {
            if((aux1OrdenadaXreproduccion->dato).Reproducciones<(aux2OrdenadaXreproduccion->dato).Reproducciones)
            {
                struct Peliculas Peli;
                Peli=aux1OrdenadaXreproduccion->dato;
                aux1OrdenadaXreproduccion->dato=aux2OrdenadaXreproduccion->dato;
                aux2OrdenadaXreproduccion->dato=Peli;
            }
            aux2OrdenadaXreproduccion=aux2OrdenadaXreproduccion->sig;
        }
        aux1OrdenadaXreproduccion=aux1OrdenadaXreproduccion->sig;
    }

    maxRating = (OrdenadaXreproduccion->dato).Reproducciones;
    aux1OrdenadaXreproduccion = OrdenadaXreproduccion;

    cout << endl << endl;

    cout << "Gr"<< char(160) << "fica del Top 5 pel"<< char(161) << "culas m"<< char(160) << "s vistas. " << endl << endl;

    for (int i=0; i<5; i++)
    {
        caracter = 'A'+i;

        if ((aux1OrdenadaXreproduccion->dato).Reproducciones == 0 || maxRating == 0)
        {
            cout << "(" <<caracter << ") |" << "[" << (aux1OrdenadaXreproduccion->dato).Reproducciones << "]" <<endl;
        }
        if ((aux1OrdenadaXreproduccion->dato).Reproducciones >= maxRating)
        {
            cout << "(" <<caracter<< ") |" << "   *   *   *   *   *  [" << (aux1OrdenadaXreproduccion->dato).Reproducciones << "]" <<endl;
        }
        else if ((aux1OrdenadaXreproduccion->dato).Reproducciones >= maxRating*0.7)
        {
            cout << "(" << caracter << ") |" << "   *   *   *   *  [" << (aux1OrdenadaXreproduccion->dato).Reproducciones << "]" <<endl;
        }
        else if ((aux1OrdenadaXreproduccion->dato).Reproducciones >= maxRating*0.5)
        {
            cout << "(" << caracter << ") |" << "   *   *   *  [" << (aux1OrdenadaXreproduccion->dato).Reproducciones << "]" <<endl;
        }
        else if ((aux1OrdenadaXreproduccion->dato).Reproducciones >= maxRating*0.3)
        {
            cout << "(" << caracter << ") |" << "   *   *  [" << (aux1OrdenadaXreproduccion->dato).Reproducciones << "]" <<endl;
        }
        else if ((aux1OrdenadaXreproduccion->dato).Reproducciones >= maxRating*0.1)
        {
            cout << "(" << caracter << ") |" << "   *  [" << (aux1OrdenadaXreproduccion->dato).Reproducciones << "]" <<endl;
        }

        aux1OrdenadaXreproduccion = aux1OrdenadaXreproduccion->sig;

    }
    cout << "____________" << endl << endl;

    aux1OrdenadaXreproduccion = OrdenadaXreproduccion;

    for (int i=0; i<5 ; i++)
    {
        caracter = 'A'+i;
        cout << i << ". (" << caracter << ") : " << (aux1OrdenadaXreproduccion->dato).Titulo << endl;
        cout << "    Reproducciones: " << (aux1OrdenadaXreproduccion->dato).Reproducciones << endl;
        aux1OrdenadaXreproduccion = aux1OrdenadaXreproduccion->sig;
    }

}
void Calificacion(int code,bool acepto,int califica)
{
    struct Peliculas RegPelis;
    bool Encontro=false;
    fstream Archivo("Peliculas.dat", ios::binary | ios::in | ios::out);
    if (Archivo)
    {
        while (!Archivo.eof())
        {
            if (Archivo.read((char *)&RegPelis, sizeof(RegPelis)))
            {
                if (code==RegPelis.Codigo)
                    Encontro = true;
                if (Encontro == true)
                {
                    RegPelis.Reproducciones++;
                    RegPelis.calif=califica;
                    if(RegPelis.Cant==0)
                    {
                        RegPelis.calificacion=RegPelis.calif;
                        RegPelis.Cant++;
                    }
                    else
                    {
                        float Aux,final1;
                        Aux=((RegPelis.calificacion*RegPelis.Cant)+RegPelis.calif)/((RegPelis.Cant+1.0));
                        final1=ceil(Aux);
                        RegPelis.calificacion=final1;
                        RegPelis.Cant++;
                    }
                    Archivo.seekg((int)((-1) * sizeof(RegPelis)), ios::cur);
                    Archivo.write((char *)&RegPelis, sizeof(RegPelis));
                    return;
                }

            }
        }

    }
    else
        cout << char(173) << "No se pudo abrir el archivo!"<<endl;
}
void peliculasUsuarios(char*Usu,TNodo<struct Peliculas> *Lista)
{
    struct Plataforma Plat;
    bool Encontro=false;
    struct Usuario RegUser;
    struct PeliculasVistas Views;
    char Usuar[20];
    strcpy(Usuar,Usu);
    ifstream Usuario("Usuarios.dat",ios::binary);
    if(Usuario)
    {
        while(!Usuario.eof())
        {
            if(Usuario.read((char*)&RegUser,sizeof(RegUser)))
            {

                if(strcmp(RegUser.Usuario,Usu)==0)
                {
                    Encontro=true;
                    if(Encontro==true)
                    {
                        ofstream File("Vistas.dat",ios::binary|ios::out|ios::app);
                        if(File)
                        {
                            strcpy(Views.Usuario,Usuar);
                            Views.codigo=(Lista->dato).Codigo;
                            strcpy(Views.Genero,(Lista->dato).Genero);
                            strcpy(Views.Titulo,(Lista->dato).Titulo);
                            Views.califi=(Lista->dato).calif;
                            File.write((char*)&Views,sizeof(Views));
                            File.close();
                        }
                        else
                            cout<<"No se pudo abrir el archivo !"<<endl;
                        return;
                    }
                }
            }
        }
        Usuario.close();
    }
    else
        cout << char(173) <<  "El archivo no existe!"<<endl;

}
void OrdenarArchivo()
{
    TNodo<struct PeliculasVistas> *Aux;
    struct PeliculasVistas Reg;
    CrearLista(&Aux);
    fstream Archivo("Vistas.dat",ios::binary|ios::in|ios::out);
    if(Archivo)
    {
        while(!Archivo.eof())
        {
            if(Archivo.read((char*)&Reg,sizeof(Reg)))
                InsertarFinal(&Aux,Reg);
        }
        Archivo.close();
    }
    else
        cout << char(173) << "No se pudo abrir el archivo!"<<endl;
    TNodo<struct PeliculasVistas> *I, *J;
    struct PeliculasVistas Temp;
    I = Aux;
    while (I != NULL)
    {
        J = I->sig;
        while (J != NULL)
        {
            if (strcmp((I->dato).Usuario, (J->dato).Usuario) > 0)
            {
                Temp = I->dato;
                I->dato = J->dato;
                J->dato = Temp;
            }
            J=J->sig;
        }
        I=I->sig;
    }
    OrdenFile(Aux);
    Proof();
}
void OrdenFile(TNodo<struct PeliculasVistas> *Aux1)
{
    TNodo<struct PeliculasVistas> *Aux;
    struct PeliculasVistas AuxReg;
    Aux=Aux1;
    ofstream Archivo("AuxVista.dat",ios::binary|ios::out|ios::app);
    if(Archivo)
    {
        while(Aux!=NULL)
        {
            strcpy(AuxReg.Titulo,(Aux->dato).Titulo);
            strcpy(AuxReg.Usuario,(Aux->dato).Usuario);
            strcpy(AuxReg.Genero,(Aux->dato).Genero);
            AuxReg.califi=(Aux->dato).califi;
            AuxReg.codigo=(Aux->dato).codigo;
            Archivo.write((char*)&AuxReg,sizeof(AuxReg));
            Aux=Aux->sig;
        }
        Archivo.close();
    }
    else
        cout << char(173) << "No se pudo abrir el archivo!"<<endl;
    remove("Vistas.dat");
    rename("AuxVista.dat","Vistas.dat");
}
void Proof()
{
    ifstream Archivo("Vistas.dat",ios::binary);
    struct PeliculasVistas Reg;

    if(Archivo)
    {
        while(!Archivo.eof())
        {
            if(Archivo.read((char*)&Reg,sizeof(Reg)))
                cout<<Reg.Usuario<<"   "<<Reg.Titulo<<endl;
        }
        Archivo.close();
    }
    else
        cout << char(173) << "No se pudo abrir el archivo!"<<endl;

}
void AlmacenarReco(char Genero[50], char Usuario[50])
{

    struct Recomendacion auxRecomendacion;
    ofstream Recomendaciones("Recomendaciones.dat", ios::binary | ios::app);

    if(Recomendaciones)
    {
        strcpy(auxRecomendacion.Usuario, Usuario);
        strcpy(auxRecomendacion.Genero, Genero);
        Recomendaciones.write((char *)&auxRecomendacion, sizeof(auxRecomendacion));

        Recomendaciones.close();
    }
    else
    {
        cout << "No se pudo crear el archivo!" << endl;
    }
}
void imprimirRecomendaciones(char Nombre[50])
{
    struct Plataforma plat;
    plat = Moviez();

    TNodo <struct Peliculas> *ListaPelis;
    TNodo <struct Peliculas> *auxListaPelis;
    ListaPelis = plat.ListaPeliculas;

    int ContInterior=0;
    int ContGeneral=0;

    ifstream Recomendaciones("Recomendaciones.dat", ios::binary);
    struct Recomendacion RegR;

    if(Recomendaciones)
    {
        system("cls");
        cout<<"\tTe puede interesar : "<<endl<<endl;
        while(!Recomendaciones.eof())
        {
            if (Recomendaciones.read((char *)&RegR, sizeof(RegR)))
            {
                auxListaPelis = ListaPelis;
                ContInterior = 0;

                if (ContGeneral<=5)
                {
                    if(strcmp(Nombre, RegR.Usuario) == 0)
                    {

                        while (auxListaPelis!=NULL && ContInterior!=3 && ContGeneral!=5)
                        {
                            if(strcmp((auxListaPelis->dato).Genero, RegR.Genero)==0)
                            {
                                cout << "Titulo: " << (auxListaPelis->dato).Titulo << endl;
                                cout << "Duracion: " << (auxListaPelis->dato).Duracion << endl;
                                cout << "Calificacion promedio: " << (auxListaPelis->dato).calificacion << endl << endl;
                                ContInterior++;
                                ContGeneral++;
                            }

                            auxListaPelis = auxListaPelis->sig;
                        }
                    }
                }
            }
        }

        Recomendaciones.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

