#ifndef __TRADEX_H
#define __TRADEX_H

#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

//
// ����API
//

//1.����API����Trade.dll�ļ��ĵ����������������º�����
//�������9��������
// void  OpenTdx();//��ͨ����
// void  CloseTdx();//�ر�ͨ����
//  int  Logon(char* IP, short Port, char* Version, short YybID, char* AccountNo,char* TradeAccount, char* JyPassword,   char* TxPassword, char* ErrInfo);//��¼�ʺ�
// void  Logoff(int ClientID);//ע��
// void  QueryData(int ClientID, int Category, char* Result, char* ErrInfo);//��ѯ���ཻ������
// void  SendOrder(int ClientID, int Category ,int PriceType,  char* Gddm,  char* Zqdm , float Price, int Quantity,  char* Result, char* ErrInfo);//�µ�
// void  CancelOrder(int ClientID, char* ExchangeID, char* hth, char* Result, char* ErrInfo);//����
// void  GetQuote(int ClientID, char* Zqdm, char* Result, char* ErrInfo);//��ȡ�嵵����
// void  Repay(int ClientID, char* Amount, char* Result, char* ErrInfo);//������ȯ�˻�ֱ�ӻ���


//��ͨ������������5��������(��Щȯ�̶������������������٣��������������Ŀ����ѯȯ��)
// void  QueryHistoryData(int ClientID, int Category, char* StartDate, char* EndDate, char* Result, char* ErrInfo);//��ѯ������ʷ����
// void  QueryDatas(int ClientID, int Category[], int Count, char* Result[], char* ErrInfo[]);//���˻�������ѯ���ཻ������
// void  SendOrders(int ClientID, int Category[] , int PriceType[], char* Gddm[],  char* Zqdm[] , float Price[], int Quantity[],  int Count, char* Result[], char* ErrInfo[]);//���˻������µ�
// void  CancelOrders(int ClientID, char* ExchangeID[], char* hth[], int Count, char* Result[], char* ErrInfo[]);//���˻���������
// void  GetQuotes(int ClientID, char* Zqdm[], int Count, char* Result[], char* ErrInfo[]);//���˻�������ȡ�嵵����


///���׽ӿ�ִ�к����ʧ�ܣ����ַ���ErrInfo�����˳�����Ϣ����˵����
///����ɹ������ַ���Result�����˽������,��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���
///Result��\n��\t�ָ��������ַ����������ѯ�ɶ�����ʱ���صĽ���ַ������� 

///"�ɶ�����\t�ɶ�����\t�ʺ����\t������Ϣ\n
///0000064567\t\t0\t\nA000064567\t\t1\t\n
///2000064567\t\t2\t\nB000064567\t\t3\t"

///��ô�����֮��ͨ���ָ��ַ����� ���Իָ�Ϊ���м��еı����ʽ������



//2.APIʹ������Ϊ: Ӧ�ó����ȵ���OpenTdx��ͨ����ʵ����һ��ʵ���¿���ͬʱ��¼��������˻���ÿ�������˻���֮ΪClientID.
//ͨ������Logon���ClientID��Ȼ����Ե�������API���������ClientID���в�ѯ���µ�; Ӧ�ó����˳�ʱӦ����Logoffע��ClientID, ������CloseTdx�ر�ͨ����ʵ��. 
//OpenTdx��CloseTdx������Ӧ�ó�����ֻ�ܱ�����һ��.API���ж����Զ��������ܣ�Ӧ�ó���ֻ�����API�������صĳ�����Ϣ�����ʵ��������ɡ�


//3. ������������˵��

/// <summary>
/// ��ͨ����ʵ��
/// </summary>
void WINAPI OpenTdx();


/// <summary>
/// �ر�ͨ����ʵ��
/// </summary>
void WINAPI CloseTdx();


