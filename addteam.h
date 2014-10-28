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

private:
    Ui::addTeam *ui;
};

#endif // ADDTEAM_H
