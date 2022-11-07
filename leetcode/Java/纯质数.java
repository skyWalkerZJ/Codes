package uestc.leetcode;

/**
 * @author: zhangjin
 * @title: 纯质数
 * @ProjectName: leetcode
 * @Description:
 * @date: 2022/6/1710:27
 */
public class 纯质数 {
    public static void main(String[] args) {
        int count=0;
        for(int i=1;i<=20210605;i+=2)
        {
            if(ifzhishu(i)){
                int temp=i;
                while(temp>0)
                {
                    int yushu=temp%10;
                    temp=temp/10;
                    if(yushu!=2&&yushu!=3&&yushu!=5&&yushu!=7) break;
                    if(temp==0) count++;
                }
            }
        }
        System.out.println(count+1);//2也是质数
    }
    public static boolean ifzhishu(int n)
    {

        for(int i=2;i<=Math.sqrt(n);i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
}
