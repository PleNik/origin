cmake_minimum_required(VERSION 3.20)

project(ClientDataBase001)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

add_subdirectory("C:\\Work\\Projects\\libpqxx-7.9.0" libpqxx-build)

add_executable(ClientDataBase001 main.cpp)

target_compile_features(ClientDataBase001 PRIVATE cxx_std_17)

target_link_libraries(ClientDataBase001 PRIVATE pqxx)