//
// Created by ahmed on 15/10/2025.
//

#include "../header/Personne.h"
#include <iostream>

Personne::Personne(const std::string& nom, int id, NiveauSecurite niveau)
    : nom(nom), id(id), niveauSecurite(niveau) {}

Personne::~Personne() = default;

std::string Personne::getNom() const { return nom; }
int Personne::getId() const { return id; }
NiveauSecurite Personne::getNiveauSecurite() const { return niveauSecurite; }