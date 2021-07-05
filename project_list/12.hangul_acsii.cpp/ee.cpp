#include <iostream>
#include <queue>
#include <string>
using namespace std;

string ja[14] = {"ㄱ","ㄴ","ㄷ","ㄹ","ㅁ","ㅂ","ㅅ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ"};
string mo[14] = {"ㅏ","ㅑ","ㅓ","ㅕ","ㅗ","ㅛ","ㅜ","ㅠ","ㅡ","ㅣ","ㅐ","ㅔ","ㅒ","ㅖ"};

string ha[14][14] = {
  {"가","갸","거","겨","고","교","구","규","그","기","개","게","걔","계"},
  {"나","냐","너","녀","노","뇨","누","뉴","느","니","내","네","냬","녜"},
  {"다","댜","더","뎌","도","됴","두","듀","드","디","대","데","댸","뎨"},
  {"라","랴","러","려","로","료","루","류","르","리","래","레","럐","례"},
  {"마","먀","머","며","모","묘","무","뮤","므","미","매","메","먜","몌"},
  {"바","뱌","버","벼","보","뵤","부","뷰","브","비","배","베","뱨","볘"},
  {"사","샤","서","셔","소","쇼","수","슈","스","시","새","세","섀","셰"},
  {"아","야","어","여","오","요","우","유","으","이","애","에","얘","예"},
  {"자","쟈","저","져","조","죠","주","쥬","즈","지","재","제","쟤","졔"},
  {"차","챠","처","쳐","초","쵸","추","츄","츠","치","채","체","챼","쳬"},
  {"카","캬","커","켜","코","쿄","쿠","큐","크","키","캐","케","컈","켸"},
  {"타","탸","터","텨","토","툐","투","튜","트","티","태","테","턔","톄"},
  {"파","퍄","퍼","펴","포","표","푸","퓨","프","피","패","페","퍠","폐"},
  {"하","햐","허","혀","호","효","후","휴","흐","히","해","헤","햬","혜"}
};
int main(){
  string input;
  queue<string> line;
  getline(cin,input);
  for(int a=0;a<input.size();a++){
    line.push(ha[input.at(a)%14][input.at(a)/14]);
  }
  while(!line.empty()){
    cout<<line.front();
    line.pop();
  }
}
/*
line.push(ja[input.at(a)/14]);
line.push(mo[input.at(a)%14]);*/
