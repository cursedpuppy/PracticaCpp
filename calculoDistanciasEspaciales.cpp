#include <iostream>

#include <cmath> //funciones matematicas

using namespace std;

double dy = 365.25;

double hd = 24;

long double c = 299792.458;

long double ua_km = 149597828.68;

struct DistanceConversion
{

    long double year_entero;

    long double dia_entero;

    long double hora_entero;
};

// Funcion para convertir años luz a tiempo (dias y horas)

DistanceConversion distanceToTime(long double distancia)
{

    long double scnd_km = distancia / c;

    long double year_km = (((scnd_km / 3600) / hd) / dy);

    // Calculo dias y año

    long double ly_int;

    long double ly_dec = modf(year_km, &ly_int);

    long double days = dy * ly_dec;

    // Calculo horas

    long double day_int;

    long double days_dec = modf(days, &day_int);

    long double hours = hd * days_dec;

    long double hours_int;

    long double hours_dec = modf(hours, &hours_int);

    return {ly_int, day_int, hours_int};
}

void print_result(long double distancia)
{

    DistanceConversion time_split = distanceToTime(distancia);

    long double year = time_split.year_entero;

    long double dias = time_split.dia_entero;

    long double horas = time_split.hora_entero;

    cout << "La luz demoraria " << year << " anios, " << dias << " dias y " << horas << " horas" << "\n";
}

int main()
{

    int eleccion = 0;

    while (eleccion < 4)
    {

        cout << "Escoja la unidad de medida de la DISTANCIA:" << "\n";

        cout << "[1]Kilometros, [2]Unidad Astronomica (UA), [3]Anios Luz, [4]Salir" << "\n";

        cin >> eleccion;

        if (eleccion == 1)
        {

            long double km;

            cout << "Ingrese kilometros: " << "\n";

            cin >> km;

            print_result(km);
        }

        else if (eleccion == 2)
        {

            long double ua;

            cout << "Ingrese unidades astronomicas (UA)" << "\n";

            cin >> ua;

            long double ua_convers = ua * ua_km;

            print_result(ua_convers);
        }

        else if (eleccion == 3)
        {

            long double ly;

            cout << "Ingrese anios luz: " << "\n";

            cin >> ly;

            long double ly_km = c * ly;

            print_result(ly_km);
        }
    }

    return 0;
}