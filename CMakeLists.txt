cmake_minimum_required(VERSION 4.0)
project(AP4A_PROJET)

set(CMAKE_CXX_STANDARD 17)

add_executable(AP4A_PROJET main.cpp
        src/Personne.cpp
        src/Etudiant.cpp
        src/Enseignant.cpp
        src/AgentSecurite.cpp
        src/Badge.cpp
        src/LecteurBadge.cpp
        src/Serveur.cpp
        src/Scheduler.cpp
        header/AgentSecurite.h
        header/Badge.h
        header/Enseignant.h
        header/Etudiant.h
        header/LecteurBadge.h
        header/Personne.h
        header/Scheduler.h
        header/Serveur.h
        header/NiveauSecurite.h)
