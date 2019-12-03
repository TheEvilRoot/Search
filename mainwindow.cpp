#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "model.hpp"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
        ui(new Ui::MainWindow),
        listModel(new QStringListModel(this)),
        filterModel(new QSortFilterProxyModel(this)) {

    ui->setupUi(this);

    /**
     * @brief connect
     *
     * Connect addButton clicked action to onAddButtonPressed function
     */
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonPressed);

    /**
     * @brief connect
     *
     * Connect text changed event from searchEdit to onSearchTextChanged function
     */
    connect(ui->searchEdit, &QLineEdit::textChanged, &MainWindow::onSearchTextChanged);

    /**
     * Set initial listview model as listmodel
     * And disable editing...
     */
    ui->listView->setModel (listModel);
    ui->listView->setEditTriggers (0);
}

/**
 * @brief MainWindow::onSearchTextChanged
 *
 * if text presented in search field
 *     update filter model with new data from list model and update filter string
 *     and set filter model as listview's model
 * if not, set listmodel as listview's model
 */
void MainWindow::onSearchTextChanged() {
    auto text = ui->searchEdit->text ();
    if (text.length () == 0) {
        ui->listView->setModel (listModel);
    } else {
        // Update filter model with search string and data from list model
        filterModel->setFilterFixedString (text);
        filterModel->setSourceModel (listModel);

        // Set filter model as listview's model
        ui->listView->setModel(filterModel);
    }
}

/**
 * @brief MainWindow::onAddButtonPressed
 *
 * Add new item to Model
 */
void MainWindow::onAddButtonPressed() {
    auto value = ui->addEdit->text ();
    if (value.length () > 0) {

        // Add new item to Model
        Model::getInstance ()->getItems ().push_back (new Item (value));

        // Update list model
        updateView ();

        // Clear the text
        ui->addEdit->setText ("");

        // Just macOS bug!
        ui->addEdit->repaint ();
    }
}

/**
 * @brief MainWindow::updateView
 *
 * Update list model with new data from Model
 */
void MainWindow::updateView () {
    QStringList list;
    // Get data from Model and transform it into QStringList
    for (const auto& item : Model::getInstance ()->getItems ()) {
        list.push_back (item->getName ());
    }

    // Set that list to model
    listModel->setStringList (list);
}

MainWindow::~MainWindow() { delete ui; }

