#ifndef DATES_H
#define DATES_H



class Date {
    private:
    // We took the 01/01/1600 like the first day in reference.
    // So if we initialize the class Dates(), the variable dayRelative
    // will have the value of 1.
    int relativeDay;
    int getRelativeDay(int day, int month, int year);

    public: 
    Date();
    Date(int year, int month, int day);
    Date(int relativeDay);


    // functions
    Date addDays(int days) const; // explain const
    void addDays(int days); // without const
    int daysTo(Date* date2) const;
    void getDMY() const;
    void setDMY(int day, int month, int year);

    // The keyword 'const' in the end of the prototype indicates you
    // that this function doesn't affect the object.

    // Because of that, we can have two functions with the same name.

};

#endif