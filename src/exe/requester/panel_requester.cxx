#include "./panel_requester.hxx"

#include <QDebug>
#include <QUrlQuery>

namespace ZG::Panel {

PanelRequester::PanelRequester (
    QString host, 
    QString port,
    QString token,
    QObject * parent
) : host  {host},
    port  {port},
    token {token},
    JsonRequester (parent)
{ }

void PanelRequester::clientGetLandAll (void (*slot)(QNetworkReply *reply)) {
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/client/get/land/all");
    
    qDebug() << QStringLiteral("Request: ") << path;

    post(path, QUrlQuery().query().toUtf8(), slot);

}

}