#include "Deque.cpp"

int main()
{

    Deque dq;
    dq.InsertRear("AAA");
    dq.InsertRear("BBB");
    dq.InsertRear("CCC");
    dq.InsertFront("111");
    dq.InsertFront("222");

    cout << "Print from Front(size=" << dq.GetLength() << "): "; 
    dq.PrintFromFront();
    cout << endl;

    cout << "Print from Rear(size=" << dq.GetLength() << "): "; 
    dq.PrintFromRear();
    cout << endl;

    dq.DeleteFront();
    dq.DeleteRear();
    dq.DeleteRear();
    
    cout << "Print from Front(size=" << dq.GetLength() << "): "; 
    dq.PrintFromFront();
    cout << endl;

    dq.InsertRear("DDD");
    dq.InsertRear("333");
    
    cout << "Print from Rear(size=" << dq.GetLength() << "): "; 
    dq.PrintFromRear();
    cout << endl;
  
    return 0;
}
