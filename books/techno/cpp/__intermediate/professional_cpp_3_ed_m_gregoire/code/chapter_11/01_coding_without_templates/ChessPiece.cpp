#include "ChessPiece.hpp"

std::unique_ptr<GamePiece> ChessPiece::clone() const {
    return std::make_unique<ChessPiece>(*this);
}