/// <summary>
/// �����˻���¼
/// </summary>
/// <param name="pszIP">ȯ�̽��׷�����IP</param>
/// <param name="nPort">ȯ�̽��׷������˿�</param>
/// <param name="pszVersion">����ͨ���ſͻ��˵İ汾��</param>
/// <param name="nYybID">Ӫҵ�����룬�뵽��ַ http://www.chaoguwaigua.com/downloads/qszl.htm ��ѯ</param>
/// <param name="pszAccountNo">�����ĵ�¼�˺ţ�ȯ��һ��ʹ���ʽ��ʻ���ͻ���</param>
/// <param name="pszTradeAccount">�����˺ţ�һ�����¼�ʺ���ͬ. ���¼ȯ��ͨ�����������ѯ�ɶ��б��ɶ��б��ڵ��ʽ��ʺž��ǽ����ʺ�, �����ѯ���������վ���ȵ��ʴ���Ŀ</param>
/// <param name="pszJyPassword">��������</param>
/// <param name="pszTxPassword">ͨѶ����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ͻ���ID��ʧ��ʱ����-1</returns>
int WINAPI Logon(
    const char* pszIP,
    short nPort,
    const char* pszVersion,
    short nYybID,
    const char* pszAccountNo,
    const char* pszTradeAccount,
    const char* pszJyPassword,
    const char* pszTxPassword,
    char* pszErrInfo);


/// <summary>
/// �����˻�ע��
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
void WINAPI Logoff(int nClientID);


/// <summary>
/// ��ѯ���ֽ�������
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="nCategory">��ʾ��ѯ��Ϣ�����࣬0�ʽ�  1�ɷ�   2����ί��  3���ճɽ�     4�ɳ���   5�ɶ�����  6�������   7��ȯ���  8����֤ȯ</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">ͬLogon������ErrInfo˵��</param>
void WINAPI QueryData(
    int nClientID,
    int nCategory,
    char* pszResult,
    char* pszErrInfo);


/// <summary>
/// ��ѯ������ʷ����
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="nCategory">��ʾ��ѯ��Ϣ�����࣬0��ʷί��  1��ʷ�ɽ�   2���</param>
/// <param name="pszStartDate">��ʾ��ʼ���ڣ���ʽΪyyyyMMdd,����2014��3��1��Ϊ  20140301
/// <param name="pszEndDate">��ʾ�������ڣ���ʽΪyyyyMMdd,����2014��3��1��Ϊ  20140301
/// <param name="pszResult">ͬ��</param>
/// <param name="pszErrInfo">ͬ��</param>
void WINAPI QueryHistoryData(
    int nClientID,
    int nCategory,
    const char* pszStartDate,
    const char* pszEndDate,
    char* pszResult,
    char* pszErrInfo);


/// <summary>
/// ������ѯ���ֽ�������,�����鴫��ÿ��ί�еĲ����������i��Ԫ�ر�ʾ��i����ѯ����Ӧ����
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="nCategory">��Ϣ�����������, ��i��Ԫ�ر�ʾ��i����ѯ����Ϣ���࣬0�ʽ�  1�ɷ�   2����ί��  3���ճɽ�     4�ɳ���   5�ɶ�����  6�������   7��ȯ���  8����֤ȯ</param>
/// <param name="nCount">��ѯ�ĸ�����������ĳ���</param>
/// <param name="pszResult">�������ݵ�����, ��i��Ԫ�ر�ʾ��i��ί�еķ�����Ϣ. ��APIִ�з��غ�Result[i]����ͬ�ϡ�</param>
/// <param name="pszErrInfo">������Ϣ�����飬��i��Ԫ�ر�ʾ��i��ί�еĴ�����Ϣ. ��APIִ�з��غ�ErrInfo[i]����ͬ�ϡ�</param>
void WINAPI QueryDatas(
    int nClientID,
    int nCategory[],
    int nCount,
    char* pszResult[],
    char* pszErrInfo[]);


