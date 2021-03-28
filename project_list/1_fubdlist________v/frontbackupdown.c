#include<stdio.h>
int main()
{
	int in, zzz;		//in 은 입력값(중심다이아의 반지름=다이아를 기준으로 하는 최종 형태의 반지름(크기 1인 다이아와 크기 2인 다이아는 겹치는것을 고려)=in)
	int z = 2;    //z는 다이아 좌우로 한 뭉텅이 1단위
	int zz = 1;  //zz는 전체 한 줄
	int a = 0;	//a는 작은 다이아의 한줄= *결정
	int ladder = 0;		//ladder는 좌우 다이아 크기 상승-하락 결정 0이면 다이아크기 상승 1이명 다이아크기 하락
	printf("몇단을 쌓으시겠습니까?\n");
	scanf_s("%d", &in);
	while (z <= in) {			//전체 형태의 상반신+중심
		while (zz < z) {		//한 다이아 뭉텅이 상반신※ 한 뭉텅이의 중심은 별 도배다. 따로 그린다
			if (a == 0) {		//맨 앞 부분 출발선//여기서 한줄 달리기 시작 왼쪽에서 오른쪽으로 별찍으며 달린다
				for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
					printf(" ");
				}
				a++;
			}
			for (int c = 1; c < 2 * a; c++) {		//*점찍기 전부 여기서 그린다
				printf("*");
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
					break;
				}
			}
			if (a == 0) {				//맨 오른쪽에 도달하면 다음줄로 간다
				printf("\n");
				ladder = 0;
				zz++;
			}
		}
		for (int b = (z - zz)*(z - zz) + (in - 1)*(in - 1) - (z - 1)*(z - 1); b >= 1; --b) {
			printf(" ");						//한 뭉텅이 중심의 출발선 ->모든 출발선과 조건과 같다
		}
		for (int e = 1; e <= (z - 1)*(z - 1) * 2 + 1; e++) {
			printf("*");		//중심 특유의 별도배//위와 같은 사이 간격 벌리기는 없다
		}
		printf("\n");
		zz--;								//한 뭉텅이의 반환점
		while (zz >= 2) {		//한 다이아 뭉텅이 하반신
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
	z--;									//전체 형태의 반환점
	z--;									//상반신과는 +-의 약간의 변경을 제외하고는 크게 차이가 없다
	while (z >= 2) {			//이제 전체 형태의 하반신-중심x 점점 뭉텅이가 작아진다
		while (zz < z) {		//한 뭉텅이의 상반신
			if (a == 0) {			//출발선
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
			printf(" ");			//한 뭉텅이 충심줄의 출발선
		}
		for (int e = 1; e <= (z - 1)*(z - 1) * 2 + 1; e++) {
			printf("*");			//한 뭉텅이 중심줄
		}
		printf("\n");
		zz--;								//뭉텅이 반환점
		while (zz >= 2) {		//뭉텅이 하반신
			if (a == 0) {			//뭉텅이 하반신 출발점
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
		printf(" ");				//마지막 출발선
	}
	printf("*");					//화 룡 점 점
	scanf_s("%d", &zzz);
}
