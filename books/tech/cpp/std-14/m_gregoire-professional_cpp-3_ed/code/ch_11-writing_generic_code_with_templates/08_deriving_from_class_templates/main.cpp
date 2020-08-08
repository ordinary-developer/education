#include "GameBoard.hpp"

#include <string>


class ChessPiece { };

auto main() -> int {
    GameBoard<ChessPiece> chessBoard(8, 8);

    ChessPiece pawn;
    chessBoard.setElementAt(0, 0, pawn);
    chessBoard.move(0, 0, 0, 1);

    return 0;
}
