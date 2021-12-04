#pragma once
// ��� ������ �ߺ����� include �Ǵ� ���� �����ϱ� ���Ͽ� #pragma once ��ó���� �߰�
#include <iostream>
#include <string>
using namespace std;

class Media {
	friend ostream& operator<< (ostream&, const Media*);
	// ����� ������ �����ε�. 
	// ǥ�� ���̺귯���� iostream�� ���ǵǾ� �ִ� Ŭ���� ostream�� ���� ��� ������ ������ �� �����Ƿ� �����Լ� �����ε��� ����.
private:
	string title; // namespace�� ���ǵ� string�� ���.
	int length;
public:
	static int count;
	// ��ü�� ������ ������ count�� 1�� ��������. �� ��ü�� ������ ��Ÿ���� ��� ���� 
	// ��ü�� ����� �����ϰ� �̹� Static �޸� ������ �����Ѵ�.

	//constructors
	Media(string title, int length);
	//destructor
	// ��� ���迡�� �ڽ� Ŭ������ �Ҹ��ڸ� ������ �� virtual�� ����ؾ� ��.
	// �ֻ��� Ŭ���������� ���� virtual�� ������� �ʾƵ� �����ϴ� 
	virtual ~Media();

	// ��� ������ �����ϴ� set �Լ�
	void setLength(int length);
	void setTitle(string title);
	// ��� ������ ��ȯ�ϴ� get �Լ�
	int getLength();
	string getTitle();

	// �ֻ��� Ŭ���������� ���� virtual�� ������� �ʾƵ� �����ϳ�, �������� ���ؼ� virtual ǥ��
	// const�� ����ؼ� ��� ���� ������ ������ �����ش�. 
	virtual void play() const;


	// mp[3] = *mp[1] + mp[2] ������ �����ε� ���� 
	Media* operator+(const Media*);
	// ������ �ڷ����� �����ؾ� �ϹǷ� ��ȯ �ڷ����� Media *�̸�
	// Media * �ڷ����� mp[2]�� �ǿ������̹Ƿ� Media * �ڷ������� �޴´�. �̶� ���� ������ �����ϱ� ���� const ������ �Ű������� �޵��� �Ѵ�. 
	void operator=(const Media*);
	// *mp[1] + mp[2]�� ����� ��ȯ�� Media * �ڷ����� ��ü�� �޾ƿ��Ƿ� �Ű������� ������ ����. 
	// ��ȯ�� �� �ʿ䰡 ������ void ��ȯ�� ����. 
};