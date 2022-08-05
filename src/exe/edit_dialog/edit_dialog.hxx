#pragma once

#include "./pages/border_locs_page.hxx"
#include "./pages/docs_page.hxx"
#include "./pages/main_page.hxx"
#include "./pages/photos_page.hxx"
#include "./pages/preview_page.hxx"

#include "data_model/land/land.hxx"
#include "data_model/requests/land_edit.hxx"

#include <QtWidgets>

namespace ZG::Panel{

class EditDialog : public QDialog
{
    Q_OBJECT
public:
    using MainPage = EditDialogInner::MainPage;
    using BorderLocsPage = EditDialogInner::BorderLocsPage;
    using DocsPage = EditDialogInner::DocsPage;
    using PhotosPage = EditDialogInner::PhotosPage;
    using PreviewPage = EditDialogInner::PreviewPage;
    
    EditDialog ( Land data, QWidget *parent = nullptr );
    EditDialog ( QWidget *parent = nullptr );

    LandEditRequest extractData ();
    
private:

    MainPage        * mainPage;
    BorderLocsPage  * borderLocsPage;
    DocsPage        * docsPage;
    PhotosPage      * photosPage;
    PreviewPage     * previewPage;
};



}