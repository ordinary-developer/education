#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP


#include <cstddef>


class GamePiece {};

class GameBoard {
    public:
        explicit GameBoard(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
        GameBoard(const GameBoard& src);

        virtual ~GameBoard();

        GameBoard& operator=(const GameBoard& rhs);

        void setPieceAt(size_t x, size_t y, const GamePiece& inPiece);
        GamePiece& getPieceAt(size_t x, size_t y);
        const GamePiece& getPieceAt(size_t x, size_t y) const;

        size_t getWidth() const { return mWidth; }
        size_t getHeight() const { return mHeight; }

        static const size_t kDefaultWidth = 100;
        static const size_t kDefaultHeight = 100;
    private:
        void copyFrom(const GameBoard& src);
        void freeMemory();

        GamePiece** mCells;
        size_t mWidth, mHeight;
};

#endif
