module filetracer {
    requires kotlin.stdlib;
    requires javafx.controls;
    requires javafx.fxml;

    opens net.davoleo.filetracer to javafx.fxml;
    exports net.davoleo.filetracer;
}