#ifndef ARBRE_H
#define ARBRE_H

#include <vector>
template <typename Valeur>
/*
*Classe permettant l'impl�mentation du dictionnaire par un arbre
*/
class Dictionnaire{

    private:
        typedef struct _feuille{
            std::vector<_feuille> suiv;
            char lettre;
        }feuille;

        feuille alpha[26];
        bool recursivContient(feuille feui, std::string mot, int rang);


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
        int indexAlpha(std::string sparkle);


};
#include <iostream>
#endif
