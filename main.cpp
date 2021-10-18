#include <iostream>
#include <string>
#include "timer.hpp"
#include "assert.hpp"
#include "array_utils.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "maximum.hpp"
#include "median_of_three.hpp"
#include "quick_partition.hpp"
#include "quick_sort.hpp"
#include "merge_sort.hpp"
#include "shell_sort.hpp"
#include "dual_pivot_quick_sort.hpp"
#include "counting_sort.hpp"
#include "radix_sort.hpp"
#include "bucket_sort.hpp"
#include "comb_sort.hpp"
#include "intro_sort.hpp"
#include "quick_merge_sort.hpp"
#include "simple_indexer.hpp"
#include "radix_indexer.hpp"
#include "comb_gapper.hpp"
#include "swapper.hpp"
#include "binary_max_heap.hpp"
#include "heap_sort.hpp"
#include "numeric_utils.hpp"
#include "debugger.hpp"
#include "colors.hpp"
#include "operation.hpp"
#include "swapper.hpp"
#include "assigner.hpp"
#include "testing_unit.hpp"
#include "testing_engine.hpp"
#include "range.hpp"
#include "progress.hpp"
#include <fstream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	std::ofstream file;
	file.open("test_001.csv");
	testing_engine engine(file);

	engine.add(bubble_sort{}, 100, 1000);
	//engine.add(bucket_sort{}, 100, 1000);
	engine.add(comb_sort{}, 100, 1000);
	//engine.add(counting_sort{}, 100, 1000);
	engine.add(dual_pivot_quick_sort{}, 100, 1000);
	engine.add(heap_sort{}, 100, 1000);
	engine.add(insertion_sort{}, 100, 1000);
	engine.add(merge_sort{}, 100, 1000);
	engine.add(quick_sort{}, 100, 1000);
	engine.add(radix_sort{}, 100, 1000);
	engine.add(selection_sort{}, 100, 1000);
	engine.add(shell_sort{}, 100, 1000);
	engine.add(intro_sort{}, 100, 1000);
	engine.add(quick_merge_sort{}, 100, 1000);
	engine.add(quick_merge_sort{}, 100, range{10000, 100000, 5000});

	engine.start();
	return 0;
}
