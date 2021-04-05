/*
 * File: Sample.cpp
 * Project: TVJ_String
 * --------------------------
 *
 * @author: Teddy van Jerry
 * @licence: The MIT Licence
 * @compiler: at least C++/11 (tested on MSVC and MinGW)
 *
 * @version 1.0 2021/04/05
 * - initial version
 *
 */

#include <iostream>
#include "TVJ_String.h"

int main()
{
	// one of the constructors
	tvj::string str1(5, 'A');
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// access via subscript
	str1[2] = 'B';
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// append string at the end
	str1.append("ABCADD");
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// append char at the end
	str1.append('E');
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// insert string at a certain location
	str1.insert_after(2, "CC");
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// copy
	tvj::string str2 = str1;
	// range for inmplicitly calls iterator begin() and end()
	for (auto& c : str2) c = tolower(c);
	str1.append(str2);
	// clear str2 and str1 still remains the same, demonstrating successful copy
	str2.clear();
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// remove at the certain location
	str1.remove_at(str1.cend() - str1.cbegin() - 2);
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// access via iterator
	*(str1.end() - 5) = 'T';
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// remove in range [15, str1.size() - 2)
	str1.remove_at(15, str1.size() - 2);
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	// check if the string is empty
	std::cout << "str1 is " << (str1.empty() ? "" : "not ") << "empty" << std::endl;
	// contains, count, find substring
	std::cout << "str1 " << (str1.contains("ABC") ? "" : "does not ") << "contains \"ABC\", "
		<< "the count is " << str1.count("ABC") << ", "
		<< "and the first appearance is at index " << str1.find("ABC") << std::endl;
	// compare
	std::cout << "str1 is " << (str1 < "Hello" ? "" : "no ") << "less than \"Hello\"" << std::endl;
	// clear
	str1.clear();
	std::cout << str1 << " (" << str1.size() << ")" << std::endl;
	return 0;
}

// ALL RIGHTS RESERVED (C) 2021 Teddy van Jerry