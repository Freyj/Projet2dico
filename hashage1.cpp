using namespace std;

//////////////////////////////////////////////////////////////////////
//Constructeur
template <typename Valeur>
Hashage<Valeur>::Hashage(){
    taille = 0;
    table[29] = {0};
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
    //si la liste est vide, on crée un maillon qu'on associe à tete
    if (estVide()){
        res->suiv = NULL;
        table[hashage(rainbowDash)] = res;
    }else{
    //si la liste n'est pas vide, on ajoute en tête
        maillon* temp = table[hashage(rainbowDash)];
        res->suiv = temp;
        table[hashage(rainbowDash)] = res;
    }
    //on incrémente la taille
    taille++;
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
    bool res;

    return res;
}

//////////////////////////////////////////////////////////////////////
//associe une valeur au mot
template <typename Valeur>
void Hashage<Valeur>::associerMot(String mot, Valeur v){

}

//////////////////////////////////////////////////////////////////////
//renvoie la valeur associée au mot demandé
template <typename Valeur>
 Valeur Hashage<Valeur>::valeurAssociée(String mot){

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