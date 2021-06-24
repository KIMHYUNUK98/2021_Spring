#include "time.cpp" 		// Specification of the class

int  main()
{
    Time  currentTime;    	// Declares two objects of Time
    Time  endTime;
    bool  done = false;

    currentTime.Set(17, 59, 50);	// Set currentTime to 17:59:50 (you can change)
    endTime.Set(18, 00, 10);		// Set endTime to 18:00:10 (you can change)
    while (!done)  
    {   
        currentTime.Increment();		    // Increment time by 1 second
        currentTime.Print();                // Print currentTime's time
        if (currentTime.Equal(endTime)) 	// Compare with endTime
            done = true;       
    }

    return 0;
}
