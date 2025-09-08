#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){

    int chois,i = 0,q, total = 0,found=0,cmp=0;
    char TitreDuLivre[100][100] ;
    char AuteurDuLivre[1000][100];
    char NomDuLivre[100];
    float PrixDuLivre[1000];
    int QuantitenStock[1000];
    int leNombreTotalDeLivres[1000];
    awed:

    chois = 0;

    printf("Choisissez ce que vous devez faire \n1.Ajouter un Livre au Stock.\n2.rechercher le livre par son nom.\n3.Afficher Tous les Livres Disponibles.\n4.Mettre a Jour la Quantite d'un Livre.\n5.Supprimer un Livre du Stock.\n6.Afficher le Nombre Total de Livres en Stock.\nchois(1-6) : ");
    scanf("%d", &chois);
     switch (chois)
     {
     case 1:
                for ( i ; i < 100; i++)
            {
                system("cls");
                printf("le nome du livre : ");
                scanf(" %[^\n]s", &TitreDuLivre[i]);
                printf("leuteur du livre : ");
                scanf(" %[^\n]s", &AuteurDuLivre[i]);
                printf("le prix du livre : ");
                scanf("%f", &PrixDuLivre[i]);
                printf("la quantite en stock : ");
                scanf(" %d", &QuantitenStock[i]);
                system("cls");
                printf("voulez-vous ajouter un livre :\n1.yes\n2.no\nchois(1-2) : ");
                scanf(" %d", &chois);
                
                if (chois == 1 )
                {
                    continue;
                }else 
                    i++;
                
                    break;
                
                
            }
            system("cls");
                    goto awed;  
        break;
     case 2:
                rcm:
                printf("entrer nam de livre : ");
                scanf(" %[^\n]s",&NomDuLivre);
                found = 0 ;

                for (int cmp = 0; cmp < i; cmp++)
                {
                    if (strcmp(NomDuLivre,TitreDuLivre[cmp]) == 0 )
                    {
                        printf("%i.%-20s%-20s%-20.2f%d\n", cmp+1, TitreDuLivre[cmp],AuteurDuLivre[cmp],PrixDuLivre[cmp],QuantitenStock[cmp]);
                        found = 1;
                    }
                    

                }
                if (!found)
                {
                    printf("aucun dun livre avec ce name in livre .");
                }
                
                printf("voulez-vous rendre le nom purement :\n1.yes\n2.no\nchois(1-2) : ");
                scanf("%d", &chois);
                if (chois == 1 )
                {
                    system("cls");
                    goto rcm;
                }else 
                    system("cls");
                    goto awed;
                break;
     case 3:
                printf("  %-20s%-20s%-20s.%-20s\n" ,"titre" ,"Auteur","Prix","Quantiten");
                for ( q = 0; q < i ; q++)
                {
                    
                    printf("%d.%-20s%-20s%-20.2f%d\n",q+1, TitreDuLivre[q],AuteurDuLivre[q],PrixDuLivre[q],QuantitenStock[q]);
                }
                
                    printf("voulez-vous revenir au debut :\n1.yes\n2.no\nchois(1-2) : ");
                scanf("%d", &chois);
                if (chois == 1 )
                {
                    system("cls");
                    goto awed;
                }else 
                
                    return 0 ;
                
        break;
    case 4:
                printf("entrer nam de livre qui tu as midiffier : ");
                scanf(" %[^\n]s",&NomDuLivre);
                found = 0 ;
                //int NewNumber;

                for ( cmp = 0; cmp < i; cmp++)
                {
                    if (strcmp(NomDuLivre,TitreDuLivre[cmp]) == 0 )
                    {
                        printf("%d.%-20s%-20s%-20.2f%d\n",cmp+1, TitreDuLivre[cmp],AuteurDuLivre[cmp],PrixDuLivre[cmp],QuantitenStock[cmp]);
                        found = 1;
                        printf("quelle est la nouvelle quantite du livre : ");
                        scanf("%d", &QuantitenStock[cmp]);
                    }
                    

                }
                if (!found)
                {
                    printf("aucun dun livre avec ce name in livre .");
                }
                //printf("quelle est la nouvelle quantite du livre : ");
                //scanf("%d", &QuantitenStock[cmp]);
                printf("voulez-vous revenir au debut :\n1.yes\n2.no\nchois(1-2) : ");
                scanf("%d", &chois);
                if (chois == 1 )
                {
                    system("cls");
                    goto awed;
                }else 
                
                    return 0 ;
        
        break;
    case 5:
                printf("entrer nam de livre qui tu as suprumer : ");
                scanf(" %[^\n]s",&NomDuLivre);
                found = 0 ;

                for ( cmp = 0; cmp < i; cmp++)
                {
                    if (strcmp(NomDuLivre,TitreDuLivre[cmp]) == 0 )
                    {
                        printf("%d.%-20s%-20s%-20.2f%d\n",cmp+1, TitreDuLivre[cmp],AuteurDuLivre[cmp],PrixDuLivre[cmp],QuantitenStock[cmp]);
                        found = 1;
                        break;
                    }
                    

                }
                if (!found)
                {
                    printf("aucun dun livre avec ce name in livre .");
                    goto ERER;
                }
                

                for (int w = cmp ; w < i ; w++)
                {
                    strcpy(TitreDuLivre[w] , TitreDuLivre[w+1]);
                    strcpy(AuteurDuLivre[w] , AuteurDuLivre[w+1]);
                    PrixDuLivre[w] = PrixDuLivre[w+1];
                    QuantitenStock[w] = QuantitenStock[w+1];
                }
                
                i = i -1;

                ERER:
                printf("voulez-vous revenir au debut :\n1.yes 2.no\nchois(1-2) : ");
                scanf("%d", &chois);
                if (chois == 1 )
                {
                    system("cls");
                    goto awed;
                }else 
                
                    return 0 ;
        break;
    case 6:
                
                total = 0 ;
                for (int  m = 0; m <= i ; m++)
                {
                    
                    total = total + QuantitenStock[m-1] ;
                }
                printf("les livre en stock est : %d", total);

                printf("\nvoulez-vous revenir au debut :\n1.yes\n2.no\nchois(1-2) : ");
                scanf("%d", &chois);
                if (chois == 1 )
                {
                    system("cls");
                    goto awed;
                }else 
                
                    return 0 ;
        
        
        break;
     
     default:
        break;
     
 
     printf("merci pour votre travail");
}
 }
 