#include "cost_factor_executor.hpp"
#include "progress.hpp"
#include "stream_utils.hpp"
#include "averager.hpp"

void cost_factor_executor::execute(std::ostream& output, const generator* const generator, const sorting* const sorting, const invariants& invariants) const
{
	const size_t n = invariants.range.end;
	const size_t repeats = invariants.repeats;

	for (size_t factor10 = 1; factor10 <= 100; factor10 += 1)
	{
		PROGRESS_INIT(sorting->name(), n);
		const double factor = factor10 / 10.0;
		averager averager{ repeats, factor };

		for (size_t i = 0; i < repeats; i++)
		{
			PROGRESS_STEP(i, repeats);
			const results results = test(generator, sorting, n, factor);
			averager.add(results);
		}
		PROGRESS_END();
		save_results(output, n, averager.average_results());
	}
}
