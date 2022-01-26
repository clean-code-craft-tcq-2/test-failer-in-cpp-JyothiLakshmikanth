// #include <iostream>
// #include <assert.h>

// float MAX_Temp = 200;
// int alertFailureCount = 0;
// int alertRequest = 0;

// int networkAlertStub(float celcius) {
//       std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
//     if(celcius>MAX_Temp)
//     {
//         return 500;
//     }
//     // Return 200 for ok
//     // Return 500 for not-ok
//     // stub always succeeds and returns 200
//     return 200;
// }

// void alertInCelcius(float farenheit) {
//     float celcius = (farenheit - 32) * 5 / 9;
//     int returnCode = networkAlertStub(celcius);
//     if (returnCode != 200) {
//         // non-ok response is not an error! Issues happen in life!
//         // let us keep a count of failures to report
//         // However, this code doesn't count failures!
//         // Add a test below to catch this bug. Alter the stub above, if needed.
//         alertFailureCount += 0;
//     }
//     alertRequest++;
// }

// int main() {
//     alertInCelcius(400.5);
//     assert(alertFailureCount == alertRequest);
//     alertInCelcius(303.6);
//     assert(alertFailureCount == alertRequest);
//     std::cout << alertFailureCount << " alerts failed.\n";
//     std::cout << "All is well (maybe!)\n";
//     return 0;
// }
// Online C++ compiler to run C++ program online
#include <iostream>
#include <assert.h>

float MAX_Temp = 200;
int alertFailureCount = 0;
int count = 0;

int checkForThreshold(float celcius)
{
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
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
        if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}
void alertInCelcius(float farenheit, int(*networkAlertStub)(int)) {
    float celcius = convertToCelcius(farenheit);
    int returnCode = checkForThreshold(celcius);
    countFailureCases(returnCode);
}
int networkAlertStub(int returnCode) {
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if (returnCode == 500)
    {
        count++;
    }
    return count;
}
int main() {
    int (*funcptr)(int);
    funcptr = networkAlertStub;
    int returnValue = 500;
    int *ptr;
    ptr = &returnValue;
    alertInCelcius(400.5, funcptr(ptr));
    alertInCelcius(303.6, funcptr(ptr));
    assert(count == alertFailureCount);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}

