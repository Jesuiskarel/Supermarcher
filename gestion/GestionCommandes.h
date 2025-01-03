#ifndef GESTION_COMMANDES_H
#define GESTION_COMMANDES_H

#include <string>
#include <vector>
#include "database/Database.h"

class GestionCommandes {
private:
    Database& db; // Référence à l'instance de la base de données

public:
    // Constructeur
    GestionCommandes(Database& database);

    // Méthodes principales
    void creerCommande(int clientId, const std::vector<std::pair<int, int>>& produits); // Produits : {id_produit, quantité}
    void traiterCommande(int commandeId);
    void annulerCommande(int commandeId);
    std::vector<std::vector<std::string>> listerCommandes(); // Liste toutes les commandes
};

#endif // GESTION_COMMANDES_H

