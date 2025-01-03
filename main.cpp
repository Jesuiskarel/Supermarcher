#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <unistd.h> // Pour clearScreen sur Linux/Mac
#include "database/Database.h"
#include "gestion/GestionProduits.h"
#include "gestion/GestionCommandes.h"
#include "gestion/GestionInventaire.h"
#include "models/Produit.h"
#include "models/Commande.h"
#include "utils/Utils.h"

#ifdef _WIN32
#include <windows.h>
void clearScreen() {
    system("cls");
}
#else
void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // Commande ANSI pour nettoyer l'écran
}
#endif

// Affiche un titre pour une section
void afficherTitre(const std::string& titre) {
    clearScreen();
    std::cout << "\n=== " << titre << " ===\n\n";
}

// Menu Recherche de produits
void menuRechercheProduits(GestionProduits& gestionProduits) {
    while (true) {
        afficherTitre("Recherche de Produits");
        std::cout << "1. Rechercher par nom\n";
        std::cout << "2. Rechercher par catégorie\n";
        std::cout << "3. Rechercher par fournisseur\n";
        std::cout << "4. Retour au menu principal\n";
        std::cout << "\nChoisissez une option : ";
        int choix = Utils::getIntInput("");

        switch (choix) {
            case 1: {
                std::string nom = Utils::getStringInput("Entrez le nom ou une partie du nom du produit : ");
                auto produits = gestionProduits.rechercherProduitsParNom(nom);
                for (const auto& produit : produits) {
                    for (const auto& champ : produit) {
                        std::cout << champ << " ";
                    }
                    std::cout << "\n";
                }
                
                break;
            }
            case 2: {
                std::string categorie = Utils::getStringInput("Entrez la catégorie : ");
                auto produits = gestionProduits.rechercherProduitsParCategorie(categorie);
                for (const auto& produit : produits) {
                    for (const auto& champ : produit) {
                        std::cout << champ << " ";
                    }
                    std::cout << "\n";
                }
                
                break;
            }
            case 3: {
                int fournisseurId = Utils::getIntInput("Entrez l'ID du fournisseur : ");
                auto produits = gestionProduits.rechercherProduitsParFournisseur(fournisseurId);
                for (const auto& produit : produits) {
                    for (const auto& champ : produit) {
                        std::cout << champ << " ";
                    }
                    std::cout << "\n";
                }
                
                break;
            }
            case 4:
                return;
            default:
                std::cout << "Option invalide.\n";
        }
        Utils::attendreEntree();
    }
}

// Menu Gestion des produits
void menuGestionProduits(GestionProduits& gestionProduits) {
    while (true) {
        afficherTitre("Gestion des Produits");
        std::cout << "1. Ajouter un produit\n";
        std::cout << "2. Mettre à jour un produit\n";
        std::cout << "3. Supprimer un produit\n";
        std::cout << "4. Afficher tous les produits\n";
        std::cout << "5. Retour au menu principal\n";
        std::cout << "\nChoisissez une option : ";
        int choix = Utils::getIntInput("");

        switch (choix) {
            case 1: {
                std::string nom = Utils::getStringInput("Nom du produit : ");
                double prix = Utils::getDoubleInput("Prix du produit : ");
                int quantite = Utils::getIntInput("Quantité initiale : ");
                std::string categorie = Utils::getStringInput("Catégorie du produit : ");
                int fournisseurId = Utils::getIntInput("ID du fournisseur : ");
                gestionProduits.ajouterProduit(nom, prix, quantite, categorie, fournisseurId);
                std::cout << "Produit ajouté avec succès !\n";
                break;
            }
            case 2: {
                int id = Utils::getIntInput("ID du produit à mettre à jour : ");
                double nouveauPrix = Utils::getDoubleInput("Nouveau prix : ");
                int quantiteAjoutee = Utils::getIntInput("Quantité ajoutée : ");
                gestionProduits.mettreAJourProduit(id, nouveauPrix, quantiteAjoutee);
                std::cout << "Produit mis à jour avec succès !\n";
                break;
            }
            case 3: {
                int id = Utils::getIntInput("ID du produit à supprimer : ");
                gestionProduits.supprimerProduit(id);
                std::cout << "Produit supprimé avec succès !\n";
                break;
            }
            case 4: {
                auto produits = gestionProduits.listerProduits();
                for (const auto& produit : produits) {
    				for (const auto& champ : produit) {
        				std::cout << champ << " ";
    				}
    				std::cout << "\n";
				}
                
                break;
            }
            case 5:
                return;
            default:
                std::cout << "Option invalide.\n";
        }
        Utils::attendreEntree();
    }
}

