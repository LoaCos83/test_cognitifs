#include "zoning.h"

int incr = 0, i = 0;
int fill_step = 0;
int redondence = 0;

utilisateur newuser;
utilisateur individu[3];
FILE* Repertoire1 = NULL;
FILE* Repertoire2 = NULL;
FILE* Repertoire3 = NULL;

void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2. * M_PI / Pas;
	int index;

	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2. * M_PI * index / Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX + rayon * cos(angle), centreY + rayon * sin(angle),
				 centreX + rayon * cos(angle + PasAngulaire), centreY + rayon * sin(angle + PasAngulaire));
		// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}
}


void gestionEvenement(EvenementGfx evenement)
{
	static int user1 =0;
	static int user2 =0;
	static int user3 =0;
	//1
	static bool once1 = false;
	static bool once2 = false;
	static bool once3 = false;
	static bool once4 = false;
	static bool once5 = false;
	static bool once6 = false;
	//2
	static bool onces1 = false;
	static bool onces2 = false;
	static bool onces3 = false;
	static bool onces4 = false;
	static bool onces5 = false;
	static bool onces6 = false;
	//3
	static bool once1s = false;
	static bool once2s= false;
	static bool once3s = false;
	static bool once4s = false;
	static bool once5s = false;
	static bool once6s = false;

	static DonneesImageRGB *image0 ,*image1,*image2,*image3,*image4,*image5,*image1_2,*image2_2,*image3_2,*image4_2,*image5_2 = NULL;


	static int B[256][256]={0}, V[256][256]={0}, R[256][256]={0};

	static int etat = 10;
	static int test ,zone = 0;

	static int vision2 , vision2_1 , vision2_2 = 0;//test 6
	static int vision1 , vision1_1 , vision1_2 = 0;//test 5

	static int carte1_1 , carte1_2 , carte2_1 , carte2_2 , carte3_1 , carte3_2 , carte4_1 , carte4_2 , carte5_1 , carte5_2 = 0;
	static int paire1 ,paire2 ,paire3 ,paire4 ,paire5 = 0;
	static int cptclic = 0;
	static int cptclic2_1 = 0;
	static int cptclic2_2 = 0;
	static int cptclic2_3 = 0;
// TEST2
	static int  mots = 0;
	static int mot1_1, mot2_1, mot3_1, mot4_1 ,mot5_1 = 0;
	static int mot1_2, mot2_2, mot3_2, mot4_2 ,mot5_2 = 0;
	static int mot1_3, mot2_3, mot3_3, mot4_3 ,mot5_3 = 0;

//TEST3
	static int position = 0;
	static int laby_1 = 0;
	static int laby_2 = 0;
	static int laby_3 = 0;
	 int sAbscisseSouris = abscisseSouris();
	 int sOrdonneeSouris = ordonneeSouris();

//TEST4
//	static char Nom[12]="",Prenom[12]="",Read[250]=""
	static int xBalle;
	static int yBalle;
	static int vxBalle = 10;
	static int vyBalle = -10;
	static int boule_1 = 0 ;
	static int boule_2 = 0 ;
	static int boule_3 = 0 ;

//TEST5
	static int couleur_1 = 0;
	static int couleur_2 = 0;
	static int couleur_3 = 0;

//TEST6
	static int lettre_1 = 0;
	static int lettre_2 = 0;
	static int lettre_3 = 0;


	switch (evenement)
	{

	case Initialisation:

		demandeTemporisation(20);

		image0 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarotback.bmp");
		image1 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot17.bmp");
		image2 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot21.bmp");
		image3 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot9.bmp");
		image4 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot13.bmp");
		image5 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot5.bmp");
		image1_2 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot17.bmp");
		image2_2 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot21.bmp");
		image3_2 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot9.bmp");
		image4_2 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot13.bmp");
		image5_2 = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/tarot5.bmp");

/*		right = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/check.bmp");
		wrong = lisBMPRGB("/home/isen/github/Projet-de-fin-d-annee-algo-/Projet_evaluation_cognitive/images/cross.bmp");
*/

		cree3matrices(B,V,R,image0);
		cree3matrices(B,V,R,image1);
		cree3matrices(B,V,R,image2);
		cree3matrices(B,V,R,image3);
		cree3matrices(B,V,R,image4);
		cree3matrices(B,V,R,image5);
		cree3matrices(B,V,R,image1_2);
		cree3matrices(B,V,R,image2_2);
		cree3matrices(B,V,R,image3_2);
		cree3matrices(B,V,R,image4_2);
		cree3matrices(B,V,R,image5_2);



			rafraichisFenetre();
		break;

	case Temporisation:
	// On met a jour les coordonnees de la balle
			xBalle += vxBalle;
			yBalle += vyBalle;

			// On fait rebondir la balle si necessaire
			if (xBalle < 0 || xBalle >= largeurFenetre()-20 )
				vxBalle = -vxBalle;
			if (yBalle < 0 || yBalle >= hauteurFenetre()-20 )
				vyBalle = -vyBalle;
			if (xBalle < 0 || xBalle <= 20 )
				vxBalle = -vxBalle;
			if (yBalle < 0 || yBalle <= 20 )
				vyBalle = -vyBalle;

			// Les coordonnees de la balle ayant eventuellement change,

			//PAge LABYRINYHE


		rafraichisFenetre();

		break;

	case Affichage:

//PAGE DEMARRAGE

		if (zone == 0)
		{
			effaceFenetre(255, 255, 255);
			PageDemarrage();

		}

		if (zone == 1)
		{
			effaceFenetre(255, 255, 255);
			PageInscription();
		}

		if (zone == 2)
		{
			effaceFenetre(255, 255, 255);
			PageConnexion();


		}

		if (etat == 0)
		{
			effaceFenetre(255, 255, 255);
			PageAccueil();
		}

		//PaGE MEMOIRE

		else if (etat == 1)
		{
			effaceFenetre(200, 200, 200);
			PageMemoire();
		}
		if (test == 1)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest1();
			ecrisImage(50,350, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(50,100, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(200,350, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(200,100, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(350,350, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(350,100, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(500,350, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(500,100, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(650,350, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);
			ecrisImage(650,100, image0->largeurImage, image0->hauteurImage, image0->donneesRGB);





		}
		else if (test == 2)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2();


		}

		//PaGE Mobilite
		else if (etat == 2)
		{
			effaceFenetre(200, 200, 200);
			PageMobilite();
		}
		if (test == 3)
		{
			effaceFenetre(255, 100, 100);
			PageMobiliteTest1();
			// LABYRINTHE
			if( position == 2)
			{
				effaceFenetre(255, 100, 100);
				 PageMobiliteTest1_2();
			}


		}
		else if (test == 4)
		{
			effaceFenetre(255, 100, 100);
			PageMobiliteTest2();
			couleurCourante(255, 255, 0);
			cercle(xBalle, yBalle, 20);

		}

		//PaGE VISION
		else if (etat == 3)
		{
			effaceFenetre(200, 200, 200);

			PageVision();
		}
		if (test == 5)
		{
			effaceFenetre(100, 100, 255);
			PageVisionTest1();
			if(user1 == 1)
				couleur_1 = 0;
			if(user2 == 1)
				couleur_2 = 0;
			if(user3 == 1)
				couleur_3 = 0;
		}
		else if (test == 6)
		{
			effaceFenetre(100, 100, 255);
			PageVisionTest2();
			if(user1 == 1)
				lettre_1 = 0;
			if(user2 == 1)
				lettre_2 = 0;
			if(user3 == 1)
				lettre_3 = 0;

		}

		//CREDIT
		else if (etat == 4)
		{
			effaceFenetre(255, 255, 255);
			PageAccueilCredit();
		}

		//RESULTAT
		if(user1 ==1)
			{
				if (etat == 5)
			{
			effaceFenetre(255, 255, 255);
			PageAccueilResultat();
			epaisseurDeTrait(2);
			
			if (cptclic2_1 == 10)
			{
				couleurCourante(255,0,0);
				afficheChaine("VOYANT", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
			if ( once1 == false)
				{
					once1 = true;
					fprintf(Repertoire1,"Resultat mémoire test 1 = VOYANT\n",individu[i].resultat);
					
				}

			}

			else if (11 <= cptclic2_1 && cptclic2_1 <= 15)
			{
				couleurCourante(255,0,0);
				afficheChaine(" PRO", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( once1 == false)
				{
					once1 = true;
					fprintf(Repertoire1,"Resultat mémoire test 1 = PRO\n",individu[i].resultat);
					
				}
			}

			else if (16 <= cptclic2_1 && cptclic2_1  <= 20)
			{
				couleurCourante(255,0,0);
				afficheChaine("AMATEUR", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( once1 == false)
				{
					once1 = true;
					fprintf(Repertoire1,"Resultat mémoire test 1 = AMATEUR\n",individu[i].resultat);
					
				}
			}


			else if (21 <= cptclic2_1)
			{
				couleurCourante(255,0,0);
				afficheChaine("DEBUTANT", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( once1 == false)
				{
					once1 = true;
					fprintf(Repertoire1,"Resultat mémoire test 1 = DEBUTANT\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
					if ( once1 == false)
					{
						once1 = true;
						fprintf(Repertoire1,"Resultat mémoire test 1 = RATE\n",individu[i].resultat);
						
					}
				}
				if (mot1_1 == 1 && mot2_1 == 1 && mot3_1 == 1 && mot4_1 == 1 && mot5_1 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/3 - 160,hauteurFenetre()/2 - 130);
				if ( once2 == false)
				{
					once2 = true;
					fprintf(Repertoire1,"Resultat mémoire test 2 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/3-160 , hauteurFenetre()/2-130);
					if ( once2 == false)
					{
						once2 = true;
						fprintf(Repertoire1,"Resultat mémoire test 1 = RATE\n",individu[i].resultat);
						
					}
				}
				if (laby_1 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/2-50,hauteurFenetre()/2 );
				if ( once3 == false)
				{
					once3 = true;
					fprintf(Repertoire1,"Resultat mobilité test 1 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/2-50 , hauteurFenetre()/2);
					if ( once3 == false)
					{
						once3 = true;
						fprintf(Repertoire1,"Resultat mobilite test 1 = RATE\n",individu[i].resultat);
						
					}
				}
				if (boule_1 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/2-50,hauteurFenetre()/2-130 );
				if ( once4 == false)
				{
					once4 = true;
					fprintf(Repertoire1,"Resultat mobilite test 2 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/2-50 , hauteurFenetre()/2-130);
					if ( once4 == false)
					{
						once4 = true;
						fprintf(Repertoire1,"Resultat mobilite test 2 = RATE\n",individu[i].resultat);
						
					}
				}
				if (couleur_1 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,3*largeurFenetre()/4,hauteurFenetre()/2 );
				if ( once5 == false)
				{
					once5 = true;
					fprintf(Repertoire1,"Resultat vision test 1 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, 3*largeurFenetre()/4 , hauteurFenetre()/2);
					if ( once5 == false)
					{
						once5 = true;
						fprintf(Repertoire1,"Resultat vision test 1 = RATE\n",individu[i].resultat);
						
					}
				}
				if (lettre_1  == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,3*largeurFenetre()/4,hauteurFenetre()/2-130 );
				if ( once6 == false)
				{
					once6 = true;
					fprintf(Repertoire1,"Resultat vision test 2 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, 3*largeurFenetre()/4, hauteurFenetre()/2-130);
					if ( once6 == false)
					{
						once6 = true;
						fprintf(Repertoire1,"Resultat vision test 2 = RATE\n",individu[i].resultat);
						
					}
				}
			}	
			}
			
			if(user2 ==1)
		{
			if (etat == 5)
			{
			effaceFenetre(255, 255, 255);
			PageAccueilResultat();
			epaisseurDeTrait(2);
			if (cptclic2_2 == 10)
			{
				couleurCourante(255,0,0);
				afficheChaine("VOYANT", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
			if ( onces1 == false)
				{
					onces1 = true;
					
					fprintf(Repertoire2,"Resultat mémoire test 1 = VOYANT\n",individu[i].resultat);
					
				}

			}

			else if (11 <= cptclic2_2 && cptclic2_2 <= 15)
			{
				couleurCourante(255,0,0);
				afficheChaine(" PRO", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( onces1 == false)
				{
					onces1 = true;
					
					fprintf(Repertoire2,"Resultat mémoire test 1 = PRO\n",individu[i].resultat);
					
				}
			}

			else if (16 <= cptclic2_2 && cptclic2_2  <= 20)
			{
				couleurCourante(255,0,0);
				afficheChaine("AMATEUR", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( onces1 == false)
				{
					onces1 = true;
					
					fprintf(Repertoire2,"Resultat mémoire test 1 = AMATEUR\n",individu[i].resultat);
					
				}
			}


			else if (21 <= cptclic2_2)
			{
				couleurCourante(255,0,0);
				afficheChaine("DEBUTANT", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( onces1 == false)
				{
					onces1 = true;
					
					fprintf(Repertoire2,"Resultat mémoire test 1 = DEBUTANT\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
					if ( onces1 == false)
					{
						onces1 = true;
						
						fprintf(Repertoire2,"Resultat mémoire test 1 = RATE\n",individu[i].resultat);
						
					}
				}
				if (mot1_2 == 1 && mot2_2 == 1 && mot3_2 == 1 && mot4_2 == 1 && mot5_2 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/3 - 160,hauteurFenetre()/2 - 130);
				if ( onces2 == false)
				{
					onces2 = true;
					
					fprintf(Repertoire2,"Resultat mémoire test 2 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/3-160 , hauteurFenetre()/2-130);
					if ( onces2 == false)
					{
						onces2 = true;
						
						fprintf(Repertoire2,"Resultat mémoire test 1 = RATE\n",individu[i].resultat);
						
					}
				}
					if (laby_2 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/2-50,hauteurFenetre()/2 );
				if ( onces3 == false)
				{
					onces3 = true;
					
					fprintf(Repertoire2,"Resultat mobilité test 1 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/2-50 , hauteurFenetre()/2);
					if ( onces3 == false)
					{
						onces3 = true;
						
						fprintf(Repertoire2,"Resultat mobilite test 1 = RATE\n",individu[i].resultat);
						
					}
				}
					if (boule_2 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/2-50,hauteurFenetre()/2-130 );
				if ( onces4 == false)
				{
					onces4 = true;
					
					fprintf(Repertoire2,"Resultat mobilite test 2 = REUSSI\n",individu[i].resultat);
				
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/2-50 , hauteurFenetre()/2-130);
					if ( onces4 == false)
					{
						onces4 = true;
						
						fprintf(Repertoire2,"Resultat mobilite test 2 = RATE\n",individu[i].resultat);
						
					}
				}
				
				if (couleur_2 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,3*largeurFenetre()/4,hauteurFenetre()/2 );
				if ( onces5 == false)
				{
					onces5 = true;
					
					fprintf(Repertoire2,"Resultat vision test 1 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, 3*largeurFenetre()/4 , hauteurFenetre()/2);
					if ( onces5 == false)
					{
						onces5 = true;
						
						fprintf(Repertoire2,"Resultat vision test 1 = RATE\n",individu[i].resultat);
						
					}
				}
				if (lettre_2  == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,3*largeurFenetre()/4,hauteurFenetre()/2-130 );
				if ( onces6 == false)
				{
					onces6 = true;
					
					fprintf(Repertoire2,"Resultat vision test 2 = REUSSI\n",individu[i].resultat);
					
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, 3*largeurFenetre()/4, hauteurFenetre()/2-130);
					if ( onces6 == false)
					{
						onces6 = true;
						
						fprintf(Repertoire2,"Resultat vision test 2 = RATE\n",individu[i].resultat);
						
					}
			
				}
			}
		}
			if (user3 == 1)
			{	
				if (etat == 5)
			{
			effaceFenetre(255, 255, 255);
			PageAccueilResultat();
			epaisseurDeTrait(2);
			if (cptclic2_3 == 10)
			{
				couleurCourante(255,0,0);
				afficheChaine("VOYANT", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
			if ( once1s == false)
				{
					once1s = true;
					
					fprintf(Repertoire3,"Resultat mémoire test 1 = VOYANT\n",individu[i].resultat);
				}

			}

			else if (11 <= cptclic2_3 && cptclic2_3 <= 15)
			{
				couleurCourante(255,0,0);
				afficheChaine(" PRO", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( once1s == false)
				{
					once1s = true;
					
					fprintf(Repertoire3,"Resultat mémoire test 1 = PRO\n",individu[i].resultat);
				}
			}

			else if (16 <= cptclic2_3 && cptclic2_3  <= 20)
			{
				couleurCourante(255,0,0);
				afficheChaine("AMATEUR", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( once1s == false)
				{
					once1s = true;
					
					fprintf(Repertoire3,"Resultat mémoire test 1 = AMATEUR\n",individu[i].resultat);
				}
			}


			else if (21 <= cptclic2_3)
			{
				couleurCourante(255,0,0);
				afficheChaine("DEBUTANT", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
				if ( once1s == false)
				{
					once1s = true;
					
					fprintf(Repertoire3,"Resultat mémoire test 1 = DEBUTANT\n",individu[i].resultat);
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/3-160 , hauteurFenetre()/2);
					if ( once1s == false)
					{
						once1s = true;
						
						fprintf(Repertoire3,"Resultat mémoire test 1 = RATE\n",individu[i].resultat);
					}
				}
				if (mot1_3 == 1 && mot2_3 == 1 && mot3_3 == 1 && mot4_3 == 1 && mot5_3 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/3 - 160,hauteurFenetre()/2 - 130);
				if ( once2s == false)
				{
					once2s = true;
					
					fprintf(Repertoire3,"Resultat mémoire test 2 = REUSSI\n",individu[i].resultat);
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/3-160 , hauteurFenetre()/2-130);
					if ( once2s == false)
					{
						once2s = true;
						
						fprintf(Repertoire3,"Resultat mémoire test 1 = RATE\n",individu[i].resultat);
					}
				}
				if (laby_3 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/2-50,hauteurFenetre()/2 );
				if ( once3s == false)
				{
					once3s = true;
					
					fprintf(Repertoire3,"Resultat mobilité test 1 = REUSSI\n",individu[i].resultat);
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/2-50 , hauteurFenetre()/2);
					if ( once3s == false)
					{
						once3s = true;
						
						fprintf(Repertoire3,"Resultat mobilite test 1 = RATE\n",individu[i].resultat);
					}
				}
				if (boule_3 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,largeurFenetre()/2-50,hauteurFenetre()/2-130 );
				if ( once4s == false)
				{
					once4s = true;
					
					fprintf(Repertoire3,"Resultat mobilite test 2 = REUSSI\n",individu[i].resultat);
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, largeurFenetre()/2-50 , hauteurFenetre()/2-130);
					if ( once4s == false)
					{
						once4s = true;
						
						fprintf(Repertoire3,"Resultat mobilite test 2 = RATE\n",individu[i].resultat);
					}
				}
				if (couleur_3 == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,3*largeurFenetre()/4,hauteurFenetre()/2 );
				if ( once5s == false)
				{
					once5s = true;
					
					fprintf(Repertoire3,"Resultat vision test 1 = REUSSI\n",individu[i].resultat);
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, 3*largeurFenetre()/4 , hauteurFenetre()/2);
					if ( once5s == false)
					{
						once5s = true;
						
						fprintf(Repertoire3,"Resultat vision test 1 = RATE\n",individu[i].resultat);
					}
				}
				if (lettre_3  == 1)
			{
				couleurCourante(255,0,0);
				afficheChaine("REUSSI",18,3*largeurFenetre()/4,hauteurFenetre()/2-130 );
				if ( once6s == false)
				{
					once6s = true;
					
					fprintf(Repertoire3,"Resultat vision test 2 = REUSSI\n",individu[i].resultat);
				}
			}
				else
				{
					couleurCourante(0,0,0);
					afficheChaine("RATE", 18, 3*largeurFenetre()/4, hauteurFenetre()/2-130);
					if ( once6s == false)
					{
						once6s = true;
						
						fprintf(Repertoire3,"Resultat vision test 2 = RATE\n",individu[i].resultat);
					}
				}
			}
			}
		
		

		// MEMORY
		if (carte1_1 == 1)
				if (image1 != NULL )
					ecrisImage(50,350, image1->largeurImage, image1->hauteurImage, image1->donneesRGB);

		if (carte1_2 == 1)
				if (image1_2 != NULL )
					ecrisImage(350,100, image1_2->largeurImage, image1_2->hauteurImage, image1_2->donneesRGB);


		if (carte1_1 == 1 && carte1_2 == 1)
		{
				paire1 = 1;
				if (image1 != NULL && image1_2 != NULL)
				{
					ecrisImage(50,350, image1->largeurImage, image1->hauteurImage, image1->donneesRGB);
					ecrisImage(350,100, image1_2->largeurImage, image1_2->hauteurImage, image1_2->donneesRGB);

				}
		}

		if (carte2_1 == 1)
				if (image2 != NULL )
					ecrisImage(50,100, image2->largeurImage, image2->hauteurImage, image2->donneesRGB);

		if (carte2_2 == 1)
				if (image2_2 != NULL )
						ecrisImage(500,350, image2_2->largeurImage, image2_2->hauteurImage, image2_2->donneesRGB);


		if (carte2_1 == 1 && carte2_2 == 1)
		{
				paire2 = 1;
				if (image2 != NULL && image2_2 != NULL)
				{
					ecrisImage(50,100, image2->largeurImage, image2->hauteurImage, image2->donneesRGB);
					ecrisImage(500,350, image2_2->largeurImage, image2_2->hauteurImage, image2_2->donneesRGB);
				}
		}

		if (carte3_1 == 1)
			if (image3 != NULL )
					ecrisImage(200,350, image3->largeurImage, image3->hauteurImage, image3->donneesRGB);

		if (carte3_2 == 1)
			if (image3_2 != NULL )
					ecrisImage(500,100, image3_2->largeurImage, image3_2->hauteurImage, image3_2->donneesRGB);

		if (carte3_1 == 1 && carte3_2 == 1)
		{
			paire3 = 1;
			if (image3 != NULL && image3_2 != NULL)
			{
					ecrisImage(200,350, image3->largeurImage, image3->hauteurImage, image3->donneesRGB);
					ecrisImage(500,100, image3_2->largeurImage, image3_2->hauteurImage, image3_2->donneesRGB);
			}
		}

		if (carte4_1 == 1)
			if (image4 != NULL )
					ecrisImage(200,100, image4->largeurImage, image4->hauteurImage, image4->donneesRGB);

		if (carte4_2 == 1)
			if (image4_2 != NULL )
					ecrisImage(650,350, image4_2->largeurImage, image4_2->hauteurImage, image4_2->donneesRGB);

		if (carte4_1 == 1 && carte4_2 == 1)
		{
			paire4 = 1;
			if (image4 != NULL && image4_2 != NULL)
			{
					ecrisImage(200,100, image4->largeurImage, image4->hauteurImage, image4->donneesRGB);
					ecrisImage(650,350, image4_2->largeurImage, image4_2->hauteurImage, image4_2->donneesRGB);
			}
		}

		if (carte5_1 == 1)
			if (image5 != NULL )
					ecrisImage(350,350, image5->largeurImage, image5->hauteurImage, image5->donneesRGB);

		if (carte5_2 == 1)
			if (image5_2 != NULL )
					ecrisImage(650,100, image5_2->largeurImage, image5_2->hauteurImage, image5_2->donneesRGB);

		if (carte5_1 == 1 && carte5_2 == 1)
		{
			paire5 = 1;
			if (image5 != NULL && image5_2 != NULL)
			{
					ecrisImage(350,350, image5->largeurImage, image5->hauteurImage, image5->donneesRGB);
					ecrisImage(650,100, image5_2->largeurImage, image5_2->hauteurImage, image5_2->donneesRGB);
			}
		}

		if (paire1 == 1)
		{
			if (image1 != NULL && image1_2 != NULL)
			{
				ecrisImage(50,350, image1->largeurImage, image1->hauteurImage, image1->donneesRGB);
				ecrisImage(350,100, image1_2->largeurImage, image1_2->hauteurImage, image1_2->donneesRGB);

			}
		}

		if (paire2 == 1)
		{
			if (image2 != NULL && image2_2 != NULL)
			{
				ecrisImage(50,100, image2->largeurImage, image2->hauteurImage, image2->donneesRGB);
				ecrisImage(500,350, image2_2->largeurImage, image2_2->hauteurImage, image2_2->donneesRGB);
			}
		}


		if (paire3 == 1)
		{
			if (image3 != NULL && image3_2 != NULL)
			{
					ecrisImage(200,350, image3->largeurImage, image3->hauteurImage, image3->donneesRGB);
					ecrisImage(500,100, image3_2->largeurImage, image3_2->hauteurImage, image3_2->donneesRGB);
			}
		}

		if (paire4 == 1)
		{
			if (image4 != NULL && image4_2 != NULL)
			{
					ecrisImage(200,100, image4->largeurImage, image4->hauteurImage, image4->donneesRGB);
					ecrisImage(650,350, image4_2->largeurImage, image4_2->hauteurImage, image4_2->donneesRGB);
			}
		}

		if (paire5 == 1)
		{
			if (image5 != NULL && image5_2 != NULL)
			{
					ecrisImage(350,350, image5->largeurImage, image5->hauteurImage, image5->donneesRGB);
					ecrisImage(650,100, image5_2->largeurImage, image5_2->hauteurImage, image5_2->donneesRGB);
			}
		}

		if (paire1 == 1 && paire2 == 1 && paire3 == 1 && paire4 == 1 && paire5 == 1 )
		{


			if (cptclic == 10)
			{
				couleurCourante(255,215,0); // GOLD
				afficheChaine("RANG : VOYANT", 18, largeurFenetre()/2-75 , hauteurFenetre()/2);
			}

			else if (11 <= cptclic && cptclic <= 15)
			{
				couleurCourante(192,192,192);//SILVER
				afficheChaine("RANG : PRO", 18, largeurFenetre()/2-75 , hauteurFenetre()/2);
			}

			else if (16 <= cptclic && cptclic  <= 20)
			{
				couleurCourante(196,156,72); //BRONZE
				afficheChaine("RANG : AMATEUR", 18, largeurFenetre()/2-75 , hauteurFenetre()/2);
			}


			else if (21 <= cptclic)
			{
				couleurCourante(0,0,0);
				afficheChaine("RANG : DEBUTANT", 18, largeurFenetre()/2-75 , hauteurFenetre()/2);
			}

			carte1_1 = 0;
			carte1_2 = 0;
			carte2_1 = 0;
			carte2_2 = 0;
			carte3_1 = 0;
			carte3_2 = 0;
			carte4_1 = 0;
			carte4_2 = 0;
			carte5_1 = 0;
			carte5_2 = 0;

		}

		// TEST 2
		if(user1 == 1)
	{
		if( mots == 1)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_1();
			mots = 2;
			if (mot1_1 == 1 && mot2_1 == 1 && mot3_1 == 1 && mot4_1 == 1 && mot5_1 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}


		}
		else if(mots == 2)
		{
			sleep(2);
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_2();
			if (mot1_1 == 1 && mot2_1 == 1 && mot3_1 == 1 && mot4_1 == 1 && mot5_1 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}

		}


		 if(mots == 3)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_3();
			mot1_1 = 1;
			if (mot1_1 == 1 && mot2_1 == 1 && mot3_1 == 1 && mot4_1 == 1 && mot5_1 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 4)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_4();
			mot2_1 = 1;
			if (mot1_1 == 1 && mot2_1 == 1 && mot3_1 == 1 && mot4_1 == 1 && mot5_1 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 5)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_5();
			mot3_1 = 1;
			if (mot1_1 == 1 && mot2_1 == 1 && mot3_1 == 1 && mot4_1 == 1 && mot5_1 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 6)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_6();
			mot4_1 = 1;
			if (mot1_1 == 1 && mot2_1 == 1 && mot3_1 == 1 && mot4_1 == 1 && mot5_1 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 7)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_7();
			mot5_1 = 1;
			if (mot1_1 == 1 && mot2_1 == 1 && mot3_1 == 1 && mot4_1 == 1 && mot5_1 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
	}
	
	if(user2 == 1)
	{
		if( mots == 1)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_1();
			mots = 2;
			if (mot1_2 == 1 && mot2_2 == 1 && mot3_2 == 1 && mot4_2 == 1 && mot5_2 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}


		}
		else if(mots == 2)
		{
			sleep(2);
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_2();
			if (mot1_2 == 1 && mot2_2 == 1 && mot3_2 == 1 && mot4_2 == 1 && mot5_2 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}

		}


		 if(mots == 3)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_3();
			mot1_2 = 1;
			if (mot1_2 == 1 && mot2_2 == 1 && mot3_2 == 1 && mot4_2 == 1 && mot5_2 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 4)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_4();
			mot2_2 = 1;
			if (mot1_2 == 1 && mot2_2 == 1 && mot3_2 == 1 && mot4_2 == 1 && mot5_2 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 5)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_5();
			mot3_2 = 1;
			if (mot1_2 == 1 && mot2_2 == 1 && mot3_2 == 1 && mot4_2 == 1 && mot5_2 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 6)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_6();
			mot4_2 = 1;
			if (mot1_2 == 1 && mot2_2 == 1 && mot3_2 == 1 && mot4_2 == 1 && mot5_2 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 7)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_7();
			mot5_2 = 1;
			if (mot1_2 == 1 && mot2_2 == 1 && mot3_2 == 1 && mot4_2 == 1 && mot5_2 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
	}
		if(user3 == 1)
	{
		if( mots == 1)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_1();
			mots = 2;
			if (mot1_3 == 1 && mot2_3 == 1 && mot3_3 == 1 && mot4_3 == 1 && mot5_3 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}


		}
		else if(mots == 2)
		{
			sleep(2);
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_2();
			if (mot1_3 == 1 && mot2_3 == 1 && mot3_3 == 1 && mot4_3 == 1 && mot5_3 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}

		}


		 if(mots == 3)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_3();
			mot1_3 = 1;
			if (mot1_3 == 1 && mot2_3 == 1 && mot3_3 == 1 && mot4_3 == 1 && mot5_3 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 4)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_4();
			mot2_3 = 1;
			if (mot1_3 == 1 && mot2_3 == 1 && mot3_3 == 1 && mot4_3 == 1 && mot5_3 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 5)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_5();
			mot3_3 = 1;
			if (mot1_3 == 1 && mot2_3 == 1 && mot3_3 == 1 && mot4_3 == 1 && mot5_3 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 6)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_6();
			mot4_3 = 1;
			if (mot1_3 == 1 && mot2_3 == 1 && mot3_3 == 1 && mot4_3 == 1 && mot5_3 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
		 if(mots == 7)
		{
			effaceFenetre(46, 139, 87);
			PageMemoireTest2_7();
			mot5_3 = 1;
			if (mot1_3 == 1 && mot2_3 == 1 && mot3_3 == 1 && mot4_3 == 1 && mot5_3 == 1)
			{
				effaceFenetre(46,137,87);
				PageMemoireTest2();
			}
		}
	}



		//QUEL EST LA COuLEUR?
		if(user1 == 1)
	{
		if (vision1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_2();
			couleur_1 =0 ;

		}

		if (vision1_1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_3();


		}

		if (vision1_2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_4();
			couleur_1 = 1;
		}
	}
		if(user2 == 1)
	{
		if (vision1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_2();
			couleur_2 =0 ;

		}

		if (vision1_1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_3();


		}

		if (vision1_2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_4();
			couleur_2 = 1;
		}
	}
		if(user3 == 1)
	{
		if (vision1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_2();
			couleur_3 =0 ;

		}

		if (vision1_1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_3();


		}

		if (vision1_2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest1_4();
			couleur_3 = 1;
		}
	}

		//ACUITE VISUEL
		if(user1 ==1)
	{
		if (vision2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_2();
			lettre_1 = 0;

		}

		if (vision2_1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_3();
			lettre_1 = 0;

		}

		if (vision2_2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_4();
			lettre_1 = 1;

		}
	}
		if(user2 ==1)
	{
		if (vision2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_2();
			lettre_2 = 0;

		}

		if (vision2_1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_3();
			lettre_2 = 0;

		}

		if (vision2_2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_4();
			lettre_2 = 1;

		}
	}
		if(user3 ==1)
	{
		if (vision2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_2();
			lettre_3 = 0;

		}

		if (vision2_1 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_3();
			lettre_3 = 0;

		}

		if (vision2_2 == 1)
		{

			effaceFenetre(100,100,255);
			PageVisionTest2_4();
			lettre_3 = 1;

		}
	}


		break;

	case Clavier:

	if (fill_step == 0)
		{
			newuser.Nom[incr] = caractereClavier();
			incr++;
		}
		if (fill_step == 1)
		{
			newuser.prenom[incr] = caractereClavier();
			incr++;
		}
		if (fill_step == 2)
		{
			newuser.age[incr]= caractereClavier();
      incr++;
		}


	/*	if (caractereClavier() == 'q')
		{
			termineBoucleEvenements();
		}*/

		break;

	case ClavierSpecial:
	fill_step ++;
	incr = 0;
		break;

	case BoutonSouris:
		if (etatBoutonSouris() == GaucheAppuye)
		{

			if (zone == 0)
			{
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					termineBoucleEvenements();
				}

//ZONE INSCRIPTION
				if ((105 <= abscisseSouris()) && (abscisseSouris() <= 695) && (325 <= ordonneeSouris()) && (ordonneeSouris() <= 415))
				{
					zone = 1;

				}
//ZONE CONNEXION
				if ((105 <= abscisseSouris()) && (abscisseSouris() <= 695) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
				{
					zone = 2;
				}

			}

//RETOUR
			if (zone == 1)
			{
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					zone = 0;

					for (incr = 0; incr < 20; incr++)
					{
						newuser.Nom[incr] = NULL;
					}
					incr = 0;
					newuser.Nom[incr] = ' ';
				}


			}

// CONNEXION
			else if (zone == 2)
			{
			// QUITTER
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					zone = 0;
				}
			//CONTINUER
				if ((largeurFenetre()/2 - 95 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2 + 95) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 0;
					zone = -1;
				}

		//USER 1
				if ((105 <= abscisseSouris()) && (abscisseSouris() <= 695) && (355 <= ordonneeSouris()) && (ordonneeSouris() <= 445))
				{
					user1=1;
					user2=0;
					user3=0;
					Repertoire1 = fopen("./DATABASE/Utilisateur1.txt" , "a");
					
				

				}
		//USER 2
				if ((105 <= abscisseSouris()) && (abscisseSouris() <= 695) && (245 <= ordonneeSouris()) && (ordonneeSouris() <= 335))
				{
					user2=1;
					user1=0;
					user3=0;
					Repertoire2 = fopen("./DATABASE/Utilisateur2.txt" , "a");
				
					
				}
		//USER 3
				if ((105 <= abscisseSouris()) && (abscisseSouris() <= 695) && (135 <= ordonneeSouris()) && (ordonneeSouris() <= 225))
				{
					user3=1;
					user1=0;
					user2=0;
					Repertoire3 = fopen("./DATABASE/Utilisateur3.txt" , "a");
					
					
				}



			}




			if (etat == 0)
			{
				//QUITTER
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					zone = 2;
					etat = 10;

				}

					if (etat == 1)
						etat = 0;

					if (etat == 2)
						etat = 0;

					if (etat == 3)
						etat = 0;

				//PAGE MEMOIRE
				else if ((largeurFenetre() / 8 - 25 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre() / 4 + 25) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
					etat = 1;

				//PAGE Mobilite
				else if ((largeurFenetre() / 4 + 95 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre() / 2 + 95) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
					etat = 2;

				//PAGE VISION
				else if ((largeurFenetre() / 2 + 175 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre() - 75) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
					etat = 3;

				//CREDIT
				else if ((0 <= abscisseSouris()) && (abscisseSouris() <= 125 + 50) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 10))
					etat = 4;

				//RESULTAT
				else if ((largeurFenetre()-150 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && ( hauteurFenetre()-45 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()))
					etat = 5;

			}

			//PAGE MEMOIRE
			else if (etat == 1)
			{
				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					etat = 0;

				//TEST1
				if ((largeurFenetre() / 6 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre() / 2 - 25) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
				{
					etat = -1;
					test = 1;
				}



				//TEST2
				if ((largeurFenetre() / 2 + 25 <= abscisseSouris()) && (abscisseSouris() <= 5 * largeurFenetre() / 6) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
				{
					etat = -1;
					test = 2;
				}
			}

			//PAGE Mobilite
			else if (etat == 2)
			{
				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					etat = 0;

				//TEST1
				if ((largeurFenetre() / 6 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre() / 2 - 25) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
				{
					etat = -1;
					test = 3;
					position = 1;
				}

				//TEST2
				if ((largeurFenetre() / 2 + 25 <= abscisseSouris()) && (abscisseSouris() <= 5 * largeurFenetre() / 6) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
				{
					etat = -1;
					test = 4;
					xBalle = abscisseSouris()-100;
					yBalle = ordonneeSouris()-50;
				}
			}

			//PAGE VISION
			else if (etat == 3)
			{
				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					etat = 0;

				//TEST1
				if ((largeurFenetre() / 6 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre() / 2 - 25) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
				{
					etat = -1;
					test = 5;
				}

				//TEST2
				if ((largeurFenetre() / 2 + 25 <= abscisseSouris()) && (abscisseSouris() <= 5 * largeurFenetre() / 6) && (hauteurFenetre() / 2 - 50 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 2 + 50))
				{
					etat = -1;
					test = 6;
				}
			}

			//MEMOIRE 1
			if (test == 1)
			{
				
				if(user1 == 1)
				{
				//RECOMMENCER
			
				if ((largeurFenetre()/2 - 105 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2 + 105) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9)) 					{

						carte1_1 = 0;
						carte1_2 = 0;
						carte2_1 = 0;
						carte2_2 = 0;
						carte3_1 = 0;
						carte3_2 = 0;
						carte4_1 = 0;
						carte4_2 = 0;
						carte5_1 = 0;
						carte5_2 = 0;

						paire1 = 0;
						paire2 = 0;
						paire3 = 0;
						paire4 = 0;
						paire5 = 0;

						cptclic = 0;
						cptclic2_1=0;
				}





				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 1;
					test = 0;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

					paire1 = 0;
					paire2 = 0;
					paire3 = 0;
					paire4 = 0;
					paire5 = 0;
					cptclic = 0;
				}

				if ((50 <= abscisseSouris()) && (abscisseSouris() <= 150) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
					{

						cptclic++;
						cptclic2_1++;

						carte1_1 = 1;
						carte2_1 = 0;
						carte2_2 = 0;
						carte3_1 = 0;
						carte3_2 = 0;
						carte4_1 = 0;
						carte4_2 = 0;
						carte5_1 = 0;
						carte5_2 = 0;

					}

				if ((50 <= abscisseSouris()) && (abscisseSouris() <= 150) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_1++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 1;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((200 <= abscisseSouris()) && (abscisseSouris() <= 300) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_1++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 1;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((200 <= abscisseSouris()) && (abscisseSouris() <= 300) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{

					cptclic++;
					cptclic2_1++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 1;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((350 <= abscisseSouris()) && (abscisseSouris() <= 450) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_1++;
					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 1;

				}
				if ((350 <= abscisseSouris()) && (abscisseSouris() <= 450) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_1++;

					carte1_2 = 1;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;
				}
				if ((500 <= abscisseSouris()) && (abscisseSouris() <= 600) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_1++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_2 = 1;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((500 <= abscisseSouris()) && (abscisseSouris() <= 600) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_1++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_2 = 1;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((650 <= abscisseSouris()) && (abscisseSouris() <= 750) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_1++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_2 = 1;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((650 <= abscisseSouris()) && (abscisseSouris() <= 750) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_1++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_2 = 1;

				}
				}
				if(user2 == 1)
				{
				//RECOMMENCER
			
				if ((largeurFenetre()/2 - 105 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2 + 105) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9)) 					{

						carte1_1 = 0;
						carte1_2 = 0;
						carte2_1 = 0;
						carte2_2 = 0;
						carte3_1 = 0;
						carte3_2 = 0;
						carte4_1 = 0;
						carte4_2 = 0;
						carte5_1 = 0;
						carte5_2 = 0;

						paire1 = 0;
						paire2 = 0;
						paire3 = 0;
						paire4 = 0;
						paire5 = 0;

						cptclic = 0;
						cptclic2_2=0;
				}





				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 1;
					test = 0;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

					paire1 = 0;
					paire2 = 0;
					paire3 = 0;
					paire4 = 0;
					paire5 = 0;
					cptclic = 0;
				}

				if ((50 <= abscisseSouris()) && (abscisseSouris() <= 150) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
					{

						cptclic++;
						cptclic2_2++;

						carte1_1 = 1;
						carte2_1 = 0;
						carte2_2 = 0;
						carte3_1 = 0;
						carte3_2 = 0;
						carte4_1 = 0;
						carte4_2 = 0;
						carte5_1 = 0;
						carte5_2 = 0;

					}

				if ((50 <= abscisseSouris()) && (abscisseSouris() <= 150) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_2++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 1;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((200 <= abscisseSouris()) && (abscisseSouris() <= 300) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_2++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 1;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((200 <= abscisseSouris()) && (abscisseSouris() <= 300) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{

					cptclic++;
					cptclic2_2++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 1;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((350 <= abscisseSouris()) && (abscisseSouris() <= 450) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_2++;
					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 1;

				}
				if ((350 <= abscisseSouris()) && (abscisseSouris() <= 450) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_2++;

					carte1_2 = 1;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;
				}
				if ((500 <= abscisseSouris()) && (abscisseSouris() <= 600) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_2++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_2 = 1;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((500 <= abscisseSouris()) && (abscisseSouris() <= 600) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_2++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_2 = 1;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((650 <= abscisseSouris()) && (abscisseSouris() <= 750) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_2++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_2 = 1;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((650 <= abscisseSouris()) && (abscisseSouris() <= 750) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_2++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_2 = 1;

				}
				}
				if(user3 == 1)
				{
				//RECOMMENCER
			
				if ((largeurFenetre()/2 - 105 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2 + 105) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9)) 					{

						carte1_1 = 0;
						carte1_2 = 0;
						carte2_1 = 0;
						carte2_2 = 0;
						carte3_1 = 0;
						carte3_2 = 0;
						carte4_1 = 0;
						carte4_2 = 0;
						carte5_1 = 0;
						carte5_2 = 0;

						paire1 = 0;
						paire2 = 0;
						paire3 = 0;
						paire4 = 0;
						paire5 = 0;

						cptclic = 0;
						cptclic2_3=0;
				}





				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 1;
					test = 0;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

					paire1 = 0;
					paire2 = 0;
					paire3 = 0;
					paire4 = 0;
					paire5 = 0;
					cptclic = 0;
				}

				if ((50 <= abscisseSouris()) && (abscisseSouris() <= 150) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
					{

						cptclic++;
						cptclic2_3++;

						carte1_1 = 1;
						carte2_1 = 0;
						carte2_2 = 0;
						carte3_1 = 0;
						carte3_2 = 0;
						carte4_1 = 0;
						carte4_2 = 0;
						carte5_1 = 0;
						carte5_2 = 0;

					}

				if ((50 <= abscisseSouris()) && (abscisseSouris() <= 150) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_3++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 1;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((200 <= abscisseSouris()) && (abscisseSouris() <= 300) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_3++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 1;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((200 <= abscisseSouris()) && (abscisseSouris() <= 300) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{

					cptclic++;
					cptclic2_3++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 1;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((350 <= abscisseSouris()) && (abscisseSouris() <= 450) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_3++;
					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 1;

				}
				if ((350 <= abscisseSouris()) && (abscisseSouris() <= 450) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_3++;

					carte1_2 = 1;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;
				}
				if ((500 <= abscisseSouris()) && (abscisseSouris() <= 600) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_3++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_2 = 1;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((500 <= abscisseSouris()) && (abscisseSouris() <= 600) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_3++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_2 = 1;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((650 <= abscisseSouris()) && (abscisseSouris() <= 750) && (350 <= ordonneeSouris()) && (ordonneeSouris() <= 500))
				{
					cptclic++;
					cptclic2_3++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_2 = 1;
					carte5_1 = 0;
					carte5_2 = 0;

				}
				if ((650 <= abscisseSouris()) && (abscisseSouris() <= 750) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 250))
				{
					cptclic++;
					cptclic2_3++;

					carte1_1 = 0;
					carte1_2 = 0;
					carte2_1 = 0;
					carte2_1 = 0;
					carte2_2 = 0;
					carte3_1 = 0;
					carte3_2 = 0;
					carte4_1 = 0;
					carte4_2 = 0;
					carte5_2 = 1;

				}
				}
			}

			//MEMOIRE 2
			if (test == 2)
			{
				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 1;
					test = 0;
				}
//COMMENCER
				
				if ((largeurFenetre()/2 - 105 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2 +105) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 365))
				{
					etat = -1;
					test = -1;
					mots = 1;
					if( user1 == 1);
					{
					mot1_1 = 0;
					mot2_1 = 0;
					mot3_1 = 0;
					mot4_1 = 0;
					mot5_1 = 0;
					}
					if( user2 == 1);
					{
					mot1_2 = 0;
					mot2_2 = 0;
					mot3_2 = 0;
					mot4_2 = 0;
					mot5_2 = 0;
					}
					if( user3 == 1);
					{
					mot1_3 = 0;
					mot2_3 = 0;
					mot3_3 = 0;
					mot4_3 = 0;
					mot5_3 = 0;
					}
				}


			}
		if ( user1 == 1)
		{
			if ( mots == 1)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots = 0;
						test = 2;
					}
				}
			if ( mots == 2 || mots == 3 || mots == 4 || mots == 5 || mots == 6 || mots ==7)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots = 0;
						test = 2;
					}



			// FAUX
			if ((largeurFenetre()/8+5 <= abscisseSouris()) && (abscisseSouris() <= 2*largeurFenetre()/8+15) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((4*largeurFenetre()/8+65 <= abscisseSouris()) && (abscisseSouris() <= 5*largeurFenetre()/8+75) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((5*largeurFenetre()/8+85 <= abscisseSouris()) && (abscisseSouris() <= 6*largeurFenetre()/8+95) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((largeurFenetre()/8+5 <= abscisseSouris()) && (abscisseSouris() <= 2*largeurFenetre()/8+15) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((3*largeurFenetre()/8+45 <= abscisseSouris()) && (abscisseSouris() <= 4*largeurFenetre()/8+55) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						etat = -1;
						mots=0;
						test = 2;
					}

			//VRAI
			if ((2*largeurFenetre()/8+25 <= abscisseSouris()) && (abscisseSouris() <= 3*largeurFenetre()/8+35) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						mots=3;
						mot1_1 = 1;
					}
			if ((3*largeurFenetre()/8+45 <= abscisseSouris()) && (abscisseSouris() <= 4*largeurFenetre()/8+55) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						mots = 4;
						mot2_1 = 2;
					}
			if ((2*largeurFenetre()/8+25 <= abscisseSouris()) && (abscisseSouris() <= 3*largeurFenetre()/8+35) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 5;
						mot3_1 = 1;
					}
			if ((4*largeurFenetre()/8+65 <= abscisseSouris()) && (abscisseSouris() <= 5*largeurFenetre()/8+75) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 6;
						mot4_1 = 1;
					}
			if ((5*largeurFenetre()/8+85 <= abscisseSouris()) && (abscisseSouris() <= 6*largeurFenetre()/8+95) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 7;
						mot5_1 = 1;
					}


				}
			if ( mots == 3)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
				}
		}
		if ( user2 == 1)
		{
			if ( mots == 1)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots = 0;
						test = 2;
					}
				}
			if ( mots == 2 || mots == 3 || mots == 4 || mots == 5 || mots == 6 || mots ==7)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots = 0;
						test = 2;
					}



			// FAUX
			if ((largeurFenetre()/8+5 <= abscisseSouris()) && (abscisseSouris() <= 2*largeurFenetre()/8+15) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((4*largeurFenetre()/8+65 <= abscisseSouris()) && (abscisseSouris() <= 5*largeurFenetre()/8+75) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((5*largeurFenetre()/8+85 <= abscisseSouris()) && (abscisseSouris() <= 6*largeurFenetre()/8+95) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((largeurFenetre()/8+5 <= abscisseSouris()) && (abscisseSouris() <= 2*largeurFenetre()/8+15) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((3*largeurFenetre()/8+45 <= abscisseSouris()) && (abscisseSouris() <= 4*largeurFenetre()/8+55) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						etat = -1;
						mots=0;
						test = 2;
					}

			//VRAI
			if ((2*largeurFenetre()/8+25 <= abscisseSouris()) && (abscisseSouris() <= 3*largeurFenetre()/8+35) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						mots=3;
						mot1_2 = 1;
					}
			if ((3*largeurFenetre()/8+45 <= abscisseSouris()) && (abscisseSouris() <= 4*largeurFenetre()/8+55) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						mots = 4;
						mot2_2 = 2;
					}
			if ((2*largeurFenetre()/8+25 <= abscisseSouris()) && (abscisseSouris() <= 3*largeurFenetre()/8+35) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 5;
						mot3_2 = 1;
					}
			if ((4*largeurFenetre()/8+65 <= abscisseSouris()) && (abscisseSouris() <= 5*largeurFenetre()/8+75) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 6;
						mot4_2 = 1;
					}
			if ((5*largeurFenetre()/8+85 <= abscisseSouris()) && (abscisseSouris() <= 6*largeurFenetre()/8+95) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 7;
						mot5_2 = 1;
					}


				}
			if ( mots == 3)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
				}
		}
		if ( user3 == 1)
		{
			if ( mots == 1)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots = 0;
						test = 2;
					}
				}
			if ( mots == 2 || mots == 3 || mots == 4 || mots == 5 || mots == 6 || mots ==7)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots = 0;
						test = 2;
					}



			// FAUX
			if ((largeurFenetre()/8+5 <= abscisseSouris()) && (abscisseSouris() <= 2*largeurFenetre()/8+15) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((4*largeurFenetre()/8+65 <= abscisseSouris()) && (abscisseSouris() <= 5*largeurFenetre()/8+75) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((5*largeurFenetre()/8+85 <= abscisseSouris()) && (abscisseSouris() <= 6*largeurFenetre()/8+95) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((largeurFenetre()/8+5 <= abscisseSouris()) && (abscisseSouris() <= 2*largeurFenetre()/8+15) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
			if ((3*largeurFenetre()/8+45 <= abscisseSouris()) && (abscisseSouris() <= 4*largeurFenetre()/8+55) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						etat = -1;
						mots=0;
						test = 2;
					}

			//VRAI
			if ((2*largeurFenetre()/8+25 <= abscisseSouris()) && (abscisseSouris() <= 3*largeurFenetre()/8+35) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						mots=3;
						mot1_3 = 1;
					}
			if ((3*largeurFenetre()/8+45 <= abscisseSouris()) && (abscisseSouris() <= 4*largeurFenetre()/8+55) && (305 <= ordonneeSouris()) && (ordonneeSouris() <= 395))
					{
						mots = 4;
						mot2_3 = 2;
					}
			if ((2*largeurFenetre()/8+25 <= abscisseSouris()) && (abscisseSouris() <= 3*largeurFenetre()/8+35) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 5;
						mot3_3 = 1;
					}
			if ((4*largeurFenetre()/8+65 <= abscisseSouris()) && (abscisseSouris() <= 5*largeurFenetre()/8+75) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 6;
						mot4_3 = 1;
					}
			if ((5*largeurFenetre()/8+85 <= abscisseSouris()) && (abscisseSouris() <= 6*largeurFenetre()/8+95) && (205 <= ordonneeSouris()) && (ordonneeSouris() <= 295))
					{
						mots = 7;
						mot5_3 = 1;
					}


				}
			if ( mots == 3)
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = -1;
						mots=0;
						test = 2;
					}
				}
		}
			//Mobilite 1
			if (test == 3)
			{

				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 2;
					test = 0;
					position = 0;
				}

				if ((0 <= abscisseSouris()) && (abscisseSouris() <=  largeurFenetre()/8) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					position = 2;
					laby_1 = 0;
					laby_2=0;
					laby_3=0;
				}

			}
			//Mobilite 2
			if (test == 4)
			{
				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					boule_1 = 0;
					boule_2 = 0;
					boule_3 = 0;
					etat = 2;
					test = 0;
				}
			}

			//VISION 1
			if (test == 5)
			{
				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 3;
					test = 0;
				}
				//Choix réponse
				if ((500 <= abscisseSouris()) && (abscisseSouris() <= 600) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 200))
				{
					vision1 = 1;
				}
				if(vision1 == 1 )
				{
					if ((350 <= abscisseSouris()) && (abscisseSouris() <= 450) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 200))
					{
						vision1_1 = 1;
						vision1 =0;
					}
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = 3;
						test = 0;
						vision1 = 0;
						vision1_2 = 0;
						vision1_1 = 0;
					}
				}

				if (vision1_1 == 1)
				{
					if ((500 <= abscisseSouris()) && (abscisseSouris() <= 600) && (100 <= ordonneeSouris()) && (ordonneeSouris() <= 200))
					{
						vision1_2 = 1;
					}



					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = 3;
						test = 0;
						vision1 = 0;
						vision1_2 = 0;
						vision1_1 = 0;
					}
				}

				if(vision1_2 == 1 )
				{

					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = 3;
						test = 0;
						vision1 = 0;
						vision1_2 = 0;
						vision1_1 = 0;
					}

				}
			}

			//VISION 2
			if (test == 6)
			{
				//RETOUR
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 3;
					test = 0;
					vision2 = 0;

				}
				//Choix réponse
				if ((550 <= abscisseSouris()) && (abscisseSouris() <= 650) && (50 <= ordonneeSouris()) && (ordonneeSouris() <= 150))
				{
					vision2 = 1;
				}
				if(vision2 == 1 )
					if ((400 <= abscisseSouris()) && (abscisseSouris() <= 500) && (50 <= ordonneeSouris()) && (ordonneeSouris() <= 150))
					{
						vision2_1 = 1;
						vision2 =0;

					}

				if (vision2_1 == 1)
				{
					if ((250 <= abscisseSouris()) && (abscisseSouris() <= 350) && (50 <= ordonneeSouris()) && (ordonneeSouris() <= 150))
					{
						vision2_2 = 1;

					}
				}
				if(vision2_1 == 1 )
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = 3;
						test = 0;
						vision2 = 0;
						vision2_2 = 0;
						vision2_1 = 0;
					}

				}
				if(vision2_2 == 1 )
				{
					if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					{
						etat = 3;
						test = 0;
						vision2 = 0;
						vision2_2 = 0;
						vision2_1 = 0;
					}

				}
			}


			//CREDIT RETOUR
			else if (etat == 4)
			{
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
				{
					etat = 0;
				}
			}
			//RESULTAT RETOUR
			else if (etat == 5)
			{
				if ((largeurFenetre() - 125 <= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (0 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre() / 9))
					etat = 0;

			}
		}




		break;

	case Souris:


// LABY
	if(position == 2)
	{
		if ((0<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && (hauteurFenetre()-100 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()))
		{
			position = 1;
			abscisseSouris();
			ordonneeSouris();
			printf("abscisse %d", sAbscisseSouris );
			printf("ordonnée %d",sOrdonneeSouris );
		}
		if(user1 == 1)
	{
		if ((largeurFenetre()/8<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+50) && (0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-175))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+50<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+240) && (0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/5))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+100<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+200) && ( hauteurFenetre()/5+50 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+240<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+280) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-140))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+280<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+380) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/10))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+315<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+350) && ( hauteurFenetre()/10+40 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_1 = 0;
		}

		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+270) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2-100))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+430<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+480) && ( hauteurFenetre()/2+70 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+410) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-130))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && ( hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2+50))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+150) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2+50))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+270) && ( hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()-120))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+330) && (hauteurFenetre()/2+120 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()-120))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && (hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()/2+60))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/2+170<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2-80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-30))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/2+350<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2+80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/2+290<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2+80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2+100))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/2+360<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/2+360<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-30))
		{
			position = 0;
			laby_1 = 0;
		}
		if ((largeurFenetre()/2+270<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-150))
		{
			position = 0;
			laby_1 = 0;
		}
		// GAGNER
		if ((largeurFenetre()/2+270<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && (hauteurFenetre()/2-150 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2-100))
		{
			laby_1 = 1;
			position = 0;
		}
	}
	
	if(user2 == 1)
	{
		if ((largeurFenetre()/8<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+50) && (0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-175))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+50<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+240) && (0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/5))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+100<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+200) && ( hauteurFenetre()/5+50 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+240<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+280) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-140))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+280<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+380) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/10))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+315<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+350) && ( hauteurFenetre()/10+40 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_2 = 0;
		}

		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+270) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2-100))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+430<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+480) && ( hauteurFenetre()/2+70 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+410) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-130))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && ( hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2+50))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+150) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2+50))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+270) && ( hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()-120))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+330) && (hauteurFenetre()/2+120 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()-120))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && (hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()/2+60))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/2+170<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2-80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-30))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/2+350<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2+80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/2+290<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2+80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2+100))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/2+360<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/2+360<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-30))
		{
			position = 0;
			laby_2 = 0;
		}
		if ((largeurFenetre()/2+270<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-150))
		{
			position = 0;
			laby_2 = 0;
		}
		// GAGNER
		if ((largeurFenetre()/2+270<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && (hauteurFenetre()/2-150 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2-100))
		{
			laby_2 = 1;
			position = 0;
		}
	}
	
		if(user3 == 1)
	{
		if ((largeurFenetre()/8<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+50) && (0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-175))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+50<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+240) && (0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/5))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+100<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+200) && ( hauteurFenetre()/5+50 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+240<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+280) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-140))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+280<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+380) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/10))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+315<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+350) && ( hauteurFenetre()/10+40 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_3 = 0;
		}

		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+270) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2-100))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+430<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+480) && ( hauteurFenetre()/2+70 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/8+410) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()-130))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && ( hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2+50))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+380<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+150) && ( 0 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2+50))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+270) && ( hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()-120))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+330) && (hauteurFenetre()/2+120 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()-120))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/8+500<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && (hauteurFenetre()/2-10 <= ordonneeSouris()) && (ordonneeSouris() <= hauteurFenetre()/2+60))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/2+170<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2-80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-30))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/2+350<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2+80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/2+290<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/2+80 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2+100))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/2+360<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/2+360<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-30))
		{
			position = 0;
			laby_3 = 0;
		}
		if ((largeurFenetre()/2+270<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()) && hauteurFenetre()/9 <= ordonneeSouris() && (ordonneeSouris() <=hauteurFenetre()/2-150))
		{
			position = 0;
			laby_3 = 0;
		}
		// GAGNER
		if ((largeurFenetre()/2+270<= abscisseSouris()) && (abscisseSouris() <= largeurFenetre()/2+340) && (hauteurFenetre()/2-150 <= ordonneeSouris()) && (ordonneeSouris() <=  hauteurFenetre()/2-100))
		{
			laby_3 = 1;
			position = 0;
		}
	}
	
	}
	
	//BALLE
	if (test == 4 )
	{
		if( user1 == 1)
		{
		if ((xBalle -20<= abscisseSouris()) && (abscisseSouris() <= xBalle +20) && (yBalle -20 <= ordonneeSouris()) && (ordonneeSouris() <= yBalle +20))
		{
		/*
		METTRE UN TIMER A LA PLACE DE SLEEP
		*/

			sleep(2);
			test = 0;
			etat = 2;
			boule_1 = 1;

		}
		else
		{
			boule_1 = 0;
			etat =2;
			test = 0;
		}
		}
		if( user2 == 1)
		{
		if ((xBalle -20<= abscisseSouris()) && (abscisseSouris() <= xBalle +20) && (yBalle -20 <= ordonneeSouris()) && (ordonneeSouris() <= yBalle +20))
		{
		/*
		METTRE UN TIMER A LA PLACE DE SLEEP
		*/

			sleep(2);
			test = 0;
			etat = 2;
			boule_2 = 1;

		}
		else
		{
			boule_2 = 0;
			etat =2;
			test = 0;
		}
		}
		if( user3 == 1)
		{
		if ((xBalle -20<= abscisseSouris()) && (abscisseSouris() <= xBalle +20) && (yBalle -20 <= ordonneeSouris()) && (ordonneeSouris() <= yBalle +20))
		{
		/*
		METTRE UN TIMER A LA PLACE DE SLEEP
		*/

			sleep(2);
			test = 0;
			etat = 2;
			boule_3 = 1;

		}
		else
		{
			boule_3 = 0;
			etat =2;
			test = 0;
		}
		}
	}




	rafraichisFenetre();
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		if (xBalle >= largeurFenetre())
				xBalle = largeurFenetre()-1;
			if (yBalle >= hauteurFenetre())
				yBalle = hauteurFenetre()-1;
		printf("Largeur : %d\t", largeurFenetre());
		printf("Hauteur : %d\n", hauteurFenetre());
		break;
	}
}

