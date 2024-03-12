cmake_minimum_required(VERSION 3.27)

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
add_definitions(-DBOOST_LOG_DYN_LINK)

add_executable(chess
# ${CMAKE_CURRENT_BINARY_DIR}/pgn.lex.c
# ${CMAKE_CURRENT_BINARY_DIR}/pgn.tab.c
  pgn.lex.c
  pgn.tab.c
  game.cpp
  main.cpp)

set_property(TARGET chess PROPERTY CXX_STANDARD 20)
target_link_libraries(chess
  boost_system
  boost_thread
  pthread)

add_executable(chess-highload-tests
  game.cpp
  tests/tests_highload.cpp)

set_property(TARGET chess-highload-tests PROPERTY CXX_STANDARD 20)
target_link_libraries(chess-highload-tests
  boost_system
  boost_thread
  pthread)

add_executable(chess-tests
  game.cpp
  tests/tests.cpp)

set_property(TARGET chess-tests PROPERTY CXX_STANDARD 20)
target_link_libraries(chess-tests
  boost_system
  boost_thread
  pthread)

add_test(NAME chess-tests COMMAND chess-tests)
