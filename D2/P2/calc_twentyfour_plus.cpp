#include "pch.h"
#include "calc_twentyfour_plus.h"
#include<iostream>
#include<math.h>
using namespace std;

void TwentyFourCalculatorPlus::ToBinaryCode(long num)
{
	int j = 0;
	if (num == 0)
	{
		code_array_[0] = 0;
	}
	while (num)
	{
		code_array_[j] = num % 2;
		num /= 2;
		j++;
	}
}

TwentyFourCalculatorPlus::TwentyFourCalculatorPlus()
{
	cin >> card_num_ >> target_;
	for (int i = 0; i < card_num_; i++)
	{
		cin >> card_numbers_array_[i];
	}
}

void TwentyFourCalculatorPlus::run()
{
	long total_permutation = pow(2, card_num_ - 1);       //n�����֣�n-1�����������Ӧ2^(n-1)�����п�����
	long result = 0;
	for (int i = 0; i < total_permutation; i++)                  //����������
	{
		ToBinaryCode(i);                                //��ʮ�����������i�ֿ����ԣ�ת���ɶ��������д����������������
		result = CalculateFormula();
		if (result == target_)        //�ҵ��Ϸ�����ʽ
		{
			PrintResult(); 
		}
		else if (result > target_&&above_target_min_ == -1 || result > target_&&result < above_target_min_) 
		{    //����Ƿ���±�Ŀ������Сֵ
			above_target_min_ = result;
		}
	}
	if (above_target_min_ > result)           //δ�ҵ��Ϸ��㷨�����ҵ���Ŀ������Сֵ
	{
		cout << "No" << endl << above_target_min_;
	}
	else                    //δ�ҵ��Ϸ��㷨�����ֵС��Ŀ��
	{
		cout << "No" << endl << -1;
	}
}

long TwentyFourCalculatorPlus::CalculateFormula()
{
	long temp_result = card_numbers_array_[0];
	for (int i = 0; i < card_num_-1; i++)                //����Ϊ0��Ӧ�ӷ�
	{
		if (code_array_[i] == 1)
		{
			temp_result = temp_result + card_numbers_array_[i + 1];
		}
		else                                                             //����Ϊ1��Ӧ�˷�
		{
			temp_result = temp_result * card_numbers_array_[i + 1];
		}
	}
	return temp_result;
}

void TwentyFourCalculatorPlus::PrintResult()
{
	for (int j = 0; j < card_num_ - 1; j++)
	{
		if (code_array_[j] == 0)
		{
			cout << card_numbers_array_[j] << '*';
		}
		else
		{
			cout << card_numbers_array_[j] << '+';
		}
	}
	cout << card_numbers_array_[card_num_ - 1];
	exit(0);
}