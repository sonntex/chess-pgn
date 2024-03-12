#include <game.hpp>

namespace chess {

game g;

} // namespace chess

extern "C" {

#include <pgn.tab.h>

extern FILE *yyin;
extern int yydebug;

void yyerror(const char* s) { chess::g.error(s); }
void chess_move(char piece, char srow, char scol, char capture, char drow, char dcol)
{ chess::g.move(piece, srow, scol, capture, drow, dcol); }
void chess_promo(char piece) { chess::g.promo(piece); }
void chess_check() { chess::g.check(); }
void chess_checkmate() { chess::g.checkmate(); }
void chess_castle_queen() { chess::g.castle_queen(); }
void chess_castle_king() { chess::g.castle_king(); }
void chess_win_white() { chess::g.win_white(); }
void chess_win_black() { chess::g.win_black(); }
void chess_draw() { chess::g.draw(); }

} // extern

int main(int argc, char* argv[])
{
  if (argc > 1) {
    yyin = fopen(argv[1], "r");
    if (!yyin) {
      return 1;
    }
  }
  // yydebug = 1;
  yyparse();
  return 0;
}
