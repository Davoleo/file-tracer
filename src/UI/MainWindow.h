//
// Created by Davoleo on 05/04/2021.
//

#ifndef FILE_TRACER_MAINWINDOW_H
#define FILE_TRACER_MAINWINDOW_H

#include <wx/wxprec.h>

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

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif //FILE_TRACER_MAINWINDOW_H

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
                EVT_MENU(wxID_EXIT, MainWindow::OnExit)
                EVT_MENU(wxID_ABOUT, MainWindow::OnAbout)
wxEND_EVENT_TABLE()