//
// Created by Davoleo on 05/04/2021.
//

#include "FileTracer.h"
#include "UI/MainWindow.h"

//This calls the main function (which then calls the onInit in the app class [this one])
wxIMPLEMENT_APP(FileTracer);

bool FileTracer::OnInit() {
    //Memory resources Resources are automatically freed by wxIMPLEMENT_APP (iirc)
    //TODO investigate this later
    auto *frame = new MainWindow();
    frame->Show(true);
    return true;
}