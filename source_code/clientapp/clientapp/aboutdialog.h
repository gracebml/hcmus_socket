#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>

class AboutDialog : public QDialog {
    Q_OBJECT

public:
    explicit AboutDialog(QWidget* parent = nullptr);

private:
    QTextEdit* contentTextEdit;
    QPushButton* closeButton;
    void loadAboutContent();
};

#endif // ABOUTDIALOG_H