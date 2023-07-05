cmake_minimum_required(VERSION 3.24)
project(ATM C)

set(CMAKE_C_STANDARD 99)

add_executable(ATM app/main.c program/program.c program/program.c program/program.c validations/validations.c linked_list/linked_list.c filehandling/filehandling.c linked_list/linked_list.h card/card.c terminal/terminal.c server/server.c server/server.h app/app.c)
