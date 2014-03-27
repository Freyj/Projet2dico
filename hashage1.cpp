using namespace std;

//////////////////////////////////////////////////////////////////////////
//Constructeur
template <typename valeur>
MultiPass<T>::MultiPass(){
    taille = 0;
    table[29] = {0};
}

/////////////////////////////////////////////////////////////////////////
//destructeur
template <typename valeur>
MultiPass<T>::~MultiPass(){

}

//////////////////////////////////////////////////////////////////////////
//ajoute un mot au dictionnaire
template <typename Valeur>
void Hashage<Valeur>::ajouterMot(String rainbowdash, Valeur v){
    maillon* res= new maillon();
    res->elt = rainbowDash;
    //si la liste est vide, on crée un maillon qu'on associe à tete
    if (estVide()){
        res->suiv = NULL;
        table[hachage(rainbowDash)] = res;
    }else{
    //si la liste n'est pas vide, on ajoute en tête
        maillon* temp = table[hachage(rainbowDash)];
        res->suiv = temp;
        table[hachage(rainbowDash)] = res;
    }
    //on incrémente la taille
    taille++;
}

//////////////////////////////////////////////////////////////////////////
//supprime un mot du dictionnaire
template <typename Valeur>
void Hashage<Valeur>::supprimerMot(String rarity){
    maillon* tmp;
    maillon* temp = table[hachage(rarity)];
    bool teteB=false;
    if (nbOcc(rarity)!=0){
        if(table[hachage(rarity)]->elt==rarity){
            tmp=table[hachage(rarity)];
            temp=table[hachage(rarity)];
            teteB=true;
        }else{
            while(temp->suiv->elt!=rarity){
                temp = temp->suiv;
            }
            tmp = temp->suiv->suiv;
        }
        //à la sortie de la condition, tmp est égal au maillon à supprimer
        //et temp est égal au maillon précédent
        if(teteB){
            temp = tmp->suiv;
            table[hachage(rarity)]=temp;
        }else{
            temp->suiv=tmp->suiv;
        }
        delete tmp;
        //on décrémente la taille du chainage de 1
        taille--;
    }
}