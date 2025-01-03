#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <regex>
#include <iostream>
#include <string>
#include <limits>

class Utils {
public:
    static int getIntInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);
    static void attendreEntree();
    static double getDoubleInput(const std::string& message);
};

/*namespace Utils {
    // Vérifie si une chaîne est un email valide
    bool estEmailValide(const std::string& email);

    // Vérifie si un numéro de téléphone est valide (10 chiffres)
    bool estTelephoneValide(const std::string& telephone);

    // Valide si une chaîne est un nombre positif
    bool estNombrePositif(const std::string& str);

    // Convertit une chaîne en minuscule
    std::string convertirEnMinuscule(const std::string& str);

    // Affiche un message d'erreur standard
    void afficherErreur(const std::string& message);

    // Affiche un message de succès
    void afficherSucces(const std::string& message);
}*/

#endif // UTILS_H

