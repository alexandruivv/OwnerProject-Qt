#include "mainWindow.h"
#include <QMessageBox>
#include <string>
mainWindow::mainWindow(Controller& ctrl):ctrl{ctrl}{
	construieste();
}

void mainWindow::conectare()
{
	QObject::connect(adauga, &QPushButton::clicked, [&]() {
		try{
			ctrl.adaugaLocuinta(idTxt->text().toStdString(), proprietarTxt->text().toStdString(), suprafTxt->text().toFloat(), impozitTxt->text().toFloat(), selectareEvidenta->currentText().toStdString());
			adaugaInLista();
			curata();
		}
		catch(RepoEx& ex){
			QMessageBox::critical(this, "Eroare:", QString::fromStdString(ex.what()));
		}
		catch(ValidatorException& ex){
			QMessageBox::critical(this, "Eroare:", QString::fromStdString(ex.what()));
		}
		
	});

	QObject::connect(listaProp, &QListWidget::itemSelectionChanged, [&]() {
		if (listaProp->selectedItems().count() > 0) {
			
			QString q = listaProp->selectedItems()[0]->text();
			QStringList a = q.split(".\t");

			this->pozlocuintaSelectata = a[0].toInt()-1;
			this->locuintaSelectata = this->ctrl.element(this->pozlocuintaSelectata);

			QStringList b = a[1].split("\t");
			idTxt->setText(b[0]);
			proprietarTxt->setText(b[1]);
			suprafTxt->setText(b[2]);
			impozitTxt->setText(b[3]);
			if(this->locuintaSelectata.getPlatit() == "Platit"){
				selectareEvidenta->setCurrentIndex(0);
			}
			else{
				selectareEvidenta->setCurrentIndex(1);
			}
			
		}
		else return;

	});

	QObject::connect(sterge, &QPushButton::clicked, [&]() {
		try {
			ctrl.stergeLocuinta(this->pozlocuintaSelectata);
			adaugaInLista();
			curata();
		}
		catch (RepoEx& ex) {
			QMessageBox::critical(this, "Eroare:", QString::fromStdString(ex.what()));
		}
	});

	QObject::connect(butSortare, &QPushButton::clicked, [&]() {
		VectorDinamic<Locuinta> vectorSortat{ this->ctrl.sortare() };
		adaugaInLista(vectorSortat);
		curata();
	});

	QObject::connect(reset, &QPushButton::clicked, [&]() {
		adaugaInLista();
		curata();
	});

	QObject::connect(modifica, &QPushButton::clicked, [&]() {
		try{
			ctrl.modificaLocuinta(this->pozlocuintaSelectata, idTxt->text().toStdString(), proprietarTxt->text().toStdString(), suprafTxt->text().toFloat(), impozitTxt->text().toFloat(), selectareEvidenta->currentText().toStdString());
			adaugaInLista();
		}
		catch(RepoEx& ex){
			QMessageBox::critical(this, "Eroare:", QString::fromStdString(ex.what()));
		}
		catch(ValidatorException& ex){
			QMessageBox::critical(this, "Eroare:", QString::fromStdString(ex.what()));
		}
		curata();
	});

	QObject::connect(filtrpropr, &QPushButton::clicked, [&]() {
		VectorDinamic<Locuinta> listaFiltrata{ this->ctrl.filtrareDupaProprietar(filtrTxt->text().toStdString()) };
		adaugaInLista(listaFiltrata);
		curata();
	});

	QObject::connect(filtrsuprafmaimare, &QPushButton::clicked, [&]() {
		VectorDinamic<Locuinta> listaFiltrata{ this->ctrl.filtrareDupaSuprafMaiMare(filtrTxt->text().toFloat()) };
		adaugaInLista(listaFiltrata);
		curata();
	});

	QObject::connect(achitat, &QPushButton::clicked, [&]() {
		listaPlati->setDisabled(false);
		VectorDinamic<Locuinta> listaFiltrata{ this->ctrl.filtrareDupaPlata("Platit") };
		adaugaInListaPlati(listaFiltrata);
		curata();
	});

	QObject::connect(neachitat, &QPushButton::clicked, [&]() {
		listaPlati->setDisabled(false);
		VectorDinamic<Locuinta> listaFiltrata{ this->ctrl.filtrareDupaPlata("Neplatit") };
		adaugaInListaPlati(listaFiltrata);
		curata();
	});

	QObject::connect(curataListaPlati, &QPushButton::clicked, [&]() {
		listaPlati->clear();
		listaPlati->setDisabled(true);
	});
}

void mainWindow::adaugaInLista()
{
	auto lista = this->ctrl.getCopieLista();
	adaugaInLista(lista);
}

void mainWindow::adaugaInLista(const VectorDinamic<Locuinta>& lista)
{
	listaProp->clear();
	capLista = new QListWidgetItem(QString::fromStdString("NR.\t") + QString::fromStdString("Nr.Casa\t") + QString::fromStdString("Proprietar\t") + QString::fromStdString("Suprafata\t") + QString::fromStdString("Impozit\t") + QString::fromStdString("Evidenta"));
	capLista->setBackgroundColor(Qt::lightGray);
	capLista->setFlags(Qt::ItemIsEnabled);
	listaProp->addItem(capLista);
	Iterator<Locuinta> it(lista);
	int j = 1;
	while (it.valid())
	 {
		Locuinta loc = it.element();
		QString det = QString::fromStdString(loc.getId()) + "\t" + QString::fromStdString(loc.getProprietar()) + "\t" + QString::number(loc.getSuprafata()) + "\t" + QString::number(loc.getImpozit()) + "\t" + QString::fromStdString(loc.getPlatit());
		QListWidgetItem *item = new QListWidgetItem(QString::number(j) + ".\t" + det);
		listaProp->addItem(item);
		it.urmator();
		j++;
	}
}