/// <summary>
/// ��ί�н���֤ȯ
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="nCategory">��ʾί�е����࣬0���� 1����  2��������  3��ȯ����   4��ȯ��ȯ   5��ȯ����  6��ȯ��ȯ</param>
/// <param name="nPriceType">��ʾ���۷�ʽ 0�Ϻ��޼�ί�� �����޼�ί�� 1(�м�ί��)���ڶԷ����ż۸�  2(�м�ί��)���ڱ������ż۸�  3(�м�ί��)���ڼ�ʱ�ɽ�ʣ�೷��  4(�м�ί��)�Ϻ��嵵����ʣ�� �����嵵����ʣ�� 5(�м�ί��)����ȫ��ɽ����� 6(�м�ί��)�Ϻ��嵵����ת�޼�
/// <param name="pszGddm">�ɶ�����, �����Ϻ���Ʊ���Ϻ��Ĺɶ����룻�������ڵĹ�Ʊ�������ڵĹɶ�����</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="fPrice">ί�м۸�</param>
/// <param name="nQuantity">ί������</param>
/// <param name="pszResult">ͬ��,���к���ί�б������</param>
/// <param name="pszErrInfo">ͬ��</param>
void WINAPI SendOrder(
    int nClientID,
    int nCategory,
    int nPriceType,
    const char* pszGddm,
    const char* pszZqdm,
    float fPrice,
    int nQuantity,
    char* pszResult,
    char* pszErrInfo);


/// <summary>
/// ������ί�н���֤ȯ�������鴫��ÿ��ί�еĲ����������i��Ԫ�ر�ʾ��i��ί�е���Ӧ����
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="nCategory">ί����������飬��i��Ԫ�ر�ʾ��i��ί�е����࣬0���� 1����  2��������  3��ȯ����   4��ȯ��ȯ   5��ȯ����  6��ȯ��ȯ</param>
/// <param name="nPriceType">��ʾ���۷�ʽ������,  ��i��Ԫ�ر�ʾ��i��ί�еı��۷�ʽ, 0�Ϻ��޼�ί�� �����޼�ί�� 1(�м�ί��)���ڶԷ����ż۸�  2(�м�ί��)���ڱ������ż۸�  3(�м�ί��)���ڼ�ʱ�ɽ�ʣ�೷��  4(�м�ί��)�Ϻ��嵵����ʣ�� �����嵵����ʣ�� 5(�м�ί��)����ȫ��ɽ����� 6(�м�ί��)�Ϻ��嵵����ת�޼�
/// <param name="pszGddm">�ɶ��������飬��i��Ԫ�ر�ʾ��i��ί�еĹɶ����룬�����Ϻ���Ʊ���Ϻ��Ĺɶ����룻�������ڵĹ�Ʊ�������ڵĹɶ�����</param>
/// <param name="pszZqdm">֤ȯ�������飬��i��Ԫ�ر�ʾ��i��ί�е�֤ȯ����</param>
/// <param name="fPrice">ί�м۸����飬��i��Ԫ�ر�ʾ��i��ί�е�ί�м۸�</param>
/// <param name="nQuantity">ί���������飬��i��Ԫ�ر�ʾ��i��ί�е�ί������</param>
/// <param name="nCount">ί�еĸ�����������ĳ���</param>
/// <param name="pszResult">ͬ��</param>
/// <param name="pszErrInfo">ͬ��</param>
void WINAPI SendOrders(
    int nClientID,
    int nCategory[],
    int nPriceType[],
    const char* pszGddm[],
    const char* pszZqdm[],
    float fPrice[],
    int nQuantity[],
    int nCount,
    char* pszResult[],
    char* pszErrInfo[]);


/// <summary>
/// ��ί��
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="pszExchangeID">������ID�� �Ϻ�1������0(����֤ȯ��ͨ�˻�������2)</param>
/// <param name="pszhth">��ʾҪ����Ŀ��ί�еı��</param>
/// <param name="pszResult">ͬ��</param>
/// <param name="pszErrInfo">ͬ��</param>
void WINAPI CancelOrder(
    int nClientID,
    const char* pszExchangeID,
    const char* pszhth,
    char* pszResult,
    char* pszErrInfo);


