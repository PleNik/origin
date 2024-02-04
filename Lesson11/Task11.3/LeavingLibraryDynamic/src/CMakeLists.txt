#для проекта исполняемого файла
CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY C:/Users/User/Documents/C++/Homworks/Lesson11/Task11.3/LeavingLibraryDynamic/lib)#библиотечные файлы
#будут помещены в каталог lib по указанному пути
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY C:/Users/User/Documents/C++/Homworks/Lesson11/Task11.3/LeavingLibraryDynamic/bin)# в bin будут
#положены как exe-файлы, так и dll-файлы
project(Leaving_project VERSION 0.1 LANGUAGES CXX)#создал проект Leaving_project
include_directories(leaving_library_dynamic)# в каталоге leaving_library_dynamic будут искаться каталоги с заголовочными файлами
add_executable(Leaving_project LeavingClient.cpp)#проект Leaving_project будет собираться из исполняемого файла LeavingClient.cpp
add_subdirectory(leaving_library_dynamic)#создаю каталог в каталоге build для промежуточных проектных файлов
target_link_libraries(Leaving_project leav_lib)#связываю проект клиента с динамической библиотекой leav_lib