#include "M5StickCPlus2.h"
#include "BluetoothSerial.h"
#include "MadgwickAHRS.h"

Madgwick MadgwickFilter;

float roll  = 0.0F;                                           // ロール格納用
float pitch = 0.0F;                                           // ピッチ格納用
float yaw   = 0.0F;                                           // ヨー格納用

const float pi = 3.1415;

bool before_off = true;
bool sw;

BluetoothSerial bts;



void setup() {
    auto cfg = M5.config();
    StickCP2.begin(cfg);
    StickCP2.Display.setRotation(1);
    StickCP2.Display.setTextColor(GREEN);
    StickCP2.Display.setTextDatum(middle_center);
    StickCP2.Display.setFont(&fonts::FreeSansBold9pt7b);
    StickCP2.Display.setTextSize(1);
    Serial.begin(115200);
    MadgwickFilter.begin(200);
    pinMode(26,INPUT_PULLUP);//スイッチがオンのとき0,スイッチがオフのとき1
    bts.begin("M5-stickC-plus2");
}

void loop(void) {
    auto imu_update = StickCP2.Imu.update();
    if (imu_update) {
        StickCP2.Display.setCursor(0, 40);
        StickCP2.Display.clear();

        auto data = StickCP2.Imu.getImuData();
        // roll  =  atan(data.accel.x / (sqrt((data.accel.y * data.accel.y) + (data.accel.z * data.accel.z))+1e-6)) * 180 / pi; 
        // pitch =  atan(data.accel.y / (sqrt((data.accel.x *data.accel.x) + (data.accel.z * data.accel.z))+1e-6)) * 180 / pi; 
        // yaw   =  atan(sqrt((data.accel.x *data.accel.x) + (data.accel.y * data.accel.y)) / (data.accel.z +1e-6)) * 180 / pi;
        
        MadgwickFilter.updateIMU(data.gyro.x,data.gyro.y,data.gyro.z,data.accel.x,data.accel.y,data.accel.z);
        
        sw = digitalRead(26);

        bool send_sw = sw;
        if(!sw and !before_off){
            send_sw = !sw;
        }

        if(!sw){
            before_off = false;
        }else if(sw){
            before_off = true;
        }

        
        // The data obtained by getImuData can be used as follows.
        // data.accel.x;      // accel x-axis value.
        // data.accel.y;      // accel y-axis value.
        // data.accel.z;      // accel z-axis value.
        // data.accel.value;  // accel 3values array [0]=x / [1]=y / [2]=z.
        // data.gyro.x;      // gyro x-axis value.
        // data.gyro.y;      // gyro y-axis value.
        // data.gyro.z;      // gyro z-axis value.
        // data.gyro.value;  // gyro 3values array [0]=x / [1]=y / [2]=z.
        // data.value;  // all sensor 9values array [0~2]=accel / [3~5]=gyro /
        //              // [6~8]=mag
        // Serial.printf("ax:%f  ay:%f  az:%f\r\n", data.accel.x, data.accel.y,data.accel.z);
        // Serial.printf("gx:%f  gy:%f  gz:%f\r\n", data.gyro.x, data.gyro.y,data.gyro.z);
        // Serial.printf("accelX:%d, accelY:%d, accelZ:%d\n", data.accel.x, data.accel.y, data.accel.z);
        // Serial.printf("gyroX:%d, gyroY:%d, gyroZ:%d\n", data.gyro.x, data.gyro.y, data.gyro.z); 


        //M5stickC-plus2が通常の向きであるときのプログラム
        // Serial.print(MadgwickFilter.getRoll());
        // Serial.print("sep");
        // Serial.print(MadgwickFilter.getPitch());
        // Serial.print("sep");
        // Serial.print(MadgwickFilter.getYaw());
        // Serial.print("sep");
        // Serial.print(!send_sw);
        // Serial.print("sep");
        // Serial.print(data.accel.x);
        // Serial.print("sep");
        // Serial.print(data.accel.y);
        // Serial.print("sep");
        // Serial.print(data.accel.z);
        // Serial.print("sep");
        // Serial.print(data.gyro.x);
        // Serial.print("sep");
        // Serial.print(data.gyro.y);
        // Serial.print("sep");
        // Serial.println(data.gyro.z);


        Serial.print(MadgwickFilter.getRoll());
        Serial.print("sep");
        Serial.print(MadgwickFilter.getPitch());
        Serial.print("sep");
        Serial.print(MadgwickFilter.getYaw());
        Serial.print("sep");
        Serial.print(!send_sw);
        Serial.print("sep");
        Serial.print(data.accel.x);
        Serial.print("sep");
        Serial.print(data.accel.y);
        Serial.print("sep");
        Serial.print(data.accel.z);
        Serial.print("sep");
        Serial.print(data.gyro.x);
        Serial.print("sep");
        Serial.print(data.gyro.y);
        Serial.print("sep");
        Serial.println(data.gyro.z);
        // bts.print(MadgwickFilter.getRoll());
        // bts.print("sep");
        // bts.print(MadgwickFilter.getPitch());
        // bts.print("sep");
        // bts.print(MadgwickFilter.getYaw());
        // bts.print("sep");
        // bts.print(!send_sw);
        // bts.print("sep");
        // bts.print(data.accel.x);
        // bts.print("sep");
        // bts.print(data.accel.y);
        // bts.print("sep");
        // bts.print(data.accel.z);
        // bts.print("sep");
        // bts.print(data.gyro.x);
        // bts.print("sep");
        // bts.print(data.gyro.y);
        // bts.print("sep");
        // bts.println(data.gyro.z);



        StickCP2.Display.printf("IMU:\r\n");
        StickCP2.Display.printf("%0.2f %0.2f %0.2f\r\n", data.accel.x,
                                data.accel.y, data.accel.z);
        StickCP2.Display.printf("%0.2f %0.2f %0.2f\r\n", data.gyro.x,
                                data.gyro.y, data.gyro.z);

        delay(1000);

    }
}