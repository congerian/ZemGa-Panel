#pragma once

#include "json_requester/json_requester.hxx"

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
    
    void clientGetLandAll (
        void (*slot) (QNetworkReply *reply)
    );

    //TODO: get and put

signals:

private slots:

};

}
