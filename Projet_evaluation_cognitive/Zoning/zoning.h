#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h>    // Pour pouvoir utiliser printf()
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>    // Pour pouvoir utiliser sin() et cos()
#include "../LibrairieGraphique/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../LibrairieGraphique/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../LibrairieGraphique/ESLib.h"    // Pour utiliser valeurAleatoire()
// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600


typedef struct {
  char Nom [30];
  char prenom [10];
  char age [3];
  char resultat [50];
  FILE* database;
}utilisateur;


// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);

void PageDemarrage();

void PageInscription();

void PageConnexion();

void PageAccueil();

void PageAccueilCredit();

void PageAccueilResultat();

void PageMemoire();

void PageMemoireTest1();

void PageMemoireTest2();

void PageMemoireTest2_1();

void PageMemoireTest2_2();

void PageMemoireTest2_3();

void PageMemoireTest2_4();

void PageMemoireTest2_5();

void PageMemoireTest2_6();

void PageMemoireTest2_7();

void PageMobilite();

void PageMobiliteTest1();

void PageMobiliteTest1_2();

void PageMobiliteTest2();

void PageVision();

void PageVisionTest1();

void PageVisionTest1_2();

void PageVisionTest1_3();

void PageVisionTest1_4();

void PageVisionTest2();

void PageVisionTest2_2();

void PageVisionTest2_3();

void PageVisionTest2_4();

void cree3matrices(int B[256][256],int V[256][256], int R[256][256], DonneesImageRGB *image);
