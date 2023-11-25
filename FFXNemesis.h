#ifndef FFXNEMESIS_H
#define FFXNEMESIS_H

#include <QMainWindow>

class FiendWidget;
class Fiend;
class Area;

namespace Ui
{
    class FFXNemesis;
}

class FFXNemesis : public QMainWindow
{
    Q_OBJECT

public:
    FFXNemesis(QWidget* parent = 0);
    ~FFXNemesis();

    void keyPressEvent(QKeyEvent*);

public slots:
    void onCurrentIndexChanged(int index);

private:
    void createAreas();

    Ui::FFXNemesis* ui_;
    std::vector<Area*> areas_;
    std::vector<FiendWidget*> fiendWidgets_;
    int currentIndex_;

    static const int MAXIMUM_NUMBER_OF_FIENDS;
};

#endif
