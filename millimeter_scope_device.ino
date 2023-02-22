// C++ code
//
#define trig 9
#define echo 12
long d=0,t=0;
byte pins[8]={8,7,6,5,4,3,2,1};
byte disp[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0} // 9
};

void presNum(byte num){
  for(int i=0;i<sizeof(pins);i++)
    digitalWrite(*(pins+i),*(*(disp+num)+i)); 
}
void ultrasonic(){
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);
  t=pulseIn(echo,1);
  d=t*0.0343/2;
}

void setup()
{
  for(int i=0;i<9;i++)
    pinMode(pins[i],OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop()
{
	ultrasonic();
  Serial.println(d);
  presNum((d<100)?(int(float(d)/10.0)):0);
  //if(d<100)presNum(int(float(d)/10.0));
  
}





