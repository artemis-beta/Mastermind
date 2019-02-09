#ifndef MMWINDOW_H
#define MMWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "Mastermind.hxx"

namespace Ui {
class MMWindow;
}

class MMWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MMWindow(QWidget *parent = nullptr);
    ~MMWindow();

private slots:

    void on_pushEnter_clicked();

    void on_pushRed_clicked();

    void on_pushGreen_clicked();

    void on_pushBlue_clicked();

    void on_pushBlack_clicked();

    void on_pushPurple_clicked();

    void on_pushWhite_clicked();

    void on_pushDel_clicked();

    void on_pushOrange_clicked();

    void on_actionExit_triggered();

    void on_actionNew_Game_triggered();

private:
    Ui::MMWindow *ui;
    Mastermind *game = new Mastermind();
    std::vector<QLabel*> _ai_choice_row;
    std::vector<std::vector<QLabel*>> _player_rows;
    std::vector<unsigned int> _current_turn;
    std::vector<QLabel*> _result_rows;
    void resetGame();
    void insertColour(Colour);
    void checkPlayerChoices();
};

#endif // MMWINDOW_H