void PageDemarrage()
{

	couleurCourante(0,0,0);
	rectangle(50,100,750,500);
	couleurCourante(255, 255, 255);
	rectangle(55,105,745,495);

	couleurCourante(0,0,0);
	rectangle(100,320,700,420);
	couleurCourante(200, 200, 200);
	rectangle(105,325,695,415);
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("I N S C R I P T I O N", 35, 140, 350);

	couleurCourante(0,0,0);
	rectangle(100,200,700,300);
	couleurCourante(200, 200, 200);
	rectangle(105,205,695,295);
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("C O N N E X I O N", 35, 180, 230);



	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);					   // QUITTER
	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9);						   // QUITTER


	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("QUITTER", 18, largeurFenetre() - 110, 25);

	couleurCourante(255, 0, 0); // Couleur en jaune
	epaisseurDeTrait(5);
	afficheChaine("EVALUATION COGNITIVE", 36, largeurFenetre() / 5,hauteurFenetre() - 45);

}


void PageInscription()
{

	couleurCourante(0,0,0);
	rectangle(50,100,750,500);
	couleurCourante(255, 255, 255);
	rectangle(55,105,745,495);


	couleurCourante(0,0,0);
	rectangle(100,240,700,340);
	couleurCourante(200, 200, 200);
	rectangle(105,245,695,335);
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);

	if ( fill_step == 0)
{
	afficheChaine("Nom:", 35, 200, 270);
	afficheChaine(newuser.Nom, 35, 340, 270);
}
else if (fill_step == 1)
{

	afficheChaine("Prenom:", 35, 200, 270);
	afficheChaine(newuser.prenom, 35, 360, 270);

}
else if( fill_step == 2)
{
	afficheChaine("Age:", 35, 200, 270);
	afficheChaine(newuser.age, 35, 340, 270);
	//=0;
}
	else if(fill_step == 3)
{

	Repertoire1 = fopen("./DATABASE/Utilisateur1.txt" , "a");
	Repertoire2 = fopen("./DATABASE/Utilisateur2.txt" , "a");
	Repertoire3 = fopen("./DATABASE/Utilisateur3.txt" , "a");

	if (redondence == 0)
	{
	fprintf(Repertoire1,"\n\nNom: %s\n",newuser.Nom);
	fprintf(Repertoire1,"Prenom: %s\n",newuser.prenom);
	fprintf(Repertoire1,"Age: %s\n",newuser.age);
	redondence++;
	}
	else if (redondence == 1)
	{
	fprintf(Repertoire2,"\n\nNom: %s\n",newuser.Nom);
	fprintf(Repertoire2,"Prenom: %s\n",newuser.prenom);
	fprintf(Repertoire2,"Age: %s\n",newuser.age);
	redondence++;
	}
	else if (redondence == 2)
	{
	fprintf(Repertoire3,"\n\nNom: %s\n",newuser.Nom);
	fprintf(Repertoire3,"Prenom: %s\n",newuser.prenom);
	fprintf(Repertoire3,"Age: %s\n",newuser.age);
	redondence=0;
	}
	//individu[i].Nom = newuser.Nom;
	//strcpy(individu[i].Nom, newuser.Nom);


	//individu[i].database = fopen(individu[i].Nom,"a");

	int j;
	for(j=0;j<20;j++)
	newuser.Nom[j] = ' ';
	//individu[i].prenom = newuser.prenom;
	strcpy(individu[i].prenom, newuser.prenom);
	for(j=0;j<20;j++)
	newuser.prenom [j] = ' ';
	//individu[i].age = newuser.age;
	strcpy(individu[i].age, newuser.age);
	for(j=0;j<2;j++)
	newuser.age[j] = ' ';


	fclose(Repertoire1);
	fclose(Repertoire2);
	fclose(Repertoire3);
	i++;
	fill_step = 0;
}




	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);										   // QUITTER
	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9);										   // QUITTER

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);

	couleurCourante(255, 0, 0); // Couleur en jaune
	epaisseurDeTrait(5);
	afficheChaine("INSCRIPTION", 36, largeurFenetre() / 5 + 120,hauteurFenetre() - 45);


}


