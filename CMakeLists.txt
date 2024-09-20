cmake_minimum_required(VERSION 3.0.0)
project(GameEngine VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(GameEngine/include GameEngine/include/Renderer GameEngine/include/Physics GameEngine/include/Entity
                    GameEngine/include/Utility)
file(GLOB SOURCES "GameEngine/src/*.cpp")
file(GLOB RENDERER "GameEngine/src/Renderer/*.cpp")
file(GLOB PHYSICS "GameEngine/src/Physics/*.cpp")
file(GLOB ENTITY "GameEngine/src/Entity/*.cpp")
file(GLOB UTILITY "GameEngine/src/Utility/*.cpp")

add_executable(GameEngine GameEngine/Main.cpp ${SOURCES} ${RENDERER} ${PHYSICS} ${ENTITY} ${UTILITY})
target_link_libraries(GameEngine SDL2main SDL2 SDL2_image)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
