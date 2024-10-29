#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Structs.h"
#include "Menus.h"
#include "Operations.h"


int (*listeFonctions[3])() = {Location,GestionVoitures,GestionClients};


int main()
{
    int id ;

    int num ;

    FILE *contracts , *cars , *tenants;

    cars = fopen("Voitures.txt", "rb+");
    tenants = fopen("Clients.txt", "rb+");
    contracts = fopen ("ContratsLocations.txt", "rb+");

    int choix,(*functionAdress)() , choice;
    do
    {
        printf("                  Menu Principal        \n\n\n");
        printf("     Location..............................1\n");
        printf("     Gestion voitures......................2\n");
        printf("     Gestion clients.......................3\n");
        printf("     Quitter...............................4\n");
        printf("\n\n                Votre choix : ");
        scanf("%d",&choix);
        printf("\n\n");
    }
    while(choix<1 || choix>4);
    printf("      ========================================\n");
    if(choix==4)
    {
        printf("      Merci d'avoir utiliser notre service :)\n");
        printf("      ========================================\n\n");
        exit(1);
    }
    else functionAdress=listeFonctions[choix-1];
    choice = functionAdress();
    switch(choix){
        case 1 : switch (choice){

              case 1 : visualiser(contracts , num);
                      break ;
              case 2 : louer(cars , contracts , tenants , id ) ;
                       break ;
              case 3 : retourner(contracts , cars , num);
                       break ;
              case 4 : modifier(contracts , num);
                       break ;
              case 5 : supprimer(cars , contracts , num);
                       break ;
        }
          case 2 : switch(choice){

               case 1 : Lister(cars);
                        break ;
               case 2 : Ajouter(cars);
                        break ;
               case 3 : Modifier(cars , id);
                        break ;
               case 4 : Supprimer(cars , id);
                        break ;



          }
          break ;
          case 3 : switch(choice){
               case 1 : LISTER(tenants);
                        break ;
               case 2 : AJOUTER(tenants);
                        break ;
               case 3 : MODIFIER(tenants , id);
                        break ;
               case 4 : SUPPRIMER(tenants , id);
                        break ;

          }
    }



    return 0;
}
