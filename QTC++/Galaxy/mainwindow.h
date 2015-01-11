#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    
private slots:
    void on_clearButton_clicked();
    void populateWithFiles();
    void on_reloadButton_clicked();
    void on_chooseDirButton_clicked();
    void on_searchEdit_textChanged(const QString &arg1);
    void filterSettings();

private:
    Ui::MainWindow *ui;
    QString folderToSearch;
    QStringList filters;
};

#endif // MAINWINDOW_H
