#include "GameBoard.hpp"
#include "ChessPiece.hpp"


auto main() -> int {
    GameBoard chessBoard(8, 8);
    auto pawn = std::make_unique<ChessPiece>();
    chessBoard.setPieceAt(0, 0, std::move(pawn));
    chessBoard.setPieceAt(0, 1, std::make_unique<ChessPiece>());
    chessBoard.setPieceAt(0, 1, nullptr);

    return 0;
}
