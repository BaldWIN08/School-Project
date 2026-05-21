#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>  
#include <cstdlib>    
#include <ctime>      
using namespace std;

double x;
double y;

struct Ebike {
    int id;
    double x;
    double y;
    bool disponibile;
    double autonomia;
};

double distanza(Ebike bike) {
    return sqrt(pow(bike.x - x, 2) + pow(bike.y - y, 2));
}

bool confronta(Ebike bike1, Ebike bike2) {
    return distanza(bike1) < distanza(bike2);
}

int main() {

    Ebike array_Ebike[8];
    array_Ebike[0] = {1, 10.5, 20.3, true, 40.0};
    array_Ebike[1] = {2, 15.0, 25.0, false, 23.0};
    array_Ebike[2] = {3, 12.2, 18.4, true, 55.0};
    array_Ebike[3] = {4, 8.0, 22.0, true, 67.0};
    array_Ebike[4] = {5, 14.5, 19.7, false, 32.0};
    array_Ebike[5] = {6, 9.8, 16.5, true, 12.0};
    array_Ebike[6] = {7, 11.0, 21.0, true, 18.0};
    array_Ebike[7] = {8, 13.3, 17.8, false, 7.0};

    cout << "Inserire la tua posizione X: ";
    cin >> x;
    cout << "Inserire la tua posizione Y: ";
    cin >> y;

    sort(array_Ebike, array_Ebike + 8, confronta);

    cout << "\n Bici disponibili ordinate per distanza \n";
    for (int i = 0; i < 8; i++) {
        if (array_Ebike[i].disponibile) {
            cout << "ID: " << array_Ebike[i].id
                 << " | Coordinate: (" << array_Ebike[i].x << ", " << array_Ebike[i].y << ")"
                 << " | Autonomia: " << array_Ebike[i].autonomia << " km"
                 << " | Distanza: " << distanza(array_Ebike[i]) << " km\n";
        }
    }

    int scelta;
    cout << "\n Inserire l'ID della bici che vuoi noleggiare: ";
    cin >> scelta;
    
    
    Ebike* biciScelta = nullptr;

    for (int i = 0; i < 8; i++) {
        if (array_Ebike[i].id == scelta && array_Ebike[i].disponibile) {
            biciScelta = &array_Ebike[i];
            break;
        }
    }
    
    if (biciScelta == nullptr) {
        cout << "Errore: bici non trovata/non disponibile.\n";
        return 0;
    }

    double km;
    cout << "Quanti km intendi percorrere? ";
    cin >> km;

    if (km > biciScelta->autonomia) {
        cout << "Noleggio negato: autonomia bici insufficiente.\n";
        return 0;
    }

    srand(time(0));
    double velocita_media = 20.0;
    double tempo_minuti = (km / velocita_media) * 60;


    int ritardo = rand() % 15 + 1;
    tempo_minuti += ritardo;
    
    
    biciScelta->autonomia -= km;

    double costo = tempo_minuti * 0.20;

    cout << "\n RIEPILOGO NOLEGGIO \n";
    cout << "Bici ID: " << biciScelta->id << "\n";
    cout << "Km percorsi: " << km << "\n";
    cout << "Tempo stimato: " << tempo_minuti << " minuti\n";
    cout << "Costo totale: " << costo << " euro\n";

    biciScelta->disponibile = true;

    cout << "\nNoleggio completato. La bici è ora nuovamente disponibile.\n";

    return 0;
}