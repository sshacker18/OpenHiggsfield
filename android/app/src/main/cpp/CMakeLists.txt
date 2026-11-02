cmake_minimum_required(VERSION 3.22.1)
project(openhiggsfield_gpu_probe LANGUAGES CXX)

add_library(gpu_probe SHARED gpu_probe.cpp)
target_compile_features(gpu_probe PRIVATE cxx_std_17)
target_compile_options(gpu_probe PRIVATE -Wall -Wextra)
find_library(vulkan-lib vulkan)
find_library(log-lib log)
target_link_libraries(gpu_probe PRIVATE ${vulkan-lib} ${log-lib})
