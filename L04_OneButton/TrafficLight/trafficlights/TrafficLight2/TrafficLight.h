class TrafficLight {
    
    long TIMER_GREEN = 5000;
    long TIMER_YELLOW = 2000;
    long TIMER_RED = 5000;
    long TIMER_RED_YELLOW = 3000;
    
    
    int _greenLED;
    int _yellowLED;
    int _redLED;

    enum State {
      GREEN,
      YELLOW,
      RED,
      RED_YELLOW
    };

    State _currentState = GREEN;
    State _targetState = GREEN;

    long timerStart = 0;
    long timerTarget = 0;

  public:
    TrafficLight(int greenLED, int yellowLED, int redLED) {
      _greenLED = greenLED;
      _yellowLED = yellowLED;
      _redLED = redLED;

      pinMode(_greenLED, OUTPUT);
      pinMode(_yellowLED, OUTPUT);
      pinMode(_redLED, OUTPUT);

      
    }

  void go() {
    _targetState = GREEN;
  }

  void stop() {
    _targetState = RED;
  }

  void loop() {
    if (_targetState == GREEN) {
      goToGreen();
    }
    else {
      goToRed();
    }
  }


  private:

    void goToGreen() {
      switch (_currentState) {
        case RED:
          _currentState = RED_YELLOW;
          startTimer(TIMER_RED_YELLOW);
          break;
        case RED_YELLOW:
          red_yellow();
          if (isTimerReady()) {
            _currentState = GREEN;
          }
          break;
        case GREEN:
          green();
          break;
        case YELLOW:
          red();
          break;
      } 
    }

    void goToRed() {
      switch (_currentState) {
        case GREEN:
          _currentState = YELLOW;
          startTimer(TIMER_YELLOW);
          break;
        case YELLOW:
          yellow();
          if (isTimerReady()) {
            _currentState = RED;
          }
          break;
        case RED:
          red();
          break;
        case RED_YELLOW:
          green();
          break;
      }
    }

    
    void green() {
      digitalWrite(_greenLED, HIGH);
      digitalWrite(_yellowLED, LOW);
      digitalWrite(_redLED, LOW);
    }

    void yellow() {
      digitalWrite(_greenLED, LOW);
      digitalWrite(_yellowLED, HIGH);
      digitalWrite(_redLED, LOW);
    }

    void red() {
      digitalWrite(_greenLED, LOW);
      digitalWrite(_yellowLED, LOW);
      digitalWrite(_redLED, HIGH);
    }

    void red_yellow() {
      digitalWrite(_greenLED, LOW);
      digitalWrite(_yellowLED, HIGH);
      digitalWrite(_redLED, HIGH);
    }

    void off() {
      digitalWrite(_greenLED, LOW);
      digitalWrite(_yellowLED, LOW);
      digitalWrite(_redLED, LOW);
    }

    void startTimer(long msec) {
      timerStart = millis();
      timerTarget = msec;
    }

    bool isTimerReady() {
      return (millis() - timerStart) > timerTarget;
    }
};
