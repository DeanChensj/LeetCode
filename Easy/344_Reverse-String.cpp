#include "../Header.h"

using namespace std;
string reverseString(string s) {
    int len = s.length(), i;
    char *result = new char[len + 1];
    for (i = 0; i < len; i++) result[i] = s[len-i-1];
    result[i] = '\0';
    string ns(result);
    return ns;
}
int main(int argc, char const *argv[])
{
	return 0;
}