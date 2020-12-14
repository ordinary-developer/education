#include "GameBoard.hpp"

GameBoard::GameBoard(size_t inWidth, size_t inHeight):
    mWidth(inWidth), mHeight(inHeight)
{
    initializeCellsContainer();
}

GameBoard::GameBoard(const GameBoard& src) {
    copyFrom(src);
}

GameBoard::~GameBoard() {
    // nothing to do
}

GameBoard& GameBoard::operator=(const GameBoard& rhs) {
    if (this == &rhs) {
        return *this;
    }
    copyFrom(rhs);
    return *this;
}

void GameBoard::initializeCellsContainer() {
    mCells.resize(mWidth);
    for (auto& column: mCells) {
        column.resize(mHeight);
    }
}

void GameBoard::setPieceAt(size_t x, size_t y, std::unique_ptr<GamePiece> inPiece)
{
    mCells[x][y] = std::move(inPiece);
}

std::unique_ptr<GamePiece>& GameBoard::getPieceAt(size_t x, size_t y) {
    return mCells[x][y];
}

const std::unique_ptr<GamePiece>& GameBoard::getPieceAt(size_t x, size_t y) const
{
    return mCells[x][y];
}

void GameBoard::copyFrom(const GameBoard& src) {
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    initializeCellsContainer();
    for (size_t i = 0; i < mWidth; i++) {
        for (size_t j = 0; j < mHeight; j++) {
            if (src.mCells[i][j]) {
                mCells[i][j] = src.mCells[i][j]->clone();
            }
            else {
                mCells[i][j].reset();
            }
        }
    }
}