/// <summary>
/// ������ί��, �����鴫��ÿ��ί�еĲ����������i��Ԫ�ر�ʾ��i����ί�е���Ӧ����
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
// <param name="pszExchangeID">������ID�� �Ϻ�1������0(����֤ȯ��ͨ�˻�������2)</param>
/// <param name="pszhth">��ʾҪ����Ŀ��ί�еı��</param>
/// <param name="nCount">��ί�еĸ�����������ĳ���</param>
/// <param name="pszResult">ͬ��</param>
/// <param name="pszErrInfo">ͬ��</param>
void WINAPI CancelOrders(
    int nClientID,
    const char* pszExchangeID[],
    const char* pszhth[],
    int nCount,
    char* pszResult[],
    char* pszErrInfo[]);


/// <summary>
/// ��ȡ֤ȯ��ʵʱ�嵵����
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="pszResult">ͬ��</param>
/// <param name="pszErrInfo">ͬ��</param>
void WINAPI GetQuote(
    int nClientID,
    const char* pszZqdm,
    char* pszResult,
    char* pszErrInfo);


/// <summary>
/// ������ȡ֤ȯ��ʵʱ�嵵����
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="nCount">֤ȯ�ĸ�����������ĳ���</param>
/// <param name="pszResult">ͬ��</param>
/// <param name="pszErrInfo">ͬ��</param>
void WINAPI GetQuotes(
    int nClientID,
    const char* pszZqdm[],
    int nCount,
    char* pszResult[],
    char* pszErrInfo[]);


/// <summary>
/// ������ȯֱ�ӻ���
/// </summary>
/// <param name="nClientID">�ͻ���ID</param>
/// <param name="pszAmount">������</param>
/// <param name="pszResult">ͬ��</param>
/// <param name="pszErrInfo">ͬ��</param>
void WINAPI Repay(
    int nClientID,
    const char* pszAmount,
    char* pszResult,
    char* pszErrInfo);



//
// ����API
//

//1.����API����TradeX.dll�ļ��ĵ����������������º�����(�������麯����Ϊ�ͻ������������ѯ�����Ƿ���������)

//2.APIʹ������Ϊ: Ӧ�ó����ȵ���TdxHq_Connect����ͨ�������������,Ȼ��ſ��Ե��������ӿڻ�ȡ��������,Ӧ�ó���Ӧ���д��������������, �ӿ����̰߳�ȫ��

//3.������������˵��

/// <summary>
///  ����ͨ�������������,��������ַ����ȯ�������¼�����е�ͨѶ�����в��
/// </summary>
/// <param name="pszIP">������IP</param>
/// <param name="nPort">�������˿�</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_Connect(
    const char *pszIP,
    short nPort,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// �Ͽ�ͬ������������
/// </summary>
void WINAPI TdxHq_Disconnect();


/// <summary>
/// ��ȡָ���г��ڵ�֤ȯ��Ŀ
/// </summary>
bool WINAPI TdxHq_GetSecurityCount(
    char nMarket,
    short *nCount,
    char *pszErrInfo);


