cmake_minimum_required (VERSION 3.8)

project ("sorting")

add_executable(sorting "main.cpp"  "src/sorting/core/bubble_sort.cpp" "include/sorting/bubble_sort.hpp"   "include/sorting/swap.hpp"  "include/sorting/comparator.hpp"   "include/sorting/sorting.hpp" "src/utils/array_utils.cpp" "include/sorting/assert.hpp"  "include/sorting/array_utils.hpp" "include/sorting/insertion_sort.hpp" "src/sorting/core/insertion_sort.cpp" "src/sorting/core/template.cpp"  "include/sorting/selection_sort.hpp" "src/sorting/core/selection_sort.cpp" "src/selection/minimum.cpp" "include/sorting/minimum.hpp" "src/utils/assert.cpp" "include/sorting/maximum.hpp" "src/selection/maximum.cpp" "include/sorting/partition.hpp" "include/sorting/quick_partition.hpp" "src/partition/quick_partition.cpp" "include/sorting/quick_sort.hpp" "src/sorting/core/quick_sort.cpp" "include/sorting/shell_sort.hpp" "src/sorting/core/shell_sort.cpp")
include_directories("./include/sorting/")

find_package(fmt CONFIG REQUIRED)
target_link_libraries(sorting PRIVATE fmt::fmt-header-only)
