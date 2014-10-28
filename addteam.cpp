#include "addteam.h"
#include "ui_addteam.h"

addTeam::addTeam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTeam)
{
    ui->setupUi(this);
}

addTeam::~addTeam()
{
    delete ui;
}
