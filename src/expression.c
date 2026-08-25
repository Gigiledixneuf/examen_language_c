#include "../include/expression.h"
#include "../include/basic_operations.h"

#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>

/*
 * ============================================================
 * MODULE : EVALUATION DES EXPRESSIONS
 * ============================================================
 *
 * Ce module permet d'analyser et d'évaluer une expression
 * mathématique écrite sous forme de texte.
 *
 * Exemple :
 *
 *     "2 + 3 * 4"
 *
 * Le résultat obtenu est :
 *
 *     14
 *
 * L'analyseur respecte les priorités mathématiques :
 *
 *     1. Parenthèses
 *     2. Multiplication et division
 *     3. Addition et soustraction
 *
 * Les opérations de base sont réalisées par les fonctions
 * du fichier basic_operations.c.
 */


/*
 * Position actuelle dans l'expression.
 *
 * L'analyseur avance caractère par caractère dans la chaîne.
 */
static const char *position;


/*
 * Fonctions internes utilisées par l'analyseur.
 */
static int analyser_expression_interne(double *resultat);
static int analyser_terme(double *resultat);
static int analyser_facteur(double *resultat);


/*
 * ============================================================
 * IGNORER LES ESPACES
 * ============================================================
 *
 * Permet d'accepter des expressions comme :
 *     2+3,  2 + 3 ou 2     +     3
 * Les espaces sont simplement ignorés.
 */
static void ignorer_espaces(void)
{
    while (isspace((unsigned char)*position))
    {
        position++;
    }
}


/*
 * ============================================================
 * LIRE UN NOMBRE
 * ============================================================
 *
 * Lit un nombre entier ou décimal à partir de la position
 * courante.
 *
 * Exemples acceptés :
 *
 *     5
 *     12
 *     2.5
 *     0.25
 *
 * La fonction strtod() permet de convertir le texte en double.
 *
 * Retour :
 *
 *     1 -> nombre correctement lu
 *     0 -> aucun nombre trouvé
 */
static int lire_nombre(double *resultat)
{
    char *fin;

    ignorer_espaces();

    *resultat = strtod(position, &fin);

    /*
     * Si la position n'a pas changé, aucun nombre n'a été lu.
     */
    if (position == fin)
    {
        return 0;
    }

    /*
     * On avance après le nombre.
     */
    position = fin;

    return 1;
}


/*
 * ============================================================
 * ANALYSER UN FACTEUR
 * ============================================================
 *
 * Un facteur représente la plus petite unité d'une expression.
 *
 * Il peut être :
 *
 *     5
 *     2.5
 *     -5
 *     +5
 *
 * ou une expression entre parenthèses :
 *
 *     (2 + 3)
 *     -(2 * 3)
 *
 * Cette fonction permet également de gérer les parenthèses
 * imbriquées.
 */
static int analyser_facteur(double *resultat)
{
    int signe = 1;

    ignorer_espaces();


    /*
     * --------------------------------------------------------
     * SIGNE POSITIF
     * --------------------------------------------------------
     *
     * Exemple :
     *
     *     +5
     *     +(2 * 3)
     */
    if (*position == '+')
    {
        position++;
        ignorer_espaces();
    }


    /*
     * --------------------------------------------------------
     * SIGNE NEGATIF
     * --------------------------------------------------------
     *
     * Exemple :
     *
     *     -5
     *     -(2 * 3)
     */
    else if (*position == '-')
    {
        signe = -1;
        position++;
        ignorer_espaces();
    }


    /*
     * --------------------------------------------------------
     * PARENTHESES
     * --------------------------------------------------------
     *
     * Exemple :
     *
     *     (2 + 3)
     *
     * Tout le contenu des parenthèses est analysé
     * récursivement.
     */
    if (*position == '(')
    {
        /*
         * Ignore '('.
         */
        position++;

        /*
         * Analyse ce qui se trouve à l'intérieur.
         *
         * Cela permet notamment de gérer :
         *
         *     (2 + 3)
         *     (2 * (3 + 4))
         *     ((2 + 3) * 4)
         */
        if (!analyser_expression_interne(resultat))
        {
            return 0;
        }

        ignorer_espaces();

        /*
         * Une parenthèse ouvrante doit obligatoirement
         * avoir une parenthèse fermante.
         */
        if (*position != ')')
        {
            return 0;
        }

        /*
         * Ignore ')'.
         */
        position++;

        /*
         * Applique le signe éventuel.
         *
         * Exemple :
         *
         *     -(2 + 3)
         *
         * donne :
         *
         *     -5
         */
        *resultat = signe * (*resultat);

        return 1;
    }


    /*
     * --------------------------------------------------------
     * NOMBRE
     * --------------------------------------------------------
     */
    if (!lire_nombre(resultat))
    {
        return 0;
    }

    /*
     * Applique le signe éventuel au nombre.
     */
    *resultat = signe * (*resultat);

    return 1;
}


/*
 * ============================================================
 * ANALYSER UN TERME
 * ============================================================
 *
 * Un terme contient les opérations prioritaires :
 *
 *     multiplication (*)
 *     division (/)
 *
 * Exemple :
 *
 *     2 * 3 / 2
 *
 * est calculé de gauche à droite :
 *
 *     2 * 3 = 6
 *     6 / 2 = 3
 *
 * Cette fonction est appelée par analyser_expression_interne().
 *
 * Cela permet de donner à * et / une priorité supérieure
 * à + et -.
 */
