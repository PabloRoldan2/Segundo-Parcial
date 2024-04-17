#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Empleado {
	string nombre, apellido;
	float precio;
	int salario, edad;
};

const string archivoEmpleado = "empleados.txt";

//****************************************************
void crearEmpleado() {
	system("cls");
    ofstream archivo(archivoEmpleado, ios::app);
    Empleado nuevoEmpleado;
	
	cout << "Ingresar Empleado" << endl;
    cout << "Ingrese el nombre del empleado: ";
    cin >> nuevoEmpleado.nombre;
    cout << "Ingrese el apellido del empleado: ";
    cin >> nuevoEmpleado.apellido;
    cout << "Ingrese la edad del empleado: ";
    cin >> nuevoEmpleado.edad;
    cout << "Ingrese el salario del empleado: ";
    cin >> nuevoEmpleado.salario;

    archivo << nuevoEmpleado.nombre << " " << nuevoEmpleado.apellido << " " << nuevoEmpleado.edad << " " << nuevoEmpleado.salario << endl;
	
    archivo.close();
    cout << "Empleado creado con exito." << endl;
    system("pause");
}

//****************************************************
void leerEmpleado() {
	system("cls");
    ifstream archivo(archivoEmpleado);
    Empleado empleado;
	cout << "Empleados" << endl;
    while (archivo >> empleado.nombre >> empleado.apellido >> empleado.edad >> empleado.salario) {
    	cout << "--------------------------" << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Edad: " << empleado.edad << endl;
        cout << "Salario: " << empleado.salario << endl;
        cout << "--------------------------" << endl;
    }

    archivo.close();
    system("pause");
}

//****************************************************
void modificarEmpleado(string nombre) {
	
	system("cls");
	cout << "Ingrese el nombre del empleado que desea modificar: ";
    cin >> nombre;
   
    ifstream archivoLectura(archivoEmpleado);
    ofstream archivoEscritura("temp.txt");

    Empleado empleado;
    bool encontrado = false;
    
    while (archivoLectura >> empleado.nombre >> empleado.apellido >> empleado.edad >> empleado.salario) {
    	
    		
            
        if (empleado.nombre == nombre) {
        	cout << "--------------------------" << endl;
            cout << "Nombre: " << empleado.nombre << endl;
            cout << "Apellido: " << empleado.apellido << endl;
            cout << "Edad: " << empleado.edad << endl;
            cout << "Salario: " << empleado.salario << endl;
            cout << "--------------------------" << endl;
            
            cout << "Ingrese el nuevo nombre del empleado: ";
            cin >> empleado.nombre;
            cout << "Ingrese el nuevo apellido del empleado: ";
            cin >> empleado.apellido;
            cout << "Ingrese la nueva edad del empleado: ";
            cin >> empleado.edad;
            cout << "Ingrese el nuevo salario del empleado: ";
            cin >> empleado.salario;
            encontrado = true;
        }
        archivoEscritura << empleado.nombre << " " << empleado.apellido << " " << empleado.edad << " " << empleado.salario << endl;
    }

    archivoLectura.close();
    archivoEscritura.close();

    if (encontrado) {
        remove(archivoEmpleado.c_str());
        rename("temp.txt", archivoEmpleado.c_str());
        cout << "Empleado modificado con exito." << endl;
    } else {
        remove("temp.txt");
        cout << "Empleado no encontrado." << endl;
    }
    system("pause");
}

//****************************************************
void eliminarEmpleado(string nombre) {
	system("cls");
	cout << "Ingrese el nombre del empleado que desea eliminar: ";
    cin >> nombre;
    ifstream archivoLectura(archivoEmpleado);
    ofstream archivoEscritura("temp.txt");

    Empleado empleado;
    bool encontrado = false;

    while (archivoLectura >> empleado.nombre >> empleado.apellido >> empleado.edad >> empleado.salario) {
        if (empleado.nombre == nombre) {
            encontrado = true;
        } else {
            archivoEscritura << empleado.nombre << " " << empleado.apellido << " " << empleado.edad << " " << empleado.salario << endl;
        }
    }

    archivoLectura.close();
    archivoEscritura.close();

    if (encontrado) {
        remove(archivoEmpleado.c_str());
        rename("temp.txt", archivoEmpleado.c_str());
        cout << "Empleado eliminado con exito." << endl;
    } else {
        remove("temp.txt");
        cout << "Empleado no encontrado." << endl;
    }
    system("pause");
}

//****************************************************
int main() {
	system("color 8e");
    int opcion;
    int codigo;

    do {
    	system("cls");
        cout << "Gestion de Empleados" << endl;
        cout << "1. Crear un empleado" << endl;
        cout << "2. Ver empleados" << endl;
        cout << "3. Modificar un empleado" << endl;
        cout << "4. Eliminar un empleado" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearEmpleado();
                break;
            case 2:
                leerEmpleado();
                break;
            case 3:
                modificarEmpleado(nombre);
                break;
            case 4:
                eliminarEmpleado(nombre);
                break;
            case 5:
                cout << "!Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}