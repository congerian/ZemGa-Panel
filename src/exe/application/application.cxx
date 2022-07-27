#include "./application.hxx"
#include "../util.hxx"

ZG::Panel::Application::Application(int argc, char *argv[]) : QApplication(argc, argv){
    if (isWindows() && AttachConsole(ATTACH_PARENT_PROCESS)) {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
}