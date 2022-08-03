#pragma once

#include "json_requester/json_requester.hxx"

#include <QUrlQuery>

namespace ZG::Panel {

class PanelRequester : public JsonRequester 
{
    Q_OBJECT

private:
    QString host;
    QString port;
    QString token;

public:
    PanelRequester (
        QString host = QString("178.250.157.247"), 
        QString port = QString("8443"), 
        QString token = "",
        QObject * parent = nullptr
    );
    
    template <typename T>
    void clientGetLandAll (
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    );

    //TODO: get and put

signals:

private slots:

};

}

template <typename T>
void ZG::Panel::PanelRequester::clientGetLandAll (T * slotAcceptor, void (T::*slot)(QNetworkReply *reply)) {
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/client/get/land/all");
    
    qDebug() << QStringLiteral("Request: ") << path;

    post(path, QUrlQuery().query().toUtf8(), slotAcceptor, slot);

}