#include "GestionInventaire.h"
#include <iostream>

// Constructeur
GestionInventaire::GestionInventaire(Database& database) : db(database) {}

// Réapprovisionnement d’un produit
void GestionInventaire::reapprovisionnerProduit(int produitId, int quantite) {
    try {
        // Vérifier si le produit existe
        std::string query = "SELECT COUNT(*) FROM Produit WHERE id = " + std::to_string(produitId) + ";";
        auto result = db.executeSelect(query);
        if (result.empty() || std::stoi(result[0][0]) == 0) {
            throw std::runtime_error("Le produit avec l'ID " + std::to_string(produitId) + " n'existe pas.");
        }

        // Réapprovisionner le stock
        query = "UPDATE Produit SET quantite = quantite + " + std::to_string(quantite) +
                " WHERE id = " + std::to_string(produitId) + ";";
        db.execute(query);

        std::cout << "Produit réapprovisionné avec succès. ID : " << produitId << ", Quantité ajoutée : " << quantite << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du réapprovisionnement : " << e.what() << "\n";
    }
}

// Vérification d’un produit spécifique
std::string GestionInventaire::verifierStock(int produitId) {
    try {
        // Récupérer la quantité en stock
        std::string query = "SELECT nom, quantite FROM Produit WHERE id = " + std::to_string(produitId) + ";";
        auto result = db.executeSelect(query);

        if (result.empty()) {
            throw std::runtime_error("Le produit avec l'ID " + std::to_string(produitId) + " n'existe pas.");
        }

        std::string nomProduit = result[0][0];
        int quantite = std::stoi(result[0][1]);

        if (quantite == 0) {
            return "Le produit \"" + nomProduit + "\" est en rupture de stock.";
        } else if (quantite < 5) {
            return "Le produit \"" + nomProduit + "\" est presque en rupture de stock. Quantité restante : " + std::to_string(quantite);
        } else {
            return "Le produit \"" + nomProduit + "\" est en stock. Quantité disponible : " + std::to_string(quantite);
        }
    } catch (const std::exception& e) {
        return "Erreur lors de la vérification du stock : " + std::string(e.what());
    }
}

// Vérification des stocks pour tous les produits
std::vector<std::pair<int, std::string>> GestionInventaire::verifierTousLesStocks() {
    std::vector<std::pair<int, std::string>> resultats;
    try {
        std::string query = "SELECT id, nom, quantite FROM Produit;";
        auto result = db.executeSelect(query);

        for (const auto& row : result) {
            int produitId = std::stoi(row[0]);
            std::string nomProduit = row[1];
            int quantite = std::stoi(row[2]);

            std::string statut;
            if (quantite == 0) {
                statut = "en rupture de stock.";
            } else if (quantite < 5) {
                statut = "presque en rupture de stock. Quantité restante : " + std::to_string(quantite);
            } else {
                statut = "en stock. Quantité disponible : " + std::to_string(quantite);
            }

            resultats.emplace_back(produitId, "Produit \"" + nomProduit + "\" est " + statut);
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la vérification des stocks : " << e.what() << "\n";
    }
    return resultats;
}

