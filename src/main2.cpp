// #include <M5StickCPlus2.h>
// #include "BluetoothSerial.h"

// float acc[3]; // 加速度を取り込む配列
// float gyro[3]; //角速度を取り込む配列
// BluetoothSerial bts; //bluetoothの初期化

// void setup() {
//   M5.begin();
//   Serial.begin(115200); // シリアルの初期化
//   if (!bts.begin("M5stick-C")) {
//     Serial.println("Bluetooth initialization failed!");
//     return;
//   }
//   Serial.println("Bluetooth initialized.");
//   M5.IMU.Init(); // センサーを初期化する

//   //マイコンの画面出力設定
//   M5.Lcd.setTextColor(WHITE);
//   M5.Lcd.setTextFont(4);
//   M5.Lcd.setTextSize(0.5);
//   M5.Lcd.setRotation(1);
//   M5.Lcd.setTextDatum(4);
// }

// void loop() {
//   M5.IMU.getAccelData(&acc[0], &acc[1], &acc[2]); // 加速度の取得
//   M5.IMU.getGyroData(&gyro[0], &gyro[1], &gyro[2]); //角速度の取得

//   M5.Lcd.fillScreen(BLACK);
//   int accx =acc[0] * 1000; // 加速度のx軸成分をmGに変換
//   int accy =acc[1] * 1000; // 加速度のy軸成分をmGに変換
//   int accz =acc[2] * 1000; // 加速度のz軸成分をmGに変換
//   int gyrox = (int)gyro[0];
//   int gyroy = (int)gyro[1];
//   int gyroz = (int)gyro[2];

//   //画面出力
//   M5.Lcd.drawNumber(accx, 20, 0);
//   M5.Lcd.drawNumber(accy, 80, 0);
//   M5.Lcd.drawNumber(accz, 140, 0);
//   M5.Lcd.drawNumber(gyrox, 20, 50);
//   M5.Lcd.drawNumber(gyroy, 80, 50);
//   M5.Lcd.drawNumber(gyroz, 140, 50);

//  //Bluetoothで1行にまとめたデータを送信
//   //bts.printf("%d,%d,%d,%d,%d,%d\n", accx, accy, accz, gyrox, gyroy, gyroz);
//   //Serial.printf(">Sent:%d,%d,%d,%d,%d,%d\n", accx, accy, accz, gyrox, gyroy, gyroz); // デバッグ出力
//   bts.printf(">AccX:%f\n",accx);
//   bts.printf(">AccY:%f\n",accy);
//   bts.printf(">AccZ:%f\n",accz);
//   bts.printf(">GyroX:%f\n",gyrox);
//   bts.printf(">GyroY:%f\n",gyroy);
//   bts.printf(">GyroZ:%f\n",gyroz);
  
//   // Serial.print("Accx: ");
//   // Serial.print(accx);
//   // Serial.print(" Accy: ");
//   // Serial.print(accy);
//   // Serial.print(" Accz: ");
//   // Serial.println(accz);
//   // Serial.print("Gyrox: ");
//   Serial.print(gyrox);
//   // Serial.print(" Gyroy: ");
//   // Serial.print(gyroy);
//   // Serial.print(" Gyroz: ");
//   Serial.print("sep");
//   Serial.println(gyroz);

//   // bts.print("Accx: ");
//   // bts.print(accx);
//   // bts.print(" Accy: ");
//   // bts.print(accy);
//   // bts.print(" Accz: ");
//   // bts.println(accz);
//   // bts.print("Gyrox: ");
//   bts.print(gyrox);
//   // bts.print(" Gyroy: ");
//   // bts.print(gyroy);
//   // bts.print(" Gyroz: ");
//   bts.print("sep");
//   bts.println(gyroz);
//   delay(10);
// }