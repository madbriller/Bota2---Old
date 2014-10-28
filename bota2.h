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

private:
    Ui::Bota2 *ui;
};

#endif // BOTA2_H
