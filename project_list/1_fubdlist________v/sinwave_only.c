#include<stdio.h>
int draw_line_surround(int in, int z, int zz) {    //a(���� ���̾��� ����)�� �� �Լ� �������� ���δ�
  int a = 0;
	int ladder = 0;
  int fire =0;
  while (1) {
		if (a == 0 && ladder == 0) {		//�� �� �κ� ��߼�//���⼭ ���� �޸��� ���� ���ʿ��� ���������� �������� �޸���
			for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
				printf(" ");
			}
			a++;
		}
    if(z%2==0 && fire==0){
      printf("%d",in);
      fire++;
    }
    else if(z%2==1 && fire==0 && ladder==1 && a==1){
      printf("%d",in);
      fire++;
    }
    else if(z%2==1 && fire==0 && zz==1){
      printf("%d",in);
      fire++;
    }
    else{
      for (int c = 1; c < 2 * a; c++) {		//*����� ���� ���⼭ �׸���
  			printf(" ");
  		}
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
        if(a==0){
          printf("\n");       //�� �Լ� �����鼭 ���� �ٷ� �Ѿ��
    			return 0;
        }
				break;
			}
		}
	}
}
void draw_line_center(int in, int z, int zz) {
	for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
		printf(" ");						//�� ������ �߽��� ��߼� ->��� ��߼��� ���ǰ� ����
	}
  if(z%2==0){
    printf("%d",in);
  }
  for (int e = 2; e <= (z - 1)*(z - 1) * 2 + 1; e++) {
		printf(" ");		//�߽� Ư���� ������//���� ���� ���� ���� ������� ����
	}
  if(z%2==1){
    printf("%d",in);
  }
	printf("\n");
}
int draw_package(int in, int z) {
	int zz = 1;
	int ladder = 0;
	while (1) {
		if (zz == z) {
				draw_line_center(in, z, zz);
				ladder = 1;
			}
		else {
			draw_line_surround(in, z, zz);
		}
		switch (ladder) {
		case 0:
			zz++;
			break;
		case 1:
			zz--;
			if (zz == 1) {
				return 0;   //�յ� �Ǵٸ��� ��ġ�� ���� �绡�� �ѱ��
			}
			break;
		}
	}
}
int main() {
	int in;
	int z = 2;
	int ladder = 0;
	printf("how many stacks do you want to stack?:");
  while(1){
    scanf_s("%d", &in);
    if(in == 1){
      printf("*");
      return 0;
    }
    else if(1<in && in<13){
    	while (1) {
    		draw_package(in, z);
    		if (z == in) {
    			ladder = 1;
    		}
    		switch (ladder) {
    		case 0:
    			z++;
    			break;
    		default:
    			z--;
    			if (z == 1) {
    				draw_line_center(in,z,1);
    				return 0;
    			}
    			break;
    		}
    	}
    }
    else{
      printf("�߸��� �Է°��Դϴ� �ٽ� �Է����ּ���:");
    }
  }
}
