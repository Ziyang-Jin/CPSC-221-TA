#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <vector>

class Unit {
public:
	Unit();
	virtual ~Unit();

	void assertEquals(std::string msg, int expected, int actual);
	void assert_LT(std::string msg, int lhs, int rhs);
	void assert_LE(std::string msg, int lhs, int rhs);
	void assertvectorEquals(std::string msg, std::vector<int>& expected, std::vector<int>& actual);
	void assertNonNull(std::string msg, void* actual);
	void assertNull(std::string msg, void* actual);
	void printResults();

private:
	std::vector<std::string> failures;

	std::vector<std::string> successes;

	std::string toStr(std::vector<int>& v);
};

#endif /* UNIT_H_ */
