#ifndef MANAGETEAMS_H
#define MANAGETEAMS_H

#include <QDialog>
#include <QtSQL/QtSQL>

namespace Ui {
class manageTeams;
}

class manageTeams : public QDialog
{
    Q_OBJECT

public:
    explicit manageTeams(QWidget *parent = 0);
    ~manageTeams();

private slots:
    void on_butAddTeam_clicked();

    void on_butClose_clicked();

    void on_butRemoveTeam_clicked();

private:
    Ui::manageTeams *ui;
    QSqlQueryModel *teamList;
    void updateTeamModel();
};

#endif // MANAGETEAMS_H
