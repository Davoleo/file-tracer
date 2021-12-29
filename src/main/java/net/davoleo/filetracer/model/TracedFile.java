package net.davoleo.filetracer.model;

import javafx.beans.property.*;

import java.io.File;

public class TracedFile {

    private final StringProperty name;
    private final StringProperty path;
    private final IntegerProperty size;
    private final StringProperty extension;
    private final ObjectProperty<FileCategories> category;

    public TracedFile(
            String path,
            int size,
            //String mimeType,
            FileCategories category)
    {
        int slashIndex = path.lastIndexOf(File.separatorChar);


        if (slashIndex != -1 && slashIndex != path.length() - 1)
            this.name = new SimpleStringProperty(path.substring(slashIndex) + 1);
        else
            this.name = new SimpleStringProperty(path);

        this.path = new SimpleStringProperty(path);
        this.size = new SimpleIntegerProperty(size);

        int extIndex = path.lastIndexOf('.');
        if (extIndex != -1)
            this.extension = new SimpleStringProperty(path.substring(extIndex));
        else
            this.extension = new SimpleStringProperty("");

        this.category = new SimpleObjectProperty<>(category);
    }

    public static TracedFile fromExistingFile(File file) {
        String filename = file.getName();
        return new TracedFile(file.getAbsolutePath(), 0, null);
    }

    public String getName()
    {
        return name.get();
    }
    public StringProperty nameProperty()
    {
        return name;
    }

    public String getPath()
    {
        return path.get();
    }
    public StringProperty pathProperty()
    {
        return path;
    }

    public int getSize()
    {
        return size.get();
    }
    public IntegerProperty sizeProperty()
    {
        return size;
    }

    public String getExtension()
    {
        return extension.get();
    }
    public StringProperty extensionProperty()
    {
        return extension;
    }

    public FileCategories getCategory()
    {
        return category.get();
    }
    public ObjectProperty<FileCategories> categoryProperty()
    {
        return category;
    }
}