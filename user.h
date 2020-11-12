#define Malloc(t) (t*)malloc(sizeof(t));

typedef struct _user{
char lg[50];
char pw[50];
int score;
}donnee;

typedef struct  user {
	donnee* infos;
	struct  user* suivant;
}user;

typedef user* listeUsers;

donnee *saisirUser(int *n);
user *creerUser(donnee *d);
listeUsers insererUser(donnee *d,listeUsers liste);
void afficherUsers(listeUsers liste);
listeUsers supprimerUser(listeUsers liste,char *lg, int* n);
listeUsers charger(char* nomfichier1,char* nomfichier2,char* nomfichier3, int* n);
void sauvegarder(char* nomfichier1,char* nomfichier2,char* nomfichier3, int n, listeUsers liste); 
listeUsers score(char* nomfichier1,char* nomfichier2,char* nomfichier3, int n, listeUsers liste, donnee* user_connecte);
listeUsers trier(listeUsers l);
void meilleur_score(listeUsers liste);

