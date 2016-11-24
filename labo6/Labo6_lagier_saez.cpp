/*
 -----------------------------------------------------------------------------------
 Laboratoire : 6 - Chèque vaudois
 Fichier     : Labo6_lagier_saez.cpp
 Auteur(s)   : Elodie Lagier, Sebastien Saez
 Date        : 16 Novembre 2016

 But         : Le but de ce laboratoire est de créer une fonction qui reçoit en entrée
 *             un nombre réel au format double, et retourne une chaine de caractères 
 *             au format string contenant en vaudois le montant correspondant exprimé 
 *             en francs et centimes. Le français utilisé est celui utilisé dans le 
 *             canton de Vaud, donc septante, huitante et nonante pour 70, 80 et 90.

 Remarque(s) : La saisie utilisateur est vérifiée et renvoie un message d'erreur
 *             si la saise est fausse. On utilise ctrl+c pour terminer le programme.

 Compilateur : g++ 6.2.1 20160830
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// Constantes
const double BORNE_INFERIEURE = 0,
             BORNE_SUPERIEURE = 999999.99;
const int    MILLE = 1000,
             CENT = 100,
             DIX = 10;


/**
    \brief Traduit des nombres réels en prix exprimés en vaudois
    \param[in] MONTANT un réel compris entre 0 et 999999.99 CHF.
    \return une chaine de caractères indiquant en vaudois le prix
    en francs et centimes.
    \details Exemples:
    12.30  -> "douze francs et trente centimes"
    200.01 -> "deux cents francs et un centime"
    180    -> "cent huitante francs"
    1.80   -> "un franc et huitante centimes"
    0.20   -> "vingt centimes"
    0      -> "zéro franc"
    */
string montantEnVaudois(const double MONTANT);


/**
 Demande les valeurs à l'utilisateur et verifie la saisie
 
 @param VALMIN(entier) définit le nombre mimimum à entrer
 @param VALMAX(entier) définit le nombre maximum à entrer
 @param valeur(double) en référence qui sera la valeur à traiter
 @return la saisie correcte en double
 */
double saisieUtilisateur(const int VALMAX, const int VALMIN, double& valeur);

/**
 Retourne la partie des milliers d'un nombre
 
 @param NOMBRE reçoit le nombre dont on veut extraire les milliers
 @return la partie décimale d'un nombre en double constant
 */
int getMilliers (const double NOMBRE);

/**
 Retourne la partie des centaines d'un nombre
 
 @param NOMBRE reçoit le nombre dont on veut extraire les centaines
 @return la partie décimale d'un nombre en double constant
 */
int getCentaines (const double NOMBRE);


/**
 Retourne la partie décimale d'un nombre
 
 @param NOMBRE reçoit le nombre dont on veut extraire la partie décimale
 @return la partie décimale d'un nombre en double constant
 */
int getDecimales (const double NOMBRE);


/**
 Retourne une chaine de caractères en français quand elle reçoit un nombre allant
 * de 0 à 9 et de 11 à 16. Ce sont les bases du comptage et les cas particuliers.
 
 @param CHIFFREreçoit le nombre(int) entre 1 et 16, 10 exclu dont on veut récupérer sa 
 *      chaîne de caractères.
 @return la chaine de caractère du chiffre reçu en paramètre.
 */
string uniteToString(const int CHIFFRE);

/**
 Fonction qui traite un nombre et retourne sa chaine de caractère en dizaine
 
 @param NOMBREreçoit le nombre(int) encodé qui correspond à sa valeur en dizaine
 *      (voir details)
 @return la dizaine correspondant sous forme de string.
 \details
 * Exemple: s'il reçoit 1, il retourne dix. 2 => vingt et etc...
 */
string dizaineToString(const int NOMBRE);

/**
 Fonction principale qui écrit les accords de centaines ainsi que les mots de liaisons
 tels que "et" ainsi que le trait d'union
 *  
 @param BLOC reçoit le bloc de chiffre que l'on veut traiter
 @param MILLIERS reçoit un boolean pour savoir si c'est un millier qu'on traite ou pas,
 * nous avons dû l'introduire afin de ne pas faire l'accord des centaines lorsque
 * que c'est des centaines de milliers.
 @return la chaine de caractère traitée avec les mots de liaisons.
 */
string blocToString(const int BLOC, const bool MILLIERS);


int main()
{
    double d;
    cout << montantEnVaudois(saisieUtilisateur(BORNE_INFERIEURE, BORNE_SUPERIEURE,d))
         << endl;

   return EXIT_SUCCESS;
}

int getMilliers (const double NOMBRE)
{
   return (int)(NOMBRE / MILLE); // retourne le nombre de milliers
}


int getCentaines (const double NOMBRE)
{
   return ((int)NOMBRE) % MILLE; // retourne le nombre de centaines
}

int getDecimales (const double NOMBRE)
{
   return (int)round(NOMBRE * CENT) % CENT; // retourne la partie décimale
}

