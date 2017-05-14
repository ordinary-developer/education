#include "GameBoard.hpp"

#include <stdexcept>
#include <new>


// [AUXILIARY FUNCTIONS] region
void GameBoard::allocateMemory() {
    size_t i = 0;

    mCells = new GamePiece*[mWidth];
    try {
        for (i = 0; i < mWidth; i++) {
            mCells[i] = new GamePiece[mHeight];
        }
    }
    catch (...) {
        for (size_t j = 0; j < i; j++) {
            delete[] mCells[j];
        }
        delete[] mCells;
        mCells = nullptr;

        mWidth = 0;
        mHeight = 0;

        throw std::bad_alloc();
    }
}

void GameBoard::copyFrom(const GameBoard& src) {
    mWidth = src.mWidth;
    mHeight = src.mHeight;

    allocateMemory();

    for (size_t i = 0; i < mWidth; i++) {
        for (size_t j = 0; j < mHeight; j++) {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

void GameBoard::freeMemory() {
    for (size_t i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;

    mWidth = 0;
    mHeight = 0;
}
// end [AUXILIARY FUNCTIONS]

// [MAIN CLASS FUNCTIONS] region
GameBoard::GameBoard(size_t inWidth, size_t inHeight)
    : mWidth(inWidth), mHeight(inHeight) 
{
    allocateMemory();    
}


GameBoard::GameBoard(const GameBoard& src) {
    copyFrom(src);
}

GameBoard::~GameBoard() {
    freeMemory();
}

GameBoard& GameBoard::operator=(const GameBoard& rhs) {
    if (&rhs == this) {
        return *this;
    }
    
    freeMemory();
    copyFrom(rhs);

    return *this;
}

void GameBoard::setPieceAt(size_t x, size_t y, const GamePiece& inElem) {
    if (x >= mWidth) {
        throw std::out_of_range("GameBoard::setPieceAt: x-coordinate beyond width");
    }
    if (y >= mHeight) {
        throw std::out_of_range("GameBoard::setPieceAt: y-coordinate beyond height");
    }
}

GamePiece& GameBoard::getPieceAt(size_t x, size_t y) {
    if (x >= mWidth) {
        throw std::out_of_range("GameBoard::getPieceAt: x-coordinate beyond width");
    }
    if (y >= mHeight) {
        throw std::out_of_range("GameBoard::getPieceAt: y-coordinate beyond height");
    }

    return mCells[x][y];
}

const GamePiece& GameBoard::getPieceAt(size_t x, size_t y) const {
    if (x >= mWidth) {
        throw std::out_of_range("GameBoard::getPieceAt: x-coordinate beyond width");
    }
    if (y >= mHeight) {
        throw std::out_of_range("GameBoard::getPieceAt: y-coordinate beyond height");
    }

    return mCells[x][y];
}

// end [MAIN CLASS FUNCTIONS]
