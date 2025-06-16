message(STATUS "Add CPM.cmake")
# download CPM.cmake
file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.40.5/CPM.cmake
        ${CMAKE_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=c46b876ae3b9f994b4f05a4c15553e0485636862064f1fcc9d8b4f832086bc5d
)
include(${CMAKE_BINARY_DIR}/cmake/CPM.cmake)

message(STATUS "Fetching external libraries started")

message(STATUS "Fetching catch2")
CPMAddPackage(
		NAME catch2
		GITHUB_REPOSITORY catchorg/Catch2
		GIT_TAG v3.8.1
		OPTIONS
		CATCH_INSTALL_DOCS OFF
		CATCH_INSTALL_HELPERS OFF
		CATCH_BUILD_TESTING OFF
)

message(STATUS "Fetching approvaltests")
CPMAddPackage(
		NAME approvaltests
		GITHUB_REPOSITORY approvals/ApprovalTests.cpp
		GIT_TAG v.10.13.0
)


message(STATUS "Fetching rapidcheck")
CPMAddPackage(
		NAME rapidcheck
		GITHUB_REPOSITORY emil-e/rapidcheck
		GIT_TAG ff6af6fc683159deb51c543b065eba14dfcf329b
)
