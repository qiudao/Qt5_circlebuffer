#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QTextBrowser>
#include <QDebug>

template<typename T>
void displayInfo(T& t)
{
	qDebug() << "--------------------------------------------------------";
	qDebug() << QString("cap: %1").arg(t.cap());
	qDebug() << QString("len: %1").arg(t.dataAvail());
	for (int i = 0; i < t.dataAvail(); i++)
		qDebug() << QString("[%1] name: \"%2\", id: %3").arg(i).arg(t.at(i).name).arg(t.at(i).id);

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

	m_btn_push 	= new QPushButton("Push", this);
	m_btn_pop	= new QPushButton("Pop", this);
	rightLayout->addWidget(m_btn_push);
	rightLayout->addWidget(m_btn_pop);
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	cwidget->setLayout(mainLayout);
	setCentralWidget(cwidget);

	connect(m_btn_push, SIGNAL(clicked()), this, SLOT(OnPush()));
	connect(m_btn_pop, SIGNAL(clicked()), this, SLOT(OnPop()));

	Stack<int> stack(30);
	m_sss = new Stack<SSS>(20);

	/* Form Layout */
	QWidget *infoWidget = new QWidget(this);
	leftLayout->addWidget(infoWidget);

	/* operation */
	SSS s1, s2;
	s1.id = 0;
	//s1.name = QString("this is sss.");
	memcpy(s1.name, "hello", strlen("hello"));
	for (int i = 0; i < 30; i++)
		m_sss->push(s1);

	for (int i = 0; i < 10; i++)
		m_sss->pop(&s2);

	/* display */
	displayInfo(*m_sss);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OnPush()
{
	SSS s = {0};
	s.id = 2;
	//s.name = QString("good");
	memcpy(s.name, "good", strlen("good"));
	m_sss->push(s);
	displayInfo(*m_sss);
}
void MainWindow::OnPop()
{
	SSS s;
	if (m_sss->pop(&s))
	{
		qDebug() << QString("Pop: name %1, id %2").arg(s.name).arg(s.id);
		displayInfo(*m_sss);
	}
}
