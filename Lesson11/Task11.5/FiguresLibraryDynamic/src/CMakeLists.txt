#для проекта исполняемого файла
CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY C:/Users/User/Documents/C++/Homworks/Lesson11/Task11.5/FiguresLibraryDynamic/lib)#библиотечные файлы
#будут помещены в каталог lib по указанному пути
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY C:/Users/User/Documents/C++/Homworks/Lesson11/Task11.5/FiguresLibraryDynamic/bin)# в bin будут
#положены как exe-файлы, так и dll-файлы
project(Figures_project VERSION 0.1 LANGUAGES CXX)#создал проект Figures_project
include_directories(figures_library_dynamic)# в каталоге figures_library_dynamic будут искаться каталоги с заголовочными файлами
add_executable(Figures_project FiguresClient.cpp)#проект Figures_project будет собираться из исполняемого файла FiguresClient.cpp
add_subdirectory(figures_library_dynamic)#создаю каталог в каталоге build для промежуточных проектных файлов
target_link_libraries(Figures_project figur_lib)#связываю проект клиента с динамической библиотекой figures_lib