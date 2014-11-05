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

private:
    Ui::Bota2 *ui;
    void overallVSWinUpdate();
    int teamNameToID(QString teamName);

};

#endif // BOTA2_H
