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

private:
    Ui::addMatch *ui;
};

#endif // ADDMATCH_H
