cmake_minimum_required(VERSION 3.5)

if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(PROJECT_MINOR_VERSION $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(PROJECT_MINOR_VERSION 0)
endif()

project(ip_filter VERSION 0.0.${PROJECT_MINOR_VERSION})

include(gtest.cmake)

configure_file(src/config.h.in src/config.h)

find_package (Threads)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    src
)

add_executable(ip_filter src/main.cpp)

add_executable(test_ip_filter tests/test_ip_filter.cpp)

add_library(utils src/version.cpp src/utils.cpp)

set_target_properties(ip_filter test_ip_filter utils gtest PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(ip_filter
    utils
)

target_link_libraries(test_ip_filter
    gtest
    ${CMAKE_THREAD_LIBS_INIT}
	utils
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

enable_testing()

add_test(test_ip_filter test_ip_filter)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT py.krivosheev@gmail.com)
set(CPACK_PACKAGE_DESCRIPTION "IP filter from stdout")

include(CPack)

