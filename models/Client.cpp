#include "Client.h"
#include <iostream>

// Constructeurs
Client::Client() : id(0) {}

Client::Client(int id, const std::string& nom, const std::string& email, const std::string& telephone)
    : id(id), nom(nom), email(email), telephone(telephone) {}

// Getters et Setters
int Client::getId() const {
    return id;
}

void Client::setId(int id) {
    this->id = id;
}

std::string Client::getNom() const {
    return nom;
}

void Client::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Client::getEmail() const {
    return email;
}

void Client::setEmail(const std::string& email) {
    this->email = email;
}

std::string Client::getTelephone() const {
    return telephone;
}

void Client::setTelephone(const std::string& telephone) {
    this->telephone = telephone;
}

// Méthodes supplémentaires
void Client::afficherDetails() const {
    std::cout << "Client ID: " << id << "\n"
              << "Nom: " << nom << "\n"
              << "Email: " << email << "\n"
              << "Téléphone: " << telephone << "\n";
}

