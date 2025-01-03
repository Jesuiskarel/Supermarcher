#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    int id;                  // ID unique du client
    std::string nom;         // Nom du client
    std::string email;       // Adresse email du client
    std::string telephone;   // Numéro de téléphone du client

public:
    // Constructeurs
    Client();
    Client(int id, const std::string& nom, const std::string& email, const std::string& telephone);

    // Getters et Setters
    int getId() const;
    void setId(int id);

    std::string getNom() const;
    void setNom(const std::string& nom);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    std::string getTelephone() const;
    void setTelephone(const std::string& telephone);

    // Méthodes supplémentaires
    void afficherDetails() const; // Affiche les détails du client
};

#endif // CLIENT_H

