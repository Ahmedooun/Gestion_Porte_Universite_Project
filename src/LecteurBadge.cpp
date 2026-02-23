//
// Created by ahmed on 15/10/2025.
//

#include "../header/LecteurBadge.h"

LecteurBadge::LecteurBadge(const std::string& id, const std::string& loc, NiveauSecurite niveau)
    : idLecteur(id), localisation(loc), niveauRequis(niveau) {}

std::string LecteurBadge::getIdLecteur() const { return idLecteur; }
std::string LecteurBadge::getLocalisation() const { return localisation; }
NiveauSecurite LecteurBadge::getNiveauRequis() const { return niveauRequis; }

/*bool LecteurBadge::verifierAcces(const Badge& badge) const {
    if (!badge.estActif()) {
        std::cout << "ERR : Badge desactive pour " << badge.getNomProprietaire() << std::endl;
        return false;
    }

    NiveauSecurite niveauBadge = badge.getNiveauSecurite();

    if (static_cast<int>(niveauBadge) >= static_cast<int>(niveauRequis)) {
        std::cout << "OK : Acces autorise a " << badge.getNomProprietaire()
                  << " pour " << localisation << std::endl;
        return true;
    } else {
        std::cout << "NON : Acces refuse a " << badge.getNomProprietaire()
                  << " pour " << localisation
                  << " (niveau insuffisant)" << std::endl;
        return false;
    }
}*/

/*std::ostream& operator<<(std::ostream& os, const LecteurBadge& lecteur) {
    os << "[Lecteur ID : " << lecteur.idLecteur
       << "] Localisation : " << lecteur.localisation
       << " | Niveau requis : " << niveauToString(lecteur.niveauRequis);
    return os;
}*/