#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string nombre, matricula;
    float calif[3];
    int grupo;
};

struct Maestro {
    string nombre, materia;
};

struct Grupo {
    string nombre, carrera;
};

int main() {
    Alumno alumnos[100];
    Maestro maestros[50];
    Grupo grupos[20];
    int na = 0, nm = 0, ng = 0, op;

    do {
        cout << "\n1. Capturar grupos y carreras";
        cout << "\n2. Capturar alumnos";
        cout << "\n3. Capturar maestros";
        cout << "\n4. Promedios de alumnos";
        cout << "\n5. Mejor alumno por grupo";
        cout << "\n6. Alumnos por carrera";
        cout << "\n7. Mostrar maestros";
        cout << "\n8. Salir\nOpcion: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            int n;
            cout << "Cantidad de grupos: ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n && ng < 20; i++) {
                cout << "Nombre del grupo: ";
                getline(cin, grupos[ng].nombre);
                cout << "Carrera: ";
                getline(cin, grupos[ng].carrera);
                ng++;
            }
        }

        else if (op == 2) {
            if (ng == 0) {
                cout << "Registra grupos primero.\n";
            }
            else {
                int n;
                cout << "Cantidad de alumnos: ";
                cin >> n;
                cin.ignore();

                for (int i = 0; i < n && na < 100; i++) {
                    cout << "Nombre: ";
                    getline(cin, alumnos[na].nombre);
                    cout << "Matricula: ";
                    getline(cin, alumnos[na].matricula);

                    for (int j = 0; j < 3; j++) {
                        cout << "Calificacion " << j + 1 << ": ";
                        cin >> alumnos[na].calif[j];
                    }

                    cout << "Grupos disponibles:\n";
                    for (int g = 0; g < ng; g++)
                        cout << g + 1 << ". "
                        << grupos[g].nombre << "\n";

                    cout << "Numero de grupo: ";
                    cin >> alumnos[na].grupo;
                    cin.ignore();
                    na++;
                }
            }
        }

        else if (op == 3) {
            int n;
            cout << "Cantidad de maestros: ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n && nm < 50; i++) {
                cout << "Nombre: ";
                getline(cin, maestros[nm].nombre);
                cout << "Materia: ";
                getline(cin, maestros[nm].materia);
                nm++;
            }
        }

        else if (op == 4) {
            for (int i = 0; i < na; i++) {
                float p = (alumnos[i].calif[0] +
                    alumnos[i].calif[1] +
                    alumnos[i].calif[2]) / 3;

                cout << alumnos[i].nombre
                    << " Promedio: " << p << "\n";
            }
        }

        else if (op == 5) {
            for (int g = 1; g <= ng; g++) {
                int mejor = -1;
                for (int i = 0; i < na; i++) {
                    if (alumnos[i].grupo == g) {
                        if (mejor == -1 ||
                            (alumnos[i].calif[0] +
                                alumnos[i].calif[1] +
                                alumnos[i].calif[2]) >
                            (alumnos[mejor].calif[0] +
                                alumnos[mejor].calif[1] +
                                alumnos[mejor].calif[2]))
                            mejor = i;
                    }
                }

                cout << grupos[g - 1].nombre << ": ";
                if (mejor == -1)
                    cout << "Sin alumnos\n";
                else
                    cout << alumnos[mejor].nombre << "\n";
            }
        }

        else if (op == 6) {
            for (int g = 0; g < ng; g++) {
                bool repetida = false;

                for (int k = 0; k < g; k++)
                    if (grupos[k].carrera == grupos[g].carrera)
                        repetida = true;

                if (!repetida) {
                    int total = 0;
                    for (int i = 0; i < na; i++)
                        if (alumnos[i].grupo >= 1 &&
                            alumnos[i].grupo <= ng &&
                            grupos[alumnos[i].grupo - 1].carrera ==
                            grupos[g].carrera)
                            total++;

                    cout << grupos[g].carrera
                        << ": " << total << " alumnos\n";
                }
            }
        }

        else if (op == 7) {
            for (int i = 0; i < nm; i++)
                cout << maestros[i].nombre << " - "
                << maestros[i].materia << "\n";
        }

    } while (op != 8);

    cout << "Programa finalizado.\n";
    return 0;
}
