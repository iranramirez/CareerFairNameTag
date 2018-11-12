#include <Adafruit_GFX.h>F#include <TouchScreen.h>
#include <Adafruit_TFTLCD.h>

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

// calibration mins and max for raw data when touching edges of screen
// YOU CAN USE THIS SKETCH TO DETERMINE THE RAW X AND Y OF THE EDGES TO GET YOUR HIGHS AND LOWS FOR X AND Y
#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

//SPI Communication
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4

//Color Definitons
#define BLACK     0x0000
#define BLUE      0x001F
#define GREY      0xCE79
#define LIGHTGREY 0xDEDB
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define MAROON  0x8000

#define MINPRESSURE 1
#define MAXPRESSURE 1000

int X, Y, Z;

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
// Pins A2-A6

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

//2.4 = 240 x 320
//Height 319 to fit on screen

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup() {
  Serial.begin(9600);

  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  
  tft.setRotation(1);

  homeScreen();
}

void homeScreen(){

  //Background color
  tft.fillScreen(MAROON);

  /*Name, Major, Class Year*/
  //Name
  tft.setCursor(15,50);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("Iran Ramirez");

  //Major
  tft.setCursor(28,105);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("Major: ESET");

  //Class Year
  tft.setCursor(15,158);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("Class of '19");

  while(true){
    
    TSPoint p = ts.getPoint(); 

    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 240);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320);
    
    if ( p.z > ts.pressureThreshhold){

    Serial.print("X ="); Serial.print(p.x);
    Serial.print("\tY ="); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);
    
    if(p.x > 45 && p.x < 74 && p.y > 21 && p.y < 275){
      
      screenOne();
   }
  }
 }
}

void screenOne(){

  //Erase Screen
  tft.fillScreen(MAROON); 

  //Projects
  tft.setCursor(15,5);
  tft.setTextSize(4);
  tft.setTextColor(WHITE);
  tft.print("Projects");

  //Skills
  tft.setCursor(15,60);
  tft.setTextSize(4);
  tft.setTextColor(WHITE);
  tft.print("Skills");

  //Accomplishments
  tft.setCursor(15,115);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.print("Accomplishments");

  while(true){
    
    TSPoint p = ts.getPoint(); 

    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 240);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320);
    
    if ( p.z > ts.pressureThreshhold){

    Serial.print("X ="); Serial.print(p.x);
    Serial.print("\tY ="); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);
    
    if (p.x > 5 && p.x < 31 && p.y > 19 && p.y < 190){
      
      screenTwo();
      
      }

    else if (p.x > 53 && p.x < 85 && p.y > 19 && p.y < 147){

      screenThree();
      
    }

    else if (p.x > 104 && p.x < 131 && p.y > 19 && p.y < 264) {

      screenFour();
      
    }

    else{

      homeScreenDos();
      
    } 
    }
  }
}


void screenTwo(){

  //Erase Screen
  tft.fillScreen(MAROON); 

  //Assistive Technology
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Residential Automatic Doorusing voice recognition, \nRFID, or facial recognition for physically disabled");


   //Trash Compactor
   tft.setCursor(0,77);
   tft.setTextSize(2);
   tft.setTextColor(WHITE);
   tft.print("Created a model trashcan \nwith ultrasonic sensor andDC motors with a linear \nactuator to detect trash \nlevels and compact trash \nusing Alexa");

   //NameTag
   tft.setCursor(0,190);
   tft.setTextSize(3);
   tft.setTextColor(WHITE);
   tft.print("THIS NAMETAG");

   goTo();
}

void screenThree(){

  //Erase Screen
  tft.fillScreen(MAROON); 

  //Software
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Software: \nMicrosoft Office, MATLAB  AutoDesk Inventor & Eagle Git");

  //ProgrammingLanguages
  tft.setCursor(0,77);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Proficient: \nPython and C \n\nExposure: \nFlask, Java, Andriod, HTMLCSS");

  //Languages
  tft.setCursor(0,190);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Fluent in Spanish");

  goTo();
}

void screenFour(){

  //Erase Screen
  tft.fillScreen(MAROON); 

  //Projects
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("2 Time 1st Place Winner \n@ Aggies Invent");

  //Projects
  tft.setCursor(0,60);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("1st Place Winner \n@ TAMUMake");

  //Projects
  tft.setCursor(0,110);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Top 3 Teller in district \nfor 3 consecutive months \nfor referrals \n\nOffered promotion from \npart-time teller to \nPersonal Banker within \nless than a year");

  goTo();
  
}

void goTo(){

  while(true){
    
    TSPoint p = ts.getPoint(); 

    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 240);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320);
    
    if ( p.z > ts.pressureThreshhold){

    Serial.print("X ="); Serial.print(p.x);
    Serial.print("\tY ="); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);
    
    if (p.x > 0 && p.x < 285 && p.y > 0 && p.y < 219){
      
      screenOne();
      
      }
    } 
  }
}

void homeScreenDos(){

  //Background color
  tft.fillScreen(MAROON);

  /*Name, Major, Class Year*/
  //Name
  tft.setCursor(15,50);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("Iran Ramirez");

  //Major
  tft.setCursor(28,105);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("Major: ESET");

  //Class Year
  tft.setCursor(15,158);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("Class of '19");

  while(true){
    
    TSPoint p = ts.getPoint(); 

    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 240);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320);
    
    if ( p.z > ts.pressureThreshhold){

    Serial.print("X ="); Serial.print(p.x);
    Serial.print("\tY ="); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);
    
    if(p.x > 45 && p.x < 74 && p.y > 21 && p.y < 275){
      
      screenOne();
   }
  }
 }
}

