package uestc.leetcode;

/**
 * @author: zhangjin
 * @title: 快速排序
 * @ProjectName: leetcode
 * @Description:
 * @date: 2022/7/2623:06
 */
public class 快速排序 {
    private static void quickSort(int[] src, int left, int right) {
        if(left<right)
        {
            int base=src[left];int i=left;int j=right;
            while (i<j)
            {
                while (i<j&&src[j]>=base) j--;
                while (i<j&&base>=src[i]) i++;
                int temp=src[i];
                src[i]=src[j];
                src[j]=temp;
            }
            int temp=src[j];
            src[j]=base;
            src[left]=temp;
            quickSort(src,left,j-1);
            quickSort(src,j+1,right);
        }
    }

    public static void main(String[] args) {
        int[] ints=new int[]{1,6,32,3,5,7};
        quickSort(ints,0,ints.length-1);
        for (int i = 0; i < ints.length; i++) {
            System.out.print(ints[i]+" ");
        }
    }
}
