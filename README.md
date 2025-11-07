#TP 16 : Patrons de conception

#Exercice 1 : Implémentation du patron Singleton

![URL image](https://github.com/fe045001-netizen/Tp16C/blob/67cf5175ff2e8471d45717bbee56be79bcaec943/images/Exercice1.png)

Pourquoi le constructeur doit-il être privé ?
    Le constructeur doit être rendu privé afin d'éviter toute instanciation externe de la classe, ce qui compromettrait le principe du Singleton.
Quelles sont les limites de ce patron dans les environnements multithreadés ? en c++
    Dans un contexte de multithreading, il est possible que deux threads exécutent simultanément instance = new Singleton(), ce qui entraînerait la création de deux instances différentes.

#Exercice 2 : Utilisation du patron Fabrique (Factory Method)

![URL image](https://github.com/fe045001-netizen/Tp16C/blob/67cf5175ff2e8471d45717bbee56be79bcaec943/images/Exercice2.png)

<h1 align="center">Quelle est l’utilité du pattern Factory dans un contexte d’extension future ?</h1>
<p>Le <strong>pattern Factory</strong> Permet de créer des objets sans connaître leur classe exacte par la suite facilite l’ajout de nouveaux types d’objets sans casser le code existant.
Comment rendre le système plus modulaire avec une classe abstraite FabriqueAbstraite ?
  Chaque fabrique  (FabriqueCercle, FabriqueCarre, FabriqueTriangle) tire sa descendance de FabriqueAbstraite, par la suiteLe client ne travaille qu'avec FabriqueAbstraite et a la possibilité de modifier la fabrique lors de l'exécution.
</p>  
