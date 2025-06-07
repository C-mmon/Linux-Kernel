#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
void function1()
{
  for(int i=0; i<10;i++)
    {
      cout<<"A"<<endl;
      //we need to mark the given thread for sleep 
      this_thread::sleep_for(chrono::millisecond(1));
    }
}

void function2()
{
  for(int i=0; i<10;i++)
    {
      cout<<"B"<<endl;
      //we need to mark the given thread for sleep 
      this_thread::sleep_for(chrono::millisecond(1));
    }
}


void function2()
{
}
int main(){
  thread worker1(function1);
  thread worker2(function2);
  worker1.join();
  worker2.join();
  cout <<'\n'<<endl;
}

//what could be the reason that A and B can be out of sync.
// cout output buffer waits for the buffer to get filled, so before the text on the display appears.
//hence it is possible for one given thread to fill the buffer and then ask for flush operation
//Since printing is a easy operation, it might be possible in modern cpu for one thread to finish printing before other thread can start working.
//Third thing there can be lack of syncrhonization.
}
