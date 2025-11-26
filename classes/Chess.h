#pragma once

#include "ChessPiece.h"
#include "Game.h"
#include "Grid.h"
#include "BitBoard.h"
constexpr int pieceSize = 80;
enum AllBitBoards
{
    WHITE_PAWNS,
    WHITE_KNIGHTS,
    WHITE_BISHOPS,
    WHITE_ROOKS,
    WHITE_QUEENS,
    WHITE_KING,
    WHITE_ALL_PIECES,
   BLACK_PAWNS,
    BLACK_KNIGHTS,
    BLACK_BISHOPS,
    BLACK_ROOKS,
    BLACK_QUEENS,
    BLACK_KING,
    BLACK_ALL_PIECES,
    OCCUPANCY,
    EMPTY_SQUARES,
    e_numBitboards
};

class Chess : public Game
{
public:
    Chess();
    ~Chess();

    void setUpBoard() override;

    bool canBitMoveFrom(Bit &bit, BitHolder &src) override;
    bool canBitMoveFromTo(Bit &bit, BitHolder &src, BitHolder &dst) override;
    bool actionForEmptyHolder(BitHolder &holder) override;

    void stopGame() override;

    Player *checkForWinner() override;
    bool checkForDraw() override;

    std::string initialStateString() override;
    std::string stateString() override;
    void setStateString(const std::string &s) override;
    void generateKnightMoves(std::vector<BitMove>& moves, BitBoard knightBoard, uint64_t occupancy);
    void generateKingMoves(std::vector<BitMove>& moves, BitBoard kingBoard, uint64_t occupancy);
    void generatePawnMoves(std::vector<BitMove>& moves, BitBoard pawnBoard, uint64_t occupancy);
    void generateRookMoves(std::vector<BitMove>& moves, BitBoard rookBoard, uint64_t occupancy);
    void generateBishopMoves(std::vector<BitMove>& moves, BitBoard bishopBoard, uint64_t occupancy);
    void generateQueenMoves(std::vector<BitMove>& moves, BitBoard queenBoard, uint64_t occupancy);
    // std::vector<BitMove> generateAllMoves();
    Grid* getGrid() override { return _grid; }
    

private:
    Bit* PieceForPlayer(const int playerNumber, ChessPiece piece);
    Player* ownerAt(int x, int y) const;
    void FENtoBoard(const std::string& fen);
    char pieceNotation(int x, int y) const;
    void placePiece(int pos, char input);
    Grid* _grid;
};