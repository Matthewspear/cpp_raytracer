
# Generic test that uses conan libs
add_executable(main main.cpp)
target_link_libraries(
    main PRIVATE project_options project_warnings 
    CONAN_PKG::docopt.cpp
    CONAN_PKG::fmt
    CONAN_PKG::spdlog
    CONAN_PKG::imgui-sfml)
