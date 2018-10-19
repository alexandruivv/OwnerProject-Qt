/********************************************************************************
** Form generated from reading UI file 'proiect.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROIECT_H
#define UI_PROIECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProiectClass
{
public:

    void setupUi(QWidget *ProiectClass)
    {
        if (ProiectClass->objectName().isEmpty())
            ProiectClass->setObjectName(QStringLiteral("ProiectClass"));
        ProiectClass->resize(600, 400);

        retranslateUi(ProiectClass);

        QMetaObject::connectSlotsByName(ProiectClass);
    } // setupUi

    void retranslateUi(QWidget *ProiectClass)
    {
        ProiectClass->setWindowTitle(QApplication::translate("ProiectClass", "Proiect", 0));
    } // retranslateUi

};

namespace Ui {
    class ProiectClass: public Ui_ProiectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROIECT_H
