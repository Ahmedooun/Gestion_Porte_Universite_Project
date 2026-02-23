//
// Created by ahmed on 15/10/2025.
//

#include "../header/Enseignant.h"
#include <iostream>

Enseignant::Enseignant(const std::string& nom, int id)
    : Personne(nom, id, NiveauSecurite::ENSEIGNANT) {} // Niveau de sécurité 3 (accès labo)

void Enseignant::afficherInfo() const {
    std::cout << "[Enseignant] Nom : " << nom
              << " | ID : " << id
              << " | Niveau de securite : " << niveauToString(niveauSecurite)
              << std::endl;
}