#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Pais.h"
#include "Evaluador.h"
#include "NodoNario.h"

using namespace std;

//Escribe "pais" en un achivo con nombre "nombre_archivo" en la posicion "posicion"
//Nota: Se deben poder agregar varios registros en un solo archivo
void escribir(string nombre_archivo, Pais*pais, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*25);
    out.write((char*)pais->nombre.c_str(),20);
    out.write((char*)&pais->habitantes,4);
    out.write((char*)&pais->hablan_espanol,1);
    out.close();
}

//Devuelve un pais previamente escrito (con la funcion escribir()) en el archivo con nombre "nombre_archivo" en la posicion "posicion"
//Nota: Se deben poder leer varios registros de un archivo
Pais* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*25);
    int habitantes;
    char nombre[20];
    bool hablan_espanol;
    in.read(nombre,20);
    in.read((char*)&habitantes,4);
    in.read((char*)&hablan_espanol,1);
    Pais *pais = new Pais(nombre,habitantes,hablan_espanol);
    return pais;
}

//Devuelve suma de habitantes de paises que hablan espanol en el archivo con nombre "nombre_archivo"
//Nota: Los registros se deben de haber guardado previamente con la funcion escribir()
int contarHispanohablantes(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    int cantidad_registros = in.tellg()/25;
    int contador_hispanos= 0;
    for(int i=0;i<cantidad_registros;i++)
    {
        Pais *pais=leer(nombre_archivo,i);
        if(pais->hablan_espanol)
        {
            contador_hispanos+=pais->habitantes;
        }

    }
    return contador_hispanos;
}

//Devuelve un set que contenga los numeros fibonacci.
//La cantidad de numeros que contiene se determina por el parametro "cantidad"
set<int> getNumerosFibonacci(int cantidad)
{
    int anterior1=0,anterior2=0;;

    set<int>respuesta;
    for(int i=0;i<cantidad;i++){
        if(i==0){
            respuesta.insert(0);
        }
        else if(i==1){
            respuesta.insert(1);
            anterior1=1;
        }
        else{
            int num=anterior1+anterior2;
            respuesta.insert(num);
            anterior2=anterior1;
            anterior1=num;
        }
    }

    return respuesta;
}

//Devuelve la cantidad de letras mayusculas presentes en "a" y "b"
int contarMayusculas(stack<char> a,queue<char> b)
{
    int ma=0;
    int mb=0;
    while(!a.empty()){

        if(a.top()=='A'||a.top()=='B'||a.top()=='C'||a.top()=='D'||a.top()=='F'||a.top()=='G'||a.top()=='H'||a.top()=='I'||
           a.top()=='J'||a.top()=='K'||a.top()=='L'||a.top()=='M'||a.top()=='N'||a.top()=='O'||a.top()=='P'||a.top()=='Q'
           ||a.top()=='R'||a.top()=='S'||a.top()=='T'||a.top()=='U'||a.top()=='V'||a.top()=='W'||a.top()=='X'||a.top()=='Y'
           ||a.top()=='Z'){

            ma++;

        }
        a.pop();
    }

    while(!b.empty()){

        if(b.front()=='A'||b.front()=='B'||b.front()=='C'||b.front()=='D'||b.front()=='F'||b.front()=='G'||b.front()=='H'||b.front()=='I'||
           b.front()=='J'||b.front()=='K'||b.front()=='L'||b.front()=='M'||b.front()=='N'||b.front()=='O'||b.front()=='P'||b.front()=='Q'
           ||b.front()=='R'||b.front()=='S'||b.front()=='T'||b.front()=='U'||b.front()=='V'||b.front()=='W'||b.front()=='X'||b.front()=='Y'
           ||b.front()=='Z'){

            mb++;

        }
        b.pop();
    }


    return ma+mb;
}

//Devuelve la cantidad de llaves repetidas en "mi_multimapa"
//Nota: No devuelve la cantidad de repeticines
int contarLLavesRepetidas(multimap<string,string>mi_multimapa)
{
    map<string,string> mi_mapa;
    for(multimap<string,string>::iterator i= mi_multimapa.begin(); i!= mi_multimapa.end(); i++)
    {
        pair<string,string>par_actual = *i;
        mi_mapa [par_actual.first] = par_actual.second;
    }
    int repetidas = (mi_multimapa.size() - mi_mapa.size());
    return repetidas;
}

//Devuelve true si y solo si "buscado" existe en el arbol nario "raiz"
bool existe(NodoNario* raiz,int buscado)
{
    bool retorna=false;
    if(raiz==NULL){
        return false;
    }
    if(raiz->valor==buscado)
        return true;
    int tamano_final=raiz->hijos.size();

    for(int j=0;j<tamano_final;j++)
    {
        if(existe(raiz->hijos[j],buscado)){
            retorna=true;
            break;
        }

    }

    return retorna;
}

//Busca el valor "buscado" en el arbol "raiz" y lo reemplaza con "reemplazo"
void buscarYReemplazar(NodoNario* raiz, int buscado, int reemplazo)
{
    if(raiz == NULL)
        return;
    if(raiz -> valor == buscado){
        raiz -> valor = reemplazo;
    }else
    {
        for(int hijo = 0; hijo < raiz -> hijos.size(); hijo ++){
            bool b = existe(raiz -> hijos[hijo], buscado);
            if(b){
                raiz -> hijos[hijo] -> valor = reemplazo;
            }
        }
    }
}


//Devuelve un vector que contenga la siguiente secuencia binaria:
//00000001
//00000010
//00000100
//00001000
//00010000
//00100000
//01000000
//10000000
vector<char> obtenerSecuencia()
{
    vector<char>respuesta;
    respuesta.push_back(1);
    respuesta.push_back(2);
    respuesta.push_back(4);
    respuesta.push_back(8);
    respuesta.push_back(16);
    respuesta.push_back(32);
    respuesta.push_back(64);
    respuesta.push_back(128);
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