void PageConnexion()
{

	couleurCourante(0,0,0);
	rectangle(50,100,750,500);
	couleurCourante(255, 255, 255);
	rectangle(55,105,745,495);


	couleurCourante(0,0,0);
	rectangle(100,350,700,450);
	couleurCourante(200, 200, 200);
	rectangle(105,355,695,445);
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine(individu[0].Nom, 35, 170, 380);
	afficheChaine(individu[0].prenom, 35, 380, 380);


	couleurCourante(0,0,0);
	rectangle(100,240,700,340);
	couleurCourante(200, 200, 200);
	rectangle(105,245,695,335);
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine(individu[1].Nom, 35, 170, 270);
	afficheChaine(individu[1].prenom, 35, 380, 270);

	couleurCourante(0,0,0);
	rectangle(100,130,700,230);
	couleurCourante(200, 200, 200);
	rectangle(105,135,695,225);
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine(individu[2].Nom, 35, 170, 160);
	afficheChaine(individu[2].prenom, 35, 380, 160);

	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);										   // QUITTER
	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9);										   // QUITTER

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);

	couleurCourante(0,0,0);
	rectangle(largeurFenetre()/2 - 100, 0, largeurFenetre()/2 + 100, hauteurFenetre() / 9 + 5);										   // CONTINUER
	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/2 - 95, 0, largeurFenetre()/2 + 95, hauteurFenetre() / 9);										   // CONTINUER

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("CONTINUER", 18, largeurFenetre()/2 - 55 , 25);


	couleurCourante(255, 0, 0); // Couleur en jaune
	epaisseurDeTrait(5);
	afficheChaine("CONNEXION", 36, largeurFenetre() / 5 + 120,hauteurFenetre() - 45);

}


