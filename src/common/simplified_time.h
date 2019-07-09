#ifndef SIMPLIFIED_TIME_H
#define SIMPLIFIED_TIME_H

#include <QDataStream>
#include <QMetaType>
#include <QString>

#include<iostream>

using namespace std;

namespace common{

class SimplifiedTime
{
public:

    SimplifiedTime()
    {
        hr=0;
        min=0;
        sec=0;
    }

    SimplifiedTime(int h,int m,int s)
    {
        hr=h;
        min=m;
        sec=s;
    }

    SimplifiedTime(const uint64_t &microseconds)
    {
        //First let us get to seconds
        double currentSeconds = microseconds / (1000 * 1000);

        hr=currentSeconds/3600;
        currentSeconds=static_cast<int>(currentSeconds)%3600;
        min=currentSeconds/60;
        sec=static_cast<int>(currentSeconds)%60;
    }

    QString getQString() const
    {
        QString hours = QString::number(hr) + " HRS : ";
        QString mins = QString::number(min) + " MINS : ";
        QString secs = QString::number(sec) + " SECS";

        return hours + mins + secs;
    }

    SimplifiedTime& operator = (const SimplifiedTime &rhs)
    {
        this->hr = rhs.hr;
        this->min = rhs.min;
        this->sec = rhs.sec;
        return *this;
    }

    SimplifiedTime operator + (const SimplifiedTime &t)
    {
        int h,m,s;
        int sum;
        sum = (hr + t.hr)*3600 + (min + t.min)*60 + sec + t.sec;
        s = sum % 60;
        sum = sum / 60;
        m = sum % 60;
        h = sum / 60;
        return SimplifiedTime(h,m,s);
    }

    SimplifiedTime operator - (const SimplifiedTime &t)
    {
        int h,m,s;
        int sum1,sum2,sum;
        sum1 = (hr)*3600 + (min )*60 + sec ;
        sum2 = (t.hr)*3600 + (t.min)*60 + t.sec;
        if (sum1>sum2)
            sum = sum1-sum2;
        else
            sum = sum2-sum1;
        s = sum %60;
        sum = sum/60;
        m = sum % 60;
        h = sum/60;
        return SimplifiedTime(h,m,s);
    }

    friend QDataStream& operator<<(QDataStream& out, const SimplifiedTime& v) {
        out << v.hr << v.min << v.sec;
        return out;
    }

    friend QDataStream& operator>>(QDataStream& in, SimplifiedTime& v) {
        in >> v.hr;
        in >> v.min;
        in >> v.sec;
        return in;
    }

public:
    int hr;
    int min;
    int sec;
};

} //end of namespace common

Q_DECLARE_METATYPE(common::SimplifiedTime)


#endif // SIMPLIFIED_TIME_H
