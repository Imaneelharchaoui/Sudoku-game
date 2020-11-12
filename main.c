#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define RESET 0
#include "sudoku44.h"
#include "user.h"
#include<string.h>




donnee* sudoku(char *nomfichier1,char *nomfichier2,char *nomfichier3,int n,listeUsers l){

    int i,j,solution=0,nCellVide;
    char ch;
	char login[50],password[50];
	donnee* user_connecte=Malloc(donnee);
    do{
		printf("\t\t\tSe connecter :\n\n");
		printf("\tlogin : ");
		scanf("%s",login);
		printf("\tpassword : ");
		scanf("%s",password);
		
	}while(!find(login,password,nomfichier1,nomfichier2,n));
	strcpy(user_connecte->lg,login);
	strcpy(user_connecte->pw,password);
	system("pause");
	system("cls");
	
    printf("\t\t\tThe Entered Sudoku puzzle is: \n");
    printf("\t\t\t");
	printGrid();
    printf("\t\t\tPress 'c' to confirm and solve, or 'e' to exit: ");
    ch=getch();
    if(ch=='e')
       exit(0);
    else if(ch=='c'){
   
		nCellVide=nEmptyCell();
		if(nCellVide){	
			sol_user();
		}
		
	
	solution=sudokuSolver();
    if(solution){
	 printf("\n\t\t\tSolution Valide \n");
	 l=score(nomfichier1,nomfichier2,nomfichier3, n, l, user_connecte);
	 printf("\n\t\t\tThe Solved Sudoku is: \n\n");
	 printGrid();
    }
    else
    printf("\n\t\t\tSolution Non valide !!\n\n");
    getch();
    }
return user_connecte;
}


int c=0;
void main(){
	
	printf("\n\t\t\t###########liste utilisateurs ###########\n\n");

	int reponse,code,continuer=1,n=0;
	donnee* user_connecte=Malloc(donnee);
    listeUsers l=NULL;
	char lg[20];
	char* nomfichier1="lg.dta";
	char* nomfichier2="pw.dta";
	char* nomfichier3="sc.dta";

    l=charger(nomfichier1,nomfichier2,nomfichier3,&n); 
		donnee * d1;
	do
    {

        printf("\n\t\t\t########### MENU DE jeu ###########\n\n");
        printf("\t\t\t\t1.Ajouter un utilisateur\n");
		printf("\t\t\t\t2.Afficher la liste des utilisateurs\n");
        printf("\t\t\t\t3.supprimer un utilisateur\n");
        printf("\t\t\t\t4.Jouer\n");
		printf("\t\t\t\t5.Meilleur scores\n\n");
		printf("\t\t\t\t0.Quiter\n\n");

        printf("\t\t\t#####################################\n\n");
        printf("\t\t\tDonner votre choix: ");

        /**********************************/
        scanf("%d",&reponse);
        switch(reponse)
        {
			case 1:
						

				d1=saisirUser(&n);

				l=insererUser(d1,l);
				printf("\nUser saisi \n");
				sauvegarder(nomfichier1,nomfichier2,nomfichier3,n,l);

				system("pause");
				system("cls");
				
					break;
			
			case 2:
				afficherUsers(l);
				system("pause");
				system("cls");
				break;
			
			case 3:

				printf("\t\tEntrer le lg du User a supprimer de la liste: ");
				scanf("%s",lg);
				l=supprimerUser(l,lg,&n);
				system("pause");
				system("cls");
				break;
			case 4:
			
				user_connecte=sudoku(nomfichier1,nomfichier2,nomfichier3,n,l);
				system("pause");
				system("cls");
				break;
			case 5:
				meilleur_score(l);
				system("pause");
				system("cls");
				break;
			case 0:
                sauvegarder(nomfichier1,nomfichier2,nomfichier3,n,l);
                exit(1);	
			
		
        }
    }
    while(continuer==1);
}



