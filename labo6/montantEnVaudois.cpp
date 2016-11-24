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



/**
 Retourne la partie des centaines d'un nombre
 
 @param reçoit le nombre dont on veut extraire les centaines
 @return la partie décimale d'un nombre en double constant
 */


/**
 Retourne la partie décimale d'un nombre
 
 @param reçoit le nombre dont on veut extraire la partie décimale
 @return la partie décimale d'un nombre en double constant
 */


/**
 Retourne une chaine de caractères en français quand elle reçoit un nombre allant
 * de 0 à 9 et de 11 à 16. Ce sont les bases du comptage et les cas particuliers.
 
 @param reçoit le nombre(int) entre 1 et 16, 10 exclu dont on veut récupérer sa chaine
 *      de caractères.
 @return la chaine de caractère du chiffre reçu en paramètre.
 */

   
/**
 Fonction qui traite un nombre et retourne sa chaine de caractère en dizaine
 
 @param reçoit le nombre(int) encodé qui correspond à sa valeur en dizaine(voir details)
 @return la dizaine correspondant sous forme de string.
 \details
 * Exemple: s'il reçoit 1, il retourne dix. 2 => vingt et etc...
 */


/**
 Fonction principale qui écrit les accords de centaines ainsi que les mots de liaisons
 * tels que "et" ainsi que le trait d'union
 *  
 @param reçoit le bloc de chiffre que l'on veut traiter
 @param reçoit un boolean pour savoir si c'est un millier qu'on traite ou pas,
 * nous avons dû l'introduire afin de ne pas faire l'accord des centaines lorsque
 * que c'est des centaines de milliers.
 @return la chaine de caractère traitée avec les mots de liaisons.
 */

   
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
   