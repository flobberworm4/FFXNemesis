#include "FFXNemesis.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    FFXNemesis ffxNemesis;
    ffxNemesis.show();
    ffxNemesis.setMinimumHeight(540);
    ffxNemesis.setMinimumWidth(440);

    return a.exec();
}
