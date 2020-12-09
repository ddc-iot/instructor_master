/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

<<<<<<< HEAD
#line 1 "c:/Users/IoTPa/Documents/IoT/cohort2/instructor_master/Utilities/Fix/src/Fix.ino"
=======
#line 1 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/Utilities/Fix/src/Fix.ino"
>>>>>>> 9473036d70bed897070f22fb29bf4b3653d8359f
/*
 * Project fix
 * Description: fix the argon going into listening mode
 * Author: Brian Rashap
 * Date: 09-APR-2020
 */
#include "Particle.h"
#include "dct.h"
void setup();
<<<<<<< HEAD
#line 9 "c:/Users/IoTPa/Documents/IoT/cohort2/instructor_master/Utilities/Fix/src/Fix.ino"
=======
#line 9 "c:/Users/IoT_Instructor/Documents/IoT/instructor_master/Utilities/Fix/src/Fix.ino"
>>>>>>> 9473036d70bed897070f22fb29bf4b3653d8359f
SYSTEM_MODE(SEMI_AUTOMATIC);
void setup() {
    const uint8_t val = 0x01;
    dct_write_app_data(&val, DCT_SETUP_DONE_OFFSET, 1);
    WiFi.on();
    WiFi.connect();
    Particle.connect();
}