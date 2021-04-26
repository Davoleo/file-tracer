//
// Created by Davoleo on 26/04/2021.
//

#ifndef FILE_TRACER_GUI_FILE_INFO_H
#define FILE_TRACER_GUI_FILE_INFO_H

#include <wx/msw/bitmap.h>

#include "ftlib.c"

class FileInfo {
private:
    const wxBitmap* icon;
    const char* filename;
    const char* path;
    const int size;
    const char* extension;

public:
    static FileInfo fromFTLibFolder(Folder* folder);
};


static FileInfo FileInfo::fromFTLibFolder(Folder* folder) {

}

#endif //FILE_TRACER_GUI_FILE_INFO_H
