#include <game.hpp>

#include <algorithm>
#include <format>
#include <iostream>
#include <sstream>
#include <stdexcept>

#ifdef NDEBUG
#define CHESS_TRACE(x)
#else
#define CHESS_TRACE(x) do { x } while (0)
#endif

namespace chess {

game::board_t make_default_board()
{
  game::board_t res = {{
      //  a     b     c     d     e     f     g     h
      {{"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"}}, // 1
      {{"wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"}}, // 2
      {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}}, // 3
      {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}}, // 4
      {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}}, // 5
      {{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}}, // 6
      {{"bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"}}, // 7
      {{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"}}  // 8
    }};
  return res;
}

game::board_t make_board(const std::string& s)
{
  game::board_t res;
  // parse lines
  std::stringstream lines_stream(s);
  std::string line;
  int i = 7;
  while (std::getline(lines_stream, line)) {
    if (!line.empty()) {
      // parse cells
      std::stringstream cells_stream(line);
      std::string cell;
      int j = 0;
      while (std::getline(cells_stream, cell, '|')) {
        if (!cell.empty()) {
          res.at(i).at(j).at(0) = cell.at(0); // throw exception
          res.at(i).at(j).at(1) = cell.at(1); // throw exception
          res.at(i).at(j).at(2) = 0;          // throw exception
          ++j;
        }
      }
      --i;
    }
  }
  return res;
}

namespace {

inline int col_to_index(char col) { return col - 'a'; }
inline bool valid_col(char col) { return col >= 'a' && col <= 'h'; }
inline int row_to_index(char row) { return row - '1'; }
inline bool valid_row(char row) { return row >= '1' && row <= '8'; }

} // namespace

game::game()
{
  init();
}

game::game(char color, board_t board)
{
  init(color, std::move(board));
}

void game::init()
{
  finished_ = false;
  ++game_number_;
  turn_number_ = 0;
  color_ = defs::black;
  board_ = make_default_board();
  cached_pieces_.resize(2);
  cached_pieces_[0].rooks   = {{0, 0}, {0, 7}};
  cached_pieces_[1].rooks   = {{7, 0}, {7, 7}};
  cached_pieces_[0].bishops = {{0, 2}, {0, 5}};
  cached_pieces_[1].bishops = {{7, 2}, {7, 5}};
  cached_pieces_[0].queens  = {{0, 3}};
  cached_pieces_[1].queens  = {{7, 3}};
}

void game::init(char color, board_t board)
{
  finished_ = false;
  ++game_number_;
  turn_number_ = 0;
  color_ = color;
  board_ = std::move(board);
  cached_pieces_.resize(2);
  for (int i = 0; i <= 7; ++i) {
    for (int j = 0; j <= 7; ++j) {
      char color = board_.at(i).at(j).at(0); // throw exception
      char piece = board_.at(i).at(j).at(1); // throw exception
      auto& cached_pieces = cached_pieces_[color == defs::white ? 0 : 1];
      switch (piece) {
      case defs::rook:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
        cached_pieces.rooks.insert({i, j});
#else
        cached_pieces.rooks.push_back({i, j});
#endif
        break;
      case defs::bishop:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
        cached_pieces.bishops.insert({i, j});
#else
        cached_pieces.bishops.push_back({i, j});
#endif
        break;
      case defs::queen:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
        cached_pieces.queens.insert({i, j});
#else
        cached_pieces.queens.push_back({i, j});
#endif
        break;
      }
    }
  }
}

void game::print(std::ostream& stream, bool beautify) const
{
  if (beautify) {
    stream << "  ";
    for (int j = 0; j <= 7; ++j) {
      stream << " " << static_cast<char>(j + 'a') << " ";
    }
    stream << "\n";
  }
  for (int i = 7; i >= 0; --i) {
    if (beautify) {
      stream << i + 1 << " ";
    }
    for (int j = 0; j <= 7; ++j) {
      if (j > 0) {
        stream << "|";
      }
      char color = board_[i][j][0];
      char piece = board_[i][j][1];
      stream << color << piece;
    }
    if (beautify) {
      stream << " " << i + 1;
    }
    stream << "\n";
  }
  if (beautify) {
    stream << "  ";
    for (int j = 0; j <= 7; ++j) {
      stream << " " << static_cast<char>(j + 'a') << " ";
    }
    stream << "\n";
  }
}

void game::error(const std::string& s)
{
  // helps to identify errors in flex and bison!
  throw std::runtime_error(s);
}

