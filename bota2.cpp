#include "bota2.h"
#include "ui_bota2.h"
#include "addteam.h"
#include "addmatch.h"
#include "QtSQL/QtSQL"
#include "qdebug.h"


Bota2::Bota2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bota2)
{
    ui->setupUi(this);
    teamUpdate();
}

Bota2::~Bota2()
{
    delete ui;
}

void Bota2::on_actionTeamAdd_triggered()
{
    addTeam dialog;
    dialog.setModal(true);
    dialog.exec();
    teamUpdate();
}

void Bota2::teamUpdate() {
    ui->comboTeam1->clear();
    ui->comboTeam2->clear();
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT teamName FROM teams");
    query.exec();
    while (query.next()) {
        ui->comboTeam1->addItem(query.value(0).toString());
        ui->comboTeam2->addItem(query.value(0).toString());
    }
    db.close(); // for close connection


}

void Bota2::on_actionAdd_Match_triggered() {
    addMatch dialog;
    dialog.setModal(true);
    dialog.exec();
    //matchUpdate();
}

int Bota2::teamNameToID(QString teamName)
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


void Bota2::on_comboTeam1_activated(const QString &arg1)
{
    overallVSWinUpdate();
}


void Bota2::on_comboTeam2_activated(const QString &arg1)
{
    overallVSWinUpdate();
}

void Bota2::overallVSWinUpdate() {
    float teamOne = 0, teamTwo = 0, overall = 0;
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM matches WHERE (teamOne = ? AND teamTwo = ?) OR (teamOne = ? AND teamTwo = ?)");
    query.addBindValue(teamNameToID(ui->comboTeam1->currentText()));
    query.addBindValue(teamNameToID(ui->comboTeam2->currentText()));
    query.addBindValue(teamNameToID(ui->comboTeam2->currentText()));
    query.addBindValue(teamNameToID(ui->comboTeam1->currentText()));
    query.exec();
    while (query.next()) {
        if (query.value(3).toInt() == teamNameToID(ui->comboTeam1->currentText())) {
            teamOne += 1;
        }
        else if (query.value(3).toInt() == teamNameToID(ui->comboTeam2->currentText())) {
            teamTwo += 1;
        }
        overall += 1;
    }
    db.close(); // for close connection
    QString team1 = QString::number(teamOne/overall*100);
    QString team2 = QString::number(teamTwo/overall*100);
    ui->lbl1O->setText(team1 + "%");
    ui->lbl2O->setText(team2 + "%");
}

