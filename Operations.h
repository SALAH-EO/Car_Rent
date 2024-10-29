void AJOUTER (FILE *rep) ;

int Id(){
    // This program will create different sequence of
    // random numbers on every program run

    // Use current time as seed for random generator
    srand(time(0));  // utilise temp actuel comme source des nombres aleatoires

    int k  = rand();

    return k ;
}




/* =============Location=============== */

 void visualiser(FILE *rep , int *num) {
    contrat contrat ;
    int trouve=0;

   printf("Donnez le num du contrat : ");
  scanf("%d",&num);
  fseek(rep, 0, SEEK_SET);
  while (fread(&contrat, sizeof(contrat), 1, rep) != 0 && trouve==0) {
    if ((int)contrat.numContrat == (int)num) {trouve = 1 ; break ; }
  }

	   if (trouve == 0)  printf(" contrat introuvable \n");

      else {
     fseek(rep,-(sizeof contrat),SEEK_CUR) ;
	   printf("Les entrees anciennes : \n");
     printf("numero du contrat ........ ........: %d\n",contrat.numContrat  );
     printf("id voiture .............: %d\n",contrat.idVoiture  );
     printf("id client ................: %d\n",contrat.idClient  );
     printf("date debu du contrat : .....: %d %d %d\n",contrat.debut.dd , contrat.debut.mm , contrat.debut.yy  );
     printf("date fin du contrat : .....: %d %d %d\n",contrat.fin.dd , contrat.fin.mm , contrat.fin.yy  );
     printf("cout : .....: %d\n",contrat.Cout  );
}

 fseek(rep, 0, SEEK_SET);  main();
}

void louer(FILE *Vs , FILE *Cs , FILE *Cls , int *id   ){

      client client ;
      voiture test ;
      voiture voiture ;
      contrat contrat ;
       int trouve = 0;
       int trouve2=0 ;

  printf("votre id personnel du programme s'il vous plait  :  \n ");
  scanf("%d",&id);
  fseek(Cls, 0, SEEK_SET);
  while (fread(&client, sizeof(client), 1, Cls) != 0 && trouve==0) {
    if ( client.idClient == id )
      {
      	printf("Entrez les specifications de la voiture voulu :  \n");
      	printf ("marque  : ");
  scanf ("%s", &test.marque);
  printf ("nom voiture : ");
  scanf ("%s", &test.nomVoiture);
  printf("couleur : ");
  scanf("%s",&test.couleur);
  printf("nombre des places :");
  scanf("%d",&test.nbplaces);

          while (fread(&voiture, sizeof(voiture), 1, Vs) != 0 && trouve2==0){
            if(strcmp(voiture.marque,test.marque)==0  &&  strcmp(voiture.nomVoiture,test.nomVoiture)==0  &&  strcmp(voiture.couleur,test.couleur)==0   &&    voiture.nbplaces==test.nbplaces    )
                       {

                              if(strcmp(voiture.EnLocation, "Oui") == 0){
                                    fseek(Vs,-(sizeof voiture),SEEK_CUR) ;
                                    strcat(voiture.EnLocation , "Oui");
                                printf("felicitations tu as de la chance , cette voiture est disponible");
                                 contrat.numContrat = Id();
                                printf("numero de votre contrat est : %f  " , contrat.numContrat);
                                contrat.idVoiture = voiture.idVoiture ;
                                contrat.idClient = id ;
                                printf("tu vas prendre la voiture quand ? : \n");
                                scanf("%d %d %d" , &contrat.debut.dd,&contrat.debut.mm,&contrat.debut.yy);
                                printf("jusqu'a : \n");
                                scanf("%d %d %d" , &contrat.fin.dd, &contrat.fin.mm , &contrat.fin.yy);
                                contrat.Cout = ( contrat.fin.dd - contrat.debut.dd ) * voiture.prixJour ;
                                fseek(Cs, 0, SEEK_END);
                                fwrite (&contrat, sizeof(contrat), 1, Cs);
                                     trouve2 = 1 ;
                              }


                       }


          }
          if(trouve2==0) {
            printf("cette voiture n'est pas valable  \n");
            main();
          }

           trouve =1;
	  }
  }
  if (trouve == 0) {
    printf("Ce nom n'existe pas\n");
    printf("si tu veux tu peux s'enregistrer avec le menu suivant  \n ==============  \n  ");
    GestionClients();
  }

 fseek(Vs, 0, SEEK_SET); fseek(Cs, 0, SEEK_SET); fseek(Cls, 0, SEEK_SET);  main();
}





