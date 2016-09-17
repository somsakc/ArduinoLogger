# ArduinoLogger
Arduino leveling logger with vsnprint-format supplied message

# Example

##include "Logging.h"

void setup() {
    Log.begin(LOG_LEVEL_DEFAULT, 115200L);
    delay(1000);
}

void loop() {
    int mInt1 = 232;
    int mInt2 = -32199;
    uint8_t mUInt8_1 = 232;
    uint8_t mUInt8_2 = 256;
    uint16_t mUInt16_1 = 23342;
    uint16_t mUInt16_2 = 3299;
    byte mByte1 = 'A';
    byte mByte2 = ' ';
    long mLong1 = 99403020L;
    long mLong2 = -45021L;
    unsigned long mULong1 = 4123456789L;
    unsigned long mULong2 = 45021L;
    bool mBool1 = true;
    bool mBool2 = false;
    float myFloat1 = 28434.32343;

    char* mCharArray = "this is a string";
    String mString = "this is String object";

    Log.info("########### Logging example ###########");
    
    Log.info("This is int mInt1 %d, mInt2 %d", mInt1, mInt2);
    Log.info("This is int mInt1=%x, mInt1=%X, mInt1=%06X", mInt1, mInt1, mInt1);
    Log.info("This is int mInt2=%x, mInt2=%X", mInt2, mInt2);
    Log.info("This is uint8_t mUInt8_1=%u, mUInt8_2=%u", mUInt8_1, mUInt8_2);
    Log.info("This is uint16_t mUInt16_1=%u, mUInt16_2=%u", mUInt16_1, mUInt16_2);
    Log.info("This is long mLong1 %ld, mLong2=%ld", mLong1, mLong2);
    Log.info("This is long mULong1 %lu, mULong2=%lu", mULong1, mULong2);
    Log.warn("This is byte mByte1=%d, mByte2=%d", mByte1, mByte2);
    Log.info("This is bool mBool1=%d, mBool2=%d", mBool1, mBool2);

    //char str_temp[6];
    /* 4 is mininum width, 2 is precision; float value is copied onto str_temp*/
    //dtostrf(temp, 4, 2, str_temp);
    //sprintf(temperature,"%s F", str_temp);

    // float is not implement on Arduino's vsnprintf function
    Log.critical("This is float myFloat1=%s, myFloat1=%s", String(myFloat1, 3).c_str(), String(myFloat1, 5).c_str());
    
    Log.info("This is char array mCharArray=%s", mCharArray);
    Log.error("This is bool mBool1=%d mBool1=%s", mBool1, (mBool1 ? "true" : "false"));
    Log.error("This is bool mBool2=%d mBool2=%s", mBool2, (mBool2 ? "true" : "false"));
    Log.debug("This is bool mBool1=%d mBool1=%s", mBool1, (mBool1 ? "true" : "false"));
    Log.verbose("This is bool mBool2=%d mBool2=%s", mBool2, (mBool2 ? "true" : "false"));
    Log.info("have fun with this Log");
    Log.warn(mString);
    Log.error(mString);
    Log.logln(mString);
    Log.logln(mString.c_str());
    Log.error("\n");
    
    delay(50000L);
}
