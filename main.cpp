#include <iostream>
#include <string>
#include "./header/Etudiant.h"
#include "./header/Enseignant.h"
#include "./header/AgentSecurite.h"
#include "./header/Badge.h"
#include "./header/LecteurBadge.h"
#include "./header/Serveur.h"
#include "./header/Scheduler.h"

using namespace std;

int main()
{
    // Création du serveur
    Serveur serveur("ServeurCentral");

    // Création de personnes et badges
    Etudiant e1("Alice", 1001);
    Enseignant e2("Dr. Bernard", 2001);
    AgentSecurite a1("Dupont", 3001);

    Badge b1(1, &e1);
    Badge b2(2, &e2);
    Badge b3(3, &a1);

    // Création de lecteurs
    LecteurBadge lecteurSalle("L001", "Salle B203", NiveauSecurite::ETUDIANT);
    LecteurBadge lecteurLabo("L002", "Laboratoire 3", NiveauSecurite::ENSEIGNANT);
    LecteurBadge lecteurSecurite("L003", "Salle Securite", NiveauSecurite::SECURITE);

    // Ordonnanceur
    Scheduler scheduler(&serveur);

    scheduler.ajouterPersonne(&e1, &b1);
    scheduler.ajouterPersonne(&e2, &b2);
    scheduler.ajouterPersonne(&a1, &b3);

    scheduler.ajouterLecteur(&lecteurSalle);
    scheduler.ajouterLecteur(&lecteurLabo);
    scheduler.ajouterLecteur(&lecteurSecurite);

    // Lancement d'une simulation de 15 tentatives entre 8h et 20h
    scheduler.simulationJournee(8, 20, 7);

    return 0;
}