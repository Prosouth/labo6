#include <string>

using namespace std;

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
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int getBloc1 (double nombre)
{
   return (int)(nombre / 1000); //donne la partie milier
}

int getBloc2 (double nombre)
{
   return ((int)nombre)% 1000; //donne la partie centaine
}

int getBloc3 (double nombre)
{
   return (int)round(nombre*100) % 100; //donne la partie décimale
}

//Cette fonction retourne la représentation française d'un chiffre non nul
string uniteToString(int chiffre)
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
   }
}
   
//cette fonction retourne la representation francaise d'un chiffre representant une dizaine. 
string dizaineToString(int nombre)
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
      }
   }
   
   string blocToString(int bloc)
   {
      string resultat = "";
      int reste = bloc % 100;
      int centaine = bloc / 100;
      
      //on ecrit les centaines
      if(centaine == 1)
      {
         resultat += "cent";
      }
      else if(centaine != 0)
      {
         resultat += uniteToString(centaine) + " cent"; // accord cents si franc direct après
      }
      if((reste != 0) && (centaine != 0))
      {
         resultat += " ";
      }
      //on ecrit les dizaines et les unités
      if(reste < 11 || reste > 16)
      {
         int dizaine = reste / 10;
         int unite = reste % 10;
         string dizStr = dizaineToString(dizaine);
         string uniStr = uniteToString(unite);
         
         if(dizaine != 0)
         {
            if(unite != 0)
            {
               if(unite == 1)
               {
                  resultat += dizStr + " et " + uniStr;
               }
               else
               {
                  resultat += dizStr + "-" + uniStr;
               }
            }
            else
            {
               resultat += dizStr;
            }
         }
         else 
         {
            resultat += uniStr;
         }
      }
      else
      {
         resultat += uniteToString(reste);
      }
      
      return resultat;
   }

   string montantEnVaudois(double montant)
   {
      string resultat = "";
      int bloc1 = getBloc1(montant);
      int bloc2 = getBloc2(montant);
      int bloc3 = getBloc3(montant);

      string bloc1String = blocToString(bloc1);
      string bloc2String = blocToString(bloc2);
      string bloc3String = blocToString(bloc3);
      
      if(bloc1 == 1)
      {
         resultat += "mille ";
      }
      else if(bloc1 != 0)
      {
         resultat += bloc1String + " mille ";
      }
      resultat += bloc2String;
      if((bloc1 == 0) && (bloc2 == 0) && (bloc3 == 0))
      {
         resultat += "zero franc";
      }
      else 
      {
         if((bloc1 != 0) || (bloc2 != 0))
         {
            resultat += " franc";
         }
      }
      if((bloc1 != 0) || (bloc2 > 1))
      {
         resultat += "s";
      }
      
      if(bloc3 != 0)
      {
         if (bloc1 != 0 || bloc2 != 0)
         {
            resultat += " et ";
         }
         
         resultat += bloc3String + " centime";
         
         if (bloc3 != 1)
         {
            resultat += "s";
         }
      }
      return resultat;
   }