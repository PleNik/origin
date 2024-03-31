#для проекта исполняемого файла
CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")#библиотечные файлы
#будут помещены в каталог lib по указанному пути

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")# в bin будут положены как exe-файлы, так и dll-файлы

project(RasingSimulator_project VERSION 0.2 LANGUAGES CXX)#создал проект RasingSimulator_project

include_directories(LibraryDynamic)# в каталоге LibraryDynamic будут искаться каталоги с заголовочными файлами

add_executable(RasingSimulator_project RacingSimulator.cpp)#проект RasingSimulator_project будет собираться из исполняемого файла RacingSimulator.cpp

add_subdirectory(LibraryDynamic)#создаю каталог в каталоге build для промежуточных проектных файлов

target_link_libraries(RasingSimulator_project racing_lib)#связываю проект клиента с динамической библиотекой - racing_lib