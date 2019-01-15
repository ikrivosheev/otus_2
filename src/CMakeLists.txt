configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

add_executable(ip_filter main.cpp)

add_library(utils version.cpp utils.cpp utils.h)

set_target_properties(ip_filter utils PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(ip_filter utils)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ip_filter RUNTIME DESTINATION bin)

