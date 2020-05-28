

include_directories(include)

file(GLOB SRCS *.cpp include/*.h)

add_executable(main ${SRCS})

target_link_libraries(
    main PRIVATE project_options project_warnings 
    CONAN_PKG::docopt.cpp
    CONAN_PKG::fmt
    CONAN_PKG::spdlog
    CONAN_PKG::imgui-sfml)
