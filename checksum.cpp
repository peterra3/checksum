#include <iostream>
#include <climits>


int main();


unsigned int add_checksum(unsigned int n);
void add_checksum(unsigned int array[], std::size_t capacity);
bool verify_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n);
void remove_checksum(unsigned int array[], std::size_t capacitiy);


int main() {
	//manual input of data is required
	//this code serves to be only the foundation
	unsigned int value_to_protect{ 99999999 };
	unsigned int protected_value = add_checksum(value_to_protect);

	std::cout << "The value " << value_to_protect
		<< " with the checksum added is " << protected_value
		<< "." << std::endl;

	if (verify_checksum(protected_value))
	{
		std::cout << "The checksum is valid." << std::endl;
	}
	else
	{
		std::cout << "The checksum is invalid." << std::endl;
	}


	std::size_t const qty_values{ 3 };
	unsigned int value_series[qty_values]{ 20201122, 20209913, 20224012 };

	add_checksum(value_series, qty_values);

	std::cout << "Series with checksums added: ";
	for (std::size_t series_index{ 0 }; series_index < qty_values; series_index++)
	{
		std::cout << value_series[series_index] << " ";
	}
	std::cout << std::endl;

	return 0;
}


unsigned int add_checksum(unsigned int n) {
	if (n <= 99999999) {
		int checked_sum{};
		int new_n{ static_cast<int>(n) };
		unsigned int digit_1;
		unsigned int digit_2;
		//calculate checked_sum

		while (n != 0) {
			digit_1 = (n % 10);
			digit_1 = digit_1 * 2;

			if (digit_1 > 9) {
				digit_1 = 1 + (digit_1 - 10);
			}

			//get new n
			n = n / 10;

			//Now we want get digit that does not multiply by 2
			digit_2 = (n) % 10;
			//get new n
			n = n / 10;

			checked_sum = checked_sum + digit_1 + digit_2;
		}
		//loop ends here
		checked_sum = (checked_sum * 9) % 10;

		//now we need to add the checksum number onto number n
		new_n = (new_n * 10) + checked_sum;


		return new_n;
	}
	else {
		return UINT_MAX;
	}
}

void add_checksum(unsigned int array[], std::size_t capacity) {
	for (std::size_t k{ 0 }; k < capacity; ++k) {
		array[k] = add_checksum(array[k]);
	}




	//function modifying add checksum as array therefore no return; just outputs
}

bool verify_checksum(unsigned int n) {
	int  n_9{}; //9 digit number that will get checksum removed

	n_9 = n / 10;





	if (n % 10 == add_checksum(n_9) % 10 && n <= 999999999) {
		return true;
	}
	else {
		return false;
	}


}



unsigned int remove_checksum(unsigned int n) {
	if (verify_checksum(n) == false) {
		return UINT_MAX;
	}
	else {
		return (n / 10);
	}
}

void remove_checksum(unsigned int array[], std::size_t capacity) {
	for (std::size_t k{ 0 }; k < capacity; ++k) {
		array[k] = remove_checksum(array[k]);
	}





}
