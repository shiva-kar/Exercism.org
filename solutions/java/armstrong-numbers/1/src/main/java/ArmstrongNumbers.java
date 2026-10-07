class ArmstrongNumbers {

    boolean isArmstrongNumber(int numberToCheck) {
        int number = numberToCheck;
        int totalDigits = 0;
        int result= 0;
        while(number != 0){
            totalDigits++;
            number /= 10;
        }
        number = numberToCheck;
        while(number != 0){
            int digit = number % 10;
            number /= 10;
            result += Math.pow(digit, totalDigits);
        }
        return result == numberToCheck;
    }

}
