cmake_minimum_required (VERSION 3.8)

project ("sorting")

add_executable(sorting "main.cpp"  "src/sorting/core/bubble_sort.cpp" "include/sorting/bubble_sort.hpp"   "include/sorting/swap.hpp"  "include/sorting/comparator.hpp"   "include/sorting/sorting.hpp" "src/utils/array_utils.cpp" "include/sorting/assert.hpp"  "include/sorting/array_utils.hpp" "include/sorting/insertion_sort.hpp" "src/sorting/core/insertion_sort.cpp" "src/sorting/core/template.cpp" "include/sorting/types.hpp")
include_directories("./include/sorting/")
