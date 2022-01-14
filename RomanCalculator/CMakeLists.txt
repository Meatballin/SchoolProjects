cmake_minimum_required(VERSION 3.17)
project(RomanCalculatorStarter)

set(CMAKE_CXX_STANDARD 17)

add_executable(RomanCalculatorStarter main.cpp Token.cpp Token.hpp InfixToPostfix.cpp InfixToPostfix.hpp TokenIterator.cpp TokenIterator.hpp Tokenizer.cpp Tokenizer.hpp RomanNumber.cpp RomanNumber.hpp)