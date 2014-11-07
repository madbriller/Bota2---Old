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
    BO1VSUpdate();
    BO2VSUpdate();
    BO3VSUpdate();
    BO5VSUpdate();
    BO7VSUpdate();
}


void Bota2::on_comboTeam2_activated(const QString &arg1)
{
    overallVSWinUpdate();
    BO1VSUpdate();
    BO2VSUpdate();
    BO3VSUpdate();
    BO5VSUpdate();
    BO7VSUpdate();
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
    if (overall > 0) {
        ui->lbl1O->setText(team1 + "%");
        ui->lbl2O->setText(team2 + "%");
    } else {
        ui->lbl1O->setText("N/A");
        ui->lbl2O->setText("N/A");
    }
}

void Bota2::BO1VSUpdate() {
    float teamOne = 0, teamTwo = 0, overall = 0;
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM matches WHERE matchType = 1 AND ((teamOne = ? AND teamTwo = ?) OR (teamOne = ? AND teamTwo = ?))");
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
    if (overall > 0) {
        ui->lbl1BO1->setText(team1 + "%");
        ui->lbl2BO1->setText(team2 + "%");
    } else {
        ui->lbl1BO1->setText("N/A");
        ui->lbl2BO1->setText("N/A");
    }
}

void Bota2::BO2VSUpdate() {
    float teamOne = 0, teamTwo = 0, overall = 0;
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM matches WHERE matchType = 2 AND ((teamOne = ? AND teamTwo = ?) OR (teamOne = ? AND teamTwo = ?))");
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
    if (overall > 0) {
        ui->lbl1BO2->setText(team1 + "%");
        ui->lbl2BO2->setText(team2 + "%");
    } else {
        ui->lbl1BO2->setText("N/A");
        ui->lbl2BO2->setText("N/A");
    }
}

void Bota2::BO3VSUpdate() {
    float teamOne = 0, teamTwo = 0, overall = 0;
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM matches WHERE matchType = 3 AND ((teamOne = ? AND teamTwo = ?) OR (teamOne = ? AND teamTwo = ?))");
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
    if (overall > 0) {
        ui->lbl1BO3->setText(team1 + "%");
        ui->lbl2BO3->setText(team2 + "%");
    } else {
        ui->lbl1BO3->setText("N/A");
        ui->lbl2BO3->setText("N/A");
    }
}

void Bota2::BO5VSUpdate() {
    float teamOne = 0, teamTwo = 0, overall = 0;
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM matches WHERE matchType = 5 AND ((teamOne = ? AND teamTwo = ?) OR (teamOne = ? AND teamTwo = ?))");
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
    if (overall > 0) {
        ui->lbl1BO5->setText(team1 + "%");
        ui->lbl2BO5->setText(team2 + "%");
    } else {
        ui->lbl1BO5->setText("N/A");
        ui->lbl2BO5->setText("N/A");
    }
}

void Bota2::BO7VSUpdate() {
    float teamOne = 0, teamTwo = 0, overall = 0;
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM matches WHERE matchType = 7 AND ((teamOne = ? AND teamTwo = ?) OR (teamOne = ? AND teamTwo = ?))");
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
    if (overall > 0) {
        ui->lbl1BO7->setText(team1 + "%");
        ui->lbl2BO7->setText(team2 + "%");
    } else {
        ui->lbl1BO7->setText("N/A");
        ui->lbl2BO7->setText("N/A");
    }
}

