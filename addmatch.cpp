#include "addmatch.h"
#include "ui_addmatch.h"

addMatch::addMatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMatch)
{
    ui->setupUi(this);
}

addMatch::~addMatch()
{
    delete ui;
}
