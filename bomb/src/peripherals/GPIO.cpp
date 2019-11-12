#include "GPIO.hpp"

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

GPIO::GPIO()
{
    pin_number = "0";
}

GPIO::GPIO(std::string pin)
{
    pin_number = pin;  
}

int GPIO::exportPin()
{
	return writeToFile("/sys/class/gpio/export", pin_number);
}

int GPIO::unexportPin()
{
    return writeToFile("/sys/class/gpio/unexport", pin_number);
}

int GPIO::setPinDirection(string direction)
{
    std::string path ="/sys/class/gpio/gpio" + pin_number + "/direction";
    return writeToFile(path, direction);
}

int GPIO::setPinValue(string value)
{
    std::string path = "/sys/class/gpio/gpio" + pin_number + "/value";
    return writeToFile(path, value);
}

int GPIO::getPinValue(string& value){

    std::string path = "/sys/class/gpio/gpio" + pin_number + "/value";
    return readFromFile(path, value);

}

int GPIO::writeToFile(std::string path, std::string value)
{
    ofstream file( path.c_str() );

    if ( ! file.is_open() )
    {
        std::cerr << "Unable to write" <<  value << " to " << path << std::endl;
        return -1;
    }

    file << value ;
    file.close();

    return 0;
}

int GPIO::readFromFile(std::string path, std::string& value)
{
    ifstream file(path.c_str());

    if ( ! file.is_open() )
    {
    	std::cerr << "Unable to write" <<  value << " to " << path << std::endl;
        return -1;
    }

    file >> value;

    file.close();
    return 0;
}
