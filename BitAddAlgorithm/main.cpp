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
int BitAddRecursion(int a, int b);


int main(int argc, const char * argv[])
{
    int result = BitAdd(1, 7);
    cout << "非递归加法：" << result << endl;;

    int result2 = BitAddRecursion(1, 7);
    cout << "递归加法：" << result2 << endl;

    return 0;
}

// 循环实现
int BitAdd(int a, int b)
{
    int result; // 结果
    int isFlow; // 进位

    result = a ^ b; // 没有进位的结果
    isFlow = a & b; // 判断有没有进位，在每一次执行异或加法操作前都要进行判断
    while (isFlow)
    {
        int temp_a = result;
        int temp_b = isFlow<<1; // 需要加上的进位值

        result = temp_a ^ temp_b;
        isFlow = temp_a & temp_b;
    }

    return result;
}

// 递归实现异或加法
int BitAddRecursion(int a, int b)
{
    if (!(a & b))
    {
        // 没有进位，直接异或相加
        return a ^ b;
    }

    // 有进位
    return BitAddRecursion(a ^ b, (a & b)<<1);
}
