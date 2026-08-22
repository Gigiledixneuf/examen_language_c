#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


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


// à implementer :: fonction defineOperator va prendre en parametre la position, va creer la structure de l'operateur choisis et va la renvoyer et va renvoyer un resultat qui sera la structure operateur avec valeur  (isBasic, isTrigo, isUnaire, flag) définie

void printArrow(int optionPosition, int arrowPosition){
    if (optionPosition == arrowPosition)
    {
        printf("%s-->> ",HIGHLIGHT);
    }else{
        printf("%s   ",RESET);
    }
}


void showMenu(){
    int position = 1;
    int keyPressed = 0;

while (keyPressed != KEY_ENTER && keyPressed != KEY_ESC)
{
    system("cls");
    printf("%sCLI Scientific Calculator \n",RESET);
    printf("%sVeuillez choisir l'operation a effectuer \n",RESET);
printArrow(1,position);
printf("Addition \n");

printArrow(2,position);
printf("Soustraction \n");

printArrow(3,position);
printf("Multiplication \n");

printArrow(4,position);
printf("Division \n");

printArrow(5,position);
printf("Sin \n");

printArrow(6,position);
printf("Cos \n");

printArrow(7,position);
printf("Tan \n");

printArrow(8,position);
printf("Exp \n");
printArrow(9,position);
printf("Log \n");

printArrow(10,position);
printf("Ln \n");

printArrow(11,position);
printf("Log a base quelconque \n");

printArrow(12,position);
printf("Puissance \n");
printArrow(13,position);
printf("Factorielle \n");

printArrow(14,position);
printf("Racine carre \n");

printArrow(15,position);
printf("Racine nieme \n");



keyPressed = getch();


if (keyPressed == KEY_UP && position != MAX_OPERATION)
{
position++;
}
else if (keyPressed == KEY_DOWN && position != MIN_OPERATION)
{
   position--;
}
else
{
    position = position;
}
}

if(keyPressed == 27){
    exit(0);
    printf("Au revoir");
    printf("%s                  ",CLEAR_SCREEN);
}else{
switch (position)
{
case 1: 
    printf("choix 1");
    break;
case 2: 
    printf("choix 2");
    break;
case 3: 
    printf("choix 3");
    break;
case 4: 
    printf("choix 4");
    break;
case 5: 
    printf("choix 5");
    break;
case 6: 
    printf("choix 6");
    break;
case 7: 
    printf("choix 7");
    break;
case 8: 
    printf("choix 8");
    break;
case 9: 
    printf("choix 9");
    break;
case 10: 
    printf("choix 10");
    break;
case 11: 
    printf("choix 11");
    break;
case 12: 
    printf("choix 12");
    break;
case 13: 
    printf("choix 12");
    break;
case 14: 
    printf("choix 12");
    break;
case 15: 
    printf("choix 12");
    break;
default:
    break;
}  
}
}