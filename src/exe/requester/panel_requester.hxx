#pragma once

#include "json_requester/json_requester.hxx"
#include "data_model/requests/land_edit.hxx"

#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>

#include <nlohmann/json.hpp>

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
        QString token = "KILaiBGIhEMMzaq3sDoSHvPT6R2XTCdORKdmQQphAkFBES3hsYenCJ6RKOTLjEbWoA7o2YCad3tYcePDmZGYnFh0v4FzaMOOLSAqFTHu2ec7IiLbFbz77IT728b9hJF04oE1bY43PkAU0pUDEaMsQzuCvQOPtBMgpFXmUs5HXRKRnRPImzYHIWPHPkOdTySzMLEbMvvqbsTms7qRcvPqL2C72QTlAdM6K6j3PhxwdNe8ko7cl7kikapJqaibwPsG",
        QObject * parent = nullptr
    );
    
    template <typename T>
    void clientGetLandAll (
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    );

    template <typename T, typename Functor>
    void clientGetLandAll (
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T>
    void clientGetLandSingle (
        long id,
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    );

    template <typename T, typename Functor>
    void clientGetLandSingle (
        long id,
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T>
    void adminContacts (
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    );

    template <typename T, typename Functor>
    void adminContacts (
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T>
    void adminAdd (
        LandEditRequest request, 
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    );

    template <typename T, typename Functor>
    void adminAdd (
        LandEditRequest request, 
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T>
    void adminDelete (
        long id,
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    );
    template <typename T, typename Functor>
    void adminDelete (
        long id,
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T>
    void adminUpdate (
        LandEditRequest request,
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    );

    template <typename T, typename Functor>
    void adminUpdate (
        LandEditRequest request,
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T, typename Functor>
    void downloadFile (
        QUrl filePath,
        T * slotAcceptor, 
        Functor slot
    );

    template <typename T>
    void downloadFile (
        QUrl filePath,
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    );

signals:

private slots:

};

}

template <typename T>
void ZG::Panel::PanelRequester::clientGetLandAll (
    T * slotAcceptor, 
    void (T::*slot)(QNetworkReply *reply)) 
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/client/get/land/all");

    post(path, QUrlQuery().query().toUtf8(), slotAcceptor, slot);
}

template <typename T, typename Functor>
void ZG::Panel::PanelRequester::clientGetLandAll (
    T * slotAcceptor, 
    Functor slot) 
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/client/get/land/all");

    post(path, QUrlQuery().query().toUtf8(), slotAcceptor, slot);
}

template <typename T>
void ZG::Panel::PanelRequester::clientGetLandSingle (
        long id,
        T * slotAcceptor, 
        void (T::* slot) (QNetworkReply * reply)
    )
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/client/get/land/single");

    QJsonObject jsonObject;
    jsonObject.insert ("id", (long long) id);

    QJsonDocument jsonDocument (jsonObject);

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T, typename Functor>
void ZG::Panel::PanelRequester::clientGetLandSingle (
        long id,
        T * slotAcceptor, 
        Functor slot
    )
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/client/get/land/single");

    QJsonObject jsonObject;
    jsonObject.insert ("id", (long long) id);

    QJsonDocument jsonDocument (jsonObject);

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T, typename Functor>
void ZG::Panel::PanelRequester::downloadFile (
    QUrl filePath,
    T * slotAcceptor, 
    Functor slot
)
{   
    get ( filePath, slotAcceptor, slot );
}

template <typename T>
void ZG::Panel::PanelRequester::downloadFile (
    QUrl filePath,
    T * slotAcceptor, 
    void (T::* slot) (QNetworkReply * reply)
)
{
    get ( filePath, slotAcceptor, slot );
}

template <typename T>
void ZG::Panel::PanelRequester::adminUpdate (
    LandEditRequest request,
    T * slotAcceptor, 
    void (T::* slot) (QNetworkReply * reply)
)
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/admin/update");

    nlohmann::json json = nlohmann::json ( request );
    json ["token"] = token.toStdString();
    QString jsonString = QString::fromStdString 
    (
        json.dump()
    );

    QJsonDocument jsonDocument = QJsonDocument::fromJson ( jsonString.toUtf8() );

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T, typename Functor>
void ZG::Panel::PanelRequester::adminUpdate (
    LandEditRequest request,
    T * slotAcceptor, 
    Functor slot
)
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/admin/update");

    nlohmann::json json = nlohmann::json ( request );
    json ["token"] = token.toStdString();
    QString jsonString = QString::fromStdString 
    (
        json.dump()
    );

    QJsonDocument jsonDocument = QJsonDocument::fromJson ( jsonString.toUtf8() );

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T>
void ZG::Panel::PanelRequester::adminAdd (
    LandEditRequest request, 
    T * slotAcceptor, 
    void (T::* slot) (QNetworkReply * reply)
)
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/admin/add");

    nlohmann::json json = nlohmann::json ( request );
    json ["token"] = token.toStdString();
    QString jsonString = QString::fromStdString 
    (
        json.dump()
    );

    QJsonDocument jsonDocument = QJsonDocument::fromJson ( jsonString.toUtf8() );

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T, typename Functor>
void ZG::Panel::PanelRequester::adminAdd (
    LandEditRequest request, 
    T * slotAcceptor, 
    Functor slot
)
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/admin/add");

    nlohmann::json json = nlohmann::json ( request );
    json ["token"] = token.toStdString();
    QString jsonString = QString::fromStdString 
    (
        json.dump()
    );

    QJsonDocument jsonDocument = QJsonDocument::fromJson ( jsonString.toUtf8() );

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T>
void ZG::Panel::PanelRequester::adminDelete (
    long id,
    T * slotAcceptor, 
    void (T::* slot) (QNetworkReply * reply)
)
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/admin/delete");

    QJsonObject jsonObject;
    jsonObject.insert ( "id", (long long) id);
    jsonObject.insert ( "token" , token);

    QJsonDocument jsonDocument (jsonObject);

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T, typename Functor>
void ZG::Panel::PanelRequester::adminDelete (
    long id,
    T * slotAcceptor, 
    Functor slot
)
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/admin/delete");

    QJsonObject jsonObject;
    jsonObject.insert ( "id", (long long) id);
    jsonObject.insert ( "token" , token);

    QJsonDocument jsonDocument (jsonObject);

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T>
void ZG::Panel::PanelRequester::adminContacts (
    T * slotAcceptor, 
    void (T::* slot) (QNetworkReply * reply)
)
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/admin/contacts");

    QJsonObject jsonObject;
    jsonObject.insert ( "token" , token);

    QJsonDocument jsonDocument (jsonObject);

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}

template <typename T, typename Functor>
void ZG::Panel::PanelRequester::adminContacts (
    T * slotAcceptor, 
    Functor slot
)
{
    QString path    = QStringLiteral("http://") 
                    + host 
                    + QStringLiteral(":") 
                    + port 
                    + QStringLiteral("/admin/contacts");

    QJsonObject jsonObject;
    jsonObject.insert ( "token" , token);

    QJsonDocument jsonDocument (jsonObject);

    post(path, jsonDocument.toJson(), slotAcceptor, slot);
}