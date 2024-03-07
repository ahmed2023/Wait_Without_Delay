///////////////// Define ///////////////////////////////////////////////////////
static unsigned long startTime;
static bool isStarted = false;
long previousMillis = 0;
int Count = 0;
//////////////////////////////////////////////////////////////////////////////
//////////////////////////// Main Function ///////////////////////////////////
bool wait(unsigned long duration){
  if(isStarted == false){     // if wait period not started yet
    startTime = millis();     // set the start time of the wait period
    isStarted = true;         // indicate that it's started
    return false;             // indicate to caller that wait period is in progress
  }
  if(millis() - startTime >= duration){     // check if wait period has lapsed
    isStarted = false;        // lapsed
    return true;              // indicate to caller that wait period has lapsed
  }
  return false;                // indicate to caller that wait period is in progress
}
/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Setup //////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// Loop /////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  if(wait(1000)){
    Serial.print("Counter: ");
    Serial.println(Count++);
  }
}
///////////////////////////////////////////////////////////////////////////////////////