cmake_minimum_required(VERSION 3.20)

project(ClientDataBase001)

#прописываем версию PostgreSQL (ищем здесь C:\Program Files\PostgreSQL\16)
set(PostgreSQL_ADDITIONAL_VERSIONS "16")

#подключаем к проекту API postgreSQL для С++, а именно libpqxx,
#указав его путь (слэши двойные!!!). libpqxx-build - каталого для сборки
add_subdirectory("C:\\Work\\Projects\\libpqxx-7.9.0" libpqxx-build)

#подключаем к проекту исполняемый файл- бинарник
add_executable(ClientDataBase001 main.cpp)

#подключаем поддержку С++ 17
target_compile_features(ClientDataBase001 PRIVATE cxx_std_17)

#подключаем библиотеку libpq++ к проекту
target_link_libraries(ClientDataBase001 PRIVATE pqxx)