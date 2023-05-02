#include "enrutador.h"
#include <string>
#include <map>
#include <iostream>

Enrutador::Enrutador(string nodo)
{
    tablaDeEnrutamiento.insert(pair<string, int>(nodo, 0));
}

bool Enrutador::addNodo(string nodo, int costo)
{
    if (nodoConectado(nodo)){
        //cout << "El enrutador ya esta conectado a ese nodo \n";
        return false;
    }
    tablaDeEnrutamiento.insert(pair<string, int>(nodo, costo));
    return true;
}

bool Enrutador::delNodo(string nodo)
{
    if (nodoConectado(nodo)){
        tablaDeEnrutamiento.erase(nodo);
        //cout << "Nodo eliminado con exito \n";
        return true;
    }
    //cout << "El nodo no esta conectado.\n";
    return false;
}

bool Enrutador::modNodo(string nodo, int newCosto)
{
    if (nodoConectado(nodo)){
        tablaDeEnrutamiento[nodo] = newCosto;
        cout << " Nodo modificado con exito \n";
        return true;
    }
    cout << "El nodo no existe \n";
    return false;
}

void Enrutador::showtablaDeEnrutamiento()
{
    map<string, int>::iterator itr;
    for (itr = tablaDeEnrutamiento.begin(); itr != tablaDeEnrutamiento.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
}

bool Enrutador::nodoConectado(string nodo)
{
    map <string, int> :: iterator it;
    it = tablaDeEnrutamiento.find(nodo);
    if (it != tablaDeEnrutamiento.end() || it->second > -1){
        return true;
    }

    //cout << "El nodo no esta conectado. \n";
    return false;
}

const map<string, int> &Enrutador::gettablaDeEnrutamiento()
{
    return tablaDeEnrutamiento;
}
