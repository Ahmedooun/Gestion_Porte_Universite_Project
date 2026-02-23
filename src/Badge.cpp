//
// Created by ahmed on 15/10/2025.
//

#include "../header/Badge.h"
#include "../header/NiveauSecurite.h"

Badge::Badge(int idBadge, Personne* proprietaire, bool actif)
    : idBadge(idBadge), proprietaire(proprietaire), actif(actif) {}

int Badge::getIdBadge() const { return idBadge; }

Personne* Badge::getProprietaire() const { return proprietaire; }

bool Badge::estActif() const { return actif; }

void Badge::desactiver() { actif = false; }

void Badge::activer() { actif = true; }

NiveauSecurite Badge::getNiveauSecurite() const {
    if (proprietaire)
        return proprietaire->getNiveauSecurite();
    return NiveauSecurite::ETUDIANT; // Par défaut
}

std::string Badge::getNomProprietaire() const {
    return proprietaire ? proprietaire->getNom() : "Inconnu";
}

/*std::ostream& operator<<(std::ostream& os, const Badge& badge) {
    os << "[Badge ID : " << badge.idBadge << "] "
       << "Proprietaire : " << badge.getNomProprietaire()
       << " | Actif : " << (badge.actif ? "Oui" : "Non")
       << " | Niveau : " << niveauToString(badge.getNiveauSecurite());
    return os;
}*/