#include<stdio.h>
#include<stdlib.h> // le programme s'arrete quand on entre 0 
#include<string.h>
#include<time.h> 
#include<windows.h>

	void copyright()  // la fonction du copyright 
		{
		
			char t[100]=" \t Copyright © 2018/2019 SMI3 \n \t by Adnane Drief \n "  ; 
			int tmp,j=0,i;
	
			while(j<50) 
				{
				system("cls");
				tmp=t[strlen(t)-1];
				for(i=strlen(t)-1;i>0;i--)
						{
							t[i]=t[i-1];
						}
				t[0]=tmp;
				puts(t); 
				j++;
				Sleep(200); // le Sleep pour augmenter la vitesse de l affichage 					
				}		
		}	

	void loading() // la fonction de loading 
			{
				int i;
				 for(i=0;i<100;i++)
			      		{
			      		printf("Loading.....%d%%",i);
						Sleep(150);
						system("cls");
					 	 }	
				for(i=0;i<10;i++)
				{
						printf("C est parti !! \n "); 	 
						Sleep(100);
						system("cls");	
				}
			}



	void  time1() // la fonction d'affichage de temps 
		{
			
				    char time[10];
				    char date[10];
				 		 FILE* fichier=NULL; // déclaration de pointeur vers fichiers
			 		  	 fichier=fopen("resultat.txt","a"); // l overture du fichier texte
				 
				    _strtime(time);
				    printf("Time: %s\n",time); // min-hh-ss
				fprintf(fichier,"Time: %s\n",time); // resultat dans le fichier 
				    _strdate(date);                          
				    printf("Date: %s\n",date); // dd-mm-yy
				fprintf(fichier,"Date: %s\n",date); // resultat dans le fichier 
				
		} 

	struct article
	{
		float p; // pour les prix 
		int n; // pour la quantité
		char  nom[30]; // pour les noms des articles
	};
	
	
	void ticket(struct article A[],int n ,int m) // la fonction de ticket (listing)
	{
			int i;
			  FILE* fichier=NULL; // déclaration de pointeur vers fichiers
	 		  fichier=fopen("resultat.txt","a"); // l overture du fichier texte
			printf("*******************************\n bonjour \n votre ticket : \n"); // resultat à l ecran 
		fputs("*********************************\n bonjour \n votre ticket : \n",fichier); // resultat dans le fichier 
			printf("Numero:\t \t nom:\t quantite:   prix:\n"); // resultat à l ecran
		fputs("Numero:\t \t nom:\t quantite:   prix:\n",fichier); // resultat dans le fichier 
			for(i=n-1;i<m-1;i++)
			{
				printf("Article\t[ %d ]\t[ %s ]\t[ %d ]\t[ %2.f ]\n",i+1,A[i].nom,A[i].n,A[i].p*A[i].n); // resultat à l ecran
			fprintf(fichier,"Article\t[ %d ]\t[ %s ]\t[ %d ]\t[ %2.f ]\n",i+1,A[i].nom,A[i].n,A[i].p*A[i].n); // resultat dans le fichier 
				
			}
			printf("****************************\n\n"); // resultat à l ecran
		fputs("****************************\n\n",fichier); // resultat dans le fichier 
			time1(); // appel a la fonction de temps de système
			printf("****************************\n Merci pour votre visite \n Au revoir \n");  // resultat à l ecran
		fputs("****************************\n Merci pour votre visite \n Au revoir \n",fichier);  // resultat dans le fichier 
	 
	}
	

		int main() // programme principal
		{
		       int N,i,n,m;
			   float S,M;
 			   struct article A[1000];
 			   FILE* fichier=NULL; // déclaration de pointeur vers fichiers
			   S=0;
			   i=-1;	
			   copyright();
			   copyright();
			   loading();
			   fichier=fopen("resultat.txt","w"); // l overture du fichier texte
			   printf("****************************\n");
			fputs("****************************\n",fichier);  // resultat dans le fichier 
			   printf("	Logiciel EPC version V5 \n \t Copyright © 2018/2019 SMI3 \n \t by Adnane Drief \n");
			fputs("	Logiciel EPC version V5 \n \t Copyright © 2018/2019 SMI3 \n \t by Adnane Drief \n",fichier);// resultat dans le fichier 
			   printf("****************************\n\n");
			fputs("****************************\n\n",fichier);// resultat dans le fichier 
			   printf("\t Bonjour \n ");
			fputs("\t Bonjour \n ",fichier);// resultat dans le fichier 
			   printf("****************************\n\n");
			fputs("****************************\n\n",fichier);// resultat dans le fichier 
			   do
			   {
			   		i++;
			   		printf(" Donner le nom de l article %d : ",i+1);
			   		scanf("%s",A[i].nom);
			   		printf(" Donner le prix de l article %d et la quantite :",i+1);
			   		scanf("%f%d",&A[i].p,&A[i].n);
			   		S=S+A[i].p;
			
			   }
			   while(A[i].p);
			   N=i;
			   if(N) M=S/N; else M=0;
			   printf("\n la somme des prix : %.2f\n",S); // resultat à l ecran
			fprintf(fichier,"\n la somme des prix : %.2f \n",S); // resultat dans le fichier 
			   printf("Le nombre d articles : %d \n",N); // resultat à l ecran
			fprintf(fichier,"Le nombre d articles : %d \n",N); // resultat dans le fichier
			   printf("La moyenne des prix : %2.f\n",M); // resultat à l ecran
			fprintf(fichier,"La moyenne des prix : %2.f\n",M); // resultat dans le fichier
			   printf("La liste des prix :\n"); // resultat 
			   printf("\n Voulez vous un listing oui:1 non:0 ");
			   scanf("%d",&i);
			   if(i)
			   		{
			   			printf(" Donner numero de debut et de fin : ");
			   			scanf("%d%d",&n,&m);
			   			ticket(A,n,m);
			   			
					   }
				system("pause");
				fclose(fichier); // fermeture du fichier 
		 	return(0);
			 			   
		}


