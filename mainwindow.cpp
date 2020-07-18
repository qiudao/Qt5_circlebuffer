#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include "icb.h"

template<typename T>
void displayInfo(QWidget *w, T& t)
{
	QFormLayout *formLayout = new QFormLayout;
	w->setLayout(formLayout);
	QLabel *lb_sss_cap  = new QLabel("hello", w);
	QLabel *lb_sss_len  = new QLabel("hello", w);

	formLayout->addRow("cap", lb_sss_cap);
	formLayout->addRow("len", lb_sss_len);

	/* display */
	lb_sss_cap->setText(QString::number(t.cap()));
	lb_sss_len->setText(QString::number(t.dataAvail()));

	for (int i = 0; i < t.dataAvail(); i++)
	{
		QString out;
		QLabel *lb_name = new QLabel(w);
		formLayout->addRow(QString("name%1").arg(i), lb_name);
		out = QString("[%1] name: \"%2\", id: %3").arg(i).arg(t.at(i).name).arg(t.at(i).id);
		lb_name->setText(out);
	}
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	QWidget *cwidget = new QWidget(this);
	QHBoxLayout *mainLayout = new QHBoxLayout;
	QVBoxLayout *leftLayout = new QVBoxLayout;
	QHBoxLayout *rightLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	cwidget->setLayout(mainLayout);
	setCentralWidget(cwidget);

	Stack<int> stack(30);

	typedef struct {
		int id;
		QString name;
	}SSS;
	Stack<SSS> sss(20);

	/* Form Layout */
	QWidget *infoWidget = new QWidget(this);
	leftLayout->addWidget(infoWidget);

	/* operation */
	SSS s1, s2;
	s1.id = 0;
	s1.name = QString("this is sss.");
	sss.push(s1);
	sss.push(s1);
	sss.push(s1);
	sss.pop(&s2);

	/* display */
	displayInfo(infoWidget, sss);
}

MainWindow::~MainWindow()
{
    delete ui;
}

