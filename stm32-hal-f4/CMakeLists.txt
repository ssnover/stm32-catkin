cmake_minimum_required(VERSION 3.0.0)
project(stm32-hal-f4)

#
# PACKAGE DEPENDENCIES
#
find_package(catkin REQUIRED)

#
# CATKIN PACAKGE
#
catkin_package(
    INCLUDE_DIRS
    Drivers/CMSIS/Device/ST/STM32F4xx/Include
    Drivers/CMSIS/Include
    Drivers/STM32F4xx_HAL_Driver/Inc
    LIBRARIES
    stm32f4_hal_conf
    stm32f4_hal_gpio
    stm32f4_hal_uart
)

#
# INCLUDES
#
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    Drivers/CMSIS/Device/ST/STM32F4xx/Include
    Drivers/CMSIS/Include
    Drivers/STM32F4xx_HAL_Driver/Inc
)

#
# LIBRARIES
#
set(HAL_SOURCE_DIR Drivers/STM32F4xx_HAL_Driver/Src)

add_definitions(
    -DSTM32F446xx
    -DUSE_HAL_DRIVER
    -DARM_MATH_CM4
    -DARM_MATH_MATRIX_CHECK
    -DARM_MATH_ROUNDING
    -D__weak=__attribute__\(\(weak\)\)
    -D__packed=__attriubte__\(\(__packed__\)\)
)

add_library(stm32f4_hal STATIC ${HAL_SOURCE_DIR}/stm32f4xx_hal.c)
add_library(stm32f4_hal_gpio STATIC ${HAL_SOURCE_DIR}/stm32f4xx_hal_gpio.c)
add_library(stm32f4_hal_uart STATIC ${HAL_SOURCE_DIR}/stm32f4xx_hal_uart.c)

add_library(stm32f4_hal_conf INTERFACE)
target_include_directories(stm32f4_hal_conf INTERFACE include/)
