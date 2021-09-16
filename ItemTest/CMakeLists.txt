cmake_minimum_required(VERSION 3.20)
project(ItemTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(ItemTest/Include)
include_directories(ItemTest/src)

add_executable(ItemTest
    ItemTest/Include/flecs.c
    ItemTest/Include/flecs.h
    ItemTest/Include/flecs_systems_civetweb.c
    ItemTest/Include/flecs_systems_civetweb.h
    ItemTest/Include/flecs_components_http.c
    ItemTest/Include/flecs_components_http.h
    ItemTest/Include/flecs_os_api_stdcpp.cpp
    ItemTest/Include/flecs_os_api_stdcpp.h
    ItemTest/Include/flecs_json.c
    ItemTest/Include/flecs_json.h
    ItemTest/Include/flecs_meta.c
    ItemTest/Include/flecs_meta.h
    ItemTest/src/Item.cpp
    ItemTest/src/Item.h
    ItemTest/src/ItemComponents.cpp
    ItemTest/src/ItemComponents.h
    ItemTest/src/ItemConfig.cpp
    ItemTest/src/ItemConfig.h
    ItemTest/src/ItemConfigComponents.h
    ItemTest/src/main.cpp)

#[[ItemTest/Include/flecs_player.c
ItemTest/Include/flecs_player.h
ItemTest/Include/flecs_rest.c
ItemTest/Include/flecs_rest.h

    ItemTest/Include/flecs_components_http.c
    ItemTest/Include/flecs_components_http.h
    ItemTest/Include/flecs_dash.c
    ItemTest/Include/flecs_dash.h

    ItemTest/Include/flecs_monitor.c
    ItemTest/Include/flecs_monitor.h]]