string uniteToString(const int CHIFFRE)
{
   switch(CHIFFRE)
   {
      case 0 : return ""; break;
      case 1 : return "un"; break;
      case 2 : return "deux"; break;
      case 3 : return "trois"; break;
      case 4 : return "quatre"; break;
      case 5 : return "cinq"; break;
      case 6 : return "six"; break;
      case 7 : return "sept"; break;
      case 8 : return "huit"; break;
      case 9 : return "neuf"; break;
      case 11 : return "onze"; break;
      case 12 : return "douze"; break;
      case 13 : return "treize"; break;
      case 14 : return "quatorze"; break;
      case 15 : return "quinze"; break;
      case 16 : return "seize"; break;  
      default: return "Erreur";
   }
}

string dizaineToString(const int NOMBRE)
{
   switch(NOMBRE)
   {
      case 0 : return ""; break;
      case 1 : return "dix"; break;
      case 2 : return "vingt"; break;
      case 3 : return "trente"; break;
      case 4 : return "quarante"; break;
      case 5 : return "cinquante"; break;
      case 6 : return "soixante"; break;
      case 7 : return "septante"; break;
      case 8 : return "huitante"; break;
      case 9 : return "nonante"; break;
      default: return "Erreur";
   }
}


string blocToString(const int BLOC, const bool MILLIERS)
{
   string resultat = "";
   int reste = BLOC % CENT;
   int centaine = BLOC / CENT;

   // s'il n'y a qu'une centaine, on écrit cent 
   if(centaine == 1)
   {
      resultat += "cent";
   }
   // sinon si la centaines est plus petite que 10 et qu'il y'a pas de reste et qu'on
   // est pas dans les milliers, on accorde cents
   else if(centaine && !reste && centaine < 10 && !MILLIERS)
   {
      resultat += uniteToString(centaine) + " cents";    
   }
   // sinon si les on est dans les milliers OU qu'on a une centaine avec un reste,
   // on écrit cent sans accorder
   else if((MILLIERS && centaine) || (centaine && reste))
   {
      resultat += uniteToString(centaine) + " cent"; 
   }
   // s'il existe un reste et qu'il reste des centaines, on met un espace en prévision
   // d'écrire la suite.
   if((reste) && (centaine))
   {
      resultat += " ";
   }
   // Si le reste est inférieur à 11 ou supérieur à 16, on doit le traiter.
   if(reste < 11 || reste > 16)
   {
      int dizaine = reste / DIX;
      int unite = reste % DIX;
      string dizaineString = dizaineToString(dizaine);
      string uniteString = uniteToString(unite);

      // s'il y a des dizaines, on les traite
      if(dizaine)
      {
         // s'il reste des unités
         if(unite)
         {
            // s'il le reste % 10 == 1, on écrit la dizaine avec et
            if(unite == 1)
            {
               resultat += dizaineString + " et " + uniteString;
            }
            // sinon on écrit avec un trait d'union.
            else
            {
               resultat += dizaineString + "-" + uniteString;
            }
         }
         // sinon on écrit la dizaine
         else
         {
            resultat += dizaineString;
         }
      }
      // sinon on écrit les unités uniquement
      else 
      {
         resultat += uniteString;
      }
   }
   // sinon on traite le reste
   else
   {
      resultat += uniteToString(reste);
   }

   return resultat;
}

string montantEnVaudois(const double MONTANT)
{
   string resultat = "";
   int milliers = getMilliers(MONTANT);
   int centaines = getCentaines(MONTANT);
   int decimales = getDecimales(MONTANT);

   string milliersString = blocToString(milliers, true);
   string centainesString = blocToString(centaines, false);
   string decimalesString = blocToString(decimales, false);

   // S'il n'y a qu'un millier, on écrit mille
   if(milliers == 1)
   {
      resultat += "mille ";
   }
   // sinon on écrit les milliers avec ce qui s'ensuit, les centaines 
   else if(milliers)
   {
      resultat += milliersString + " mille ";
   }
   resultat += centainesString;
   // Si on a pas de milliers, ni de centaines, ni de décimales, c'est qu'on a zéro
   if((!milliers) && (!centaines) && (!decimales))
   {
      resultat += "zero franc";
   }
   else  // sinon on doit traiter
   {
      // si on a des milliers
      if((milliers) || (centaines))
      {
         resultat += " franc";
      }
   }
   if((milliers) || (centaines > 1))
   {
      resultat += "s";
   }

   if(decimales)
   {
      // S'il y'a des milliers ou des centaines, on doit rajouter un et pour écrire
      // les centimes.
      if (milliers || centaines)
      {
         resultat += " et ";
      }
      
      resultat += decimalesString + " centime";

      // si les décimales sont supérieures à 1, on doit rajouter un s.
      if (decimales > 1)
      {
         resultat += "s";
      }
   }
   return resultat;
}


double saisieUtilisateur(const int VALMIN, const int VALMAX, double& valeur)
{
   bool entree_invalide = false;   
   
   do
   {
      // entrée est invalide si valeur non attendue ou dépasse les bornes
      entree_invalide = ((not(cin >> valeur) || valeur <  VALMIN ||  valeur > VALMAX));
      if (entree_invalide) // si entrée est invalide, on affiche erreur, vide buffer et affiche question
      {
         cout << "Votre valeur est fausse, veuillez saisir une valeur entre " 
              << VALMIN  << " et " <<  VALMAX << endl;
         cin.clear();
         cin.ignore(numeric_limits<int>::max(), '\n');
         cin >> valeur;
      }      
   } 
   while(entree_invalide); // tant que l'entrée est invalide, on garde l'utilisateur captif   
   
   return valeur;
}