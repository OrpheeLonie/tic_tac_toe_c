#pragma once

#include <array>

#include "state.hh"

namespace tic_tac_toe
{
    class TicTacToe
    {
    public:
        TicTacToe(std::array<State, 9> s);
        TicTacToe();

        int IsMoveValid(std::string move);
        int PlayMove(State player, std::string move);

        friend std::ostream &operator<<(std::ostream &out, const TicTacToe &t);

    private:
        std::array<State, 9> board_;
    };
}
