#include "GestionFournisseurs.h"
#include <iostream>

// Constructeur
GestionFournisseurs::GestionFournisseurs(Database& database) : db(database) {}

// Création d’un fournisseur
void GestionFournisseurs::creerFournisseur(const std::string& nom, const std::string& adresse, const std::string& telephone) {
    try {
        std::string query = "INSERT INTO Fournisseur (nom, adresse, telephone) VALUES ('" +
                            nom + "', '" + adresse + "', '" + telephone + "');";
        db.execute(query);
        std::cout << "Fournisseur ajouté avec succès !\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la création du fournisseur : " << e.what() << "\n";
    }
}

// Modification d’un fournisseur
void GestionFournisseurs::modifierFournisseur(int fournisseurId, const std::string& nom, const std::string& adresse, const std::string& telephone) {
    try {
        std::string query = "UPDATE Fournisseur SET nom = '" + nom +
                            "', adresse = '" + adresse +
                            "', telephone = '" + telephone +
                            "' WHERE id = " + std::to_string(fournisseurId) + ";";
        db.execute(query);
        std::cout << "Fournisseur mis à jour avec succès !\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la modification du fournisseur : " << e.what() << "\n";
    }
}

// Suppression d’un fournisseur
void GestionFournisseurs::supprimerFournisseur(int fournisseurId) {
    try {
        std::string query = "DELETE FROM Fournisseur WHERE id = " + std::to_string(fournisseurId) + ";";
        db.execute(query);
        std::cout << "Fournisseur supprimé avec succès !\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la suppression du fournisseur : " << e.what() << "\n";
    }
}

// Recherche d’un fournisseur
std::vector<std::string> GestionFournisseurs::rechercherFournisseur(int fournisseurId) {
    try {
        std::string query = "SELECT * FROM Fournisseur WHERE id = " + std::to_string(fournisseurId) + ";";
        auto result = db.executeSelect(query);

        if (!result.empty()) {
            return result[0]; // Retourne la première ligne correspondant au fournisseur
        } else {
            std::cerr << "Erreur : Fournisseur avec ID " << fournisseurId << " introuvable.\n";
            return {};
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la recherche du fournisseur : " << e.what() << "\n";
        return {};
    }
}


// Afficher tous les fournisseurs
std::vector<std::vector<std::string>> GestionFournisseurs::afficherTousLesFournisseurs() {
    try {
        std::string query = "SELECT * FROM Fournisseur;";
        return db.executeSelect(query);
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la récupération des fournisseurs : " << e.what() << "\n";
        return {};
    }
}

