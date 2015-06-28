#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	p('*'), c('O'),
	col(3), row(3)
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

	for (short i = 0, count = 0; i < row; ++i, count = 0) {
		for (short j = 0; j < col; ++j) {

			game[i][j] = 0;

		}
	}

}

void MainWindow::move() {

	if (game[i][j] != 1) {

		playerMove();
		think();
	}

}

void MainWindow::playerMove() {

	game[i][j] = 1;

	btn[i][j]->setText(p);
	btn[i][j]->setFlat(true);

}

void MainWindow::commitComputer() {

	game[i][j] = 2;

	btn[i][j]->setText(c);
	btn[i][j]->setFlat(true);

}

void MainWindow::on_btn_00_clicked() {

//	ui->btn_00->setStyleSheet("QPushButton {color: blue}");

	i = 0; j = 0;

	move();

}

void MainWindow::on_btn_01_clicked() {

	i = 0; j = 1;

	move();

}

void MainWindow::on_btn_02_clicked() {


	i = 0; j = 2;

	move();

}

void MainWindow::on_btn_10_clicked() {

	i = 1; j = 0;

	move();

}

void MainWindow::on_btn_11_clicked() {

	i = 1; j = 1;

	move();

}

void MainWindow::on_btn_12_clicked() {

	i = 1; j = 2;

	move();

}

void MainWindow::on_btn_20_clicked() {


	i = 2; j = 0;

	move();

}

void MainWindow::on_btn_21_clicked() {

	i = 2; j = 1;

	move();

}

void MainWindow::on_btn_22_clicked() {


	i = 2; j = 2;

	move();

}

void MainWindow::think() {

	if (canContinue()) {	// if not lose till now then...
		if (!attackForWin()) { // if cant win then...

			if (!notToLose()) {

				if (!justAttack()) {

					justDefence();
				}
			}
		}
	}

	else {

		endGame(false);	// we lose, end game

	}

}

bool MainWindow::canContinue() {

	for (int i=0, cnt1=0, cnt2=0; i < row; ++i, cnt1 = cnt2 = 0) {

		for (int j = 0; j < col; ++j) {

			if (game[i][j] == 2) {	//row

				cnt1++;
			}

			if (game[j][i] == 2) {	//col

				cnt2++;
			}
		}

		if (cnt1 == 3 || cnt2 == 3) {

			return false;
		}
	}

	///// orib /////
	if (game[0][0] == 1 && game[1][1] == 1 && game[2][2] == 1) {

		return false;
	}

	if (game[0][2] == 1 && game[1][1] == 1 && game[2][0] == 1) {

		return false;
	}

	return true;

}

bool MainWindow::attackForWin() {

	for (int i=0, cnt1=0, cnt2=0; i < row; ++i, cnt1 = cnt2 = 0) {

		for (int j = 0; j < col; ++j) {

			if (game[i][j] == 2) {	//row

				cnt1++;
			}

			if (game[j][i] == 2) {	//col

				cnt2++;
			}
		}

		if (cnt1 == 2) {

			this->i = i;
			win(true);
			return true;
		}

		if (cnt2 == 2) {

			this->j = i;
			win(false);
			return true;
		}
	}

	///// orib /////
	if (game[0][0] == 2 && game[1][1] == 2) {

		i = j = 2;

		commitComputer();
		endGame(true);
		return true;
	}

	if (game[0][0] == 2 && game[2][2] == 2) {

		i = j = 1;

		commitComputer();
		endGame(true);
		return true;
	}

	if (game[1][1] == 2 && game[2][2] == 2) {

		i = j = 0;

		commitComputer();
		endGame(true);
		return true;
	}

	if (game[0][2] == 2 && game[1][1] == 2) {

		i = 2; j = 0;

		commitComputer();
		endGame(true);
		return true;
	}

	if (game[0][2] == 2 && game[2][0] == 2) {

		i = 1; j = 1;

		commitComputer();
		endGame(true);
		return true;
	}

	if (game[1][1] == 2 && game[2][0] == 2) {

		i = 0; j = 0;

		commitComputer();
		endGame(true);
		return true;
	}

	return false;

}

void MainWindow::win(const bool &row) {

	if (row) {

		if (game[i][0] == 2 && game[i][1] == 2) {

			j = 2;
			commitComputer();

		}

		else if (game[i][0] == 2 && game[i][2] == 2) {

			j = 1;
			commitComputer();

		}

		else if (game[i][1] == 2 &&  game[i][2] == 2) {

			j = 0;
			commitComputer();

		}

	}

	else {

		if (game[0][j] == 2 && game[1][j] == 2) {

			i = 2;
			commitComputer();

		}

		else if (game[0][j] == 2 && game[2][j] == 2) {

			i = 1;
			commitComputer();

		}

		else if (game[1][j] == 2 &&  game[2][j] == 2) {

			i = 0;
			commitComputer();

		}

	}

	endGame(true);

}

