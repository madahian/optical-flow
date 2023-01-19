cmake_minimum_required(VERSION 3.16)

project(AdvPT VERSION 1.0
              DESCRIPTION "Tensors"
              LANGUAGES CXX)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test_tensor test_tensor.cpp)
target_compile_features(test_tensor PRIVATE cxx_std_20)
target_compile_options(test_tensor PRIVATE -Wall -Wextra -pedantic -Werror -pg -g)
target_link_options(test_tensor PRIVATE -pg)

add_executable(test_matvec test_matvec.cpp)
target_compile_features(test_matvec PRIVATE cxx_std_20)
target_compile_options(test_matvec PRIVATE -Wall -Wextra -pedantic -Werror -pg -g)
target_link_options(test_matvec PRIVATE -pg)


add_executable(optical_flow optical_flow.cpp)
target_link_libraries(optical_flow X11)
target_compile_features(optical_flow PRIVATE cxx_std_20)
target_compile_options(optical_flow PRIVATE -Wall -Wextra -pedantic -Werror -pg -g)
target_link_options(optical_flow PRIVATE -pg)

add_executable(test_derivative test_derivative.cpp)
target_compile_features(test_derivative PRIVATE cxx_std_20)
target_compile_options(test_derivative PRIVATE -Wall -Wextra -pedantic -Werror -pg -g)
target_link_options(test_derivative PRIVATE -pg)

add_executable(test_linear test_linear.cpp)
target_compile_features(test_linear PRIVATE cxx_std_20)
target_compile_options(test_linear PRIVATE -Wall -Wextra -pedantic -Werror -pg -g)
target_link_options(test_linear PRIVATE -pg)