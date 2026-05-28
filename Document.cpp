#include "Document.h"
#include <sstream>

unsigned int Document::cptDoc = 1;

Document::Document(std::string titre)
{
	this->nDoc = Document::cptDoc;
	this->titre = titre;
	this->idAbonne = 0;
	this->present = true;
	this->setId();
	Document::cptDoc++;
}

void Document::emprunt(int emprunteur)
{
	this->idAbonne = emprunteur;
	this->present = false;
}

std::string Document::getId()
{
	return this->id;
}

void Document::setId()
{
	if ((this->id).empty()) {
		std::stringstream ss;
		char lid = 'A';
		unsigned int nid;
		nid = (this->nDoc) / 27;
		lid = lid + ((this->nDoc - 1) % 26);
		ss << lid << nid;
		this->id = ss.str();
	}
}

std::string Document::getTitre()
{
	return this->titre;
}

void Document::retour()
{
	if (!this->present) {
		this->idAbonne = 0;
		this->present = true;
	}
}

std::string Document::toString()
{
	std::stringstream ss;

	ss << "id: " << this->id << " ; titre: " << this->titre << " ; " << ((this->present)? "Disponible" : "Indisponible") << " ; ";

	return ss.str();
}

void Document::perdu()
{
	this->present = false;
	this->idAbonne = 0;
}

int Document::getIdAbonne()
{
	return this->idAbonne;
}

bool Document::estPresent()
{
	return this->present;
}

std::string Document::typeDocument()
{
	return "On sait pas encore.";
}

int Document::pourAdulte()
{
	return 0;
}
