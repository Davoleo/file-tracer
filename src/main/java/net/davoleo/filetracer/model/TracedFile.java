package net.davoleo.filetracer.model;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

import java.io.File;

public class TracedFile {

    private final StringProperty name;
    private final StringProperty path;
    private final IntegerProperty size;
    private final StringProperty extension;

    public TracedFile(
            String path,
            int size,
            //String mimeType,
            FileCategories category)
    {
        int slashIndex = path.lastIndexOf(File.separatorChar);
        if (slashIndex != -1)
            this.name = new SimpleStringProperty(path.substring(slashIndex));
        else
            this.name = new SimpleStringProperty(path);

        this.path = new SimpleStringProperty(path);
        this.size = new SimpleIntegerProperty(size);

        int extIndex = path.lastIndexOf('.');
        if (extIndex != -1)
            this.extension = new SimpleStringProperty(path.substring(extIndex));
        else
            this.extension = new SimpleStringProperty("");
    }

    public static TracedFile fromExistingFile(File file) {
        String filename = file.getName();
        return new TracedFile(file.getAbsolutePath(), 0, null);
    }
}