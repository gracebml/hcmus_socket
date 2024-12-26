#include "helpdialog.h"
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "fontmanager.h"

HelpDialog::HelpDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Help");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(600, 500);
    setWindowIcon(QIcon("help.png")); // You'll need to provide an appropriate icon

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

    loadHelpContent();

    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
}

void HelpDialog::loadHelpContent() {
    QFile helpFile(":clientapp/content/help.txt");
    if (!helpFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open Help file.");
        return;
    }

    QTextStream in(&helpFile);
    QString content = in.readAll();
    contentTextEdit->setHtml(content); // Thay vì setText() thì dùng setHtml()
    helpFile.close();
}