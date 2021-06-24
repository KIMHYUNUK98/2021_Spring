//  Specification file (Time.h)
class  Time        	    // Declares a class data type
{			            // does not allocate memory
    private :      	    // Three private data members
        int  hrs;           
        int  mins;          
        int  secs;

    public :        
        // TODO: define member funcitons --> Set(), Increment(), Print() 
        void Set(int hours, int mins, int secs);
        void Print() const;
        void Increment();
        void Write() const;
        bool Equal (Time otherTime)  const;   
        bool LessThan(Time otherTime) const;
};	
