#include "string.h"

int main()
{
	String s1 = "hello";
	String s2 = "hworld";
	String s3 = s1 + " " + s2;
	std::cout << s3 << '\n';
	if (s1 < s2)
	{
		std::cout << s1 << " lower than " << s2 << '\n';
	}
	s2[0] = 'p';
	std::cout << "change str: " << s2 << '\n';
	s2.reverse();
	std::cout << s2 << '\n';
	std::cout << s3.find(s2) << '\n';
	s1.replace(4, 2, s2);
	std::cout << s1 << '\n';
	s1.insert(3, "CLOSE");
	std::cout << s1 << '\n';
	std::cout << s2.count('d') << '\n';
	return 0;
}
