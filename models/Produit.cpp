#include "Produit.h"
#include <iostream>

// Constructeurs
Produit::Produit() : id(0), prix(0.0), quantite(0), fournisseurId(0) {}

Produit::Produit(int id, const std::string& nom, double prix, int quantite, const std::string& categorie, int fournisseurId)
    : id(id), nom(nom), prix(prix), quantite(quantite), categorie(categorie), fournisseurId(fournisseurId) {}

// Getters et Setters
int Produit::getId() const {
    return id;
}

void Produit::setId(int id) {
    this->id = id;
}

std::string Produit::getNom() const {
    return nom;
}

void Produit::setNom(const std::string& nom) {
    this->nom = nom;
}

double Produit::getPrix() const {
    return prix;
}

void Produit::setPrix(double prix) {
    this->prix = prix;
}

int Produit::getQuantite() const {
    return quantite;
}

void Produit::setQuantite(int quantite) {
    this->quantite = quantite;
}

std::string Produit::getCategorie() const {
    return categorie;
}

void Produit::setCategorie(const std::string& categorie) {
    this->categorie = categorie;
}

int Produit::getFournisseurId() const {
    return fournisseurId;
}

void Produit::setFournisseurId(int fournisseurId) {
    this->fournisseurId = fournisseurId;
}


// Méthodes supplémentaires
void Produit::afficherDetails() const {
    std::cout << "Produit ID: " << id << "\n"
              << "Nom: " << nom << "\n"
              << "Prix: " << prix << " FCFA\n"
              << "Quantité: " << quantite << "\n"
              << "Catégorie: " << categorie << "\n"
              << "ID Fournisseur: " << fournisseurId << "\n";
}

