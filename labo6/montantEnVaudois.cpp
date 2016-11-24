#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

/**
 Retourne la partie des milliers d'un nombre
 
 @param reçoit le nombre dont on veut extraire les milliers
 @return la partie décimale d'un nombre en double constant
 */
int getMilliers (const double nombre)
{
   return (int)(nombre / 1000); // retourne le nombre de milliers
}


/**
 Retourne la partie des centaines d'un nombre
 
 @param reçoit le nombre dont on veut extraire les centaines
 @return la partie décimale d'un nombre en double constant
 */
int getCentaines (const double nombre)
{
   return ((int)nombre) % 1000; // retourne le nombre de centaines
}

/**
 Retourne la partie décimale d'un nombre
 
 @param reçoit le nombre dont on veut extraire la partie décimale
 @return la partie décimale d'un nombre en double constant
 */
int getDecimales (const double nombre)
{
   return (int)round(nombre * 100) % 100; // retourne la partie décimale
}

/**
 Retourne les valeurs décimales
 
 @param reçoit le nombre dont on veut extraire la partie décimale
 @return la partie décimale d'un nombre en double
 */
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
   
/**
 Retourne les valeurs décimales
 
 @param reçoit le nombre dont on veut extraire la partie décimale
 @return la partie décimale d'un nombre en double
 */
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
      else if(milliers && centaine || centaine && reste)
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
         
         if (decimales != 1)
         {
            resultat += "s";
         }
      }
      return resultat;
   }