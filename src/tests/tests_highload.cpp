#include <game.hpp>

#include <chrono>
#include <iostream>

namespace chess {

game g;

void work()
{
  using namespace chess;
  g.move(defs::pawn,   ' ', ' ', ' ', '4', 'e'); g.move(defs::pawn,   ' ', ' ', ' ', '5', 'e');
  g.move(defs::knight, ' ', ' ', ' ', '3', 'f'); g.move(defs::knight, ' ', ' ', ' ', '6', 'c');
  g.move(defs::bishop, ' ', ' ', ' ', '5', 'b'); g.move(defs::pawn,   ' ', ' ', ' ', '6', 'a');
  g.move(defs::bishop, ' ', ' ', ' ', '4', 'a'); g.move(defs::knight, ' ', ' ', ' ', '6', 'f');
  g.castle_king();                               g.move(defs::bishop, ' ', ' ', ' ', '7', 'e');
  g.move(defs::rook,   ' ', ' ', ' ', '1', 'e'); g.move(defs::pawn,   ' ', ' ', ' ', '5', 'b');
  g.move(defs::bishop, ' ', ' ', ' ', '3', 'b'); g.move(defs::pawn,   ' ', ' ', ' ', '6', 'd');
  g.move(defs::pawn,   ' ', ' ', ' ', '3', 'c'); g.castle_king();
  g.move(defs::pawn,   ' ', ' ', ' ', '3', 'h'); g.move(defs::knight, ' ', ' ', ' ', '8', 'b');
  g.move(defs::pawn,   ' ', ' ', ' ', '4', 'd'); g.move(defs::knight, ' ', 'b', ' ', '7', 'd');
  g.move(defs::pawn,   ' ', ' ', ' ', '4', 'c'); g.move(defs::pawn,   ' ', ' ', ' ', '6', 'c');
  g.move(defs::pawn,   ' ', 'c', 'x', '5', 'b'); g.move(defs::pawn,   ' ', 'a', 'x', '5', 'b');
  g.move(defs::knight, ' ', ' ', ' ', '3', 'c'); g.move(defs::bishop, ' ', ' ', ' ', '7', 'b');
  g.move(defs::bishop, ' ', ' ', ' ', '5', 'g'); g.move(defs::pawn,   ' ', ' ', ' ', '4', 'b');
  g.move(defs::knight, ' ', ' ', ' ', '1', 'b'); g.move(defs::pawn,   ' ', ' ', ' ', '6', 'h');
  g.move(defs::bishop, ' ', ' ', ' ', '4', 'h'); g.move(defs::pawn,   ' ', ' ', ' ', '5', 'c');
  g.move(defs::pawn,   ' ', 'd', 'x', '5', 'e'); g.move(defs::knight, ' ', ' ', 'x', '4', 'e');
  g.move(defs::bishop, ' ', ' ', 'x', '7', 'e'); g.move(defs::queen,  ' ', ' ', 'x', '7', 'e');
  g.move(defs::pawn,   ' ', 'e', 'x', '6', 'd'); g.move(defs::queen,  ' ', ' ', ' ', '6', 'f');
  g.move(defs::knight, ' ', 'b', ' ', '2', 'd'); g.move(defs::knight, ' ', ' ', 'x', '6', 'd');
  g.move(defs::knight, ' ', ' ', ' ', '4', 'c'); g.move(defs::knight, ' ', ' ', 'x', '4', 'c');
  g.move(defs::bishop, ' ', ' ', 'x', '4', 'c'); g.move(defs::knight, ' ', ' ', ' ', '6', 'b');
  g.move(defs::knight, ' ', ' ', ' ', '5', 'e'); g.move(defs::rook,   ' ', 'a', ' ', '8', 'e');
  g.move(defs::bishop, ' ', ' ', 'x', '7', 'f'); g.move(defs::rook,   ' ', ' ', 'x', '7', 'f');
  g.move(defs::knight, ' ', ' ', 'x', '7', 'f'); g.move(defs::rook,   ' ', ' ', 'x', '1', 'e');
  g.move(defs::queen,  ' ', ' ', 'x', '1', 'e'); g.move(defs::king,   ' ', ' ', 'x', '7', 'f');
  g.move(defs::queen,  ' ', ' ', ' ', '3', 'e'); g.move(defs::queen,  ' ', ' ', ' ', '5', 'g');
  g.move(defs::queen,  ' ', ' ', 'x', '5', 'g'); g.move(defs::pawn,   ' ', 'h', 'x', '5', 'g');
  g.move(defs::pawn,   ' ', ' ', ' ', '3', 'b'); g.move(defs::king,   ' ', ' ', ' ', '6', 'e');
  g.move(defs::pawn,   ' ', ' ', ' ', '3', 'a'); g.move(defs::king,   ' ', ' ', ' ', '6', 'd');
  g.move(defs::pawn,   ' ', 'a', 'x', '4', 'b'); g.move(defs::pawn,   ' ', 'c', 'x', '4', 'b');
  g.move(defs::rook,   ' ', ' ', ' ', '5', 'a'); g.move(defs::knight, ' ', ' ', ' ', '5', 'd');
  g.move(defs::pawn,   ' ', ' ', ' ', '3', 'f'); g.move(defs::bishop, ' ', ' ', ' ', '8', 'c');
  g.move(defs::king,   ' ', ' ', ' ', '2', 'f'); g.move(defs::bishop, ' ', ' ', ' ', '5', 'f');
  g.move(defs::rook,   ' ', ' ', ' ', '7', 'a'); g.move(defs::pawn,   ' ', ' ', ' ', '6', 'g');
  g.move(defs::rook,   ' ', ' ', ' ', '6', 'a'); g.move(defs::king,   ' ', ' ', ' ', '5', 'c');
  g.move(defs::king,   ' ', ' ', ' ', '1', 'e'); g.move(defs::knight, ' ', ' ', ' ', '4', 'f');
  g.move(defs::pawn,   ' ', ' ', ' ', '3', 'g'); g.move(defs::knight, ' ', ' ', 'x', '3', 'h');
  g.move(defs::king,   ' ', ' ', ' ', '2', 'd'); g.move(defs::king,   ' ', ' ', ' ', '5', 'b');
  g.move(defs::rook,   ' ', ' ', ' ', '6', 'd'); g.move(defs::king,   ' ', ' ', ' ', '5', 'c');
  g.move(defs::rook,   ' ', ' ', ' ', '6', 'a'); g.move(defs::knight, ' ', ' ', ' ', '2', 'f');
  g.move(defs::pawn,   ' ', ' ', ' ', '4', 'g'); g.move(defs::bishop, ' ', ' ', ' ', '3', 'd');
  g.move(defs::rook,   ' ', ' ', ' ', '6', 'e'); g.draw();
}

} // namespace chess

int main(int argc, char* argv[])
{
  namespace chrono = std::chrono;
  using namespace chess;
  int n = std::stoi(argv[1]);
  auto tp1 = chrono::high_resolution_clock::now();
  for (int i = 0; i < n; ++i) {
    work();
  }
  auto tp2 = chrono::high_resolution_clock::now();
  auto duration = tp2 - tp1;
  auto ns = chrono::duration_cast<chrono::nanoseconds>(duration).count();
  ns /= n;
  std::cout << ns << "ns\n";
  return 0;
}
