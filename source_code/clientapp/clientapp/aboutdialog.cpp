#include "aboutdialog.h"
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "fontmanager.h"

AboutDialog::AboutDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("About");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(400, 500);  // Slightly larger than LoginDialog to accommodate more content
    setWindowIcon(QIcon("info.png"));  // You'll need to provide an appropriate icon

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(16);

    // Set the background color to match LoginDialog
    setStyleSheet("background-color: #F5F5DC;");

    // Content text area
    contentTextEdit = new QTextEdit(this);
    contentTextEdit->setReadOnly(true);
    contentTextEdit->setStyleSheet(
        "QTextEdit {"
        "    font-size: 15px;"
        "    padding: 8px;"
        "    background-color: #F5F5DC;"
        "    color: black;"
        "    border: none;"
        "}"
    );
    contentTextEdit->setFont(FontManager::getInstance().getLogFont());

    // Close button
    closeButton = new QPushButton("Close", this);
    closeButton->setStyleSheet(
        "font-size: 15px;"
        "padding: 8px;"
        "background-color: #C2B280;"
        "color: black;"
    );
    closeButton->setFont(FontManager::getInstance().getButtonFont());

    layout->addWidget(contentTextEdit);
    layout->addWidget(closeButton);

    // Load content from resource file
    loadAboutContent();

    // Connect close button
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
}

void AboutDialog::loadAboutContent() {
    QFile aboutFile(":clientapp/content/about.txt");
    if (!aboutFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open About file.");
        return;
    }

    QTextStream in(&aboutFile);
    QString content = in.readAll();
    contentTextEdit->setHtml(content); 
    aboutFile.close();
}
