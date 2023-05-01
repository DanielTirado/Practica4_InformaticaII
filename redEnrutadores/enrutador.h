#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <map>
#include <string>

using namespace std;

class Enrutador
{
    map<string, int> tablaDeEnrutamiento;
public:
    Enrutador(string nodo);
    bool addNodo(string nodo, int costo);
    bool delNodo(string nodo);
    bool modNodo(string nodo, int newCosto);
    void showtablaDeEnrutamiento();
    bool nodoConectado(string nodo);
    const map<string, int> &gettablaDeEnrutamiento();
};

#endif // ENRUTADOR_H
