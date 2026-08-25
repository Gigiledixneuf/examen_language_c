#include <stdio.h>
#include <windows.h>
#include "../include/base_conversion.h"








int main()
{
    char result[100];

    if (convert_base(
        "FF",
        16,
        2,
        result,
        sizeof(result)
    ))
    {
        printf("Resultat : %s\n", result);
    }
    else
    {
        printf("Erreur de conversion\n");
    }

    
    return 0;
}

//amos & jonathan & juliette k
//implementation des l'historiques des calculs
//ajout de la possibilité de changement de base