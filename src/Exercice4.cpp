#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class StrategieTri {
public:
    virtual void trier(vector<string>& donnees) = 0;
    virtual ~StrategieTri() {}
};

class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& donnees) override {
        sort(donnees.begin(), donnees.end());
    }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& donnees) override {
        sort(donnees.rbegin(), donnees.rend());
    }
};

bool comparerParLongueur(const string& a, const string& b) {
    return a.size() < b.size();
}

class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& donnees) override {
        sort(donnees.begin(), donnees.end(), comparerParLongueur);
    }
};

class GestionnaireTri {
private:
    StrategieTri* strategie; 
public:
    GestionnaireTri(StrategieTri* strat = nullptr) {
    	strategie=strat;
	}

    void setStrategie(StrategieTri* strat) {
	 strategie = strat;
	  }

    void trierDonnees(vector<string>& donnees) {
        if (strategie) strategie->trier(donnees);
    }
};

void afficherVecteur(const vector<string>& donnees) {
    for (const auto& d: donnees) cout << d << " ";
    cout << endl;
}

int main() {
    vector<string> pays = {"Maroc", "Allemagne", "Italie", "Japon", "Bali"};

    TriCroissant croissant;
    TriDecroissant decroissant;
    TriParLongueur parLongueur;

    GestionnaireTri gestionnaire;
    cout << "Les pays: ";
    afficherVecteur(pays);

    gestionnaire.setStrategie(&croissant);
    gestionnaire.trierDonnees(pays);
    cout << "Tri croissant : ";
    afficherVecteur(pays);

    gestionnaire.setStrategie(&decroissant);
    gestionnaire.trierDonnees(pays);
    cout << "Tri decroissant : ";
    afficherVecteur(pays);

    gestionnaire.setStrategie(&parLongueur);
    gestionnaire.trierDonnees(pays);
    cout << "Tri par longueur : ";
    afficherVecteur(pays);

    return 0;
}

