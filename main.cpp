#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>



class Address
{
private:
	std::string city;
	std::string street;
	int house_number;
	int apartment_number;
	std::string FullAddress;

public:

	Address(std::string City, std::string Street, int House, int Apartment)
	{
		city = City;
		street = Street;
		house_number = House;
		apartment_number = Apartment;
	}

	std::string get_output_adrress()
	{
		FullAddress = city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
		return FullAddress;
	};
};

int printArray(std::string* arr, const int numberOfAddresses)
{
	std::ofstream fout("out.txt", std::ios_base::trunc);

	fout << numberOfAddresses << std::endl;

	for (int i = 0; i < numberOfAddresses; i++)
	{
		fout << arr[i] << std::endl;
	}
	fout.close();
	return 0;
}

void sort(std::string* arr, const int numberOfAddresses)
{
	bool swapped = false;
	do
	{
		swapped = false;
		std::string tmp;

		for (int i = numberOfAddresses - 1; i > 1; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				tmp = arr[i-1];
				arr[i-1] = arr[i];
				arr[i] = tmp;
			    swapped = true;
			}
		}
	} while (swapped);
}

std::string* textArr(const int numberOfAddresses)
{
	std::string* TextArray = new std::string[numberOfAddresses];

	return TextArray;
}

void deleteTextArray(std::string* TextArray, const int numberOfAddresses)
{
	delete[] TextArray;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::ifstream fin("in.txt");

	int numberOfAddresses = 0;
	std::string City = {};
	std::string Street = {};
	int House = 0;
	int Apartment = 0;

	fin >> numberOfAddresses;

	std::string* arr = textArr(numberOfAddresses);

	for (int i = 0; i < numberOfAddresses; i++)
	{
		fin >> City >> Street >> House >> Apartment;
		Address address(City, Street, House, Apartment);
		arr[i] = address.get_output_adrress();
	}
	fin.close();

	sort(arr, numberOfAddresses);
	printArray(arr, numberOfAddresses);
	deleteTextArray(arr, numberOfAddresses);
}