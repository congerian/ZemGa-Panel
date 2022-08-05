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
    
    template <typename T>
    void post (
        const QUrl & url,
        const QByteArray &data,
        T * slotAcceptor, 
        void (T::*slot) (QNetworkReply *reply)
    );

    template <typename T, typename Functor>
    void post (
        const QUrl & url,
        const QByteArray &data,
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T, typename Functor>
    void get (
        const QUrl & url,
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T>
    void get (
        const QUrl & url,
        T * slotAcceptor, 
        void (T::*slot) (QNetworkReply *reply)
    );

    //TODO: get and put
};

}

namespace ZG::Panel {

template <typename T>
void JsonRequester::post (
    const QUrl & url,
    const QByteArray &data,
    T * slotAcceptor, 
    void (T::*slot) (QNetworkReply *reply)
) 
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [manager] (QNetworkReply *reply) 
        {
            manager->deleteLater();
        }
    );
    QObject::connect(manager, &QNetworkAccessManager::finished, slotAcceptor, slot);
    
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Content-Type", "application/json");
    manager->post(request, data);
}

template <typename T, typename Functor>
void JsonRequester::post (
    const QUrl & url,
    const QByteArray &data,
    T * slotAcceptor, 
    Functor slot
) 
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [manager] (QNetworkReply *reply) 
        {
            manager->deleteLater();
        }   
    );
    QObject::connect(manager, &QNetworkAccessManager::finished, slotAcceptor, slot);
    
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Content-Type", "application/json");
    manager->post(request, data);
}

template <typename T, typename Functor>
void JsonRequester::get (
    const QUrl & url,
    T * slotAcceptor, 
    Functor slot
)
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [manager] (QNetworkReply *reply) 
        {
            manager->deleteLater();
        }   
    );
    QObject::connect(manager, &QNetworkAccessManager::finished, slotAcceptor, slot);
    
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

template <typename T>
void JsonRequester::get (
    const QUrl & url,
    T * slotAcceptor, 
    void (T::*slot) (QNetworkReply *reply)
)
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [manager] (QNetworkReply *reply) 
        {
            manager->deleteLater();
        }   
    );
    QObject::connect(manager, &QNetworkAccessManager::finished, slotAcceptor, slot);
    
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

}
