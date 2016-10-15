//
//  main.cpp
//  BitAddAlgorithm
//
//  Created by chenyufeng on 10/15/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 *  使用位运算实现加法
 */

int BitAdd(int a, int b);


int main(int argc, const char * argv[])
{
    int result = BitAdd(4, 4);
    cout << result;

    return 0;
}

int BitAdd(int a, int b)
{
    int result; // 结果

    result = a ^ b; // 没有进位
    int isFlow = a & b; // 判断有没有进位
    while (isFlow)
    {
        int temp_a = result;
        int temp_b = isFlow;

        result = temp_a ^ (temp_b << 1);
        isFlow = temp_a & temp_b;
    }

    return result;
}





