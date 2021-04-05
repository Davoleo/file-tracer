//
// Created by Davoleo on 05/04/2021.
//

#include "MainWindow.h"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Hello Worldo!") {
    this->CreateStatusBar();
    this->SetStatusText("Example Status Message");

}