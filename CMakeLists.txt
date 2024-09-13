cmake_minimum_required(VERSION 3.29)
project(cpp_study)

set(CMAKE_CXX_STANDARD 20)

# 添加 libcurl 和其他依赖库的路径
set(CURL_INCLUDE_DIR "D:/project/libcurl/include")
set(CURL_LIBRARY "D:/project/libcurl/lib/libcurl.dll.a")
set(CURL_DEPENDENCIES
        "D:/project/libcurl/lib/libcrypto.a"
        "D:/project/libcurl/lib/libssl.a"
        "D:/project/libcurl/lib/libz.a"
        "D:/project/libcurl/lib/libbrotlicommon.a"
        "D:/project/libcurl/lib/libbrotlidec.a"
)

# 添加 include 目录
include_directories(${CURL_INCLUDE_DIR})

# 添加可执行文件
add_executable(cpp_study
        main.cpp
        telegram.cpp
        telegram.h
)

# 链接 libcurl 和依赖库
target_link_libraries(cpp_study ${CURL_LIBRARY} ${CURL_DEPENDENCIES})
