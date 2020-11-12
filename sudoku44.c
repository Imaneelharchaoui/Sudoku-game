#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define RESET 0
#include "sudoku44.h"
#include "user.h"
int grid[4][4]= {{0, 0, 4, 3},
        {4, 0, 0, 0},
        {0, 4, 0, 0},
        {3, 0, 0, 0}};



int row,col,nCellVide=0;
int *U; 
//this variable was used just to keep track of number of recursive calls
long int totalNumOfCalls=0;

int nEmptyCell(){
	int i,j;

 for(i=row;i<=3;i++)
     for(j=0;j<=3;j++){
	  if(grid[i][j]==0)
	  
	   nCellVide++;
	   
     }
return 	nCellVide;
}
	

int findEmptyCell(){
 int i,j;

 for(i=row;i<=3;i++)
     for(j=0;j<=3;j++){
	  if(grid[i][j]==0)
	   {
	   row=i;col=j;
	   return 1;
	   }
     }
   return 0;

}

int isValid(int cellRow, int cellCol, int num){
   int i,j;
     int rowStart = (cellRow/2) * 2;
    int colStart = (cellCol/2) * 2;

  // to check the presence of number in row and column
   for(j=0;j<=3;j++){
       if(grid[cellRow][j]==num)
    return 0;
       if(grid[j][cellCol]==num)
    return 0;

   }
     // to check the presence of number in 2X2 box

    for(i=rowStart;i<=rowStart+1;i++)
  for(j=colStart;j<=colStart+1;j++)
      if(grid[i][j]==num)return 0;
    return 1;
}
int sudokuSolver(){
    
     int prevRow,prevCol; // for backtracking
     totalNumOfCalls++;

     if(!findEmptyCell())
 return 1;
 
	for(int l=0;l<nCellVide;l++)
	{
		  if(findEmptyCell() && isValid(row,col,U[l])){
			  
			  grid[row][col]=U[l];
			  
			  prevRow=row;prevCol=col;
			 
		}
	
	}
	
	if(!findEmptyCell())
 return 1;
	return 0;
  
}

void sol_user(){
	int n;
	U=(int*)malloc(nCellVide*sizeof(int));

	printf("\n\t\t\tEntre une solution : "); 
	for(int i=0;i<nCellVide;i++){
		scanf("%d",&n);
		if(n!=1 && n!=2 && n!=3 && n!=4){
			printf("\n\t\t\t %d vs devez entre un nombre entre 1 et 4\n",n);
			i--;
		}
		if((n==1 || n==2 || n==3 || n==4))
		 U[i]=n;
	}	
}

void prin(){

	for(int i=0;i<nCellVide;i++){
		printf("%d",U[i]);
	}	
}

void printGrid(){

 int i,j;

 printf("\t-------------\n");
 for(i=0;i<4;i++){
    printf("\t");
    for(j=0;j<4;j++){
       if(j==0)
    printf("| ");
       if(grid[i][j]==0)
    printf(". ");
       else
    printf("%d ",grid[i][j]);
       if((j+1)%2==0 )
    printf("| ");

   }

   if((i+1)%2==0 )
       printf("\n\t-------------");

   printf("\n");

 }
}
int find(char* lg,char* pw,char* nomfichier1,char* nomfichier2, int n){

    listeUsers liste=Malloc(user);
	liste=NULL;
    FILE* file1;
    file1=fopen(nomfichier1,"rb");
	FILE* file2;
    file2=fopen(nomfichier2,"rb");
    if (file1==NULL || file2==NULL){
        printf("Erreur dans le chargement des fichiers\n");
        exit(0);
    }
	fread(&n, sizeof(int),1,file1);
	fread(&n, sizeof(int),1,file2);
	
 	for (int i = 0; i < n; i++) {
        donnee* d=Malloc(donnee);
        fread(d->lg,50*sizeof(char),1,file1);
        fread(d->pw,50*sizeof(char),1,file2);
		if(!strcmp(d->lg,lg)&& !strcmp(d->pw,pw))
			return 1;
    }
    
	fclose(file2);
	fclose(file1);
	return 0;
   
}







