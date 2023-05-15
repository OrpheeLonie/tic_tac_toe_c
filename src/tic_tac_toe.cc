#include "tic_tac_toe.hh"

#include <ostream>

namespace tic_tac_toe
{
    TicTacToe::TicTacToe()
        : board_({{}})
    {}

    std::ostream &operator<<(std::ostream &out, const TicTacToe &t)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                out << t.board_[i*3+j] << ' ';
            }

            out << '\n';
        }

        return out;
    }
}
