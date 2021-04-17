//
// Created by Davoleo on 05/04/2021.
//

#ifndef FILE_TRACER_MAINWINDOW_H
#define FILE_TRACER_MAINWINDOW_H

#include <wx/wxprec.h>
//#include <wx/stc/stc.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainWindow : public wxFrame {

public:
    MainWindow();

private:
    wxBoxSizer* mainColumn;
    wxBoxSizer* topRow;

    wxTextCtrl*  searchBox;

    //Event handlers -- they don't need to be public
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif //FILE_TRACER_MAINWINDOW_H