bool MainWindow::justAttack() {

	for (int i = 0; i < row; ++i) {

		for (int j = 0; j < col; ++j) {

			if (game[i][j] == 2) {

				this->i = i;
				this->j = j;

				if(attack()) {

					return true;
				}
			}
		}
	}

	return false;

}

bool MainWindow::attack() {

	if (i == 0) {

		if (j == 0) {

			if (game[0][1] == 0) {

				i = 0; j = 1;
				commitComputer();
				return true;
			}

			else if (game[1][0]) {

				i = 1; j = 0;
				commitComputer();
				return true;
			}
		}

		else if (j == 1) {

			if (game[0][0] == 0) {

				i = 0; j = 0;
				commitComputer();
				return true;
			}

			else if (game[0][2]) {

				i = 0; j = 2;
				commitComputer();
				return true;
			}

			else if (game[1][1]) {

				i = 1; j = 1;
				commitComputer();
				return true;
			}
		}

		else if (j == 2) {

			if (game[0][1] == 0) {

				i = 0; j = 1;
				commitComputer();
				return true;
			}

			else if (game[1][2]) {

				i = 1; j = 2;
				commitComputer();
				return true;
			}
		}
	}

	else if (i == 1) {

		if (j == 0) {

			if (game[0][0] == 0) {

				i = 0; j = 0;
				commitComputer();
				return true;
			}

			else if (game[1][1]) {

				i = 1; j = 1;
				commitComputer();
				return true;
			}

			else if (game[2][0]) {

				i = 2; j = 0;
				commitComputer();
				return true;
			}
		}

		else if (j == 1) {

			if (game[0][1] == 0) {

				i = 0; j = 1;
				commitComputer();
				return true;
			}

			else if (game[1][0]) {

				i = 1; j = 0;
				commitComputer();
				return true;
			}

			else if (game[1][2]) {

				i = 1; j = 2;
				commitComputer();
				return true;
			}

			else if (game[2][1]) {

				i = 2; j = 1;
				commitComputer();
				return true;
			}
		}

		else if (j == 2) {

			if (game[0][2] == 0) {

				i = 0; j = 2;
				commitComputer();
				return true;
			}

			else if (game[1][1]) {

				i = 1; j = 1;
				commitComputer();
				return true;
			}

			else if (game[2][2]) {

				i = 2; j = 2;
				commitComputer();
				return true;
			}
		}
	}

	else if (i == 2) {

		if (j == 0) {

			if (game[1][0] == 0) {

				i = 1; j = 0;
				commitComputer();
				return true;
			}

			else if (game[2][1]) {

				i = 2; j = 1;
				commitComputer();
				return true;
			}
		}

		else if (j == 1) {

			if (game[2][0] == 0) {

				i = 2; j = 0;
				commitComputer();
				return true;
			}

			else if (game[1][1]) {

				i = 1; j = 1;
				commitComputer();
				return true;
			}

			else if (game[2][2]) {

				i = 2; j = 2;
				commitComputer();
				return true;
			}
		}

		else if (j == 2) {

			if (game[1][2] == 0) {

				i = 1; j = 2;
				commitComputer();
				return true;
			}

			else if (game[2][1]) {

				i = 2; j = 1;
				commitComputer();
				return true;
			}
		}
	}

	return false;
}

bool MainWindow::notToLose() {

	for (int i=0, cnt1=0, cnt2=0; i < row; ++i, cnt1 = cnt2 = 0) {

		for (int j = 0; j < col; ++j) {

			if (game[i][j] == 1) {

				cnt1++;
			}

			if (game[j][i] == 1) {

				cnt2++;
			}
		}

		if (cnt1 == 2) {

			this->i = i;
			lose(true);
			return true;
		}

		if (cnt2 == 2) {

			this->j = i;
			lose(false);
			return true;
		}
	}

	///// orib /////
	if (game[0][0] == 1 && game[1][1] == 1) {

		i = j = 2;

		commitComputer();
		return true;
	}

	if (game[0][0] == 1 && game[2][2] == 1) {

		i = j = 1;

		commitComputer();
		return true;
	}

	if (game[1][1] == 1 && game[2][2] == 1) {

		i = j = 0;

		commitComputer();
		return true;
	}

	if (game[0][2] == 1 && game[1][1] == 1) {

		i = 2; j = 0;

		commitComputer();
		return true;
	}

	if (game[0][2] == 1 && game[2][0] == 1) {

		i = 1; j = 1;

		commitComputer();
		return true;
	}

	if (game[1][1] == 1 && game[2][0] == 1) {

		i = 0; j = 0;

		commitComputer();
		return true;
	}

	return false;

}

