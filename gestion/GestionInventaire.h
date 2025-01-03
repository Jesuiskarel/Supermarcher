#ifndef GESTION_INVENTAIRE_H
#define GESTION_INVENTAIRE_H

#include <string>
#include <vector>
#include "database/Database.h"

class GestionInventaire {
private:
    Database& db; // Référence à l'instance de la base de données

public:
    // Constructeur
    GestionInventaire(Database& database);

    // Méthodes principales
    void reapprovisionnerProduit(int produitId, int quantite);
    std::string verifierStock(int produitId); // Vérifie si un produit est en rupture de stock ou presque
    std::vector<std::pair<int, std::string>> verifierTousLesStocks(); // Vérifie les stocks pour tous les produits
};

#endif // GESTION_INVENTAIRE_H

