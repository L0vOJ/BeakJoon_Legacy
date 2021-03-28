#include<stdio.h>
int draw_line_surround(int in, int z, int zz) {    //a(작은 다이아의 한줄)는 이 함수 내에서만 쓰인다
  int a = 0;
	int ladder = 0;
  int fire =0;
  while (1) {
		if (a == 0 && ladder == 0) {		//맨 앞 부분 출발선//여기서 한줄 달리기 시작 왼쪽에서 오른쪽으로 별찍으며 달린다
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
      for (int c = 1; c < 2 * a; c++) {		//*점찍기 전부 여기서 그린다
  			printf(" ");
  		}
    }
		if (a >= 1) {
			for (int d = zz * 2; d + 1 < z * 2; ++d) {
				printf(" ");										//내부 다이아 사이의 모든 간격을 여기서 벌린다
			}
			if (zz == a) {
				ladder = 1;			//한 줄 안에서 반환점 찍기
			}
			switch (ladder)		//한 줄 안에서 반환점 안찍었다면 별 많이 찍었다면 별 적게
			{
			case 0:
				a++;
				break;
			default:
				a--;
        if(a==0){
          printf("\n");       //이 함수 끝나면서 다음 줄로 넘어간다
    			return 0;
        }
				break;
			}
		}
	}
}
void draw_line_center(int in, int z, int zz) {
	for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
		printf(" ");						//한 뭉텅이 중심의 출발선 ->모든 출발선과 조건과 같다
	}
  if(z%2==0){
    printf("%d",in);
  }
  for (int e = 2; e <= (z - 1)*(z - 1) * 2 + 1; e++) {
		printf(" ");		//중심 특유의 별도배//위와 같은 사이 간격 벌리기는 없다
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
				return 0;   //앞뒤 꽁다리가 겹치기 전에 재빨리 넘긴다
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
      printf("잘못된 입력값입니다 다시 입력해주세요:");
    }
  }
}
