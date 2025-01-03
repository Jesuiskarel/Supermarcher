#include "Database.h"
#include <iostream>

// Constructeur : Connexion à la base de données
Database::Database(const std::string& dbName) : db(nullptr), isConnected(false) {
    int result = sqlite3_open(dbName.c_str(), &db);
    if (result != SQLITE_OK) {
        throw std::runtime_error("Erreur lors de la connexion à la base de données : " + std::string(sqlite3_errmsg(db)));
    }
    isConnected = true;
}

// Destructeur : Fermeture de la base de données
Database::~Database() {
    if (isConnected) {
        sqlite3_close(db);
    }
}

// Exécute une requête SQL (INSERT, UPDATE, DELETE)
void Database::executeQuery(const std::string& query) {
    char* errorMessage = nullptr;
    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errorMessage);
    if (result != SQLITE_OK) {
        std::string error = errorMessage;
        sqlite3_free(errorMessage);
        throw std::runtime_error("Erreur lors de l'exécution de la requête : " + error);
    }
}

// Alias pour executeQuery
void Database::execute(const std::string& query) {
    executeQuery(query);
}

// Récupère l'ID de la dernière insertion
int Database::getLastInsertId() {
    return static_cast<int>(sqlite3_last_insert_rowid(db));
}

// Exécute une requête SELECT et renvoie les résultats
std::vector<std::vector<std::string>> Database::executeSelect(const std::string& query) {
    sqlite3_stmt* stmt;
    std::vector<std::vector<std::string>> results;

    int result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (result != SQLITE_OK) {
        throw std::runtime_error("Erreur lors de la préparation de la requête : " + std::string(sqlite3_errmsg(db)));
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        int columnCount = sqlite3_column_count(stmt);
        for (int i = 0; i < columnCount; ++i) {
            const char* text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            row.push_back(text ? text : "NULL");
        }
        results.push_back(row);
    }

    sqlite3_finalize(stmt);
    return results;
}

// Gestion des produits
void Database::ajouterProduit(const std::string& nom, double prix, int quantite, const std::string& categorie, int fournisseur_id) {
    std::string query = "INSERT INTO Produit (nom, prix, quantite, categorie, fournisseur_id) VALUES ('" + nom + "', " + std::to_string(prix) + ", " + std::to_string(quantite) + ", '" + categorie + "', " + std::to_string(fournisseur_id) + ");";
    executeQuery(query);
}

void Database::mettreAJourProduit(int id, double prix, int quantite) {
    std::string query = "UPDATE Produit SET prix = " + std::to_string(prix) + ", quantite = quantite + " + std::to_string(quantite) + " WHERE id = " + std::to_string(id) + ";";
    executeQuery(query);
}

void Database::supprimerProduit(int id) {
    std::string query = "DELETE FROM Produit WHERE id = " + std::to_string(id) + ";";
    executeQuery(query);
}

std::vector<std::vector<std::string>> Database::listerProduits() {
    return executeSelect("SELECT * FROM Produit;");
}

// Gestion des commandes
void Database::creerCommande(int client_id) {
    std::string query = "INSERT INTO Commande (client_id) VALUES (" + std::to_string(client_id) + ");";
    executeQuery(query);
}

void Database::ajouterProduitACommande(int commande_id, int produit_id, int quantite) {
    std::string query = "INSERT INTO Commande_Produit (commande_id, produit_id, quantite) VALUES (" + std::to_string(commande_id) + ", " + std::to_string(produit_id) + ", " + std::to_string(quantite) + ");";
    executeQuery(query);

    // Mise à jour du stock
    query = "UPDATE Produit SET quantite = quantite - " + std::to_string(quantite) + " WHERE id = " + std::to_string(produit_id) + ";";
    executeQuery(query);
}

void Database::annulerCommande(int commande_id) {
    auto produits = executeSelect("SELECT produit_id, quantite FROM Commande_Produit WHERE commande_id = " + std::to_string(commande_id) + ";");
    for (const auto& row : produits) {
        int produit_id = std::stoi(row[0]);
        int quantite = std::stoi(row[1]);
        std::string query = "UPDATE Produit SET quantite = quantite + " + std::to_string(quantite) + " WHERE id = " + std::to_string(produit_id) + ";";
        executeQuery(query);
    }

    executeQuery("DELETE FROM Commande_Produit WHERE commande_id = " + std::to_string(commande_id) + ";");
    executeQuery("DELETE FROM Commande WHERE id = " + std::to_string(commande_id) + ";");
}

// Réapprovisionnement
void Database::reapprovisionnerProduit(int id, int quantite) {
    std::string query = "UPDATE Produit SET quantite = quantite + " + std::to_string(quantite) + " WHERE id = " + std::to_string(id) + ";";
    executeQuery(query);
}

// Vérification d'inventaire
bool Database::verifierInventaire(int id) {
    std::string query = "SELECT quantite FROM Produit WHERE id = " + std::to_string(id) + ";";
    auto result = executeSelect(query);
    if (!result.empty() && std::stoi(result[0][0]) > 0) {
        return true; // Produit en stock
    }
    return false; // Produit en rupture de stock
}

