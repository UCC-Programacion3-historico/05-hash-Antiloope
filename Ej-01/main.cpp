#include <iostream>
#include"../HashMap/HashMap.h"

using namespace std;

unsigned int hashfuncion(int n){return (n*n)%11;};

int main() {

    HashMap<int, int> tabla(11, hashfuncion);
    int opc,salir=0,valor,clave;

    do {
        cout << "Ingrese una opcion: " << endl;
        cout << "  1)Insertar elemento." << '\n';
        cout << "  2)Leer elemento." << '\n';
        cout << "  3)Borrar elemento." << '\n';
        cout << "  4)Salir." << '\n';
        cin >> opc;
        switch (opc) {
          case 1:
            cout << "Ingrese el valor:" << '\n';
            cin >> valor;
            cout << "Ingrese la clave:" << '\n';
            cin >> clave;
            try {
                tabla.put(clave,valor);
            }
            catch (int a) {
                cerr << "La celda esta ocupada" << '\n';
            }
            break;
          case 2:
            cout << "Ingrese la clave:" << '\n';
            cin >> clave;
            try {
                cout << tabla.get(clave) << '\n';
            }
            catch (int a) {
                cerr << "La celda esta vacia" << '\n';
            }
            break;
          case 3:
            cout << "Ingrese la clave: " << '\n';
            cin >> clave;
            try {
                tabla.remove(clave);
            }
            catch (int a) {
                cerr << "La celda estaba vacia" << '\n';
            }
            break;
          case 4:
            salir = 1;
            break;
        }
    } while(salir != 1);
    return 0;
}
