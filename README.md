# Purpose
This is an exploratory project inspired by my recent work with the 
Robot Operating System (ROS) middleware for Linux robotics applications. 
The ROS community has developed the tool catkin for managing CMake 
builds of an ecosystem of packages and for specifying those packages' 
dependencies.

Many of the same problems ROS developers wanted to overcome with catkin
can be found in embedded projects including managing dependencies on
libraries by third parties, loose coupling between components, a simple
build process (developers want to focus on robots/embedded systems, not
build management). In noticing this I decided to see how difficult it
would be to get an STM32 binary to pop out of a catkin build and to test
the package management approach by developing several packages, some of
which are dependent on third party source code (code by STMicroelectronics
in this case).

# My Environment Set Up
I'm running Ubuntu 18.04 and have ROS Melodic installed (this comes with
catkin). There is likely an easier way to get just catkin, but I haven't
looked into it yet.

You'll also need:
* ARM-GCC toolchain
* A copy of STMicroelectronics HAL for STM32F4 (a symlink in the stm32-hal-f4
will need to be updated to the location of this).
* To modify a file in ROS: Comment out the assert in 
`/opt/ros/melodic/share/catkin/cmake/tools/rt.cmake`. I don't think this hurts
anything in Ubuntu Linux ROS builds.
* Optional: CLion. Not required, but it makes working with CMake projects so
much easier. You'll need to follow their guide for setting up for a ROS
environment.

# Building
The first time, at the top of your catkin workspace:

`catkin_make -DCMAKE_TOOLCHAIN_FILE=/src/app-blink/toolchain/stm32f4-toolchain.cmake`

Anytime after that, at the top of your catkin workspace:

`catkin_make`
