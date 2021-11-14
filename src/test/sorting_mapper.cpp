#include "sorting_mapper.hpp"
#include "fail.hpp"
#include "bubble_sort.hpp"
#include "bucket_sort.hpp"
#include "comb_sort.hpp"
#include "counting_sort.hpp"
#include "dual_pivot_quick_sort.hpp"
#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "radix_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"
#include "intro_sort.hpp"
#include "quick_merge_sort.hpp"
#include "lemuto_partition.hpp"
#include "dual_pivot_quick_partition.hpp"
#include "simple_pivot_selector.hpp"
#include "median_of_three_pivot_selector.hpp"
#include "simple_dual_pivot_selector.hpp"
#include "middle_pivot_selector.hpp"

const sorting* sorting_mapper::map(const std::string& str)
{
	return allocate(str);
}

const sorting* sorting_mapper::allocate(const std::string& str)
{
	// UNRELIABLE
	if (str == "bucket_sort")		return new bucket_sort{};
	if (str == "counting_sort")		return new counting_sort{};
	if (str == "radix_sort")		return new radix_sort{};

	// SLOW
	if (str == "bubble_sort")		return new bubble_sort{};
	if (str == "comb_sort")			return new comb_sort{};
	if (str == "insertion_sort")	return new insertion_sort{};
	if (str == "selection_sort")	return new selection_sort{};

	// FAST
	if (str == "dual_pivot_quick_sort") return new dual_pivot_quick_sort{new dual_pivot_quick_partition{new simple_dual_pivot_selector{}}};
	if (str == "heap_sort")			return new heap_sort{};
	if (str == "merge_sort")		return new merge_sort{};
	if (str == "quick_sort")		return new quick_sort{new lemuto_partition{new simple_pivot_selector{}}};
	if (str == "shell_sort")		return new shell_sort{};
	if (str == "intro_sort")		return new intro_sort{new lemuto_partition{new median_of_three_pivot_selector{}}};
	if (str == "quick_merge_sort")	return new quick_merge_sort{new lemuto_partition{new simple_pivot_selector{}}};

	// MIXED
	if (str == "quick_sort_middle_pivot_selector") return new quick_sort{new lemuto_partition{new middle_pivot_selector{}}};
	if (str == "quick_sort_median_of_three_pivot_selector") return new quick_sort{new lemuto_partition{new median_of_three_pivot_selector{}}};

	fail("Unrecognized sorting algorithm");
}