void supprimer(FILE *rep1 ,FILE *rep2 , int *num){



    FILE* temp = fopen("willberenamed.txt","wb+");
  contrat contrat ;
  voiture voiture ;
  int trouve2=0;
 // client buff ;
  int trouve = 0;
  char test;


  fseek(rep1 , 0, SEEK_SET);

  while (fread(&voiture, sizeof(voiture), 1, rep1) != 0 && trouve==0) {
    if (strcmp((voiture.EnLocation), "Non" ) == 0 )
      {


          while (fread(&contrat, sizeof(contrat), 1, rep2) != 0 && trouve2==0){
            fseek(rep2, 0, SEEK_SET);


		if(contrat.numContrat == num )
		{
              fseek(rep2,-(sizeof contrat),SEEK_CUR) ;
             fwrite(&contrat,sizeof( contrat),1,temp);
		}
		else
		{
			fwrite(&contrat,sizeof( contrat),1,temp);
		}

    fclose(rep2);

    remove(rep2);

   rename("willberenamed.txt" , "Voitures.txt");

   fclose(temp);




          }
          if(trouve2==0) {
            printf("cette voiture n'est pas valable  \n");
            main();
          }

           trouve =1;
	  }
  }
  if (trouve == 0) {
    printf("Cette contrat n'existe pas\n");
  }

 fseek(rep1, 0, SEEK_SET);   fseek(rep2, 0, SEEK_SET);

}



void modifier(FILE *rep ,int *num){

    contrat contrat ;
  int trouve = 0;
  char test;

  printf("Donnez le id : ");
  scanf("%d",&num);
  fseek(rep, 0, SEEK_SET);
  while (fread(&contrat, sizeof(contrat), 1, rep) != 0 && trouve==0) {
    if (contrat.numContrat == num) {trouve = 1 ; break ; }
  }

	   if (trouve == 0)  printf("Cette contrat n'existe pas\n");

      else {
     fseek(rep,-(sizeof contrat),SEEK_CUR) ;
	   printf("Les entrees anciennes : \n");
     printf("date debut ........ ........: %d %d %d\n",contrat.debut.dd , contrat.debut.mm , contrat.debut.yy  );
     printf("date fin .............: %d %d %d\n",contrat.fin.dd , contrat.fin.mm , contrat.fin.yy  );

        printf("\n\n qu'est ce que tu veux changer ? \n ============================= \n ");

     contrat.numContrat = contrat.numContrat ;
     printf("debut ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%d %d %d",&contrat.debut.dd,&contrat.debut.mm,&contrat.debut.yy) ; else { contrat.debut = contrat.debut  ; printf("\n"); }
     printf("fin ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%d %d %d",&contrat.fin.dd,&contrat.fin.mm,&contrat.fin.yy) ; else contrat.fin = contrat.fin ; printf("\n");
     contrat.Cout = contrat.Cout ;
     contrat.idClient = contrat.idClient ;
     contrat.idVoiture = contrat.idVoiture ;
     fwrite(&contrat,sizeof contrat,1,rep);
      }

       fseek(rep, 0, SEEK_SET);  main();


}


 void retourner(FILE* rep ,FILE *rep2 ,  int *num){
     voiture voiture ;
     contrat contrat ;
     int trouve=0;

 printf("num de contrat ") ;
 if(strcmp(voiture.EnLocation,"Non")==0 ){
 fseek(rep, 0, SEEK_SET);
  while (fread(&contrat, sizeof(contrat), 1, rep) != 0 && trouve==0) {
    if (contrat.numContrat == num)
      {
      	supprimer(rep , rep2 , num) ;
	  }
  }
  if (trouve == 0) {
    printf("Ce nom n'existe pas\n");
  }
 }

  fseek(rep, 0, SEEK_SET);    fseek(rep2, 0, SEEK_SET);    main();
}



/*===========Gestion voitures=================*/



void Lister(FILE *rep) {
   voiture voiture;

   fseek(rep,0,SEEK_SET);
 //  if(fread(&voiture,sizeof(voiture),1,rep) == 0){ printf("Fichier inaccessible ou vide \n"); system("pause"); main() ; }
   while (fread(&voiture,sizeof(voiture),1,rep) != 0) {
     printf("identificateur du voiture .....: %d\n",voiture.idVoiture  );
     printf("     La marque : ...............: %s\n",voiture.marque  );
     printf("      nom du voiture : .........: %s\n",voiture.nomVoiture  );
     printf("             Couleur : .........: %s\n",voiture.couleur  );
     printf("nombre des places : ............: %d\n",voiture.nbplaces  );
     printf("           Prix par Jour : .....: %d\n",voiture.prixJour  );
     printf("                  En Loc : .....: %s\n",voiture.EnLocation  );
     printf("\n ================================ \n");
   }

    fseek(rep, 0, SEEK_SET);  main();

}



