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
    void OnHello(wxCommandEvent& event) {}
    void OnExit(wxCommandEvent& event) {}
    void OnAbout(wxCommandEvent& event) {}
};


#endif //FILE_TRACER_MAINWINDOW_H
