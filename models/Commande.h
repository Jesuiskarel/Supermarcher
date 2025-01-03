#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include <vector>
#include <utility> // pour std::pair

class Commande {
private:
    int id;                              // ID unique de la commande
    int idClient;                        // ID du client associé à la commande
    std::string dateCommande;            // Date de la commande
    std::string statut;                  // Statut de la commande (e.g., "En cours", "Traitée", "Annulée")
    std::vector<std::pair<int, int>> produits; // Liste des produits (id, quantité) dans la commande

public:
    // Constructeurs
    Commande();
    Commande(int id, int idClient, const std::string& dateCommande, const std::string& statut);

    // Getters et Setters
    int getId() const;
    void setId(int id);

    int getIdClient() const;
    void setIdClient(int idClient);

    std::string getDateCommande() const;
    void setDateCommande(const std::string& dateCommande);

    std::string getStatut() const;
    void setStatut(const std::string& statut);

    std::vector<std::pair<int, int>> getProduits() const;
    void ajouterProduit(int idProduit, int quantite);
    void supprimerProduit(int idProduit);

    // Méthodes supplémentaires
    void afficherDetails() const; // Affiche les détails de la commande
    void traiter();               // Marque la commande comme "Traitée"
    void annuler();               // Annule la commande
};

#endif // COMMANDE_H

