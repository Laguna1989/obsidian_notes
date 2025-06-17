#include <catch2/catch_all.hpp>
#include <rapidcheck.h>
#include <rapidcheck/catch.h>

std::string concatenate(std::string const& a, std::string const& b)
{
	return a + b;
}

TEST_CASE("string concatenation")
{
	SECTION("result contains a")
	{
		rc::check([](std::string const& a, std::string const& b) {
			auto const concatenated_result = concatenate(a, b);
			RC_ASSERT(concatenated_result.contains(a));
		});
	}

	// rc::prop creates a dedicated catch2 section
	rc::prop("result contains b", [](std::string const& a, std::string const& b) {
		auto const concatenated_result = concatenate(a, b);
		RC_ASSERT(concatenated_result.contains(b));
	});

	// rc::prop("result contains XYZ", [](std::string const& a, std::string const& b) {
	// 	auto const concatenated_result = concatenate(a, b);
	// 	RC_ASSERT(concatenated_result.contains("XYZ"));
	// });
}
