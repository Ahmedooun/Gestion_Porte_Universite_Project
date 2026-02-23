//
// Created by ahmed on 15/10/2025.
//

#include "../header/AgentSecurite.h"
#include <iostream>

AgentSecurite::AgentSecurite(const std::string& nom, int id)
    : Personne(nom, id, NiveauSecurite::SECURITE) {} // Niveau de sécurité maximal

void AgentSecurite::afficherInfo() const {
    std::cout << "[Agent de Securite] Nom : " << nom
              << " | ID : " << id
              << " | Niveau de securite : " << niveauToString(niveauSecurite)
              << std::endl;
}