void game::move(char piece, char srow, char scol, char capture, char drow, char dcol)
{
  switch_turn(piece);
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. move '{}{}' from '{}{}' to '{}{}' {}\n",
          turn_number_, color_, piece_, scol, srow, dcol, drow, capture);
  );
  int di = row_to_index(drow);
  int dj = col_to_index(dcol);
  int si = -1;
  int sj = -1;
  bool found = false;
  switch (piece) {
  case defs::pawn:
    if (capture == defs::capture) {
      found = find_capturing_pawn(srow, scol, di, dj, si, sj);
    } else {
      found = find_pawn(srow, scol, di, dj, si, sj);
    }
    break;
  case defs::rook:
    found = find_rook(srow, scol, di, dj, si, sj);
    break;
  case defs::knight:
    found = find_knight(srow, scol, di, dj, si, sj);
    break;
  case defs::bishop:
    found = find_bishop(srow, scol, di, dj, si, sj);
    break;
  case defs::queen:
    found = find_queen(srow, scol, di, dj, si, sj);
    break;
  case defs::king:
    found = find_king(srow, scol, di, dj, si, sj);
    break;
  }
  if (!found) {
    // helps to identify errors in flex and bison!
    throw std::runtime_error("invalid board");
  }
  update(color_, piece_, capture, di, dj, si, sj);
  CHESS_TRACE( print(std::cerr, true); );
}

void game::promo(char piece)
{
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. promote '{}{}'\n", turn_number_, color_, piece);
  );
  // no sanity checks!
  auto& cached_pieces = cached_pieces_[cache_];
  switch (piece) {
  case defs::rook:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
    cached_pieces.rooks.insert({li, lj});
#else
    cached_pieces.rooks.push_back({li, lj});
#endif
    break;
  case defs::bishop:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
    cached_pieces.bishops.insert({li, lj});
#else
    cached_pieces.bishops.push_back({li, lj});
#endif
    break;
  case defs::queen:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
    cached_pieces.queens.insert({li, lj});
#else
    cached_pieces.queens.push_back({li, lj});
#endif
    break;
  }
  board_[li][lj][1] = piece;
}

void game::check()
{
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. check\n", turn_number_);
  );
}

void game::checkmate()
{
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. checkmate", turn_number_);
  );
}

void game::castle_queen()
{
  switch_turn(defs::king);
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. castle queen '{}{}'\n", turn_number_, color_, piece_);
  );
  int i = (color_ == defs::white ? 0 : 7);
  update(color_, defs::rook, defs::whitespace, i, col_to_index('d'), i, col_to_index('a'));
  update(color_, defs::king, defs::whitespace, i, col_to_index('c'), i, col_to_index('e'));
}

void game::castle_king()
{
  switch_turn(defs::king);
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. castle king '{}{}'\n", turn_number_, color_, piece_);
  );
  int i = (color_ == defs::white ? 0 : 7);
  update(color_, defs::rook, defs::whitespace, i, col_to_index('f'), i, col_to_index('h'));
  update(color_, defs::king, defs::whitespace, i, col_to_index('g'), i, col_to_index('e'));
}

void game::win_white()
{
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. win white\n", turn_number_);
  );
  winner_color_ = defs::white;
  finished_ = true;
  print(std::cout);
}

void game::win_black()
{
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. win black\n", turn_number_);
  );
  winner_color_ = defs::black;
  finished_ = true;
  print(std::cout);
}

void game::draw()
{
  CHESS_TRACE( std::cerr <<
      std::format("!!! {}. draw\n", turn_number_);
  );
  winner_color_ = defs::whitespace;
  finished_ = true;
  print(std::cout);
}

void game::switch_turn(char piece)
{
  if (finished_) {
    init();
  }
  if (color_ == defs::black) {
    ++turn_number_;
    color_ = defs::white;
    opponent_color_ = defs::black;
    cache_ = 0;
    opponent_cache_ = 1;
  } else {
    color_ = defs::black;
    opponent_color_ = defs::white;
    cache_ = 1;
    opponent_cache_ = 0;
  }
  piece_ = piece;
}

