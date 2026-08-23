//elyséé & & manassé & daniella
// Fonctions trigonometriques 
//sinus
double sinus(double valeur)
{
    return sin(valeur);
}
//cosinus
double cosinus(double valeur)
{
    return cos(valeur);
}
//tangente
double tangente(double valeur)
{
    if (cos(valeur) == 0)
        return NAN;

    return tan(valeur);
}
//prennent en parametre la valeur et l'unité et doit retourner la valeur de cosinus, du sinus ou de la tangeante

//Fonctions logarithmiques (log10, ln) 
double logarithme10(double a)
{
    if (a <= 0)
        return NAN;

    return log10(a);
}
//Logarithme népérien
double logarithme_neperien(double a)
{
    if (a <= 0)
        return NAN;

    return log(a);
}
//prennent en parametre une valeur a et retourne log10(a) ou ln(a)

//Fonction exponentielle (exp)
double exponentielle(double a)
{
    return exp(a);
}
//prend en parametre une valeur et retourne leurs exp(a)

//Racine carree (sqrt) 
double racine_carree(double a)
{
    if (a < 0)
        return NAN;

    return sqrt(a);
}
//prennent en parametre une valeur a et retourne racine_carré(a)

//Puissance (pow)
double puissance(double a, double b)
{
    if (a == 0 && b <= 0)
        return NAN;

    if (a < 0 && floor(b) != b)
        return NAN;

    return pow(a, b);
}
//prend en parametre deux nombre, une base a et l'exposant b et retourne a^b

//Factorielle
long long factorielle(int n)
{
    long long resultat = 1;

    if (n < 0 || n > 20)
        return -1;

    for (int i = 1; i <= n; i++)
        resultat = resultat * i;

    return resultat;
}
//prend en parametre

//Fonctions logarithmiques à base qlq
double logarithme_base(double b, double a)
{
    if (b <= 0 || b == 1 || a <= 0)
        return NAN;

    return log(a) / log(b);
}
//prend en parametre, deux nombre la base b et la valeur a et effectue logb(a)

//Racine nième
double racine_nieme(int n, double a)
{
    if (n <= 0)
        return NAN;

    if (a < 0 && n % 2 == 0)
        return NAN;

    if (a < 0)
        return -pow(-a, 1.0 / n);

    return pow(a, 1.0 / n);
}

//prend en parametre deux nombre n et la valuer a et renvoi racine_nieme(a)

//chaque fonction doit etre testé individuellemnt, pour le cas particulier, renvoyez des exceptions

//total: 11 fonctions
