#include "GameBoard.hpp"

// region [AUXILIARY FUNCTIONS] 

void GameBoard::copyFrom(const GameBoard& src) {
    mWidth = src.mWidth;
    mHeight = src.mHeight;

    mCells = new GamePiece*[mWidth];
    for (size_t i = 0; i < mWidth; i++) {
        mCells[i] = new GamePiece[mHeight];
    }

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


// [MAIN FUNCTIONS] region
GameBoard::GameBoard(size_t inWidth, size_t inHeight) 
    : mWidth(inWidth), mHeight(inHeight)
{
    mCells = new GamePiece*[mWidth];
    for (size_t i = 0; i < mWidth; i++) {
        mCells[i] = new GamePiece[mHeight];
    }
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
    mCells[x][y] = inElem;
}

GamePiece& GameBoard::getPieceAt(size_t x, size_t y) {
    return mCells[x][y];
}

const GamePiece& GameBoard::getPieceAt(size_t x, size_t y) const {
    return mCells[x][y];
}

