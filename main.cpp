#include"mbed.h" 
 
DigitalOut clk(p27);  
DigitalOut rst(p28);  
DigitalOut data(p30); 
 
void EdgeClock(){ 
 wait(0.000001); 
 clk = 1; 
 wait(0.000001); 
 clk=0; 
  
} 
int main(){ 
 rst = 0; 
 EdgeClock(); 
 rst = 1; 
 EdgeClock(); 
  
 int arr[16][8] = {  {1,1,0,0,0,0,0,0}, //0 
      {1,1,1,1,1,0,0,1}, //1 
      {1,0,1,0,0,1,0,0}, //2 
      {1,0,1,1,0,0,0,0}, //3 
      {1,0,0,1,1,0,0,1}, //4 
      {1,0,0,1,0,0,1,0}, //5 
      {1,0,0,0,0,0,1,0}, //6 
      {1,1,1,1,1,0,0,0}, //7 
      {1,0,0,0,0,0,0,0}, //8 
      {1,0,0,1,1,0,0,0}, //9
			{1,0,0,0,1,0,0,0}, //A
 			{1,0,0,0,0,0,1,1}, //B
			{1,1,0,0,0,1,1,0}, //C
			{1,0,1,0,0,0,0,1}, //D
			{1,0,0,0,0,1,1,0}, //E
			{1,0,0,0,1,1,1,0}}; //F
			
      //{0,1,1,1,1,1,1,1}}; //dot 
			
  
 int dot[2][8] =  {{0,1,1,1,1,1,1,1}, //dot ON 
      {1,1,1,1,1,1,1,1}}; //dot OFF 
        
 
while(1){ 
 for (int a = 0; a < 16; a++){ 
  for(int i = 0; i < 16; i++){ 
   for (int j = 0; j < 8 ; j++) { 
     data = arr[i][j]; 
     EdgeClock(); 
    } 
     
    for (int j = 0; j < 8 ; j++) { 
     data = arr[a][j]; 
     EdgeClock(); 
    }   
    wait(0.05); 
   }// end for 
 } 
//Blink dots protocal 
for (int a = 1; a >= 0 ; a--){   
 for (int b = 0; b < 8; b++){ 
    data = dot[a][b]; 
    EdgeClock(); 
    } 
   } 
  wait(0.25); 
for (int a = 0; a < 2 ; a++){   
 for (int b = 0; b < 8; b++){ 
    data = dot[a][b]; 
    EdgeClock(); 
    } 
   } 
  wait(0.25); 
}//end while 
           
 
}//end main