#include "density_executor.hpp"
#include "progress.hpp"
#include "stream_utils.hpp"

void density_executor::execute(std::ostream& output, const generator* generator, const sorting* sorting, const invariants& invariants) const
{
	const size_t n = invariants.range.end;
	const size_t repeats = invariants.repeats;

	PROGRESS_INIT(sorting->name(), n);
	for (size_t i = 0; i < repeats; i++)
	{
		PROGRESS_STEP(i, repeats);
		const results results = test(generator, sorting, n);
		save_results(output, n, results);
	}
	PROGRESS_END();
}
