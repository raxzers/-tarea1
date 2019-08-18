cmake_minimum_required(VERSION 3.14)
project(t1SERVER)

set(CMAKE_CXX_STANDARD 14)


find_package(Boost COMPONENTS system REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAGS ON)
find_package(Threads)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    set (Boost_USE_STATIC_LIBS ON)

endif()

add_executable(t1SERVER main.cpp servidor/Server.cpp servidor/Server.h servidor/con_handler.cpp servidor/con_handler.h estructuras/lnode.cpp estructuras/lnode.h estructuras/list.cpp estructuras/list.h estructuras/BST.cpp estructuras/BST.h estructuras/BSTNode.cpp estructuras/BSTNode.h)
if(Boost_FOUND)

    target_link_libraries(t1SERVER ${Boost_LIBRARIES})
    target_link_libraries(t1SERVER ${CMAKE_THREAD_LIBS_INIT})
endif()