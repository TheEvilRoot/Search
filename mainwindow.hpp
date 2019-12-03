#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStringListModel>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateView();
private:
    Ui::MainWindow *ui;
    QStringListModel *listModel;
    QSortFilterProxyModel *filterModel;

    void onSearchTextChanged();
    void onAddButtonPressed();
};
#endif // MAINWINDOW_HPP
