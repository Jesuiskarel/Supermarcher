#include "Fournisseur.h"
#include <iostream>

// Constructeurs
Fournisseur::Fournisseur() : id(0) {}

Fournisseur::Fournisseur(int id, const std::string& nom, const std::string& adresse, const std::string& telephone)
    : id(id), nom(nom), adresse(adresse), telephone(telephone) {}

// Getters et Setters
int Fournisseur::getId() const {
    return id;
}

void Fournisseur::setId(int id) {
    this->id = id;
}

std::string Fournisseur::getNom() const {
    return nom;
}

void Fournisseur::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Fournisseur::getAdresse() const {
    return adresse;
}

void Fournisseur::setAdresse(const std::string& adresse) {
    this->adresse = adresse;
}

std::string Fournisseur::getTelephone() const {
    return telephone;
}

void Fournisseur::setTelephone(const std::string& telephone) {
    this->telephone = telephone;
}

// Méthodes supplémentaires
void Fournisseur::afficherDetails() const {
    std::cout << "Fournisseur ID: " << id << "\n"
              << "Nom: " << nom << "\n"
              << "Adresse: " << adresse << "\n"
              << "Téléphone: " << telephone << "\n";
}

