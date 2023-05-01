#include <iostream>
#include <enrutador.h>
#include <red.h>
#include <string>
#include <map>

using namespace std;

int main()
{
    red miRed;
    miRed.addEnrutador("A");
    miRed.addEnrutador("B");
    miRed.addEnrutador("C");
    miRed.addEnrutador("D");

    /*int numEnrutadores = 0;
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
    }*/

    string nombreRouter; //eliminar luego de la prueba
    int op;
    system("cls");
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
                cout << "(1) Agregar un nodo (Conectarlo con otro enrutador).\n";
                cout << "(2) Remover un nodo (Desconectarlo de un enrutador).\n";
                cout << "(3) Modificar un nodo (Cambiar su costo).\n";
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
                    cout << "\t\tAGREGAR UN NODO \n\n";
                    cout << "Ingrese el nombre del nodo (Enrutador ya creado): ";
                    cin >> nombreNodo;
                    cout << "\nIngrese el costo de la conexion a ese nodo: ";
                    cin >> costo;

                    nodoEnTabla = miRed.getRed().at(nombreRouter).nodoConectado(nombreNodo);
                    while (!miRed.existeEnrutador(nombreNodo) || nodoEnTabla){
                        if (nodoEnTabla){
                            cout << "\nEl nodo ya esta conectado al enrutador '"<<nombreRouter <<"'\n\n";
                            break;
                        }
                        else cout << "\nEl enrutador no existe. \n";

                        cout << "\nIngrese de nuevo el nombre del enrutador: ";
                        cin >> nombreNodo;
                        cout << "\nIngrese el costo de la conexion a ese nodo: ";
                        cin >> costo;
                    }

                    if (!nodoEnTabla && miRed.getRed().at(nombreRouter).addNodo(nombreNodo, costo)) {
                        cout<<"\nNodo '"<<nombreNodo<<"' agregado al enrutador '"<<nombreRouter<<"' con exito.\n";
                    }
                    else cout << "Error al agregar un nodo en el enrutador '"<<nombreRouter<<"'. \n";

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

                    if (nodoEnTabla && miRed.getRed().at(nombreRouter).addNodo(nombreNodo, costo)) {
                        cout<<"\nNodo '"<<nombreNodo<<"' removido del enrutador '"<<nombreRouter<<"' con exito.\n";
                    }
                    else cout << "Error desconocido al remover un nodo del enrutador '"<<nombreRouter<<"'. \n";

                    system("pause");
                    break;

                    /*case 3:
                    break;
                case 4:
                    break;*/
                default: cout << "\nOpcion invalida.\n";
                        system("pause");
                    break;
                }

                system("cls");
            }
            while(op2!=4);

            break;

        case 4:

            break;

        case 5: miRed.showRed();
            system("pause");
            break;

        case 6: cout << "Saliste del programa, adios.\n\n";
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
