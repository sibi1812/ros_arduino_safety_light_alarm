#include <ros.h> // ros header file
#include <std_msgs/Float32.h> // float32 header file
#define red_led 3 // PIN 3 for Red led
#define yellow_led 9 // PIN 9 for yellow led
#define green_led 12 // PIN 12 for green led

ros::NodeHandle nh; //ros nodehandle
// defining the datatypes
std_msgs::Float32 red_led_msg; 
std_msgs::Float32 yellow_led_msg;
std_msgs::Float32 green_led_msg;
// callback for red LED
void red_led_Callback(const std_msgs::Float32& red_led_msg) {
  if (red_led_msg.data  == 1.0) {
    digitalWrite(red_led, HIGH);
    delay(250);
    digitalWrite(red_led, LOW);
    delay(250); 
  } else {
    digitalWrite(red_led, LOW);
  }
}
// callback for yellow LED
void yellow_led_Callback(const std_msgs::Float32& yellow_led_msg) {
  if (yellow_led_msg.data  == 1.0) {
    digitalWrite(yellow_led, HIGH);
    delay(250);
    digitalWrite(yellow_led, LOW); 
    delay(250);
  } else {
    digitalWrite(yellow_led, LOW);
  }
}
// callback for Green LED
void green_led_Callback(const std_msgs::Float32& green_led_msg) {
  
  digitalWrite(green_led, HIGH);
  if (green_led_msg.data  == 1) {
    digitalWrite(green_led, HIGH);
    
  } else {
    digitalWrite(green_led, LOW);
  }
}
//  subscriber for Three LED
ros::Subscriber<std_msgs::Float32> red_led_subscriber("toggle_red_led",&red_led_Callback);
ros::Subscriber<std_msgs::Float32> yellow_led_subscriber("toggle_yellow_led",&yellow_led_Callback);
ros::Subscriber<std_msgs::Float32> green_led_subscriber("toggle_green_led",green_led_Callback);

void setup()
{
  // setting the LED output connection
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  // declaring the subscriber 
  nh.initNode();
  nh.subscribe(red_led_subscriber);
  nh.subscribe(yellow_led_subscriber);
  nh.subscribe(green_led_subscriber);
}

void loop()
{ 
  nh.spinOnce();
}
