#ifndef RECORRIDO_H
#define RECORRIDO_H
#include <string>
#include <list>

using namespace std;

class recorrido
{

public:
    list<string>  camino;
    int costo= -1;

    recorrido(string origen);
    void addStop(string nombreNodo, int sumarCosto);
    void clearCamino();
};

#endif // RECORRIDO_H
