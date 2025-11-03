#include "string.h"


int main() {

    String s1;
    std::cout << "Default ctor: \"" << s1 << "\"" << '\n';
    
    String s2('A');
    std::cout << "Char ctor: \"" << s2 << "\"" << '\n';

    String s3("Hello");
    std::cout << "C-string ctor: \"" << s3 << "\"" << '\n';

    String s4(s3);
    std::cout << "Copy ctor: \"" << s4 << "\"" << '\n';

    String s5(std::move(s4));
    std::cout << "Move ctor: \"" << s5 << "\"" << '\n';

    s1 = s3;
    std::cout << "operator= (copy): \"" << s1 << "\"" << '\n';

    s1 = 'Z';
    std::cout << "operator= (char): \"" << s1 << "\"" << '\n';

    s1 = "World";
    std::cout << "operator= (const char*): \"" << s1 << "\"" << '\n';

    s1 = std::move(s5);
    std::cout << "operator= (move): \"" << s1 << "\"" << '\n';

    String s6 = s3 + s1;
    std::cout << "operator+: \"" << s6 << "\"" << '\n';

    s6 += s2;
    std::cout << "operator+=: \"" << s6 << "\"" << '\n';

    String s7 = "Start " + s3;
    std::cout << "operator+(const char*, String): \"" << s7 << "\"" << '\n';

    std::cout << "s3 == \"Hello\" ? " << (s3 == String("Hello")) << '\n';
    std::cout << "s3 != s1 ? " << (s3 != s1) << '\n';
    std::cout << "s3 < s1 ? " << (s3 < s1) << '\n';

    std::cout << "s3[1] = " << s3[1] << '\n';
    std::cout << "s3.at(2) = " << s3.at(2) << '\n';
    std::cout << "front: " << s3.front() << ", back: " << s3.back() << '\n';

    std::cout << "size: " << s3.size() << ", capacity: " << s3.capacity() << '\n';
    std::cout << "empty? " << s3.empty() << '\n';

    s3.push_back('!');
    std::cout << "push_back: \"" << s3 << "\"" << '\n';
    s3.pop_back();
    std::cout << "pop_back: \"" << s3 << "\"" << '\n';

    s3.resize(10, '*');
    std::cout << "resize(10,'*'): \"" << s3 << "\"" << '\n';
    s3.resize(3, '*');
    std::cout << "resize(3,'*'): \"" << s3 << "\"" << '\n';

    s3.append(" appended");
    std::cout << "append(const char*): \"" << s3 << "\"" << '\n';
    s3.append(String(" +String"));
    std::cout << "append(String): \"" << s3 << "\"" << '\n';

    std::cout << "find(\"appended\"): " << s3.find(String("appended")) << '\n';
    std::cout << "find_first_of(\"aeiou\"): " << s3.find_first_of(String("aeiou")) << '\n';
    std::cout << "find_last_of(\"d\"): " << s3.find_last_of(String("d")) << '\n';

    String sub = s3.substr(2, 5);
    std::cout << "substr(2,5): \"" << sub << "\"" << '\n';

    s3.reverse();
    std::cout << "reverse: \"" << s3 << "\"" << '\n';

    s3.erase(2);
    std::cout << "erase(pos=2): \"" << s3 << "\"" << '\n';
    s3.append(" again");
    s3.erase(2, 3);
    std::cout << "erase(2,3): \"" << s3 << "\"" << '\n';

    std::cout << "compare with \"Hello\": " << s3.compare(String("Hello")) << '\n';

    s3.insert(2, String("INSERT"));
    std::cout << "insert(2,\"INSERT\"): \"" << s3 << "\"" << '\n';

    s3.replace(2, 6, String("REPL"));
    std::cout << "replace(2,6,\"REPL\"): \"" << s3 << "\"" << '\n';

    std::cout << "c_str(): " << s3.c_str() << '\n';

    std::cout << "count('l'): " << s3.count('l') << '\n';

    s3.swap(s2);
    std::cout << "swap with s2: s3=\"" << s3 << "\", s2=\"" << s2 << "\"" << '\n';

    String input;
    std::cout << "input string ";
    std::cin >> input;
    std::cout << "you input: \"" << input << "\"" << '\n';

    return 0;
}
