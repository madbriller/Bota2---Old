#ifndef ADDMATCH_H
#define ADDMATCH_H

#include <QDialog>

namespace Ui {
class addMatch;
}

class addMatch : public QDialog
{
    Q_OBJECT

public:
    explicit addMatch(QWidget *parent = 0);
    ~addMatch();

private slots:
    void on_comboTeam1_activated(const QString &arg1);
    void on_comboTeam2_activated(const QString &arg1);

    void on_butComplete_clicked();

    void on_butCancel_clicked();

private:
    Ui::addMatch *ui;
};

#endif // ADDMATCH_H
