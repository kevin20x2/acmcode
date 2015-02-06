import java.math.BigInteger;
import java.util.Scanner;
public class Main{
    public static void main(String argv[])
    {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        for(int cas = 1;cas<=T;cas++)
        {
            String str = input.next();
            BigInteger bg = new BigInteger(str);
            BigInteger ans = bg.multiply(bg).multiply(BigInteger.valueOf(8));
            ans = ans.subtract(bg.multiply(BigInteger.valueOf(7))).add(BigInteger.valueOf(1));
            System.out.print("Case #"+cas+": ");
            System.out.println(ans);
        }
    }
}
