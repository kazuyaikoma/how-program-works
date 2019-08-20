//
//  main.c
//  cnote
//
//  Created by NixieSquid on 2019/08/20.
//  Copyright © 2019 NixieSquid. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void main() {
    // float: 4バイトの単精度浮動小数点実数 (有効桁数は7ケタ)
    // double: 8バイトの倍精度浮動小数点実数 (有効桁数は16ケタ)
    float data;
    // short: 2バイトの符号付整数
    // long: 4バイトの符号付整数
    unsigned long buff;
    int i;
    char s[34+1];
    
    data = (float)0.75;
    
    memcpy(&buff, &data, 4);
    
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
