#include "simple_executor.hpp"
#include "progress.hpp"
#include "stream_utils.hpp"

void simple_executor::execute(std::ostream& output, const sorting* const sorting, const invariants& invariants) const
{
	const range& range = invariants.range;
	const size_t repeats = invariants.repeats;

	for (size_t n = range.begin; n < range.end + range.step; n += range.step)
	{
		PROGRESS_INIT(sorting->name(), n);

		for (size_t i = 0; i < repeats; i++)
		{
			PROGRESS_STEP(i, repeats);
			const results results = test(sorting, n);
			save_results(output, n, results);
			
		}
		PROGRESS_END();
	}
}
