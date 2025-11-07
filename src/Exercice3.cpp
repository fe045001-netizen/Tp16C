#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observateur {
public:
    virtual void mettreAJour(float temperature, float humidite, float pression)  const = 0;
    virtual ~Observateur() {}
};


class StationMeteo {
private:
    float temperature;
    float humidite;
    float pression;
    vector<Observateur*> observateurs;

public:
    void ajouterObservateur(Observateur* obs) {
        observateurs.push_back(obs);
    }

    void retirerObservateur(Observateur* obs) {
        observateurs.erase(remove(observateurs.begin(), observateurs.end(), obs), observateurs.end());
    }

    void notifierObservateurs() {
        for (auto obs : observateurs) {
            obs->mettreAJour(temperature, humidite, pression);
        }
    }

    void setMesures(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;
        notifierObservateurs();
    }
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float temperature, float humidite, float pression) const override {
        cout << "Temperature: " << temperature << " degreC" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float temperature, float humidite, float pression)const override {
        cout << "Humidite: " << humidite << " %" << endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(float temperature, float humidite, float pression) const override {
        cout << "Pression : " << pression << " hPa" << endl;
    }
};

int main() {
    StationMeteo station;

    AffichageTemperature temp;
    AffichageHumidite hum;
    AffichagePression pres;

    station.ajouterObservateur(&temp);
    station.ajouterObservateur(&hum);
    station.ajouterObservateur(&pres);

    cout << "---- Mesures 1 ----" << endl;
    station.setMesures(18, 30, 1011.0);

    cout << "\n---- Mesures 2 ----" << endl;
    station.setMesures(25.0, 60.0, 1013.5);

    return 0;
}

