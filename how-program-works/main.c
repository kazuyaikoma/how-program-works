//
//  main.c
//  cnote
//
//  Created by NixieSquid on 2019/08/20.
//  Copyright © 2019 NixieSquid. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void researchDecimalNumber(float);
void calcByReplacing(int);

int main() {
//    researchDecimalNumber(0.75);
    calcByReplacing(10);
    return 0;
}

// Find out how any decimal number passed as an argument is represented as a single precision floating point number
void researchDecimalNumber(float f) {
    // float: 4バイトの単精度浮動小数点実数 (有効桁数は7ケタ)
    // double: 8バイトの倍精度浮動小数点実数 (有効桁数は16ケタ)
    float data = f;
    // short: 2バイトの符号付整数
    // long: 4バイトの符号付整数
    unsigned long buff;
    
    memcpy(&buff, &data, 4);
    
    int i;
    char s[34+1];
    
    // 1bitずつ走査
    for (i=34-1; i>=0; i--) {
        if (i == 1 || i == 10) {
            s[i] = '-';
        } else {
            // 1bitずつ走査し、'0'または'1'という数字としてsに格納
            if (buff % 2 == 1) {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
            buff /= 2;
        }
    }
    s[34] = '\0';
    
    printf("%s\n", s);
}

// Calculate by replacing decimals with integers
void calcByReplacing(int count) {
    if (count <= 1) { return; }
    
    float sum = 0;
    int i;
    
    for (i=1;i<=count;i++) {
        sum += 1;
    }
    sum /= 10;
    
    printf("%f\n", sum);
}
