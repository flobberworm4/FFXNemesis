#include "FFXNemesis.h"
#include "ui_FFXNemesis.h"
#include "FiendWidget.h"
#include "Fiend.h"
#include "Area.h"

const int FFXNemesis::MAXIMUM_NUMBER_OF_FIENDS = 12;

FFXNemesis::FFXNemesis(QWidget* parent)
: QMainWindow(parent)
, ui_(new Ui::FFXNemesis)
, areas_()
, fiendWidgets_()
, currentIndex_(0)
{
    ui_->setupUi(this);
    ui_->areaComboBox->setFocusPolicy(Qt::NoFocus);
    createAreas();

   for (std::vector<Area*>::iterator i = areas_.begin(); i != areas_.end(); ++i)
   {
       Area* area = *i;
       ui_->areaComboBox->addItem(area->getName());
   }

   for (int i = 0; i < MAXIMUM_NUMBER_OF_FIENDS; ++i)
   {
       FiendWidget* fiendWidget = new FiendWidget(i, this);
       ui_->verticalLayout->addWidget(fiendWidget);
       fiendWidgets_.push_back(fiendWidget);
   }

   ui_->verticalLayout->insertStretch(-1, 1);
   ui_->verticalLayout->setSpacing(0);

   connect(ui_->areaComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrentIndexChanged(int)));
   onCurrentIndexChanged(currentIndex_);
}



FFXNemesis::~FFXNemesis()
{
    delete ui_;
}



void FFXNemesis::createAreas()
{
    QStringList besaid;
    besaid << "Dingo" << "Condor" << "Water Flan";

    QStringList kilika;
    kilika << "Dinonix" << "Killer Bee" << "Yellow Element" << "Ragora";

    QStringList miihenHighroad;
    miihenHighroad << "Mi'ihen Fang" << "Ipiria" << "Floating Eye" << "White Element" << "Raldo" << "Vouivre" << "Bomb" << "Dual Horn";

    QStringList mushroomRock;
    mushroomRock << "Raptor" << "Gandarewa" << "Thunder Flan" << "Red Element" << "Lamashtu" << "Funguar" << "Garuda";

    QStringList djoseHighroad;
    djoseHighroad << "Garm" << "Simurgh" << "Bite Bug" << "Snow Flan" << "Bunyip" << "Basilisk" << "Ochu";

    QStringList thunderPlains;
    thunderPlains << "Melusine" << "Aerouge" << "Buer" << "Gold Element" << "Kusariqqu" << "Larva" << "Iron Giant" << "Qactuar";

    QStringList macalania;
    macalania << "Snow Wolf" << "Iguion" << "Wasp" << "Evil Eye" << "Ice Flan" << "Blue Element" << "Murussu" << "Mafdet" << "Xiphos" << "Chimera";

    QStringList bikanel;
    bikanel << "Sand Wolf" << "Alcyone" <<"Mushussu" <<"Zu" <<"Sand Worm" <<"Cactuar";

    QStringList calmLands;
    calmLands << "Skoll" << "Nebiros" << "Flame Flan" << "Shred" << "Anacondaur" << "Ogre" << "Coeurl" << "Chimera Brain" << "Malboro";

    QStringList stolenFaythCavern;
    stolenFaythCavern << "Yowie" << "Imp" << "Dark Element" << "Nidhogg" << "Thorn" << "Valaha" << "Epaaj" << "Ghost" << "Tonberry";

    QStringList mtGagazet;
    mtGagazet << "Bandersnatch" << "Ahriman" << "Dark Flan" << "Grenade" << "Grat" << "Grendel" << "Bashura" << "Mandragora" << "Behemoth" << "Splasher" << "Achelous" << "Maelspike";

    QStringList insideSin;
    insideSin << "Exoray" << "Wraith" << "Gemini A" << "Gemini B" << "Demonolith"<< "Great Malboro"<< "Barbatos" << "Adamantiose" << "Behemoth King";

    QStringList omegaRuins;
    omegaRuins << "Zaurus" << "Floating Death"<< "Black Element" << "Halma" << "Puroboros" << "Spirit" << "Machea" << "Master Coeurl" << "Master Tonberry" << "Varuna";

    areas_.push_back(new Area("Besaid", besaid));
    areas_.push_back(new Area("Kilika", kilika));
    areas_.push_back(new Area("Mi'ihen Highroad", miihenHighroad));
    areas_.push_back(new Area("Mushroom Rock Road", mushroomRock));
    areas_.push_back(new Area("Djose Highroad", djoseHighroad));
    areas_.push_back(new Area("Thunder Plains", thunderPlains));
    areas_.push_back(new Area("Macalania", macalania));
    areas_.push_back(new Area("Bikanel", bikanel));
    areas_.push_back(new Area("Calm Lands", calmLands));
    areas_.push_back(new Area("Cavern of the Stolen Fayth", stolenFaythCavern));
    areas_.push_back(new Area("Mt. Gagazet", mtGagazet));
    areas_.push_back(new Area("Inside Sin", insideSin));
    areas_.push_back(new Area("Omega Ruins", omegaRuins));
}



void FFXNemesis::onCurrentIndexChanged(int index)
{
    Area* currentArea = areas_[currentIndex_];
    QList<Fiend*> currentFiends = currentArea->getFiends();

    int currentCount = 0;
    foreach (Fiend* fiend, currentFiends)
    {
        FiendWidget* fiendWidget = fiendWidgets_[currentCount];

        int captureCount = fiendWidget->getCaptureCount();
        fiend->setCaptureCount(captureCount);

        ++currentCount;
    }

    Area* newArea = areas_[index];
    QList<Fiend*> newFiends = newArea->getFiends();
    int count = 0;
    foreach (Fiend* fiend, newFiends)
    {
        FiendWidget* fiendWidget = fiendWidgets_[count];
        fiendWidget->setVisible(true);

        QString fiendName;
        fiend->getName(fiendName);
        fiendWidget->setLabel(fiendName);

        int captureCount = fiend->getCaptureCount();
        fiendWidget->setCaptureCount(captureCount);
        fiendWidget->refresh();

        ++count;
    }

    size_t numberOfFiends = newFiends.size();
    for (size_t i = numberOfFiends; i < MAXIMUM_NUMBER_OF_FIENDS; ++i)
    {
        FiendWidget* fiendWidget = fiendWidgets_[i];
        fiendWidget->setVisible(false);
    }

    currentIndex_ = index;
}



void FFXNemesis::keyPressEvent(QKeyEvent* event)
{
    int fiendWidgetId = -1;

    switch (event->key())
    {
    case Qt::Key_F1 :
        fiendWidgetId = 0;
        break;
    case Qt::Key_F2 :
        fiendWidgetId = 1;
        break;
    case Qt::Key_F3 :
        fiendWidgetId = 2;
        break;
    case Qt::Key_F4 :
        fiendWidgetId = 3;
        break;
    case Qt::Key_F5 :
        fiendWidgetId = 4;
        break;
    case Qt::Key_F6 :
        fiendWidgetId = 5;
        break;
    case Qt::Key_F7 :
        fiendWidgetId = 6;
        break;
    case Qt::Key_F8 :
        fiendWidgetId = 7;
        break;
    case Qt::Key_F9 :
        fiendWidgetId = 8;
        break;
    case Qt::Key_F10 :
        fiendWidgetId = 9;
        break;
    case Qt::Key_F11 :
        fiendWidgetId = 10;
        break;
    case Qt::Key_F12 :
        fiendWidgetId = 11;
        break;
    };

    if (fiendWidgetId > -1)
    {
        FiendWidget* fiendWidget = fiendWidgets_[fiendWidgetId];
        fiendWidget->onButtonAdd();
    }
}

