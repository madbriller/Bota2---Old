#include "manageteams.h"
#include "ui_manageteams.h"
#include "addteam.h"

manageTeams::manageTeams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageTeams)
{
    ui->setupUi(this);
    updateTeamModel();
}

manageTeams::~manageTeams()
{
    delete ui;
}

void manageTeams::updateTeamModel() {
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    this->teamList = new QSqlQueryModel();
    teamList->setQuery("SELECT teamName, teamTier, teamLocation FROM teams", db);
    teamList->sort(0,Qt::DescendingOrder);
    ui->tableTeamView->setModel(teamList);
    db.close(); // for close connection
}

void manageTeams::on_butAddTeam_clicked()
{
    addTeam dialog;
    dialog.setModal(true);
    dialog.exec();
    updateTeamModel();
}

void manageTeams::on_butClose_clicked()
{
    this->close();
}

void manageTeams::on_butRemoveTeam_clicked()
{
    //here!
}