void Ajouter (FILE *rep) {
  voiture voiture;
  voiture.idVoiture = Id();
  printf ("marque  : ");
  scanf ("%s", &voiture.marque);
  printf ("nom voiture : ");
  scanf ("%s", &voiture.nomVoiture);
  printf("couleur :");
  scanf("%s",&voiture.couleur);
  printf("nombre des places :");
  scanf("%d",&voiture.nbplaces);
  printf("Prix/Jour :");
  scanf("%d",&voiture.prixJour);
  printf("en location ? ");
  scanf("%s",&voiture.EnLocation);
  printf("\n l'Id mis pour la voiture est : %d",voiture.idVoiture);
  fseek(rep, 0, SEEK_END);
  fwrite (&voiture, sizeof(voiture), 1, rep);

   fseek(rep, 0, SEEK_SET);  main();
}


void Modifier(FILE *rep , int *id){

    voiture voiture ;
  int trouve = 0;
  char test;

  printf("Donnez le id : ");
  scanf("%d",&id);
  fseek(rep, 0, SEEK_SET);
  while (fread(&voiture, sizeof(voiture), 1, rep) != 0 && trouve==0) {
    if (voiture.idVoiture == id) {trouve = 1 ; break ; }
  }

	   if (trouve == 0)  printf("Ce client n'existe pas\n");

      else {
     fseek(rep,-(sizeof voiture),SEEK_CUR) ;
	   printf("Les entrees anciennes : \n");
     printf("marque du voiture........ ........: %s\n",voiture.marque  );
     printf("nom du voiture .............: %s\n",voiture.nomVoiture  );
     printf("couleur du voiture ................: %s\n",voiture.couleur  );
     printf("nbplaces : .....: %d\n",voiture.nbplaces  );
     printf("prix/jour : .....: %d\n",voiture.prixJour  );
        printf("\n\n qu'est ce que tu veux changer ? \n ============================= \n ");

     voiture.idVoiture = voiture.idVoiture ;
     printf("marque ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%s",&voiture.marque) ; else strcpy(voiture.marque , voiture.marque) ; printf("\n");
     printf("nom ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%s",&voiture.nomVoiture) ; else strcpy(voiture.nomVoiture,voiture.nomVoiture) ; printf("\n");
     printf("couleur ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%s",&voiture.couleur) ; else strcpy(voiture.couleur,voiture.couleur) ; printf("\n");
     printf("nb palces ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%d",&voiture.nbplaces) ; else voiture.nbplaces = voiture.nbplaces ; printf("\n");
     printf("prix jour ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%d",&voiture.prixJour) ; else voiture.prixJour = voiture.prixJour ; printf("\n");
     fwrite(&voiture,sizeof voiture,1,rep);
      }

       fseek(rep, 0, SEEK_SET);  main();

}

void Supprimer(FILE *rep , int *id){
    FILE* temp = fopen("willberenamed.txt","wb+");
  voiture voiture ;
 // client buff ;
  int trouve = 0;
  char test;

  printf("Donnez le id a supprimer : ");
  scanf("%d",&id);

  fseek(rep, 0, SEEK_SET);
  while (fread(&voiture, sizeof(voiture), 1, rep) != 0 && trouve==0) {
    if (voiture.idVoiture == id) {trouve = 1 ; break ; }
  }

	   if (trouve == 0) { printf("Ce client n'existe pas\n"); system("pause");  main();}


  printf("est ce que tu es sur ? o/n   :   ");
  scanf("%s",&test);

  if(test == 'o') {
    fseek(rep, 0, SEEK_SET);


    while(fread(&voiture, sizeof(voiture), 1, rep) != 0)
	{
		fread(&voiture,sizeof( voiture),1,rep);
		if(voiture.idVoiture==id)
		{
              fseek(rep,-(sizeof voiture),SEEK_CUR) ;
             fwrite(&voiture,sizeof( voiture),1,temp);
		}
		else
		{
			fwrite(&voiture,sizeof( voiture),1,temp);
		}
	}
    fclose(rep);

    remove(rep);

   rename("willberenamed.txt" , "Voitures.txt");

   fclose(temp);


  }
  else   {  fseek(rep, 0, SEEK_SET);  main(); }

}