void game::update(char color, char piece, char capture, int di, int dj, int si, int sj)
{
  // no sanity checks!
  if (capture == defs::capture) {
    char piece = board_[di][dj][1];
    auto& cached_pieces = cached_pieces_[opponent_cache_];
    switch (piece) {
    case defs::rook:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
      cached_pieces.rooks.erase({di, dj});
#else
      cached_pieces.rooks.erase(
          std::remove(std::begin(cached_pieces.rooks), std::end(cached_pieces.rooks),
              std::make_pair(di, dj)),
          std::end(cached_pieces.rooks));
#endif
      break;
    case defs::bishop:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
      cached_pieces.bishops.erase({di, dj});
#else
      cached_pieces.bishops.erase(
          std::remove(std::begin(cached_pieces.bishops), std::end(cached_pieces.bishops),
              std::make_pair(di, dj)),
          std::end(cached_pieces.bishops));
#endif
      break;
    case defs::queen:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
      cached_pieces.queens.erase({di, dj});
#else
      cached_pieces.queens.erase(
          std::remove(std::begin(cached_pieces.queens), std::end(cached_pieces.queens),
              std::make_pair(di, dj)),
          std::end(cached_pieces.queens));
#endif
      break;
    }
  }
  auto& cached_pieces = cached_pieces_[cache_];
  switch (piece) {
  case defs::rook:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
    cached_pieces.rooks.erase({si, sj});
    cached_pieces.rooks.insert({di, dj});
#else
    cached_pieces.rooks.erase(
        std::remove(std::begin(cached_pieces.rooks), std::end(cached_pieces.rooks),
            std::make_pair(si, sj)),
        std::end(cached_pieces.rooks));
    cached_pieces.rooks.push_back({di, dj});
#endif
    break;
  case defs::bishop:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
    cached_pieces.bishops.erase({si, sj});
    cached_pieces.bishops.insert({di, dj});
#else
    cached_pieces.bishops.erase(
        std::remove(std::begin(cached_pieces.bishops), std::end(cached_pieces.bishops),
            std::make_pair(si, sj)),
        std::end(cached_pieces.bishops));
    cached_pieces.bishops.push_back({di, dj});
#endif
    break;
  case defs::queen:
#if defined(CHESS_OPT_SET) || defined(CHESS_OPT_UNORDERED_SET)
    cached_pieces.queens.erase({si, sj});
    cached_pieces.queens.insert({di, dj});
#else
    cached_pieces.queens.erase(
        std::remove(std::begin(cached_pieces.queens), std::end(cached_pieces.queens),
            std::make_pair(si, sj)),
        std::end(cached_pieces.queens));
    cached_pieces.queens.push_back({di, dj});
#endif
    break;
  }
  board_[si][sj][0] = defs::whitespace;
  board_[si][sj][1] = defs::whitespace;
  board_[di][dj][0] = color;
  board_[di][dj][1] = piece;
  li = di;
  lj = dj;
}

bool game::find_ncross(char srow, char scol, int di, int dj, int& si, int& sj, const cache_t& cache) const
{
  auto walk = [&](int ci, int cj) {
    if ((ci != di && cj != dj) ||
        (ci == di && cj == dj)) {
      return false;
    }
    if (ci == di) {
      if (cj > dj) {
        // go right
        for (int j = dj + 1; j <= cj; ++j) {
          if (valid0(color_, piece_, ci, j)) {
            si = ci;
            sj = j;
            return true;
          }
          if (!valid0(defs::whitespace, defs::whitespace, ci, j)) {
            break;
          }
        }
      } else {
        // go left
        for (int j = dj - 1; j >= cj; --j) {
          if (valid0(color_, piece_, ci, j)) {
            si = ci;
            sj = j;
            return true;
          }
          if (!valid0(defs::whitespace, defs::whitespace, ci, j)) {
            break;
          }
        }
      }
    } else {
      if (ci > di) {
        // go up
        for (int i = di + 1; i <= ci; ++i) {
          if (valid0(color_, piece_, i, cj)) {
            si = i;
            sj = cj;
            return true;
          }
          if (!valid0(defs::whitespace, defs::whitespace, i, cj)) {
            break;
          }
        }
      } else {
        // go down
        for (int i = di - 1; i >= ci; --i) {
          if (valid0(color_, piece_, i, cj)) {
            si = i;
            sj = cj;
            return true;
          }
          if (!valid0(defs::whitespace, defs::whitespace, i, cj)) {
            break;
          }
        }
      }
    }
    return false;
  };
  // no sanity checks!
  bool valid_srow = valid_row(srow);
  bool valid_scol = valid_col(scol);
  if (!valid_srow && !valid_scol) {
    for (const auto& [ci, cj] : cache) {
      if (walk(ci, cj)) {
        return true;
      }
    }
    return false;
  }
  if (valid_srow) {
    si = row_to_index(srow);
    for (const auto& [ci, cj] : cache) {
      if (ci == si && walk(ci, cj)) {
        return true;
      }
    }
    return false;
  }
  if (valid_scol) {
    sj = col_to_index(scol);
    for (const auto& [ci, cj] : cache) {
      if (cj == sj && walk(ci, cj)) {
        return true;
      }
    }
    return false;
  }
  si = row_to_index(srow);
  sj = col_to_index(scol);
  return true;
}

