#include "./Zoning/zoning.h"


int main(int argc, char **argv)
{
	utilisateur user[3];

	initialiseGfx(argc, argv);

	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);

	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();

	return 0;
}
