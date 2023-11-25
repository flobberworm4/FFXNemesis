#ifndef FIENDWIDGET_H
#define FIENDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QKeyEvent>

class FiendWidget : public QWidget
{
    Q_OBJECT
public:
    FiendWidget(int keyPress, QWidget* parent = 0);
    ~FiendWidget();

    void setLabel(const QString& fiendLabel);
    void setCaptureCount(int captureCount);
    int getCaptureCount() const;
    void refresh();

public slots:
    void onButtonAdd();
    void onButtonSubtract();

private:
    QLabel* keyLabel_;
    QLabel* fiendLabel_;
    QProgressBar* progressBar_;
    QPushButton* addButton_;
    QPushButton* subtractButton_;
    int captureCount_;
    int keyPress_;

    static const int MINIMUM_CAPTURE_COUNT;
    static const int MAXIMUM_CAPTURE_COUNT;
};

#endif
