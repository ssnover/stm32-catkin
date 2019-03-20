/*
 * file: i2c-intf.hpp
 * purpose: Define an abstract interface class for interfacing an I2C communication
 *          bus.
 */

#ifndef HARDWARE_INTF_I2C_INTF_HPP
#define HARDWARE_INTF_I2C_INTF_HPP

#include <cstdint>

namespace i2c
{

template <typename Derived>
class I2cIntf
{
protected:

    I2cIntf() = default;

public:

    /*
     * Opens the I2C port for data transfer to a device.
     *
     * address - The address of the device to write to.
     *
     * Returns: True if opened for device, false otherwise.
     */
    inline bool open(uint16_t address)
    {
        return static_cast<Derived *>(this)->open(address);
    }

    /*
     * Closes the I2C port.
     *
     * Returns: True if closed, false otherwise.
     */
    inline bool close()
    {
        return static_cast<Derived *>(this)->close();
    }

    /*
     * Writes data to a device on an open I2C bus.
     *
     * data - A pointer to the buffer containing data to be written.
     * numberOfBytes - The number of bytes to be written from the buffer.
     *
     * Returns: The number of bytes written.
     */
    inline unsigned int write(uint8_t * data, unsigned int numberOfBytes)
    {
        return static_cast<Derived *>(this)->write(data, numberOfBytes);
    }

    /*
     * Reads data from an open I2C bus into a buffer.
     *
     * data - A pointer to the buffer where data will be written.
     * numberOfBytes - The number of bytes to read from the bus.
     *
     * Returns: The number of bytes read.
     */
    inline unsigned int read(uint8_t * data, unsigned int numberOfBytes)
    {
        return static_cast<Derived *>(this)->read(data, numberOfBytes);
    }

    /*
     * Gets the frequency of the bus transmission.
     *
     * Returns: The frequency in hertz.
     */
    inline unsigned int getFrequency()
    {
        return static_cast<Derived *>(this)->getFrequency();
    }
};

} // namespace i2c

#endif // HARDWARE_INTF_I2C_INTF_HPP
