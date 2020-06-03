class Led
{
    public:
        Led (int LED) : LED(LED) { IsOn = false; }
        void TurnOn() { digitalWrite(LED, HIGH); IsOn = true; }
        void TurnOff() { digitalWrite(LED, LOW); IsOn = false; }
        void Toggle() 
        {
            if (IsOn)
                TurnOff();
            else
                TurnOn();
        }
        void Initialise() { pinMode(LED, OUTPUT); }
    private:
        const int LED;
        bool IsOn;
};


Led Red(D6);
Led Blue(D5);
Led Green(D4);

void setup()
{
    Red.Initialise();
    Blue.Initialise();
    Green.Initialise();
    Particle.function("lights", ToggleLed);
    delay(1000);
}

void loop()
{

}

int ToggleLed(String led)
{
    if (led == "red")
        Red.Toggle();
    else if (led == "blue")
        Blue.Toggle();
    else if (led == "green")
        Green.Toggle();
    else
        return -1; //failure
    return 1; //success
}