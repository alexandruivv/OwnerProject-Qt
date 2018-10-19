#pragma once
#include "VectorDinamic.h"
#include "Locuinta.h"
#include <exception>
#include <string>
using namespace std;

class RepoEx:public exception{
private:
	string msg;
public:
	RepoEx(string msg) :msg{msg}{}
	virtual const char* what() {
		return msg.c_str();
	}
};

class Repository
{
private:
	VectorDinamic<Locuinta> lista_locuinte;
public:
	//default constructor
	Repository() {};
	Repository(const Repository& ot) = delete;
	//returneaza lungimea listei de locuinte
	
	Locuinta element(int);
	//verifica daca casa cu numarul dat exista
	bool cauta(string);
	//modifica locuinta de pe o pozitie cu o locuinta
	void modificaLocuinta(int, Locuinta&);
	//adauga la sfarsit o locuinta
	void adaugaSfarsit(Locuinta&);
	//sterge locuinta de pe o anumita pozitie
	void stergePozitie(int poz);
	//returneaza lista cu locuinte
	VectorDinamic<Locuinta>& getAll();
	//returneaza o copie a listei de locuinte
	VectorDinamic<Locuinta> getCopieLista();
};

