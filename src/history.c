#include "../include/history.h"

#include <stdio.h>

#define HISTORY_FILE "data/history.txt"


void saveTextHistory(const char *expression)
{
    FILE *file = fopen(HISTORY_FILE, "a");

    if (file == NULL)
    {
        printf("Erreur : impossible d'ouvrir l'historique.\n");
        return;
    }

    fprintf(file, "%s\n", expression);

    fclose(file);
}

void saveHistory(
    const char *expression,
    double result
)
{
    FILE *file = fopen(HISTORY_FILE, "a");

    if (file == NULL)
    {
        printf("Erreur : impossible d'ouvrir l'historique.\n");
        return;
    }

    fprintf(
        file,
        "%s = %.10g\n",
        expression,
        result
    );

    fclose(file);
}


void displayHistory(void)
{
    FILE *file = fopen(HISTORY_FILE, "r");

    if (file == NULL)
    {
        printf("\nAucun historique disponible.\n");
        return;
    }

    char line[256];

    printf("\n");
    printf("========== HISTORIQUE ==========\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    printf("================================\n");

    fclose(file);

    printf("\nAppuyez sur une touche pour revenir au menu...");
    getchar();
    getchar();
}