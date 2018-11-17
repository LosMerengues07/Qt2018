#ifndef TWENTYFOURCALCULATION_H
#define TWENTYFOURCALCULATION_H
#include <vector>
#include <set>

namespace std
{
	class TwentyFourCalculator
	{
	public:
		TwentyFourCalculator();      //���캯�� �������
		void PrintAnswer();    // ������н��
		void Run();     // ����ɼ��������������

	private:
		int p_numbers_[4];    //��������
		char p_operators_[4] = { '+','-','*','/' };  //�����
		set<string> answer_set_;      //�Ϸ��Ĵ𰸴洢����

		void StartCalculation();
		//��ʼ���� 

		double BinaryOperation(double a, double b, char opr);
		//���ж�Ԫ����  ����Ϊ����Ԫ�غ��ַ���ʶ�������

		void GenerateAnswer(int n1, int n2, int n3, int n4, char o1, char o2, char o, int order);
		// ���ɽ�����������ʽ  �����������ֺ������
	};
}


#endif TWENTYFOURCALCULATION_H
