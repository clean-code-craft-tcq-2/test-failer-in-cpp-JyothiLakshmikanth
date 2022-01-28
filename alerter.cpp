#include <iostream>
#include <assert.h>
#include <cmath>
 
float MAX_Temp = 200;
int alertFailureCount = 0;
float acceptedDiff = 0.001;

int checkForThreshold(float celcius)
{
    if(celcius>MAX_Temp)
    {
        return 500;
    }
    return 200;
}
float convertToCelcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}
void countFailureCases(int returnCode)
{
   if (returnCode != 200) 
   {
        alertFailureCount += 1;
   }
}
void alertInCelcius(float farenheit, int(*funAlerter)(float)) {
    float celcius = convertToCelcius(farenheit);
    int returnCode = funAlerter(celcius);
    countFailureCases(returnCode);
}
int networkAlertStub(float celcius) {
    int value = checkForThreshold(celcius);
    ::std::cout<<"value "<<value<<::std::endl;
    return value;
}
void testConversion(float f, float expectedValue)
{
    float receivedValue = convertToCelcius(f);
    std::cout <<receivedValue<<::std::endl;
    std::cout <<expectedValue<<::std::endl;
    std::cout <<(receivedValue-expectedValue)<<::std::endl;
    assert((receivedValue-expectedValue) < acceptedDiff);
}
void testTheThreshold(float c, int expectedoutput)
{
    assert(checkForThreshold(c) == expectedoutput);
}

void testAlerter(float testValue, int expectedCount)
{
    alertInCelcius(testValue, &networkAlertStub);
    std::cout << "alertFailureCount "<< alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount == expectedCount);
}
int main() {
    testAlerter(400.5, 1);
    testAlerter(303.6, 1);
    testAlerter(503.6, 2);
    testConversion(400.5, 204.722);
    testConversion(303.6, 150.899);
    testTheThreshold(204.722, 500);
    testTheThreshold(150.899, 200);
    std::cout << "All is well (maybe!)\n";

    return 0;
}
