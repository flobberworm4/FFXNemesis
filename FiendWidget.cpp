#include "FiendWidget.h"
#include "Fiend.h"

#include <QHBoxLayout>
#include <QProgressBar>
#include <QLabel>

const int FiendWidget::MINIMUM_CAPTURE_COUNT = 0;
const int FiendWidget::MAXIMUM_CAPTURE_COUNT = 10;

FiendWidget::FiendWidget(int keyPress, QWidget* parent)
: QWidget(parent)
, keyLabel_(new QLabel("F" + QString::number(keyPress + 1) + ":", parent))
, fiendLabel_(new QLabel(parent))
, progressBar_(new QProgressBar(this))
, addButton_(new QPushButton("+", this))
, subtractButton_(new QPushButton("-", this))
, captureCount_(0)
, keyPress_(keyPress + 1)
{
    fiendLabel_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(keyLabel_);
    layout->addWidget(fiendLabel_);
    layout->addWidget(progressBar_);
    layout->addWidget(addButton_);
    layout->addWidget(subtractButton_);

    QFont keyFont;
    keyFont.setBold(true);
    keyFont.setPixelSize(14);
    keyLabel_->setFont(keyFont);

    QFont fiendFont;
    fiendFont.setPixelSize(14);
    fiendLabel_->setFont(fiendFont);

    addButton_->setMaximumWidth(50);
    subtractButton_->setMaximumWidth(50);

    progressBar_->setRange(MINIMUM_CAPTURE_COUNT, MAXIMUM_CAPTURE_COUNT);
    progressBar_->setValue(captureCount_);
    progressBar_->setMinimumWidth(150);

    setLayout(layout);

    connect(addButton_, SIGNAL(pressed()), this, SLOT(onButtonAdd()));
    connect(subtractButton_, SIGNAL(pressed()), this, SLOT(onButtonSubtract()));
}



FiendWidget::~FiendWidget()
{
}



void FiendWidget::onButtonAdd()
{
  if (captureCount_ < MAXIMUM_CAPTURE_COUNT)
  {
      ++captureCount_;
      progressBar_->setValue(captureCount_);
  }
}



void FiendWidget::onButtonSubtract()
{
  if (captureCount_ > MINIMUM_CAPTURE_COUNT)
  {
      --captureCount_;
      progressBar_->setValue(captureCount_);
  }
}



void FiendWidget::setLabel(const QString& fiendLabel)
{
    fiendLabel_->setText(fiendLabel);
}



void FiendWidget::setCaptureCount(int captureCount)
{
    captureCount_ = captureCount;
}



int FiendWidget::getCaptureCount() const
{
    return captureCount_;
}



void FiendWidget::refresh()
{
    progressBar_->setValue(captureCount_);
}



