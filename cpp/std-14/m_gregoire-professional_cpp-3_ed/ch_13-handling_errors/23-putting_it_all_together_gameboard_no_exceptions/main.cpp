#include "GameBoard.hpp"


void processGameBoard(const GameBoard& board) {
    const GamePiece& piece = board.getPieceAt(0, 0);
    // does not compile
    // board.setPieceAt(0, 0, piece);
}


auto main() -> int {
    GameBoard board(10, 10);
    GamePiece piece;

    board.setPieceAt(0, 0, piece);
    board.setPieceAt(0, 1, board.getPieceAt(0, 0));

    GameBoard board2;
    board2 = board;

    processGameBoard(board2);
    
    return 0;
}

