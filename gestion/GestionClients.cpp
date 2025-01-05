#include "GestionClients.h"
#include <iostream>

// Constructeur
GestionClients::GestionClients(Database& database) : db(database) {}

// Créer un client
void GestionClients::creerClient(const std::string& nom, const std::string& email, const std::string& telephone) {
    try {
        std::string query = "INSERT INTO Client (nom, email, telephone) VALUES ('" +
                            nom + "', '" + email + "', '" + telephone + "');";
        db.execute(query);
        std::cout << "Client créé avec succès : " << nom << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la création du client : " << e.what() << "\n";
    }
}

// Modifier un client
void GestionClients::modifierClient(int id, const std::string& nom, const std::string& email, const std::string& telephone) {
    try {
        std::string query = "UPDATE Client SET nom = '" + nom +
                            "', email = '" + email +
                            "', telephone = '" + telephone +
                            "' WHERE id = " + std::to_string(id) + ";";
        db.execute(query);
        std::cout << "Client modifié avec succès : ID " << id << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la modification du client : " << e.what() << "\n";
    }
}

// Supprimer un client
void GestionClients::supprimerClient(int id) {
    try {
        std::string query = "DELETE FROM Client WHERE id = " + std::to_string(id) + ";";
        db.execute(query);
        std::cout << "Client supprimé avec succès : ID " << id << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la suppression du client : " << e.what() << "\n";
    }
}

// Rechercher un client
std::vector<std::string> GestionClients::rechercherClient(int id) {
    try {
        std::string query = "SELECT * FROM Client WHERE id = " + std::to_string(id) + ";";
        auto result = db.executeSelect(query);

        if (!result.empty()) {
            return result[0]; // Retourne la première ligne correspondant au client
        } else {
            std::cerr << "Erreur : Client avec ID " << id << " introuvable.\n";
            return {};
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la recherche du client : " << e.what() << "\n";
        return {};
    }
}

// Afficher tous les clients
std::vector<std::vector<std::string>> GestionClients::afficherTousLesClients() {
    try {
        return db.executeSelect("SELECT * FROM Client;");
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de l'affichage des clients : " << e.what() << "\n";
        return {};
    }
}

