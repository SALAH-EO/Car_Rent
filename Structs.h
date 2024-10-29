
typedef struct date

{

   int mm,dd,yy;

} date;

typedef struct Voiture
{
 int idVoiture;
 char marque[15];
 char nomVoiture[15];
 char couleur[7];
 int nbplaces;
 int prixJour;
 char EnLocation[4];
} voiture;

typedef struct contratLocation
{
 int numContrat;
 int idVoiture;
 int idClient;
 date debut;
 date fin;
 int Cout ;
} contrat;


typedef struct Client
{
 int idClient;
 char nom[20];
 char prenom[20];
 int Cin ;
 char adresse[15];
 int telephone;
}client;



