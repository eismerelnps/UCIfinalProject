#include <iostream>

using namespace std;
const int years = 2;
const int months = 12;
float annualTemperatures[years][months] = {
        {27.0, 28.0, 15.0, 37.0, 32.0, 38.0, 35.0, 34.0, 27.0, 250.0, 14.0, 13.0},
        {24.0, 32.0, 17.0, 21.0, 32.0, 32.0, 37.5, 33.0, 32.5, 25.5,  13.0, 11.0}
};

//checks if the provided year to functions is valid
bool checkBounds(int year) {
    if (year < years || year > years) {
        return true;
    } else {
        return false;
    }
}

int showAllTemperatures() {
    for (int i = 0; i < years; i++) {
        for (int j = 0; j < months; j++) {
            cout << "temperaturasAnuales[" << i << "][" << j << "]: " << annualTemperatures[i][j] << endl;
        }
    }
}

//function for lower temperature from a specific year
int lowerTemperature(int year) {
    float minTemperature = annualTemperatures[year][0];
    if (checkBounds(year)) {

        for (int i = 0; i < months; i++) {
            if (annualTemperatures[year][i] < minTemperature) {
                minTemperature = annualTemperatures[year][i];
            }
        }
    }


    return minTemperature;
}

int countTemperaturesBelow(float temperature) {
    int count = 0;

    for (int i = 0; i < years; i++) {
        for (int j = 0; j < months; j++) {
            if (annualTemperatures[i][j] < temperature) {
                count++;
            }
        }
    }

    return count;
}

int findYearWithHighestAverageTemperature() {
    int yearWithHighestAverage = 0;
    float highestAverage = 0.0;

    for (int i = 0; i < years; i++) {
        float sum = 0.0;
        for (int j = 0; j < months; j++) {
            sum += annualTemperatures[i][j];
        }
        float average = sum / months;
        if (average > highestAverage) {
            highestAverage = average;
            yearWithHighestAverage = i;
        }
    }

    return yearWithHighestAverage + 2009;
}


int main() {
    int option;

    do {
        // Mostrar el menú de opciones
        cout << "----- Menú -----" << endl;
        cout << "1. Obtener la temperatura más baja para un año" << endl;
        cout << "2. Contar la cantidad de temperaturas por debajo de un valor" << endl;
        cout << "3. Obtener el año con la temperatura promedio más alta" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: "<<endl;
        cin >> option;

        switch (option) {
            case 1: {
                int year;
                cout << "Ingrese  '0' para el año 2009, '1' para el año 2010): "<<endl;
                cin >> year;
                if (checkBounds(year)) {
                    cout << "La temperatura minima en el ano " << year << " fue: " << lowerTemperature(0)<< "°C " << endl;
                } else {
                    cout << "Año inválido. Intente nuevamente." << endl;
                }
                break;
            }
            case 2: {
                float temperatureToSearch;
                cout << "Ingrese el valor de la temperatura a buscar " << endl;
                cin >> temperatureToSearch;
                cout << "Se registraron " << countTemperaturesBelow(temperatureToSearch)
                     << " temperaturas por debajo de " << temperatureToSearch << endl;
                break;
            }
            case 3: {
                cout << "El ano con la mayor temperatura promedio fue: " << findYearWithHighestAverageTemperature()
                     << endl;
            }
            case 4: {
                cout << "Gracias por utilizar nuestros servicios... Vuelva pronto.";
                break;
            }
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;

        }
    } while (option != 4);


    return 0;
}