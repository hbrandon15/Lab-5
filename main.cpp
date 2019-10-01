#include"mbed.h" 
 
DigitalOut clk(p27);  //Clock pin
DigitalOut rst(p28);  //Reset|Clear pin
DigitalOut data(p30); //Data pin
 
void EdgeClock(){ //Setting function for Clock
 wait(0.000001); 
 clk = 1; 
 wait(0.000001); 
 clk=0; 
  
} 
int main(){ 
 rst = 0; //Reset is set to 0, ready to take data
 EdgeClock(); //Clock sequence 
 rst = 1; //reset
 EdgeClock(); //Clock sequence
  
 
 //We are using negative logic!!
 int arr[10][8] = {  
  
    //{D,g,f,e,d,c,b,a} 
  
      {1,1,0,0,0,0,0,0}, //0 
      {1,1,1,1,1,0,0,1}, //1 
      {1,0,1,0,0,1,0,0}, //2 
      {1,0,1,1,0,0,0,0}, //3 
      {1,0,0,1,1,0,0,1}, //4 
      {1,0,0,1,0,0,1,0}, //5 
      {1,0,0,0,0,0,1,0}, //6 
      {1,1,1,1,1,0,0,0}, //7 
      {1,0,0,0,0,0,0,0}, //8 
      {1,0,0,1,1,0,0,0}}; //9 
      //{0,1,1,1,1,1,1,1}}; //dot 
  
 //We are displaying the decimal last
 int dot[2][8] =  {{0,1,1,1,1,1,1,1}, //dot ON 
      {1,1,1,1,1,1,1,1}}; //dot OFF 
        
 //Execute while logic=1
while(1){ 
 for (int a = 0; a < 10; a++){ 
  for(int i = 0; i < 10; i++){ 
   for (int j = 0; j < 8 ; j++) { 
     data = arr[i][j]; 
     EdgeClock(); 
    } 
     
    for (int j = 0; j < 8 ; j++) { 
     data = arr[a][j]; 
     EdgeClock(); 
    }   
    wait(0.1); 
   }// end for 
 } 
//Blink dots protocal 
for (int a = 1; a >= 0 ; a--){   
 for (int b = 0; b < 8; b++){ 
    data = dot[a][b]; 
    EdgeClock(); 
    } 
   } 
  wait(0.5); 
for (int a = 0; a < 2 ; a++){   
 for (int b = 0; b < 8; b++){ 
    data = dot[a][b]; 
    EdgeClock(); 
    } 
   } 
  wait(0.5); 
}//end while 
           
 
}//end main
