#pragma once

#include <ostream>

namespace tic_tac_toe
{
    enum class State
    {
        EMPTY,
        O,
        X,
    };

    inline std::ostream &operator<<(std::ostream &out, const State s)
    {
        switch(s)
        {
            case State::EMPTY:
                out << ' ';
                break;

            case State::O:
                out << 'O';
                break;

            case State::X:
                out << 'X';
                break;
        }

        return out;
    }
}
