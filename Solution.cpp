#include "Solution.h"

#include <numeric>

Solution::Solution()
{
	permCount.reserve(MAX_SUM + 1);
	for (size_t i = 0; i <= MAX_SUM; ++i)
	{
		permCount[i] = 0;
	}
}

uint64_t Solution::getAnswer()
{
	uint64_t ans{0};
	std::vector<uint32_t> temp(NUM_SIZE, 0);
	generateCombinations(temp, 0, 0);

	for (const auto& pair : permCount)
	{
		ans += pair.second * pair.second;
	}
	return 13 * ans;
}

uint32_t Solution::countUniquePermutationCount(const std::vector<uint32_t>& nums)
{
	const uint32_t numerator{factorial(NUM_SIZE)};
	uint32_t denumerator{1};
	std::unordered_map<uint32_t, uint32_t> digitCount;

	for (const uint32_t num : nums)
	{
		digitCount[num]++;
	}

	for (const auto& pair : digitCount)
	{
		denumerator *= factorial(pair.second);
	}
	return numerator / denumerator;
}

void Solution::generateCombinations(std::vector<uint32_t>& set, uint32_t position, uint32_t start)
{
	if (position == set.size())
	{
		const auto sum = std::accumulate(set.begin(), set.end(), 0);
		permCount[sum] += countUniquePermutationCount(set);
		return;
	}

	for (size_t i = start; i <= DIGIT_COUNT; ++i)
	{
		set[position] = i;
		generateCombinations(set, position + 1, i);
	}
}