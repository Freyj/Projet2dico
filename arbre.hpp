#ifndef ARBRE_H
#define ARBRE_H

int const NULL=0;
template <typename Valeur>
/*
*Classe permettant l'implémentation du dictionnaire par un arbre
*/
class Arbre{
    
    private:
    
    
    
    public:
    
    bool contientMot(String mot)
    // vrai ssi la chaîne mot figure dans le dictionnaire
    void ajouterMot(String mot, Valeur v)
    // ajoute la chaîne mot au dictionnaire, avec la valeur v,
    // mot étant supposé absent du dictionnaire
    void associerMot(String mot, Valeur v)
    // associe la valeur v à la chaîne mot dans le dictionnaire,
    // mot pouvant être présent ou absent du dictionnaire
    void supprimerMot(String mot)
    // supprime l'éventuelle chaîne mot du dictionnaire
    Valeur valeurAssociée(String mot)
    // donne la valeur correspondant à la chaîne mot
    // (supposée figurer dans le dictionnaire)
    
    
};
#include <iostream>
#endif 