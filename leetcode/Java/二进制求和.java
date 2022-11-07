package uestc.leetcode;

/**
 * @author: zhangjin
 * @title: 二进制求和
 * @ProjectName: leetcode
 * @Description:
 * @date: 2022/6/2419:42
 */
public class 二进制求和 {
    //会溢出
    public String addBinary(String a, String b) {
        return Integer.toBinaryString(Integer.valueOf(a,2)+Integer.valueOf(b,2));
    }
}