/*=================Gestion clients==================*/

void LISTER(FILE *rep) {
   client client;

   fseek(rep,0,SEEK_SET);

   while (fread(&client,sizeof(client),1,rep) != 0) {
     printf("identificateur du client .....: %d\n",client.idClient  );
     printf("nom du client........ ........: %s\n",client.nom  );
     printf("prenom du client .............: %s\n",client.prenom  );
     printf("cin du client ................: %d\n",client.Cin  );
     printf("adresse : .....: %s\n",client.adresse  );
     printf("telephone : .....: %d\n",client.telephone  );
     printf("\n ================================ \n");
   }

}



void AJOUTER (FILE *rep) {
  client client;
  client.idClient = Id();
  printf ("nom  : ");
  scanf ("%s", &client.nom);
  printf ("prenom : ");
  scanf ("%s", &client.prenom);
  printf("Cin (nbre) : ");
  scanf("%d",&client.Cin);
  printf("adresse : ");
  scanf("%s",&client.adresse);
  printf("telephone : ");
  scanf("%d",&client.telephone);
  printf("\n votre id est : %d",client.idClient);
  fseek(rep, 0, SEEK_END);
  fwrite (&client, sizeof(client), 1, rep);

}


void MODIFIER(FILE *rep, int *id) {
  client client ;
  int trouve = 0;
  char test;

  printf("Donnez le id : ");
  scanf("%d",&id);
  fseek(rep, 0, SEEK_SET);
  while (fread(&client, sizeof(client), 1, rep) != 0 && trouve==0) {
    if (client.idClient == id) {trouve = 1 ; break ; }
  }

	   if (trouve == 0)  printf("Ce client n'existe pas\n");

      else {
     fseek(rep,-(sizeof client),SEEK_CUR) ;
	   printf("Les entrees anciennes : \n");
     printf("nom du client........ ........: %s\n",client.nom  );
     printf("prenom du client .............: %s\n",client.prenom  );
     printf("cin du client ................: %d\n",client.Cin  );
     printf("adresse : .....: %s\n",client.adresse  );
     printf("telephone : .....: %d\n",client.telephone  );
        printf("\n\n qu'est ce que tu veux changer ? \n ============================= \n ");

     client.idClient = client.idClient ;
     printf("nom ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%s",&client.nom) ; else strcpy(client.nom , client.nom) ; printf("\n");
     printf("prenom ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%s",&client.prenom) ; else strcpy(client.prenom,client.prenom) ; printf("\n");
     printf("cin ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%d",&client.Cin) ; else client.Cin=client.Cin ; printf("\n");
     printf("adresse ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%s",&client.adresse) ; else strcpy(client.adresse,client.adresse) ; printf("\n");
     printf("tel ? : (o/n) \t ") ; scanf("%s",&test) ;  if(test == 'o') scanf("%d",&client.telephone) ; else client.telephone=client.telephone ; printf("\n");
     fwrite(&client,sizeof client,1,rep);
      }

}


void SUPPRIMER(FILE *rep , int *id){
    FILE* temp = fopen("willberenamed.txt","wb+");
  client client ;
 // client buff ;
  int trouve = 0;
  char test;

  printf("Donnez le id a supprimer : ");
  scanf("%d",&id);

  fseek(rep, 0, SEEK_SET);
  while (fread(&client, sizeof(client), 1, rep) != 0 && trouve==0) {
    if (client.idClient == id) {trouve = 1 ; break ; }
  }

	   if (trouve == 0) { printf("Ce client n'existe pas\n"); system("pause");  main();}


  printf("est ce que tu es sur ? o/n   :   ");
  scanf("%s",&test);

  if(test == 'o') {
    fseek(rep, 0, SEEK_SET);


    while(fread(&client, sizeof(client), 1, rep) != 0)
	{
		fread(&client,sizeof( client),1,rep);
		if(client.idClient==id)
		{
              fseek(rep,-(sizeof client),SEEK_CUR) ;
             fwrite(&client,sizeof( client),1,temp);
		}
		else
		{
			fwrite(&client,sizeof( client),1,temp);
		}
	}
    fclose(rep);

    remove(rep);

   rename("willberenamed.txt" , "Clients.txt");

   fclose(temp);


  }
  else   {  fseek(rep, 0, SEEK_SET);  main(); }

}