void MainWindow::lose(const bool &row) {

	if (row) {

		if (game[i][0] == 1 && game[i][1] == 1) {

			j = 2;
			commitComputer();

		}

		else if (game[i][0] == 1 && game[i][2] == 1) {

			j = 1;
			commitComputer();

		}

		else if (game[i][1] == 1 &&  game[i][2] == 1) {

			j = 0;
			commitComputer();

		}

	}

	else {

		if (game[0][j] == 1 && game[1][j] == 1) {

			i = 2;
			commitComputer();

		}

		else if (game[0][j] == 1 && game[2][j] == 1) {

			i = 1;
			commitComputer();

		}

		else if (game[1][j] == 1 &&  game[2][j] == 1) {

			i = 0;
			commitComputer();

		}
	}
}

bool MainWindow::justDefence() {

	for (int i = 0; i < row; ++i) {

		for (int j = 0; j < col; ++j) {

			if (game[i][j] == 1) {

				this->i = i;
				this->j = j;

				if (defence()) {

					return true;
				}
			}
		}
	}

	return false;

}

bool MainWindow::defence() {

	if (i == 0) {

		if (j == 0) {

			if (game[0][1] == 0) {

				i = 0; j = 1;
				commitComputer();
				return true;
			}

			else if (game[1][0]) {

				i = 1; j = 0;
				commitComputer();
				return true;
			}
		}

		else if (j == 1) {

			if (game[0][0] == 0) {

				i = 0; j = 0;
				commitComputer();
				return true;
			}

			else if (game[0][2]) {

				i = 0; j = 2;
				commitComputer();
				return true;
			}

			else if (game[1][1]) {

				i = 1; j = 1;
				commitComputer();
				return true;
			}
		}

		else if (j == 2) {

			if (game[0][1] == 0) {

				i = 0; j = 1;
				commitComputer();
				return true;
			}

			else if (game[1][2]) {

				i = 1; j = 2;
				commitComputer();
				return true;
			}
		}
	}

	else if (i == 1) {

		if (j == 0) {

			if (game[0][0] == 0) {

				i = 0; j = 0;
				commitComputer();
				return true;
			}

			else if (game[1][1]) {

				i = 1; j = 1;
				commitComputer();
				return true;
			}

			else if (game[2][0]) {

				i = 2; j = 0;
				commitComputer();
				return true;
			}
		}

		else if (j == 1) {

			if (game[0][1] == 0) {

				i = 0; j = 1;
				commitComputer();
				return true;
			}

			else if (game[1][0]) {

				i = 1; j = 0;
				commitComputer();
				return true;
			}

			else if (game[1][2]) {

				i = 1; j = 2;
				commitComputer();
				return true;
			}

			else if (game[2][1]) {

				i = 2; j = 1;
				commitComputer();
				return true;
			}
		}

		else if (j == 2) {

			if (game[0][2] == 0) {

				i = 0; j = 2;
				commitComputer();
				return true;
			}

			else if (game[1][1]) {

				i = 1; j = 1;
				commitComputer();
				return true;
			}

			else if (game[2][2]) {

				i = 2; j = 2;
				commitComputer();
				return true;
			}
		}
	}

	else if (i == 2) {

		if (j == 0) {

			if (game[1][0] == 0) {

				i = 1; j = 0;
				commitComputer();
				return true;
			}

			else if (game[2][1]) {

				i = 2; j = 1;
				commitComputer();
				return true;
			}
		}

		else if (j == 1) {

			if (game[2][0] == 0) {

				i = 2; j = 0;
				commitComputer();
				return true;
			}

			else if (game[1][1]) {

				i = 1; j = 1;
				commitComputer();
				return true;
			}

			else if (game[2][2]) {

				i = 2; j = 2;
				commitComputer();
				return true;
			}
		}

		else if (j == 2) {

			if (game[1][2] == 0) {

				i = 1; j = 2;
				commitComputer();
				return true;
			}

			else if (game[2][1]) {

				i = 2; j = 1;
				commitComputer();
				return true;
			}
		}
	}

	return false;

}

void MainWindow::endGame(const bool &winComputer) {

	if (winComputer) {

		ui->resualt_lbl->setText("<font color='red'>You Lose</font>");

	}

	else {

		ui->resualt_lbl->setText("<font color='green'>You Win</font>");

	}

}
