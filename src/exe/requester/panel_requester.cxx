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

}