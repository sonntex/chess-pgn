#define BOOST_TEST_MODULE chess_tests
#include <boost/test/included/unit_test.hpp>

#include <game.hpp>

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn0)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "wP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::black, orig};
  g.move(defs::pawn, defs::whitespace, defs::whitespace, defs::whitespace, '3', 'e');
  BOOST_TEST(g.board() == curr);
}

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn1)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "wP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::black, orig};
  g.move(defs::pawn, defs::whitespace, defs::whitespace, defs::whitespace, '4', 'e');
  BOOST_TEST(g.board() == curr);
}

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn2)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "wP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "bP", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "  ", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "wP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "bP", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "  ", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::black, orig};
  g.move(defs::pawn, defs::whitespace, defs::whitespace, defs::whitespace, '5', 'e');
  BOOST_TEST(g.board() == curr);
}

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn3)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "wP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "bP", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "  ", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "wP", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "  ", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::black, orig};
  g.move(defs::pawn, defs::whitespace, defs::whitespace, defs::capture, '6', 'd');
  BOOST_TEST(g.board() == curr);
}

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn4)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "wP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "bP", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "  ", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "wP", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "  ", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::black, orig};
  g.move(defs::pawn, '5', defs::whitespace, defs::capture, '6', 'd');
  BOOST_TEST(g.board() == curr);
}

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn5)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "wP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "bP", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "  ", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "  ", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "wP", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "  ", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::black, orig};
  g.move(defs::pawn, defs::whitespace, 'e', defs::capture, '6', 'd');
  BOOST_TEST(g.board() == curr);
}

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn6)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "bP", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "  ", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::white, orig};
  g.move(defs::pawn, defs::whitespace, defs::whitespace, defs::whitespace, '6', 'e');
  BOOST_TEST(g.board() == curr);
}

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn7)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "bP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "  ", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::white, orig};
  g.move(defs::pawn, defs::whitespace, defs::whitespace, defs::whitespace, '5', 'e');
  BOOST_TEST(g.board() == curr);
}

// rewrite to make_board
BOOST_AUTO_TEST_CASE(test_pawn8)
{
  using namespace chess;
  game::board_t orig{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "  ", "wP", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "wP", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "bP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "  ", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game::board_t curr{{
    {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}},
    {{"wP", "wP", "wP", "  ", "wP", "wP", "wP", "wP"}},
    {{"  ", "  ", "  ", "wP", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "bP", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}},
    {{"bP", "bP", "bP", "bP", "  ", "bP", "bP", "bP"}},
    {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}
  }};
  game g{defs::white, orig};
  g.move(defs::pawn, defs::whitespace, defs::whitespace, defs::whitespace, '4', 'e');
  BOOST_TEST(g.board() == curr);
}

