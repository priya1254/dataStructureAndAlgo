package q3;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by ramakantagrawal on 11/02/17.
 */
public class BarberShop {


    private Boolean isNewCustomer;
    private Customer customer;
    public Queue<Customer> chairs = new LinkedList<Customer>();
//    private static const n = 1;
    public Customer getNewCustomer(){
        return this.customer;
    }

    public void setNewCustomer(Customer customer){
        this.customer = customer;
    }

    public static void main(String[] args){
        BarberShop bs = new BarberShop();
        Barber barber = new Barber();
        int n = Integer.valueOf(args[1]);
        while(true){
            if (!barber.isSleeping()){
                if(bs.chairs.size()>0){
                    barber.processCustomer(bs.chairs.poll());
                    if (bs.chairs.size()==0){
                        barber.setSleeping(true);
                    }
                }
            }
            if (bs.isNewCustomer){
                Customer c = bs.getNewCustomer();
                if (barber.isSleeping()){
                    barber.awake();
                }
                if (barber.getBusy()){
                    if (bs.chairs.size() < n){
                        bs.chairs.add(c);
                    }
                    else{
                        System.out.println("Customer goes to another Barber");
                    }
                } else{
                    barber.processCustomer(c);
                    if (bs.chairs.size()==0){
                        barber.setSleeping(true);
                    }
                }
            }
        }
    }
}
