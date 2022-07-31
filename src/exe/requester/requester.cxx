#include "./requester.hxx"

#include <QString>
#include <QObject>
#include <QDebug>
#include <QByteArray>
#include <QUrlQuery>
#include <QtCore>
#include <QTextCodec>

#include <iostream>

#include <nlohmann/json.hpp>

ZG::Panel::Requester::Requester(){
    QObject::connect(&manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            QString answer = QString::fromUtf8(reply->readAll());

            qDebug() << answer;
        }
    );

    request.setUrl(QUrl("http://178.250.157.247:8443/client/get/land/all"));
    request.setRawHeader("Content-Type", "application/json");
    manager.post(request, (QUrlQuery()).toString(QUrl::FullyEncoded).toUtf8());
}