void PageAccueil()
{
	couleurCourante(0,0,0);
	rectangle(50,100,750,500);
	couleurCourante(200, 200, 200);
	rectangle(55,105,745,495);

	couleurCourante(0,0,0);
	rectangle(largeurFenetre() / 8 - 30, hauteurFenetre() / 2 - 55, largeurFenetre() / 4 + 30, hauteurFenetre() / 2 + 55); //MEMOIRE
	rectangle(largeurFenetre() / 4 + 90, hauteurFenetre() / 2 - 55, largeurFenetre() / 2 + 100, hauteurFenetre() / 2 + 55); //Mobilite
	rectangle(largeurFenetre() / 2 + 170, hauteurFenetre() / 2 - 55, largeurFenetre() - 70, hauteurFenetre() / 2 + 55);	   //VISION
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);										   // QUITTER
	rectangle(largeurFenetre()-155, hauteurFenetre()-50, largeurFenetre(), hauteurFenetre() );							   // RESULTAT
	rectangle(0, 0, 130, hauteurFenetre() / 10 + 5);							   // CREDIT

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() / 8 - 25, hauteurFenetre() / 2 - 50, largeurFenetre() / 4 + 25, hauteurFenetre() / 2 + 50); //MEMOIRE
	rectangle(largeurFenetre() / 4 + 95, hauteurFenetre() / 2 - 50, largeurFenetre() / 2 + 95, hauteurFenetre() / 2 + 50); //Mobilite
	rectangle(largeurFenetre() / 2 + 175, hauteurFenetre() / 2 - 50, largeurFenetre() - 75, hauteurFenetre() / 2 + 50);	   //VISION
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9);										   // QUITTER
	rectangle(largeurFenetre()-150, hauteurFenetre()-45, largeurFenetre(), hauteurFenetre() );							   // RESULTAT
	rectangle(0, 0, 125, hauteurFenetre() / 10);							   // CREDIT

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("QUITTER", 18, largeurFenetre() - 110, 25);
	afficheChaine("MEMOIRE", 18, largeurFenetre() / 8 + 5, hauteurFenetre() / 2 - 10);
	afficheChaine("MOBILITE", 18, largeurFenetre() / 2 - 45, hauteurFenetre() / 2 - 10);
	afficheChaine("VISION", 18, largeurFenetre() / 2 + 220, hauteurFenetre() / 2 - 10);
	afficheChaine("RESULTAT", 18, 675, 570);
	afficheChaine("CREDIT", 18, 30, 25);

	couleurCourante(255, 0, 0);
	epaisseurDeTrait(5);
	afficheChaine("EVALUATION COGNITIVE", 36, largeurFenetre() / 5, 2 * hauteurFenetre() / 3);
}

