#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "icb.h"

typedef struct {
	int id;
	//QString name;
	char name[20];
}SSS;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
	void OnPush();
	void OnPop();

private:
    Ui::MainWindow *ui;
	Stack<SSS> *m_sss;
	QPushButton *m_btn_push;
	QPushButton *m_btn_pop;
};


#endif // MAINWINDOW_H

