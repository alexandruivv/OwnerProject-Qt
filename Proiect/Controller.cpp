#include "Controller.h"



Controller::Controller(Repository& repo, ValidatorLocuinta& validator):repo{repo},validator{validator}
{
}

void Controller::adaugaLocuinta(string id, string proprietar, float suprafata, float impozit, string platit)
{
	Locuinta loc{ id,proprietar,suprafata,impozit,platit };
	validator.valideaza(loc);
	this->repo.adaugaSfarsit(loc);
}

void Controller::stergeLocuinta(int poz)
{
	this->repo.stergePozitie(poz);
}

void Controller::modificaLocuinta(int poz, string id, string proprietar, float suprafata, float impozit, string platit)
{
	Locuinta loc{ id,proprietar,suprafata,impozit, platit };
	validator.valideaza(loc);
	this->repo.modificaLocuinta(poz, loc);
}

Locuinta Controller::element(int poz)
{
	return this->repo.element(poz);
}

VectorDinamic<Locuinta> Controller::sortare()
{
	VectorDinamic<Locuinta> copie{ this->repo.getAll() };
	copie.sortareVector([](const Locuinta& loc1, const Locuinta& loc2) {
		return loc1.getImpozit() >= loc2.getImpozit();
	});
	return copie;
}

VectorDinamic<Locuinta> Controller::filtrare(function<bool(const Locuinta&)> functie)
{
	VectorDinamic<Locuinta> locuinte;
	Iterator<Locuinta> it(this->repo.getAll());
	while(it.valid()){
		if(functie(it.element())){
			locuinte.adaugaSfarsit(it.element());
		}
		it.urmator();
	}
	return locuinte;
}

VectorDinamic<Locuinta> Controller::filtrareDupaProprietar(string proprietar)
{

	return filtrare([proprietar](const Locuinta& locuinta) {
		return locuinta.getProprietar() == proprietar;
	});
}

VectorDinamic<Locuinta> Controller::filtrareDupaSuprafMaiMare(float suprafata){
	return filtrare([suprafata](const Locuinta& locuinta) {
		return locuinta.getSuprafata() > suprafata;
	});
}


VectorDinamic<Locuinta> Controller::filtrareDupaPlata(string platit)
{
	return filtrare([platit](const Locuinta& locuinta) {
		return locuinta.getPlatit() == platit;
	});
}



VectorDinamic<Locuinta> Controller::getCopieLista()
{
	return this->repo.getCopieLista();
}









