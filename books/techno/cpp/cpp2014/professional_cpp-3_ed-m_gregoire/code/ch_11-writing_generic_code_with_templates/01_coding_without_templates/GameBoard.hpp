#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include <cstdlib> // for size_t
#include <vector>

#include "GamePiece.hpp"


class GameBoard {
    public:
        explicit GameBoard(size_t inWidth = kDefaultWidth,
                size_t inHeight = kDefaultHeight);
        GameBoard(const GameBoard& src);
        virtual ~GameBoard();
        GameBoard& operator=(const GameBoard& rhs);
        void setPieceAt(size_t x, size_t y, std::unique_ptr<GamePiece> inPiece);
        std::unique_ptr<GamePiece>& getPieceAt(size_t x, size_t y);
        const std::unique_ptr<GamePiece>& getPieceAt(size_t x, size_t y) const;

        size_t getHeight() const { return mHeight; }
        size_t getWidth() const { return mWidth; }

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;
    private:
        void copyFrom(const GameBoard& src);
        void initializeCellsContainer();
        std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
        size_t mWidth, mHeight;
};
#endif
