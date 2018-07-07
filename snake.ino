#define R0 4
#define R1 3
#define R2 2
#define C0 A3
#define C1 A4
#define C2 A5
#define EN 5

volatile int row = 0;
volatile int col = 0;
volatile int m[8][8];
volatile int mat1[8][8];
volatile int mat2[8][8];
int field[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const int _SPACE[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const int _A[] = {B00011000,B00100100,B01000010,B10000001,B11111111,B10000001,B10000001,B10000001};
const int _B[] = {B11111110,B10000001,B10000001,B11111110,B11111110,B10000001,B10000001,B11111110};
const int _C[] = {B00111111,B01000000,B10000000,B10000000,B10000000,B10000000,B01000000,B00111111};
const int _D[] = {B11111100,B10000010,B10000001,B10000001,B10000001,B10000001,B10000010,B11111100};
const int _E[] = {B11111111,B10000000,B10000000,B11111000,B11111000,B10000000,B10000000,B11111111};
const int _F[] = {B11111111,B10000000,B10000000,B11111000,B11111000,B10000000,B10000000,B10000000};
const int _G[] = {B01111110,B10000001,B10000000,B10000000,B10011110,B10000001,B10000001,B01111110};
const int _H[] = {B10000001,B10000001,B10000001,B11111111,B11111111,B10000001,B10000001,B10000001};
const int _I[] = {B11111111,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000,B11111111};
const int _J[] = {B11111111,B00000100,B00000100,B00000100,B00000100,B00100100,B00100100,B00011000};
const int _K[] = {B10000001,B10000001,B10000010,B11111100,B11111000,B10000100,B10000010,B10000010};
const int _L[] = {B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01111110};
const int _M[] = {B10000001,B11000011,B10100101,B10011001,B10000001,B10000001,B10000001,B10000001};
const int _N[] = {B10000001,B11000001,B10100001,B10010001,B10001001,B10000101,B10000011,B10000001};
const int _O[] = {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
const int _P[] = {B11111110,B10000001,B10000001,B11111110,B10000000,B10000000,B10000000,B10000000};
const int _Q[] = {B00111100,B01000010,B10000001,B10000001,B10001001,B10000111,B01000110,B00111101};
const int _R[] = {B11111100,B10000010,B10000001,B10000010,B11111100,B10001000,B10000100,B10000010};
const int _S[] = {B01111110,B10000001,B10000000,B01111110,B00000001,B00000001,B10000001,B01111110};
const int _T[] = {B11111111,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000};
const int _U[] = {B10000001,B10000001,B10000001,B10000001,B10000001,B10000001,B10000001,B01111110};
const int _V[] = {B10000001,B10000001,B10000001,B01000010,B01000010,B00100100,B00100100,B00011000};
const int _W[] = {B10000001,B10000001,B10000001,B10000001,B10011001,B10100101,B11000011,B10000001};
const int _X[] = {B10000001,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B10000001};
const int _Y[] = {B10000001,B01000010,B00100100,B00011000,B00011000,B00011000,B00011000,B00011000};
const int _Z[] = {B11111111,B00000010,B00000100,B00001000,B00010000,B00100000,B01000000,B11111111};
const int _ZERO[] = {B01111110,B11000001,B10100001,B10010001,B10001001,B10000101,B10000011,B01111110};
const int _UM[] = {B00011000,B00101000,B01001000,B00001000,B00001000,B00001000,B00001000,B11111111};
const int _DOIS[] = {B01111110,B10000001,B10000001,B00000010,B00001100,B00110000,B01000000,B11111111};
const int _TRES[] = {B01111100,B10000010,B00000010,B00001100,B00001100,B00000010,B10000010,B01111100};
const int _QUATRO[] = {B00000100,B00001100,B00010100,B00100100,B01000100,B11111111,B00000100,B00000100};
const int _CINCO[] = {B11111111,B10000000,B10000000,B11111110,B00000011,B00000001,B00000011,B11111110};
const int _SEIS[] = {B01111110,B10000001,B10000000,B11111110,B10000001,B10000001,B10000001,B01111110};
const int _SETE[] = {B11111111,B00000001,B00000001,B00000010,B00000100,B00001000,B00010000,B00100000};
const int _OITO[] = {B01111110,B10000001,B10000001,B01111110,B10000001,B10000001,B10000001,B01111110};
const int _NOVE[] = {B01111110,B10000001,B10000001,B01111110,B00000001,B00000001,B00000001,B01111110};
const int _HEART[] = {B01100110,B11111111,B11111111,B11111111,B11111111,B01111110,B00111100,B00011000};
const int A = 0;const int B = 1;const int C = 2;const int D = 3;const int E = 4;const int F = 5;const int G = 6;const int H = 7;
const int I = 8;const int J = 9;const int K = 10;const int L = 11;const int M = 12;const int N = 13;const int O = 14;const int P = 15;
const int Q = 16;const int R = 17;const int S = 18;const int T = 19;const int U = 20;const int V = 21;const int W = 22;const int X = 23;
const int Y = 24;const int Z = 25;const int SPACE = 26;const int HEART = 27;const int ZERO = 28;const int UM = 29;const int DOIS = 30;
const int TRES = 31;const int QUATRO = 32;const int CINCO = 33;const int SEIS = 34;const int SETE = 35;const int OITO = 36;const int NOVE = 37;
const int* letters[] = {_A, _B, _C, _D, _E, _F, _G, _H, _I, _J, _K, _L, _M, _N, _O, _P, _Q, _R, _S, _T, _U, _V, _W, _X, _Y, _Z, _SPACE, _HEART, _ZERO, _UM, _DOIS, _TRES, _QUATRO, _CINCO, _SEIS, _SETE, _OITO, _NOVE};


struct Coordenates{
    int x;
    int y;
};
struct Snake_game{
    bool play = true;
    int len = 3;
    Coordenates* body = malloc(3 * sizeof(Coordenates));
    char dir = 'd'; //w a s d
    Coordenates coin;
    bool grow = false;
};

volatile Snake_game game;

void setup() {
  Serial.begin(9600);
  // Configuração do timer1
  TCCR1A = 0;                        //configura o timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;                        //limpa registo
  TCCR1B |= (0 << CS12 | 0 << CS11 | 1 << CS10 );            // configura prescaler para 1: CS12 = 0, CS11 = 0, CS10 = 1
  TCNT1 = 0xF000;                   // 65536-(16MHz/PRESCALER/1Hz) = 49911 = 0xC2F7
  TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
  pinMode(R0, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(C0, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(EN, OUTPUT);
}

void loop() {
  Snake_game game2;
  game = game2;
  for(int i=0; i<game.len; i++){
    game.body[i].x = game.len-1-i;
    game.body[i].y = 4;
  }
  randomSeed(analogRead(A7));
  game.play = true;
  game.coin = {random(8), random(8)};
  game.dir = 'd';
  while(game.play){
    refresh();
    char c =' ';
    if(Serial.available()){
      c = Serial.read();
    }
    for(int i = 1; i<game.len; i++){
      if((game.body[0].x == game.body[i].x) and (game.body[0].y == game.body[i].y)){
        game.play = false;
      }
    }
    if((c!=' ') and (c != game.dir)) changedir(c);
    move_foward();
    delay(200);
  }
  efeito(4,20);
  delay(200);
  slide("GAME OVER");
  efeito(2,20);
  delay(300);
  efeito(3,20);
  delay(300);
  efeito(1,0);
  delay(300);
  efeito(0,0);
  delay(300);
}

void slide(String s){
  for(int i=0; i<s.length(); i++ ){
    int now = select_char(s[i]);
    letter_to_matrix(letters[now], 1);
    int next = select_char(s[i+1]);
    letter_to_matrix(letters[next], 2);
    memcpy(m,mat1,sizeof(m));
    for(int k=-2;k<=7;k++){
      for(int j = 0; j<=7; j++){
        if(j<7){
          m[j][0] = m[j+1][0];
          m[j][1] = m[j+1][1];
          m[j][2] = m[j+1][2];
          m[j][3] = m[j+1][3];
          m[j][4] = m[j+1][4];
          m[j][5] = m[j+1][5];
          m[j][6] = m[j+1][6];
          m[j][7] = m[j+1][7];
        }else if(k<0){
          m[j][0] = 0;
          m[j][1] = 0;
          m[j][2] = 0;
          m[j][3] = 0;
          m[j][4] = 0;
          m[j][5] = 0;
          m[j][6] = 0;
          m[j][7] = 0;
          }
          else{
            m[j][0] = mat2[k][0];
            m[j][1] = mat2[k][1];
            m[j][2] = mat2[k][2];
            m[j][3] = mat2[k][3];
            m[j][4] = mat2[k][4];
            m[j][5] = mat2[k][5];
            m[j][6] = mat2[k][6];
            m[j][7] = mat2[k][7];
          }
      }
      delay(50);
    }
  }
}
int select_char(char c){
  switch(c){
    case 'A':case 'a':return A;
    case 'B':case 'b':return B;
    case 'C':case 'c':return C;
    case 'D':case 'd':return D;
    case 'E':case 'e':return E;
    case 'F':case 'f':return F;
    case 'G':case 'g':return G;
    case 'H':case 'h':return H;
    case 'I':case 'i':return I;
    case 'J':case 'j':return J;
    case 'K':case 'k':return K;
    case 'L':case 'l':return L;
    case 'M':case 'm':return M;
    case 'N':case 'n':return N;
    case 'O':case 'o':return O;
    case 'P':case 'p':return P;
    case 'Q':case 'q':return Q;
    case 'R':case 'r':return R;
    case 'S':case 's':return S;
    case 'T':case 't':return T;
    case 'U':case 'u':return U;
    case 'V':case 'v':return V;
    case 'W':case 'w':return W;
    case 'X':case 'x':return X;
    case 'Y':case 'y':return Y;
    case 'Z':case 'z':return Z;
    case '1':return UM;
    case '2':return DOIS;
    case '3':return TRES;
    case '4':return QUATRO;
    case '5':return CINCO;
    case '6':return SEIS;
    case '7':return SETE;
    case '8':return OITO;
    case '9':return NOVE;
    case '0':return ZERO;
    case ' ':return SPACE;
    case '/':return HEART;
    default: return SPACE;
  }
}

void letter_to_matrix(int* x, int matrix){
  for(int i=0; i<=7; i++){
    int num = x[7-i];
    for (int j = 7; j >= 0; j--){
      if (num % 2 == 0){
        if(matrix==1)mat1[j][i] = 0;
        else mat2[j][i] = 0;
      }
      else{
        if(matrix==1)mat1[j][i] = 1;
        else mat2[j][i] = 1;
      }
      num = num / 2;
    }
  }
}

void efeito(int i, int d){
  int r,c;
  char s[2]={0,0};
  switch(i){
    case 0: //apagar leds
      for(r = 0; r<8; r++)
        for(c=0;c<8;c++){
          m[r][c]=0;
          }
      delay(d);
      break;
    case 1: //acende leds
      for(r = 0; r<8; r++)
        for(c=0;c<8;c++){
          m[r][c]=1;
          }
      delay(d);
      break;
    case 2: //efeito crescente negador
      s[0] = -1;
      while(!(s[0]==7 && s[1]==7)){
        s[0] ++;
        if(s[0]>7){
          s[0] = 0;
          s[1]++;
          if(s[1]>7)s[1]=0;
        }
      m[s[0]][s[1]] = !m[s[0]][s[1]];
      delay(d);
      }
      break;
    case 3:
      s[0] = 8;
      s[1] = 7;
      while(!(s[0]==0 && s[1]==0)){
        s[0] --;
        if(s[0]<0){
          s[0] = 7;
          s[1]--;
          if(s[1]<0)s[1]=7;
        }
      m[s[0]][s[1]] = !m[s[0]][s[1]];
      delay(d);
      }
      break;
    case 4: //efeito crescente negador
      s[0] = -1;
      while(!(s[0]==7 && s[1]==7)){
        s[0] ++;
        if(s[0]>7){
          s[0] = 0;
          s[1]++;
          if(s[1]>7)s[1]=0;
        }
      m[s[0]][s[1]] = 1;
      delay(d);
      }
      break;
    }
  }

void coin_sort(void){
  bool ok = false;
  while(!ok){
    game.coin.x = random(8);
    game.coin.y = random(8);
    ok = true;
    for(int i=0; i<game.len; i++){
      if((game.body[i].x == game.coin.x) and (game.body[i].y == game.coin.y)){
        ok = false;
      }
    }
  }
}

void move_foward(void){
    if(game.grow){
      game.body[game.len-1].x = game.body[game.len-2].x;
      game.body[game.len-1].y = game.body[game.len-2].y;
      }
    Coordenates tmp;
    switch(game.dir){
      case 'w': tmp = {game.body[0].x, game.body[0].y+1}; break;
      case 'a': tmp = {game.body[0].x-1, game.body[0].y}; break;
      case 's': tmp = {game.body[0].x, game.body[0].y-1}; break;
      case 'd': tmp = {game.body[0].x+1, game.body[0].y}; break;
      }
    if(tmp.x <= -1) tmp.x = 7;
    if(tmp.x >= 8) tmp.x = 0;
    if(tmp.y <= -1) tmp.y = 7;
    if(tmp.y >= 8) tmp.y = 0;
    for(int i=game.len-1; i>0; i--){
        game.body[i].x = game.body[i-1].x;
        game.body[i].y = game.body[i-1].y;
      }
    game.body[0].x = tmp.x;
    game.body[0].y = tmp.y;
    game.grow = false;
    if(tmp.x == game.coin.x and tmp.y == game.coin.y){
      coin_sort();
      game.len++;
      realloc(game.body, game.len * sizeof(Coordenates));
      game.grow = true;
    }
  }

void changedir(char c){
    switch(c){
      case 'w':
      case 'W':
        if(game.dir != 's')game.dir = 'w';
        break;
      case 'a':
      case 'A':
        if(game.dir != 'd')game.dir = 'a';
        break;
      case 's':
      case 'S':
        if(game.dir != 'w')game.dir = 's';
        break;
      case 'd':
      case 'D':
        if(game.dir != 'a')game.dir = 'd';
        break;
      default:
        Serial.println("Invalid direction, try, W,A,S e D");
        break;
      }
  }

void refresh(void){
    efeito(0,0);
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
          for(int k=0; k<game.len; k++){
            if(game.body[k].x == i and game.body[k].y == j) m[i][j]=1;
          }
      }
    }
    m[game.coin.x][game.coin.y] = 1;
  }

ISR(TIMER1_OVF_vect)                              //interrupção do TIMER1
{
  row ++;
  if (row > 7) {
    row = 0;
    col++;
    if(col>7) col = 0;
  }
  int bin1[3];
  int bin2[3];
  int num1 = row;
  int num2 = col;
  for (int i = 0; i <= 2; i++)
  {
    if (num1 % 2 == 0){ bin1[i] = 0;}
    else{ bin1[i] = 1;}
    
    if (num2 % 2 == 0){ bin2[i] = 0;}
    else{ bin2[i] = 1;}
    
    num1 = num1 / 2;
    num2 = num2 / 2;
  }
  bool b = false;
  for(int i=0; i < game.len; i++){
    b = (game.body[i].x == col) and (game.body[i].y == row);
    if(b)break;
  }
  if((game.coin.x == col) and (game.coin.y == row)) b = true;
  
  digitalWrite(R0, bin1[0]);
  digitalWrite(R1, bin1[1]);
  digitalWrite(R2, bin1[2]);
  digitalWrite(C0, bin2[0]);
  digitalWrite(C1, bin2[1]);
  digitalWrite(C2, bin2[2]);
  digitalWrite(EN, m[col][row]);
  TCNT1 = 0xF000;                               // Renicia TIMER
}

