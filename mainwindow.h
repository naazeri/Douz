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

	bool player[3][3];
	bool computer[3][3];

	int step;
	const short col, row;

	const QString p, c;
	QPushButton ***btn;


	void initData();
	void resetScore();

	bool available(const int&, const int&) const;

	void commitPlayer(const int&, const int&);
	void commitComputer(const int&, const int&);

	void  where(const int&, const int&);
	void firstMove(const int&, const int&);
	void firstMoveInSide(const int&, const int&);
	void firstMoveInMiddle(const int &, const int &);
	void firstMoveInCenter();

	void think(const int&, const int&);

};

#endif // MAINWINDOW_H
