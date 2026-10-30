#ifndef READING_H
#define READING_H

class Reading
{
    private:
        bool live_reading;
    public:
        Reading();
        void setReading(bool a);
        bool getReading() const;
};
#endif