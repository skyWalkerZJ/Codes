package uestc.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

/**
 * @author: zhangjin
 * @title: 最大数
 * @ProjectName: leetcode
 * @Description:
 * @date: 2022/7/2622:12
 */
public class 最大数 {
    public static String largestNumber(int[] nums) {
        String ans="";
        Integer[] integers=new Integer[nums.length];
        for (int i = 0; i < integers.length; i++) {
            integers[i]=nums[i];
        }
        Arrays.sort(integers, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                String s1=o1.toString();
                String s2=o2.toString();
                for (int i = 0; i < s1.length()&&i<s2.length(); i++) {
                    if(s1.charAt(i)<s2.charAt(i)) return -1;
                    else if(s1.charAt(i)>s2.charAt(i)) return 1;
                }
                if(s1.length()==s2.length()) return 0;
                else if(s1.length()>s2.length())
                {
                    return Integer.valueOf(s2+s1)-Integer.valueOf(s1+s2);
                }
                else return Integer.valueOf(s1+s2)-Integer.valueOf(s2+s1);
            }
            @Override
            public boolean equals(Object obj) {
                return false;
            }
        });
        for (int i = integers.length-1; i >=0 ; i--) {
            ans+=integers[i];
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums=new int[]{3,30};
        System.out.println(largestNumber(nums));
    }
}
