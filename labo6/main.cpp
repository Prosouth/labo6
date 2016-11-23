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

 Remarque(s) : 

 Compilateur : g++ 6.2.1 20160830
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

// Constantes
const double BORNE_INFERIEURE = 0;
const double BORNE_SUPERIEURE = 999999.99;

string montantEnVaudois(double montant);
double saisieUtilisateur(int valMin, int valMax, double& valeur);

int main()
{
    double d;
    montantEnVaudois(saisieUtilisateur(BORNE_INFERIEURE, BORNE_SUPERIEURE,d));

   return EXIT_SUCCESS;
}

double saisieUtilisateur(int valMin, int valMax, double& valeur)
{
   bool entree_invalide = false;   
   
   do
   {
      // entrée est invalide si valeur non attendue ou dépasse les bornes
      entree_invalide = ((not(cin >> valeur) || valeur <  valMin ||  valeur > valMax));
      if (entree_invalide) // si entrée est invalide, on affiche erreur, vide buffer et affiche question
      {
         cout << "Votre valeur est fausse, veuillez saisir une valeur entre "  <<
                 valMin  << " et " <<  valMax << endl;
         cin.clear();
         cin.ignore(numeric_limits<int>::max(), '\n');
         cin >> valeur;
      }      
   } 
   while(entree_invalide); // tant que l'entrée est invalide, on garde l'utilisateur captif   
   
   return valeur;
}