
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;


public class MinimumHeapTestRunner {
  public static void main(String[] args) {
    //to run ant clean test clean
    Result result = JUnitCore.runClasses(MinimumHeapTestInt.class);
    for (Failure failure : result.getFailures()) {
      System.out.println(failure.toString());
    }
  
    System.out.println(result.wasSuccessful());
    
  }
}

