#include "Media.h"
#include "DVD.h"
#include "LegalDVD.h"
#include "VTR.h"
#include <iostream>
using namespace std;
// �ּ����� 10��
// ���� ���� 20��
// static int count���� 0���� �ʱ�ȭ (10��)
int Media::count = 0;
// Media Ŭ������ 'count' ������ �����Ͽ� ���� 0���� �ʱ�ȭ�Ѵ�.

int main(void)
{
	Media* mp[4];
	// new �Ҷ����� count�����ϵ��� ���� (10��)
	mp[0] = new VTR("Hello", 15, "avi");
	mp[1] = new DVD("Superman", 3, "123-9899");
	mp[2] = new LegalDVD("Marvel", 10, "456-9899", "GG entertainment");
	mp[3] = new VTR("Disney", 23, "mkv");

	for (int i = 0; i < Media::count; i++) // ������ ���� (20��)
		mp[i]->play();
	cout << "������ �����ε� �ǽ�" << endl;
	cout << mp[0]; // "VTR�� play�ǰ� �ֽ��ϴ�."�� ��µǵ��� ������ �����ε� ����(30��)
	
	mp[3] = *mp[1] + mp[2]; //"mp[1]�� length+mp[2]�� length���� �ǰԲ� �����ε� (30��)
	cout << mp[3]->getLength() << endl; // 13	
	cout << endl;
	// new�� ��ü���� �Ҹ��Ų��.
	for (int i = 0; i < 4; i++) {
		cout << i << "��° ��ü�� �Ҹ��� ȣ�� : " << endl;
		delete mp[i];
		cout << endl;
	}
	
	return 0; // new�� ��ü���� �� �Ҹ�Ǵ��� ���� �� (20��)
}
