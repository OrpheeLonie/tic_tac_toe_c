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
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
