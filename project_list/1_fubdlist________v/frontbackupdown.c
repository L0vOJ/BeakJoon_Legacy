#include<stdio.h>
int main()
{
	int in, zzz;		//in �� �Է°�(�߽ɴ��̾��� ������=���̾Ƹ� �������� �ϴ� ���� ������ ������(ũ�� 1�� ���̾ƿ� ũ�� 2�� ���̾ƴ� ��ġ�°��� ���)=in)
	int z = 2;    //z�� ���̾� �¿�� �� ������ 1����
	int zz = 1;  //zz�� ��ü �� ��
	int a = 0;	//a�� ���� ���̾��� ����= *����
	int ladder = 0;		//ladder�� �¿� ���̾� ũ�� ���-�϶� ���� 0�̸� ���̾�ũ�� ��� 1�̸� ���̾�ũ�� �϶�
	printf("����� �����ðڽ��ϱ�?\n");
	scanf_s("%d", &in);
	while (z <= in) {			//��ü ������ ��ݽ�+�߽�
		while (zz < z) {		//�� ���̾� ������ ��ݽš� �� �������� �߽��� �� �����. ���� �׸���
			if (a == 0) {		//�� �� �κ� ��߼�//���⼭ ���� �޸��� ���� ���ʿ��� ���������� �������� �޸���
				for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
					printf(" ");
				}
				a++;
			}
			for (int c = 1; c < 2 * a; c++) {		//*����� ���� ���⼭ �׸���
				printf("*");
			}
			if (a >= 1) {
				for (int d = zz * 2; d + 1 < z * 2; ++d) {
					printf(" ");										//���� ���̾� ������ ��� ������ ���⼭ ������
				}
				if (zz == a) {
					ladder = 1;			//�� �� �ȿ��� ��ȯ�� ���
				}
				switch (ladder)		//�� �� �ȿ��� ��ȯ�� ������ٸ� �� ���� ����ٸ� �� ����
				{
				case 0:
					a++;
					break;
				default:
					a--;
					break;
				}
			}
			if (a == 0) {				//�� �����ʿ� �����ϸ� �����ٷ� ����
				printf("\n");
				ladder = 0;
				zz++;
			}
		}
		for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
			printf(" ");						//�� ������ �߽��� ��߼� ->��� ��߼��� ���ǰ� ����
		}
		for (int e = 1; e <= (z - 1)*(z - 1) * 2 + 1; e++) {
			printf("*");		//�߽� Ư���� ������//���� ���� ���� ���� ������� ����
		}
		printf("\n");
		zz--;								//�� �������� ��ȯ��
		while (zz >= 2) {		//�� ���̾� ������ �Ϲݽ�
			if (a == 0) {
				for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
					printf(" ");
				}
				a++;
			}
			for (int c = 1; c < 2 * a; c++) {
				printf("*");
			}
			if (a >= 1) {
				for (int d = zz * 2; d + 1 < z * 2; ++d) {
					printf(" ");
				}
				if (zz == a) {
					ladder = 1;
				}
				switch (ladder)
				{
				case 0:
					a++;
					break;
				default:
					a--;
					break;
				}
			}
			if (a == 0) {
				printf("\n");
				ladder = 0;
				zz--;
			}
		}
		z++;
	}
	z--;									//��ü ������ ��ȯ��
	z--;									//��ݽŰ��� +-�� �ణ�� ������ �����ϰ�� ũ�� ���̰� ����
	while (z >= 2) {			//���� ��ü ������ �Ϲݽ�-�߽�x ���� �����̰� �۾�����
		while (zz < z) {		//�� �������� ��ݽ�
			if (a == 0) {			//��߼�
				for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
					printf(" ");
				}
				a++;
			}
			for (int c = 1; c < 2 * a; c++) {
				printf("*");
			}
			if (a >= 1) {
				for (int d = zz * 2; d + 1 < z * 2; ++d) {
					printf(" ");
				}
				if (zz == a) {
					ladder = 1;
				}
				switch (ladder)
				{
				case 0:
					a++;
					break;
				default:
					a--;
					break;
				}
			}
			if (a == 0) {
				printf("\n");
				ladder = 0;
				zz++;
			}
		}
		for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
			printf(" ");			//�� ������ ������� ��߼�
		}
		for (int e = 1; e <= (z - 1)*(z - 1) * 2 + 1; e++) {
			printf("*");			//�� ������ �߽���
		}
		printf("\n");
		zz--;								//������ ��ȯ��
		while (zz >= 2) {		//������ �Ϲݽ�
			if (a == 0) {			//������ �Ϲݽ� �����
				for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
					printf(" ");
				}
				a++;
			}
			for (int c = 1; c < 2 * a; c++) {
				printf("*");
			}
			if (a >= 1) {
				for (int d = zz * 2; d + 1 < z * 2; ++d) {
					printf(" ");
				}
				if (zz == a) {
					ladder = 1;
				}
				switch (ladder)
				{
				case 0:
					a++;
					break;
				default:
					a--;
					break;
				}
			}
			if (a == 0) {
				printf("\n");
				ladder = 0;
				zz--;
			}
		}
		z--;
	}
	for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
		printf(" ");				//������ ��߼�
	}
	printf("*");					//ȭ �� �� ��
	scanf_s("%d", &zzz);
}
