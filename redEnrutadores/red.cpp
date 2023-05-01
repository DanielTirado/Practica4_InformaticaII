#include "red.h"
#include <iostream>
#include <string>
#include <map>

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
    return true;
}

bool red::delEnrutador(string nombreEnrutador)
{
    if (existeEnrutador(nombreEnrutador)){
        MiRed.erase(nombreEnrutador);

        for (auto it = MiRed.begin(); it != MiRed.end(); ++it) {
            it->second.delNodo(nombreEnrutador);
        }
        cout << "El enrutador se elimino correctamente \n";
        return true;
    }
    cout << "El enrutador no existe \n";
    return false;
}

bool red::existeEnrutador(string enrutador)
{
    map<string, Enrutador> :: iterator it;
    it = MiRed.find(enrutador);
    if (it != MiRed.end())
        return true;
    return false;
}

void red::showRed()
{
    for (auto it = MiRed.begin(); it != MiRed.end(); ++it) {
        cout << "Enrutador " << it->first << ":" << endl;

        for (auto it2 = it->second.getNodos().begin(); it2 != it->second.getNodos().end(); ++it2) {
            cout << "    " << it2->first << " => " << it2->second << endl;
        }
    }
}
