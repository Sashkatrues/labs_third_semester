#include "string.h"

int main()
{
    try
    {
        String s1;
        String s2('A');
        String s3("Hello");
        String s4(s3);
        String s5(std::move(s4));

        s1 = s3;
        s1 = "World";
        s1 = 'Z';
        s1 = std::move(s5);

        String s6 = s2 + s3;
        String s7 = s6 += s1;
        String s8 = "Start " + s3;

        bool eq = (s2 == s3);
        bool gt = (s2 > s3);
        bool lt = (s2 < s3);
        bool le = (s2 <= s3);
        bool ge = (s2 >= s3);
        bool ne = (s2 != s3);

        char ch = s3[1];
        s3[1] = 'a';

        std::cout << "s3: " << s3 << '\n';

        s1.copy(s3);
        std::cout << "Front: " << s3.front() << ", Back: " << s3.back() << '\n';
        std::cout << "Size: " << s3.size() << '\n';
        s3.reserve(50);
        std::cout << "Capacity: " << s3.capacity() << '\n';
        std::cout << "Empty: " << s1.empty() << '\n';
        s3.push_back('!');
        s3.pop_back();
        //s3.swap(s2);
        s3.resize(10, '*');
        s3.append(" appended");
        size_t pos = s3.find(String("lo"));
        size_t first = s3.find_first_of(String("aeiou"));
        size_t last = s3.find_last_of(String("aeiou"));
        String sub = s3.substr(1, 4);
        s3.reverse();
        s3.erase(2);
        s3.erase(1, 3);
        int cmp = s3.compare(s2);
        s3.insert(1, String("INS"));
        s3.replace(0, 2, String("RE"));
        const char* cstr = s3.c_str();
        size_t count = s3.count('l');
        char& ref = s3.at(0);

        std::cout << "Final s3: " << s3 << '\n';
        std::cout << "Substring: " << sub << '\n';
        std::cout << "Find: " << pos << ", First of: " << first << ", Last of: " << last << '\n';
        std::cout << "Compare result: " << cmp << '\n';
        std::cout << "C-string: " << cstr << '\n';
        std::cout << "Count of 'l': " << count << '\n';
        std::cout << "First char (via at): " << ref << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
