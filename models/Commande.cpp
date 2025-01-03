#include "Commande.h"
#include <iostream>
#include <algorithm>


// Constructeurs
Commande::Commande() : id(0), idClient(0), statut("En cours") {}

Commande::Commande(int id, int idClient, const std::string& dateCommande, const std::string& statut)
    : id(id), idClient(idClient), dateCommande(dateCommande), statut(statut) {}

// Getters et Setters
int Commande::getId() const {
    return id;
}

void Commande::setId(int id) {
    this->id = id;
}

int Commande::getIdClient() const {
    return idClient;
}

void Commande::setIdClient(int idClient) {
    this->idClient = idClient;
}

std::string Commande::getDateCommande() const {
    return dateCommande;
}

void Commande::setDateCommande(const std::string& dateCommande) {
    this->dateCommande = dateCommande;
}

std::string Commande::getStatut() const {
    return statut;
}

void Commande::setStatut(const std::string& statut) {
    this->statut = statut;
}

std::vector<std::pair<int, int>> Commande::getProduits() const {
    return produits;
}

void Commande::ajouterProduit(int idProduit, int quantite) {
    produits.emplace_back(idProduit, quantite);
}

void Commande::supprimerProduit(int idProduit) {
    produits.erase(
        std::remove_if(produits.begin(), produits.end(),
                       [idProduit](const std::pair<int, int>& produit) {
                           return produit.first == idProduit;
                       }),
        produits.end());
}

// Méthodes supplémentaires
void Commande::afficherDetails() const {
    std::cout << "Commande ID: " << id << "\n"
              << "Client ID: " << idClient << "\n"
              << "Date: " << dateCommande << "\n"
              << "Statut: " << statut << "\n"
              << "Produits:\n";
    for (const auto& produit : produits) {
        std::cout << "  - Produit ID: " << produit.first
                  << ", Quantité: " << produit.second << "\n";
    }
}

void Commande::traiter() {
    setStatut("Traitée");
}

void Commande::annuler() {
    setStatut("Annulée");
}

