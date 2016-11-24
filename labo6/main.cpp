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
 *             si la saise est fausse.

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
const double BORNE_INFERIEURE = 0;
const double BORNE_SUPERIEURE = 999999.99;


/**
    \brief Traduit des nombres réels en prix exprimés en vaudois
    \param[in] montant un réel compris entre 0 et 999999.99 CHF.
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
string montantEnVaudois(const double montant);


/**
 Demande les valeurs à l'utilisateur et verifie la saisie
 
 @param valMin(entier) définit le nombre mimimum à entrer
 @param valMax(entier) définit le nombre maximum à entrer
 @param valeur(double) en référence qui sera la valeur à traiter
 @return la saisie correcte en double
 */
double saisieUtilisateur(const int valMin, const int valMax, double& valeur);

/**
 Retourne la partie des milliers d'un nombre
 
 @param reçoit le nombre dont on veut extraire les milliers
 @return la partie décimale d'un nombre en double constant
 */
int getMilliers (const double nombre);

/**
 Retourne la partie des centaines d'un nombre
 
 @param reçoit le nombre dont on veut extraire les centaines
 @return la partie décimale d'un nombre en double constant
 */
int getCentaines (const double nombre);


/**
 Retourne la partie décimale d'un nombre
 
 @param reçoit le nombre dont on veut extraire la partie décimale
 @return la partie décimale d'un nombre en double constant
 */
int getDecimales (const double nombre);


/**
 Retourne une chaine de caractères en français quand elle reçoit un nombre allant
 * de 0 à 9 et de 11 à 16. Ce sont les bases du comptage et les cas particuliers.
 
 @param reçoit le nombre(int) entre 1 et 16, 10 exclu dont on veut récupérer sa chaine
 *      de caractères.
 @return la chaine de caractère du chiffre reçu en paramètre.
 */
string uniteToString(const int chiffre);

/**
 Fonction qui traite un nombre et retourne sa chaine de caractère en dizaine
 
 @param reçoit le nombre(int) encodé qui correspond à sa valeur en dizaine(voir details)
 @return la dizaine correspondant sous forme de string.
 \details
 * Exemple: s'il reçoit 1, il retourne dix. 2 => vingt et etc...
 */
string dizaineToString(const int nombre);



int main()
{
    double d;
    cout << montantEnVaudois(saisieUtilisateur(BORNE_INFERIEURE, BORNE_SUPERIEURE,d))
         << endl;

   return EXIT_SUCCESS;
}

int getMilliers (const double nombre)
{
   return (int)(nombre / 1000); // retourne le nombre de milliers
}


int getCentaines (const double nombre)
{
   return ((int)nombre) % 1000; // retourne le nombre de centaines
}

int getDecimales (const double nombre)
{
   return (int)round(nombre * 100) % 100; // retourne la partie décimale
}

string uniteToString(const int chiffre)
{
   switch(chiffre)
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

string dizaineToString(const int nombre)
{
   switch(nombre)
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

string blocToString(const int bloc, const bool milliers)
{
   string resultat = "";
   int reste = bloc % 100;
   int centaine = bloc / 100;

   //on ecrit les centaines
   if(centaine == 1)
   {
      resultat += "cent";
   }
   else if(centaine && !reste && centaine < 10 && !milliers)
   {
      resultat += uniteToString(centaine) + " cents";    
   }
   else if((milliers && centaine) || (centaine && reste))
   {
      resultat += uniteToString(centaine) + " cent"; 
   }
   if((reste != 0) && (centaine))
   {
      resultat += " ";
   }
   //on ecrit les dizaines et les unités
   if(reste < 11 || reste > 16)
   {
      int dizaine = reste / 10;
      int unite = reste % 10;
      string dizaineString = dizaineToString(dizaine);
      string uniteString = uniteToString(unite);

      if(dizaine)
      {
         if(unite)
         {
            if(unite == 1)
            {
               resultat += dizaineString + " et " + uniteString;
            }
            else
            {
               resultat += dizaineString + "-" + uniteString;
            }
         }
         else
         {
            resultat += dizaineString;
         }
      }
      else 
      {
         resultat += uniteString;
      }
   }
   else
   {
      resultat += uniteToString(reste);
   }

   return resultat;
}

string montantEnVaudois(const double montant)
{
   string resultat = "";
   int milliers = getMilliers(montant);
   int centaines = getCentaines(montant);
   int decimales = getDecimales(montant);

   string milliersString = blocToString(milliers, true);
   string centainesString = blocToString(centaines, false);
   string decimalesString = blocToString(decimales, false);

   if(milliers == 1)
   {
      resultat += "mille ";
   }
   else if(milliers)
   {
      resultat += milliersString + " mille ";
   }
   resultat += centainesString;
   if((!milliers) && (!centaines) && (!decimales))
   {
      resultat += "zero franc";
   }
   else 
   {
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
      if (milliers || centaines)
      {
         resultat += " et ";
      }

      resultat += decimalesString + " centime";

      if (decimales > 1)
      {
         resultat += "s";
      }
   }
   return resultat;
}


double saisieUtilisateur(const int valMin, const int valMax, double& valeur)
{
   bool entree_invalide = false;   
   
   do
   {
      // entrée est invalide si valeur non attendue ou dépasse les bornes
      entree_invalide = ((not(cin >> valeur) || valeur <  valMin ||  valeur > valMax));
      if (entree_invalide) // si entrée est invalide, on affiche erreur, vide buffer et affiche question
      {
         cout << "Votre valeur est fausse, veuillez saisir une valeur entre " 
              << valMin  << " et " <<  valMax << endl;
         cin.clear();
         cin.ignore(numeric_limits<int>::max(), '\n');
         cin >> valeur;
      }      
   } 
   while(entree_invalide); // tant que l'entrée est invalide, on garde l'utilisateur captif   
   
   return valeur;
}