void PageAccueilCredit()
{
	couleurCourante(0,0,0);
	rectangle(95,50,705,500);

	couleurCourante(200, 200, 200); // Couleur gris
	rectangle(100, 55, 700, 495);
	couleurCourante(0,0,0);
	rectangle(250,400,550,480);
	rectangle(250,290,550,370);
	rectangle(250,180,550,260);
	rectangle(250,70,550,150);

	couleurCourante(255,255,255);
	rectangle(255,405,545,475);
	rectangle(255,295,545,365);
	rectangle(255,185,545,255);
	rectangle(255,75,545,145);

	couleurCourante(0,0,0);
	rectangle(670,0,800,hauteurFenetre()/9 +5);
	couleurCourante(255, 255, 255);
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("MEHDI DUPONT", 18, 320,430);
	afficheChaine("ADNEN KADDOURI", 18,  320, 320);
	afficheChaine("LOAN COSSON", 18,  320, 210);
	afficheChaine("CLEMENT CHARABOT", 18,  320, 100);
	couleurCourante(255, 0, 0);
	epaisseurDeTrait(5);
	afficheChaine("CREDIT", 36, 330, 530);
}

void PageAccueilResultat()
{
	couleurCourante(0,0,0);
	rectangle(50,100,750,500);
	couleurCourante(200, 200, 200);
	rectangle(55,105,745,495);

	couleurCourante(0,0,0);
	rectangle(largeurFenetre() / 8 - 30, 110, largeurFenetre() / 4 + 40, hauteurFenetre() / 2 + 120); //MEMOIRE
	rectangle(largeurFenetre() / 4 + 100, 110, largeurFenetre() / 2 + 90, hauteurFenetre() / 2 + 120); //Mobilite
	rectangle(largeurFenetre() / 2 + 160, 110, largeurFenetre() - 70, hauteurFenetre() / 2 + 120);	   //VISION

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() / 8 - 25, 115, largeurFenetre() / 4 + 35, hauteurFenetre() / 2 + 115); //MEMOIRE
	rectangle(largeurFenetre() / 4 + 105, 115, largeurFenetre() / 2 + 85, hauteurFenetre() / 2 + 115); //Mobilite
	rectangle(largeurFenetre() / 2 + 165, 115, largeurFenetre() - 75, hauteurFenetre() / 2 + 115);	   //VISION

	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	couleurCourante(255, 255, 255);
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // QUITTER

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("MEMOIRE", 25, largeurFenetre() / 8 + 5, 450);
	afficheChaine("MOBILITE", 25, largeurFenetre() / 2 - 45, 450);
	afficheChaine("VISION", 25, largeurFenetre() / 2 + 200,450);
	afficheChaine("TEST 1", 25, largeurFenetre() / 8 + 5, 350);
	afficheChaine("TEST 1", 25, largeurFenetre() / 2 - 45, 350);
	afficheChaine("TEST 1", 25, largeurFenetre() / 2 + 200,350);
	afficheChaine("TEST 2", 25, largeurFenetre() / 8 + 5, 220);
	afficheChaine("TEST 2", 25, largeurFenetre() / 2 - 45, 220);
	afficheChaine("TEST 2", 25, largeurFenetre() / 2 + 200,220);

	couleurCourante(255, 0, 0);
	epaisseurDeTrait(5);
	afficheChaine("RESULTAT", 36, 330, 530);
}

void PageMemoire() //PAGE MEMOIRE
{

	couleurCourante(0, 0, 0);																							  // Couleur en noir
	rectangle(largeurFenetre() / 6 - 5, hauteurFenetre() / 2 - 55, largeurFenetre() / 2 - 20, hauteurFenetre() / 2 + 55);	  //TEST 1
	rectangle(largeurFenetre() / 2 + 20, hauteurFenetre() / 2 - 55, 5 * largeurFenetre() / 6 + 5, hauteurFenetre() / 2 + 55); //TEST 2
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);										  // RETOUR


	couleurCourante(255, 255, 255); // Couleur blanc

	rectangle(largeurFenetre() / 6, hauteurFenetre() / 2 - 50, largeurFenetre() / 2 - 25, hauteurFenetre() / 2 + 50);	  //TEST 1
	rectangle(largeurFenetre() / 2 + 25, hauteurFenetre() / 2 - 50, 5 * largeurFenetre() / 6, hauteurFenetre() / 2 + 50); //TEST 2
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9);										  // RETOUR
	couleurCourante(0, 0, 0);																							  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 1", 18, largeurFenetre() / 6 + 70, hauteurFenetre() / 2 - 10);
	afficheChaine("TEST 2", 18, largeurFenetre() / 2 + 100, hauteurFenetre() / 2 - 10);
	epaisseurDeTrait(1);
	afficheChaine("Trouver les paires. ", 20, largeurFenetre() / 6 + 10, hauteurFenetre() / 2 - 80);
	afficheChaine("Essayer de retrouver ", 20, largeurFenetre() / 2 + 50, hauteurFenetre() / 2 - 80);
	afficheChaine("les mots ", 20, largeurFenetre() / 2 + 50, hauteurFenetre() / 2 - 105);


	couleurCourante(255, 0, 0); // Couleur en rouge
	epaisseurDeTrait(5);
	afficheChaine("MEMOIRE", 36, largeurFenetre() / 3 + 50, 2 * hauteurFenetre() / 3 + 50);
}

void PageMemoireTest1() //PAGE MEMORY
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	rectangle(largeurFenetre()/2 - 110, 0, largeurFenetre()/2 + 110, hauteurFenetre() / 9 + 5);


	couleurCourante(255, 255, 255);												  // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	rectangle(largeurFenetre()/2 - 105, 0, largeurFenetre()/2 + 105, hauteurFenetre() / 9 ); //RECOMMENCER

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("MEMORY",24,largeurFenetre()/2-50,hauteurFenetre()-50);
	afficheChaine("RECOMMENCER",24,largeurFenetre()/2-95,25);

}



