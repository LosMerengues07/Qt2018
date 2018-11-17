
#pragma once

class TwentyFourCalculatorPlus
{
public:
	void ToBinaryCode(long num);     //��ʮ�����������Ϊ���������У���Ӧ����ӷ��ͳ˷�������
	void run();     //�����㷨���нӿڣ�
	TwentyFourCalculatorPlus();     //���캯��  �������벢��ʼ������

private:
	int card_num_;                               //��������
	int target_;                                     //Ŀ������
	int code_array_[23] = {0};              //�����Ʊ������У���Ӧ�����
	long card_numbers_array_[24];     //���濨�Ƹ����ֵ�����
	long above_target_min_ = -1;       //��Ŀ�����������Сֵ

	long CalculateFormula();               //�������ʽ��ֵ
	void PrintResult();                          //��ӡ����ʽ
};