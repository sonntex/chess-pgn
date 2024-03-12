#pragma once

// #define CHESS_OPT_SET
// #define CHESS_OPT_UNORDERED_SET
#define CHESS_OPT_STATIC_VECTOR

#if   defined(CHESS_OPT_SET)
#  include <set>
#elif defined(CHESS_OPT_UNORDERED_SET)
#  include <unordered_set>
#elif defined(CHESS_OPT_STATIC_VECTOR)
#  include <boost/container/static_vector.hpp>
#endif

#include <array>
#include <string>
#include <vector>

namespace chess {

namespace defs {

constexpr char whitespace = ' ';
constexpr char white = 'w';
constexpr char black = 'b';
constexpr char pawn = 'P';
constexpr char rook = 'R';
constexpr char knight = 'N';
constexpr char bishop = 'B';
constexpr char queen = 'Q';
constexpr char king = 'K';
constexpr char capture = 'x';

} // namespace defs

class game
{
public:

  // use arrays for better performance on cpu cache
  using board_t = std::array<std::array<std::array<char, 3>, 8>, 8>;
#if   defined(CHESS_OPT_SET)
  using cache_t = std::set<std::pair<int, int>>;
#elif defined(CHESS_OPT_UNORDERED_SET)
  struct pair_hash
  {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
      const auto& [x, y] = p;
      return (x << 4) | y;
    }
  };
  using cache_t = std::unordered_set<std::pair<int, int>, pair_hash>;
#elif defined(CHESS_OPT_STATIC_VECTOR)
  using cache_t = boost::container::static_vector<std::pair<int, int>, 8>;
#else
  using cache_t = std::vector<std::pair<int, int>>;
#endif
  using directions_t = std::vector<std::pair<int, int>>;

  game();
  game(char color, board_t board);

  game(const game& other) = default;
  game& operator=(const game& other) = default;
  game(game&& other) = default;
  game& operator=(game&& other) = default;

  char color() const { return color_; }
  char opponent_color() const { return opponent_color_; }
  char winner_color() const { return winner_color_; }
  char piece() const { return piece_; }
  char finished() const { return finished_; }

  board_t& board() { return board_; }
  const board_t& board() const { return board_; }

  void print(std::ostream& stream, bool beautify = false) const;

  void error(const std::string& s);
  void move(char piece, char srow, char scol, char capture, char dcol, char drow);
  void promo(char piece);
  void check();
  void checkmate();
  void castle_queen();
  void castle_king();
  void win_white();
  void win_black();
  void draw();

private:

  void init();
  void init(char color, board_t board);

  void switch_turn(char piece);

  void update(char color, char piece, char capture, int di, int dj, int si, int sj);

  bool find_ncross(char srow, char scol, int di, int dj, int& si, int& sj, const cache_t& cache) const;
  bool find_xcross(char srow, char scol, int di, int dj, int& si, int& sj, const cache_t& cache) const;
  bool find_around(char srow, char scol, int di, int dj, int& si, int& sj, const directions_t& directions) const;

  bool find_capturing_pawn(char srow, char scol, int di, int dj, int& si, int& sj) const;
  bool find_pawn(char srow, char scol, int di, int dj, int& si, int& sj) const;
  bool find_rook(char srow, char scol, int di, int dj, int& si, int& sj) const;
  bool find_knight(char srow, char scol, int di, int dj, int& si, int& sj) const;
  bool find_bishop(char srow, char scol, int di, int dj, int& si, int& sj) const;
  bool find_queen(char srow, char scol, int di, int dj, int& si, int& sj) const;
  bool find_king(char srow, char scol, int di, int dj, int& si, int& sj) const;

  bool valid0(char color, char piece, int si, int sj) const;
  bool valid1(char color, char piece, int si, int sj) const;

  int game_number_{0};
  int turn_number_{0};

  char color_{defs::black};
  char opponent_color_{defs::white};
  char winner_color_{defs::whitespace};
  char piece_{defs::whitespace};
  bool finished_{false};
  int li{-1}; // last i
  int lj{-1}; // last j

  board_t board_;

  struct combined_cache
  {
    cache_t rooks;
    cache_t bishops;
    cache_t queens;
  };

  std::vector<combined_cache> cached_pieces_;
  size_t cache_{1};
  size_t opponent_cache_{0};
};

game::board_t make_default_board();
game::board_t make_board(const std::string& s);

extern game g;

} // namespace chess
