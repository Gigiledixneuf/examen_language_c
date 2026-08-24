#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include  "../include/basic_operations.h"

#define CLEAR_SCREEN "\033[2J\033[H"
#define CLEAR_LINE "\033[K"
#define HIGHLIGHT "\033[7m" // Reverse video (highlight)
#define RESET "\033[0m"     // Reset attributes

#define MAX_OPERATION  15
#define MIN_OPERATION  1
#define KEY_UP 80
#define KEY_DOWN 72
#define KEY_ESC 27
#define KEY_ENTER 13
bool isinitialExecution = true;


struct Operator
{
    bool isBasic;
    bool isTrigo;
    bool isUnary;
    int position;
};


//cette fonction affiche la position de la souris
void printArrow(int optionPosition, int arrowPosition){
    if (optionPosition == arrowPosition)
    {
        printf("%s-->> ",HIGHLIGHT);
    }else{
        printf("%s   ",RESET);
    }
}

// affche le titre de l'application
void showTitle(){
    printf("%sCLI Scientific Calculator \n",RESET);
}

int getNewArrowPosition(int arowPos, int keyP){
if (keyP == KEY_UP && arowPos!= MAX_OPERATION)
{
arowPos++;
}
else if(keyP == KEY_DOWN && arowPos!= MIN_OPERATION)
arowPos--;

return arowPos;
}

// affiche le menu du choix des operations
void showOperationsMenu(int actualPosition){
     printf("%sVeuillez choisir l'operation a effectuer \n",RESET);
printArrow(1,actualPosition);
printf("Addition \n");

printArrow(2,actualPosition);
printf("Soustraction \n");

printArrow(3,actualPosition);
printf("Multiplication \n");

printArrow(4,actualPosition);
printf("Division \n");

printArrow(5,actualPosition);
printf("Sin \n");

printArrow(6,actualPosition);
printf("Cos \n");

printArrow(7,actualPosition);
printf("Tan \n");

printArrow(8,actualPosition);
printf("Exp \n");
printArrow(9,actualPosition);
printf("Log  base 10\n");

printArrow(10,actualPosition);
printf("Ln \n");

printArrow(11,actualPosition);
printf("Log base quelconque \n");

printArrow(12,actualPosition);
printf("Puissance \n");
printArrow(13,actualPosition);
printf("Factorielle \n");

printArrow(14,actualPosition);
printf("Racine carre \n");

printArrow(15,actualPosition);
printf("Racine nieme \n");
}

//interromp la ligne de commande si l'utilisateur entre esc au clavier
void interrupt(int k){
if(k == 27){
    exit(0);
    printf("Au revoir");
    printf("%s                  ",CLEAR_SCREEN);
}
}



//prend en parametre la position de l'operateur choisi par l'utilisateur et renvoi la structure associé à cette operateur.
struct Operator defineOperator(int p){
    struct Operator o;
    bool isBasic=true;
    bool isTrigo=false;
    bool isUnary=false;
    int operatorPosition;
    switch (p)
{
case 1: 
    operatorPosition = 1;
    break;
case 2: 
     operatorPosition = 2;
    break;
case 3: 
     operatorPosition = 3;
    break;
case 4:
     operatorPosition = 4;
    break;
case 5: 
    isBasic=false;
    isUnary=true;
    isTrigo=true;
     operatorPosition = 5;
    break;
case 6: 
    isBasic=false;
    isUnary=true;
    isTrigo=true;
     operatorPosition = 6;
    break;
case 7: 
    isBasic=false;
    isUnary=true;
    isTrigo=true;
     operatorPosition = 7;
    break;
case 8: 
    isBasic=false;
    isUnary=true;
     operatorPosition = 8;
    break;
case 9: 
    isBasic=false;
    isUnary=true;
     operatorPosition = 9;
    break;
case 10: 
    isBasic=false;
    isUnary=true;
     operatorPosition = 10;
    break;
case 11: 
    isBasic=false;
     operatorPosition = 11;
    break;
case 12: 
    isBasic=false;
     operatorPosition = 12;
    break;
case 13: 
    isBasic=false;
    isUnary=true;
     operatorPosition = 13;
    break;
case 14: 
    isBasic=false;
    isUnary=true;
     operatorPosition = 14;
    break;
case 15: 
    isBasic=false;
     operatorPosition = 15;
    break;
default:
    break;
}  

 o.position=operatorPosition;
 o.isBasic=isBasic;
 o.isTrigo=isTrigo;
 o.isUnary=isUnary;

 return o;
}

//une fonction qui prend en parametre la structure et un booleen indiquant si c'est la premiere exécution ou pas choisi par l'utilisateur et effectue le flux des calculs
void askUserOperatorParams(const struct Operator *opr){
        double nbr1;
        double nbr2;
        double resultat;
        bool loopFlag = true;
        int keyPressed;
    
        while(loopFlag){
            if(opr->isBasic){
                //reste d'opération de base  ici(addition et soustraction)
            if(opr->position == 3){
                if (isinitialExecution)
                {
                     printf("Veuillez entrer deux nombres a multiplier:\n ");
                    printf("premier nombre 1: ");
                    scanf("%lf",&nbr1);
                    printf("deuxieme nombre 2: ");
                    scanf("%lf",&nbr2);
                    resultat = multiplier(nbr1,nbr2);
                }else{
                    printf("Veuillez entrez le nombre suivant: ");
                scanf("%lf",&nbr1);
                resultat = multiplier(resultat,nbr1);
                }
                }
                else if(opr->position == 4){
                    int success;
                    if (isinitialExecution)
                    {
                        printf("Veuillez entrer deux nombres a diviser:\n ");
                    printf("premier nombre 1: ");
                    scanf("%lf",&nbr1);
                    printf("deuxieme nombre 2: ");
                    scanf("%lf",&nbr2);
                   success = diviser(nbr1,nbr2,&resultat);
                    }else {
                     printf("Veuillez entrez le nombre suivant: ");
                scanf("%lf",&nbr2);
                success = diviser(resultat,nbr2,&resultat);   
                    }
                while (!success)
                    {
                        int num;
                        if (isinitialExecution)
                        {
                            num =nbr1;
                        }else{
                            num = resultat;
                        }
                        
                        printf("Erreur : division par zero\n");
                        printf("Veuillez entrer un nombre different de zero: ");
                        scanf("%lf",&nbr2);
                        success=diviser(num,nbr2,&resultat);
                    }
                    
                }
            
        }
        printf("le resultat est: %lf\n",resultat);
        printf("Appuyez sur ENTER pour enchainer avec la meme operation \n C pour enchainer avec une nouvelle operation ; ESC pour quitter le programme \n R pour revenir au menu de choix d'operation\n");
        keyPressed = getch();
        if(keyPressed == 13){
            isinitialExecution = false;
        }

        //sinon si c'es esc, on quitte le programm.
        //sinon si c'est R, on revient aux choix d'opération
        //sinon si c'est Shift on met initialisation à false et on refait les calculs
        }
        
}

// ecoute la saisi au clavier de l'utilisateur
void handleUserKeywordInput(){
    int position = 1;
    int keyPressed = 0;

while (keyPressed != KEY_ENTER && keyPressed != KEY_ESC)
{
    system("cls");
    showOperationsMenu(position);


keyPressed = getch();


    position = getNewArrowPosition(position,keyPressed);

}
interrupt(keyPressed);
struct Operator selectedOperator = defineOperator(position);
askUserOperatorParams(&selectedOperator);

}