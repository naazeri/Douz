#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTime>

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

bool MainWindow::available() const{

	return (player[i][j] || computer[i][j])? false : true;

}

void MainWindow::move() {

	if (available()) {

		playerMove();
		computerMove();
	}

}

void MainWindow::playerMove() {

	commitPlayer();

}

void MainWindow::commitPlayer() {

	player[i][j] = true;

	btn[i][j]->setText(p);
	btn[i][j]->setFlat(true);

}

void MainWindow::computerMove() {

	think();

}

void MainWindow::commitComputer(const int &i, const int &j) {

	computer[i][j] = true;

	btn[i][j]->setText(c);
	btn[i][j]->setFlat(true);

}


void MainWindow::on_btn_00_clicked() {

	place = side;
	i = top; j = left;

	move();

}

void MainWindow::on_btn_01_clicked() {



}

void MainWindow::on_btn_02_clicked() {

	place = side;
	i = top;j = right;

	move();

}

void MainWindow::on_btn_10_clicked() {



}

void MainWindow::on_btn_11_clicked() {

	place = center;
	i = middle; j = middle;

	move();

}

void MainWindow::on_btn_12_clicked() {



}

void MainWindow::on_btn_20_clicked() {

	place = side;
	i = bottom; j = left;

	move();

}

void MainWindow::on_btn_21_clicked() {



}

void MainWindow::on_btn_22_clicked() {

	place = side;
	i = bottom; j = right;

	move();

}

void MainWindow::think() {

	switch (step) {

	case 1:

		firstMove();
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


void MainWindow::firstMove() {


	if (place == side) {

		firstMoveInSide();

	}

	else if (place == middle) {

		firstMoveInMiddle();

	}

	else if (place == center) {

		firstMoveInCenter();

	}

	step++;

}

void MainWindow::firstMoveInSide() {

	commitComputer(middle, middle);


//	if (i == top && j == left) {

//		commitComputer(bottom, right);

//	}

//	else if (i == top && j == right) {

//		commitComputer(bottom, left);

//	}

//	else if (i == bottom && j == left) {

//		commitComputer(top, right);

//	}

//	else if (i == bottom && j == right) {

//		commitComputer(top, left);

//	}

}

void MainWindow::firstMoveInMiddle() {

	if (i == top && j == middle) {

		commitComputer(top, left);

	}

	else if (i == middle && j == left) {

		commitComputer(top, left);

	}

	else if (i == middle && j == right) {

		commitComputer(top, right);

	}

	else if (i == bottom && j == middle) {

		commitComputer(top, middle);

	}

}

void MainWindow::firstMoveInCenter() {

	QTime time = QTime::currentTime();
	qsrand(time.msec());

	int rand = qrand() %4;

	if (rand == 0) {

		commitComputer(0,0);
	}
	else if (rand == 1) {

		commitComputer(0,2);
	}
	else if (rand == 2) {

		commitComputer(2,0);
	}
	else if (rand == 3) {

		commitComputer(2,2);
	}

}

void MainWindow::move2() {

	if (i == top && j == left) {


	}

}

void MainWindow::move3() {


}

void MainWindow::move4() {


}

void MainWindow::move5() {


}

void MainWindow::move6() {


}

void MainWindow::move7() {


}
