/*
 * file: pca9685.hpp
 * purpose: A class definition for a driver for the PCA9685.
 */

#ifndef PCA9685_HPP
#define PCA9685_HPP

#include "hardware-intf/i2c-intf.hpp"

namespace pca9685
{

class PCA9685
{
public:

    /*
     * Gets a reference to a singleton driver for the PCA9685.
     *
     * ADDRESS - The I2C bus address of the driver.
     *
     * Returns: Pointer to the driver object.
     */
    template<uint16_t ADDRESS>
    static PCA9685 * getInstance();

private:

    /*
     * Constructor.
     */
    explicit PCA9685(uint16_t deviceAddress);

};

template<uint16_t ADDRESS>
PCA9685 * PCA9685::getInstance()
{
    static PCA9685 instance{ADDRESS};
    return &instance;
}

} // namespace pca9685

#endif // PCA9685_HPP
