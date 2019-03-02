cmake_minimum_required(VERSION 3.0.0)
project(app-blink)

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
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F446RETx_FLASH.ld)
set(FPU_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
set(COMMON_FLAGS "${FPU_FLAGS} -g -fno-common -fmessage-length=0 -specs=nosys.specs -specs=nano.specs")
set(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS} --std=c++17")
set(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS} --std=gnu99")

add_executable(app-blink ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(app-blink ${catkin_LIBRARIES} stm32f4_hal_gpio)
target_compile_options(app-blink
    PRIVATE
        "-Wl,-gc-sections -T ${LINKER_SCRIPT}"
        -mcpu=cortex-m4
        -mthumb
        -mthumb-interwork
        -ffunction-sections
        -fdata-sections
        -mfloat-abi=hard
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