#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include <map>
#include <string>

class red
{
    map<string, Enrutador> MiRed;
public:
    red();
    bool addEnrutador(string nombreEnrutador);
    bool delEnrutador(string nombreEnrutador);
    bool existeEnrutador(string enrutador);
    void showRed();
};

#endif // RED_H
