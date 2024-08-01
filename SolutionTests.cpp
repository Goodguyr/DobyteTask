#include <gtest/gtest.h>

#include <random>
#include <vector>

#include "Solution.h"

class SolutionTests : public ::testing::Test
{
protected:
	uint32_t factorial(const uint32_t num) { return solution.factorial(num); }
	int32_t countUniquePermutationCount(const std::vector<uint32_t>& nums) { return solution.countUniquePermutationCount(nums); }

	std::vector<uint32_t> generateRandomVector(size_t size)
	{
		std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
		std::uniform_int_distribution<uint32_t> dist(0, 12);

		std::vector<uint32_t> randomVector(size);
		for (size_t i = 0; i < size; ++i)
		{
			randomVector[i] = dist(rng);
		}
		std::sort(randomVector.begin(), randomVector.end());
		return randomVector;
	}

private:
	Solution solution;
};

TEST_F(SolutionTests, FactorialTest)
{
	EXPECT_EQ(factorial(0), 1);
	EXPECT_EQ(factorial(1), 1);
	EXPECT_EQ(factorial(5), 120);
	EXPECT_EQ(factorial(10), 3628800);
}

TEST_F(SolutionTests, CountUniquePermutationCountTest)
{
	std::vector<uint32_t> nums1 = generateRandomVector(6);
	uint32_t permutations = 1;
	while (std::next_permutation(nums1.begin(), nums1.end()))
	{
		++permutations;
	}
	EXPECT_EQ(countUniquePermutationCount(nums1), permutations);

	std::vector<uint32_t> nums2 = {1, 1, 1, 1, 1, 1};
	EXPECT_EQ(countUniquePermutationCount(nums2), 1);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
