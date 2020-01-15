cmake_minimum_required (VERSION 2.8) #指定需要的cmake的版本
project(matrix_test)
include_directories("${PROJECT_BINARY_DIR}/include") #设置头文件路径
add_executable(matrix_test main.cpp src/matrix.cpp)  #这里写源文件（必须带路径）
#target_link_libraries(...)  如果链接了其他库使用这条指令