// Menu Gestion des commandes
void menuGestionCommandes(GestionCommandes& gestionCommandes) {
    while (true) {
        afficherTitre("Gestion des Commandes");
        std::cout << "1. Créer une commande\n";
        std::cout << "2. Traiter une commande\n";
        std::cout << "3. Annuler une commande\n";
        std::cout << "4. Afficher toutes les commandes\n";
        std::cout << "5. Retour au menu principal\n";
        std::cout << "\nChoisissez une option : ";
        int choix = Utils::getIntInput("");

        switch (choix) {
            case 1: {
                int clientId = Utils::getIntInput("ID du client : ");
				std::vector<std::pair<int, int>> produits;
				int nombreProduits = Utils::getIntInput("Combien de produits pour cette commande ? ");

				for (int i = 0; i < nombreProduits; ++i) {
			    int produitId = Utils::getIntInput("Entrez l'ID du produit : ");
				int quantite = Utils::getIntInput("Entrez la quantité : ");
			    produits.emplace_back(produitId, quantite);
				}

				// Passez maintenant le vecteur de produits à la méthode creerCommande
				gestionCommandes.creerCommande(clientId, produits);
                std::cout << "Commande créée avec succès !\n";
                break;
                
            }
            case 2: {
                int commandeId = Utils::getIntInput("ID de la commande à traiter : ");
                gestionCommandes.traiterCommande(commandeId);
                std::cout << "Commande traitée avec succès !\n";
                break;
            }
            case 3: {
                int commandeId = Utils::getIntInput("ID de la commande à annuler : ");
                gestionCommandes.annulerCommande(commandeId);
                std::cout << "Commande annulée avec succès !\n";
                break;
            }
            case 4: {
                auto commandes = gestionCommandes.listerCommandes();
                for (const auto& commande : commandes) {
    				for (const auto& champ : commande) {
        				std::cout << champ << " ";
    				}
    			std::cout << "\n";
				}
                break;
            }
            case 5:
                return;
            default:
                std::cout << "Option invalide.\n";
        }
        Utils::attendreEntree();
    }
}

// Menu Gestion de l'inventaire
void menuGestionInventaire(GestionInventaire& gestionInventaire) {
    while (true) {
        afficherTitre("Gestion de l'Inventaire");
        std::cout << "1. Réapprovisionner un produit\n";
        std::cout << "2. Vérifier les stocks\n";
        std::cout << "3. Afficher l'inventaire complet\n";
        std::cout << "4. Retour au menu principal\n";
        std::cout << "\nChoisissez une option : ";
        int choix = Utils::getIntInput("");

        switch (choix) {
            case 1: {
                int produitId = Utils::getIntInput("ID du produit : ");
                int quantite = Utils::getIntInput("Quantité à ajouter : ");
                gestionInventaire.reapprovisionnerProduit(produitId, quantite);
                std::cout << "Produit réapprovisionné avec succès !\n";
                break;
            }
            case 2: {
                int produitId = Utils::getIntInput("ID du produit : ");
                gestionInventaire.verifierStock(produitId);
                break;
            }
            case 3: {
                auto inventaire = gestionInventaire.verifierTousLesStocks();
			    for (const auto& produit : inventaire) {
			        std::cout << "ID : " << produit.first << ", Nom : " << produit.second << "\n";
    			}                
                break;
            }
            case 4:
                return;
            default:
                std::cout << "Option invalide.\n";
        }
        Utils::attendreEntree();
    }
}

// Menu principal
void afficherMenuPrincipal() {
    afficherTitre("Gestionnaire de Supermarché");
    std::cout << "1. Gestion des produits\n";
    std::cout << "2. Gestion des commandes\n";
    std::cout << "3. Gestion de l'inventaire\n";
    std::cout << "4. Recherche de produits\n";
    std::cout << "5. Quitter\n";
    std::cout << "\nChoisissez une option : ";
}

// Point d'entrée principal
int main() {
    try {
        // Initialisation
        Database db("supermarche.db");
        GestionProduits gestionProduits(db);
        GestionCommandes gestionCommandes(db);
        GestionInventaire gestionInventaire(db);

        // Menu principal
        while (true) {
            afficherMenuPrincipal();
            int choix = Utils::getIntInput("");

            switch (choix) {
                case 1:
                    menuGestionProduits(gestionProduits);
                    break;
                case 2:
                    menuGestionCommandes(gestionCommandes);
                    break;
                case 3:
                    menuGestionInventaire(gestionInventaire);
                    break;
                case 4:
                    menuRechercheProduits(gestionProduits);
                    break;
                case 5:
                    std::cout << "Merci d'avoir utilisé l'application. À bientôt !\n";
                    return 0;
                default:
                    std::cout << "Option invalide. Réessayez.\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }
}

