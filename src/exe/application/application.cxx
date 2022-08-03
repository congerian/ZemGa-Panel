#include "./application.hxx"
#include "../util.hxx"

#include <QTextCodec>

ZG::Panel::Application::Application(int argc, char *argv[]) : QApplication(argc, argv){
    if (isWindows() && AttachConsole(ATTACH_PARENT_PROCESS)) {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }

    requester = new PanelRequester();
    mainWindow = new MainWindow();

    requester->clientGetLandAll([](QNetworkReply *reply)
        {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            QString answer = QString::fromUtf8(reply->readAll());

            qDebug() << answer;
        }
    );
}

ZG::Panel::Application::~Application() {
    delete mainWindow;
    delete requester;
}