package uestc.leetcode;

import java.util.Scanner;

/**
 * @author: zhangjin
 * @title: 蓝桥杯国赛123
 * @ProjectName: leetcode
 * @Description:
 * @date: 2022/6/1710:48
 */
public class 蓝桥杯国赛123 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        //在此输入您的代码...
        int n=scan.nextInt();
        for(int i=1;i<=n;i++)
        {
            int left=scan.nextInt();
            int right=scan.nextInt();
            int row1=getRowAndCol(left)[0];
            int col1=getRowAndCol(left)[1];
            int row2=getRowAndCol(right)[0];
            int col2=getRowAndCol(right)[1];
            int sum=0;
            if(row1!=row2) {
            for(int j=col1;j<=row1;j++) sum+=j;
            for(int j=1;j<=col2;j++) sum+=j;
            for(int j=row1+1;j<row2;j++)
            {
                sum+=(j+1)*j/2;
            }
            }else{
                for (int j = col1; j <=col2 ; j++) {
                    sum+=j;
                }
            }
            System.out.println(sum);
        }
        scan.close();
    }
    public static int[] getRowAndCol(int n)
    {
        for(int i=1;i<Integer.MAX_VALUE;i++)
        {
            int left=i*(i+1)/2;
            int right=(i+1)*(i+2)/2;
            if(n==left) return new int[]{i,i};
            if(n==right) return new int[]{i+1,i+1};
            if(n>left&&n<right)
            {
                return new int[]{i+1,n-i*(i+1)/2};
            }
        }
        return null;
    }
}
