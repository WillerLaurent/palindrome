#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main()
{
    printf("LE PALINDROME\n\n");

    char mot[100], copyMot[100];
    int i = 0, j = 0, longueur = 0, palindrome = 1;

    printf("Entrez un mot ou une phrase : ");
    fgets(mot, 100, stdin);

    copyString(mot, copyMot);

    longueur = enleveEspace(mot);


            for(i=0, j=longueur-2; i<j; i++, j--)
        {
            printf("mot[%d] : %c\n", i, mot[i]);
            printf("mot[%d] : %c\n", j, mot[j]);


            if(mot[i] != mot[j])
            {
                palindrome = 0;
                printf("Le mot / la phrase \'%s\' n'est pas un palindrome\n", copyMot);
                break;
            }
        }


    if(palindrome == 1)
    {
        printf("Le mot / la phrase \'%s\' est un palindrome\n", copyMot);
    }

   /* if(palindrome == 0)
    {
        printf("Le mot %s n'est pas un palindrome\n", mot);
    }*/
    //printf("Nombre de lettre : %d\n", longueur);
    return 0;
}

int longueurMot(char *mot)
{
    int longueur = 0;
    char caractereActuel = 0;

    do
    {
        caractereActuel = mot[longueur];

        if(caractereActuel == '\n')
        {
            mot[longueur] = '\0';
        }

        longueur++;
    }
    while(caractereActuel != '\0');
    longueur--;

    return longueur;
}

int enleveEspace(char *chaine)
{
    int i,j, longueur;
    char caractere = 0;

    longueur = longueurMot(chaine);

    for(i=0; i<longueur; i++)
    {
        toLower(&chaine[i]); // met en minuscule
        caractere = chaine[i];

        if(caractere == 32)
        {
            for(j=i; j<longueur; j++)
            {
                chaine[j] = chaine[j+1];
            }
            longueur--;
            i--;
        }
    }

    return longueur;
}

void toLower(char *caractere)
{
    if(*caractere<='Z' && *caractere>='A')
    {
        *caractere = *caractere + 32;
    }
}

void copyString(char *model, char *copie)
{
    int i = 0;

    do
    {
        copie[i] = model[i];
        i++;
    }
    while(model[i] != '\0');

    copie[i-1] = '\0';
}
