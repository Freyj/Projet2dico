#ifndef HASHAGE_H
#define HASHAGE_H

const int NULL=0;
template <typename Valeur = int>
/*
*Classe g�rant le dictionnaire via une table de hashage
*/
class Dictionnaire{
    private:
        typedef struct _maillon {
            std::string mot;
            Valeur val;
            _maillon* suiv ;
        }maillon;

        typedef struct _chainageTab{
            int taille;
            maillon* tete;
        }chainageTab;

        chainageTab table[40];


    public:
        Dictionnaire();
        ~Dictionnaire();

        bool contientMot(std::string mot);
        // vrai ssi la cha�ne mot figure dans le dictionnaire

        void ajouterMot(std::string mot, Valeur v);
        // ajoute la cha�ne mot au dictionnaire, avec la valeur v,
        // mot �tant suppos� absent du dictionnaire

        void associerMot(std::string mot, Valeur v);
        // associe la valeur v � la cha�ne mot dans le dictionnaire,
        // mot pouvant �tre pr�sent ou absent du dictionnaire

        void supprimerMot(std::string mot);
        // supprime l'�ventuelle cha�ne mot du dictionnaire

        Valeur valeurAssociee(std::string mot);
        // donne la valeur correspondant � la cha�ne mot
        // (suppos�e figurer dans le dictionnaire)

        int hashage(std::string sparkle);
};
#include <iostream>
#endif
