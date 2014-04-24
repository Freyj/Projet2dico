#ifndef ARBRE_H
#define ARBRE_H

int const NULL=0;
template <typename Valeur>
/*
*Classe permettant l'implémentation du dictionnaire par un arbre
*/
class Dictionnaire{

    private:
        typedef struct _feuille{
            vector<_feuille> suiv;
            char lettre;
        }feuille;

        feuille alpha[26];
        recursivContient(feuille feui, std::string mot, int rang);


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
        Valeur valeurAssociée(std::string mot);
        // donne la valeur correspondant à la chaîne mot
        // (supposée figurer dans le dictionnaire)
        int indexAlpha(std::string sparkle);


};
#include <iostream>
#endif
