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
MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "File Tracer", wxPoint(100, 100)) {

    //Setup the main menu bar
    auto* mainMenu = new wxMenuBar;
    setupMenus(mainMenu);
    this->SetMenuBar(mainMenu);

    mainColumn = new wxBoxSizer(wxVERTICAL);
    this->SetSizerAndFit(mainColumn);

    //--- Top Row Setup (Search Box) ---
    searchBox = new wxTextCtrl(this, wxID_ANY);
    searchBox->SetFont(searchFont);
    searchBox->SetHint("Search Something");
    searchBox->SetWindowStyleFlag(wxTE_RICH);
    searchBox->SetWindowStyleFlag(wxTE_NOHIDESEL);

    //--- Add the search box to the main column sizer ---
    mainColumn->Add(searchBox, 1, wxEXPAND, 0);


    fileListView = new wxDataViewListCtrl(this, wxID_ANY);
    fileListView->AppendBitmapColumn("", 1, wxDATAVIEW_CELL_INERT, 5, wxALIGN_CENTER);
    fileListView->AppendTextColumn("Test1Text");
    fileListView->AppendToggleColumn("Test2Toggle");
    wxVector<wxVariant> data;
    data.push_back(wxVariant(wxNullBitmap));
    data.push_back( wxVariant("row 1") );
    data.push_back( wxVariant(true) );
    fileListView->AppendItem(data);
    mainColumn->Add(fileListView, 9, wxEXPAND, 0);

//    data.push_back( wxVariant(false) );
//    data.push_back( wxVariant("row 3") );
//    listctrl->AppendItem( data );

    this->SetInitialSize(wxSize(600, 800));

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