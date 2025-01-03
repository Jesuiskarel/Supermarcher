#ifndef GESTION_PRODUITS_H
#define GESTION_PRODUITS_H

#include <string>
#include <vector>
#include "database/Database.h"

class GestionProduits {
private:
    Database& db; // Référence à l'instance de la base de données

public:
    // Constructeur
    GestionProduits(Database& database);

    // Méthodes principales
    void ajouterProduit(const std::string& nom, double prix, int quantite, const std::string& categorie, int fournisseur_id);
    void mettreAJourProduit(int id, double nouveauPrix, int quantiteAjoutee);
    void supprimerProduit(int id);
    std::vector<std::vector<std::string>> listerProduits();
    std::vector<std::vector<std::string>> rechercherProduitsParNom(const std::string& nom);
    std::vector<std::vector<std::string>> rechercherProduitsParCategorie(const std::string& categorie);
    std::vector<std::vector<std::string>> rechercherProduitsParFournisseur(int fournisseur_id);
};

#endif // GESTION_PRODUITS_H

