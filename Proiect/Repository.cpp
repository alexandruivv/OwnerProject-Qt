#include "Repository.h"



Locuinta Repository::element(int poz)
{
	if (lista_locuinte.vida())
	{
		throw RepoEx("Lista e vida !");
	}
	if (poz < 0 || poz >= lista_locuinte.dimensiune()) {
		throw RepoEx("Pozitie invalida !");
	}
	return this->lista_locuinte.element(poz);
}

bool Repository::cauta(string id)
{
	Iterator<Locuinta> it(lista_locuinte);
	while(it.valid()){
		Locuinta loc = it.element();
		if (loc.getId() == id) return true;
		it.urmator();
	}
	return false;
}

void Repository::modificaLocuinta(int poz, Locuinta & loc)
{
	if (lista_locuinte.vida())
	{
		throw RepoEx("Lista e vida !");
	}
	if (poz < 0 || poz >= lista_locuinte.dimensiune()) {
		throw RepoEx("Pozitie invalida !");
	}
	lista_locuinte.modifica(poz, loc);
}

void Repository::adaugaSfarsit(Locuinta &loc)
{
	if(cauta(loc.getId())){
		throw RepoEx("Locuinta existenta !");
	}
	this->lista_locuinte.adaugaSfarsit(loc);
}


void Repository::stergePozitie(int poz)
{
	if (lista_locuinte.vida())
	{
		throw RepoEx("Lista e vida !");
	}
	if (poz < 0 || poz >= lista_locuinte.dimensiune()) {
		throw RepoEx("Pozitie invalida !");
	}
	this->lista_locuinte.stergePozitie(poz);
}

VectorDinamic<Locuinta>& Repository::getAll()
{
	return this->lista_locuinte;
}

VectorDinamic<Locuinta> Repository::getCopieLista()
{
	VectorDinamic<Locuinta> copie(lista_locuinte);
	return copie;
}