void mainWindow::adaugaInListaPlati(const VectorDinamic<Locuinta>& lista)
{
	listaPlati->clear();
	capLista = new QListWidgetItem(QString::fromStdString("NR.\t") + QString::fromStdString("Nr.Casa\t") + QString::fromStdString("Proprietar\t") + QString::fromStdString("Suprafata\t") + QString::fromStdString("Impozit\t") + QString::fromStdString("Evidenta"));
	capLista->setBackgroundColor(Qt::lightGray);
	capLista->setFlags(Qt::ItemIsEnabled);
	listaPlati->addItem(capLista);
	Iterator<Locuinta> it(lista);
	int j = 1;
	while (it.valid())
	{
		Locuinta loc = it.element();
		QString det = QString::fromStdString(loc.getId()) + " \t" + QString::fromStdString(loc.getProprietar()) + "\t" + QString::number(loc.getSuprafata()) + "\t" + QString::number(loc.getImpozit()) + "\t" + QString::fromStdString(loc.getPlatit());
		QListWidgetItem *item = new QListWidgetItem(QString::number(j) + ".\t" + det);
		listaPlati->addItem(item);
		it.urmator();
		j++;
	}
}

void mainWindow::curata()
{
	idTxt->clear();
	proprietarTxt->clear();
	suprafTxt->clear();
	impozitTxt->clear();
	filtrTxt->clear();
}


void mainWindow::construieste(){
	//layout-ul principal
	mainLayout = new QHBoxLayout(this);
	//primul layout
	firstLayout = new QFormLayout;
	mainLayout->addLayout(firstLayout);
	listaProp = new QListWidget;

	
	adaugaInLista();
	listaProp->setMinimumHeight(207);
	listaProp->setMinimumWidth(500);
	listaCase = new QLabel{ "Lista locuinte" };
	firstLayout->addRow(listaCase);
	firstLayout->addRow(listaProp);
	reset = new QPushButton{ "&Revenire la lista locuinte" };
	firstLayout->addRow(reset);
	butSortare = new QPushButton{ "&Sortare dupa impozit" };
	firstLayout->addRow(butSortare);
	//al doilea layout
	secondLayout = new QFormLayout;

	mainLayout->addLayout(secondLayout);
	infCase = new QLabel{ "Informatii locuinta" };
	secondLayout->addRow(infCase);
	id = new QLabel{ "Numar:" };
	idTxt = new QLineEdit;
	
	secondLayout->addRow(id, idTxt);

	proprietar = new QLabel{ "Proprietar:" };
	proprietarTxt = new QLineEdit;
	secondLayout->addRow(proprietar, proprietarTxt);

	/*prenume = new QLabel{ "Prenume:" };
	prenumeTxt = new QLineEdit;
	secondLayout->addRow(prenume, prenumeTxt);
	*/
	supraf = new QLabel{ "Suprafata:" };
	suprafTxt = new QLineEdit;
	secondLayout->addRow(supraf, suprafTxt);

	impozit = new QLabel{ "Impozit:" };
	impozitTxt = new QLineEdit;
	secondLayout->addRow(impozit, impozitTxt);

	adauga = new QPushButton{ "&Adauga" };
	sterge = new QPushButton{ "&Sterge" };
	modifica = new QPushButton{ "&Modifica" };

	evidenta = new QLabel{ "Evidenta" };
	selectareEvidenta = new QComboBox;
	selectareEvidenta->addItem(tr("Platit"));
	selectareEvidenta->addItem(tr("Neplatit"));

	secondLayout->addRow(evidenta, selectareEvidenta);

	secondLayout->addRow(adauga);
	secondLayout->addRow(sterge);
	secondLayout->addRow(modifica);
	
	filtrTxt = new QLineEdit;
	filtrTxt->setPlaceholderText("Camp filtrare");
	secondLayout->addRow(filtrTxt);

	filtrpropr = new QPushButton{ "&Filtrare dupa proprietar" };
	secondLayout->addRow(filtrpropr);

	filtrsuprafmaimare = new QPushButton{ "&Filtrare dupa suprafata mai mare" };
	secondLayout->addRow(filtrsuprafmaimare);
	
	//al treilea layout
	thirdLayout = new QFormLayout;
	mainLayout->addLayout(thirdLayout);

	infPlati = new QLabel{ "Evidenta plata impozit" };
	thirdLayout->addRow(infPlati);

	listaPlati = new QListWidget;
	listaPlati->setDisabled(true);
	
	thirdLayout->addRow(listaPlati);

	listaPlati->setMinimumHeight(237);
	listaPlati->setMinimumWidth(500);

	achitat = new QPushButton{ "&Proprietari care au platit impozitul" };
	thirdLayout->addRow(achitat);

	neachitat = new QPushButton{ "&Proprietari care nu au platit impozitul" };
	thirdLayout->addRow(neachitat);

	curataListaPlati = new QPushButton{ "&Curata lista proprietari" };
	thirdLayout->addRow(curataListaPlati);

	conectare();
}

