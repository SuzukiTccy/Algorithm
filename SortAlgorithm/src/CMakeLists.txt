cmake_minimum_required(VERSION 3.10)


# 查找当前目录下所有源文件
# 并将文件名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(SortAlgorithm ${DIR_LIB_SRCS})