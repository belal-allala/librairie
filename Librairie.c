#include <stdio.h>
#include <string.h> 
#define max_livres 1000

int main() {
    char titre[max_livres][max_livres];
    char auteur[max_livres][max_livres];
    char recherche[100];
    char ligne[100];
    int quantite[max_livres];
    int somme = 0;
    int nblivres = 0;
    int existe = 0;
    int verifi=0;
    int i;
    float prix[max_livres];
    int choix;
    debut:
    printf("entrer votre choix :\n");
    printf("1. Ajouter un livre\n");
    printf("2. Afficher tous les livres\n");
    printf("3. Rechercher un livre par son titre.\n");
    printf("4. Mettre à jour la quantité d'un livre.\n");
    printf("5. Supprimer un livre du stock.\n");
    printf("6. Afficher le nombre total de livres en stock.\n");
    printf("0. Quitter\n");
    do{
        printf("choix: ");
        fgets(ligne,100,stdin);
        if (sscanf(ligne,"%d", &choix) != 1){
            printf("le choix invalide.\n");
            verifi=0;
        } else {
            verifi = 1;
        }
        } while (verifi == 0);
    switch (choix) {
        case 1:
            printf("entrer les info de livre:\n");
            printf("titre : ");
            scanf("%s", titre[nblivres]);
            printf("auteur : ");
            scanf("%s", auteur[nblivres]);
            getchar();
            do {
                printf("quantitie : ");
                verifi = scanf("%d", &quantite[nblivres]);
                if (verifi != 1 || quantite[nblivres] < 0){
                    printf("Quantite invalide. Entrez un nombre entier positif.\n");
                while (getchar() != '\n');
                        }
                } while (verifi != 1 || quantite[nblivres] < 0);
            do {
                printf("prix : ");
                verifi = scanf("%f", &prix[nblivres]);
                if (verifi != 1 || prix[nblivres] < 0){
                    printf("prix invalide. Entrez un nombre entier positif.\n");
                while (getchar() != '\n');
                        }
                } while (verifi != 1 || prix[nblivres] < 0);
            nblivres++;
            break;
        case 2:
            for (int i = 0; i < nblivres; i++) {
                printf("les livres disponibles sont :\n");
                printf("%s de %s, \n", titre[i], auteur[i]);
            }
            break;
        case 3:
            printf("titre a rechercher : ");
            scanf("%s", recherche);
            for (int i = 0; i < nblivres; i++) {
                if (strcmp(titre[i] , recherche)==0) {
                    printf("livre trouve:\n");
                    printf("titre: %s\nauteur: %s\nquantite: %d\nprix: %f\n", titre[i], auteur[i], quantite[i], prix[i]);
                    break;
                } else {
                printf("livre non trouve.\n");
                }
                break;
            }
            break;
        case 4:
            int nq;
            printf("titre du livre a modifier : ");
            scanf("%s", recherche);
            for (int i = 0; i < nblivres; i++) {
                if (strcmp(titre[i] , recherche)==0) {
                    do{
                    printf("nouvelle quantite :");
                    fgets(ligne,100,stdin);
                    if (sscanf(ligne,"%d", &nq) != 1) {
                    printf("nouvelle quantite invalide. Entrez un nombre entier positif.\n");
                    verifi=0;
                    } else {
                    verifi = 1;
                    }
                    } while (verifi == 0);
                    quantite[i] = nq;
                    printf("quantite mise a jour avec succes.\n");
                    existe = 1;
                    break;
                }
            }
            if (!existe) {
                printf("ce livre n existe pas dans librairie.\n");
            }
            break;
        case 5:    
            printf("titre du livre a supprimer : ");
            scanf("%s",&recherche);
            for (int i = 0; i < nblivres; i++) {
                if (strcmp(titre[i], recherche) == 0)  {
                    for (int j = i; j < nblivres - 1; j++) {
                        strcpy(titre[j], titre[j+1]);
                        strcpy(auteur[j],auteur[j+1]);
                        quantite[j] = quantite[j+1];
                        prix[j]=prix[j+1];
                    }
                    nblivres--;
                    printf("livre supprime avec succes.\n");
                    existe = 1;
                    break;
                }
            }
            if (!existe) {
            printf("livre n est existe pas dans librairie.\n");
            }
            break;
        case 6:
            for( i = 0; i < nblivres; i++);{
                somme = somme + quantite[i];
            }
            printf("le nombre total des livres est : %d\n", somme);
            break;
        case 0:
            goto final;
        default:
                printf("Choix n est pas valide.\n");
                goto debut;
    }
    fine:
    int revenu;
    printf("choisir 0 ou 1 pour quitter ou bien revenir au menu pricipal \n");
    printf("0. quitter le programme\n");
    printf("1. revenir au menu principal\n");
    scanf("%d",&revenu);
    if (revenu == 1)
        goto debut ;
    else if (revenu == 0)
    final:
        printf("merci");
    else 
        goto fine ;
    return 0;
}
