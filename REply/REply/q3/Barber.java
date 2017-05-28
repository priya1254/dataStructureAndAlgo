public class Barber
{

   private boolean working;
   private boolean sleeping;

   void Barber()
   {
      this.sleeping = true;
      this.working = false;

   }
  
  void awake()
  {
    this.sleeping = false;
  }
   
   boolean isworking()
   {
    return working;
   }

   boolean issleeping()
   {
     return sleeping;
   }
    
   void setsleeping(boolean sleeping)
   {
     this.sleeping = sleeping;
   }
   void setworking(boolean working)
   {
     this.working = working;
   }

   void workWithCustomer()
   {
    this.working = true;
    sleepFor60minutes();
   }
    
}
