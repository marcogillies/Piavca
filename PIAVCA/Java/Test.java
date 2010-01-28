import Piavca.*;

import java.util.Iterator;
import java.util.Properties;
import java.util.TreeSet;
import java.util.UUID;

public class Test {

  public static void main(String argv[]) {

        Properties pr = System.getProperties();
        TreeSet propKeys = new TreeSet(pr.keySet());

        for (Iterator it = propKeys.iterator(); it.hasNext(); ) {
          String key = (String)it.next();
          // System.out.println("" + key + "=" + pr.get(key) + "\n");
          System.out.println("" + key + "=" + pr.get(key) );
        }
	System.out.println(Piavca.otherTest(2));
	System.out.println(PiavcaBase.degToRad(90));
	  //Avatar a = new Avatar();
	  //Vec v = new Vec();
  }
}

