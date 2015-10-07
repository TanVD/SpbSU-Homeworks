#pragma once
#include "KeyControl.h"
#include "FramesUpdater.h"

class KeyManager : public QObject
{
    Q_OBJECT

public:
    KeyManager(QList<KeyControl*> controls, FramesUpdater *updater, QObject *parent = 0);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QList<KeyControl *> controls;
    FramesUpdater *updater;

private slots:
    void repressButton();
};