static int analyser_terme(double *resultat)
{
    double valeur_droite;

    /*
     * Un terme doit commencer par un facteur.
     */
    if (!analyser_facteur(resultat))
    {
        return 0;
    }


    /*
     * Continue tant qu'une multiplication ou une division
     * est rencontrée.
     */
    while (1)
    {
        ignorer_espaces();


        /*
         * ----------------------------------------------------
         * MULTIPLICATION
         * ----------------------------------------------------
         */
        if (*position == '*')
        {
            position++;

            /*
             * Il faut obligatoirement une valeur après '*'.
             */
            if (!analyser_facteur(&valeur_droite))
            {
                return 0;
            }

            /*
             * Utilise la fonction du module des opérations
             * de base.
             */
            *resultat = multiplier(*resultat, valeur_droite);
        }


        /*
         * ----------------------------------------------------
         * DIVISION
         * ----------------------------------------------------
         */
        else if (*position == '/')
        {
            position++;

            /*
             * Il faut obligatoirement une valeur après '/'.
             */
            if (!analyser_facteur(&valeur_droite))
            {
                return 0;
            }

            /*
             * La fonction diviser() vérifie notamment
             * la division par zéro.
             */
            if (!diviser(*resultat, valeur_droite, resultat))
            {
                return 0;
            }
        }


        /*
         * Aucun * ou / :
         *
         * le terme est terminé.
         */
        else
        {
            break;
        }
    }

    return 1;
}


/*
 * ============================================================
 * ANALYSER UNE EXPRESSION
 * ============================================================
 *
 * C'est le niveau supérieur de l'analyseur.
 *
 * Une expression peut contenir :
 *
 *     terme
 *     terme + terme
 *     terme - terme
 *
 * Exemple :
 *
 *     2 + 3 * 4
 *
 * L'analyse se fait ainsi :
 *
 *     2
 *     +
 *     3 * 4
 *
 * Le terme "3 * 4" est calculé en premier.
 *
 * Résultat :
 *
 *     2 + 12 = 14
 *
 * Cette organisation permet donc de respecter la priorité
 * entre les opérations.
 */
static int analyser_expression_interne(double *resultat)
{
    double valeur_droite;

    /*
     * Une expression commence obligatoirement par un terme.
     */
    if (!analyser_terme(resultat))
    {
        return 0;
    }


    /*
     * Recherche ensuite les opérations + et -.
     */
    while (1)
    {
        ignorer_espaces();


        /*
         * ----------------------------------------------------
         * ADDITION
         * ----------------------------------------------------
         */
        if (*position == '+')
        {
            position++;

            /*
             * Il faut obligatoirement un terme après '+'.
             */
            if (!analyser_terme(&valeur_droite))
            {
                return 0;
            }

            /*
             * Utilise la fonction additionner() de Benel/Isaac.
             */
            *resultat = additionner(*resultat, valeur_droite);
        }


        /*
         * ----------------------------------------------------
         * SOUSTRACTION
         * ----------------------------------------------------
         */
        else if (*position == '-')
        {
            position++;

            /*
             * Il faut obligatoirement un terme après '-'.
             */
            if (!analyser_terme(&valeur_droite))
            {
                return 0;
            }

            /*
             * Utilise la fonction soustraire() de Benel/Isaac.
             */
            *resultat = soustraire(*resultat, valeur_droite);
        }


        /*
         * Aucun + ou - :
         *
         * l'expression courante est terminée.
         */
        else
        {
            break;
        }
    }

    return 1;
}


/*
 * ============================================================
 * FONCTION PUBLIQUE
 * ============================================================
 *
 * Point d'entrée du module.
 *
 * Cette fonction reçoit une expression sous forme de chaîne
 * et calcule son résultat.
 *
 * Exemples :
 *
 *     evaluer_expression("2 + 3", &resultat);
 *
 *     evaluer_expression("2 + 3 * 4", &resultat);
 *
 *     evaluer_expression("(2 + 3) * 4", &resultat);
 *
 * Retour :
 *
 *     1 -> expression valide
 *     0 -> expression invalide
 */
int evaluer_expression(const char *expression, double *resultat)
{
    /*
     * Vérifie les paramètres reçus.
     */
    if (expression == NULL || resultat == NULL)
    {
        return 0;
    }

    /*
     * Commence l'analyse au début de la chaîne.
     */
    position = expression;


    /*
     * Analyse l'expression complète.
     */
    if (!analyser_expression_interne(resultat))
    {
        return 0;
    }


    /*
     * Ignore les espaces qui peuvent rester à la fin.
     */
    ignorer_espaces();


    /*
     * Tous les caractères doivent avoir été analysés.
     *
     * Exemple :
     *
     *     2 + 3)
     *
     * Le calcul donne 5 mais ')' reste dans la chaîne.
     *
     * L'expression est donc invalide.
     */
    if (*position != '\0')
    {
        return 0;
    }

    return 1;
}