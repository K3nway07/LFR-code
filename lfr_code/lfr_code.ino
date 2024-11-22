//#define Kp 1.88
//#define Kd 0
 int a[]={A0,A1,A2,A3,A4,A5,2,3};
 int w=1,bl=0,light;
int e,le=0,sp,lf=0,rf=0;
void setup() {
  // put your setup code here, to run once:
 
  pinMode(a[0], INPUT);
  pinMode(a[1], INPUT);
  pinMode(a[2], INPUT);
  pinMode(a[3], INPUT);
  pinMode(a[4], INPUT);
  pinMode(a[5], INPUT);
  pinMode(a[6], INPUT);
  pinMode(a[7], INPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13,OUTPUT);
  le=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(7,LOW);
  int b[8];
  int i;
  for(i=0;i<8;i++)
  {
    b[i]=digitalRead(a[i]);
  }
//inversion
//  if((b[7]==1 && b[6]==1 && b[4]==0 && b[3]==0 && b[1]==1 && b[0]==1)||(b[7]==1 && b[6]==1 && b[4]==1 && b[3]==0 && b[1]==1 && b[0]==1)||(b[7]==1 && b[6]==1 && b[4]==0 && b[3]==1 && b[1]==1 && b[0]==1)){
//    w=1;
//    bl=0;
//  }
//  if((b[7]==0 && b[6]==0 && b[4]==1 && b[3]==1 && b[1]==0 && b[0]==0)||(b[7]==0 && b[6]==0 && b[4]==0 && b[3]==1 && b[1]==0 && b[0]==0)||(b[7]==0 && b[6]==0 && b[4]==1 && b[3]==0 && b[1]==0 && b[0]==0)){
//    w=0;
//    bl=1;
//  }

  if((b[7]==w && b[6]==w && b[5]==w && b[4]==bl && b[3]==bl && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==bl && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==bl && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==bl && b[6]==bl && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==bl && b[0]==bl)||
  (b[7]==w && b[6]==bl && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==bl && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==w && b[0]==w)){
  e=0;
  if((b[7]==bl && b[6]==bl && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==bl && b[0]==bl)||
  (b[7]==w && b[6]==bl && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==bl && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==w && b[0]==w))
  light=1;
  }
  else if((b[7]==w && b[6]==w && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==bl && b[4]==bl && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==bl && b[4]==w && b[3]==w && b[2]==w && b[1]==w && b[0]==w))
  e=1;
  else if((b[7]==w && b[6]==w && b[5]==w && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==bl && b[2]==bl && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==w && b[2]==bl && b[1]==w && b[0]==w))
  e=-1;
  else if((b[7]==w && b[6]==bl && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==bl && b[5]==bl && b[4]==bl && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==bl && b[5]==bl && b[4]==w && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==w && b[6]==bl && b[5]==w && b[4]==w && b[3]==w && b[2]==w && b[1]==w && b[0]==w))
  e=2;
  else if((b[7]==w && b[6]==w && b[5]==w && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==bl && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==bl && b[2]==bl && b[1]==bl && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==w && b[2]==bl && b[1]==bl && b[0]==w)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==w && b[2]==w && b[1]==bl && b[0]==w))
  e=-2;
  else if((b[7]==bl && b[6]==bl && b[5]==bl && b[4]==bl && b[3]==bl && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==bl && b[6]==bl && b[5]==bl && b[4]==bl && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==bl && b[6]==bl && b[5]==bl && b[4]==w && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==bl && b[6]==bl && b[5]==w && b[4]==w && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
  (b[7]==bl && b[6]==w && b[5]==w && b[4]==w && b[3]==w && b[2]==w && b[1]==w && b[0]==w))
  e=3;
  else if((b[7]==w && b[6]==w && b[5]==w && b[4]==bl && b[3]==bl && b[2]==bl && b[1]==bl && b[0]==bl)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==bl && b[2]==bl && b[1]==bl && b[0]==bl)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==w && b[2]==bl && b[1]==bl && b[0]==bl)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==w && b[2]==w && b[1]==bl && b[0]==bl)||
  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==w && b[2]==w && b[1]==w && b[0]==bl))
  e=-3;
//  else if((b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==bl && b[2]==w && b[1]==bl && b[0]==w)||
//  (b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==bl && b[2]==w && b[1]==w && b[0]==bl)||
//  (b[7]==w && b[6]==w && b[5]==w && b[4]==bl && b[3]==bl && b[2]==w && b[1]==bl && b[0]==w)||
//  (b[7]==w && b[6]==w && b[5]==w && b[4]==bl && b[3]==bl && b[2]==w && b[1]==w && b[0]==bl))
//  e=-4;
//  else if((b[7]==w && b[6]==bl && b[5]==w && b[4]==bl && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
//  (b[7]==bl && b[6]==w && b[5]==w && b[4]==bl && b[3]==w && b[2]==w && b[1]==w && b[0]==w)||
//  (b[7]==w && b[6]==bl && b[5]==w && b[4]==bl && b[3]==bl && b[2]==w && b[1]==w && b[0]==w)||
//  (b[7]==bl && b[6]==w && b[5]==w && b[4]==bl && b[3]==bl && b[2]==w && b[1]==w && b[0]==w))
//  e=4;
  sp=12*e;
  le=e;
  if(e==0)
  {
    lf=0;
    rf=0;
    analogWrite(9,110);
    analogWrite(6,110);
    if(light==1){
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    
    }
    light=0;
   
  }
 else if(e==2 ||e==1||e==3)
 {
 analogWrite(6,0);
  analogWrite(9,110+sp);
  lf=1;
  rf=0; 
 }
// else if(e==3){
// analogWrite(6,0);
//  analogWrite(9,130+(15*e)); 
// }
 else if(e==-2 ||e==-1||e==-3)
 {
   analogWrite(6,110-sp);
  analogWrite(9,0);
  lf=0;
  rf=1;
 }
// else if(e==-3){
//  analogWrite(6,130-(15*e));
//  analogWrite(9,0);
// }
// if(b[7]==w && b[6]==w && b[5]==w && b[4]==w && b[3]==w && b[2]==w && b[1]==w && b[0]==w){
// if(lf==0 && rf==1)
// {
//   analogWrite(6,100-sp);
//  analogWrite(9,0);
// }
// else if(lf==1 && rf==0)
// {
//  analogWrite(6,0);
//  analogWrite(9,100+sp);
// }
// else if(lf==0 && rf==0){
//  analogWrite(9,100);
//    analogWrite(6,100);
// }
// }
}
