#include "mmwindow.h"
#include "ui_mmwindow.h"
#include <vector>

MMWindow::MMWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MMWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Mastermind "+game->getVersion());
    _ai_choice_row = {ui->label_0_1, ui->label_0_2,
                      ui->label_0_3, ui->label_0_4};
    _player_rows = {{ui->label_1_1, ui->label_1_2,
                  ui->label_1_3, ui->label_1_4},
                  {ui->label_2_1, ui->label_2_2,
                   ui->label_2_3, ui->label_2_4},
                  {ui->label_3_1, ui->label_3_2,
                   ui->label_3_3, ui->label_3_4},
                  {ui->label_4_1, ui->label_4_2,
                   ui->label_4_3, ui->label_4_4},
                  {ui->label_5_1, ui->label_5_2,
                   ui->label_5_3, ui->label_5_4},
                  {ui->label_6_1, ui->label_6_2,
                   ui->label_6_3, ui->label_6_4},
                  {ui->label_7_1, ui->label_7_2,
                   ui->label_7_3, ui->label_7_4},
                  {ui->label_8_1, ui->label_8_2,
                   ui->label_8_3, ui->label_8_4},
                  {ui->label_9_1, ui->label_9_2,
                   ui->label_9_3, ui->label_9_4},
                  {ui->label_10_1, ui->label_10_2,
                   ui->label_10_3, ui->label_10_4},
                  {ui->label_11_1, ui->label_11_2,
                   ui->label_11_3, ui->label_11_4},
                  {ui->label_12_1, ui->label_12_2,
                   ui->label_12_3, ui->label_12_4}};

    _result_rows = {{ui->check_1_1, ui->check_1_2,
                  ui->check_1_3, ui->check_1_4},
                  {ui->check_2_1, ui->check_2_2,
                   ui->check_2_3, ui->check_2_4},
                  {ui->check_3_1, ui->check_3_2,
                   ui->check_3_3, ui->check_3_4},
                  {ui->check_4_1, ui->check_4_2,
                   ui->check_4_3, ui->check_4_4},
                  {ui->check_5_1, ui->check_5_2,
                   ui->check_5_3, ui->check_5_4},
                  {ui->check_6_1, ui->check_6_2,
                   ui->check_6_3, ui->check_6_4},
                  {ui->check_7_1, ui->check_7_2,
                   ui->check_7_3, ui->check_7_4},
                  {ui->check_8_1, ui->check_8_2,
                   ui->check_8_3, ui->check_8_4},
                  {ui->check_9_1, ui->check_9_2,
                   ui->check_9_3, ui->check_9_4},
                  {ui->check_10_1, ui->check_10_2,
                   ui->check_10_3, ui->check_10_4},
                  {ui->check_11_1, ui->check_11_2,
                   ui->check_11_3, ui->check_11_4},
                  {ui->check_12_1, ui->check_12_2,
                   ui->check_12_3, ui->check_12_4}};

    _result_pegs[black] = QPixmap(":/new/png/img/Black_colour_peg_small.png");
    _result_pegs[blank] = QPixmap(":/new/png/img/No_colour_peg_small.png");
    _result_pegs[white] = QPixmap(":/new/png/img/White_colour_peg_small.png");

    _peg_colour_files["R"] = QPixmap(":/new/png/img/Red_colour_peg.png");
    _peg_colour_files["B"] = QPixmap(":/new/png/img/Blue_colour_peg.png");
    _peg_colour_files["K"] = QPixmap(":/new/png/img/Black_colour_peg.png");
    _peg_colour_files["W"] = QPixmap(":/new/png/img/White_colour_peg.png");
    _peg_colour_files["O"] = QPixmap(":/new/png/img/Orange_colour_peg.png");
    _peg_colour_files["P"] = QPixmap(":/new/png/img/Purple_colour_peg.png");
    _peg_colour_files["G"] = QPixmap(":/new/png/img/Green_colour_peg.png");
    _peg_colour_files[""] = QPixmap(":/new/png/img/No_colour_peg.png");
    _current_turn = {0,0};
    game->setColours();
}

