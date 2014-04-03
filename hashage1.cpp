using namespace std;

//////////////////////////////////////////////////////////////////////
//Constructeur
template <typename Valeur>
Hashage<Valeur>::Hashage(){
    taille = 0;
    table[39] = {0};
}

//////////////////////////////////////////////////////////////////////
//destructeur
template <typename Valeur>
Hashage<Valeur>::~Hashage(){
}

//////////////////////////////////////////////////////////////////////
//ajoute un mot au dictionnaire
template <typename Valeur>
void Hashage<Valeur>::ajouterMot(String rainbowdash, Valeur v){
    maillon* res= new maillon();
    res->elt = rainbowDash;
    
    int index = hashage(rainbowdash);

    res->suiv = table[index].tete;
    table[index].tete = &res;
    table[index].taille++;
}

//////////////////////////////////////////////////////////////////////
//supprime un mot du dictionnaire
template <typename Valeur>
void Hashage<Valeur>::supprimerMot(String rarity){
    maillon* tmp;
    maillon* temp = table[hashage(rarity)];
    bool teteB=false;
    if (nbOcc(rarity)!=0){
        if(table[hashage(rarity)]->elt==rarity){
            tmp=table[hashage(rarity)];
            temp=table[hashage(rarity)];
            teteB=true;
        }else{
            while(temp->suiv->elt!=rarity){
                temp = temp->suiv;
            }
            tmp = temp->suiv->suiv;
        }
        //à la sortie de la condition, tmp est égal au maillon à 
        //supprimer et temp est égal au maillon précédent
        if(teteB){
            temp = tmp->suiv;
            table[hashage(rarity)]=temp;
        }else{
            temp->suiv=tmp->suiv;
        }
        delete tmp;
        //on décrémente la taille du chainage de 1
        taille--;
    }
}

//////////////////////////////////////////////////////////////////////
//vérifie si le dictionnaire contient le mot
template <typename Valeur>
bool Hashage<Valeur>::contientMot(String mot){
    if (taille!=0){
        int index_mot = hashage(mot);
        int i=0;
        maillon* temp = table[index_mot].tete;
        while(temp->val!=mot && i<table[index_mot].taille){
            i++;
            temp = temp->suiv;
        }
        if (i<taille-1){
            return true;
        }
        else{
            return false;
        }

    }
    else return false;
}

//////////////////////////////////////////////////////////////////////
//associe une valeur au mot qui peut être soit présent, soit absent du
//dictionnaire
template <typename Valeur>
void Hashage<Valeur>::associerMot(String mot, Valeur v){
    //si le mot est présent, on change la valeur associée (unicité)
    if (contientMot(mot)){
        int index_mot = hashage(mot);
        int i = 0;
        maillon* temp = table[index_mot].tete;
        while(temp->mot!=mot && i<table[index_mot].taille){
            i++;
            temp = temp->suiv;
        }
        temp->val = v;
    }
    //si le mot est absent, on l'ajoute au dictionnaire
    else {
        ajouterMot(String mot, Valeur v)
    }

}

//////////////////////////////////////////////////////////////////////
//renvoie la valeur associée au mot demandé
//PRE : le mot existe dans le dictionnaire
template <typename Valeur>
 Valeur Hashage<Valeur>::valeurAssociee(String mot){
    int index_mot = hashage(mot);
    int i = 0;
    maillon* temp = table[index_mot].tete;
    while(temp->mot!=mot && i<table[index_mot].taille){
        i++;
        temp = temp->suiv;
    }
    return temp->val;
 }

//////////////////////////////////////////////////////////////////////
//fonction de hashage qui ignore les 3 premières lettres du mot et les
// 2 dernières, et fait une addition des codes ascii des 3 lettres du 
//milieu  du mot puis un modulo 40 pour retourner un int de hash
//PRE : la chaine de caractères n'est pas vide
template <typename Valeur>
int Hashage<Valeur>::hashage(String sparkle){
    int res, i, ascii;
    String temp;
    ascii = 0;
    //si le mot fait plus de 5 lettres
    if (sparkle.size()>5){
        //on forme une sous-chaine
        temp = sparkle.substr(4,(sparkle.size()-5));
        for (i=0;i<temp.size();++i){
            ascii += (int) temp[i];
        }
        res = ascii % 40;
    }
    else {
        for (i=0;i<sparkle.size();++i){
            ascii+= (int) temp[i];
        }
        res = ascii %40
    }
    return res;
}