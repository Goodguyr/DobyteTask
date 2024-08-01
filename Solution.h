#pragma once

#include <unordered_map>
#include <vector>

constexpr size_t DIGIT_COUNT = 12;
constexpr size_t NUM_SIZE = 6;
constexpr size_t MAX_SUM = DIGIT_COUNT * NUM_SIZE;

class Solution
{
public:
	Solution();
	~Solution() = default;
	uint64_t getAnswer();

private:
	friend class SolutionTests;

	inline uint32_t factorial(const uint32_t num) { return std::tgamma(num + 1); }
	uint32_t countUniquePermutationCount(const std::vector<uint32_t>& nums);
	void generateCombinations(std::vector<uint32_t>& set, uint32_t position, uint32_t start);

	std::unordered_map<uint32_t, uint64_t> permCount;
};
