#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace ZG::Panel {

class JsonRequester : public QObject 
{
    Q_OBJECT
private:
public:
    using QObject::QObject;
    
    void post (
        const QUrl & url,
        const QByteArray &data,
        void (*slot) (QNetworkReply *reply)
    );

    //TODO: get and put
    
signals:
private slots:
};

}



