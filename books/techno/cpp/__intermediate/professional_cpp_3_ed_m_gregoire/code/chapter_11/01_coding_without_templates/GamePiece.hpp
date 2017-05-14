#ifndef GAME_PIECE_HPP
#define GAME_PIECE_HPP

#include <memory>

class GamePiece {
    public:
        virtual std::unique_ptr<GamePiece> clone() const = 0;
};
#endif
