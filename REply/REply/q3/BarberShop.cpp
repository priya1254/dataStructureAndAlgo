#include<Barber.cpp>
class Customer {
}

class BarberShop
{
  
  private:

  private Customer customer;
  private boolean isNewCustomer;  // Private members , object of customer class and check if isNewCustomer is there.
  

  public:
    Queue<Customer> waitingcustomers; //Queue for waiting customers, size of queue is equal to no of chairs.
    Customer getcustomer()
  {
    return this.customer;  //getter for customer
  }
   
   void setNewCustomer(Customer customer)
  {
    this.customer = customer;  //Setter for customer
  }



}

int main()
{

    BarberShop barbshop = new BarberShop();
    Barber barber = new Barber();  //object of barber class
    cin>> no_of_chairs;  //input no of chairs in barber shop

    while(1)
    {
        if(!barber.issleeping())
        {
            if(barbshop.waitingcustomers.size() > 0)
                {
                    barber.workWithCustomer(barbshop.waitingcustomers.pop());     //if barber is not sleeping, assign it a waiting customer in the queue.
                    if(barbshop.waitingcustomers.size() == 0)                     // if queue becomes empty after waiting customer is processed, assign it to sleeping state.
                        barber.setsleeping(true);

                }

        }

        if(barbshop.isNewCustomer)
        {
             Customer c = barbshop.getNewCustomer();
                if (barber.issleeping())
                {
                    barber.awake();  // when new customer arises, and barber is sleeping, wake up the barber.
                }
                 if(barber.isworking())
                 {
                    if(barbshop.waitingcustomers.size() < nof_of_chairs)    //if barber is working, put new customer in the waiting queue.
                        waitingcustomers.push(c);
                    else
                        cout<<"customer goes to another shop";        // if size of waiting queue become equal to no of avavilable chairs, barber goes to new shop
                 } 
                
        }
         
        
    }

}

Hi Paul,

I have started my thesis at ETH, Zurich on ''. 

Currently i am doing the literature survey, 
1. Checking what else have been by app market analysis data. 
2. What are the new emerging applications

I have also collected data from 42mattersAG, 



Thanks and Regards
Priya Goel
Student MSc Informatics(03668914)
Technical University Munich