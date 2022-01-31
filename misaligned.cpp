#include <iostream>
#include <sstream>
#include <assert.h>
#include <string>
#include <map>
#include <utility>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

typedef ::std::pair< const char*, const char*> T_ColorCombinationPair;
typedef ::std::map< int , T_ColorCombinationPair> T_ColorPairMap;
T_ColorCombinationPair colorCombinationPair;
T_ColorPairMap colorPairMap;

int calcPair(int majorIdx, int minorIdx)
{
   return majorIdx * 5 + minorIdx;
}
void fillTheColorMap(int majorIdx, int minorIdx)
{
    colorPairMap.insert({calcPair(majorIdx, minorIdx), ::std::make_pair(majorColor[majorIdx],minorColor[minorIdx])});
}
void printOnConsole(int majorIdx, int minorIdx)
{
    char ch = '|';
    std::cout << calcPair(majorIdx, minorIdx) << ch << majorColor[majorIdx] << ch << minorColor[minorIdx]  << "\n";
}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
           fillTheColorMap(i,j );
           printOnConsole(i, j);
        }
    }
    return i * j;
}

T_ColorPairMap prepareExpectedMap()
{
    T_ColorPairMap expectedColorPairMap;
    expectedColorPairMap.insert({0,::std::make_pair("White","Blue")});
    expectedColorPairMap.insert({1,::std::make_pair("White","Orange")});
    expectedColorPairMap.insert({2,::std::make_pair("White","Green")});
    expectedColorPairMap.insert({3,::std::make_pair("White","Brown")});
    expectedColorPairMap.insert({4,::std::make_pair("White","Slate")});
    expectedColorPairMap.insert({5,::std::make_pair("Red","Blue")});
    expectedColorPairMap.insert({6,::std::make_pair("Red","Orange")});
    expectedColorPairMap.insert({7,::std::make_pair("Red","Green")});
    expectedColorPairMap.insert({8,::std::make_pair("Red","Brown")});
    expectedColorPairMap.insert({9,::std::make_pair("Red","Slate")});
    expectedColorPairMap.insert({10,::std::make_pair("Black","Blue")});
    expectedColorPairMap.insert({11,::std::make_pair("Black","Orange")});
    expectedColorPairMap.insert({12,::std::make_pair("Black","Green")});
    expectedColorPairMap.insert({13,::std::make_pair("Black","Brown")});
    expectedColorPairMap.insert({14,::std::make_pair("Black","Slate")});
    expectedColorPairMap.insert({15,::std::make_pair("Yellow","Blue")});
    expectedColorPairMap.insert({16,::std::make_pair("Yellow","Orange")});
    expectedColorPairMap.insert({17,::std::make_pair("Yellow","Green")});
    expectedColorPairMap.insert({18,::std::make_pair("Yellow","Brown")});
    expectedColorPairMap.insert({19,::std::make_pair("Yellow","Slate")});
    expectedColorPairMap.insert({20,::std::make_pair("Violet","Blue")});
    expectedColorPairMap.insert({21,::std::make_pair("Violet","Orange")});
    expectedColorPairMap.insert({22,::std::make_pair("Violet","Green")});
    expectedColorPairMap.insert({23,::std::make_pair("Violet","Brown")});
    expectedColorPairMap.insert({24,::std::make_pair("Violet","Slate")});
    return expectedColorPairMap;
}

void testPrintColorMap()
{
    T_ColorPairMap expectedColorMap = prepareExpectedMap();
    assert(colorPairMap == expectedColorMap);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testPrintColorMap();
    // test 
    //  std::cout << getCombination(0,2)<<std::endl;
    //  assert(getCombination(0,2) == "2|White|Green");
    std::cout << "All is well (maybe!)\n";
    return 0;
}
