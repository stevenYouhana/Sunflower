import java.util.Random;
class TopTwo {
  public static void main(String[] args){
    Random randInt = new Random();
    int[] sensors = new int[4];
    boolean find=false;
    boolean flag=true;
    int first = sensors[0];
    int second = sensors[0];
    for(int i=0; i<4; i++){
      sensors[i] = randInt.nextInt(255);
    }

    for (int i = 0; i < sensors.length; i++)
    {
        System.out.print(sensors[i]+"\t");
    }
    System.out.println("");
    while(flag)
    {
        for (int i = 0; i < sensors.length; i++)
        {
            if (sensors[i] > first)
            {
                find=true;
                second = first;
                first = sensors[i];
            }
            else if (sensors[i] > second)
            {
                find=true;
                second = sensors[i];
            }
        }
        if(find)
        {
            System.out.println("\nSecond number is:" + second);
            flag=false;
        }else
        {
            first = sensors[1];
            second = sensors[1];
        }
    }
    System.out.println("first number is: "+first);
}
}
