#include <iostream>
#include <stdint.h>

struct Data
{
	int	storedValue;
};

uintptr_t serialize(Data* dataPtr)
{
	return reinterpret_cast<uintptr_t>(dataPtr);
}

Data* deserialize(uintptr_t serializedAddress)
{
	return reinterpret_cast<Data*>(serializedAddress);
}

int	main()
{
	Data		dataValue;
	Data*		restoredData;
	uintptr_t	serializedAddress;

	dataValue.storedValue = 42;
	serializedAddress = serialize(&dataValue);
	std::cout << "data value: " << dataValue.storedValue << std::endl;
	std::cout << "data ptr(hexa): " << &dataValue << std::endl;
	std::cout << "data ptr(decimal): " << serializedAddress << std::endl;

	std::cout << "========================================" << std::endl;

	restoredData = deserialize(serializedAddress);
	std::cout << "data value: " << restoredData->storedValue << std::endl;
	std::cout << "data ptr(hexa): " << restoredData << std::endl;
	std::cout << "data ptr(decimal): " << serialize(restoredData) << std::endl;

	return 0;
}
