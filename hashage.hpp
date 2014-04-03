#ifndef HASHAGE_H
#define HASHAGE_H

int const NULL=0;
template <typename Valeur>
/*
*Classe gérant le dictionnaire via une table de hashage
*/
class Hashage{
    
    private:
    
   typedef struct _maillon {
        string mot;
        Valeur val;
        _maillon * suiv ;
    }maillon;

    typedef struct chainageTab{
        int taille;
        maillon * tete;
    };

    chainageTab table[40];
    
    
    public:
    Hashage();
    ~Hashage();
    
    bool contientMot(String mot);
    // vrai ssi la chaîne mot figure dans le dictionnaire
    
    void ajouterMot(String mot, Valeur v);
    // ajoute la chaîne mot au dictionnaire, avec la valeur v,
    // mot étant supposé absent du dictionnaire
    
    void associerMot(String mot, Valeur v);
    // associe la valeur v à la chaîne mot dans le dictionnaire,
    // mot pouvant être présent ou absent du dictionnaire
    
    void supprimerMot(String mot);
    // supprime l'éventuelle chaîne mot du dictionnaire
    
    Valeur valeurAssociee(String mot);
    // donne la valeur correspondant à la chaîne mot
    // (supposée figurer dans le dictionnaire)
    
    int hashage(String sparkle);
    
};
#include <iostream>
#endif 