bool game::find_xcross(char srow, char scol, int di, int dj, int& si, int& sj, const cache_t& cache) const
{
  auto walk = [&](int ci, int cj) {
    if (abs(ci - di) != abs(cj - dj)) {
      return false;
    }
    if (ci > di) {
      if (cj > dj) {
        // go down-right
        for (int i = di + 1, j = dj + 1; i <= ci && j <= cj; ++i, ++j) {
          if (valid0(color_, piece_, i, j)) {
            si = i;
            sj = j;
            return true;
          }
          if (!valid0(defs::whitespace, defs::whitespace, i, j)) {
            break;
          }
        }
      } else {
        // go down-left
        for (int i = di + 1, j = dj - 1; i <= ci && j >= cj; ++i, --j) {
          if (valid0(color_, piece_, i, j)) {
            si = i;
            sj = j;
            return true;
          }
          if (!valid0(defs::whitespace, defs::whitespace, i, j)) {
            break;
          }
        }
      }
    } else {
      if (cj > dj) {
        // go up-right
        for (int i = di - 1, j = dj + 1; i >= ci && j <= cj; --i, ++j) {
          if (valid0(color_, piece_, i, j)) {
            si = i;
            sj = j;
            return true;
          }
          if (!valid0(defs::whitespace, defs::whitespace, i, j)) {
            break;
          }
        }
      } else {
        // go up-left
        for (int i = di - 1, j = dj - 1; i >= ci && j >= cj; --i, --j) {
          if (valid0(color_, piece_, i, j)) {
            si = i;
            sj = j;
            return true;
          }
          if (!valid0(defs::whitespace, defs::whitespace, i, j)) {
            break;
          }
        }
      }
    }
    return false;
  };
  // no sanity checks!
  bool valid_srow = valid_row(srow);
  bool valid_scol = valid_col(scol);
  if (!valid_srow && !valid_scol) {
    for (const auto& [ci, cj] : cache) {
      if (walk(ci, cj)) {
        return true;
      }
    }
    return false;
  }
  if (valid_srow) {
    si = row_to_index(srow);
    for (const auto& [ci, cj] : cache) {
      if (ci == si && walk(ci, cj)) {
        return true;
      }
    }
    return false;
  }
  if (valid_scol) {
    sj = col_to_index(scol);
    for (const auto& [ci, cj] : cache) {
      if (cj == sj && walk(ci, cj)) {
        return true;
      }
    }
    return false;
  }
  si = row_to_index(srow);
  sj = col_to_index(scol);
  return true;
}

bool game::find_around(char srow, char scol, int di, int dj, int& si, int& sj, const directions_t& directions) const
{
  // no sanity checks!
  bool valid_srow = valid_row(srow);
  bool valid_scol = valid_col(scol);
  if (!valid_srow && !valid_scol) {
    for (const auto& [x, y] : directions) {
      if (valid1(color_, piece_, di + x, dj + y)) {
        si = di + x;
        sj = dj + y;
        return true;
      }
    }
    return false;
  }
  if (valid_srow) {
    si = row_to_index(srow);
    for (const auto& [x, y] : directions) {
      if (di + x == si &&
          valid1(color_, piece_, si, dj + y)) {
        sj = dj + y;
        return true;
      }
    }
    return false;
  }
  if (valid_scol) {
    sj = col_to_index(scol);
    for (const auto& [x, y] : directions) {
      if (dj + y == sj &&
          valid1(color_, piece_, di + x, sj)) {
        si = di + x;
        return true;
      }
    }
    return false;
  }
  si = row_to_index(srow);
  sj = col_to_index(scol);
  return true;
}

