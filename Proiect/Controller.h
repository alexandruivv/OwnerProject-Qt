#pragma once
#include "VectorDinamic.h"
#include "Repository.h"
#include "Validator.h"

class Controller
{
private:
	Repository& repo;
	ValidatorLocuinta& validator;
public:
	Controller(Repository& repo, ValidatorLocuinta& validator);

	//functionalitate adauga
	void adaugaLocuinta(string, string, float, float, string);

	//functionalitate sterge
	void stergeLocuinta(int);

	//functionalitate modifica
	void modificaLocuinta(int, string, string, float, float, string);

	//returneaza elementul de o pozitie
	Locuinta element(int);

	//sorteaza locuintele descrescator dupa valoarea impozitului
	VectorDinamic<Locuinta> sortare();

	//returneaza lista de locuinte
	VectorDinamic<Locuinta>& getAll(){
		return this->repo.getAll();
	}

	//filtrare generala
	VectorDinamic<Locuinta> filtrare(function<bool(const Locuinta&)> functie);
	
	//filtrare dupa proprietar
	VectorDinamic<Locuinta> filtrareDupaProprietar(string);

	//filtrare dupa suprafata mai mare decat suprafata data
	VectorDinamic<Locuinta> filtrareDupaSuprafMaiMare(float);

	//filtrare dupa proprietarii care au platit impozitul
	VectorDinamic<Locuinta> filtrareDupaPlata(string);

	//returneaza o copie a listei de locuinte
	VectorDinamic<Locuinta> getCopieLista();
};

