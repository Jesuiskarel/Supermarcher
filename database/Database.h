#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>
#include <vector>
#include <stdexcept>

class Database {
private:
    sqlite3* db; // Instance SQLite
    bool isConnected;

public:
    // Constructeur et destructeur
    Database(const std::string& dbName);
    ~Database();

    // Méthodes principales
    void executeQuery(const std::string& query); // Exécute une requête SQL (INSERT, UPDATE, DELETE)
    std::vector<std::vector<std::string>> executeSelect(const std::string& query); // Exécute une requête SELECT et renvoie les résultats
    void execute(const std::string& query); // Exécute une requête générique (alias pour executeQuery)
    int getLastInsertId(); // Récupère l'ID de la dernière insertion

    // Gestion des produits
    void ajouterProduit(const std::string& nom, double prix, int quantite, const std::string& categorie, int fournisseur_id);
    void mettreAJourProduit(int id, double prix, int quantite);
    void supprimerProduit(int id);
    std::vector<std::vector<std::string>> listerProduits();

    // Gestion des commandes
    void creerCommande(int client_id);
    void ajouterProduitACommande(int commande_id, int produit_id, int quantite);
    void annulerCommande(int commande_id);

    // Gestion des clients et fournisseurs
    void ajouterFournisseur(const std::string& nom, const std::string& adresse, const std::string& telephone);
    void ajouterClient(const std::string& nom, const std::string& email, const std::string& telephone);

    // Réapprovisionnement et vérification d'inventaire
    void reapprovisionnerProduit(int id, int quantite);
    bool verifierInventaire(int id);
};

#endif

