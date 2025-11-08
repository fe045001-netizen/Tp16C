<h1 align="center">TP 16 : Patrons de conception</h1>

# Exercice 1 : Implémentation du patron Singleton

![URL image](https://github.com/fe045001-netizen/Tp16C/blob/67cf5175ff2e8471d45717bbee56be79bcaec943/images/Exercice1.png)

<h2>Pourquoi le constructeur doit-il être privé ?</h2>
    Le constructeur doit être rendu privé afin d'éviter toute instanciation externe de la classe, ce qui compromettrait le principe du Singleton.
<h2>Quelles sont les limites de ce patron dans les environnements multithreadés ? </h2>
    Dans un contexte de multithreading, il est possible que deux threads exécutent simultanément instance = new Singleton(), ce qui entraînerait la création de deux instances différentes.

# Exercice 2 : Utilisation du patron Fabrique (Factory Method)

![URL image](https://github.com/fe045001-netizen/Tp16C/blob/67cf5175ff2e8471d45717bbee56be79bcaec943/images/Exercice2.png)

<h2 >Quelle est l’utilité du pattern Factory dans un contexte d’extension future ?</h2>
Le <strong>pattern Factory</strong> Permet de créer des objets sans connaître leur classe exacte par la suite facilite l’ajout de nouveaux types d’objets sans casser le code existant.
<h2>Comment rendre le système plus modulaire avec une classe abstraite FabriqueAbstraite ?</h2>
  Chaque fabrique  (FabriqueCercle, FabriqueCarre, FabriqueTriangle) tire sa descendance de FabriqueAbstraite, par la suiteLe client ne travaille qu'avec FabriqueAbstraite et a la possibilité de modifier la fabrique lors de l'exécution.
  
# Exercice 3 : Application du patron Observateur (Observer)

![URL image](https://github.com/fe045001-netizen/Tp16C/blob/67cf5175ff2e8471d45717bbee56be79bcaec943/images/Exercice3.png)


<h2>Comment éviter une forte dépendance entre le sujet et les observateurs ?</h2>
    En utilisant une interface abstraite pour assurer un découplage, le sujet ne sera exposé que à l'interface des observateurs.
<h2>Quelle alternative moderne offre la bibliothèque standard pour cela ? </h2>
     La bibliothèque std::function et à des expressions lambda pour la gestion des rétroactions dynamiques.

# Exercice 4 : Mise en œuvre du patron Stratégie (Strategy)


![URL image](https://github.com/fe045001-netizen/Tp16C/blob/67cf5175ff2e8471d45717bbee56be79bcaec943/images/Exercice4.png)

 <h2>En quoi ce modèle améliore-t-il la maintenabilité du code ? </h2>
 Le modèle Stratégie facilite l'intégration ou la modification d'algorithmes sans la nécessite de modifications dans le code principal.
 <h2>Quelle différence avec le pattern Template Method ? </h2>
La stratégie sélectionne dynamiquement l'algorithme , alors que la Méthode Template Method établit une structure rigide avec des phases redéfinies dans les sous-classes.
