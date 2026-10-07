import java.util.Random;
import java.util.Scanner;

public class ArithmeticProblemGenerator {
    public static void main(String[] args) {
        Random random = new Random();

        // Using try-with-resources to automatically close the scanner
        try (Scanner scanner = new Scanner(System.in)) {
            char[] operators = {'+', '-', '*', '/'};
            char op = operators[random.nextInt(operators.length)];

            int a, b, answer;

            switch (op) {
                case '/':
                    // Ensure non-zero divisor and clean integer division
                    b = random.nextInt(12) + 1;
                    answer = random.nextInt(12) + 1;
                    a = b * answer;
                    break;

                case '*':
                    a = random.nextInt(12) + 1;
                    b = random.nextInt(12) + 1;
                    answer = a * b;
                    break;

                case '-':
                    a = random.nextInt(100) + 1;
                    b = random.nextInt(100) + 1;
                    // Optional: keep results non-negative
                    if (a < b) {
                        int temp = a;
                        a = b;
                        b = temp;
                    }
                    answer = a - b;
                    break;

                case '+':
                default:
                    a = random.nextInt(100) + 1;
                    b = random.nextInt(100) + 1;
                    answer = a + b;
                    break;
            }

            System.out.print("Solve: " + a + " " + op + " " + b + " = ");

            if (scanner.hasNextInt()) {
                int userAnswer = scanner.nextInt();
                if (userAnswer == answer) {
                    System.out.println("Correct!");
                } else {
                    System.out.println("Incorrect. The correct answer was " + answer + ".");
                }
            } else {
                System.out.println("Please enter a valid integer.");
            }
        }
    }
}