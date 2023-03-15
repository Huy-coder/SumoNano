

class DetectSensor
{
    private:
        int Distance;
    public:
        DetectSensor() {};
        ~DetectSensor() {};
        void setDistance(int distance)
        {
            Distance = distance;
        };
        int getDistance()
        {
            return Distance;
        }
};