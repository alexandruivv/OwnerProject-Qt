#include "VectorDinamic.h"
#include "Locuinta.h"
#include <QtWidgets/QWidget>
#include "ui_proiect.h"
#include <QListView>
#include <QLabel>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QTableWidget>
#include <QGroupBox>
#include <QComboBox>
#include "Controller.h"

class mainWindow : public QWidget
{
private:
	Controller& ctrl;
	QHBoxLayout *mainLayout;
	QFormLayout *firstLayout;
	QFormLayout *secondLayout;
	QFormLayout *thirdLayout;
	QFormLayout *fourthLayout;
	QListWidget *listaProp;
	QListWidget *listaPlati;

	QLabel *listaCase;
	QLabel *infCase;
	QLabel *id;
	QLabel *proprietar;
	QLabel *supraf;
	QLabel *impozit;
	QLabel *infPlati;
	QLabel *evidenta;

	QListWidgetItem *capLista;

	QLineEdit *idTxt;
	QLineEdit *proprietarTxt;
	QLineEdit *suprafTxt;
	QLineEdit *impozitTxt;
	QLineEdit *filtrTxt;
	
	QPushButton *adauga;
	QPushButton *modifica;
	QPushButton *sterge;
	QPushButton *butSortare;
	QPushButton *reset;
	QPushButton *filtrpropr;
	QPushButton *filtrsuprafmaimare;
	QPushButton *achitat;
	QPushButton *neachitat;
	QPushButton *curataListaPlati;

	QComboBox *selectareEvidenta;
	void construieste();

	int pozlocuintaSelectata;
	Locuinta locuintaSelectata;
public:
	mainWindow(Controller&);
	void conectare();
	void adaugaInLista();
	void adaugaInLista(const VectorDinamic<Locuinta>&);
	void adaugaInListaPlati(const VectorDinamic<Locuinta>&);
	void curata();


};

