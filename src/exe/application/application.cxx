#include "./application.hxx"
#include "../util.hxx"

#include <QTextCodec>

ZG::Panel::Application::Application(int argc, char *argv[]) : QApplication(argc, argv)
{
    if (isWindows() && AttachConsole(ATTACH_PARENT_PROCESS)) {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }

    requester = new PanelRequester();
}

ZG::Panel::Application::~Application() 
{
    delete requester;
}

ZG::Panel::PanelRequester * ZG::Panel::Application::getRequester()
{
    return requester;
}
