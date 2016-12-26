#include "base/sigslot.h"
#include <iostream>
using namespace sigslot; 
using namespace std;
struct Clock
{
	sigslot::signal1<int> Tick;//��������
	void SendMsg(int nTime)
	{
		Tick(nTime);
	}
};
/*******************************************************/
struct Student : public sigslot::has_slots<>
{
	void GetUp(int nTime)//�����������¼��Ĵ��� ��Tick�Ĳ���һһ��Ӧ
	{
		std::cout << "��ʱ�� : " <<nTime<< std::endl;
	}
};
/*******************************************************/
int main3(int argc, char* argv[])
{
	Clock   AlarmClock;
	Student MidSchoolStu;
	AlarmClock.Tick.connect(&MidSchoolStu, &Student::GetUp);
	for(int i=0;i<10;i++)
	{
		AlarmClock.SendMsg(100);
		Sleep(2000);
	}
	AlarmClock.Tick.disconnect(&MidSchoolStu);
	return 0;
}