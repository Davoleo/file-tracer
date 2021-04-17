//
// Created by Davoleo on 05/04/2021.
//

#include "MainWindow.hpp"
#include "../Utils/constants.h"

///Maps events to handler functions
wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
                EVT_MENU(wxID_EXIT, MainWindow::OnExit)
                EVT_MENU(wxID_ABOUT, MainWindow::OnAbout)
wxEND_EVENT_TABLE()

/// Constructs the Main Menu Bar and all its internal menus
/// \param menuBar the menu bar that is injected with items
void setupMenus(wxMenuBar* menuBar) {
    //Menu Bar
    auto* fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT);

    auto* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT);

    menuBar->Append(fileMenu, "File");
    menuBar->Append(helpMenu, "&Help");

}

///Constructs the main window and all its components
MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "File Tracer") {

    //Setup the main menu bar
    auto* mainMenu = new wxMenuBar;
    setupMenus(mainMenu);
    this->SetMenuBar(mainMenu);

    mainColumn = new wxBoxSizer(wxVERTICAL);
    this->SetSizerAndFit(mainColumn);

    //--- Top Row Setup ---
    searchBox = new wxTextCtrl(this, wxID_ANY);
    searchBox->SetFont(searchFont);
    searchBox->SetHint("Search Something");
    searchBox->SetWindowStyleFlag(wxTE_RICH);
    searchBox->SetWindowStyleFlag(wxTE_NOHIDESEL);

    //--- Add all the children sizer to the top level sizer ---
    mainColumn->Add(searchBox, 0, wxEXPAND, 0);

    this->SetInitialSize(wxSize(350, 400));

    //--- Setup the Status Bar
    this->CreateStatusBar();
    this->SetStatusText("Welcome to File Tracer!");
}


#pragma region Menu Event Handlers

void MainWindow::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MainWindow::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Test");
}

#pragma endregion