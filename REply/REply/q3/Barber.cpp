class Barber
{

   private:
   boolean working; // two states of barber working and sleeping
   boolean sleeping;

   public:
   void Barber()
   {
      this.sleeping = true;
      this.working = false; // initilaize both state to false

   }
  
  
   boolean isworking()
   {
    return working;    //check if barber is wworking.
   }

   boolean issleeping()
   {
     return sleeping;   //check if barber is sleeping
   }
    
   void setsleeping(boolean sleeping)
   {
     this.sleeping = sleeping; // set barber state to sleeping
   }
   void setworking(boolean working)
   {
     this.working = working;      //set barber state to working
   }
    
  void awake()
  {
    this.sleeping = false; //Called if new customer arrives, barber gets up
  }
   
   void workWithCustomer(Customer c)
   {
    this.working = true;
    sleepFor60seconds();     //barber is working on a customer, make it sleep for 60 secs.
   }
    
}
