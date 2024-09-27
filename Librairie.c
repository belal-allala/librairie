#include <stdio.h>
#include <string.h>
#define max_livres 100

int main() {
    char titre[max_livres][max_livres];
    char auteur[max_livres][max_livres];
    char recherche[100];
    int quantite[max_livres];
    int nblivres = 0;
    int existe = 0;
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
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            printf("entrer les info de livre:\n");
            printf("titre : ");
            scanf("%s", titre[nblivres]);
            printf("auteur : ");
            scanf("%s", auteur[nblivres]);
            printf("quantite : ");
            scanf("%d", &quantite[nblivres]);
            printf("prix : ");
            scanf("%f", &prix[nblivres]);
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
                    printf("nouvelle quantite : ");
                    scanf("%d", &nq);
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
            scanf("%s", recherche);
            for (int i = 0; i < nblivres; i++) {
                if (strcmp(titre[i], recherche) == 0)  {
                    for (int j = i; j < nblivres - 1; j++) {
                        strcpy(titre[j], titre[j+1]);
                        strcpy(auteur[j],auteur[j+1]);
                        quantite[j] = quantite[j+1];
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
            printf("le nombre total des livres est : %d\n", nblivres);
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