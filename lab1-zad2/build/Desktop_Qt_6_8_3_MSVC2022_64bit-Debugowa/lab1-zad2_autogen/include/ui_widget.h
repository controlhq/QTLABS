/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_4;
    QTextEdit *textEdit;
    QLabel *label_5;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QOpenGLWidget *openGLWidget;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(604, 567);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(Widget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMaximumSize(QSize(800, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        doubleSpinBox = new QDoubleSpinBox(Widget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMaximumSize(QSize(800, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox);

        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        doubleSpinBox_2 = new QDoubleSpinBox(Widget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setMaximumSize(QSize(800, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_2);

        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");
        textEdit->setMaximumSize(QSize(800, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, textEdit);


        verticalLayout_2->addLayout(formLayout);

        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName("checkBox");

        verticalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(Widget);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout_2->addWidget(checkBox_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName("radioButton_4");

        verticalLayout->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName("radioButton_5");

        verticalLayout->addWidget(radioButton_5);


        verticalLayout_3->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        openGLWidget = new QOpenGLWidget(Widget);
        openGLWidget->setObjectName("openGLWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);
        openGLWidget->setMinimumSize(QSize(250, 250));

        verticalLayout_4->addWidget(openGLWidget);

        verticalSpacer_2 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Nazwa funkcji:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Warto\305\233\304\207 pocz\304\205tkowa:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Warto\305\233\304\207 ko\305\204cowa:", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Opis funkcji:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Opcje", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "U\305\274yj wielu rdzeni", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "Ciemny motyw wykresu", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "Opcje prze\305\202\304\205czalne", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "bardzo dok\305\202adnie", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "dok\305\202adnie", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "optymalnie", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Widget", "szybko", nullptr));
        radioButton_5->setText(QCoreApplication::translate("Widget", "bardzo szybko", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
