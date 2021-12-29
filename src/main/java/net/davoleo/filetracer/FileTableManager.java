package net.davoleo.filetracer;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import net.davoleo.filetracer.model.TracedFile;

import java.util.Collection;

public class FileTableManager {

    private ObservableList<TracedFile> cache;

    public FileTableManager(Collection<TracedFile> files)
    {
        FXCollections.observableArrayList(files);
    }

    public void handleSearchSubmission(ActionEvent event) {

    }
}
