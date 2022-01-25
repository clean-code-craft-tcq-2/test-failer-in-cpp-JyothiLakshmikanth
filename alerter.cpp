#include <iostream>
#include <assert.h>

float MAX_Temp = 200;
int alertFailureCount = 0;
int alertRequest = 0;

int networkAlertStub(float celcius) {
      std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if(celcius>MAX_Temp)
    {
        return 500;
    }
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
    alertRequest++;
}

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount == alertRequest);
    alertInCelcius(303.6);
    assert(alertFailureCount == alertRequest);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
