#ifndef GESTION_FOURNISSEURS_H
#define GESTION_FOURNISSEURS_H

#include <string>
#include <vector>
#include "database/Database.h"

class GestionFournisseurs {
private:
    Database& db; // Référence à l'instance de la base de données

public:
    // Constructeur
    GestionFournisseurs(Database& database);

    // Méthodes principales
    void creerFournisseur(const std::string& nom, const std::string& adresse, const std::string& telephone);
    void modifierFournisseur(int fournisseurId, const std::string& nom, const std::string& adresse, const std::string& telephone);
    void supprimerFournisseur(int fournisseurId);
    std::vector<std::string> rechercherFournisseur(int fournisseurId);
    std::vector<std::vector<std::string>> afficherTousLesFournisseurs();
};

#endif // GESTION_FOURNISSEURS_H

