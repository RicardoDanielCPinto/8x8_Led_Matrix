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

const char str1[] = "Sly Cooper 2";

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

void setup(void) {
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

void loop(void) {
  int i=-1;
  while(1){
    i++;
    if(i>sizeof(str1)/sizeof(char)) i=-1;
    int now = select_char(str1[i]);
    letter_to_matrix(letters[now], 1);
    int next = select_char(str1[i+1]);
    letter_to_matrix(letters[next], 2);
    memcpy(m,mat1,sizeof(m));
    delay(100);
    for(int k=9;k>0;k--){
      for(int j = 7; j>=0; j--){
        if(j>0){
          m[j][0] = m[j-1][0];
          m[j][1] = m[j-1][1];
          m[j][2] = m[j-1][2];
          m[j][3] = m[j-1][3];
          m[j][4] = m[j-1][4];
          m[j][5] = m[j-1][5];
          m[j][6] = m[j-1][6];
          m[j][7] = m[j-1][7];
        }else if(k>=8){
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
      delay(100);
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
    int num = x[i];
    for (int j = 0; j <= 7; j++){
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
  digitalWrite(R0, bin1[0]);
  digitalWrite(R1, bin1[1]);
  digitalWrite(R2, bin1[2]);
  digitalWrite(C0, bin2[0]);
  digitalWrite(C1, bin2[1]);
  digitalWrite(C2, bin2[2]);
  digitalWrite(EN, m[col][row]);
  TCNT1 = 0xF000;                               // Renicia TIMER
}
