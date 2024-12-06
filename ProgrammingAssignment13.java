import java.util.HashSet;
import java.util.TreeSet;

public class LargestSubsetConsecutive {
    public static TreeSet<Integer> findLargestSubsetConsecutive(int[] input) {
        HashSet<Integer> hash = new HashSet<>();
        TreeSet<Integer> largestSequence = new TreeSet<>();

        for (int number : input) {
            hash.add(number);
        }
        for (int number : input) {
            if (!hash.contains(number - 1)) {
                int currentNumber = number;
                TreeSet<Integer> currentSequence = new TreeSet<>();
                while (hash.contains(currentNumber)) {
                    currentSequence.add(currentNumber);
                    currentNumber++;
                }
                if (currentSequence.size() > largestSequence.size()) {
                    largestSequence = currentSequence;
                }
            }
        }

        return largestSequence;
    }

    public static void main(String[] args) {
        int[] input = {3,7,14,23,1,64,2,11,13,4};
        TreeSet<Integer> result = findLargestSubsetConsecutive(input);

        System.out.println("Largest subset of consecutive numbers: " + result);
    }
}
