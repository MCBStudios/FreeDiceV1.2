//�����
#include<iostream>//����cin��cout 
#include<cstdio>//scanf��printf 
#include<cstdlib>//������ 
#include<time.h>//����� 
#include<windows.h>//Sleep 

//���������ռ�
using namespace std;

//��ʼ��ȫ�ֱ���
//Ϊ��߿���ֲ�ԣ���ʹ��long
long mode;//���ڼ�¼�û���ѡģʽ

long settings_start,settings_end;//������9-�����м�¼�û�ѡ��Ŀ�ʼ-ֹͣ��ֵ

long random_number;//���ڴ洢ģʽ2~8�������

long random_number_max=49,clearlag0=0,clearlag1=0;

//��ʾ����ͼ��
void startup_screen() {

	cout<<("|---------|-----|")<<endl;
	cout<<("|�ȴ���...|׼�� |")<<endl;
	cout<<("|         | ��ʼ|")<<endl;
	cout<<("|---------|-----|")<<endl;
	cout<<("�� 1 �������ģʽ")<<endl;
	cout<<("��2~8����Ԥ��ģʽ")<<endl;
	cout<<("�� 9 �� �� �� �� ")<<endl;

}

//��ȡ�û����룬ѡ��ģʽ
void mode_select() {

	cout<<("����ģʽ���Ų����س�ִ��")<<endl;
	cout<<(">_ ");
	scanf("%d",&mode);

}

//��1�������ģʽ
void help_mode() {

	cout<<endl;
	cout<<("FreeDiceʹ���ֲ�  -  By MCB Studios")<<endl;
	cout<<endl;
	cout<<("Ԥ��ģʽ��7�֣����ÿɵ������������")<<endl;
	cout<<endl;
	cout<<("�� 2 �� 1 ~ 49�� ���� 3 �� 1 ~ 12��")<<endl;
	cout<<("�� 4 �� 1 ~ 44�� ���� 5 �� 1 ~ 11��")<<endl;
	cout<<endl;
	cout<<("V1.5��֧��.txt���! V2.0����������!")<<endl; 
	cout<<endl;
	cout<<("FreeDice3.0-C++ �ڲ��汾1.0 Release")<<endl;
	cout<<("Made with Dev-C++  &  TDM-GCC 4.9.2")<<endl;
	cin.get();

}

//��ȡ�����
void random_choose() {
    
    if (mode == 2) random_number_max = 49 ;
	else if (mode == 3) random_number_max = 12 ;
	else if (mode == 4) random_number_max = 44 ;
	else if (mode == 5) random_number_max = 11 ;
	else random_number_max = 49 ;
	
	srand(time(0));
	for (long i=0; i<=5; i++) {

		long sum = rand() % random_number_max+1;
		cout<< sum << endl ;
		Sleep (500);
	}
}

//�û��Զ�������
void current_settings() {

	cout<<"�����뿪ʼ�ţ�";
	cin>>settings_start;
	cout<<endl<<"����������ţ�";
	cin>>settings_end;

	srand(time(0)) ;
	for (long i=0; i<=5; i++) {

		long current_sum = rand() % settings_end+1;
		if (current_sum <= settings_start) current_sum = rand() % settings_end+1;
		else cout<< current_sum << endl ;
		Sleep (500);
	}

}

//��ʾ�˳�����
void finish_window() {

	cout<<("���س��˳�...")<<endl;
	cin.get();//Ϊ��ֹ����ֱ���˳�����ȡһ������
	cin.get(); //����һ��

}

//������
int main() {
	startup_screen();

	mode_select();
	if (mode == 1) {
		help_mode();
		mode_select();
		random_choose();
	} else if (mode >= 2 && mode <=8) {
		

		random_choose();
	} else if (mode == 9) {

		current_settings() ;
	}

	finish_window();
	return 0;
}
