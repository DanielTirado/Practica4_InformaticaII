#include "red.h"
#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

red::red()
{

}

bool red::addEnrutador(string nombreEnrutador)
{
    Enrutador router(nombreEnrutador);

    if (existeEnrutador(nombreEnrutador)){
        cout << "El enrutador ya existe \n";
        return false;
    }

    MiRed.insert(pair<string, Enrutador>(nombreEnrutador, router));
    for (auto it = MiRed.begin(); it != MiRed.end(); ++it) {
        MiRed.at(it->first).addNodo(nombreEnrutador, -1);
        MiRed.at(nombreEnrutador).addNodo(it->first, -1);

    }
    return true;
}

bool red::delEnrutador(string nombreEnrutador)
{
    if (existeEnrutador(nombreEnrutador)){
        MiRed.erase(nombreEnrutador);

        for (auto it = MiRed.begin(); it != MiRed.end(); ++it) {
            it->second.delNodo(nombreEnrutador);
        }
        cout << "\n\nEl enrutador se elimino correctamente \n";
        return true;
    }
    cout << "El enrutador no existe \n";
    return false;
}

bool red::existeEnrutador(string enrutador)
{
    map<string, Enrutador> :: iterator it;
    it = MiRed.find(enrutador);
    if (it != MiRed.end()){
        return true;
    }
    return false;
}

void red::showRed()
{
    for (auto it = MiRed.begin(); it != MiRed.end(); ++it) {
        cout << "Enrutador " << it->first << ":" << endl;

        for (auto it2 = it->second.gettablaDeEnrutamiento().begin(); it2 != it->second.gettablaDeEnrutamiento().end(); ++it2) {
            cout << "    " << it2->first << " => " << it2->second << endl;
        }
    }
}

/*void red::calcularRuta(string origen, string destino)
{
    int minCosto = 0;

    for (auto it = MiRed.begin(); it != MiRed.end(); ++it) {
        if (it->first !=destino){
            for (auto it2 = it->second.gettablaDeEnrutamiento.begin(); it2 != it->second.gettablaDeEnrutamiento().end(); ++it2){

            }

        }

    }

}*/

map<string, Enrutador> &red::getRed()
{
    return MiRed;
}
