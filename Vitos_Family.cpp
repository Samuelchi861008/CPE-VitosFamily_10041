/* **************************************************************************

    * File Name : Vitos_Family.cpp

    * Creation Date : 2018-08-21 00:05:12

    * Last Modified : 2018-08-28 14:19:34

    * Created By : Samuel Chi <Yu-Ning Chi>

************************************************************************** */

#include <iostream>
#include <algorithm> //sort()
#include <math.h> //fabs()
using namespace std;

int main()
{
    int numOfCase; //輸入的組數
    int numOfInput; //每組數字輸入個數
    long long inputNbrAry[100000] = {0}; //儲存數字陣列
    long long resultAry[100000] = {0};
    long double total; //總和

    cin >> numOfCase; //輸入組數
    for (int i = 0; i < numOfCase; i++)
    {
        total = 0; //每次歸零
        cin >> numOfInput; //輸入個數
        for (int j = 0; j < numOfInput; j++)
            cin >> inputNbrAry[j]; //輸入數字存入陣列
        sort(inputNbrAry, inputNbrAry + numOfInput); //排序陣列
        if (numOfInput % 2 != 0) //若輸入個數是奇數
            for (int k = 0; k < numOfInput; k++)
                total += fabs(inputNbrAry[numOfInput / 2] - inputNbrAry[k]);
                //中位數與每位數字相減並取絕對值後相加
        else //若輸入數字是偶數
        {
            double midNbr = (inputNbrAry[numOfInput / 2] + 
                inputNbrAry[numOfInput / 2 - 1]) / 2; //中位數為中間兩數相加除2
            for (int k = 0; k < numOfInput; k++)
                total += fabs(midNbr - inputNbrAry[k]);
                //中位數與每位數字相減並取絕對值後相加，浮點數絕對值使用fabs
        }
        resultAry[i] = total; //將結果儲存至結果陣列
    }
    for (int l = 0; l < numOfCase; l++)
        cout << resultAry[l] << endl; //從結果陣列中印出所有結果
    return 0;
}
