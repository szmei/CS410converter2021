//#include <stdio.h>
#include <iostream>
#include <vector>
//using namespace std;

class SingletonConverter {
    public:
        static SingletonConverter* getInstance() {
            static SingletonConverter* instance;
            return instance;
        };
        ~SingletonConverter( );
        float tempFtoC(float temp) {
            return (temp-32)/1.8;
        };
    private:
        SingletonConverter();
        // static SingletonConverter* instance;
};

int main() {
    std::vector<float> allTemps;

    while (1) {
        std::string temp;
        std::cout << "Please enter a temperature or x to stop entering temperature.\n";
        std::cin >> temp;

        if (temp == "x") {
            break;
        }

        std::cout << "Stored " << temp << "!\n";
        allTemps.push_back(std::stof(temp));
    }

    std::cout << allTemps.size() << " temperatures stored!\n";

    float averageTemp = 0;
    for (int i = 0; i < allTemps.size(); i++) {
        averageTemp += allTemps[i];
    }

    averageTemp /= allTemps.size();

    std::cout << "The average temperature is: " << averageTemp << "\n";
    std::cout << "Converted to Celsius, this temperature is " << SingletonConverter::getInstance() -> tempFtoC(averageTemp) << "!\n";
   
    //float temp;
    // cout << "Please enter a temperture in Fahrenheit. ";
    // cin >> temp;
    
    // SingletonConverter *c = SingletonConverter::getInstance();
    // float convertedTemp = c->tempFtoC(temp);
    
    // cout << "Converted to Celsius, the temperture is " << convertedTemp << ".";

};