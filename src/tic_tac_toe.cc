#include "tic_tac_toe.hh"

#include <ostream>

namespace tic_tac_toe
{
    TicTacToe::TicTacToe(std::array<State, 9> s)
        : board_(s)
    {}

    TicTacToe::TicTacToe()
        : TicTacToe(std::array<State, 9>{{}})
    {}

    int TicTacToe::IsMoveValid(std::string move)
    {
        return move.size() == 2 
            && move[0] >= 'a' && move[0] <= 'c'
            && move[1] >= '0' && move[1] <= '2';
    }

    int TicTacToe::PlayMove(State player, std::string move)
    {
        if (!this->IsMoveValid(move) || player == State::EMPTY)
            return 0;

        int x = move[0] - 'a';
        int y = move[1] - '0';
        int index = y*3 + x;

        if (board_[index] != State::EMPTY)
            return 0;

        board_[index] = player;

        return 1;
    }

    std::ostream &operator<<(std::ostream &out, const TicTacToe &t)
    {
        out << "  a   b   c\n0";
        for (int i = 0; i < 9; i++)
        {
            out << ' ' << t.board_[i];

            switch(i)
            {
                case 2:
                case 5:
                    out << "\n ---+---+---\n" << (i+1)/3;
                    break;

                case 8:
                    out << '\n';
                    break;

                default:
                    out << " |";
                    break;

            }
        }

        return out;
    }
}
