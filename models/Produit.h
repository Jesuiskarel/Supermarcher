#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

class Produit {
private:
    int id;                   // ID unique du produit
    std::string nom;          // Nom du produit
    double prix;              // Prix unitaire du produit
    int quantite;             // Quantité en stock
    std::string categorie;    // Catégorie du produit
    int fournisseurId;        // ID du fournisseur associé

public:
    // Constructeurs
    Produit();
    Produit(int id, const std::string& nom, double prix, int quantite, const std::string& categorie, int fournisseurId);

    // Getters et Setters
    int getId() const;
    void setId(int id);

    std::string getNom() const;
    void setNom(const std::string& nom);

    double getPrix() const;
    void setPrix(double prix);

    int getQuantite() const;
    void setQuantite(int quantite);

    std::string getCategorie() const;
    void setCategorie(const std::string& categorie);

    int getFournisseurId() const;
    void setFournisseurId(int fournisseurId);
    
    // Méthodes supplémentaires
    void afficherDetails() const; // Afficher les détails du produit
};


#endif // PRODUIT_H

