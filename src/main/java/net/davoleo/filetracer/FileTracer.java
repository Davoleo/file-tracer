package net.davoleo.filetracer;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.stage.Stage;
import net.davoleo.filetracer.model.FileCategories;
import net.davoleo.filetracer.model.TracedFile;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;

public class FileTracer extends Application implements Initializable {

    public static void main(String[] args)
    {
        launch(args);
    }

    Stage primaryStage;

    @FXML
    private TableView<TracedFile> filesTable;

    /**
     * Launches the app
     */
    @Override
    public void start(Stage primaryStage)
    {
        Parent root = null;

        try {
            root = FXMLLoader.load(getClass().getClassLoader().getResource("gui/main.fxml"));
        }
        catch (IOException e) {
            e.printStackTrace();
            throw new RuntimeException("IO-Exception on FXML loading");
        }
        assert root != null;

        this.primaryStage = primaryStage;
        primaryStage.setTitle("File Tracer");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    /**
     * Called when the UI has been loaded
     */
    @Override
    public void initialize(URL location, ResourceBundle resources)
    {
        List<TracedFile> samples = new ArrayList<>();
        samples.add(new TracedFile("bla\\bla\\bla\\test.txt", 100, FileCategories.DOCUMENT));
        samples.add(new TracedFile("bla\\bla\\bla\\test.mp3", 111, FileCategories.AUDIO));
        samples.add(new TracedFile("Bla\\zipped\\bla\\test.zip", 222, FileCategories.COMPRESSED));
        samples.add(new TracedFile("bla\\zipped\\bla\\test.rar", 333, FileCategories.COMPRESSED));
        samples.add(new TracedFile("bla\\death\\exec\\test.exe", 444, FileCategories.EXECUTABLE));
        samples.add(new TracedFile("bla\\docs\\bla\\test.pdf", 555, FileCategories.DOCUMENT));
        samples.add(new TracedFile("bla\\bla\\bla\\test\\", 0, FileCategories.FOLDER));

        TableColumn<TracedFile, String> nameCol = new TableColumn<>("Name");
        TableColumn<TracedFile, String> pathCol = new TableColumn<>("Path");
        TableColumn<TracedFile, Integer> sizeCol = new TableColumn<>("Size");
        TableColumn<TracedFile, String> extCol = new TableColumn<>("Extension");
        TableColumn<TracedFile, FileCategories> catCol = new TableColumn<>("Category");

        filesTable.getColumns().setAll(nameCol, pathCol, sizeCol, extCol, catCol);

        ObservableList<TracedFile> obSamples = FXCollections.observableArrayList(samples);
        filesTable.setItems(obSamples);
    }
}
