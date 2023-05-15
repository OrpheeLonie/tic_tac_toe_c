#include <iostream>

#include "src/tic_tac_toe.hh"

int main()
{
    tic_tac_toe::TicTacToe ticTacToe;
    tic_tac_toe::State player = tic_tac_toe::State::O;
    std::string input;
    int i = 0;

    while (i < 9 && !ticTacToe.IsWin())
    {
        std::cout << ticTacToe << "Player " << player << " : ";
        std::cin >> input;
        if (!ticTacToe.PlayMove(player, input))
        {
            std::cout << "Invalid move\n";
            continue;
        }

        i++;

        player = player == tic_tac_toe::State::O ? tic_tac_toe::State::X : tic_tac_toe::State::O;
    }

    if (ticTacToe.IsWin())
    {
        player = player == tic_tac_toe::State::O ? tic_tac_toe::State::X : tic_tac_toe::State::O;
        std::cout << "Player " << player << " won!\n";
    }
    else
    {
        std::cout << "Draw!\n";
    }

    return 0;
}
