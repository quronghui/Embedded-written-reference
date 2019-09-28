cmake_minimum_required(VERSION 3.14)
project(code C)

set(CMAKE_C_STANDARD 99)

add_executable(code main.c)
add_executable(one_array_transmit_paramter one_array_transmit_paramter.c)
add_executable(double_array_tran_pram double_array_tran_pram.c)
add_executable(funcation_array funcation_array.c)
add_executable(pointer_funcation pointer_funcation.c)
add_executable(sizeof_value sizeof_value.c)

