#include "average_executor.hpp"
#include "progress.hpp"
#include "stream_utils.hpp"
#include "averager.hpp"

void average_executor::execute(std::ostream& output, const sorting& sorting, const invariants& invariants) const
{
	const range& range = invariants.range;
	const size_t repeats = invariants.repeats;

	for (size_t n = range.begin; n < range.end + range.step; n += range.step)
	{
		PROGRESS_INIT(sorting.name(), n);
		averager averager{ repeats };

		for (size_t i = 0; i < repeats; i++)
		{
			PROGRESS_STEP(i, repeats);
			const results results = test(sorting, n);
			averager.add(results);
		}
		PROGRESS_END();
		save_results(output, n, averager.average_results());
	}
}
