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
bool Dictionnaire<Valeur>::contientMot(std::string mot){
    int indexTab = indexAlpha(mot);
    bool ret = false;
    for(int i= 0; i<alpha[indexTab].size(); i++){
        if(mot.at(1)==alpha[indexTab].suiv[i].lettre){
            ret = recursivContient(alpha[indexTab].suiv[i], mot, 1);
        }
    }
    return ret;
}
// vrai ssi la chaîne mot figure dans le dictionnaire

template <typename Valeur>
bool Dictionnaire<Valeur>::recursivContient(feuille feui, std::string mot, int rang){
    for(int i= 0; i<feui.suiv.size(); i++){
        if(mot.at(rang+1)==feui.suiv[i].lettre){
            if(rang+1==mot.size()){
                return true;
            }else{
                return recursivContient(feui.suiv[i], mot, rang+1)
            }
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////
//ajoute un mot au dictionnaire
template <typename Valeur>
void Dictionnaire<Valeur>::ajouterMot(std::string mot, Valeur v){
    int indexTab = indexAlpha(mot);
    bool trouv = false;
    for(int i= 0; i<alpha[indexTab].size(); i++){
        if(mot.at(1)==feui.suiv[i].lettre){
            trouv = true;
            recursivTrouvAjout(feui.suiv[i], mot, 1)
        }
    }
    if(!trouv){
        feuille* nouv = new feuille();
        nouv.lettr=mot.at(1);
        feui.suiv.push_back(nouv);
        recursivAjout(nouv, mot, 1);
    }
}
   	// ajoute la chaîne mot au dictionnaire, avec la valeur v,
   	// mot étant supposé absent du dictionnaire


recursivTrouvAjout(feuille feui, std::string mot, int rang){
    bool trouv = false;
    for(int i= 0; i<feui.suiv.size(); i++){
        if(mot.at(rang+1)==feui.suiv[i].lettre){
            trouv = true;
            recursivTrouvAjout(feui.suiv[i], mot, rang+1)
        }
    }

    if(!trouv){
        feuille* nouv = new feuille();
        nouv.lettr = mot.at(rang+1);
        feui.suiv.push_back(nouv);
        if(mot.size()!=rang){
            recursivAjout(nouv, mot, rang+1);
        }
    }
}

recursivAjout(feuille feui, mot, int rang){
    feuille* nouv = new feuille();
    nouv.lettr = mot.at(rang+1);
    feui.suiv.push_back(nouv);
    if(mot.size()!=rang){
        recursivAjout(nouv, mot, rang+1);
    }
}
//////////////////////////////////////////////////////////////////////
//associe une valeur au mot qui peut être soit présent, soit absent du
//dictionnaire
template <typename Valeur>
void Dictionnaire<Valeur>::associerMot(std::string mot, Valeur v);
    // associe la valeur v à la chaîne mot dans le dictionnaire,
    // mot pouvant être présent ou absent du dictionnaire

//////////////////////////////////////////////////////////////////////
//supprime un mot du dictionnaire
template <typename Valeur>
void Dictionnaire<Valeur>::supprimerMot(std::string mot);
// supprime l'éventuelle chaîne mot du dictionnaire

//////////////////////////////////////////////////////////////////////
//renvoie la valeur associée au mot demandé
//PRE : le mot existe dans le dictionnaire
template <typename Valeur>
Valeur Dictionnaire<Valeur>::valeurAssociee(std::string mot);
    // donne la valeur correspondant à la chaîne mot
    // (supposée figurer dans le dictionnaire)

template <typename Valeur>
int Dictionnaire<Valeur>::indexAlpha(std::string sparkle){
	int aMaj = 'A';
	int aMin = 'a';
	int first = sparkle[0];

	if(first <=90){
		return first - aMaj;
	}else{
		return first - aMin;
	}
}
