#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include "GamePiece.hpp"

class ChessPiece : public GamePiece {
    public:
        virtual std::unique_ptr<GamePiece> clone() const override;
};
#endif
