#include <string.h>
#include "../../bib/classes/classes.hh"

#include "../../../libExt/rapidjson/document.h"

/**
 * \brief Systeme de Gestion de Fichiers
 * */

/**
 * \brief Sauvegarde
 * Sauvegarde du Graphe courant. 
 * La fonctione &eacute;crit dans un fichier plac&eacute; en parametre ou dans le chemin en attribut
 * L'objet sera d&eacute;crit grace &agrave; la bibliotheque JSON
 * Si path n'est pas &eacute;gal &agrave NULL : sauvegarde sous ou nouveau document
 * @param G Graphe &agrav; sauvegarder
 * @param path Chemin de la sauvegarde
 * @return 0 Si la sauvegarde est r&eacute;ussis
 * @return -1 Si il y a une erreur lors de la sauvegarde
 * */
int sauvegarde(Graphe G, std::string path="NULL");

/**
 * \brief Chargement
 * Cette fonction parse le fichier JSON qui contient un Graphe sauvegard&eacute; lors d'une pr&eacute;c&eacute;dente session puis charge le fichier
 * @param path CHemin du fichier &agrave; charger
 * @return Graphe pr&eacute;sent dans le fichier
 * */
Graphe chargement(string path);

/**
 * \brief Verification
 * Cette fonction v&eacute;rifie que le document JSON correspond &agrave; l'arch&eacute;type de notre document de sauvegarde.
 * La structure Document est un objet en JSON 
 * @param path Document &agrave; v&eacute;rifier
 * @return true Si l'architercture est correcte
 * @return false Si l'achitecture n'est pas la bonne
 * */
bool verif_file(string path);

/**
 * \brief Suppression
 * Supprime le fichier en parametre
 * @param path Fichier &agrave; supprimer
 * @return 0 si le fichier est bien supprim&eacute;
 * @return -1 dans le cas contraire
 * */
int suppression(string path);