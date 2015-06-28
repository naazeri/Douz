#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_btn_00_clicked();
	void on_btn_01_clicked();
	void on_btn_02_clicked();
	void on_btn_10_clicked();
	void on_btn_11_clicked();
	void on_btn_12_clicked();
	void on_btn_20_clicked();
	void on_btn_21_clicked();
	void on_btn_22_clicked();

private:
	Ui::MainWindow *ui;

	unsigned int game[3][3];

	int i, j;
	QPushButton ***btn;

	const short col, row;
	const QString p, c;

	void initData();

	void move();
	void playerMove();
	void commitComputer();

	void think();

	bool canContinue();
	bool attackForWin();
	bool justAttack();
	bool attack();
	bool notToLose();
	bool justDefence();
	bool defence();

	void win(const bool&);
	void lose(const bool&);

	void endGame(const bool&);
};

#endif // MAINWINDOW_H
