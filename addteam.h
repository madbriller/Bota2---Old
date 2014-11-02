#ifndef ADDTEAM_H
#define ADDTEAM_H

#include <QDialog>

namespace Ui {
class addTeam;
}

class addTeam : public QDialog
{
    Q_OBJECT

public:
    explicit addTeam(QWidget *parent = 0);
    ~addTeam();

private slots:
    void on_butAdd_clicked();

    void on_butCancel_clicked();

private:
    Ui::addTeam *ui;
};

#endif // ADDTEAM_H
