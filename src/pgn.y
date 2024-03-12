%{
/* #define YYDEBUG 1*/

void yyerror(const char* s);
void chess_move(char piece, char srow, char scol, char capture, char dcol, int draw);
void chess_promo(char piece);
void chess_check();
void chess_checkmate();
void chess_castle_queen();
void chess_castle_king();
void chess_win_white();
void chess_win_black();
void chess_draw();
%}

%union {
  char c;
}

%token TOKEN_MOVE
%token TOKEN_WIN_WHITE
%token TOKEN_WIN_BLACK
%token TOKEN_DRAW
%token TOKEN_SPACE
%token TOKEN_CASTLE_QUEEN
%token TOKEN_CASTLE_KING
%token <c> TOKEN_PIECE
%token <c> TOKEN_COL
%token <c> TOKEN_ROW
%token TOKEN_CAPTURE
%token TOKEN_PROMO
%token TOKEN_CHECK
%token TOKEN_CHECKMATE

%%

grammar:
    move_sequence
  ;

move_sequence:
    move
  | move_finish
  | move_sequence move
  | move_sequence move_finish
  ;

move:
    TOKEN_MOVE TOKEN_SPACE move_one TOKEN_SPACE
  | TOKEN_MOVE TOKEN_SPACE move_one TOKEN_SPACE move_one TOKEN_SPACE
  ;

move_one:
    move_piece
  | move_piece TOKEN_CHECK { chess_check(); }
  | move_piece TOKEN_CHECKMATE { chess_checkmate(); }
  | move_piece TOKEN_PROMO TOKEN_PIECE { chess_promo($3); }
  | move_piece TOKEN_PROMO TOKEN_PIECE TOKEN_CHECK { chess_promo($3); chess_check(); }
  | move_piece TOKEN_PROMO TOKEN_PIECE TOKEN_CHECKMATE { chess_promo($3); chess_checkmate(); }
  | move_castle
  ;

move_piece:
    move_piece_pawn
  | move_piece_non_pawn
  ;

move_piece_pawn:
    TOKEN_COL TOKEN_ROW { chess_move('P', ' ', ' ', ' ', $2, $1); }
  | TOKEN_COL TOKEN_COL TOKEN_ROW { chess_move('P', ' ', $1, ' ', $3, $2); }
  | TOKEN_ROW TOKEN_COL TOKEN_ROW { chess_move('P', $1, ' ', ' ', $3, $2); }
  | TOKEN_COL TOKEN_ROW TOKEN_COL TOKEN_ROW { chess_move('P', $2, $1, ' ', $4, $3); }
  | TOKEN_CAPTURE TOKEN_COL TOKEN_ROW { chess_move('P', ' ', ' ', 'x', $3, $2); }
  | TOKEN_COL TOKEN_CAPTURE TOKEN_COL TOKEN_ROW { chess_move('P', ' ', $1, 'x', $4, $3); }
  | TOKEN_ROW TOKEN_CAPTURE TOKEN_COL TOKEN_ROW { chess_move('P', $1, ' ', 'x', $4, $3); }
  | TOKEN_COL TOKEN_ROW TOKEN_CAPTURE TOKEN_COL TOKEN_ROW { chess_move('P', $2, $1, 'x', $5, $4); }
  ;

move_piece_non_pawn:
    TOKEN_PIECE TOKEN_COL TOKEN_ROW { chess_move($1, ' ', ' ', ' ', $3, $2); }
  | TOKEN_PIECE TOKEN_COL TOKEN_COL TOKEN_ROW { chess_move($1, ' ', $2, ' ', $4, $3); }
  | TOKEN_PIECE TOKEN_ROW TOKEN_COL TOKEN_ROW { chess_move($1, $2, ' ', ' ', $4, $3); }
  | TOKEN_PIECE TOKEN_COL TOKEN_ROW TOKEN_COL TOKEN_ROW { chess_move($1, $3, $2, ' ', $5, $4); }
  | TOKEN_PIECE TOKEN_CAPTURE TOKEN_COL TOKEN_ROW { chess_move($1, ' ', ' ', 'x', $4, $3); }
  | TOKEN_PIECE TOKEN_COL TOKEN_CAPTURE TOKEN_COL TOKEN_ROW { chess_move($1, ' ', $2, 'x', $5, $4); }
  | TOKEN_PIECE TOKEN_ROW TOKEN_CAPTURE TOKEN_COL TOKEN_ROW { chess_move($1, $2, ' ', 'x', $5, $4); }
  | TOKEN_PIECE TOKEN_COL TOKEN_ROW TOKEN_CAPTURE TOKEN_COL TOKEN_ROW { chess_move($1, $3, $2, 'x', $6, $5); }
  ;

move_castle:
    TOKEN_CASTLE_QUEEN { chess_castle_queen(); }
  | TOKEN_CASTLE_KING { chess_castle_king(); }
  ;

move_finish:
    TOKEN_WIN_WHITE { chess_win_white(); }
  | TOKEN_WIN_BLACK { chess_win_black(); }
  | TOKEN_DRAW { chess_draw(); }
  ;

%%
