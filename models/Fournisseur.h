#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>

class Fournisseur {
private:
    int id;                  // ID unique du fournisseur
    std::string nom;         // Nom du fournisseur
    std::string adresse;     // Adresse du fournisseur
    std::string telephone;   // Numéro de téléphone du fournisseur

public:
    // Constructeurs
    Fournisseur();
    Fournisseur(int id, const std::string& nom, const std::string& adresse, const std::string& telephone);

    // Getters et Setters
    int getId() const;
    void setId(int id);

    std::string getNom() const;
    void setNom(const std::string& nom);

    std::string getAdresse() const;
    void setAdresse(const std::string& adresse);

    std::string getTelephone() const;
    void setTelephone(const std::string& telephone);

    // Méthodes supplémentaires
    void afficherDetails() const; // Afficher les détails du fournisseur
};

#endif // FOURNISSEUR_H