bool game::find_capturing_pawn(char srow, char scol, int di, int dj, int& si, int& sj) const
{
  // no en passant capture support!
  // no sanity checks!
  bool valid_srow = valid_row(srow);
  bool valid_scol = valid_col(scol);
  if (!valid_srow && !valid_scol) {
    if (color_ == defs::white) {
      if (valid1(color_, piece_, di - 1, dj - 1)) {
        si = di - 1;
        sj = dj - 1;
        return true;
      }
      if (valid1(color_, piece_, di - 1, dj + 1)) {
        si = di - 1;
        sj = dj + 1;
        return true;
      }
    } else {
      if (valid1(color_, piece_, di + 1, dj - 1)) {
        si = di + 1;
        sj = dj - 1;
        return true;
      }
      if (valid1(color_, piece_, di + 1, dj + 1)) {
        si = di + 1;
        sj = dj + 1;
        return true;
      }
    }
    return false;
  }
  if (valid_srow) {
    si = row_to_index(srow);
    if (color_ == defs::white) {
      if (si == di - 1) {
        if (valid1(color_, piece_, si, dj - 1)) {
          sj = dj - 1;
          return true;
        }
        if (valid1(color_, piece_, si, dj + 1)) {
          sj = dj + 1;
          return true;
        }
      }
    } else {
      if (si == di + 1) {
        if (valid1(color_, piece_, si, dj - 1)) {
          sj = dj - 1;
          return true;
        }
        if (valid1(color_, piece_, si, dj + 1)) {
          sj = dj + 1;
          return true;
        }
      }
    }
    return false;
  }
  if (valid_scol) {
    sj = col_to_index(scol);
    if (color_ == defs::white) {
      if (valid0(color_, piece_, di - 1, sj)) {
        si = di - 1;
        return true;
      }
    } else {
      if (valid1(color_, piece_, di + 1, sj)) {
        si = di + 1;
        return true;
      }
    }
    return false;
  }
  si = row_to_index(srow);
  sj = col_to_index(scol);
  return true;
}

bool game::find_pawn(char srow, char scol, int di, int dj, int& si, int& sj) const
{
  // no sanity checks!
  sj = dj;
  if (color_ == defs::white) {
    if (di == 3) {
      for (int i = di - 1; i >= di - 2; --i) {
        if (valid0(color_, piece_, i, sj)) {
          si = i;
          return true;
        }
        if (!valid0(defs::whitespace, defs::whitespace, i, sj)) {
          break;
        }
      }
    } else if (di > 1) {
      if (valid0(color_, piece_, di - 1, sj)) {
        si = di - 1;
        return true;
      }
    }
  } else {
    if (di == 4) {
      for (int i = di + 1; i <= di + 2; ++i) {
        if (valid0(color_, piece_, i, sj)) {
          si = i;
          return true;
        }
        if (!valid0(defs::whitespace, defs::whitespace, i, sj)) {
          break;
        }
      }
    } else if (di < 6) {
      if (valid0(color_, piece_, di + 1, sj)) {
        si = di + 1;
        return true;
      }
    }
  }
  return false;
}

bool game::find_rook(char srow, char scol, int di, int dj, int& si, int& sj) const
{
  return find_ncross(srow, scol, di, dj, si, sj, cached_pieces_[cache_].rooks);
}

bool game::find_knight(char srow, char scol, int di, int dj, int& si, int& sj) const
{
  static const directions_t directions{
    {+1,-2}, {+2,-1}, {+2,+1}, {+1,+2}, {-1,+2}, {-2,+1}, {-2,-1}, {-1,-2}
  };
  return find_around(srow, scol, di, dj, si, sj, directions);
}

bool game::find_bishop(char srow, char scol, int di, int dj, int& si, int& sj) const
{
  return find_xcross(srow, scol, di, dj, si, sj, cached_pieces_[cache_].bishops);
}

bool game::find_queen(char srow, char scol, int di, int dj, int& si, int& sj) const
{
  return find_ncross(srow, scol, di, dj, si, sj, cached_pieces_[cache_].queens) ||
         find_xcross(srow, scol, di, dj, si, sj, cached_pieces_[cache_].queens);
}

bool game::find_king(char srow, char scol, int di, int dj, int& si, int& sj) const
{
  static const directions_t directions{
    {-0,-1}, {+1,-1}, {+1,+0}, {+1,+1}, {+0,+1}, {-1,+1}, {-1,-0}, {-1,-1}
  };
  return find_around(srow, scol, di, dj, si, sj, directions);
}

inline bool game::valid0(char color, char piece, int si, int sj) const
{
  if (board_[si][sj][0] != color ||
      board_[si][sj][1] != piece) {
    return false;
  }
  return true;
}

inline bool game::valid1(char color, char piece, int si, int sj) const
{
  if (si < 0 || si > 7 || sj < 0 || sj > 7) {
    return false;
  }
  if (board_[si][sj][0] != color ||
      board_[si][sj][1] != piece) {
    return false;
  }
  return true;
}

} // namespace chess
