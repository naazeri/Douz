#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	p('*'), c('O'),
	col(3), row(3),
	step(1)
{

	ui->setupUi(this);

	initData();


}

MainWindow::~MainWindow() {

	delete ui;

}

void MainWindow::initData() {

	btn = new QPushButton** [row];

	for (short i = 0; i < row; ++i) {

		btn[i] = new QPushButton* [col];

	}

	btn[0][0] = ui->btn_00;
	btn[0][1] = ui->btn_01;
	btn[0][2] = ui->btn_02;
	btn[1][0] = ui->btn_10;
	btn[1][1] = ui->btn_11;
	btn[1][2] = ui->btn_12;
	btn[2][0] = ui->btn_20;
	btn[2][1] = ui->btn_21;
	btn[2][2] = ui->btn_22;

	resetScore();

}

void MainWindow::resetScore() {

	for (short i = 0; i < row; ++i) {
		for (short j = 0; j < col; ++j) {

			player[i][j] = false;
			computer[i][j] = false;
		}
	}
}

bool MainWindow::available(const int &i, const int &j) const{

	return (player[i][j] && computer[i][j])? false : true;

}

void MainWindow::where(const int &i, const int &j) {

	if ((i == 0 && j == 0)
			|| (i == 0 && j == 2)
			|| (i == 2 && j == 0)
			|| (i == 2 && j == 2)) {

		place = side;
		return;

	}

	else if ((i == 0 && j == 1)
			|| (i == 1 && j == 0)
			|| (i == 1 && j == 2)
			|| (i == 2 && j == 1)) {

		place = middle;
		return;

	}

	else if ((i == 1 && j == 1)) {

		place = center;
		return;

	}

}

void MainWindow::commitPlayer(const int &i, const int &j) {

	btn[i][j]->setText(p);
	btn[i][j]->setFlat(true);

	player[i][j] = true;

}

void MainWindow::commitComputer(const int &i, const int &j) {

	btn[i][j]->setText(c);
	btn[i][j]->setFlat(true);

	computer[i][j] = true;

}

void MainWindow::on_btn_00_clicked() {

	const int i = 0;
	const int j = 0;

	if (available(i, j)) {

		place = side;
		commitPlayer(i,  j);
		think(i, j);

	}

}

void MainWindow::on_btn_01_clicked() {



}

void MainWindow::on_btn_02_clicked() {

	const int i = 0;
	const int j = 2;

	if (available(i, j)) {

		place = side;
		commitPlayer(i,  j);
		think(i, j);

	}

}

void MainWindow::on_btn_10_clicked() {



}

void MainWindow::on_btn_11_clicked() {

	const int i = 1;
	const int j = 1;

	if (available(i, j)) {

		place = center;
		commitPlayer(i,  j);
		think(i, j);

	}

}

void MainWindow::on_btn_12_clicked() {



}

void MainWindow::on_btn_20_clicked() {

	const int i = 2;
	const int j = 0;

	if (available(i, j)) {

		place = side;
		commitPlayer(i,  j);
		think(i, j);

	}

}

void MainWindow::on_btn_21_clicked() {



}

void MainWindow::on_btn_22_clicked() {

	const int i = 2;
	const int j = 2;

	if (available(i, j)) {

		place = side;
		commitPlayer(i,  j);
		think(i, j);


	}

}

void MainWindow::think(const int &i, const int &j) {

	switch (step) {

	case 1:

		firstMove(i, j);
		step++;
		break;

	case 2:

		break;

	case 3:

		break;

	case 4:

		break;

	case 5:

		break;

	case 6:

		break;

	case 7:

		break;

	case 8:

		break;

	default:
		break;
	}

}

void MainWindow::firstMove(const int &i, const int &j) {

//	where(i, j);

	if (place == side) {

		firstMoveInSide(i, j);

	}

	else if (place == middle) {

		firstMoveInMiddle(i, j);

	}

	else if (place == center) {

		firstMoveInCenter();

	}

}

void MainWindow::firstMoveInSide(const int &i, const int &j) {

	if (i == 0 && j == 0) {

		commitComputer(i + 2, j + 2);

	}

	else if (i == 0 && j == 2) {

		commitComputer(i + 2, j - 2);

	}

	else if (i == 2 && j == 0) {

		commitComputer(i - 2, j + 2);

	}

	else if (i == 2 && j == 2) {

		commitComputer(i - 2, j - 2);

	}

}

void MainWindow::firstMoveInMiddle(const int &i, const int &j) {

	/*if (available(0, 0)) {

		commitComputer(0, 0); //top-left

	}

	else if (available(0, 2)) {

		commitComputer(0, 2); //top-right
	}

	else if (available(2, 2)) {

		commitComputer(0, 2);
	}

	else if (available(0, 2)) {

		commitComputer(0, 2);
	}*/

}

void MainWindow::firstMoveInCenter() {

	commitComputer(0,0);

}
