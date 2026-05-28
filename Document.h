#pragma once

#include <string>
#include "Abonne.h"

class Document
{
private:
	std::string id;
	std::string titre;
	int idAbonne;
	bool present;
	static unsigned int cptDoc;
	
protected:
	unsigned int nDoc;

public:
	Document(std::string);
	void emprunt(int);
	std::string getId();
	void setId();
	std::string getTitre();
	void retour();
	virtual std::string toString() = 0;
	void perdu();
	int getIdAbonne();
	bool estPresent();
	virtual std::string typeDocument();
	virtual int pourAdulte();
};

