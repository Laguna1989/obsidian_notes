file(GLOB_RECURSE TESTFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)
add_executable(pbt_examples ${TESTFILES}
        02_cool_sort.cpp
        03_shrinking.cpp)

FETCHCONTENT_GETPROPERTIES(rapidcheck)

target_include_directories(pbt_examples PUBLIC ${rapidcheck_SOURCE_DIR}/extras/catch/include)

target_link_libraries(pbt_examples PUBLIC
        rapidcheck
        ApprovalTests::ApprovalTests
        Catch2::Catch2WithMain
)