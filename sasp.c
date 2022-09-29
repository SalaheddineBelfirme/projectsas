#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include <stdlib.h>
int size=0,i,j,coder=1;
int  sizev;
typedef struct{//
     int codep;
    int  jour ;
    char mois[4];
    int anee;
    int quantiteV;
     float Ptcc;
}date;
typedef struct{
    int code;
    char nom[25];
    int quantite;
    float prix;  
    date d;

}produit;

produit Ajouter_produit();//declration function qui ajouter un produit 
void Ajouter_Pproduits(int n,int size,produit p[size]);//declration function qui ajouter pulsieur  produits
void listerPprix(int size,produit p[size]);//declration function qui lister par prix
void listerPnom(int size,produit p[size]);//declration function qui lister par nom
void Acheter_produit(int code,int sizev ,int q,int size,date pv[] ,produit p[size]); //declration function qui acheter un produit
void Rechercher_produit(int choix ,int size,produit p[]); //declration function qui rechercher pour un produit (par : code ou quantite)
void Etat_stock(int size,produit p[]);//declration function qui afficher les produits qui ont des quantites inferieur de 3
void Alimenter_stock(int code ,int q ,int size,produit p[]);//declration function qui ajouter une quantite a la quantite originale du produit
void Supprimer_produit(int code ,int size,produit p[]);//declration function qui supprimer un produit
void Statistique_vente(int sizev,date pv[]);//declration function qui afficher les statistiques de vente 
void affchhge(int size,produit p[size]);//declration function qui afficher les produits
int main(){
    produit tableP[1000]={{1,"1",1,1}};
    date tableV[1000];
    int choix ,n,code ,q;
    
    do{ 
        printf("\n\t\t\t\t\t\t\t\t\t \"Bienvenue Dans Votre Pharmacie\" \n");
        printf("\n________________________________________________________________________________________________________________________________________________________________________________________________________\n\n");
        printf("\n\t\t\t\t\t - \t\t1==> Ajouter un nouveau produit     -  \t\t   2==> Ajouter plusieurs nouveaux produits\n\n \t\t\t\t\t - \t\t3==> Lister tous les produits       - \t \t   4==> Acheter produit\n\n");
        printf("\t\t\t\t\t - \t\t15==> Rechercher les produits       -    \t 6==> Etat du stock:\n\n  \t\t\t\t\t - \t\t7==> Alimenter le stock:            -    \t 8==> Supprimer les produits\n\n \t\t\t\t\t\t\t\t - \t\t9==> Statistique de vente: ");
        printf("\n_________________________________________________________________________________________________________________________________________________________________________________________________________\n\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:system("cls");
            tableP[size]=Ajouter_produit();
            system("cls");
            size++;
            coder++;
            affchhge(size,tableP);
            break;
        case 2:
            printf("entrez le nombre de produits que vous voulez ajouter :");
            scanf("%d",&n);
            Ajouter_Pproduits(n,size,tableP);
            size=size+n;
               system("cls");
            affchhge(size,tableP);
            break;
        case 3:
            do
            {
                printf("\n 1==>lister tous les produits selon lordre alphabetique croissant du nom\n 2==> lister tous les produits selon lordre decroissant du prix");
                scanf("%d",&choix);
                
            } while (choix!=1 && choix!=2);
            if(choix==2){
                listerPprix(size,tableP);

            } 
            else{
                listerPnom(size,tableP);
                }     
            break;
        case 4 :
            printf("\nenter code :");
            scanf("%d",&code);
            printf("\nenter quntite :");
            scanf("%d",&q);
            Acheter_produit(code,sizev,q,size,tableV,tableP);
            sizev++;
            break;   
        case 5 :
            do {
                printf("\n 1==>par code \n 2==> par quantite  :");
                scanf("%d",&n);
            }while(n!=1 && n!=2);
            Rechercher_produit( n,size,tableP);
            break;
        case 6:Etat_stock(size,tableP);break;
        
        case 7:
            printf("\nenter code :");
            scanf("%d",&code);
            printf("\nenter quntite :");
            scanf("%d",&q);
            Alimenter_stock(code,q,size,tableP);
            break;
        case 8:
            printf("\nenter code :");
            scanf("%d",&code);
            Supprimer_produit(code,size,tableP);
            size--;
            break;
        case 9 :
            Statistique_vente( sizev ,tableV);
            break;
         case 0: break;
        default:
            printf("invalid choix");
            break;
        }
        
    }while(choix!=0);
    return 0;
}
produit Ajouter_produit(){//creation function qui ajouter un produit 
    produit p;
    // printf("code :");
    // scanf("%d",&i);
    p.code=coder;
    printf("Nome :");
    scanf("%s",p.nom);
    printf("quantite :");
    scanf("%d",&p.quantite);
    printf("Prix :");
    scanf("%f",&p.prix);
     coder++;
    return p;
}
void Ajouter_Pproduits(int n,int size,produit p[size]){ //creation function qui ajouter pulsieur  produits 
    for(i=size;i<size+n;i++){
        p[i]=Ajouter_produit();//utilisation function qui acheter un produit
    }
}
void listerPprix(int size,produit p[size]){//trier par prix utilisant la methode de tri par selection
    int max;
    produit tmp;
    for(i=0;i<size-1;i++){
        max=i;
        for (j=i+1 ;j<size; j++) {
           if(p[j].prix>p[max].prix){
            max=j;
           }         
        }
         if(max!=i){
            tmp=p[i];
            p[i]=p[max];
            p[max]=tmp;
           }
    }
      system("cls");
    printf("tableau trier par nom\n");
    affchhge(size,p);
}
void affchhge(int size,produit p[]){
        for(i=0;i<size;i++){
             printf("\n code :%d  nome  :%s  quantite :%d  prix:%.2f DH ",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
         }
}
void listerPnom(int size,produit p[size]){//trier par nom utilisant la methode de tri par selection
    int max;
    produit tmp;
    for(i=0;i<size-1;i++){
        max=i;
        for (j=i+1 ;j<size; j++) {
           if(strcmp(p[j].nom,p[max].nom)==-1){
            max=j;
           } 
        }
        if(max!=i){
            tmp=p[i];
            p[i]=p[max];
            p[max]=tmp;
           }
    }
      system("cls");
    printf("tableau trier par prix\n");
    affchhge(size,p);
}
void Acheter_produit(int code,int sizev ,int q,int size,date pv[] ,produit p[size]){
    for (i=0;i<size; i++){
        if (p[i].code==code)
        {
            if (p[i].quantite>=q)
            {       
                p[i].quantite=p[i].quantite-q;
                sscanf(__DATE__, "%s %d %d", p[i].d.mois, &p[i].d.jour, &p[i].d.anee);           
                pv[sizev].codep=p[i].code;//remplissage produit achater
                pv[sizev].anee=p[i].d.anee;
                strcpy( pv[sizev].mois,p[i].d.mois);//utilisation function strcpy pour strings
                pv[sizev].quantiteV=p[i].d.quantiteV+q;
                pv[sizev].jour=p[i].d.jour;
                pv[sizev].Ptcc=p[i].prix+(p[i].prix * 0.15);
                printf("\ncodep :%d  quantitev :%d  jour: %d  mois : %s anee : %d pttc :%.2f  ",pv[sizev].codep,pv[sizev].quantiteV,pv[sizev].jour,pv[sizev].mois,pv[sizev].anee,pv[sizev].Ptcc); 
                printf("\nAcheter avec succe... "); 
            }
            else{
                printf("\netat de stock : %d",p[i].quantite);
            }      
        }   
    }
}
void Rechercher_produit(int choix ,int size,produit p[]){// creation d'une fonction qui rechercher un produit
    int c,b=0;
    if(choix==1){
         printf("enter code de produit");
         scanf("%d",&c);
          for(i=0;i<size;i++){
             if(p[i].code==c){
                printf("\ncode :%d  nome  :%s  quantite :%d  prix:%2f DH ",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
                b = 1;
             break;
         }    
        }
         if (b==0){
            printf("ce produit n'existe pas\n");
         }
    }
     else{
         printf("enter quantite de produit");
         scanf("%d",&c);
          for(i=0;i<size;i++){
             if(p[i].quantite==c){
             printf("\ncode :%d  nome  :%s  quantite :%d  prix:%2f DH ",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
             b=1;
             break;
            }   
     }
     if (b==0){
            printf("ce produit n'existe pas\n");
         }
    }
}
void Etat_stock(int size,produit p[]){
    int n=0;
     for(i=0;i<size;i++){
             if(p[i].quantite<3){
                n=1;
             printf("\ncode :%d  nome  :%s  quantite :%d  prix:%2f DH ",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
         }
    }
      if(n==0){printf("aucun produit n'a une quantite moin de 3 \n");}  
}
void Alimenter_stock(int code ,int q ,int size,produit p[]){ 
    for (i=0;i<size; i++){
        if (p[i].code==code)
        {       
                p[i].quantite=p[i].quantite+q;
                printf("la quantite a ete ajoutee avec succee...");                    
        }
        
    }
}
void Supprimer_produit(int code ,int size,produit p[]){
    int n,b;
    for(i=0;i<size;i++){
             if(p[i].code==code){
                n=i;
                b=1;
                break;
             }}
    if (b==1){
         for (i=n;i<size-1;i++){
        p[i]=p[i+1];
    }
    }
    else{
        printf("ce produit n'existe pas\n");
    }
  
}
void Statistique_vente(int sv,date pv[]){
    float sum=0,con=0 ;
    date tmp;
    int mx,mn;
    for ( i = 0; i< sv-1; i++)
    { 
        mx=i;
        for(j=i+1;j<sv;j++){
            if((pv[j].Ptcc * pv[i].quantiteV )>((pv[mx].Ptcc * pv[mx].quantiteV ))){
                mx=j;               
            }
        } 
           if (mx!=i){
            tmp=pv[i];
            pv[i]=pv[mx];
            pv[mx]=tmp;   
        } 
    }   
    printf("\n max est %.2f min est : %.2f ",pv[0].Ptcc * pv[0].quantiteV ,pv[sv-1].Ptcc * pv[sv-1].quantiteV);
    for ( i = 0; i< sv; i++){
        sum+=pv[i].Ptcc*pv[i].quantiteV;
        con++;
    }
    printf("la somme est : %.2f la moyenne est %.2f:",sum,sum/con);
}


