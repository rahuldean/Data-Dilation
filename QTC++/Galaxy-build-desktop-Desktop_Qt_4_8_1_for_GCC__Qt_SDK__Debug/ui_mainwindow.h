/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jun 11 10:46:53 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *mainTabWidget;
    QWidget *myFilesTab;
    QGridLayout *gridLayout;
    QPushButton *searchButton;
    QLineEdit *searchEdit;
    QLabel *searchlabel;
    QTableWidget *filesView;
    QWidget *fileExplorerTab;
    QGridLayout *gridLayout_3;
    QGroupBox *dirGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *directoryLabel;
    QLineEdit *selectedDirEdit;
    QPushButton *chooseDirButton;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *filesGroupBox;
    QGridLayout *gridLayout_2;
    QTextEdit *fileListEdit;
    QGroupBox *filtersGroupBox;
    QVBoxLayout *verticalLayout;
    QLabel *filter_video;
    QCheckBox *mkvCB;
    QCheckBox *movCB;
    QCheckBox *aviCB;
    QCheckBox *mpgCB;
    QCheckBox *mp4CB;
    QFrame *line;
    QLabel *filter_audio;
    QCheckBox *mp3CB;
    QCheckBox *oggCB;
    QFrame *line_2;
    QLabel *filter_other;
    QCheckBox *srtCB;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *clearButton;
    QPushButton *reloadButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(822, 580);
        MainWindow->setMinimumSize(QSize(640, 580));
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mainTabWidget = new QTabWidget(centralWidget);
        mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
        myFilesTab = new QWidget();
        myFilesTab->setObjectName(QString::fromUtf8("myFilesTab"));
        gridLayout = new QGridLayout(myFilesTab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        searchButton = new QPushButton(myFilesTab);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(searchButton, 0, 2, 1, 1);

        searchEdit = new QLineEdit(myFilesTab);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));
        sizePolicy.setHeightForWidth(searchEdit->sizePolicy().hasHeightForWidth());
        searchEdit->setSizePolicy(sizePolicy);
        searchEdit->setMaximumSize(QSize(3000, 16777215));

        gridLayout->addWidget(searchEdit, 0, 1, 1, 1);

        searchlabel = new QLabel(myFilesTab);
        searchlabel->setObjectName(QString::fromUtf8("searchlabel"));

        gridLayout->addWidget(searchlabel, 0, 0, 1, 1);

        filesView = new QTableWidget(myFilesTab);
        if (filesView->columnCount() < 5)
            filesView->setColumnCount(5);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        filesView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        filesView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        filesView->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        filesView->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        filesView->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        filesView->setObjectName(QString::fromUtf8("filesView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filesView->sizePolicy().hasHeightForWidth());
        filesView->setSizePolicy(sizePolicy1);
        filesView->setFrameShape(QFrame::StyledPanel);
        filesView->setFrameShadow(QFrame::Sunken);
        filesView->setDragEnabled(false);
        filesView->setAlternatingRowColors(true);
        filesView->setGridStyle(Qt::SolidLine);
        filesView->setSortingEnabled(true);
        filesView->horizontalHeader()->setCascadingSectionResizes(false);
        filesView->horizontalHeader()->setDefaultSectionSize(150);
        filesView->horizontalHeader()->setStretchLastSection(false);
        filesView->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        filesView->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(filesView, 2, 0, 1, 3);

        mainTabWidget->addTab(myFilesTab, QString());
        fileExplorerTab = new QWidget();
        fileExplorerTab->setObjectName(QString::fromUtf8("fileExplorerTab"));
        fileExplorerTab->setEnabled(true);
        gridLayout_3 = new QGridLayout(fileExplorerTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        dirGroupBox = new QGroupBox(fileExplorerTab);
        dirGroupBox->setObjectName(QString::fromUtf8("dirGroupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dirGroupBox->sizePolicy().hasHeightForWidth());
        dirGroupBox->setSizePolicy(sizePolicy2);
        horizontalLayout = new QHBoxLayout(dirGroupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        directoryLabel = new QLabel(dirGroupBox);
        directoryLabel->setObjectName(QString::fromUtf8("directoryLabel"));

        horizontalLayout->addWidget(directoryLabel);

        selectedDirEdit = new QLineEdit(dirGroupBox);
        selectedDirEdit->setObjectName(QString::fromUtf8("selectedDirEdit"));
        selectedDirEdit->setReadOnly(true);

        horizontalLayout->addWidget(selectedDirEdit);

        chooseDirButton = new QPushButton(dirGroupBox);
        chooseDirButton->setObjectName(QString::fromUtf8("chooseDirButton"));

        horizontalLayout->addWidget(chooseDirButton);


        gridLayout_3->addWidget(dirGroupBox, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        filesGroupBox = new QGroupBox(fileExplorerTab);
        filesGroupBox->setObjectName(QString::fromUtf8("filesGroupBox"));
        gridLayout_2 = new QGridLayout(filesGroupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        fileListEdit = new QTextEdit(filesGroupBox);
        fileListEdit->setObjectName(QString::fromUtf8("fileListEdit"));
        fileListEdit->setReadOnly(true);

        gridLayout_2->addWidget(fileListEdit, 0, 0, 1, 1);

        filtersGroupBox = new QGroupBox(filesGroupBox);
        filtersGroupBox->setObjectName(QString::fromUtf8("filtersGroupBox"));
        verticalLayout = new QVBoxLayout(filtersGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        filter_video = new QLabel(filtersGroupBox);
        filter_video->setObjectName(QString::fromUtf8("filter_video"));

        verticalLayout->addWidget(filter_video);

        mkvCB = new QCheckBox(filtersGroupBox);
        mkvCB->setObjectName(QString::fromUtf8("mkvCB"));

        verticalLayout->addWidget(mkvCB);

        movCB = new QCheckBox(filtersGroupBox);
        movCB->setObjectName(QString::fromUtf8("movCB"));

        verticalLayout->addWidget(movCB);

        aviCB = new QCheckBox(filtersGroupBox);
        aviCB->setObjectName(QString::fromUtf8("aviCB"));

        verticalLayout->addWidget(aviCB);

        mpgCB = new QCheckBox(filtersGroupBox);
        mpgCB->setObjectName(QString::fromUtf8("mpgCB"));

        verticalLayout->addWidget(mpgCB);

        mp4CB = new QCheckBox(filtersGroupBox);
        mp4CB->setObjectName(QString::fromUtf8("mp4CB"));
        mp4CB->setChecked(true);
        mp4CB->setTristate(false);

        verticalLayout->addWidget(mp4CB);

        line = new QFrame(filtersGroupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        filter_audio = new QLabel(filtersGroupBox);
        filter_audio->setObjectName(QString::fromUtf8("filter_audio"));

        verticalLayout->addWidget(filter_audio);

        mp3CB = new QCheckBox(filtersGroupBox);
        mp3CB->setObjectName(QString::fromUtf8("mp3CB"));

        verticalLayout->addWidget(mp3CB);

        oggCB = new QCheckBox(filtersGroupBox);
        oggCB->setObjectName(QString::fromUtf8("oggCB"));

        verticalLayout->addWidget(oggCB);

        line_2 = new QFrame(filtersGroupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        filter_other = new QLabel(filtersGroupBox);
        filter_other->setObjectName(QString::fromUtf8("filter_other"));

        verticalLayout->addWidget(filter_other);

        srtCB = new QCheckBox(filtersGroupBox);
        srtCB->setObjectName(QString::fromUtf8("srtCB"));

        verticalLayout->addWidget(srtCB);


        gridLayout_2->addWidget(filtersGroupBox, 0, 2, 2, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        clearButton = new QPushButton(filesGroupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(clearButton);

        reloadButton = new QPushButton(filesGroupBox);
        reloadButton->setObjectName(QString::fromUtf8("reloadButton"));
        sizePolicy.setHeightForWidth(reloadButton->sizePolicy().hasHeightForWidth());
        reloadButton->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(reloadButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        horizontalLayout_3->addWidget(filesGroupBox);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        mainTabWidget->addTab(fileExplorerTab, QString());

        horizontalLayout_2->addWidget(mainTabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        mainTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        searchButton->setText(QApplication::translate("MainWindow", "SEARCH", 0, QApplication::UnicodeUTF8));
        searchlabel->setText(QApplication::translate("MainWindow", "Search:  ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = filesView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = filesView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Location", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = filesView->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Rating", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = filesView->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Date Created", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = filesView->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(myFilesTab), QApplication::translate("MainWindow", "My Files", 0, QApplication::UnicodeUTF8));
        dirGroupBox->setTitle(QApplication::translate("MainWindow", "Search Directory:", 0, QApplication::UnicodeUTF8));
        directoryLabel->setText(QApplication::translate("MainWindow", "Choose Directory:           ", 0, QApplication::UnicodeUTF8));
        chooseDirButton->setText(QApplication::translate("MainWindow", "Choose", 0, QApplication::UnicodeUTF8));
        filesGroupBox->setTitle(QApplication::translate("MainWindow", "List Of Files", 0, QApplication::UnicodeUTF8));
        fileListEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Choose a directory to search for files</p></body></html>", 0, QApplication::UnicodeUTF8));
        filtersGroupBox->setTitle(QApplication::translate("MainWindow", "Filters", 0, QApplication::UnicodeUTF8));
        filter_video->setText(QApplication::translate("MainWindow", "Video:", 0, QApplication::UnicodeUTF8));
        mkvCB->setText(QApplication::translate("MainWindow", ".MKV", 0, QApplication::UnicodeUTF8));
        movCB->setText(QApplication::translate("MainWindow", ".MOV", 0, QApplication::UnicodeUTF8));
        aviCB->setText(QApplication::translate("MainWindow", ".AVI", 0, QApplication::UnicodeUTF8));
        mpgCB->setText(QApplication::translate("MainWindow", ".MPG", 0, QApplication::UnicodeUTF8));
        mp4CB->setText(QApplication::translate("MainWindow", ".MP4", 0, QApplication::UnicodeUTF8));
        filter_audio->setText(QApplication::translate("MainWindow", "Audio:", 0, QApplication::UnicodeUTF8));
        mp3CB->setText(QApplication::translate("MainWindow", ".MP3", 0, QApplication::UnicodeUTF8));
        oggCB->setText(QApplication::translate("MainWindow", ".OGG", 0, QApplication::UnicodeUTF8));
        filter_other->setText(QApplication::translate("MainWindow", "Other:", 0, QApplication::UnicodeUTF8));
        srtCB->setText(QApplication::translate("MainWindow", ".SRT", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        reloadButton->setText(QApplication::translate("MainWindow", "Reload", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(fileExplorerTab), QApplication::translate("MainWindow", "File Explorer", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
