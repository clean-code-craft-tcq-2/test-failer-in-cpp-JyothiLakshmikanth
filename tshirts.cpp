#include <iostream>
#include <assert.h>

char getTheSizeName(int cms) {
    char sizeName = '\0';
    if(cms <= 38 && cms>0) {
        sizeName = 'S';
    } else if(cms > 38 && cms <= 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testForCorrectSizeName(int s_cms, char expectedSizeName)
{
    assert(getTheSizeName(s_cms) == expectedSizeName);
}
int main() {

    testForCorrectSizeName(37, 'S');
    testForCorrectSizeName(40, 'M');
    testForCorrectSizeName(43, 'L');
    testForCorrectSizeName(38, 'S');
    testForCorrectSizeName(42, 'M');
    testForCorrectSizeName(-1, '\0');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
