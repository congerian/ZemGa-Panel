#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace ZG::Panel{

class Requester : public QObject 
{
    Q_OBJECT
private:
    QNetworkAccessManager manager;
    QNetworkRequest request;
public:
    Requester();
signals:
private slots:
};

}



