#include "addmatch.h"
#include "ui_addmatch.h"
#include <QtSql/QtSql>

addMatch::addMatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMatch)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT teamName FROM teams;");
    query.exec();
    while (query.next()) {
        ui->comboTeam1->addItem(query.value(0).toString());
        ui->comboTeam2->addItem(query.value(0).toString());
    }
    db.close(); // for close connection
    ui->comboWinner->addItem(ui->comboTeam1->currentText());
    ui->comboWinner->addItem(ui->comboTeam2->currentText());
}

addMatch::~addMatch()
{
    delete ui;
}

void addMatch::on_comboTeam1_activated(const QString &arg1) //updates winner combo box
{
    ui->comboWinner->clear();
    ui->comboWinner->addItem(arg1);
    ui->comboWinner->addItem(ui->comboTeam2->currentText());
}

void addMatch::on_comboTeam2_activated(const QString &arg1) //updates winner combo box
{
    ui->comboWinner->clear();
    ui->comboWinner->addItem(arg1);
    ui->comboWinner->addItem(ui->comboTeam1->currentText());
}

void addMatch::on_butComplete_clicked()
{
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO matches (teamOne, teamTwo, teamWinner, matchType, teamOneScore, teamTwoScore, Date) VALUES (?, ?, ?, ?, ?, ?, ?) ");
    query.addBindValue(ui->comboTeam1->currentText());
    query.addBindValue(ui->comboTeam2->currentText());
    query.addBindValue(ui->comboWinner->currentText());
    query.addBindValue(ui->spinBO->value());
    query.addBindValue(ui->spin1Score->value());
    query.addBindValue(ui->spin2Score->value());
    query.addBindValue(ui->dateEdit->dateTime().toString());
    query.exec();
    db.close(); // for close connection
    this->close();
}

void addMatch::on_butCancel_clicked()
{
    this->close();
}
