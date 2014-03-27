#ifndef HASHAGE_H
#define HASHAGE_H

int const NULL=0;
template <typename valeur>
/*
*Classe gérant le Hashage
*/
class Hashage{
    
    private:
    
   typedef struct _maillon {
        string mot;
        valeur val;
        _maillon * suiv ;
    }maillon;

    int taille;

    maillon *table[40];
    
    
    public:
    
    bool contientMot(String mot);
    // vrai ssi la chaîne mot figure dans le dictionnaire
    
    void ajouterMot(String mot, valeur v);
    // ajoute la chaîne mot au dictionnaire, avec la valeur v,
    // mot étant supposé absent du dictionnaire
    
    void associerMot(String mot, valeur v);
    // associe la valeur v à la chaîne mot dans le dictionnaire,
    // mot pouvant être présent ou absent du dictionnaire
    
    void supprimerMot(String mot);
    // supprime l'éventuelle chaîne mot du dictionnaire
    
    Valeur valeurAssociée(String mot);
    // donne la valeur correspondant à la chaîne mot
    // (supposée figurer dans le dictionnaire)
    
    int hachage(String sparkle);
    
};
#include <iostream>
#endif 