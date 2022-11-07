package uestc.剑指offer;

import java.util.ArrayList;
import java.util.Scanner;

public class test1 {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<String> arrayList=new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String next = scanner.next();
            arrayList.add(next);
        }
        for(String s:arrayList)
        {
            System.out.println(topicLength(s));
        }
    }
    public static int topicLength(String s)
    {
        if(s.length()<3) return 0;
        if(s.lastIndexOf(s.charAt(0))==0) return 0;
        if(s.indexOf(s.charAt(s.length()-1))==s.length()-1) return 0;
        int ans=0;
        char c = s.charAt(s.length() - 1);
        for(int i=0;i<s.length();i++)
        {
            int length=i+1;
            if(s.charAt(i)!=c) continue;
            String topic = s.substring(0, length);
            String secondString = s.substring(length);
            int secondIndex = secondString.indexOf(topic);
            if(secondIndex==-1) continue;
            String thirdString = secondString.substring(secondIndex + length);
            if(thirdString.endsWith(topic)) ans=Math.max(ans,length);
        }
        return ans;
    }
}
