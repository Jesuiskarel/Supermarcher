#include "Utils.h"
#include <iostream>


double Utils::getDoubleInput(const std::string& message) {
    double valeur;
    std::cout << message;
    std::cin >> valeur;
    return valeur;
}

int Utils::getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrée invalide. Veuillez entrer un entier.\n";
        } else {
            break;
        }
    }
    return value;
}

std::string Utils::getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::cin.ignore(); // Ignorer les caractères résiduels
    std::getline(std::cin, value);
    return value;
}

void Utils::attendreEntree() {
    std::cout << "Appuyez sur Entrée pour continuer...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

/*namespace Utils {

// Vérifie si une chaîne est un email valide
bool estEmailValide(const std::string& email) {
    const std::regex emailRegex(R"((\w+)(\.?\w+)*@(\w+)(\.\w{2,3})+)");
    return std::regex_match(email, emailRegex);
}

// Vérifie si un numéro de téléphone est valide (10 chiffres)
bool estTelephoneValide(const std::string& telephone) {
    const std::regex phoneRegex(R"(\d{10})");
    return std::regex_match(telephone, phoneRegex);
}

// Valide si une chaîne est un nombre positif
bool estNombrePositif(const std::string& str) {
    try {
        double valeur = std::stod(str);
        return valeur > 0;
    } catch (...) {
        return false;
    }
}

// Convertit une chaîne en minuscule
std::string convertirEnMinuscule(const std::string& str) {
    std::string resultat = str;
    for (char& c : resultat) {
        c = std::tolower(c);
    }
    return resultat;
}

// Affiche un message d'erreur standard
void afficherErreur(const std::string& message) {
    std::cerr << "[ERREUR] " << message << std::endl;
}

// Affiche un message de succès
void afficherSucces(const std::string& message) {
    std::cout << "[SUCCÈS] " << message << std::endl;
}

} // namespace Utils*/

