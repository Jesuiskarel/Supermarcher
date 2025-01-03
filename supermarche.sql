-- Création de la base de données pour la gestion des stocks

-- Table des fournisseurs
CREATE TABLE Fournisseur (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nom TEXT NOT NULL,
    adresse TEXT,
    telephone TEXT
);

-- Table des produits
CREATE TABLE Produit (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nom TEXT NOT NULL,
    prix REAL NOT NULL,
    quantite INTEGER NOT NULL,
    categorie TEXT NOT NULL,
    fournisseur_id INTEGER,
    FOREIGN KEY (fournisseur_id) REFERENCES Fournisseur(id) ON DELETE SET NULL
);

-- Table des clients
CREATE TABLE Client (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nom TEXT NOT NULL,
    email TEXT NOT NULL UNIQUE,
    telephone TEXT
);

-- Table des commandes
CREATE TABLE Commande (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    client_id INTEGER NOT NULL,
    dateCommande TEXT DEFAULT CURRENT_TIMESTAMP,
    statut TEXT DEFAULT 'En cours',
    FOREIGN KEY (client_id) REFERENCES Client(id) ON DELETE CASCADE
);

-- Table des produits dans une commande (relation *-*)
CREATE TABLE Commande_Produit (
    commande_id INTEGER,
    produit_id INTEGER,
    quantite INTEGER NOT NULL,
    PRIMARY KEY (commande_id, produit_id),
    FOREIGN KEY (commande_id) REFERENCES Commande(id) ON DELETE CASCADE,
    FOREIGN KEY (produit_id) REFERENCES Produit(id) ON DELETE CASCADE
);

-- Ajout des fournisseurs
INSERT INTO Fournisseur (nom, adresse, telephone) VALUES 
('Fournisseur Alim', '123 Rue Alim, Ville', '0612345678'),
('Fournisseur Elec', '456 Avenue Elec, Ville', '0623456789'),
('Fournisseur Cosmo', '789 Boulevard Cosmo, Ville', '0634567890'),
('Fournisseur Pain', '321 Rue Pain, Ville', '0645678901');

-- Ajout des produits
INSERT INTO Produit (nom, prix, quantite, categorie, fournisseur_id) VALUES
-- Alimentaire
('Lait', 1.50, 100, 'Alimentaire', 1),
('Riz', 2.00, 50, 'Alimentaire', 1),
('Farine', 1.20, 80, 'Alimentaire', 1),
('Huile', 3.50, 40, 'Alimentaire', 1),
('Sucre', 1.00, 60, 'Alimentaire', 1),
-- Electronique
('Télévision', 300.00, 10, 'Electronique', 2),
('Ordinateur', 800.00, 5, 'Electronique', 2),
('Smartphone', 600.00, 15, 'Electronique', 2),
-- Cosmétique
('Shampooing', 5.00, 30, 'Cosmétique', 3),
('Crème', 10.00, 25, 'Cosmétique', 3),
('Parfum', 50.00, 10, 'Cosmétique', 3),
('Savon', 2.50, 50, 'Cosmétique', 3),
-- Boulangerie
('Pain', 1.00, 100, 'Boulangerie', 4),
('Croissant', 0.80, 200, 'Boulangerie', 4),
('Baguette', 1.20, 150, 'Boulangerie', 4),
('Beignet', 0.50, 180, 'Boulangerie', 4);

-- Ajout des clients
INSERT INTO Client (nom, email, telephone) VALUES
('Jean Dupont', 'jean.dupont@example.com', '0678901234'),
('Marie Curie', 'marie.curie@example.com', '0689012345'),
('Paul Martin', 'paul.martin@example.com', '0690123456');

-- Ajout des commandes
INSERT INTO Commande (client_id, statut) VALUES
(1, 'En cours'),
(2, 'En cours'),
(3, 'En cours'),
(1, 'Traité'),
(2, 'Annulé'),
(3, 'En cours');

-- Ajout des produits aux commandes
INSERT INTO Commande_Produit (commande_id, produit_id, quantite) VALUES
-- Commande 1
(1, 1, 5), -- Lait
(1, 5, 2), -- Sucre
(1, 13, 10), -- Croissant
-- Commande 2
(2, 2, 3), -- Riz
(2, 7, 1), -- Ordinateur
(2, 9, 2), -- Shampooing
-- Commande 3
(3, 6, 1), -- Télévision
(3, 15, 6), -- Beignet
-- Commande 4
(4, 4, 2), -- Huile
(4, 3, 3), -- Farine
-- Commande 5
(5, 10, 1), -- Crème
(5, 11, 1), -- Parfum
-- Commande 6
(6, 12, 4), -- Savon
(6, 14, 2); -- Baguette

