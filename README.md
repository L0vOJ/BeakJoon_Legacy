"#https://www.acmicpc.net/step"
"#들어가라"
C:\Users\정재원\AppData\Local\atom\app-1.52.0\resources\app.asar.unpacked\node_modules\dugite\git\mingw64\bin
ㄴatom 안에 git 위치

typedef struct{
  int a;
  int b;
  int ** map;
}block;

block maze;

이때 maze가 value로써 존재한다면 멤버를 dot operator로 불러올 수 있음
그러나 maze를 parameter에서 pointer로서 가져왔다면 멤버를 -> operator로 가져와야함

조건 연산자 max_val = (x>y)?x:y
?x -> 앞 x>y가 맞다면 max_val은 x의 값을 가진다
:y -> 앞 x>y가 틀리다면 max_val은 y의 값을 가진다
