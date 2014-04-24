#ifndef HASHAGE_H
#define HASHAGE_H

int const NULL=0;
template <typename Valeur>
/*
*Classe gérant le dictionnaire via une table de hashage
*/
class Dictionnaire{
    private:
        typedef struct _maillon {
            std::string mot;
            Valeur val;
            _maillon* suiv ;
        }maillon;

        typedef struct chainageTab{
            int taille;
            maillon* tete;
        };

        chainageTab table[40];


    public:
        Dictionnaire();
        ~Dictionnaire();

        bool contientMot(std::string mot);
        // vrai ssi la chaîne mot figure dans le dictionnaire

        void ajouterMot(std::string mot, Valeur v);
        // ajoute la chaîne mot au dictionnaire, avec la valeur v,
        // mot étant supposé absent du dictionnaire

        void associerMot(std::string mot, Valeur v);
        // associe la valeur v à la chaîne mot dans le dictionnaire,
        // mot pouvant être présent ou absent du dictionnaire

        void supprimerMot(std::string mot);
        // supprime l'éventuelle chaîne mot du dictionnaire

        Valeur valeurAssociee(std::string mot);
        // donne la valeur correspondant à la chaîne mot
        // (supposée figurer dans le dictionnaire)

        int hashage(std::string sparkle);
};
#include <iostream>
#endif
