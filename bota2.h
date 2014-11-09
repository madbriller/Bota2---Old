#ifndef BOTA2_H
#define BOTA2_H

#include <QMainWindow>

namespace Ui {
class Bota2;
}

class Bota2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bota2(QWidget *parent = 0);
    ~Bota2();
    void teamUpdate();


private slots:
    void on_actionTeamAdd_triggered();

    void on_actionAdd_Match_triggered();

    void on_comboTeam1_activated(const QString &arg1);

    void on_comboTeam2_activated(const QString &arg1);

    void on_actionTeamManage_triggered();

private:
    Ui::Bota2 *ui;
    void overallVSWinUpdate();
    void VS7DayUpdate();
    void VS30DayUpdate();
    void BO1VSUpdate();
    void BO2VSUpdate();
    void BO3VSUpdate();
    void BO5VSUpdate();
    void BO7VSUpdate();
    void T1OverallUpdate();
    void T2OverallUpdate();
    void T17DayUpdate();
    void T27DayUpdate();
    void T130DayUpdate();
    void T230DayUpdate();
    int teamNameToID(QString teamName);

};

#endif // BOTA2_H
