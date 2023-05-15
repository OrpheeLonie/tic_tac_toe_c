#include "../src/tic_tac_toe.hh"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

namespace tic_tac_toe
{
    class TicTacToeTest : public ::testing::Test {
    };

    TEST_F(TicTacToeTest, empty_constructor)
    {
        // Given
        std::ostringstream out;
        std::string expected_output = "  a   b   c\n0   |   |  \n ---+---+---\n1   |   |  \n ---+---+---\n2   |   |  \n";

        // When
        tic_tac_toe::TicTacToe ticTacToe;
        out << ticTacToe;
        std::string output = out.str();

        // Then
        EXPECT_EQ(output, expected_output);
    }

    TEST_F(TicTacToeTest, constructor_with_an_input)
    {
        // Given
        std::ostringstream out;
        std::string expected_output = "  a   b   c\n0 O | X |  \n ---+---+---\n1 X |   | O\n ---+---+---\n2   |   |  \n";

        // When
        tic_tac_toe::TicTacToe ticTacToe(std::array<State, 9>{{State::O, State::X, State::EMPTY, State::X, State::EMPTY, State::O}});
        out << ticTacToe;
        std::string output = out.str();

        // Then
        EXPECT_EQ(output, expected_output);
    }

    TEST_F(TicTacToeTest, test_is_move_valid_valid_move)
    {
        // Given
        std::string move = "a0";
        tic_tac_toe::TicTacToe ttt;
        int output;

        // When
        for (int i = 0; i < 3; i++)
        {
            for (int j = 1; j < 3; j++)
            {
                move[0] = 'a' + i;
                move[1] = '0' + i;
                output = ttt.IsMoveValid(move);

                // Then
                EXPECT_TRUE(output) << "move: " << move;
            }
        }
    }

    TEST_F(TicTacToeTest, test_is_move_valid_invalid_move)
    {
        // Given
        std::vector inputs = {"a0c", "b20", "2b", "a3", "eafea"};
        tic_tac_toe::TicTacToe ttt;
        int output;

        for (std::string in : inputs)
        {
            // When
            output = ttt.IsMoveValid(in);

            // Then
            EXPECT_FALSE(output) << "move: " << in;
        }
    }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
