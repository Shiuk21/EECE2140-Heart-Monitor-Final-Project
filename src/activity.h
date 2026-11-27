#ifndef ACTIVITY_H
#define ACTIVITY_H

//Ella's Class
class Activity
{
    private:
        int activity;
        // 0 = at rest
        // 1 = walking
        // 2 = working out
    public:
        Activity();
        void setActivity(int a);
        int getActivity () const;
};

#endif