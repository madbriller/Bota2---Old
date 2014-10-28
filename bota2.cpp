#include "bota2.h"
#include "ui_bota2.h"

Bota2::Bota2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bota2)
{
    ui->setupUi(this);
}

Bota2::~Bota2()
{
    delete ui;
}
