Supermarché Management System
Structure du Projet

Le projet est organisé comme suit :

Supermarcher/
├── database/
│   ├── Database.h
│   └── Database.cpp
├── gestion/
│   ├── GestionClients.h
│   ├── GestionClients.cpp
│   ├── GestionCommandes.h
│   ├── GestionCommandes.cpp
│   ├── GestionFournisseurs.h
│   ├── GestionFournisseurs.cpp
│   ├── GestionInventaire.h
│   ├── GestionInventaire.cpp
│   ├── GestionProduits.h
│   └── GestionProduits.cpp
├── models/
│   ├── Client.h
│   ├── Client.cpp
│   ├── Commande.h
│   ├── Commande.cpp
│   ├── Fournisseur.h
│   ├── Fournisseur.cpp
│   ├── Produit.h
│   └── Produit.cpp
├── utils/
│   ├── Utils.h
│   └── Utils.cpp
├── build/                # Répertoire généré pour les fichiers compilés
├── main.cpp
├── makefile
├── supermarche			  # Executable du projet
├── supermarche.db
├── supermarche.sql
└── README.md             # Documentation du projet

Fonctionnalités

1. Gestion des produits :
   - Ajouter, mettre à jour et supprimer des produits.
   - Rechercher des produits.
   - Afficher la liste des produits.

2. Gestion des commandes :
   - Créer, modifier et supprimer des commandes.
   - Ajouter des produits à une commande.

3. Gestion de l'inventaire :
   - Réapprovisionner des produits.
   - Vérifier la disponibilité des stocks.

4. Gestion des clients et fournisseurs :
   - Ajouter et gérer les informations des clients et fournisseurs.

5. Base de données :
   - Utilisation de SQLite pour persister les données.

6. Utilitaires :
   - Fonctions d’aide pour les formats de données et la manipulation de chaînes.

Dépendances

- Compilateur : GCC avec support pour C++17.
- Base de données : SQLite3.
- Bibliothèques :
  - sqlite3 (inclus par le lien -lsqlite3 lors de la compilation).

Installation et Compilation
### Prérequis

Assurez-vous d'avoir installé :
- GCC (avec support pour C++17).
- SQLite3 et les fichiers d'en-tête.
- Linux ou un environnement Unix-like (testé sur Ubuntu).

### Étapes

1. Clonez le dépôt :
   git clone <url-du-repo>
   cd Supermarcher

2. Compilez le projet en utilisant make :
   make

3. L'exécutable généré sera disponible sous le nom supermarche.

### Nettoyage

Pour supprimer les fichiers compilés :
make clean

Exécution

Lancez l'exécutable :
make run

Fichiers Importants

1. main.cpp : Le point d’entrée du programme. Il intègre les différentes fonctionnalités en appelant les classes et fonctions des modules.

2. database/Database.cpp : Gère les interactions avec la base de données SQLite :
   - Connexion à la base.
   - Exécution des requêtes SQL.
   - Gestion des transactions.

3. gestion/ : Contient les modules de gestion :
   - GestionCommandes.cpp : Gestion des commandes.
   - GestionInventaire.cpp : Gestion des stocks.
   - GestionProduits.cpp : Gestion des produits.
   - GestionClients.cpp : Gestion des clients.
   - GestionFournisseurs.cpp : Gestion des fournisseurs.

4. models/ : Contient les modèles pour représenter les entités du système :
   - Client.cpp : Informations sur les clients.
   - Commande.cpp : Représentation des commandes.
   - Fournisseur.cpp : Informations sur les fournisseurs.
   - Produit.cpp : Représentation des produits.

5. utils/Utils.cpp : Fonctions utilitaires utilisées dans tout le projet, comme la manipulation de chaînes de caractères ou le formatage.

Contributeurs
ONDO JEAN KAREL 22U2381 : Développeur principal et gestionnaire du projet.
Licence

Ce projet est sous licence libre. Vous pouvez l'utiliser, le modifier et le distribuer librement en citant l'auteur original.
