#ifndef _IOTTIMER_H_
#define _IOTTIMER_H_

class IoTTimer {

  unsigned long timerStart = 0;
  unsigned long timerTarget = 0;

  public:

    IoTTimer() {}
    
    void startTimer(long msec) {
      timerStart = millis();
      timerTarget = msec;
    }

    bool isTimerReady() {
      return (millis() - timerStart) > timerTarget;
    }  
};

#endif // _IOTTIMER_H_
