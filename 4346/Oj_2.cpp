// �Գ���������ع��ͼ�
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*****************************************************************************
Prototype    : multiply
Description  : �������ⳤ�ȵĳ��������, ������
Input Param  :
const std::string strMultiplierA  ����A
const std::string strMultiplierB  ����B
Output       :
std::string strRst            �˷����
Return Value :
int                       0  ��ȷ
-1  �쳣
*****************************************************************************/
int multiply(const std::string strMultiplierA, const std::string strMultiplierB, std::string &strRst)
{

	/* ������ʵ�ֹ��� */
	if (strMultiplierA.length() == 0 || strMultiplierB.length() == 0)
		return -1;
	vector<int> multiA, multiB;
	for (int i = strMultiplierA.length() - 1; i >= 0; --i)
		multiA.push_back(strMultiplierA[i] - '0');
	for (int i = strMultiplierB.length() - 1; i >= 0; --i)
		multiB.push_back(strMultiplierB[i] - '0');

	vector<int> result(multiA.size() + multiB.size(), 0);
	for (int i = 0; i < multiA.size(); ++i)
	for (int j = 0; j < multiB.size(); ++j)
	{
		result[i + j] += multiA[i] * multiB[j];
	}

	for (int i = 0; i < result.size(); ++i)
	{
		if (result[i] >= 10)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	}

	int pos = -1;
	for (int i = result.size() - 1; i >= 0; --i)
	{
		if (result[i] != 0)
		{
			pos = i;
			break;
		}
	}

	if (pos == -1)
		strRst = "0";

	for (int i = pos; i >= 0; --i)
		strRst.push_back(result[i] + '0');

	return 0;

}

int main()
{
	string b = "154156";
	string a = "12553";
	string c;
	multiply(a, b, c);
	cout << a << " * " << b << " = " << c << endl;
}