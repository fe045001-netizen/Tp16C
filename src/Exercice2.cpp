#include <iostream>
#include <string>
using namespace std;

class Forme {
public:
    virtual void afficher() const = 0; 
    virtual ~Forme() {}
};

class Cercle : public Forme {
public:
    void afficher() const override {
        cout << "Cercle." << endl;
    }
};

class Carre : public Forme {
public:
    void afficher() const override {
        cout << "Carre." << endl;
    }
};

class Triangle : public Forme {
public:
    void afficher() const override {
        cout << "Triangle." << endl;
    }
};

class FabriqueAbstraite {
public:
    virtual Forme* forme() const = 0; 
    virtual ~FabriqueAbstraite() {}
};

class FabriqueCercle : public FabriqueAbstraite {
public:
    Forme* forme() const override { 
	return new Cercle(); 
	}
};

class FabriqueCarre : public FabriqueAbstraite {
public:
    Forme* forme() const override { 
	return new Carre(); 
	}
};

class FabriqueTriangle : public FabriqueAbstraite {
public:
    Forme* forme() const override { 
	return new Triangle(); 
	}
};

int main() {

    FabriqueAbstraite* fab1 = new FabriqueCercle();
    FabriqueAbstraite* fab2 = new FabriqueCarre();
    FabriqueAbstraite* fab3 = new FabriqueTriangle();

    Forme* f1 = fab1->forme();
    Forme* f2 = fab2->forme();
    Forme* f3 = fab3->forme();

    f1->afficher();
    f2->afficher();
    f3->afficher();

    delete f1;
    delete f2;
    delete f3;
    delete fab1;
    delete fab2;
    delete fab3;

    return 0;
}

