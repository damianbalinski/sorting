#include "simple_executor.hpp"
#include "progress.hpp"
#include "stream_utils.hpp"

void simple_executor::execute(std::ostream& output) const
{
	for (size_t n = rng.begin; n < rng.end + rng.step; n += rng.step)
	{
		PROGRESS_INIT(sort.name(), n);

		for (size_t i = 0; i < rep; i++)
		{
			PROGRESS_STEP(i, rep);
			const results results = test(sort, n);
			save_results(output, n, results);
			
		}
		PROGRESS_END();
	}
}
