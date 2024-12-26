// helpdialog.h
#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>

class HelpDialog : public QDialog {
    Q_OBJECT

public:
    explicit HelpDialog(QWidget* parent = nullptr);

private:
    QTextEdit* contentTextEdit;
    QPushButton* closeButton;
    void loadHelpContent();
};

#endif // HELPDIALOG_H