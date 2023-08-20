const int buttonPin = 2;   
int currentButtonstate = 0;        // Current state of the button
int lastButtonState = HIGH; // Previous state of the button
bool blinkingFlag = false;  // Flag to track if the name is currently blinking
int charIndex = 0;          // Index of the character being blinked

char inputName[100];        // Buffer to store user input
int userInput = 0;         // Index for reading user input

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  Serial.begin(9600);
  Serial.println("Enter the name you want to blink(a-z with space): ");
}

//function for dot with no return value
void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

//function for dash with no return value
void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

//morse code 
void morse_encrypt(char name) {
  switch (name) {
    case 'a':
      dot();
      dash();
      break;
    case 'b':
      dash();
      dot();
      dot();
      dot();
      break;
    case 'c':
      dash();
      dot();
      dash();
      dot();
      break;
    case 'd':
      dash();
      dot();
      dot();
      break;
    case 'e':
      dot();
      break;
    case 'f':
      dot();
      dot();
      dash();
      dot();
      break;
    case 'g':
      dash();
      dash();
      dot();
      break;
    case 'h':
      dot();
      dot();
      dot();
      dot();
      break;
    case 'i':
      dot();
      dot();
      break;
    case 'j':
      dot();
      dash();
      dash();
      dash();
      break;
    case 'k':
      dash();
      dot();
      dash();
      break;
    case 'l':
      dot();
      dash();
      dot();
      dot();
      break;
    case 'm':
      dash();
      dash();
      break;
    case 'n':
      dash();
      dot();
      break;
    case 'o':
      dash();
      dash();
      dash();
      break;
    case 'p':
      dot();
      dash();
      dash();
      dot();
      break;
    case 'q':
      dash();
      dash();
      dot();
      dash();
      break;
    case 'r':
      dot();
      dash();
      dot();
      break;
    case 's':
      dot();
      dot();
      dot();
      break;
    case 't':
      dash();
      break;
    case 'u':
      dot();
      dot();
      dash();
      break;
    case 'v':
      dot();
      dot();
      dot();
      dash();
      break;
    case 'w':
      dot();
      dash();
      dash();
      break;
    case 'x':
      dash();
      dot();
      dot();
      dash();
      break;
    case 'y':
      dash();
      dot();
      dash();
      dash();
      break;
    case 'z':
      dash();
      dash();
      dot();
      dot();
      break;
    default:
      break;
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    blinkingFlag = !blinkingFlag; 
    charIndex = 0; 
  }

  lastButtonState = buttonState;

  if (blinkingFlag) {
    if (inputName[charIndex] != '\0') {
      char y = inputName[charIndex];
     morse_encrypt(y);
      delay(1000); 
      charIndex++;
    } else {
      blinkingFlag = false; 
    }
  } else {
    
    digitalWrite(LED_BUILTIN, LOW);
  }

  // Read user input from Serial Monitor
  while (Serial.available() > 0) {
    char incomingChar = Serial.read();
    if (incomingChar == '\n' || userInput >= sizeof(inputName) - 1) {
      inputName[userInput] = '\0'; 
      userInput = 0; 
      Serial.print("name ");
      Serial.print(inputName);
      Serial.print(" blinking");
      blinkingFlag = true; 
    } else {
      inputName[userInput] = incomingChar;
      userInput++;
    }
  }
}