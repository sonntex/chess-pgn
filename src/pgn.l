%option noyywrap
/* %option debug */
%{
#include <pgn.tab.h>
%}

%x TAG MOVE

%%

"["                         { BEGIN(TAG); }
<TAG>"]"                    { BEGIN(INITIAL); }
<TAG>.                      { /* ignore everything inside tag */ }

[ \t\n]+                    { /* ignore spaces */ }

[1-9][0-9]*\.               { BEGIN(MOVE); return TOKEN_MOVE; }
<MOVE>[1-9][0-9]*\.         { BEGIN(MOVE); return TOKEN_MOVE; }
<MOVE>"1-0"                 { BEGIN(INITIAL); return TOKEN_WIN_WHITE; }
<MOVE>"0-1"                 { BEGIN(INITIAL); return TOKEN_WIN_BLACK; }
<MOVE>"1/2-1/2"             { BEGIN(INITIAL); return TOKEN_DRAW; }
<MOVE><<EOF>>               { BEGIN(INITIAL); return TOKEN_SPACE; }
<MOVE>[ \t\n]+              { return TOKEN_SPACE; }
<MOVE>"{"[^}]*"}"[ \t\n]    { /* ignore everything inside comment and next space */ }
<MOVE>"O-O-O"               { return TOKEN_CASTLE_QUEEN; }
<MOVE>"O-O"                 { return TOKEN_CASTLE_KING; }
<MOVE>[KQRBN]               { yylval.c = yytext[0]; return TOKEN_PIECE; }
<MOVE>[a-h]                 { yylval.c = yytext[0]; return TOKEN_COL; }
<MOVE>[1-8]                 { yylval.c = yytext[0]; return TOKEN_ROW; }
<MOVE>x                     { return TOKEN_CAPTURE; }
<MOVE>\=                    { return TOKEN_PROMO; }
<MOVE>\+                    { return TOKEN_CHECK; }
<MOVE>\#                    { return TOKEN_CHECKMATE; }

%%
