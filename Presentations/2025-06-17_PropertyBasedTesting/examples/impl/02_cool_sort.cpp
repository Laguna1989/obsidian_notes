#include <catch2/catch_all.hpp>
#include <rapidcheck.h>
#include <rapidcheck/catch.h>
#include <algorithm>

template<typename T>
void cool_sort(std::vector<T>& vec)
{
	std::ranges::sort(vec);
}

TEST_CASE("CoolSortUnitTest")
{
	std::vector data{2, 7, 1, 5, 1, 8};

	REQUIRE(!std::ranges::is_sorted(data));

	auto const input_copy = data;
	cool_sort(data);

	SECTION("is_sorted")
	{
		REQUIRE(std::ranges::is_sorted(data));
	}

	SECTION("is_permutation")
	{
		REQUIRE(std::ranges::is_permutation(data, input_copy));
	}
}

//
//
//
//
//
//
//
//
//
//

TEST_CASE("CoolSortPropertyTest")
{
	rc::prop("???", [](std::vector<int> const& data) {
	});
}
