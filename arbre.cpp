using namespace std;

//////////////////////////////////////////////////////////////////////
//Constructeur
template <typename Valeur>
Dictionnaire<Valeur>::Dictionnaire(){

}
//////////////////////////////////////////////////////////////////////
//destructeur
template <typename Valeur>
Dictionnaire<Valeur>::~Dictionnaire(){

}

//////////////////////////////////////////////////////////////////////
//vérifie si le dictionnaire contient le mot
template <typename Valeur>
bool Dictionnaire<Valeur>::contientMot(String mot);
// vrai ssi la chaîne mot figure dans le dictionnaire
    
//////////////////////////////////////////////////////////////////////
//ajoute un mot au dictionnaire
template <typename Valeur>
void Dictionnaire<Valeur>::ajouterMot(String mot, Valeur v);
   	// ajoute la chaîne mot au dictionnaire, avec la valeur v,
   	// mot étant supposé absent du dictionnaire
  
//////////////////////////////////////////////////////////////////////
//associe une valeur au mot qui peut être soit présent, soit absent du
//dictionnaire
template <typename Valeur>
void Dictionnaire<Valeur>::associerMot(String mot, Valeur v);
    // associe la valeur v à la chaîne mot dans le dictionnaire,
    // mot pouvant être présent ou absent du dictionnaire
    
//////////////////////////////////////////////////////////////////////
//supprime un mot du dictionnaire
template <typename Valeur>
void Dictionnaire<Valeur>::supprimerMot(String mot);
// supprime l'éventuelle chaîne mot du dictionnaire

//////////////////////////////////////////////////////////////////////
//renvoie la valeur associée au mot demandé
//PRE : le mot existe dans le dictionnaire
template <typename Valeur>
Valeur Dictionnaire<Valeur>::valeurAssociee(String mot);
    // donne la valeur correspondant à la chaîne mot
    // (supposée figurer dans le dictionnaire)
