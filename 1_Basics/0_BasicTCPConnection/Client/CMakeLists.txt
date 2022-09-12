project(${NETWORK_PROJECT_NAME}Client VERSION 1.0.0)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${NETWORK_PROJECT_NAME}Client src/EntryPoint.cpp src/Application.cpp)
add_executable(${NETWORK_PROJECT_NAME}ClientTest test/main.cpp test/HelloTest.cpp)

target_include_directories(${NETWORK_PROJECT_NAME}Client PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/ProjectClient>)

target_link_libraries(
        ${NETWORK_PROJECT_NAME}ClientTest
        gtest
        gmock
)

include(GoogleTest)
gtest_discover_tests(${NETWORK_PROJECT_NAME}ClientTest)