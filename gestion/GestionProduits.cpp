#include "GestionProduits.h"
#include <iostream>

// Constructeur
GestionProduits::GestionProduits(Database& database) : db(database) {}

// Ajouter un nouveau produit
void GestionProduits::ajouterProduit(const std::string& nom, double prix, int quantite, const std::string& categorie, int fournisseur_id) {
    try {
        db.ajouterProduit(nom, prix, quantite, categorie, fournisseur_id);
        std::cout << "Produit ajouté avec succès : " << nom << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de l'ajout du produit : " << e.what() << "\n";
    }
}

// Mettre à jour les détails d'un produit
void GestionProduits::mettreAJourProduit(int id, double nouveauPrix, int quantiteAjoutee) {
    try {
        db.mettreAJourProduit(id, nouveauPrix, quantiteAjoutee);
        std::cout << "Produit mis à jour avec succès. ID : " << id << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la mise à jour du produit : " << e.what() << "\n";
    }
}

// Supprimer un produit
void GestionProduits::supprimerProduit(int id) {
    try {
        db.supprimerProduit(id);
        std::cout << "Produit supprimé avec succès. ID : " << id << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la suppression du produit : " << e.what() << "\n";
    }
}

// Lister tous les produits
std::vector<std::vector<std::string>> GestionProduits::listerProduits() {
    try {
        return db.listerProduits();
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la récupération des produits : " << e.what() << "\n";
        return {};
    }
}

// Rechercher des produits par nom
std::vector<std::vector<std::string>> GestionProduits::rechercherProduitsParNom(const std::string& nom) {
    try {
        std::string query = "SELECT * FROM Produit WHERE nom LIKE '%" + nom + "%';";
        return db.executeSelect(query);
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la recherche des produits par nom : " << e.what() << "\n";
        return {};
    }
}

// Rechercher des produits par catégorie
std::vector<std::vector<std::string>> GestionProduits::rechercherProduitsParCategorie(const std::string& categorie) {
    try {
        std::string query = "SELECT * FROM Produit WHERE categorie = '" + categorie + "';";
        return db.executeSelect(query);
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la recherche des produits par catégorie : " << e.what() << "\n";
        return {};
    }
}

// Rechercher des produits par fournisseur
std::vector<std::vector<std::string>> GestionProduits::rechercherProduitsParFournisseur(int fournisseur_id) {
    try {
        std::string query = "SELECT * FROM Produit WHERE fournisseur_id = " + std::to_string(fournisseur_id) + ";";
        return db.executeSelect(query);
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la recherche des produits par fournisseur : " << e.what() << "\n";
        return {};
    }
}


