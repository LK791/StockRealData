// TradeXDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>

using namespace std;

#include "TradeX.h"

int test_trade_funcs();
int test_hq_funcs(const char *pszHqSvrIP, short nPort);
int test_exhq_funcs(const char *pszHqSvrIP, short nPort);
int test_l2hq_funcs();

int _tmain(int argc, _TCHAR* argv[])
{
    //////////////////////////////////////////////////////////////////////////////////

    cout << "\n";
    cout << "\n";
    cout << "\tTradeX�ĺ�һ��ȫ����ԭ�е�Trade.dll�µ�ҵ������������API" << endl;
    cout << "\t����˻�̩��ȯ�̷������޷��������ӵ����⣬���κ�ʱ��ζ�������ȷȡ����" << endl;
    cout << "\t֧��VC,VB��C#��Python��ֱ�����׷����������������" << endl;
    cout << "\n";
    cout << "\tTradeX = trade.dll + tdxhqapi.dll + tdxexhqapi.dll + tdxl2hqapi.dll" << endl;
    cout << "\n";
    cout << "\t������Ҫ����ϵQQ��3048747297�� ����֧��QQȺ��318139137" << endl;
    cout << "\n";

    cout << "���س������в���..." << endl;
    cin.get();

    cout << endl;
    cout << "\n";

    //
    //
    //
    if (1)
    {
        cout << "���Խ���API, ���س�������...\n" << std::endl;
        if (!test_trade_funcs())
        {
            cout << "���Խ���!!!" << endl;
            cin.get();
            //return 0;
        }
    }

    //
    //
    if (1)
    {
        cout << "��������API, ���س�������...\n" << std::endl;
        test_hq_funcs("14.17.75.71", 7709);
        getchar();
    }

    //
    //
    if (1)
    {
        cout << "������չ����API, ���س�������...\n" << std::endl;
        test_exhq_funcs("59.175.238.38", 7727);
        getchar();
    }

    //
    //
    if (1)
    {
        cout << "����L2����API, ���س�������...\n" << std::endl;
        test_l2hq_funcs();
    }

    cout << "���Խ���!!!" << endl;
    cin.get();

    return 0;
}

