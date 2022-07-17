#include "chess.hpp"

using namespace Chess;

Board board = Board();
uint64_t nodes;

uint64_t perft(int depth) {
    Moves moveList = board.legal_moves();
    if (depth == 1) {
        return (int)moveList.count;
    }
    uint64_t nodes = 0;
    for (int i = 0; i < (int)moveList.count; i++) {
        Move move = moveList.moves[i];
        board.make_move(move);
        nodes += perft(depth - 1);
        board.unmake_move(move);
    }
    return nodes;
}

int main() {
    
    board.parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    auto t1 = std::chrono::high_resolution_clock::now();
    uint64_t n = perft(6);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    
    std::cout << "nodes: " << n << " nps " << (n * 1000) / ms << std::endl;
    return 0;
}