void PageMemoireTest2() //PAGE MEMORY 2
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre()/2-110, 300, largeurFenetre() / 2 + 110, 370);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/2-105, 305, largeurFenetre() / 2 +105, 365);
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("MEMORY 2", 24,largeurFenetre()/2-50,hauteurFenetre()-50);
	afficheChaine("COMMENCER",24,largeurFenetre()/2-85,325);
}

void PageMemoireTest2_1() //PAGE MEMORY 2
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	rectangle(largeurFenetre()/8, 300, 2*largeurFenetre()/8+20, 400);
	rectangle(2*largeurFenetre()/8+20, 300, 3*largeurFenetre()/8+40, 400);
	rectangle(3*largeurFenetre()/8+40, 300, 4*largeurFenetre()/8+60, 400);
	rectangle(4*largeurFenetre()/8+60, 300, 5*largeurFenetre()/8+80, 400);
	rectangle(5*largeurFenetre()/8+80, 300, 6*largeurFenetre()/8+100, 400);
	rectangle(largeurFenetre()/8, 200, 2*largeurFenetre()/8+20, 300);
	rectangle(2*largeurFenetre()/8+20, 200, 3*largeurFenetre()/8+40, 300);
	rectangle(3*largeurFenetre()/8+40, 200, 4*largeurFenetre()/8+60, 300);
	rectangle(4*largeurFenetre()/8+60, 200, 5*largeurFenetre()/8+80, 300);
	rectangle(5*largeurFenetre()/8+80, 200, 6*largeurFenetre()/8+100, 300);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/8+5, 305, 2*largeurFenetre()/8+15, 395);
	rectangle(2*largeurFenetre()/8+25, 305, 3*largeurFenetre()/8+35, 395);
	rectangle(3*largeurFenetre()/8+45, 305, 4*largeurFenetre()/8+55, 395);
	rectangle(4*largeurFenetre()/8+65, 305, 5*largeurFenetre()/8+75, 395);
	rectangle(5*largeurFenetre()/8+85, 305, 6*largeurFenetre()/8+95, 395);
	rectangle(largeurFenetre()/8+5, 205, 2*largeurFenetre()/8+15, 295);
	rectangle(2*largeurFenetre()/8+25, 205, 3*largeurFenetre()/8+35, 295);
	rectangle(3*largeurFenetre()/8+45, 205, 4*largeurFenetre()/8+55, 295);
	rectangle(4*largeurFenetre()/8+65, 205, 5*largeurFenetre()/8+75, 295);
	rectangle(5*largeurFenetre()/8+85, 205, 6*largeurFenetre()/8+95, 295);
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 2", 24,largeurFenetre()/2-50,hauteurFenetre()-50);
	epaisseurDeTrait(1.5);
	afficheChaine("LUNETTES",18,largeurFenetre()/8+15,340);
	afficheChaine("MONTRE",18,2*largeurFenetre()/8+35,340);
	afficheChaine("CRAVATE",18,3*largeurFenetre()/8+55,340);
	afficheChaine("VALISE",18,4*largeurFenetre()/8+75,340);
	afficheChaine("OREILLER",18,5*largeurFenetre()/8+95,340);
	afficheChaine("TABLE",18,largeurFenetre()/8+15,240);
	afficheChaine("MIROIR",18,2*largeurFenetre()/8+35,240);
	afficheChaine("CLE",18,3*largeurFenetre()/8+55,240);
	afficheChaine("LIVRE",18,4*largeurFenetre()/8+75,240);
	afficheChaine("TASSE",18,5*largeurFenetre()/8+95,240);
	afficheChaine("RETROUVE LES 5 MOTS",40,160,100);
}

void PageMemoireTest2_2() //PAGE MEMOIRE
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	rectangle(largeurFenetre()/8, 300, 2*largeurFenetre()/8+20, 400);
	rectangle(2*largeurFenetre()/8+20, 300, 3*largeurFenetre()/8+40, 400);
	rectangle(3*largeurFenetre()/8+40, 300, 4*largeurFenetre()/8+60, 400);
	rectangle(4*largeurFenetre()/8+60, 300, 5*largeurFenetre()/8+80, 400);
	rectangle(5*largeurFenetre()/8+80, 300, 6*largeurFenetre()/8+100, 400);
	rectangle(largeurFenetre()/8, 200, 2*largeurFenetre()/8+20, 300);
	rectangle(2*largeurFenetre()/8+20, 200, 3*largeurFenetre()/8+40, 300);
	rectangle(3*largeurFenetre()/8+40, 200, 4*largeurFenetre()/8+60, 300);
	rectangle(4*largeurFenetre()/8+60, 200, 5*largeurFenetre()/8+80, 300);
	rectangle(5*largeurFenetre()/8+80, 200, 6*largeurFenetre()/8+100, 300);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/8+5, 305, 2*largeurFenetre()/8+15, 395);
	rectangle(2*largeurFenetre()/8+25, 305, 3*largeurFenetre()/8+35, 395);
	rectangle(3*largeurFenetre()/8+45, 305, 4*largeurFenetre()/8+55, 395);
	rectangle(4*largeurFenetre()/8+65, 305, 5*largeurFenetre()/8+75, 395);
	rectangle(5*largeurFenetre()/8+85, 305, 6*largeurFenetre()/8+95, 395);
	rectangle(largeurFenetre()/8+5, 205, 2*largeurFenetre()/8+15, 295);
	rectangle(2*largeurFenetre()/8+25, 205, 3*largeurFenetre()/8+35, 295);
	rectangle(3*largeurFenetre()/8+45, 205, 4*largeurFenetre()/8+55, 295);
	rectangle(4*largeurFenetre()/8+65, 205, 5*largeurFenetre()/8+75, 295);
	rectangle(5*largeurFenetre()/8+85, 205, 6*largeurFenetre()/8+95, 295);
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 2", 24,largeurFenetre()/2-50,hauteurFenetre()-50);
	epaisseurDeTrait(1.5);
	afficheChaine("PASSE",18,largeurFenetre()/8+15,340);
	afficheChaine("LIVRE",18,2*largeurFenetre()/8+35,340);
	afficheChaine("TABLE",18,3*largeurFenetre()/8+55,340);
	afficheChaine("IVRE",18,4*largeurFenetre()/8+75,340);
	afficheChaine("OREILLE",18,5*largeurFenetre()/8+95,340);
	afficheChaine("MABRE",18,largeurFenetre()/8+15,240);
	afficheChaine("VALISE",18,2*largeurFenetre()/8+35,240);
	afficheChaine("CHIEN",18,3*largeurFenetre()/8+55,240);
	afficheChaine("CRAVATE",18,4*largeurFenetre()/8+75,240);
	afficheChaine("MONTRE",18,5*largeurFenetre()/8+95,240);
	afficheChaine("RETROUVE LES 5 MOTS",40,160,100);

}
void PageMemoireTest2_3() //PAGE MEMOIRE
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	rectangle(largeurFenetre()/8, 300, 2*largeurFenetre()/8+20, 400);
	rectangle(2*largeurFenetre()/8+20, 300, 3*largeurFenetre()/8+40, 400);
	rectangle(3*largeurFenetre()/8+40, 300, 4*largeurFenetre()/8+60, 400);
	rectangle(4*largeurFenetre()/8+60, 300, 5*largeurFenetre()/8+80, 400);
	rectangle(5*largeurFenetre()/8+80, 300, 6*largeurFenetre()/8+100, 400);
	rectangle(largeurFenetre()/8, 200, 2*largeurFenetre()/8+20, 300);
	rectangle(2*largeurFenetre()/8+20, 200, 3*largeurFenetre()/8+40, 300);
	rectangle(3*largeurFenetre()/8+40, 200, 4*largeurFenetre()/8+60, 300);
	rectangle(4*largeurFenetre()/8+60, 200, 5*largeurFenetre()/8+80, 300);
	rectangle(5*largeurFenetre()/8+80, 200, 6*largeurFenetre()/8+100, 300);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/8+5, 305, 2*largeurFenetre()/8+15, 395);
	rectangle(2*largeurFenetre()/8+25, 305, 3*largeurFenetre()/8+35, 395);
	rectangle(3*largeurFenetre()/8+45, 305, 4*largeurFenetre()/8+55, 395);
	rectangle(4*largeurFenetre()/8+65, 305, 5*largeurFenetre()/8+75, 395);
	rectangle(5*largeurFenetre()/8+85, 305, 6*largeurFenetre()/8+95, 395);
	rectangle(largeurFenetre()/8+5, 205, 2*largeurFenetre()/8+15, 295);
	rectangle(2*largeurFenetre()/8+25, 205, 3*largeurFenetre()/8+35, 295);
	rectangle(3*largeurFenetre()/8+45, 205, 4*largeurFenetre()/8+55, 295);
	rectangle(4*largeurFenetre()/8+65, 205, 5*largeurFenetre()/8+75, 295);
	rectangle(5*largeurFenetre()/8+85, 205, 6*largeurFenetre()/8+95, 295);

	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	couleurCourante(0, 255, 0); // Couleur vert

	rectangle(2*largeurFenetre()/8+25, 305, 3*largeurFenetre()/8+35, 395);


	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 2", 24,largeurFenetre()/2-50,hauteurFenetre()-50);
	epaisseurDeTrait(1.5);
	afficheChaine("PASSE",18,largeurFenetre()/8+15,340);
	afficheChaine("LIVRE",18,2*largeurFenetre()/8+35,340);
	afficheChaine("TABLE",18,3*largeurFenetre()/8+55,340);
	afficheChaine("IVRE",18,4*largeurFenetre()/8+75,340);
	afficheChaine("OREILLE",18,5*largeurFenetre()/8+95,340);
	afficheChaine("MABRE",18,largeurFenetre()/8+15,240);
	afficheChaine("VALISE",18,2*largeurFenetre()/8+35,240);
	afficheChaine("CHIEN",18,3*largeurFenetre()/8+55,240);
	afficheChaine("CRAVATE",18,4*largeurFenetre()/8+75,240);
	afficheChaine("MONTRE",18,5*largeurFenetre()/8+95,240);
}

