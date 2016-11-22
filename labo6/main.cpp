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
#include<iostream>

using namespace std;

string montantEnVaudois(double montant);

int main()
{
    double d;
    
    while(cin >> d) 
    {
        cout << montantEnVaudois(d) << endl;
    }   

   return EXIT_SUCCESS;
}