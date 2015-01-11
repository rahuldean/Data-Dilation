#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDirIterator>
#include <QStatusBar>
#include <QDateTime>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    folderToSearch = "/";
    ui->reloadButton->setEnabled(0);
/*
    QPushButton *open1 = new QPushButton("Open",this);
    QPushButton *open2 = new QPushButton("Open",this);

    ui->filesView->insertRow(0);
    QTableWidgetItem *nI=new QTableWidgetItem("Avengers");
    QTableWidgetItem *n2=new QTableWidgetItem("/Rahul/Movies/Avengers");
    QTableWidgetItem *n3=new QTableWidgetItem("5");
    QTableWidgetItem *n4=new QTableWidgetItem("18/05/2012");

    ui->filesView->setItem(0,0,nI);
    ui->filesView->setItem(0,1,n2);
    ui->filesView->setItem(0,2,n3);
    ui->filesView->setItem(0,3,n4);
    ui->filesView->setCellWidget(0,4,open1);


    int row = ui->filesView->rowCount();
    ui->filesView->insertRow(row);
    QTableWidgetItem *n11=new QTableWidgetItem("Spider Man");
    QTableWidgetItem *n21=new QTableWidgetItem("/Rahul/Movies/SpiderMan");
    QTableWidgetItem *n31=new QTableWidgetItem("4.5");
    QTableWidgetItem *n41=new QTableWidgetItem("27/02/2011");
    ui->filesView->setItem(1,0,n11);
    ui->filesView->setItem(1,1,n21);
    ui->filesView->setItem(1,2,n31);
    ui->filesView->setItem(1,3,n41);
    ui->filesView->setCellWidget(1,4,open2);
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateWithFiles()
{
    int row = 0;
    int count=0;
    QString cnt;
    filterSettings();

    ui->filesView->setRowCount(0);
    QDirIterator it(folderToSearch,
                    filters,
                    QDir::AllDirs|QDir::Files|QDir::NoSymLinks,
                    QDirIterator::Subdirectories);
    while(it.hasNext())
    {

        it.next();
        if(! it.fileInfo().isDir())
        {
        //1.Shows the Name of the file
        QString currentFile = it.fileInfo().fileName().simplified();
        //2.When it is created/Last modified
        QString createdAt = NULL;
        createdAt = it.fileInfo().created().date().toString();
        createdAt=createdAt.remove(0,4);
        //3.FilePath
        QString currentPath = it.filePath();

        //Prepare to write them to the filesView
        QTableWidgetItem *fName = new QTableWidgetItem(currentFile);
        QTableWidgetItem *fCreated = new QTableWidgetItem(createdAt);
        QTableWidgetItem *fPath = new QTableWidgetItem(currentPath);


        row = ui->filesView->rowCount();
        ui->filesView->insertRow(row);
        ui->filesView->setItem(row,0,fName);
        ui->filesView->setItem(row,1,fPath);
        ui->filesView->setItem(row,3,fCreated);


        ui->fileListEdit->append(currentFile);



      //  ui->fileListEdit->append(createdAt);
        count++;
        }

    }
    cnt.append(QString("%1").arg(count));
    ui->reloadButton->setEnabled(1);
    ui->statusBar->showMessage("Files:"+cnt);
}

void MainWindow::on_clearButton_clicked()
{
        ui->fileListEdit->clear();
        ui->statusBar->clearMessage();
}

void MainWindow::on_reloadButton_clicked()
{
    on_clearButton_clicked();
    populateWithFiles();
}

void MainWindow::on_chooseDirButton_clicked()
{
    //Get the folder to search
    on_clearButton_clicked();
    folderToSearch = QFileDialog::getExistingDirectory(this,tr("Select directory to search for files"),folderToSearch,QFileDialog::ShowDirsOnly);
    ui->selectedDirEdit->setText(folderToSearch);

    //Populate with files
    populateWithFiles();
}

void MainWindow::on_searchEdit_textChanged(const QString &arg1)
{
    QTableWidgetItem *rowPtr;
    int row;
    QList<QTableWidgetItem *> match = ui->filesView->findItems(ui->searchEdit->text(),Qt::MatchContains) ;
    ui->statusBar->showMessage(ui->searchEdit->text());

    foreach(rowPtr,match)
    {
        row = ui->filesView->row(rowPtr);
        ui->filesView->selectRow(row);


    }


}

void MainWindow::filterSettings()
{
    //obtain the checked lists from filters group box
    //Video
    filters.clear();
    if(ui->mkvCB->isChecked())
    {filters << "*.mkv";}
    if(ui->movCB->isChecked())
       { filters << "*.mov";}
    if(ui->aviCB->isChecked())
    {filters << "*.avi";}
    if(ui->mpgCB->isChecked())
       { filters << "*.mpg";}
    if(ui->mp4CB->isChecked())
       { filters << "*.mp4";}

    //Audio
    if(ui->mp3CB->isChecked())
    {filters << "*.mp3";}
    if(ui->oggCB->isChecked())
       { filters << "*.ogg";}

    //Other
    if(ui->srtCB->isChecked())
       { filters << "*.srt";}




}