/// <summary>
/// ��ȡָ���г��ڵ�֤ȯ�б�
/// </summary>
bool WINAPI TdxHq_GetSecurityList(
    char nMarket,
    short nStart,
    short *nCount,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡ֤ȯ��K������
/// </summary>
/// <param name="nCategory">K������, 0->5����K��    1->15����K��    2->30����K��  3->1СʱK��    4->��K��  5->��K��  6->��K��  7->1����  8->1����K��  9->��K��  10->��K��  11->��K��< / param>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="nStart">K�߿�ʼλ��,���һ��K��λ����0, ǰһ����1, ��������</param>
/// <param name="nCount">APIִ��ǰ,��ʾ�û�Ҫ�����K����Ŀ, APIִ�к�,������ʵ�ʷ��ص�K����Ŀ, ���ֵ800</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetSecurityBars(
    char nCategory,
    char nMarket,
    const char *pszZqdm,
    short nStart,
    short *nCount,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡָ����K������
/// </summary>
/// <param name="nCategory">K������, 0->5����K��    1->15����K��    2->30����K��  3->1СʱK��    4->��K��  5->��K��  6->��K��  7->1����  8->1����K��  9->��K��  10->��K��  11->��K��< / param>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="nStart">K�߿�ʼλ��,���һ��K��λ����0, ǰһ����1, ��������</param>
/// <param name="nCount">APIִ��ǰ,��ʾ�û�Ҫ�����K����Ŀ, APIִ�к�,������ʵ�ʷ��ص�K����Ŀ,���ֵ800</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetIndexBars(
    char nCategory,
    char nMarket,
    const char *pszZqdm,
    short nStart,
    short *nCount,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡ��ʱ����
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetMinuteTimeData(
    char nMarket,
    const char *pszZqdm,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡ��ʷ��ʱ����
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="nDate">����, ����2014��1��1��Ϊ����20140101</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetHistoryMinuteTimeData(
    char nMarket,
    const char *pszZqdm,
    int nDate,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡ��ʱ�ɽ�����
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="nStart">K�߿�ʼλ��,���һ��K��λ����0, ǰһ����1, ��������</param>
/// <param name="nCount">APIִ��ǰ,��ʾ�û�Ҫ�����K����Ŀ, APIִ�к�,������ʵ�ʷ��ص�K����Ŀ</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetTransactionData(
    char nMarket,
    const char *pszZqdm,
    short nStart,
    short *nCount,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡ��ʷ��ʱ�ɽ�����
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="nStart">K�߿�ʼλ��,���һ��K��λ����0, ǰһ����1, ��������</param>
/// <param name="nCount">APIִ��ǰ,��ʾ�û�Ҫ�����K����Ŀ, APIִ�к�,������ʵ�ʷ��ص�K����Ŀ</param>
/// <param name="nDate">����, ����2014��1��1��Ϊ����20140101</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetHistoryTransactionData(
    char nMarket,
    const char *pszZqdm,
    short nStart,
    short *nCount,
    int nDate,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ������ȡ���֤ȯ���嵵��������
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�, ��i��Ԫ�ر�ʾ��i��֤ȯ���г�����</param>
/// <param name="pszZqdm">֤ȯ����, Count��֤ȯ������ɵ�����</param>
/// <param name="nCount">APIִ��ǰ,��ʾ�û�Ҫ�����֤ȯ��Ŀ,���290, APIִ�к�,������ʵ�ʷ��ص���Ŀ</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetSecurityQuotes(
    char nMarket[],
    const char *pszZqdm[],
    short *nCount,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡF10���ϵķ���
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetCompanyInfoCategory(
    char nMarket,
    const char *pszZqdm,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡF10���ϵ�ĳһ���������
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="pszFileName">��Ŀ���ļ���, ��TdxHq_GetCompanyInfoCategory������Ϣ�л�ȡ</param>
/// <param name="nStart">��Ŀ�Ŀ�ʼλ��, ��TdxHq_GetCompanyInfoCategory������Ϣ�л�ȡ</param>
/// <param name="nLength">��Ŀ�ĳ���, ��TdxHq_GetCompanyInfoCategory������Ϣ�л�ȡ</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����,����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetCompanyInfoContent(
    char nMarket,
    const char *pszZqdm,
    const char *pszFileName,
    int nStart,
    int nLength,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡ��Ȩ��Ϣ��Ϣ
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����,����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetXDXRInfo(
    char nMarket,
    const char *pszZqdm,
    char *pszResult,
    char *pszErrInfo);


/// <summary>
/// ��ȡ������Ϣ
/// </summary>
/// <param name="nMarket">�г�����,   0->����     1->�Ϻ�</param>
/// <param name="pszZqdm">֤ȯ����</param>
/// <param name="pszResult">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����,����ʱΪ���ַ�����</param>
/// <param name="pszErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ɹ�����true, ʧ�ܷ���false</returns>
bool WINAPI TdxHq_GetFinanceInfo(
    char nMarket,
    const char *pszZqdm,
    char *pszResult,
    char *pszErrInfo);

#ifdef __cplusplus
}
#endif

#endif
