#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:

    string cheminFichier;
    string utilisateur;
    string motDePasse;

    static Configuration* instance;
    
    Configuration(const string& chemin, const string& util, const string& motdp){
       cheminFichier=chemin;
	   utilisateur=util;
	   motDePasse=motdp;
    }
public:
  
    static Configuration* getInstance(const string& chemin = "", const string& util = "", const string& motdp = "") {
        if (instance == nullptr) {
            instance = new Configuration(chemin, util, motdp);
        }
        return instance;
    }
    void afficherParametres() const {
        cout << "Chemin du fichier : " << cheminFichier << endl;
        cout << "Utilisateur       : " << utilisateur << endl;
        cout << "Mot de passe      : " << motDePasse << endl;
    }
};
  Configuration* Configuration::instance = NULL;
int main() {
    Configuration* config1 = Configuration::getInstance("C:/App/config.init", "fatima", "2004");
    config1->afficherParametres();

    Configuration* config2 = Configuration::getInstance("D:/Data/other.txt", "user", "abcd");
    config2->afficherParametres();

    if (config1 == config2)
        cout << "\nSingleton confirme." << endl;
    else
        cout << "\nerreur !" << endl;

    return 0;
}
