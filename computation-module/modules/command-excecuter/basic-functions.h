//
// Created by Yaten on 05-01-2022.
//

#ifndef ARCOS_BASIC_FUNCTIONS_H
#define ARCOS_BASIC_FUNCTIONS_H

namespace basic {
    // all basic functions: (here so that they could also be called manually if needed)
    float ADD(float num1, float num2) {
        return num1 + num2;
    }

    float SUB(float num1, float num2) {
        return num1 - num2;
    }

    float DIV(float num1, float num2) {
        return num1 / num2;
    }

    float MUL(float num1, float num2) {
        return num1 * num2;
    }

    float POW(float base, float exponent) {
        float output = 0.0;
        for (float i = 0; i < exponent; ++i) {
            output *= base;
        }
        return output;
    }

    float NRT(float num1, float root) {
        float power = 1.0 / root;
        float output = POW(num1, power);
        return output;
    }

    String SAP(String str1, String str2) {
        return str1 + str2;
    }

    int SIA(String *str) {
        int output_arr[];
        int counter = 0;

        for (char i : *str) {
            byte bytes = bitRead(myChar,i);
            output_arr[counter] = int(bytes);
            ++counter;
        }

        return output_arr;
    }
}

#endif //ARCOS_BASIC_FUNCTIONS_H
