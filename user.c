#include "user.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int listeVide(listeUsers l){
	if(l == NULL)
		return 1;
	return 0;

}
donnee *saisirUser(int *n){ 

    donnee *Nouveau= Malloc(donnee);
	
    (*n)++;
    printf("\t\t Loging: ");
    scanf("%s",Nouveau->lg);
    printf("\t\t Pass word: ");
    scanf("%s",Nouveau->pw);
    Nouveau->score=0;
    return Nouveau;
}

user *creerUser(donnee *d){
    user *point_new=Malloc(user);
    point_new->infos=d;
    point_new->suivant=NULL;
    return point_new;
}

listeUsers insererUser(donnee *d,listeUsers l){


listeUsers p=creerUser(d); // contient l nouveau adh a inserer
listeUsers pl;	// pour parcourir la liste
listeUsers q;	// aider a inserer au milieu d la liste
			
		pl=l;
		 
						if( listeVide(l) || ( !listeVide(l) && strcmp(d->lg,pl->infos->lg)<0))
						{
							p->suivant=pl;
							pl=p;
							return pl;
						}else
					{
					q=pl;
					pl=pl->suivant;
					while(pl &&  strcmp(d->lg,pl->infos->lg)>0) {
						q=pl;
						pl=pl->suivant;
						}
						
					p->suivant=pl;
					q->suivant=p;
						
				return l; 		
		     	}
	
}

void afficherUsers(listeUsers liste){
listeUsers aux;
	if(liste==NULL){
		printf("il n'existe aucun user \n");
		return;
	}
	aux = liste; //on se place au début
	while(aux != NULL){
		printf("%s\t",aux->infos->lg);
		printf("%s\n",aux->infos->pw);
		printf("%d\n",aux->infos->score);
	
		
		aux = aux->suivant;
	}
	return;
}


listeUsers supprimerUser(listeUsers l,char *lg,int *n){

listeUsers pl=l,q;

	if(l==NULL){
			printf("il n'existe aucun user \n");
			return l;
		}
		if(!strcmp(lg,pl->infos->lg)){
			l=pl->suivant;
			free(pl);
			(*n)--;
			return l;
		}	
		q=pl;
		pl=pl->suivant;
		while(pl &&  (strcmp(lg,pl->infos->lg))) {
			q=pl;
			pl=pl->suivant;
		}
		if(pl){					
		q->suivant=pl->suivant;
		free(pl);
		(*n)--;
		}
		else
			printf("il n'existe aucun user \n");
		
		return l; 		
   	}


listeUsers charger(char* nomfichier1,char* nomfichier2,char* nomfichier3, int* n) {
    listeUsers liste=Malloc(user);
	liste=NULL;
    FILE* file1;
    file1=fopen(nomfichier1,"rb");
	FILE* file2;
    file2=fopen(nomfichier2,"rb");
	FILE* file3=fopen(nomfichier3,"rb");

    if (file1==NULL || file2==NULL|| file3==NULL){
        printf("Erreur dans le chargement du fichier\n");
        exit(0);
    }
	fread(n, sizeof(int),1,file1);
	fread(n, sizeof(int),1,file2);
	fread(n, sizeof(int),1,file3);

	
 	for (int i = 0; i < *n; i++) {
        donnee* d=Malloc(donnee);
        fread(d->lg,50*sizeof(char),1,file1);
        fread(d->pw,50*sizeof(char),1,file2);
		fread(&d->score,sizeof(int),1,file3);
		liste=insererUser(d,liste);
    }
    
	fclose(file2);
	fclose(file1);
	fclose(file3);

    return liste;
}

void sauvegarder(char* nomfichier1,char* nomfichier2,char* nomfichier3, int n, listeUsers liste) {
    listeUsers aux;
    FILE* flot1=fopen(nomfichier1,"wb");
	FILE* flot2=fopen(nomfichier2,"wb");
	FILE* flot3=fopen(nomfichier3,"wb");
    fwrite(&n,sizeof(int),1,flot1);
	fwrite(&n,sizeof(int),1,flot2);
	fwrite(&n,sizeof(int),1,flot3);

    aux=liste; 
    while(aux!=NULL){
        fwrite(aux->infos->lg,50*sizeof(char),1,flot1);
        fwrite(aux->infos->pw,50*sizeof(char),1,flot2);
		fwrite(&aux->infos->score,sizeof(int),1,flot3);

		aux=aux->suivant;
    }
	
	fclose(flot2);
	fclose(flot1);
	fclose(flot3);
    printf("\n\tSauvegardage termine\n");
    
}

listeUsers score(char* nomfichier1,char* nomfichier2,char* nomfichier3, int n, listeUsers liste, donnee* user_connecte){

listeUsers aux;
    FILE* flot1=fopen(nomfichier1,"wb");
	FILE* flot2=fopen(nomfichier2,"wb");
	FILE* flot3=fopen(nomfichier3,"wb");
    fwrite(&n,sizeof(int),1,flot1);
	fwrite(&n,sizeof(int),1,flot2);
	fwrite(&n,sizeof(int),1,flot3);

    aux=liste; 
    while(aux!=NULL){
		
        fwrite(aux->infos->lg,50*sizeof(char),1,flot1);
        fwrite(aux->infos->pw,50*sizeof(char),1,flot2);
		if(!strcmp(aux->infos->lg,user_connecte->lg)&& !strcmp(aux->infos->pw,user_connecte->pw))
			aux->infos->score=(aux->infos->score)+10;
		fwrite(&aux->infos->score,sizeof(int),1,flot3);

		aux=aux->suivant;
    }
	
	fclose(flot2);
	fclose(flot1);
	fclose(flot3);
    //printf("\n\tSauvegardage termine!\n");
return liste;
	}
	
void meilleur_score(listeUsers liste){
listeUsers aux;
	if(liste==NULL){
		printf("il n'existe aucun user \n");
		return;
	}
	aux = liste; //on se place au début
	aux=trier(aux);
	while(aux != NULL){
		printf("%s\t",aux->infos->lg);
		printf("%s\n",aux->infos->pw);
		printf("%d\n",aux->infos->score);
	
		aux = aux->suivant;
	}
	return;


}




listeUsers trier(listeUsers l)
{
	listeUsers i,j,min;

	for(i=l;i->suivant!=NULL;i=i->suivant)
	{min=i;
		 for(j=i->suivant;j!=NULL;j=j->suivant)
			 {if(j->infos->score > min->infos->score)
			 min=j;
			 }
			 if(i!=min)
			 {
			 listeUsers q=Malloc(user);
			 
			 strcpy(q->infos->lg,min->infos->lg);
			 strcpy(q->infos->pw,min->infos->pw);
			 q->infos->score=min->infos->score;
			 
			 strcpy(min->infos->lg,i->infos->lg);
			 strcpy(min->infos->pw,i->infos->pw);
			 min->infos->score=i->infos->score;
			 
			 strcpy(i->infos->lg,q->infos->lg);
			 strcpy(i->infos->pw,q->infos->pw);
			 i->infos->score=q->infos->score;
		 }
	}
	return l; 
}
	
