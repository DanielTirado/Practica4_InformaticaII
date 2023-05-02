#include "recorrido.h"

recorrido::recorrido(string origen)
{
    camino.back() = costo ;
    camino.push_front(origen);
}

void recorrido::addStop(string nombreNodo, int sumarCosto)
{
    costo = 0;
    camino.push_front(nombreNodo);
    camino.back() = costo + sumarCosto;
}

void recorrido::clearCamino()
{
    camino.clear();
}