MMWindow::~MMWindow()
{
    delete ui;
}

void MMWindow::insertColour(Colour c)
{
    if(_current_turn[0] == 12)
    {
        resetGame();
    }
    if(_current_turn[1] < 4)
    {
        game->player_grid[_current_turn[1]] = c;
        _player_rows[_player_rows.size()-1-_current_turn[0]][_current_turn[1]]->setPixmap(_peg_colour_files[game->getStrFromColour(c)]);
        _current_turn[1]++;
    }
}

void MMWindow::resetGame()
{
    for(auto i : _player_rows)
    {
        for(auto j : i)
        {
            j->setPixmap(_peg_colour_files[""]);
        }
    }
    for(auto j : _result_rows)
    {
        for(auto m : j)
        {
            m->setPixmap(_result_pegs[blank]);
        }
    }
    for(auto k : _ai_choice_row)
    {
        k->setPixmap(_peg_colour_files[""]);
    }
    _current_turn = {0,0};
    game->player_grid = {};
    game->setColours();
}

void MMWindow::on_pushEnter_clicked()
{
    if(_current_turn[1] != 4)
    {
        ui->msgDialogue->setText("You need to choose 4 colours!");
    }
    else
    {
        ui->msgDialogue->setText("");
        checkPlayerChoices();
        _current_turn[0]++;
        _current_turn[1] = 0;
    }
}

void MMWindow::revealAIChoice()
{
    for(unsigned int k{0}; k<_ai_choice_row.size(); ++k)
    {
        _ai_choice_row[k]->setPixmap(_peg_colour_files[game->getStrFromColour(game->grid[k])]);
    }
}
void MMWindow::checkPlayerChoices()
{
    std::vector<pegBool> _result = {};
    std::vector<unsigned int> _pegs = game->getPegs();
    for(unsigned int j{0}; j<_pegs[0]; ++j)_result.push_back(white);
    for(unsigned int k{0}; k<_pegs[1]; ++k)_result.push_back(black);

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(_result), std::end(_result), rng);

    while(_result.size() < 4)_result.push_back(blank);

    for(unsigned int i{0}; i<_result.size(); ++i)
    {
        _result_rows[_player_rows.size()-1-_current_turn[0]][i]->setPixmap(_result_pegs[_result[i]]);
    }

    if(_pegs[1] == 4)
    {
        ui->msgDialogue->setText("You Won!");
        revealAIChoice();
    }
    if(_current_turn[0] == 11)
    {
        ui->msgDialogue->setText("You Lose.");
        revealAIChoice();
    }

}

void MMWindow::on_pushRed_clicked()
{
    insertColour(Red);
}

void MMWindow::on_pushGreen_clicked()
{
    insertColour(Green);
}

void MMWindow::on_pushBlue_clicked()
{
    insertColour(Blue);
}

void MMWindow::on_pushBlack_clicked()
{
    insertColour(Black);
}

void MMWindow::on_pushPurple_clicked()
{
    insertColour(Purple);
}

void MMWindow::on_pushWhite_clicked()
{
    insertColour(White);
}

void MMWindow::on_pushOrange_clicked()
{
    insertColour(Orange);
}

void MMWindow::on_pushDel_clicked()
{
    if(_current_turn[1] > 0)
    {   _current_turn[1]--;
        game->player_grid[_current_turn[1]] = None;
        _player_rows[_player_rows.size()-1-_current_turn[0]][_current_turn[1]]->setPixmap(_peg_colour_files[""]);
    }

}

void MMWindow::on_actionExit_triggered()
{
    exit(EXIT_SUCCESS);
}

void MMWindow::on_actionNew_Game_triggered()
{
    resetGame();
}