BOOST_AUTO_TEST_CASE(test_rook0)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |wR|  |  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::rook, ' ', 'a', ' ', '1', 'd');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_rook1)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |wR|  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::rook, ' ', 'h', ' ', '1', 'f');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_rook2)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |wR|  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |wR|  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::rook, ' ', ' ', ' ', '1', 'e');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_rook3)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |  |  |wR|  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |wR|  |  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::rook, ' ', ' ', ' ', '1', 'd');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_rook4)
{
  using namespace chess;
  std::string orig{
    "wR|  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "wR|  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::rook, '8', ' ', ' ', '5', 'a');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_rook5)
{
  using namespace chess;
  std::string orig{
    "wR|  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "wR|  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "wR|  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::rook, '1', ' ', ' ', '3', 'a');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_rook6)
{
  using namespace chess;
  std::string orig{
    "wR|  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "wR|  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "wR|  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "wR|  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::rook, ' ', ' ', ' ', '4', 'a');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_rook7)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "wR|  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "wR|  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::rook, ' ', ' ', ' ', '5', 'a');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_knight0)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |wN|  |  |  |  |wN|  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "wN|  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |  |  |  |wN|  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::knight, ' ', ' ', ' ', '3', 'a');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_knight1)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |wN|  |  |  |  |  \n" // 2
    "  |wN|  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "wN|  |  |  |  |  |  |  \n" // 3
    "  |  |wN|  |  |  |  |  \n" // 2
    "  |  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::knight, ' ', 'b', ' ', '3', 'a');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_knight2)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |wN|  |  |  |  |  \n" // 2
    "  |wN|  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "wN|  |  |  |  |  |  |  \n" // 3
    "  |  |wN|  |  |  |  |  \n" // 2
    "  |  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::knight, '1', ' ', ' ', '3', 'a');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_bishop0)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |wB|  |  |wB|  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |wB|  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |  |  |wB|  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::bishop, ' ', ' ', ' ', '4', 'f');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_bishop1)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |wB|  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |  |  |  |wB|  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |wB|  |  |wB|  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::bishop, ' ', ' ', ' ', '1', 'c');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_bishop2)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |wB|  |  |wB|  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |wB|  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |wB|  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::bishop, ' ', ' ', ' ', '4', 'c');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_bishop3)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |wB|  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |wB|  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |wB|  |  |wB|  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::bishop, ' ', ' ', ' ', '1', 'f');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_castle0)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |wK|  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |  |wR|wK|  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.castle_king();
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_castle1)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "wR|  |  |  |wK|  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |  |  |  |  \n" // 6
    "  |  |  |  |  |  |  |  \n" // 5
    "  |  |  |  |  |  |  |  \n" // 4
    "  |  |  |  |  |  |  |  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "  |  |wK|wR|  |  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.castle_queen();
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_error0)
{
  using namespace chess;
  std::string orig{
    "bR|  |bB|bQ|bK|bB|bN|bR\n" // 8
    "  |bP|bP|bP|  |bP|bP|bP\n" // 7
    "bP|  |bN|  |  |  |  |  \n" // 6
    "  |wB|  |  |bP|  |  |  \n" // 5
    "  |  |  |  |wP|  |  |  \n" // 4
    "  |  |  |  |  |wN|  |  \n" // 3
    "wP|wP|wP|wP|  |wP|wP|wP\n" // 2
    "wR|wN|wB|wQ|wK|  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "bR|  |bB|bQ|bK|bB|bN|bR\n" // 8
    "  |bP|bP|bP|  |bP|bP|bP\n" // 7
    "bP|  |bN|  |  |  |  |  \n" // 6
    "  |  |  |  |bP|  |  |  \n" // 5
    "wB|  |  |  |wP|  |  |  \n" // 4
    "  |  |  |  |  |wN|  |  \n" // 3
    "wP|wP|wP|wP|  |wP|wP|wP\n" // 2
    "wR|wN|wB|wQ|wK|  |  |wR\n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::black, make_board(orig)};
  g.move(defs::bishop, ' ', ' ', ' ', '4', 'a');
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_error1)
{
  using namespace chess;
  std::string orig{
    "bR|  |bB|bQ|bK|  |  |bR\n" // 8
    "  |  |bP|  |bB|bP|bP|bP\n" // 7
    "bP|  |bN|bP|  |bN|  |  \n" // 6
    "  |bP|  |  |bP|  |  |  \n" // 5
    "  |  |  |  |wP|  |  |  \n" // 4
    "  |wB|wP|  |  |wN|  |  \n" // 3
    "wP|wP|  |wP|  |wP|wP|wP\n" // 2
    "wR|wN|wB|wQ|wR|  |wK|  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "bR|  |bB|bQ|  |bR|bK|  \n" // 8
    "  |  |bP|  |bB|bP|bP|bP\n" // 7
    "bP|  |bN|bP|  |bN|  |  \n" // 6
    "  |bP|  |  |bP|  |  |  \n" // 5
    "  |  |  |  |wP|  |  |  \n" // 4
    "  |wB|wP|  |  |wN|  |  \n" // 3
    "wP|wP|  |wP|  |wP|wP|wP\n" // 2
    "wR|wN|wB|wQ|wR|  |wK|  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::white, make_board(orig)};
  g.castle_king();
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_error2)
{
  using namespace chess;
  std::string orig{
    "  |  |  |  |  |  |wQ|  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |bK|bP|  |  |  |  |wP\n" // 6
    "  |  |bQ|  |bP|  |  |  \n" // 5
    "  |  |wP|bP|wP|  |  |  \n" // 4
    "  |  |bN|wP|  |  |wP|  \n" // 3
    "bP|  |  |  |  |  |  |  \n" // 2
    "  |  |  |  |  |wB|wK|  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  std::string curr{
    "  |  |  |  |  |  |wQ|  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |bK|bP|  |  |  |  |wP\n" // 6
    "  |  |bQ|  |bP|  |  |  \n" // 5
    "  |  |wP|bP|wP|  |  |  \n" // 4
    "  |  |bN|wP|  |  |wP|  \n" // 3
    "  |  |  |  |  |  |  |  \n" // 2
    "bQ|  |  |  |  |wB|wK|  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g{defs::white, make_board(orig)};
  g.move(defs::pawn, ' ', ' ', ' ', '1', 'a');
  g.promo(defs::queen);
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}

BOOST_AUTO_TEST_CASE(test_game0)
{
  using namespace chess;
  std::string curr{
    "  |  |  |  |  |  |  |  \n" // 8
    "  |  |  |  |  |  |  |  \n" // 7
    "  |  |  |  |wR|  |bP|  \n" // 6
    "  |  |bK|  |  |  |bP|  \n" // 5
    "  |bP|  |  |  |  |wP|  \n" // 4
    "  |wP|  |bB|  |wP|  |  \n" // 3
    "  |  |  |wK|  |bN|  |  \n" // 2
    "  |  |  |  |  |  |  |  \n" // 1
    //a  b  c  d  e  f  g  h
  };
  game g;
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
  BOOST_TEST(g.finished());
  BOOST_TEST(g.winner_color() == defs::whitespace); 
  std::stringstream stream;
  g.print(stream);
  BOOST_TEST(stream.str() == curr);
}
