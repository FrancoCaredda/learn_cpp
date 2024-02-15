#include <iostream>
#include <bitset>
#include <string>

int main(int argc, char** argv)
{
	// Let's pack four 1 byte numbers inside a 4 byte variable
	uint32_t value = 0;// 4 bytes.

	value = (1 << 24) |
			(2 << 16) |
			(3 << 8) |
			4;

	std::bitset<32> bitset(value);
	std::string bitsetToFormat = bitset.to_string();

	std::cout << bitsetToFormat.substr(0, 8) << " " 
			  << bitsetToFormat.substr(8, 8) << " " 
			  << bitsetToFormat.substr(16, 8) << " " 
			  << bitsetToFormat.substr(24, 8) << "\n";

	// Let's unpack four 1 byte numbers from the 4 byte variable
	std::cout << (value >> 24)         << " "
			  << ((value << 8) >> 24)  << " "
			  << ((value << 16) >> 24) << " "
			  << ((value << 24) >> 24) << "\n";

	// Let's unpack four 1 byte numbers from the 4 byte variable using masks instead of the shifts
	std::cout << ((value & 0xFF000000) >> 24) << " "
			  << ((value & 0x00FF0000) >> 16) << " "
			  << ((value & 0x0000FF00) >> 8) << " "
			  << (value  & 0x000000FF) << "\n";

	// Let's remove the third value from the variable and check if it's a zero
	value &= 0xFF00FFFF;

	if (!(value & 0x00FF0000))
	{
		std::cout << "The third value is a zero now!";
	}


	return 0;
}