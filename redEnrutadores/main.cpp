#include <iostream>
#include <enrutador.h>
#include <red.h>
#include <recorrido.h>
#include <string>
#include <map>
#include <list>

using namespace std;

int main()
{
    red miRed;

    int numEnrutadores = 0;
    cout << "\t\tSIMULADOR DE RED DE ENRUTADORES \n\n";
    cout << "Para comenzar, cree enrutadores.\n";
    cout << "Cuantos enrutadores desea agregar inicialmente? ";
    cin >> numEnrutadores;

    while (numEnrutadores<2){
        cout << "Debe agregar por lo menos 2 enrutadores. \n Intente de nuevo: ";
        cin >> numEnrutadores;
    }

    string nombreRouter;
    for (int i=0; i<numEnrutadores; i++){
        cout << "Ingrese el nombre del enrutador #" <<i+1 << ": ";
        cin >> nombreRouter;
        while (!miRed.addEnrutador(nombreRouter)){
            cout << "\nIngrese el nombre del enrutador #" <<i+1 << ": ";
            cin >> nombreRouter;
        }
    }

    int op;
    system("cls");

    string origen;
    string destino;


    do{
        op=0;
        cout << "\n\t\tSimulador de red de Enrutadores \n\n";
        cout << "Elija una opcion: \n";
        cout << "(1) Crear enrutador.\n";
        cout << "(2) Eliminar un enrutador.\n";
        cout << "(3) Modificar un enrutador.\n";
        cout << "(4) Cotizar envio.\n";
        cout << "(5) Mostrar red.\n";
        cout << "(6) Salir.\n";
        cout << "Opcion: ";
        cin >>op;
        cout << "\n\n";

        switch(op)
        {
        case 1:
            system("cls");
            cout << "\t\tCREAR ENRUTADOR \n\n";
            cout << "Ingrese el nombre del enrutador: ";
            cin >> nombreRouter;
            while (!miRed.addEnrutador(nombreRouter)){
                cout << "Ingrese el nombre del enrutador: ";
                cin >> nombreRouter;
            }
            cout << "Enrutador '" << nombreRouter << "' correctamente agregado a la red. \n";

            system("pause");
            break;

        case 2:
            system("cls");
            cout << "\t\tELIMINAR UN ENRUTADOR \n\n";
            cout << "Ingrese el nombre del enrutador: ";
            cin >> nombreRouter;
            while (!miRed.delEnrutador(nombreRouter)){
                cout << "\nIngrese el nombre del enrutador: ";
                cin >> nombreRouter;
            }

            system("pause");
            break;

        case 3:
            system("cls");
            cout << "\t\tMODIFICAR ENRUTADOR \n\n";
            cout << "Ingrese el nombre del enrutador: ";
            cin >> nombreRouter;
            while (!miRed.existeEnrutador(nombreRouter)){
                cout << "\nEl enrutador no existe. \n";
                cout << "Ingrese el nombre del enrutador: ";
                cin >> nombreRouter;
            }

            int op2;
            do{
                op2=0;
                cout << "\n\nQue deseas hacer con el enrutador '" << nombreRouter << "' ? \n";
                cout << "Elija una opcion: \n";
                cout << "(1) Modificar un nodo (Cambiar su costo).\n";
                cout << "(2) Remover un nodo (Desconectarlo de un enrutador).\n";
                cout << "(3) Mostrar tabla de enrutamiento de '" << nombreRouter <<"'.\n";
                cout << "(4) Volver al menu principal.\n";
                cout << "Opcion: ";
                cin >>op2;

                string nombreNodo;
                int costo;
                bool nodoEnTabla;
                switch (op2)
                {
                case 1:
                    system("cls");
                    cout << "\t\tENRUTADOR '" << nombreRouter << "' \n\n";
                    cout << "\t\tMODIFICAR UN NODO \n\n";
                    cout << "Ingrese el nombre del nodo"
                            ": ";
                    cin >> nombreNodo;
                    cout << "\nIngrese el costo de la conexion a ese nodo: ";
                    cin >> costo;

                    while (!miRed.existeEnrutador(nombreNodo)){
                            cout << "\nEl enrutador '"<< nombreNodo <<"' no existe. \n";
                            cout << "\nIngrese de nuevo el nombre del enrutador: ";
                            cin >> nombreNodo;
                            cout << "\nIngrese el costo de la conexion a ese nodo: ";
                            cin >> costo;
                        }

                    if (miRed.getRed().at(nombreNodo).modNodo(nombreRouter, costo) && miRed.getRed().at(nombreRouter).modNodo(nombreNodo, costo)) {
                        cout<<"\nLa conexion '"<<nombreNodo<<"' <-> '"<<nombreRouter<<"' ahora tiene un nuevo costo de "<< costo <<".\n";
                    }
                    else cout << "Error al modificar '"<<nombreNodo<<"' desde enrutador '" << nombreRouter <<"'. \n";

                    system("pause");
                    break;

                case 2:
                    system("cls");
                    cout << "\t\tENRUTADOR '" << nombreRouter << "' \n\n";
                    cout << "\t\tREMOVER UN NODO \n\n";
                    cout << "Ingrese el nombre del nodo (Enrutador ya creado): ";
                    cin >> nombreNodo;

                    nodoEnTabla = miRed.getRed().at(nombreRouter).nodoConectado(nombreNodo);
                    while (!miRed.existeEnrutador(nombreNodo) || !nodoEnTabla || nombreNodo == nombreRouter){
                        if (!nodoEnTabla){
                            cout << "\n El nodo NO esta conectado al enrutador '"<<nombreRouter <<"'\n";
                            break;
                        }
                        else if (nombreNodo==nombreRouter) cout << "Nombre invalido, es igual al nombre del enrutador\n";
                        else cout << "\nEl enrutador no existe. \n";

                        cout << "\nIngrese de nuevo el nombre del enrutador: ";
                        cin >> nombreNodo;
                    }

                    if (nodoEnTabla && miRed.getRed().at(nombreRouter).delNodo(nombreNodo) && miRed.getRed().at(nombreNodo).delNodo(nombreRouter)) {
                        cout<<"\nNodo '"<<nombreNodo<<"' removido del enrutador '"<<nombreRouter<<"' con exito.\n";
                    }
                    else cout << "Error al remover un nodo del enrutador '"<<nombreRouter<<"'. \n";

                    system("pause");
                    break;

                case 3:
                    miRed.getRed().at(nombreRouter).showtablaDeEnrutamiento();
                        system("pause");
                    break;

                case 4:
                    cout << "Opcion no disponible. \n";
                    system("pause");
                    break;

                default:
                    break;
                }

                system("cls");
            }
            while(op2!=4);

            break;

        case 4:
            system("cls");
            cout << "\t\tCOTIZAR ENVIO\n\n";
            cout << "Ingrese el nombre del enrutador origen: ";
            cin >> origen;

            while(!miRed.existeEnrutador(origen)){
                cout << "\n\nEl enrutador no existe. \n";
                cout << "Ingrese el nombre del enrutador origen: ";
                cin >> origen;
            }

            cout << "\nElija enrutador de destino";
            miRed.getRed().at(origen).showtablaDeEnrutamiento();

            cout << "\n\nIngrese el nombre del enrutador destino: ";
            cin >> destino;
            while(!miRed.existeEnrutador(destino)){
                cout << "\n\nEl enrutador no existe. \n";
                cout << "Ingrese el nombre del enrutador origen: \n";
                cin >> destino;
            }

            for (int i=0; i<(int)miRed.getRed().size()-2; i++){

            }
            break;

        case 5: miRed.showRed();
            system("pause");
            break;

        case 6: cout << "Saliste del programa, adios.\n\n";
            system("pause");
            break;

        default: cout << "Opcion invalida \n";
            system("pause");
            break;
        }

        system("cls");
    }
    while(op!=6);

    return 0;
}