void PageMemoireTest2_4() //PAGE MEMOIRE
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	rectangle(largeurFenetre()/8, 300, 2*largeurFenetre()/8+20, 400);
	rectangle(2*largeurFenetre()/8+20, 300, 3*largeurFenetre()/8+40, 400);
	rectangle(3*largeurFenetre()/8+40, 300, 4*largeurFenetre()/8+60, 400);
	rectangle(4*largeurFenetre()/8+60, 300, 5*largeurFenetre()/8+80, 400);
	rectangle(5*largeurFenetre()/8+80, 300, 6*largeurFenetre()/8+100, 400);
	rectangle(largeurFenetre()/8, 200, 2*largeurFenetre()/8+20, 300);
	rectangle(2*largeurFenetre()/8+20, 200, 3*largeurFenetre()/8+40, 300);
	rectangle(3*largeurFenetre()/8+40, 200, 4*largeurFenetre()/8+60, 300);
	rectangle(4*largeurFenetre()/8+60, 200, 5*largeurFenetre()/8+80, 300);
	rectangle(5*largeurFenetre()/8+80, 200, 6*largeurFenetre()/8+100, 300);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/8+5, 305, 2*largeurFenetre()/8+15, 395);
	rectangle(2*largeurFenetre()/8+25, 305, 3*largeurFenetre()/8+35, 395);
	rectangle(3*largeurFenetre()/8+45, 305, 4*largeurFenetre()/8+55, 395);
	rectangle(4*largeurFenetre()/8+65, 305, 5*largeurFenetre()/8+75, 395);
	rectangle(5*largeurFenetre()/8+85, 305, 6*largeurFenetre()/8+95, 395);
	rectangle(largeurFenetre()/8+5, 205, 2*largeurFenetre()/8+15, 295);
	rectangle(2*largeurFenetre()/8+25, 205, 3*largeurFenetre()/8+35, 295);
	rectangle(3*largeurFenetre()/8+45, 205, 4*largeurFenetre()/8+55, 295);
	rectangle(4*largeurFenetre()/8+65, 205, 5*largeurFenetre()/8+75, 295);
	rectangle(5*largeurFenetre()/8+85, 205, 6*largeurFenetre()/8+95, 295);

	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	couleurCourante(0, 255, 0); // Couleur vert

	rectangle(3*largeurFenetre()/8+45, 305, 4*largeurFenetre()/8+55, 395);


	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 2", 24,largeurFenetre()/2-50,hauteurFenetre()-50);
	epaisseurDeTrait(1.5);
	afficheChaine("PASSE",18,largeurFenetre()/8+15,340);
	afficheChaine("LIVRE",18,2*largeurFenetre()/8+35,340);
	afficheChaine("TABLE",18,3*largeurFenetre()/8+55,340);
	afficheChaine("IVRE",18,4*largeurFenetre()/8+75,340);
	afficheChaine("OREILLE",18,5*largeurFenetre()/8+95,340);
	afficheChaine("MABRE",18,largeurFenetre()/8+15,240);
	afficheChaine("VALISE",18,2*largeurFenetre()/8+35,240);
	afficheChaine("CHIEN",18,3*largeurFenetre()/8+55,240);
	afficheChaine("CRAVATE",18,4*largeurFenetre()/8+75,240);
	afficheChaine("MONTRE",18,5*largeurFenetre()/8+95,240);
}
void PageMemoireTest2_5() //PAGE MEMOIRE
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	rectangle(largeurFenetre()/8, 300, 2*largeurFenetre()/8+20, 400);
	rectangle(2*largeurFenetre()/8+20, 300, 3*largeurFenetre()/8+40, 400);
	rectangle(3*largeurFenetre()/8+40, 300, 4*largeurFenetre()/8+60, 400);
	rectangle(4*largeurFenetre()/8+60, 300, 5*largeurFenetre()/8+80, 400);
	rectangle(5*largeurFenetre()/8+80, 300, 6*largeurFenetre()/8+100, 400);
	rectangle(largeurFenetre()/8, 200, 2*largeurFenetre()/8+20, 300);
	rectangle(2*largeurFenetre()/8+20, 200, 3*largeurFenetre()/8+40, 300);
	rectangle(3*largeurFenetre()/8+40, 200, 4*largeurFenetre()/8+60, 300);
	rectangle(4*largeurFenetre()/8+60, 200, 5*largeurFenetre()/8+80, 300);
	rectangle(5*largeurFenetre()/8+80, 200, 6*largeurFenetre()/8+100, 300);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/8+5, 305, 2*largeurFenetre()/8+15, 395);
	rectangle(2*largeurFenetre()/8+25, 305, 3*largeurFenetre()/8+35, 395);
	rectangle(3*largeurFenetre()/8+45, 305, 4*largeurFenetre()/8+55, 395);
	rectangle(4*largeurFenetre()/8+65, 305, 5*largeurFenetre()/8+75, 395);
	rectangle(5*largeurFenetre()/8+85, 305, 6*largeurFenetre()/8+95, 395);
	rectangle(largeurFenetre()/8+5, 205, 2*largeurFenetre()/8+15, 295);
	rectangle(2*largeurFenetre()/8+25, 205, 3*largeurFenetre()/8+35, 295);
	rectangle(3*largeurFenetre()/8+45, 205, 4*largeurFenetre()/8+55, 295);
	rectangle(4*largeurFenetre()/8+65, 205, 5*largeurFenetre()/8+75, 295);
	rectangle(5*largeurFenetre()/8+85, 205, 6*largeurFenetre()/8+95, 295);

	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	couleurCourante(0, 255, 0); // Couleur vert
	rectangle(2*largeurFenetre()/8+25, 205, 3*largeurFenetre()/8+35, 295);

	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 2", 24,largeurFenetre()/2-50,hauteurFenetre()-50);
	epaisseurDeTrait(1.5);
	afficheChaine("PASSE",18,largeurFenetre()/8+15,340);
	afficheChaine("LIVRE",18,2*largeurFenetre()/8+35,340);
	afficheChaine("TABLE",18,3*largeurFenetre()/8+55,340);
	afficheChaine("IVRE",18,4*largeurFenetre()/8+75,340);
	afficheChaine("OREILLE",18,5*largeurFenetre()/8+95,340);
	afficheChaine("MABRE",18,largeurFenetre()/8+15,240);
	afficheChaine("VALISE",18,2*largeurFenetre()/8+35,240);
	afficheChaine("CHIEN",18,3*largeurFenetre()/8+55,240);
	afficheChaine("CRAVATE",18,4*largeurFenetre()/8+75,240);
	afficheChaine("MONTRE",18,5*largeurFenetre()/8+95,240);
}
void PageMemoireTest2_6() //PAGE MEMOIRE
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	rectangle(largeurFenetre()/8, 300, 2*largeurFenetre()/8+20, 400);
	rectangle(2*largeurFenetre()/8+20, 300, 3*largeurFenetre()/8+40, 400);
	rectangle(3*largeurFenetre()/8+40, 300, 4*largeurFenetre()/8+60, 400);
	rectangle(4*largeurFenetre()/8+60, 300, 5*largeurFenetre()/8+80, 400);
	rectangle(5*largeurFenetre()/8+80, 300, 6*largeurFenetre()/8+100, 400);
	rectangle(largeurFenetre()/8, 200, 2*largeurFenetre()/8+20, 300);
	rectangle(2*largeurFenetre()/8+20, 200, 3*largeurFenetre()/8+40, 300);
	rectangle(3*largeurFenetre()/8+40, 200, 4*largeurFenetre()/8+60, 300);
	rectangle(4*largeurFenetre()/8+60, 200, 5*largeurFenetre()/8+80, 300);
	rectangle(5*largeurFenetre()/8+80, 200, 6*largeurFenetre()/8+100, 300);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/8+5, 305, 2*largeurFenetre()/8+15, 395);
	rectangle(2*largeurFenetre()/8+25, 305, 3*largeurFenetre()/8+35, 395);
	rectangle(3*largeurFenetre()/8+45, 305, 4*largeurFenetre()/8+55, 395);
	rectangle(4*largeurFenetre()/8+65, 305, 5*largeurFenetre()/8+75, 395);
	rectangle(5*largeurFenetre()/8+85, 305, 6*largeurFenetre()/8+95, 395);
	rectangle(largeurFenetre()/8+5, 205, 2*largeurFenetre()/8+15, 295);
	rectangle(2*largeurFenetre()/8+25, 205, 3*largeurFenetre()/8+35, 295);
	rectangle(3*largeurFenetre()/8+45, 205, 4*largeurFenetre()/8+55, 295);
	rectangle(4*largeurFenetre()/8+65, 205, 5*largeurFenetre()/8+75, 295);
	rectangle(5*largeurFenetre()/8+85, 205, 6*largeurFenetre()/8+95, 295);
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	couleurCourante(0, 255, 0); // Couleur vert
	rectangle(4*largeurFenetre()/8+65, 205, 5*largeurFenetre()/8+75, 295);


	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 2", 24,largeurFenetre()/2-50,hauteurFenetre()-50);
	epaisseurDeTrait(1.5);
	afficheChaine("PASSE",18,largeurFenetre()/8+15,340);
	afficheChaine("LIVRE",18,2*largeurFenetre()/8+35,340);
	afficheChaine("TABLE",18,3*largeurFenetre()/8+55,340);
	afficheChaine("IVRE",18,4*largeurFenetre()/8+75,340);
	afficheChaine("OREILLE",18,5*largeurFenetre()/8+95,340);
	afficheChaine("MABRE",18,largeurFenetre()/8+15,240);
	afficheChaine("VALISE",18,2*largeurFenetre()/8+35,240);
	afficheChaine("CHIEN",18,3*largeurFenetre()/8+55,240);
	afficheChaine("CRAVATE",18,4*largeurFenetre()/8+75,240);
	afficheChaine("MONTRE",18,5*largeurFenetre()/8+95,240);
}
void PageMemoireTest2_7() //PAGE MEMOIRE
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	rectangle(largeurFenetre()/8, 300, 2*largeurFenetre()/8+20, 400);
	rectangle(2*largeurFenetre()/8+20, 300, 3*largeurFenetre()/8+40, 400);
	rectangle(3*largeurFenetre()/8+40, 300, 4*largeurFenetre()/8+60, 400);
	rectangle(4*largeurFenetre()/8+60, 300, 5*largeurFenetre()/8+80, 400);
	rectangle(5*largeurFenetre()/8+80, 300, 6*largeurFenetre()/8+100, 400);
	rectangle(largeurFenetre()/8, 200, 2*largeurFenetre()/8+20, 300);
	rectangle(2*largeurFenetre()/8+20, 200, 3*largeurFenetre()/8+40, 300);
	rectangle(3*largeurFenetre()/8+40, 200, 4*largeurFenetre()/8+60, 300);
	rectangle(4*largeurFenetre()/8+60, 200, 5*largeurFenetre()/8+80, 300);
	rectangle(5*largeurFenetre()/8+80, 200, 6*largeurFenetre()/8+100, 300);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre()/8+5, 305, 2*largeurFenetre()/8+15, 395);
	rectangle(2*largeurFenetre()/8+25, 305, 3*largeurFenetre()/8+35, 395);
	rectangle(3*largeurFenetre()/8+45, 305, 4*largeurFenetre()/8+55, 395);
	rectangle(4*largeurFenetre()/8+65, 305, 5*largeurFenetre()/8+75, 395);
	rectangle(5*largeurFenetre()/8+85, 305, 6*largeurFenetre()/8+95, 395);
	rectangle(largeurFenetre()/8+5, 205, 2*largeurFenetre()/8+15, 295);
	rectangle(2*largeurFenetre()/8+25, 205, 3*largeurFenetre()/8+35, 295);
	rectangle(3*largeurFenetre()/8+45, 205, 4*largeurFenetre()/8+55, 295);
	rectangle(4*largeurFenetre()/8+65, 205, 5*largeurFenetre()/8+75, 295);
	rectangle(5*largeurFenetre()/8+85, 205, 6*largeurFenetre()/8+95, 295);

	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	couleurCourante(0, 255, 0); // Couleur vert
	rectangle(5*largeurFenetre()/8+85, 205, 6*largeurFenetre()/8+95, 295);

	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 2", 24,largeurFenetre()/2-50,hauteurFenetre()-50);
	epaisseurDeTrait(1.5);
	afficheChaine("PASSE",18,largeurFenetre()/8+15,340);
	afficheChaine("LIVRE",18,2*largeurFenetre()/8+35,340);
	afficheChaine("TABLE",18,3*largeurFenetre()/8+55,340);
	afficheChaine("IVRE",18,4*largeurFenetre()/8+75,340);
	afficheChaine("OREILLE",18,5*largeurFenetre()/8+95,340);
	afficheChaine("MABRE",18,largeurFenetre()/8+15,240);
	afficheChaine("VALISE",18,2*largeurFenetre()/8+35,240);
	afficheChaine("CHIEN",18,3*largeurFenetre()/8+55,240);
	afficheChaine("CRAVATE",18,4*largeurFenetre()/8+75,240);
	afficheChaine("MONTRE",18,5*largeurFenetre()/8+95,240);
}



void PageMobilite() //PAGE Mobilite
{
	couleurCourante(0, 0, 0);																							  // Couleur en noir
	rectangle(largeurFenetre() / 6 - 5, hauteurFenetre() / 2 - 55, largeurFenetre() / 2 - 20, hauteurFenetre() / 2 + 55);	  //TEST 1
	rectangle(largeurFenetre() / 2 + 20, hauteurFenetre() / 2 - 55, 5 * largeurFenetre() / 6 + 5, hauteurFenetre() / 2 + 55); //TEST 2
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);										  // RETOUR




	couleurCourante(255, 255, 255); // Couleur blanc

	rectangle(largeurFenetre() / 6, hauteurFenetre() / 2 - 50, largeurFenetre() / 2 - 25, hauteurFenetre() / 2 + 50);	  //TEST 1
	rectangle(largeurFenetre() / 2 + 25, hauteurFenetre() / 2 - 50, 5 * largeurFenetre() / 6, hauteurFenetre() / 2 + 50); //TEST 2
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9);										  // RETOUR
	couleurCourante(0, 0, 0);																							  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 1", 18, largeurFenetre() / 6 + 70, hauteurFenetre() / 2 - 10);
	afficheChaine("TEST 2", 18, largeurFenetre() / 2 + 100, hauteurFenetre() / 2 - 10);

	epaisseurDeTrait(1);
	afficheChaine("Sortir le plus vite ", 20, largeurFenetre() / 6 + 10, hauteurFenetre() / 2 - 80);
	afficheChaine("possible sans ", 20, largeurFenetre() / 6 + 10, hauteurFenetre() / 2 - 105);
	afficheChaine("toucher les bords. ", 20, largeurFenetre() / 6 + 10, hauteurFenetre() / 2 - 130);
	afficheChaine("Cliquer dans la ", 20, largeurFenetre() / 2 + 50, hauteurFenetre() / 2 - 80);
	afficheChaine("boule jaune. ", 20, largeurFenetre() / 2 + 50, hauteurFenetre() / 2 - 105);

	couleurCourante(255, 0, 0); // Couleur en rouge
	epaisseurDeTrait(5);
	afficheChaine("MOBILITE", 36, largeurFenetre() / 2 - 75, 2 * hauteurFenetre() / 3 + 50);
}

void PageMobiliteTest1_2() //PAGE Mobilite 1
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255);												  // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("LE LABYRINTHE", 24,largeurFenetre()/2-80,hauteurFenetre()-50);

// LABYRINTHE
	couleurCourante(255, 255, 255);												  // Couleur blanc
	rectangle(0, 0, largeurFenetre()/8, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8, hauteurFenetre()-175, largeurFenetre()/8+100, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+50, hauteurFenetre()/5, largeurFenetre()/8+100, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+50, hauteurFenetre()/5, largeurFenetre()/8+200, hauteurFenetre()/5+50);
	rectangle(largeurFenetre()/8+200, hauteurFenetre()/5, largeurFenetre()/8+240, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+220, hauteurFenetre()-140, largeurFenetre()/8+315, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+280, hauteurFenetre()/10, largeurFenetre()/8+315, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+280, hauteurFenetre()/10, largeurFenetre()/8+380, hauteurFenetre()/10+40);
	rectangle(largeurFenetre()/8+350, hauteurFenetre()/10, largeurFenetre()/8+380, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+350, hauteurFenetre()-130, largeurFenetre()/8+430, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+410, hauteurFenetre()/2+50, largeurFenetre()/8+430, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+410, hauteurFenetre()/2+50, largeurFenetre()/8+500, hauteurFenetre()/2+70);
	rectangle(largeurFenetre()/8+480, hauteurFenetre()/2+50, largeurFenetre()/8+500, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+480, hauteurFenetre()-120, largeurFenetre()/2+350, hauteurFenetre()-100);
	rectangle(largeurFenetre()/2+330, hauteurFenetre()/2+100, largeurFenetre()/2+350, hauteurFenetre()-100);
	rectangle(largeurFenetre()/2+270, hauteurFenetre()/2+100, largeurFenetre()/2+350, hauteurFenetre()/2+120);
	rectangle(largeurFenetre()/2+270, hauteurFenetre()/2+60, largeurFenetre()/2+290, hauteurFenetre()/2+120);
	rectangle(largeurFenetre()/2+270, hauteurFenetre()/2+60, largeurFenetre()/2+360, hauteurFenetre()/2+80);
	rectangle(largeurFenetre()/2+340, hauteurFenetre()/2-30, largeurFenetre()/2+360, hauteurFenetre()/2+80);
	rectangle(largeurFenetre()/2+150, hauteurFenetre()/2-30, largeurFenetre()/2+360, hauteurFenetre()/2-10);
	rectangle(largeurFenetre()/2+150, hauteurFenetre()/2-100, largeurFenetre()/2+170, hauteurFenetre()/2-10);
	rectangle(largeurFenetre()/2+150, hauteurFenetre()/2-100, largeurFenetre()/2+340, hauteurFenetre()/2-80);
	couleurCourante(255, 255, 0);
	rectangle(largeurFenetre()/2+270, hauteurFenetre()/2-150, largeurFenetre()/2+340, hauteurFenetre()/2-100);


}
void PageMobiliteTest1() //PAGE Mobilite 1
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255);												  // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("LE LABYRINTHE", 24,largeurFenetre()/2-80,hauteurFenetre()-50);

// LABYRINTHE
	couleurCourante(255, 255, 255);												  // Couleur blanc
	rectangle(0, 0, largeurFenetre()/8, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8, hauteurFenetre()-175, largeurFenetre()/8+100, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+50, hauteurFenetre()/5, largeurFenetre()/8+100, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+50, hauteurFenetre()/5, largeurFenetre()/8+200, hauteurFenetre()/5+50);
	rectangle(largeurFenetre()/8+200, hauteurFenetre()/5, largeurFenetre()/8+240, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+220, hauteurFenetre()-140, largeurFenetre()/8+315, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+280, hauteurFenetre()/10, largeurFenetre()/8+315, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+280, hauteurFenetre()/10, largeurFenetre()/8+380, hauteurFenetre()/10+40);
	rectangle(largeurFenetre()/8+350, hauteurFenetre()/10, largeurFenetre()/8+380, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+350, hauteurFenetre()-130, largeurFenetre()/8+430, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+410, hauteurFenetre()/2+50, largeurFenetre()/8+430, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+410, hauteurFenetre()/2+50, largeurFenetre()/8+500, hauteurFenetre()/2+70);
	rectangle(largeurFenetre()/8+480, hauteurFenetre()/2+50, largeurFenetre()/8+500, hauteurFenetre()-100);
	rectangle(largeurFenetre()/8+480, hauteurFenetre()-120, largeurFenetre()/2+350, hauteurFenetre()-100);
	rectangle(largeurFenetre()/2+330, hauteurFenetre()/2+100, largeurFenetre()/2+350, hauteurFenetre()-100);
	rectangle(largeurFenetre()/2+270, hauteurFenetre()/2+100, largeurFenetre()/2+350, hauteurFenetre()/2+120);
	rectangle(largeurFenetre()/2+270, hauteurFenetre()/2+60, largeurFenetre()/2+290, hauteurFenetre()/2+120);
	rectangle(largeurFenetre()/2+270, hauteurFenetre()/2+60, largeurFenetre()/2+360, hauteurFenetre()/2+80);
	rectangle(largeurFenetre()/2+340, hauteurFenetre()/2-30, largeurFenetre()/2+360, hauteurFenetre()/2+80);
	rectangle(largeurFenetre()/2+150, hauteurFenetre()/2-30, largeurFenetre()/2+360, hauteurFenetre()/2-10);
	rectangle(largeurFenetre()/2+150, hauteurFenetre()/2-100, largeurFenetre()/2+170, hauteurFenetre()/2-10);
	rectangle(largeurFenetre()/2+150, hauteurFenetre()/2-100, largeurFenetre()/2+340, hauteurFenetre()/2-80);
	couleurCourante(255, 255, 0);
	rectangle(largeurFenetre()/2+270, hauteurFenetre()/2-150, largeurFenetre()/2+340, hauteurFenetre()/2-100);

	couleurCourante(0, 0, 0);												  // Couleur blanc
	rectangle(0, 0, largeurFenetre()/8+5, hauteurFenetre()/9+5);
	couleurCourante(255, 255, 255);												  // Couleur blanc
	rectangle(0, 0, largeurFenetre()/8, hauteurFenetre()/9);
	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("START",18,25,25);
}



