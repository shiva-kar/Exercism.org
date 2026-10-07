class ArmstrongNumbers {

    boolean isArmstrongNumber(int numberToCheck) {
        int number = numberToCheck;
        int totalDigits = String.valueOf(numberToCheck).length();
        int result= 0;
        while(number != 0){
            int digit = number % 10;
            number /= 10;
            result += Math.pow(digit, totalDigits);
        }
        return result == numberToCheck;
    }

}
