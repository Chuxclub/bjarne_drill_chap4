#include <iostream>
#include "std_lib_facilities.h"

double convert_cm_m (double a); //MUST BE DECLARED OUT OF MAIN!!!
double convert_in_cm (double a);
double convert_ft_in (double a);

int	main()
{
    double user_value = 0, largest_value = 0, smallest_value = 0;
    double sum_of_values = 0, number_of_values = 0;
    vector<double> stored_values;
    string unit = " ";

    /* -------------------------- Setting first value for comparison loop -------------------------- */
    //In case of first wrong input, not being caught with smallest_value = 0 afterwards

    cin >> user_value >> unit;

        //Unit selection
        while (unit != "cm" && unit != "m" && unit != "in" && unit != "ft")
        {
            cout << endl << "Illegal unit, input again: \n\n";
            cin >> user_value >> unit;
        }

        if (unit == "cm")
        {
            user_value = convert_cm_m(user_value); // MUST ASSIGN NEW VALUE TO USER_VALUE!!!
            stored_values.push_back(user_value);
        }

        else if (unit == "in")
        {
            user_value = convert_in_cm(user_value);
            user_value = convert_cm_m(user_value);
            stored_values.push_back(user_value);
        }

        else if (unit == "ft")
        {
            user_value = convert_ft_in(user_value);
            user_value = convert_in_cm(user_value);
            user_value = convert_cm_m(user_value);
            stored_values.push_back(user_value);
        }

        else
            stored_values.push_back(user_value);

        //User value processing
        largest_value = user_value;
        smallest_value = user_value;
        sum_of_values += user_value;
        number_of_values++;
        sort(stored_values);

        cout << endl << "The largest so far: " << largest_value << "m";
        cout << endl << "The smallest so far: " << smallest_value << "m";
        cout << endl << "Sum of the values so far: " << sum_of_values << "m";
        cout << endl << "Number of values entered so far: " << number_of_values;
        cout << endl << "Values entered so far in increasing order: ";
        for (double x : stored_values) cout << x;

    cout << endl << endl;


    /* -------------------------- Comparison loop -------------------------- */
    //input loop for unlimited number of comparisons

    while(cin >> user_value >> unit)
    {
        //Unit selection
        while (unit != "cm" && unit != "m" && unit != "in" && unit != "ft")
        {
            cout << endl << "Illegal unit, input again: \n\n";
            cin >> user_value >> unit;
        }

        if (unit == "cm")
        {
            user_value = convert_cm_m(user_value);
            stored_values.push_back(user_value);
        }

        else if (unit == "in")
        {
            user_value = convert_in_cm(user_value);
            user_value = convert_cm_m(user_value);
            stored_values.push_back(user_value);
        }

        else if (unit == "ft")
        {
            user_value = convert_ft_in(user_value);
            user_value = convert_in_cm(user_value);
            user_value = convert_cm_m(user_value);
            stored_values.push_back(user_value);
        }

        else
            stored_values.push_back(user_value);

        //User value processing
        sum_of_values += user_value;
        number_of_values++;
        sort(stored_values);

        if(user_value > largest_value)
            largest_value = user_value;
        else if(user_value < smallest_value)
            smallest_value = user_value;

        cout << endl << "The largest so far: " << largest_value << "m";
        cout << endl << "The smallest so far: " << smallest_value << "m";
        cout << endl << "Sum of the values so far: " << sum_of_values << "m";
        cout << endl << "Number of values entered so far: " << number_of_values;
        cout << endl << "Values entered so far in increasing order: ";
        for (double x : stored_values) cout << x << ", ";

        cout << endl << endl;
    }
}

    /* -------------------------- Defined functions -------------------------- */
    // Out of main too

    double convert_cm_m (double a)
    {
        constexpr double cm_to_m = 1.0/100; //MUST BE 1.0/100 OR 1/100.0 FOR DOUBLE OUTPUT!!!
        a *= cm_to_m;
        return a;
    }

    double convert_in_cm (double a)
    {
        constexpr double in_to_cm = 2.54;
        a *= in_to_cm;
        return a;
    }

    double convert_ft_in (double a)
    {
        constexpr double ft_to_in = 12;
        a *= ft_to_in;
        return a;
    }