void PageMobiliteTest2() //PAGE Mobilite 2
{
	couleurCourante(0,0,0);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255); // Couleur blanc

	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("LA BOULE",24,largeurFenetre()/2-60,hauteurFenetre()-50);
}

void PageVision() //PAGE VISION
{

	couleurCourante(0, 0, 0);																							  // Couleur en noir
	rectangle(largeurFenetre() / 6 - 5, hauteurFenetre() / 2 - 55, largeurFenetre() / 2 - 20, hauteurFenetre() / 2 + 55);	  //TEST 1
	rectangle(largeurFenetre() / 2 + 20, hauteurFenetre() / 2 - 55, 5 * largeurFenetre() / 6 + 5, hauteurFenetre() / 2 + 55); //TEST 2
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);  // RETOUR

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() / 6, hauteurFenetre() / 2 - 50, largeurFenetre() / 2 - 25, hauteurFenetre() / 2 + 50);	  //TEST 1
	rectangle(largeurFenetre() / 2 + 25, hauteurFenetre() / 2 - 50, 5 * largeurFenetre() / 6, hauteurFenetre() / 2 + 50); //TEST 2
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9);	  // RETOUR
	couleurCourante(0, 0, 0);	  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("TEST 1", 18, largeurFenetre() / 6 + 70, hauteurFenetre() / 2 - 10);
	afficheChaine("TEST 2", 18, largeurFenetre() / 2 + 100, hauteurFenetre() / 2 - 10);

	epaisseurDeTrait(1);
	afficheChaine("Quel est la ", 20, largeurFenetre() / 6 + 10, hauteurFenetre() / 2 - 80);
	afficheChaine("bonne couleur? ", 20, largeurFenetre() / 6 + 10, hauteurFenetre() / 2 - 105);
	afficheChaine("Repondre a la", 20, largeurFenetre() / 2 + 50, hauteurFenetre() / 2 - 80);
	afficheChaine("question. ", 20, largeurFenetre() / 2 + 50, hauteurFenetre() / 2 - 105);

	couleurCourante(255, 0, 0); // Couleur en rouge
	epaisseurDeTrait(5);
	afficheChaine("VISION", 36, largeurFenetre() / 2 - 55, 2 * hauteurFenetre() / 3 + 50);
}

void PageVisionTest1() //PAGE VISION 1
{
	couleurCourante(0,0,0);
	rectangle(195,95,305,205);
	rectangle(345,95,455,205);
	rectangle(495,95,605,205);
	rectangle(345,395,455,505);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	epaisseurDeTrait(5);
	afficheChaine("?", 150, largeurFenetre()/2-50, hauteurFenetre() / 3+30);

	couleurCourante(255, 255, 255);		 // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	// CARREES COLORES
	couleurCourante(255, 0, 0);
	rectangle(200,100,300,200);

	couleurCourante(0, 255, 0);
	rectangle(350,100,450,200);

	couleurCourante(0, 0 , 255);
	rectangle(500,100,600,200);

	couleurCourante(0, 255, 255);	//couleur 1
	rectangle(350,400,450,500);

	// MOTS COLORES
	couleurCourante(0, 255, 255);
	epaisseurDeTrait(1);
	afficheChaine("JAUNE", 12, 225, 150);

	couleurCourante(255, 0, 255);
	epaisseurDeTrait(1);
	afficheChaine("MAGENTA", 12, 375, 150);

	couleurCourante(255, 0, 0); 	//réponse 1
	epaisseurDeTrait(1);
	afficheChaine("CYAN", 12, 530, 150);



	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("Quelle est la bonne couleur?",24,largeurFenetre()/3-30,hauteurFenetre()-50);

}
void PageVisionTest1_2()
{
	couleurCourante(0,0,0);
	rectangle(195,95,305,205);
	rectangle(345,95,455,205);
	rectangle(495,95,605,205);
	rectangle(345,395,455,505);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	epaisseurDeTrait(5);
	afficheChaine("?", 150, largeurFenetre()/2-50, hauteurFenetre() / 3+30);

	couleurCourante(255, 255, 255);		 // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	// CARREES COLORES
	couleurCourante(255, 0, 255);
	rectangle(200,100,300,200);

	couleurCourante(200, 200, 200);
	rectangle(350,100,450,200);

	couleurCourante(130, 0 , 0);
	rectangle(500,100,600,200);

	couleurCourante(255, 255, 0);	//couleur 2
	rectangle(350,400,450,500);

	// MOTS COLORES
	couleurCourante(0, 0, 255);
	epaisseurDeTrait(1);
	afficheChaine("VERT", 12, 225, 150);

	couleurCourante(0, 255, 0); 		//réponse 2
	epaisseurDeTrait(1);
	afficheChaine("JAUNE", 12, 375, 150);

	couleurCourante(255, 255, 0);
	epaisseurDeTrait(1);
	afficheChaine("ORANGE", 12, 530, 150);



	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("Quelle est la bonne couleur?",24,largeurFenetre()/3-30,hauteurFenetre()-50);

	couleurCourante(0,255,0);
	rectangle(50,500,100,550);

}

void PageVisionTest1_3()
{
	couleurCourante(0,0,0);
	rectangle(195,95,305,205);
	rectangle(345,95,455,205);
	rectangle(495,95,605,205);
	rectangle(345,395,455,505);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);
	epaisseurDeTrait(5);
	afficheChaine("?", 150, largeurFenetre()/2-50, hauteurFenetre() / 3+30);

	couleurCourante(255, 255, 255);		 // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR

	// CARREES COLORES
	couleurCourante(0, 0, 255);
	rectangle(200,100,300,200);

	couleurCourante(255, 0, 0);
	rectangle(350,100,450,200);

	couleurCourante(0, 255 , 255);
	rectangle(500,100,600,200);

	couleurCourante(255, 0, 0);	//couleur 3
	rectangle(350,400,450,500);

	// MOTS COLORES
	couleurCourante(255, 255,0);
	epaisseurDeTrait(1);
	afficheChaine("GRIS", 12, 225, 150);

	couleurCourante(50, 0, 0);
	epaisseurDeTrait(1);
	afficheChaine("ORANGE", 12, 375, 150);

	couleurCourante(255, 0, 255); 		//réponse 3
	epaisseurDeTrait(1);
	afficheChaine("ROUGE", 12, 530, 150);



	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("Quelle est la bonne couleur?",24,largeurFenetre()/3-30,hauteurFenetre()-50);

	couleurCourante(0,255,0);
	rectangle(50,500,100,550);
	rectangle(50,300,100,350);

}

void PageVisionTest1_4()
{
	couleurCourante(0,0,0);

	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	epaisseurDeTrait(5);

	afficheChaine("F I N", 40, largeurFenetre()/2 - 50 , hauteurFenetre()/2);

	couleurCourante(0,255,0);
	rectangle(50,500,100,550);
	rectangle(50,300,100,350);
	rectangle(50,100,100,150);

}


void PageVisionTest2() //PAGE VISION 2
{
	couleurCourante(0,0,0);
	rectangle(245, 45, 355, 155);
	rectangle(395, 45, 505, 155);
	rectangle(545, 45, 655, 155);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255); // Couleur blanc

	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	afficheChaine("ACUITE VISUEL", 24,largeurFenetre()/2-100,hauteurFenetre()-50);

	epaisseurDeTrait(5);
	afficheChaine("1 : H O T E L E T G J", 36, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 +50);
	epaisseurDeTrait(4);
	afficheChaine("2 : K G Y I E G S J K", 30, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 );
	epaisseurDeTrait(3);
	afficheChaine("3 : B S G A M G N I J", 25, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 - 50);
	epaisseurDeTrait(2);
	afficheChaine("4 : Q X W V B N D M Z", 20, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -75);
	epaisseurDeTrait(1);
	afficheChaine("5 : A Z E R Q F K P T", 15, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -100);
	epaisseurDeTrait(0.75);
	afficheChaine("6 : M H D T U P A X B", 10, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -125);
	epaisseurDeTrait(0.50);
	afficheChaine("7 : Z G J S G C M F I", 5, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -150);
	epaisseurDeTrait(0.25);
	afficheChaine("8 : F H L Z O Q X D N", 4, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -170);

	epaisseurDeTrait(4);
	afficheChaine("Ligne 2 , lettre 3 ?", 25, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -230);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(250, 50, 350, 150);
	rectangle(400, 50, 500, 150);
	rectangle(550, 50, 650, 150);
	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(5);
	afficheChaine("H", 36, 290, 75);
	afficheChaine("I", 36, 440, 75);
	afficheChaine("Y", 36, 590, 75);

}

void PageVisionTest2_2() //PAGE VISION 2
{
	couleurCourante(0,0,0);
	rectangle(245, 45, 355, 155);
	rectangle(395, 45, 505, 155);
	rectangle(545, 45, 655, 155);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	couleurCourante(0, 0, 0); // Couleur en noir
	afficheChaine("ACUITE VISUEL", 24,largeurFenetre()/2-100,hauteurFenetre()-50);
	epaisseurDeTrait(5);
	afficheChaine("1 : H O T E L E T G J", 36, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 +50);
	epaisseurDeTrait(4);
	afficheChaine("2 : K G Y I E G S J K", 30, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 );
	epaisseurDeTrait(3);
	afficheChaine("3 : B S G A M G N I J", 25, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 - 50);
	epaisseurDeTrait(2);
	afficheChaine("4 : Q X W V B N D M Z", 20, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -75);
	epaisseurDeTrait(1);
	afficheChaine("5 : A Z E R Q F K P T", 15, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -100);
	epaisseurDeTrait(0.75);
	afficheChaine("6 : M H D T U P A X B", 10, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -125);
	epaisseurDeTrait(0.50);
	afficheChaine("7 : Z G J S G C M F I", 5, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -150);
	epaisseurDeTrait(0.25);
	afficheChaine("8 : F H L Z O Q X D N", 4, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -170);

	epaisseurDeTrait(4);
	afficheChaine("Ligne 6, lettre 7 ?", 25, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -230);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(250, 50, 350, 150);
	rectangle(400, 50, 500, 150);
	rectangle(550, 50, 650, 150);
	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(5);
	afficheChaine("M", 36, 290, 75);
	afficheChaine("A", 36, 440, 75);
	afficheChaine("P", 36, 590, 75);

	couleurCourante(0,255,0);
	rectangle(50,500,100,550);
}

void PageVisionTest2_3() //PAGE VISION 2
{
	couleurCourante(0,0,0);
	rectangle(245, 45, 355, 155);
	rectangle(395, 45, 505, 155);
	rectangle(545, 45, 655, 155);
	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	couleurCourante(0, 0, 0); // Couleur en noir
	afficheChaine("ACUITE VISUEL", 24,largeurFenetre()/2-100,hauteurFenetre()-50);
	epaisseurDeTrait(5);
	afficheChaine("1 : H O T E L E T G J", 36, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 +50);
	epaisseurDeTrait(4);
	afficheChaine("2 : K G Y I E G S J K", 30, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 );
	epaisseurDeTrait(3);
	afficheChaine("3 : B S G A M G N I J", 25, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 - 50);
	epaisseurDeTrait(2);
	afficheChaine("4 : Q X W V B N D M Z", 20, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -75);
	epaisseurDeTrait(1);
	afficheChaine("5 : A Z E R Q F K P T", 15, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -100);
	epaisseurDeTrait(0.75);
	afficheChaine("6 : M H D T U P A X B", 10, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -125);
	epaisseurDeTrait(0.50);
	afficheChaine("7 : Z G J S G C M F I", 5, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -150);
	epaisseurDeTrait(0.25);
	afficheChaine("8 : F H L Z O Q X D N", 4, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -170);

	epaisseurDeTrait(4);
	afficheChaine("Ligne 8, lettre 5 ?", 25, largeurFenetre() /2-200, 2 * hauteurFenetre() / 3 -230);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(250, 50, 350, 150);
	rectangle(400, 50, 500, 150);
	rectangle(550, 50, 650, 150);
	couleurCourante(0, 0, 0); // Couleur en noir
	epaisseurDeTrait(5);
	afficheChaine("O", 36, 290, 75);
	afficheChaine("Q", 36, 440, 75);
	afficheChaine("D", 36, 590, 75);

	couleurCourante(0,255,0);
	rectangle(50,500,100,550);
	rectangle(50,300,100,350);
}


void PageVisionTest2_4() //PAGE VISION 2
{
	couleurCourante(0,0,0);

	rectangle(largeurFenetre() - 130, 0, largeurFenetre(), hauteurFenetre() / 9 + 5);

	couleurCourante(255, 255, 255); // Couleur blanc
	rectangle(largeurFenetre() - 125, 0, largeurFenetre(), hauteurFenetre() / 9); // RETOUR
	couleurCourante(0, 0, 0);													  // Couleur en noir
	epaisseurDeTrait(3);
	afficheChaine("RETOUR", 18, largeurFenetre() - 110, 25);
	epaisseurDeTrait(5);

	afficheChaine("F I N", 40, largeurFenetre()/2 - 50 , hauteurFenetre()/2);

	couleurCourante(0,255,0);
	rectangle(50,500,100,550);
	rectangle(50,300,100,350);
	rectangle(50,100,100,150);

}


void cree3matrices(int B[256][256],int V[256][256], int R[256][256], DonneesImageRGB *image)
{
	for(int a=0;a<256;a++)
	{
		for(int b=0;b<256;b++)
		{
			B[a][b]=image->donneesRGB[(a*image->largeurImage+b)*3];
			V[a][b]=image->donneesRGB[((a*image->largeurImage+b)*3)+1];
			R[a][b]=image->donneesRGB[((a*image->largeurImage+b)*3)+2];
		}
	}
}
