cmake_minimum_required(VERSION 3.5)

# g++ test.cpp -o test --std=c++17 -lstdc++fs
add_executable(test test.cpp)
target_compile_features(test PRIVATE cxx_std_17)
target_link_libraries(test PRIVATE stdc++fs)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../)