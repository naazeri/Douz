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

	enum placeHolder {
		side = 0, middle, center
	}place;

	enum positionHolder {
		top = 0, left = 0, bottom = 2, right = 2
	};

	bool player[3][3];
	bool computer[3][3];

	const short col, row;
	int step;
	int i, j;

	const QString p;
	const QString c;
	QPushButton ***btn;


	void initData();
	void resetScore();

	bool available() const;

	void move();

	void playerMove();
	void commitPlayer();

	void computerMove();
	void commitComputer(const int&, const int&);

	void firstMove();
	void firstMoveInSide();
	void firstMoveInMiddle();
	void firstMoveInCenter();

	void move2();
	void move3();
	void move4();
	void move5();
	void move6();
	void move7();

	void think();

};

#endif // MAINWINDOW_H
