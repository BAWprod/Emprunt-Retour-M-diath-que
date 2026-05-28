#include "Document.h"
#include "DVD.h"
#include "Livre.h"
#include "Abonne.h"
#include <iostream>
#include <map>

void main() {

	/* Début de l'initialisation des documents et des abonnés */

	std::map<std::string, Document*> documents;
	std::string titre[] = {"18 ans apres", "Dragon Ball tome 28", "C++ pour les nuls", "Cars 3", "Guerre et Paix", "Shaolin Soccer", "La Bible de L'aventure"};
	char type[] = {'d', 'l', 'l', 'd', 'l', 'd', 'l'};
	int caractéristique[] = {1, 350, 442, 0, 2000, 0, 2080};
	Document* d;
	Livre* l;
	DVD* dvd;

	for (int i = 0; i < 7; i++) {
		if (type[i] == 'd') {
			dvd = new DVD(titre[i], caractéristique[i]);
			d = dvd;
			dvd = nullptr;
		}
		else if (type[i] == 'l') {
			l = new Livre(titre[i], caractéristique[i]);
			d = l;
			l = nullptr;
		}
		
		documents.insert(std::pair<std::string, Document*>(d->getId(), d));
		d = nullptr;
	}


	std::map<int, Abonne*> abonnes;
	std::string nom[] = { "Adele", "Tristan", "Marine", "Damien", "Jean Christophe" };
	std::string date[] = { "20/07/2010", "19/04/1992", "26/11/2002", "02/02/2002", "07/05/2014" };
	unsigned int age[] = { 15, 34, 23, 24, 12 };
	Abonne* a;

	for (int i = 0; i < 5; i++) {
		a = new Abonne(nom[i], date[i], age[i]);
		abonnes.insert(std::pair<int, Abonne*>(a->getId(), a));
	}

	/* Fin de l'initialisation des documents et des abonnés */



	/* Préparation de la perte d'un document */
	
	documents["C0"]->perdu();
	
	/* Perte du document C0 */



	/* Interface Homme-Machine */

	int idAbo;
	int choix;
	std::string idDoc;

	while (1) {

		do {
			std::cout << "quel est votre identifiant (0 : quitter le logiciel) : ";
			std::cin >> idAbo;
			if (!idAbo) break;
			if (abonnes[idAbo] == nullptr) {
				std::cout << "Identifiant Inconnu." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (abonnes[idAbo] == nullptr);

		if (!idAbo) { std::cout << "fin du programme.\n"; break; }

		while (idAbo) {

			std::cout << std::endl;
			std::cout << "0 : quitter" << std::endl << "1 : voir tout les documents" << std::endl << "2 : emprunter un document" << std::endl << "3 : rendre un document" << std::endl << "4 : voir mon profil" << std::endl;

			std::cout << "Que souhaitait vous faire " << abonnes[idAbo]->getNom() << " : ";
			std::cin >> choix;
			if (std::cin.good()) {

				if (choix == 0) { std::cout << "Au revoir" << "\n\n"; break; }
				switch (choix) {
				case 0: idAbo = 0;
					break;
				case 1: std::cout << "voir tout les documents";
					std::cout << documents.size() << std::endl;
					for (auto document : documents) {
						std::cout << (document.second)->toString();
					}
					break;

				case 2: std::cout << "identifiant du document : ";
					std::cin >> idDoc;
					if (documents[idDoc] != nullptr) {
						std::cout << "Le " << documents[idDoc]->typeDocument() << " {" << documents[idDoc]->getId() << " : " << documents[idDoc]->getTitre() << "} " << "est ";
						if (documents[idDoc]->estPresent()) {
							if(documents[idDoc]->pourAdulte() && abonnes[idAbo]->getAge()<18) {
								std::cout << "reserve aux adulte, emprunt impossible." << std::endl;
							}
							else {
								documents[idDoc]->emprunt(idAbo);
								std::cout << "maintenant emprunte." << std::endl;
							}
						}
						else {
							if(documents[idDoc]->getIdAbonne()) std::cout << "deja emprunte, emprunt impossible." << std::endl;
							else std::cout << "indisponible, emprunt impossible." << std::endl;
						}
					}
					else std::cout << "document inexistant, emprunt impossible." << std::endl;
					break;

				case 3: std::cout << "identifiant du document : ";
					std::cin >> idDoc;
					if (documents[idDoc] != nullptr) {
						std::cout << "Le " << documents[idDoc]->typeDocument() << " {" << documents[idDoc]->getId() << " : " << documents[idDoc]->getTitre() << "} " << "est ";
						if (!documents[idDoc]->estPresent()) {
							documents[idDoc]->retour();
							std::cout << "rendu." << std::endl;
						}
						else std::cout << "deja present." << std::endl;
					}
					else std::cout << "document inexistant." << std::endl;
					break;

				case 4: std::cout << abonnes[idAbo]->toString() << "Documents : " << std::endl;
					for (auto document : documents) {
						if ((document.second)->getIdAbonne() == idAbo)std::cout << (document.second)->toString();
					}
					break;

				default: std::cout << "Option inconnue" << std::endl;
				}
			}
			else {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Option inconnue" << std::endl;
				continue;
			}
		}
	}

	/* Fin Interface Homme-Machine */


	/* Suppression des données stockées en mémoire */
	for (auto document : documents) {
		delete (document.second);
	}
	documents.clear();

	for (auto abonne : abonnes) {
		delete (abonne.second);
	}
	abonnes.clear();
}