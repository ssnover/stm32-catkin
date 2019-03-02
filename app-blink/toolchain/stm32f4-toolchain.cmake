set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.7)

# specify the cross compiler
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_C_COMPILER /home/ssnover/tools/gcc-arm-none-eabi-7-2018-q2-update/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER /home/ssnover/tools/gcc-arm-none-eabi-7-2018-q2-update/bin/arm-none-eabi-g++)
set(AS /home/ssnover/tools/gcc-arm-none-eabi-7-2018-q2-update/bin/arm-none-eabi-as)
set(AR arm-none-eabi-ar)
set(OBJCOPY arm-none-eabi-objcopy)
set(OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)

add_definitions(
    -DSTM32F446xx
    -DUSE_HAL_DRIVER
    -DARM_MATH_CM4
    -DARM_MATH_MATRIX_CHECK
    -DARM_MATH_ROUNDING
    -D__weak=__attribute__\(\(weak\)\)
    -D__packed=__attriubte__\(\(__packed__\)\)
)

# NOTE: To make this work I had to remove the assert in ROS's rt.cmake file