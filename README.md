"#https://www.acmicpc.net/step"
"#����"
C:\Users\�����\AppData\Local\atom\app-1.52.0\resources\app.asar.unpacked\node_modules\dugite\git\mingw64\bin
��atom �ȿ� git ��ġ

typedef struct{
  int a;
  int b;
  int ** map;
}block;

block maze;

�̶� maze�� value�ν� �����Ѵٸ� ����� dot operator�� �ҷ��� �� ����
�׷��� maze�� parameter���� pointer�μ� �����Դٸ� ����� -> operator�� �����;���

���� ������ max_val = (x>y)?x:y
?x -> �� x>y�� �´ٸ� max_val�� x�� ���� ������
:y -> �� x>y�� Ʋ���ٸ� max_val�� y�� ���� ������
