# CMake file

# cmake minimum version required
cmake_minimum_required (VERSION 3.10)

# project name
project (project_sort_algorithm)

# set C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# 启用线程支持
find_package(Threads REQUIRED)

# 添加可执行文件
add_executable(exe_sortalgorithm)

# 添加子文件夹
add_subdirectory(./src ../bin)

# 添加源文件
target_sources(exe_sortalgorithm
    PRIVATE
    ./main.cpp
)

# 添加头文件搜索路径
target_include_directories(exe_sortalgorithm
    PUBLIC
    ./include
)

# 添加依赖库
target_link_libraries(exe_sortalgorithm
    PRIVATE
    SortAlgorithm
    Threads::Threads
)


# 针对不同平台的编译选项
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")  # macOS
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    # Windows 通常不需要额外标志
endif()


# ========== 修改：添加run目标 ==========
# 创建run目标，只有在显式执行make run时才会运行程序
add_custom_target(run
    DEPENDS exe_sortalgorithm
    COMMAND echo "=== 运行程序 ==="
    COMMAND $<TARGET_FILE:exe_sortalgorithm> # 生成器表达式，获取exe_sortalgorithm可执行文件的路径
    COMMAND echo "=== 程序执行完成 ==="
)