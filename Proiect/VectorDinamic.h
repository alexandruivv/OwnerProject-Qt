#pragma once
#include <string>
#include <assert.h>
#include <functional>
using namespace std;

template<typename T>
class Iterator;

template<typename T>
class VectorDinamic{
private:
	//capacitate
	int capac;
	//dimensiune
	int dim;
	//elemente
	T* elem;

	//redimensionare
	void redim(){
		T* newElems = new T[capac * 2];
		for(int i = 0;i < dim; i++){
			newElems[i] = elem[i];
		}
		delete[] elem;
		this->elem = newElems;
		capac *= 2;
	}

public:

	//pentru a putea accesa componentele vectorului
	friend class Iterator<T>;

	//constructor
	VectorDinamic(){
		this->capac = 10;
		this->dim = 0;
		this->elem = new T[capac];
	}
	VectorDinamic(int cp){
		this->capac = cp;
		this->dim = 0;
		this->elem = new T[capac];
	}

	VectorDinamic(const VectorDinamic& other){
		this->capac = other.capac;
		this->dim = 0;
		this->elem = new T[this->capac];
		for (int i = 0; i < other.dimensiune(); i++)
			this->adaugaSfarsit(other.element(i));
	}
	//returneaza dimensiunea vectorului
	int dimensiune() const{
		return this->dim;
	}

	//verifica daca lista e vida
	bool vida() const {
		return this->dim == 0;
	}

	//returneaza elementul de pe pozitia poz
	T element(int poz) const{
		return this->elem[poz];
	}

	//inlocuieste elementul de pe pozitia poz cu elementul el
	void modifica(int poz, const T& el){
		this->elem[poz] = el;
	}

	//adauga la sfarsitul vectorului
	void adaugaSfarsit(const T& el) {
		//daca s-a atins capacitatea maxima redimensionam
		if(capac == dim){
			redim();
		}
		this->elem[dim++] = el;
	}

	//adauga un element pe pozitia poz in vector
	void adaugaPozitie(int poz, const T& el){
		//daca s-a atins capacitatea maxima redimensionam
		if(capac == dim){
			redim();
		}
		for(int i=dim; i>=poz+1; i--){
			this->elem[i] = this->elem[i - 1];
		}
		this->elem[poz] = el; 
		this->dim++;
	}

	//sterge elementul elem de la sfarsitul vectorului
	T stergeSfarsit(){
		return this->elem[--this->dim];
	}

	//sterge elementul de pe pozitia poz
	T stergePozitie(int poz) {
		T el = this->elem[poz];
		for(int i=poz;i<dim-1;i++){
			this->elem[i] = this->elem[i + 1];
		}
		dim--;
		return el;
	}

	//arborele cu radacina i devine maxheap
	void construiesteMaxHeap(int dimens, int i, std::function<bool(const T&, const T&)>& fctCompara){
		int parinte = i;
		int fiuSt = 2 * i + 1;
		int fiuDr = 2 * i + 2;
		
		if (fiuSt < dimens && !fctCompara(this->elem[parinte], this->elem[fiuSt])){
			parinte = fiuSt;
		}

		if (fiuDr < dimens && !fctCompara(this->elem[parinte], this->elem[fiuDr])) {
			parinte = fiuDr;
		}

		if(parinte != i){
			std::swap(this->elem[i], this->elem[parinte]);
			construiesteMaxHeap(dimens, parinte, fctCompara);
		}
	}

	//sorteaza vectorul folosind metoda de sortare HeapSort
	void sortareVector(std::function<bool(const T&, const T&)> fctCompara) {
		for (int i = this->dim / 2 - 1; i >= 0; i--){
			construiesteMaxHeap(this->dim, i, fctCompara);
		}
		for (int i = this->dim - 1; i >= 0; i--){
			std::swap(this->elem[0], this->elem[i]);
			construiesteMaxHeap(i, 0, fctCompara);
		}
	}

	//creeaza un iterator pe vector
	void iterator(){
		return Iterator(*this);
	}

	T& operator[](unsigned poz) {
		return this->elem[poz];
	}
	//destructor
	~VectorDinamic(){
		delete[] elem;
	}
	static void testVectorDinamic(){
		VectorDinamic<int> numere(10);
		assert(numere.dimensiune() == 0);
		numere.adaugaSfarsit(1);
		assert(numere.dimensiune() == 1);
		numere.adaugaSfarsit(2);
		assert(numere.dimensiune() == 2);
		assert(numere.elem[0] == 1);
		assert(numere.elem[1] == 2);
	}
};

template<typename T>
class Iterator{
private:
	const VectorDinamic<T>& v;
	int curent;
	int aux;
public:
	Iterator(const VectorDinamic<T>& v) :v{ v } {
		curent = 0;
		aux = 0;
	}

	bool valid() {
		return this->curent < v.dimensiune();

	}

	T element() const {
		return v.elem[curent];
	}

	void urmator(){
		curent += 2;
		if (aux == 0 && !valid())
		{
			aux = 1;
			curent = 1;
		}
		
	}
};

