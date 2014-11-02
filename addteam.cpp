#include "addteam.h"
#include "ui_addteam.h"
#include <QtSql/QtSql>

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

void addTeam::on_butAdd_clicked()
{
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO teams (teamName, teamTier, teamLocation) VALUES (?, ?, ?) ");
    query.addBindValue(ui->texName->text());
    query.addBindValue(ui->spinTier->value());
    query.addBindValue(ui->texLocation->text());
    query.exec();
    db.close(); // for close connection
    this->close();
}

void addTeam::on_butCancel_clicked()
{
    this->close();
}
