#ifndef HEARTRATE_H
#define HEARTRATE_H

class heartrate
{
    private:
        int rate;
    public:
        void setRate();
        int getRate() const;
        bool isNormal(int age) const;
};

#endif