#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	p('*'), c('O'),
	col(3), row(3),
	step(0)
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

int MainWindow::where(const int &i, const int &j) const {

	if ((i == 0 && j == 0)
			|| (i == 0 && j == 2)
			|| (i == 2 && j == 0)
			|| (i == 2 && j == 2)) {

		return 0; //Side

	}

	else if ((i == 0 && j == 1)
			|| (i == 1 && j == 0)
			|| (i == 1 && j == 2)
			|| (i == 2 && j == 1)) {

		return 1; //Middle

	}

	else if ((i == 1 && j == 1)) {

		return 2;//center

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
	const int j = 2;

	if (available(i, j)) {

		commitPlayer(i,  j);

		think(i, j, 0); //think(0, 0, side);

		step++;

	}

}

void MainWindow::on_btn_01_clicked() {



}

void MainWindow::on_btn_02_clicked() {

	const int i = 0;
	const int j = 2;

	if (available(i, j)) {

		commitPlayer(i, j);

		think(i, j, 0); //think(0, 0, side);

		step++;

	}

}

void MainWindow::on_btn_10_clicked() {



}

void MainWindow::on_btn_11_clicked() {



}

void MainWindow::on_btn_12_clicked() {



}

void MainWindow::on_btn_20_clicked() {

	const int i = 2;
	const int j = 0;

	if (available(i, j)) {

		commitPlayer(i, j);

		think(i, j, 0); //think(0, 0, side);

		step++;

	}

}

void MainWindow::on_btn_21_clicked() {



}

void MainWindow::on_btn_22_clicked() {

	const int i = 2;
	const int j = 2;

	if (available(i, j)) {

		commitPlayer(i, j);

		think(i, j, 0); //think(0, 0, side);

		step++;

	}

}

void MainWindow::think(const int &i, const int &j, const int &position) {

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			qDebug() << player[i][j];
			qDebug() << computer[i][j];
		}
		qDebug() << "-----";
	}
	qDebug() << "*-----------*";

	if (step == 0) {

		firstMove(i, j, position);

	}

}

void MainWindow::firstMove(const int &i, const int &j, const int &position) {

//	const int whereIs = where(i, j);

	if (position == 0) {

		firstMoveInSide(i, j);

	}

	else if (position == 1) {

		firstMoveInMiddle(i, j);

	}

	else if (position == 2) {

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



}

void MainWindow::firstMoveInCenter() {

	commitComputer(0,0);

}
