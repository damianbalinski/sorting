#include "array_utils.hpp"
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

string arr_to_string(int arr[], int n)
{
	ostringstream os;
	for (size_t i = 0; i < n; i++) {
		os << arr[i] << " ";
	}
	return os.str();
}
