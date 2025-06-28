package backtracking;

import java.util.ArrayList;
import java.util.List;

public class Subsets {

    public static void subsetsHelp(List<Integer> nums, int i, List<Integer> curSubset, List<List<Integer>> res) {
        if (i == nums.size()) {
            res.add(new ArrayList<>(curSubset));  // 必须创建一个新列表，否则会共享引用
            return;
        }

        // discard i
        subsetsHelp(nums, i + 1, curSubset, res);

        // keep i
        curSubset.add(nums.get(i));
        subsetsHelp(nums, i + 1, curSubset, res);

        // 回溯
        curSubset.remove(curSubset.size() - 1);
    }

    public static List<List<Integer>> subsets(List<Integer> nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> curSubset = new ArrayList<>();
        subsetsHelp(nums, 0, curSubset, res);
        return res;
    }

    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<>();
        nums.add(1);
        nums.add(2);
        nums.add(3);

        List<List<Integer>> result = subsets(nums);
        
        // 打印结果
        for (List<Integer> subset : result) {
            System.out.println(subset);
        }
    }
}