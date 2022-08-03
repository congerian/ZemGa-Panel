#include "./json_requester.hxx"

#include <QString>
#include <QObject>
#include <QDebug>
#include <QByteArray>
#include <QUrlQuery>
#include <QtCore>
#include <QTextCodec>

#include <iostream>

namespace ZG::Panel {

void JsonRequester::post (
    const QUrl & url,
    const QByteArray &data,
    void (*slot) (QNetworkReply *reply)
) 
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [manager] (QNetworkReply *reply) 
        {
            manager->deleteLater();
        }
    );
    QObject::connect(manager, &QNetworkAccessManager::finished, this, slot);
    
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Content-Type", "application/json");
    manager->post(request, data);
}

}


