#ifndef GESTION_CLIENTS_H
#define GESTION_CLIENTS_H

#include <string>
#include <vector>
#include "database/Database.h"

class GestionClients {
private:
    Database& db; // Référence à l'instance de la base de données

public:
    // Constructeur
    GestionClients(Database& database);

    // Méthodes principales
    void creerClient(const std::string& nom, const std::string& adresse, const std::string& telephone);
    void modifierClient(int id, const std::string& nom, const std::string& adresse, const std::string& telephone);
    void supprimerClient(int id);
    std::vector<std::string> rechercherClient(int id);
    std::vector<std::vector<std::string>> afficherTousLesClients();
};

#endif // GESTION_CLIENTS_H

