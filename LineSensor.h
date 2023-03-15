

class LineSensor
{
    private:
        bool Value;
    public:
        LineSensor() {};
        ~LineSensor() {};
        void setValue(bool _value)
        {
            Value = _value;
        };
        int getValue()
        {
            return Value;
        };
};