#include "addmatch.h"
#include "ui_addmatch.h"
#include <QtSql/QtSql>

addMatch::addMatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMatch)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT teamName FROM teams;");
    query.exec();
    QStringList teamList;
    while (query.next()) {
        teamList.insert(0, query.value(0).toString());
    }
    teamList.sort();
    db.close(); // for close connection
    ui->comboTeam1->addItems(teamList);
    ui->comboTeam2->addItems(teamList);
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
    query.addBindValue(teamNameToID(ui->comboTeam1->currentText()));
    query.addBindValue(teamNameToID(ui->comboTeam2->currentText()));
    query.addBindValue(teamNameToID(ui->comboWinner->currentText()));
    query.addBindValue(ui->spinBO->value());
    query.addBindValue(ui->spin1Score->value());
    query.addBindValue(ui->spin2Score->value());
    query.addBindValue(ui->dateEdit->dateTime().date().toString());
    query.exec();

    db.close(); // for close connection
    this->close();
}

int addMatch::teamNameToID(QString teamName)
{
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT teamID FROM teams WHERE teamName = ?");
    query.addBindValue(teamName);
    query.exec();
    while (query.next()) {
        db.close(); // for close connection
        return (query.value(0).toInt()); //returns ID
    }
    return -1; //no team name match

}

void addMatch::on_butCancel_clicked()
{
    this->close();
}
