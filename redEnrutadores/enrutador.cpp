#include "enrutador.h"
#include <string>
#include <map>
#include <iostream>

Enrutador::Enrutador(string nodo)
{
    nodos.insert(pair<string, int>(nodo, 0));
}

bool Enrutador::addNodo(string nodo, int costo)
{
    if (nodoConectado(nodo)){
        cout << "El nodo ya existe \n";
        return false;
    }
    nodos.insert(pair<string, int>(nodo, costo));
    return true;
}

bool Enrutador::delNodo(string nodo)
{
    if (nodoConectado(nodo)){
        nodos.erase(nodo);
        //cout << "Nodo eliminado con exito \n";
        return true;
    }
    //cout << "El nodo no esta conectado.\n";
    return false;
}

bool Enrutador::modNodo(string nodo, int newCosto)
{
    if (nodoConectado(nodo)){
        nodos[nodo] = newCosto;
        cout << " Nodo modificado con exito \n";
        return true;
    }
    cout << "El nodo no existe \n";
    return false;
}

void Enrutador::showNodos()
{
    map<string, int>::iterator itr;
    for (itr = nodos.begin(); itr != nodos.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
}

bool Enrutador::nodoConectado(string nodo)
{
    map <string, int> :: iterator it;
    it = nodos.find(nodo);
    if (it != nodos.end())
        return true;
    cout << "El nodo no esta conectado. \n";
    return false;
}

const map<string, int> &Enrutador::getNodos()
{
    return nodos;
}
