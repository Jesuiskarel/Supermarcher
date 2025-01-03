#include "GestionCommandes.h"
#include <iostream>

// Constructeur
GestionCommandes::GestionCommandes(Database& database) : db(database) {}

// Création d’une commande
void GestionCommandes::creerCommande(int clientId, const std::vector<std::pair<int, int>>& produits) {
    try {
        // Insérer la commande dans la table Commande
        std::string query = "INSERT INTO Commande (client_id) VALUES (" + std::to_string(clientId) + ");";
        db.execute(query);

        // Récupérer l'ID de la commande créée
        int commandeId = db.getLastInsertId();

        // Ajouter les produits à la commande
        for (const auto& produit : produits) {
            int produitId = produit.first;
            int quantite = produit.second;

            // Insérer dans Commande_Produit
            query = "INSERT INTO Commande_Produit (commande_id, produit_id, quantite) VALUES (" +
                    std::to_string(commandeId) + ", " + std::to_string(produitId) + ", " + std::to_string(quantite) + ");";
            db.execute(query);

            // Réduire le stock du produit
            query = "UPDATE Produit SET quantite = quantite - " + std::to_string(quantite) +
                    " WHERE id = " + std::to_string(produitId) + ";";
            db.execute(query);
        }

        std::cout << "Commande créée avec succès. ID : " << commandeId << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la création de la commande : " << e.what() << "\n";
    }
}

// Traitement d’une commande
void GestionCommandes::traiterCommande(int commandeId) {
    try {
        // Mettre à jour le statut de la commande
        std::string query = "UPDATE Commande SET statut = 'Traitée' WHERE id = " + std::to_string(commandeId) + ";";
        db.execute(query);

        std::cout << "Commande traitée avec succès. ID : " << commandeId << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du traitement de la commande : " << e.what() << "\n";
    }
}

// Annulation d’une commande
void GestionCommandes::annulerCommande(int commandeId) {
    try {
        // Restaurer les quantités des produits dans l’inventaire
        std::string query = "SELECT produit_id, quantite FROM Commande_Produit WHERE commande_id = " + std::to_string(commandeId) + ";";
        auto result = db.executeSelect(query);

        for (const auto& row : result) {
            int produitId = std::stoi(row[0]);
            int quantite = std::stoi(row[1]);

            // Restaurer le stock
            query = "UPDATE Produit SET quantite = quantite + " + std::to_string(quantite) +
                    " WHERE id = " + std::to_string(produitId) + ";";
            db.execute(query);
        }

        // Mettre à jour le statut de la commande
        query = "UPDATE Commande SET statut = 'Annulée' WHERE id = " + std::to_string(commandeId) + ";";
        db.execute(query);

        std::cout << "Commande annulée avec succès. ID : " << commandeId << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de l’annulation de la commande : " << e.what() << "\n";
    }
}

// Lister toutes les commandes
std::vector<std::vector<std::string>> GestionCommandes::listerCommandes() {
    try {
        return db.executeSelect("SELECT * FROM Commande;");
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la récupération des commandes : " << e.what() << "\n";
        return {};
    }
}

