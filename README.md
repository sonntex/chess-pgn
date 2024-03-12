# chess-pgn

### How to build?

```
$ cd chess-pgn
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make -j
$ make test
```

### Hot to export sources?

```
cd chess-pgn
git archive --prefix=chess-pgn/ -o chess-pgn.tar.gz HEAD
```

### How to generate parser?

Uncomment relative cmake instructions. Switch from `pgn.lex.c` and `pgn.tab.c` to the generated files. Rebuild.

```
# find_package(FLEX)
# 
# flex_target(chess-pgn-lexer
#   pgn.l ${CMAKE_CURRENT_BINARY_DIR}/pgn.lex.c)
# 
# find_package(BISON)
# 
# bison_target(chess-pgn-parser
#   pgn.y ${CMAKE_CURRENT_BINARY_DIR}/pgn.tab.c
#   DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/pgn.tab.h)
# 
# add_flex_bison_dependency(chess-pgn-lexer chess-pgn-parser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(chess
# ${CMAKE_CURRENT_BINARY_DIR}/pgn.lex.c
# ${CMAKE_CURRENT_BINARY_DIR}/pgn.tab.c
  pgn.lex.c
  pgn.tab.c
  game.cpp
  main.cpp)
```

### How to enable debug in flex?

Uncomment debug option in `src/pgn.l`. Generate flex files again. Rebuild.

```
/* %option debug */
```

### How to enable debug in bison?

Uncomment debug macro in `src/phn.y`. Generate bison files again. Uncomment debug flag in `src/main.cpp`. Rebuild.

```
/* #define YYDEBUG 1*/
```

```
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
```

### How to check performance?

```
$ ./chess-highload-tests 1000000000 &
$ perf record -p $(pidof chess-highload-tests) sleep 10
$ perf record
$ fg
$ ^C
```

### Results without parsing and printing

Built with `CHESS_OPT_SET`:

```
$ ./chess-highload-tests 10000000
2317ns
```

Built with `CHESS_OPT_UNORDERED_SET`:

```
$ ./chess-highload-tests 10000000
2795ns
```

Built with `CHESS_OPT_STATIC_VECTOR`:

```
$ ./chess-highload-tests 10000000
1417ns
```

Built with `CHESS_OPT_VECTOR`:

```
$ ./chess-highload-tests 10000000
1474ns
```
