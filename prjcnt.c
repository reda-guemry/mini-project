#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct contact{
    char nom [MAX] ;
    char NumeroDeTelepone[MAX];
    char AdresseEmail[MAX];
};

struct contact n[MAX];

int recherch()
    {
        int i ;
        char NomRecherch[100]; 

        printf("entrer nom que tu veus : ");
        scanf("%s", NomRecherch);
        for ( i = 0; i < MAX ; i++)
        {
        if (strcmp(NomRecherch , n[i].nom) == 0)
        {
            return i;
        }
        }
        printf("le nom nexist pas");
        return -1 ;
    }
int backmenu()
{
    int chois;

    do
    {
    printf("\nretur to menu .\n1.yes.\n2.no\nchois : ");
    scanf("%d", &chois);

    if (chois == 1)
    {
       system("cls");
       return 1 ;
    }else if (chois == 2)
    {
        system("cls");
        return 2 ;
    }
    } while (chois != 1 && chois != 2);
}

int main()
{
    int chois,Ncnt,found = 0;
    char NomRecherch[100];

    rt:
    printf("------entrer ce que vous allez faire------\n1.ajouter un contact.\n2.modifier un contact.\n3.supprimer un contact.\n4.afficer un contact.\n5.rechercher un contact.\nchois : ");
    scanf("%d",&chois);
    
    switch (chois)
    {
    case 1:
        system("cls");
        for ( Ncnt = 0; Ncnt < MAX ; Ncnt++)
        {
            printf("entrer le nom de cet contact : ");
            scanf(" %[^\n]s", &n[Ncnt].nom);
            printf("entrer le Numero de cet contact : ");
            scanf(" %[^\n]s", &n[Ncnt].NumeroDeTelepone);
            printf("entrer email de cet contact : ");
            scanf(" %[^\n]s", &n[Ncnt].AdresseEmail);
            ereur:
            printf("voulez-vous ajouter un autre nouveau contact ou retour to menu  .\n1.ajoutr un autre\n2.retour to menu\nchois(1-2): " );
            scanf("%d",&chois);
            if (chois == 1)
            {
                system("cls");
            }else if (chois == 2)
            {
                system("cls");
                goto rt;
            }else
                goto ereur;
                system("cls");
        }

        break;
    case 2:
            system("cls");
            found = recherch(NomRecherch);
            if (found < 0 )
            {
                goto MAkaynch ;
            }
            printf("nom : %s", n[found].nom);
            printf("\nNumero : %s", n[found].NumeroDeTelepone);
            printf("\nemail : %s\n", n[found].AdresseEmail);

            awad:
            printf("qoit tu va changer .\n1.nom.\n2.numero.\n3.email.\nchois : ");
            scanf("%d", &chois);

            switch (chois)
            {
            case 1:
                printf("entrer le nouveu nom : ");
                scanf(" %[^\n]s", n[found].nom);

                break;
            case 2:
                printf("entrer le nouvou numero : ");
                scanf(" %[^\n]s",n[found].NumeroDeTelepone);
                
                
                break;
            case 3:
                printf("entrer le nouveu email");
                scanf(" %[^\n]s",n[found].AdresseEmail);
                
                break;
            
            
            default:
                printf("eroor retry");
                goto awad;
                break;
            }
            MAkaynch :

            chois = backmenu();
            if (chois == 1)
            {
                goto rt;
            }else if (chois == 2)
            {
                printf("merci");
            }
            
        break;
    case 3:
            system("cls");
            found = recherch(NomRecherch) ; 
            if (found < 0 )
            {
                goto Makaynch ;
            }
            for (int i = found; i < Ncnt; i++)
            {
                n[i] =  n[i+1] ;
            }
            Ncnt = Ncnt - 1 ; 
            Makaynch :
            chois = backmenu();
            if (chois == 1)
            {
                goto rt;
            }else if (chois == 2)
            {
                printf("merci");
            }
            

        
        break;
    case 4:
            system("cls");
            for (int i = 0; i <= Ncnt; i++)
            {
                printf("%d.%-20s%-20s%-20s\n" ,i+1,n[i].nom,n[i].NumeroDeTelepone,n[i].AdresseEmail);
            }
            chois = backmenu();
            if (chois == 1)
            {
                goto rt;
            }else if (chois == 2)
            {
                printf("merci");
            }
            
        break;
    case 5:
            system("cls");
            found = recherch(NomRecherch);
            if (found < 0 )
            {
                goto makaynch ;
            }
            printf("nom : %s", n[found].nom);
            printf("\nNumero : %s", n[found].NumeroDeTelepone);
            printf("\nemail : %s\n", n[found].AdresseEmail);
            makaynch : 

            chois = backmenu();
            if (chois == 1)
            {
                goto rt;
            }else if (chois == 2)
            {
                printf("merci");
            }
        break;

    default:
            system("cls");
            printf("cette choit na pas exist .\nrettry votre chois .");
            chois = backmenu();
            if (chois == 1)
            {
                goto rt;
            }
        break;
    }
    printf("merci pour votre effort");
}