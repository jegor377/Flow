#include <iostream>
#include "lest_basic.hpp"
#include "test_cases.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	lest::run(test_cases::tests);
	return 0;
}