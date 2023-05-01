#include <iostream>
#include <enrutador.h>
#include <red.h>
#include <string>

using namespace std;

int main()
{
    red miRed;

    int numEnrutadores = 0;
    cout << "\t\tSimulador de red de Enrutadores \n\n";
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
            cout << "Ingrese el nombre del enrutador #" <<i+1 << ": ";
            cin >> nombreRouter;
        }
    }

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
        cout << "(5) Salir.\n";
        cout << "Opcion: ";
        cin >>op;

        switch(op)
        {
        case 1:
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
            cout << "\t\tELIMINAR UN ENRUTADOR \n\n";
            cout << "Ingrese el nombre del enrutador: ";
            cin >> nombreRouter;
            while (!miRed.delEnrutador(nombreRouter)){
                cout << "Ingrese el nombre del enrutador: ";
                cin >> nombreRouter;
            }

            system("pause");
            break;

        case 3:
            cout << "\t\tMODIFICAR ENRUTADOR \n\n";
            cout << "Ingrese el nombre del enrutador: ";
            cin >> nombreRouter;
            while (!miRed.existeEnrutador(nombreRouter)){
                cout << "El enrutador no existe. \n";
                cout << "Ingrese el nombre del enrutador: ";
                cin >> nombreRouter;
            }

            int op2;
            do{
                op2=0;
                cout << "\nQue deseas hacer con el enrutador " << nombreRouter << " ? \n";
                cout << "Elija una opcion: \n";
                cout << "(1) Agregar un nodo (Conectarlo con otro enrutador).\n";
                cout << "(2) Eliminar un nodo (Desconectarlo de un enrutador).\n";
                cout << "(3) Modificar un nodo (Cambiar su costo).\n";
                cout << "(4) Volver al menu principal.\n";
                cout << "Opcion: ";
                cin >>op2;
                switch (op2)
                {
                case 1:
                    string nombreNodo;
                    cout << "\t\tAGREGAR UN NODO \n\n";
                    cout << "Ingrese el nombre del nodo (Enrutador ya creado): ";
                    cin >> nombreNodo;
                    while (!miRed.existeEnrutador(nombreNodo)){
                        cout << "\nEl enrutador no existe. \n";
                            cout << "Ingrese el nombre del enrutador: ";
                        cin >> nombreNodo;
                    }

                    cout << "\nIngrese el costo de la conexion a ese nodo: ";


                    break;

                /*case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    break;*/
                }
            }
            while(op2!=4);

            break;

        case 4:

            break;


        case 5: cout << "Saliste del programa, adios.\n\n";
            break;

        default: cout << "Opcion invalida \n";
            system("pause");
            break;
        }

        system("cls");
    }
    while(op!=5);

    return 0;
}
