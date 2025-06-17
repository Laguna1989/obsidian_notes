#include <catch2/catch_all.hpp>
#include <rapidcheck.h>
#include <rapidcheck/catch.h>

TEST_CASE("Advanced features")
{
	// rc::prop("RC_TAG", [](int a) {
	// 	int const result = a + 5;
	//
	// 	RC_TAG(a);
	// 	RC_CLASSIFY(a > 0, "positive values");
	//
	// 	RC_ASSERT(result > a);
	// });

	// rc::prop("RC_CLASSIFY", [](int a) {
	// 	int const result = a + 5;
	// 	RC_CLASSIFY(a > 0, "positive values");
	//
	// 	RC_ASSERT(result > a);
	// });

	// rc::prop("RC_PRE", [](int a) {
	// 	RC_PRE(a > -5);
	// 	int const result = a + 5;
	//
	// 	RC_ASSERT(result >= 0);
	// });
}
