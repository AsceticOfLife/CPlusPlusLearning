cmake_minimum_required(VERSION 3.0)
project(DesignMode)
aux_source_directory(./src/5.chocolate chocolate) # 源文件列表
aux_source_directory(./src code)
add_executable(main ${code} ${chocolate})


