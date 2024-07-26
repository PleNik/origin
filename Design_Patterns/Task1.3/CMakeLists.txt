cmake_minimum_required(VERSION 3.20)

project(StudentDataBase001)

#прописываем версию PostgreSQL (ищем здесь C:\Program Files\PostgreSQL\16)
set(PostgreSQL_ADDITIONAL_VERSIONS "16")

#подключаем к проекту API postgreSQL для С++, а именно libpqxx,
#указав его путь (слэши двойные!!!). libpqxx-build - каталого для сборки
add_subdirectory("C:\\Work\\Projects\\libpqxx-7.9.0" libpqxx-build)

#подключаем к проекту исполняемый файл- бинарник
add_executable(StudentDataBase001 main.cpp "sql_query_builder.h" "sql_query_builder.cpp" )

#подключаем поддержку С++ 17
target_compile_features(StudentDataBase001 PRIVATE cxx_std_17)

#подключаем библиотеку libpq++ к проекту
target_link_libraries(StudentDataBase001 PRIVATE pqxx)