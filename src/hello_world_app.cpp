//
// Created by Davoleo on 04/04/2021.
//

#include <wx/wxprec.h>
#include <wx/frame.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "hello_world_app.h"

IMPLEMENT_APP(hello_world_app)

//Executed upon startup, like the main function
bool hello_world_app::onInit() {
    auto *frame = new wxFrame((wxFrame*) nullptr, -1, _T("Hello Warudo!"));
    frame->CreateStatusBar();
    frame->SetStatusText(_T("Hello Worldo!"));
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}