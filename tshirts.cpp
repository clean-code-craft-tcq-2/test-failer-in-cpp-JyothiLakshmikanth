#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms <= 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms <= 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testForCorrectSizeName(int size, char expectedSizeName)
{
    assert(size(size) == expectedSizeName);
}
int main() {

    testForCorrectSize(37, 'S');
    testForCorrectSize(40, 'M');
    testForCorrectSize(43, 'L');
    testForCorrectSize(38, 'S');
    testForCorrectSize(42, 'M');
    testForCorrectSize(-1, '\0');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
