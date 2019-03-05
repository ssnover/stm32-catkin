cmake_minimum_required(VERSION 3.0.0)
project(app-blink CXX C ASM)

#
# PACKAGE DEPENDENCIES
#
find_package(catkin REQUIRED
    COMPONENTS
        stm32-hal-f4)

#
# CATKIN PACAKGE
#
catkin_package(
        INCLUDE_DIRS
        include
        LIBRARIES
)

#
# INCLUDES
#
include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)

#
# EXECUTABLES
#
set(LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/STM32F446RETx_FLASH.ld)
#set(FPU_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

#add_library(app-startup ${PROJECT_SOURCE_DIR}/src/startup_stm32f446xx.s)

add_executable(app-blink
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/startup_stm32f446xx.s)
target_include_directories(app-blink
    PRIVATE
        ${catkin_INCLUDE_DIRS})
target_compile_options(app-blink
    PRIVATE
        -fno-common
        -fmessage-length=0
        -mcpu=cortex-m4
        -mthumb
        -mthumb-interwork
        -ffunction-sections
        -fdata-sections
        -mfloat-abi=soft
        -mfpu=fpv4-sp-d16)
target_compile_definitions(app-blink
    PUBLIC
        -DSTM32F446xx
        -DUSE_HAL_DRIVER
        -DARM_MATH_CM4
        -DARM_MATH_MATRIX_CHECK
        -DARM_MATH_ROUNDING
        -D__weak=__attribute__\(\(weak\)\)
        -D__packed=__attriubte__\(\(__packed__\)\))
target_link_libraries(app-blink
    ${catkin_LIBRARIES}
    stm32f4_hal
    stm32f4_hal_cortex
    stm32f4_hal_gpio
    stm32f4_hal_uart)
target_link_libraries(app-blink
    # LINK_FLAGS
    -specs=nosys.specs
    -specs=nano.specs
    -mfloat-abi=soft
    -mfpu=fpv4-sp-d16
    #-Wl,-gc-sections
    "-T ${LINKER_SCRIPT}")
